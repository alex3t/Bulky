//
//  ContactWindowController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ContactWindowController.h"
#import "Contact.h"
#import "AppDelegate.h"
#import "CoreDataHelper.h"
#import "List.h"

@interface ContactWindowController ()
- (void)validate;

- (void)save;


@end

@implementation ContactWindowController

@synthesize obj = _obj;

@synthesize titles = _titles;



- (id)init {
    self = [super initWithWindowNibName:@"ContactWindow"];
    self.titles =  [NSArray arrayWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"titles" ofType:@"plist"]];
    return self;
}


- (void)awakeFromNib {

}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {

    if (object == self.obj) {
        [self validate];
    }
}


- (void)dealloc {
//    [_obj removeObserver:self forKeyPath:@"email"];
    [_obj release];

    [_titles release];

    [super dealloc];
}

#pragma mark Actions

- (IBAction)cancelFormAction:(id)sender {
//    [self.managedObjectContext rollback];
    [self dismissSheet];
}

- (IBAction)saveFormAction:(id)sender {
    [self save];
    [self dismissSheet];
}

- (IBAction)saveAndNewFormAction:(id)sender {
    [self save];
    [self prepare];
}


#pragma mark Methods

- (void)prepare {
    NSRect cancelBtnRect = NSMakeRect(303, 12, 120, 32);
    NSRect saveAndNewBtnRect = NSMakeRect(427, 12, 120, 32);

    if (self.editId) {
        self.obj = (Contact *) [self.managedObjectContext objectWithID:self.editId];
        [saveAndNewBtn setHidden:YES];
        [cancelBtn setFrame:saveAndNewBtnRect];
    } else {
        self.obj = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self managedObjectContext]];
        [saveAndNewBtn setHidden:NO];
        [cancelBtn setFrame:cancelBtnRect];
        [saveAndNewBtn setFrame:saveAndNewBtnRect];

    }
//    [_obj addObserver:self forKeyPath:@"name" options:0 context:nil];
    [self validate];
}

- (void)validate {
    NSError *err = nil;
    [self.obj validateForInsert:&err];
    self.saveEnabled = err == nil;
}

- (void)save {
    if (!self.editId)
    {
        self.obj.list = self.currentList;
    }
    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"switchToContacts" object:nil];
}


@end
