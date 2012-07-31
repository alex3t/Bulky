//
//  ABWindowController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <AddressBook/AddressBook.h>
#import "ImportABWindowController.h"
#import "CoreDataHelper.h"
#import "List.h"
#import "Contact.h"

Boolean FindFirstMatch(ABMutableMultiValue *multiValue, NSString *label, int *index) {
    unsigned int mvCount = 0;
    int x;

    mvCount = [multiValue count];
    if (mvCount > 0) {
        for (x = 0; x < mvCount; x++) {
            NSString *text = [multiValue labelAtIndex:x];
            NSComparisonResult result = [text compare:label];

            if (result == NSOrderedSame) {
                *index = x;
                return true;
            }
        }
    }
    return false;
}

@interface ImportABWindowController ()
- (void)insertContact:(NSDictionary *)contactDict;

- (void)populateAbRecords;

- (NSString *)emptyIfNil:(NSString *)str;


@end

@implementation ImportABWindowController
@synthesize abRecords = _abRecords;
@synthesize selectedAbRecords = _selectedAbRecords;


- (id)init {
    self = [super initWithWindowNibName:@"ImportABWindow"];

    _abRecords = [[NSMutableArray alloc] init];
    return self;
}

- (void)awakeFromNib {
    [recordsCtrl addObserver:self forKeyPath:@"arrangedObjects.checked" options:0 context:nil];
}


- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {

    if (object == recordsCtrl && [keyPath isEqualToString:@"arrangedObjects.checked"]) {

        self.selectedAbRecords = [self.abRecords filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"checked == YES"]];
        self.saveEnabled = self.selectedAbRecords.count > 0;
    }

}

- (void)dealloc {
    [recordsCtrl removeObserver:self forKeyPath:@"arrangedObjects.checked"];

    [_abRecords release];
    [_selectedAbRecords release];
    [super dealloc];
}

#pragma mark Actions

- (IBAction)cancelFormAction:(id)sender {
//    [self.managedObjectContext rollback];
    [self dismissSheet];
}

- (IBAction)importFormAction:(id)sender {
    self.saveEnabled = NO;
    [saveInd startAnimation:self];

    for (int i = 0; i < self.abRecords.count; i++) {
        NSDictionary *cr = [self.abRecords objectAtIndex:(NSUInteger) i];
        [self insertContact:cr];
    }
    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    self.saveEnabled = YES;
    [saveInd stopAnimation:self];

    [self dismissSheet];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"switchToContacts" object:nil];
}

#pragma mark Methods

- (void)prepare {
    [self populateAbRecords];
    self.saveEnabled = (self.selectedAbRecords.count > 0);

}

- (void)insertContact:(NSDictionary *)contactDict {
    Contact *c = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:self.managedObjectContext];
    c.list = self.currentList;
//    [self.currentList addContactsObject:c];
    [c setValuesForKeysWithDictionary:contactDict];
}


- (void)populateAbRecords {
    //[self.abRecords removeAllObjects];

    NSMutableArray *r = [NSMutableArray array];
    NSArray *people = [[ABAddressBook sharedAddressBook] people];
    for (int i = 0; i < people.count; i++) {
        ABRecord *person = [people objectAtIndex:(NSUInteger) i];
//        NSLog(@"p=%@",person);
        int index = 0;
        ABMutableMultiValue *anAddressList = [[person valueForProperty:kABAddressProperty] mutableCopy];
        NSUInteger primaryIndex = [anAddressList indexForIdentifier:[anAddressList primaryIdentifier]];
        NSMutableDictionary *anAddress = [[anAddressList valueAtIndex:primaryIndex] mutableCopy];
        NSString *country = (NSString *) [anAddress objectForKey:kABAddressCountryKey];
        NSString *street = (NSString *) [anAddress objectForKey:kABAddressStreetKey];
        NSString *city = (NSString *) [anAddress objectForKey:kABAddressCityKey];
        NSString *zip = (NSString *) [anAddress objectForKey:kABAddressZIPKey];
        NSString *state = (NSString *) [anAddress objectForKey:kABAddressStateKey];
        NSString *firstName = [person valueForProperty:kABFirstNameProperty];
        NSString *lastName = [person valueForProperty:kABLastNameProperty];
        NSString *nickname = [person valueForProperty:kABNicknameProperty];
        NSString *title = [person valueForProperty:kABTitleProperty];
        NSString *phone = nil;
        NSString *mobile = nil;
        ABMutableMultiValue *anPhonesList = [[person valueForProperty:kABPhoneProperty] mutableCopy];
        if (FindFirstMatch(anPhonesList, kABPhoneMainLabel, &index)) {
            phone = [anPhonesList valueAtIndex:(NSUInteger) index];
        }
        if (!phone) {
            if (FindFirstMatch(anPhonesList, kABPhoneHomeLabel, &index)) {
                phone = [anPhonesList valueAtIndex:(NSUInteger) index];
            }
        }
        if (FindFirstMatch(anPhonesList, kABPhoneMobileLabel, &index)) {
            mobile = [anPhonesList valueAtIndex:(NSUInteger) index];
        }
        NSString *email = nil;
        ABMutableMultiValue *anEmailsList = [[person valueForProperty:kABEmailProperty] mutableCopy];
        if (FindFirstMatch(anEmailsList, kABEmailHomeLabel, &index)) {
            email = [anEmailsList valueAtIndex:(NSUInteger) index];
        }


        NSString *name = [NSString stringWithFormat:@"%@ %@", [self emptyIfNil:firstName], [self emptyIfNil:lastName]];
//        NSString *address = [NSString stringWithFormat:@"%@\n%@, %@ %@", [self emptyIfNil:street], [self emptyIfNil:city], [self emptyIfNil:state], [self emptyIfNil:zip]];

        NSMutableDictionary *contactHolder = [[NSMutableDictionary alloc] init];
        [contactHolder setValue:name forKey:@"name"];
        [contactHolder setValue:nickname forKey:@"nickname"];
        [contactHolder setValue:title forKey:@"title"];
        [contactHolder setValue:phone forKey:@"phone"];
        [contactHolder setValue:mobile forKey:@"mobile"];
        [contactHolder setValue:email forKey:@"email"];
        [contactHolder setValue:street forKey:@"street"];
        [contactHolder setValue:city forKey:@"city"];
        [contactHolder setValue:state forKey:@"state"];
        [contactHolder setValue:zip forKey:@"zip"];
        [contactHolder setValue:country forKey:@"country"];
        [contactHolder setValue:[NSNumber numberWithBool:NO] forKey:@"checked"];

//        if (firstName && lastName)
        //[self.abRecords addObject:contactHolder];
        [r addObject:contactHolder];

        [anAddress release];
        [anAddressList release];
        [contactHolder release];
        [anPhonesList release];
        [anEmailsList release];
    }

//    self.selectedAbRecords = [self.abRecords filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"checked == YES"]];
    self.abRecords = r;
//    NSLog(@"contacth=%@", self.abRecords);

}

- (NSString *)emptyIfNil:(NSString *)str {
    if (!str)
        return @"";
    else
        return str;
}
@end
