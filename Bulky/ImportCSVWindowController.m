//
//  CSVWindowController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ImportCSVWindowController.h"
#import "Contact.h"
#import "CSVParser.h"
#import "CoreDataHelper.h"

@interface ImportCSVWindowController ()
- (void)import;

- (void)insertContact:(NSDictionary *)contactDict;

- (void)resetViews;

@end

@implementation ImportCSVWindowController
@synthesize importBtnEnabled = _importBtnEnabled;
@synthesize excludeFirstRow = _excludeFirstRow;
@synthesize hideFileInfo = _hideFileInfo;
@synthesize hideStatus = _hideStatus;
@synthesize separator = _separator;
@synthesize fileName = _fileName;
@synthesize recordsNumber = _recordsNumber;
@synthesize contactFields = _contactFields;
@synthesize csvFields = _csvFields;
@synthesize csvRecords = _csvRecords;


- (id)init {
    self = [super initWithWindowNibName:@"ImportCSVWindow"];
    NSArray *arr = [[NSArray alloc] initWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"contactFields" ofType:@"plist"]];
    self.contactFields = arr;
    [arr release];

    return self;
}

#pragma mark Actions
- (IBAction)selectFileAction:(id)sender {
    NSArray *fileTypes = [[NSArray alloc] initWithObjects:@"csv", @"txt", nil];
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    [panel setCanChooseDirectories:NO];
    [panel setAllowsMultipleSelection:NO];
//    [panel setAllowedFileTypes:fileTypes];

    if ([panel runModalForTypes:fileTypes] == NSOKButton) {
        NSError *err;
        NSURL *url = [panel URL];
        NSString *csvData = [NSString stringWithContentsOfFile:[url path] encoding:NSUTF8StringEncoding error:&err];

        CSVParser *parser = [[CSVParser alloc] initWithString:csvData separator:self.separator hasHeader:NO fieldNames:nil];
        NSMutableArray *tempCsvRecords = [[NSMutableArray alloc] initWithArray:[parser arrayOfParsedRows]];

        self.hideFileInfo = NO;
        self.fileName = [url lastPathComponent];
        self.recordsNumber = self.excludeFirstRow ? tempCsvRecords.count - 1 : tempCsvRecords.count;

        if (tempCsvRecords.count > 0) {
            NSDictionary *headerRow = [[tempCsvRecords objectAtIndex:0] retain];
            NSMutableArray *headerValues = [[NSMutableArray alloc] initWithObjects:@"-", nil];
//            NSMutableArray *allKeys = [[NSMutableArray alloc] initWithArray:[headerRow allKeys]];
//            for (int i = 0; i < allKeys.count; i++) {
//                NSString *k = [allKeys objectAtIndex:(NSUInteger) i];
//                NSString *string1 = [k stringByReplacingOccurrencesOfString:@"FIELD_" withString:@""];
//
////                [allKeys replaceObjectAtIndex:(NSUInteger) i withObject:[NSNumber numberWithInt:string1.intValue]];
//                [allKeys replaceObjectAtIndex:(NSUInteger) string1.intValue-1 withObject:string1];
//            }
            NSArray *headerKeys = [[headerRow allKeys] sortedArrayUsingSelector:@selector(psuedoNumericCompare:)];
//            NSLog(@"headerKeys=%@", headerKeys);
            for (NSString *headerKey in headerKeys) {
                [headerValues addObject:[headerRow objectForKey:headerKey]];
            }
//            NSLog(@"headerValues=%@", headerValues);
            self.csvFields = headerValues;
            [headerValues release];
            [headerRow release];

            self.csvRecords = tempCsvRecords;
//            NSLog(@"csv=%@", self.csvRecords);
            self.importBtnEnabled = YES;


            //[allKeys release];
        }
        [parser release];
        [tempCsvRecords release];
    }

    [fileTypes release];
}

- (IBAction)cancelFormAction:(id)sender {
    [self dismissSheet];

}

- (IBAction)importFormAction:(id)sender {
    self.importBtnEnabled = NO;
    [statusInd startAnimation:self];
    [self import];
    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    [statusInd stopAnimation:self];
    [self resetViews];
    [self dismissSheet];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"switchToContacts" object:nil];
}



#pragma mark Methods
- (void)import {
//    NSLog(@"self.contactFields=%@", self.contactFields);
    for (int i = 0; i < self.csvRecords.count; i++) {
        if (self.excludeFirstRow && i == 0)
            continue;
        NSDictionary *row = [self.csvRecords objectAtIndex:(NSUInteger) i];
        NSMutableDictionary *contactValues = [[NSMutableDictionary alloc] init];
        NSString *firstName = nil;
        NSString *lastName = nil;
        NSString *fullName = nil;
        for (int j = 0; j < self.contactFields.count; j++) {
            NSDictionary *cf = [self.contactFields objectAtIndex:(NSUInteger) j];
            int ind = ((NSNumber *) [cf valueForKey:@"index"]).intValue;
            if (ind == 0)
                continue;
            NSString *valueForKey = [row valueForKey:[NSString stringWithFormat:@"%i_FIELD", ind]];
            NSString *key = [cf valueForKey:@"key"];
            if ([key isEqual:@"firstName"])
                firstName = valueForKey;
            else if ([key isEqual:@"lastName"])
                lastName = valueForKey;
            else if ([key isEqual:@"name"])
                fullName = valueForKey;

            else {
                [contactValues setValue:valueForKey forKey:key];
            }
        }
        if (fullName)
            [contactValues setValue:fullName forKey:@"name"];
        else if (firstName || lastName)
            [contactValues setValue:[NSString stringWithFormat:@"%@ %@", firstName, lastName] forKey:@"name"];

        [self insertContact:contactValues];
        [contactValues release];
    }
}


- (void)prepare {
    [self resetViews];
}

- (void)insertContact:(NSDictionary *)contactDict {
    Contact *c = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:self.managedObjectContext];
    c.list = self.currentList;
//    [self.currentList addContactsObject:c];
    [c setValuesForKeysWithDictionary:contactDict];
}

- (void)resetViews {
    self.importBtnEnabled = NO;
    self.excludeFirstRow = NO;
    self.hideFileInfo = YES;
    self.separator = @",";
    self.fileName = @"";
    self.recordsNumber = 0;
}

- (void)dealloc {
    [_separator release];
    [_fileName release];
    [_contactFields release];
    [_csvFields release];
    [_csvRecords release];
    [super dealloc];
}
@end
