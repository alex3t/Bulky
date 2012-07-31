//
//  DESSheetController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"
#import "AppDelegate.h"
#import "List.h"

@implementation BaseSheetController
#pragma mark inherited methods

@synthesize editId = _editId;
@synthesize currentList = _currentList;
@synthesize saveEnabled = _saveEnabled;
@synthesize parentManagedObjectContext = _parentManagedObjectContext;


- (id)initWithWindowNibName:(NSString *)nibName {
    self = [super initWithWindowNibName:nibName];
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    self.parentManagedObjectContext = app.managedObjectContext;
    if ([self.parentManagedObjectContext hasChanges]) {
        NSError *error = nil;
        [self.parentManagedObjectContext save:&error];
    }
    return self;
}

- (NSWindow*)windowWithId:(NSManagedObjectID *)editId {
    self.editId = editId;
    NSWindow* window = [super window];
    [self prepare];
    return window;
}

- (NSWindow *)windowWithId:(NSManagedObjectID *)id1 andListId:(NSManagedObjectID *)listId {
    NSWindow *w = [self windowWithId:id1];
    if (listId)
        self.currentList = (List *) [self.managedObjectContext objectWithID:listId];
    return w;
}

- (NSManagedObjectContext *)managedObjectContext {
    if (_managedObjectContext == nil) {
        _managedObjectContext = [[NSManagedObjectContext alloc] init];
        [_managedObjectContext setPersistentStoreCoordinator:[[self parentManagedObjectContext] persistentStoreCoordinator]];
    }
    return _managedObjectContext;
}

#pragma mark private methods

- (void)prepare {
    // do nothing by design, overridden by sub-classes
}

- (void)dismissSheet {
    // note the use of super instead of self in order to bypass the sheet reset code 
    // via the hydrateView method
    [NSApp endSheet:[super window] returnCode:NSOKButton];
    [[super window] orderOut:self];
}

- (void)dealloc {
    [_editId release];
    [_currentList release];
    [_parentManagedObjectContext release];
    [_managedObjectContext release];
    [super dealloc];
}


- (AppDelegate *)app {
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    return app;
}

@end
