//
//  ImportFromListWindowController.m
//  Bulky
//
//  Created by iMac on 2/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ImportFromListWindowController.h"
#import "Contact.h"
#import "CoreDataHelper.h"
#import "AppDelegate.h"
#import "List.h"

@interface ImportFromListWindowController ()
- (void)insertContact:(Contact *)c;

- (void)setupSaveBtnStatus;


@end

@implementation ImportFromListWindowController

- (id)init {
    self = [super initWithWindowNibName:@"ImportFromListWindow"];

    return self;
}

- (void)awakeFromNib {
    [contactsCtrl addObserver:self forKeyPath:@"arrangedObjects.checked" options:0 context:nil];
    
}

- (void)dealloc {
    [contactsCtrl removeObserver:self forKeyPath:@"arrangedObjects.checked"];
    [super dealloc];
}


- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    if (skipObserving) return;
    if (object == contactsCtrl && [keyPath isEqualToString:@"arrangedObjects.checked"]) {

        [self setupSaveBtnStatus];
    }

}

- (void)prepare {
//    [listsCtrl setFilterPredicate:[NSPredicate predicateWithFormat:@"objectID != %@",self.currentList.objectID]];
}

- (IBAction)cancelFormAction:(id)sender {
    [self dismissSheet];
}

- (IBAction)importFormAction:(id)sender {
    self.saveEnabled = NO;
    [statusInd startAnimation:self];

    /////////////
    NSArray *selectedContacts = [contactsCtrl.arrangedObjects filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"checked == YES"]];
    for (Contact *contact in selectedContacts) {
        [self insertContact:contact];
    }
    /////////////

    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    [statusInd stopAnimation:self];

    [self dismissSheet];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"switchToContacts" object:nil];
}

- (IBAction)selectContactsAction:(id)sender {
    int tag = ((NSMenuItem *) sender).tag;
    skipObserving = YES;
    if (tag == 2000) {
        //select all
        for (Contact *contact in contactsCtrl.arrangedObjects) {
            contact.checked = [NSNumber numberWithBool:YES];
        }

    } else if (tag == 2001) {
        //deselect all
        for (Contact *contact in contactsCtrl.arrangedObjects) {
            contact.checked = [NSNumber numberWithBool:NO];
        }
    }
    skipObserving = NO;
    [self setupSaveBtnStatus];
}


- (void)insertContact:(Contact *)c {
    Contact *nc = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:self.managedObjectContext];
    NSDictionary *keysDict = [c dictionaryWithValuesForKeys:[Contact copyKeys]];
    [nc setValuesForKeysWithDictionary:keysDict];
    [nc setValue:self.currentList forKey:@"list"];
}

- (void)setupSaveBtnStatus {
    self.saveEnabled = [self.app countArray:contactsCtrl.arrangedObjects by:@"checked" andValue:[NSNumber numberWithBool:YES]] > 0;
}

@end
