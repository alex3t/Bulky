//
//  ListWindowController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ListWindowController.h"
#import "List.h"
#import "AppDelegate.h"
#import "CoreDataHelper.h"
#import "Project.h"
#import "Contact.h"
#import "StoreHelper.h"

@interface ListWindowController ()
- (void)validate;

- (void)save;


@end

@implementation ListWindowController
@synthesize obj = _obj;
@synthesize allowSelectList = _allowSelectList;
@synthesize hideCopyBlock = _hideCopyBlock;


- (void)reloadProjects {
    NSError *e = nil;
    NSError *e2 = nil;
    [projectsCtrl fetchWithRequest:nil merge:NO error:&e];
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    if ([app countRecords:@"Project" by:nil andValue:nil] >= 2) {
        [projectsForCopyCtrl fetchWithRequest:nil merge:NO error:&e2];
        [listsForCopyCtrl rearrangeObjects];
    }

    BOOL found = NO;
    for (Project *a in [projectsCtrl arrangedObjects]) {
        if ([a isEqual:self.obj.project]) {
            found = YES;
            break;
        }
    }
    if (!found) {
        if ([[projectsCtrl arrangedObjects] count] > 0)
            self.obj.project = [[projectsCtrl arrangedObjects] objectAtIndex:0];
        else
            self.obj.project = nil;
    }
}

- (id)init {
    self = [super initWithWindowNibName:@"ListWindow"];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(reloadProjects)
                                                 name:@"projectsUpdated"
                                               object:nil];
    return self;
}

- (void)awakeFromNib {
    [super awakeFromNib];


}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {

    if (object == self.obj) {
        [self validate];
    }
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"projectsUpdated" object:nil];
    [_obj removeObserver:self forKeyPath:@"name"];
    [_obj removeObserver:self forKeyPath:@"project"];
    [_obj release];
    [super dealloc];
}

#pragma mark Actions

- (IBAction)cancelFormAction:(id)sender {
    [self.managedObjectContext rollback];
    [self dismissSheet];
}

- (IBAction)saveFormAction:(id)sender {

        [self save];

    [self dismissSheet];
}

- (IBAction)checkForCopyAction:(id)sender {
    self.allowSelectList = ((NSButton *) sender).state == NSOnState;
}


#pragma mark Methods

- (void)prepare {
    NSError *error;
    [projectsCtrl fetchWithRequest:nil merge:NO error:&error];
    [projectsCtrl rearrangeObjects];
    if (self.editId) {
        self.obj = (List *) [self.managedObjectContext objectWithID:self.editId];
    } else {
        self.obj = [NSEntityDescription insertNewObjectForEntityForName:@"List" inManagedObjectContext:[self managedObjectContext]];
        if ([[projectsCtrl arrangedObjects] count] > 0)
            self.obj.project = [[projectsCtrl arrangedObjects] objectAtIndex:0];
    }
    [_obj addObserver:self forKeyPath:@"name" options:0 context:nil];
    [_obj addObserver:self forKeyPath:@"project" options:0 context:nil];
    [self validate];
    self.hideCopyBlock = self.editId != nil;
    [listsForCopyCtrl setFilterPredicate:[NSPredicate predicateWithFormat:@"objectID != %@",self.obj.objectID]];
}

- (void)validate {
    NSError *err = nil;
    [self.obj validateForInsert:&err];
    self.saveEnabled = err == nil;
}

- (void)save {
//    NSLog(@"listsForCopyCtrl.selectedObjects = %@", listsForCopyCtrl.selectedObjects);
    if (!self.editId && self.allowSelectList && [listsForCopyCtrl.selectedObjects count] > 0) {
        List *listForCopy = [listsForCopyCtrl.selectedObjects objectAtIndex:0];
        [savingInd startAnimation:self];
        NSMutableSet *copiedContacts = [[NSMutableSet alloc] init];
        for (Contact *contact in listForCopy.contacts) {
            NSDictionary *keysDict = [contact dictionaryWithValuesForKeys:[Contact copyKeys]];
            NSManagedObject *cc = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:self.managedObjectContext];
            [cc setValuesForKeysWithDictionary:keysDict];
            [cc setValue:self.obj forKey:@"list"];
//            NSLog(@"coping:%@",cc);
        }
        [self.obj addContacts:copiedContacts];
        [copiedContacts release];
        [savingInd stopAnimation:self];
    }

    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"listsUpdated" object:nil];
    if (!self.editId)
        [[NSNotificationCenter defaultCenter] postNotificationName:@"selectListMenu" object:self.obj.objectID];
}

@end
