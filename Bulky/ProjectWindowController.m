//
//  ProjectWindowController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ProjectWindowController.h"
#import "Project.h"
#import "AppDelegate.h"
#import "CoreDataHelper.h"
#import "Account.h"
#import "List.h"


@interface ProjectWindowController ()
- (void)validate;

- (void)save;

@end

@implementation ProjectWindowController

@synthesize obj = _obj;


- (void)reloadAccounts {
//    NSLog(@"reloadAccounts");
    NSError *e = nil;
    [accountsCtrl fetchWithRequest:nil merge:NO error:&e];

    BOOL found = NO;
    for (Account *a in [accountsCtrl arrangedObjects]) {
        if ([a isEqual:self.obj.account]) {
            found = YES;
            break;
        }
    }
    if (!found) {
        if ([[accountsCtrl arrangedObjects] count] > 0)
            self.obj.account = [[accountsCtrl arrangedObjects] objectAtIndex:0];
        else
            self.obj.account = nil;
    }
//
//    NSLog(@"self.obj.account = %@", self.obj.account);
//    NSLog(@"[objCtrl.content = %@", [objCtrl.content valueForKey:@"account"]);
}

- (id)init {
    self = [super initWithWindowNibName:@"ProjectWindow"];
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    self.parentManagedObjectContext = app.managedObjectContext;
    if ([self.parentManagedObjectContext hasChanges]) {
        NSError *error = nil;
        [self.parentManagedObjectContext save:&error];
    }
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(reloadAccounts)
                                                 name:@"accountsUpdated"
                                               object:nil];
    return self;
}

- (void)awakeFromNib {
    [accountsCtrl setSortDescriptors:[NSArray arrayWithObjects:[NSSortDescriptor sortDescriptorWithKey:@"isDefault" ascending:NO], [NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES], nil]];
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {

    if (object == self.obj) {
        [self validate];
    }
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"accountsUpdated" object:nil];
    [_obj removeObserver:self forKeyPath:@"name"];
    [_obj release];

    [super dealloc];
}

#pragma mark Actions
- (IBAction)openAccountPrefsActions:(id)sender {
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    [app openPrefsAction:sender];
}

- (IBAction)cancelFormAction:(id)sender {
//    [self.managedObjectContext rollback];
    [self dismissSheet];
}

- (IBAction)saveFormAction:(id)sender {
    [self save];
    [self dismissSheet];
}

#pragma mark Methods

- (void)prepare {
    NSError *error;
    [accountsCtrl fetchWithRequest:nil merge:NO error:&error];
    if (self.editId) {
        self.obj = (Project *) [self.managedObjectContext objectWithID:self.editId];
    } else {
        self.obj = [NSEntityDescription insertNewObjectForEntityForName:@"Project" inManagedObjectContext:[self managedObjectContext]];
        if ([[accountsCtrl arrangedObjects] count] > 0)
            self.obj.account = [[accountsCtrl arrangedObjects] objectAtIndex:0];
    }
    [_obj addObserver:self forKeyPath:@"name" options:0 context:nil];
//    [_obj addObserver:self forKeyPath:@"account" options:0 context:nil];
    [self validate];
}

- (void)validate {
    NSError *err = nil;
    [self.obj validateForInsert:&err];
    self.saveEnabled = err == nil;
}

- (void)save {
    List *l = nil;
    if (!self.editId) {
        l = [NSEntityDescription insertNewObjectForEntityForName:@"List" inManagedObjectContext:[self managedObjectContext]];
        l.name = @"Default";
        l.project = self.obj;
    }

    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"projectsUpdated" object:nil];
    if (!self.editId) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"listsUpdated" object:nil];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"selectListMenu" object:l.objectID];
    }
    [self.managedObjectContext rollback];
}


@end
