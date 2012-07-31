//
//  DESSheetController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class AppDelegate;
@class List;

@interface BaseSheetController : NSWindowController
{
    NSManagedObjectID *_editId;
    List *_currentList;
    BOOL _saveEnabled;
    NSManagedObjectContext *_managedObjectContext;
    NSManagedObjectContext *_parentManagedObjectContext;

}

@property(nonatomic) BOOL saveEnabled;
@property(nonatomic, readonly) NSManagedObjectContext *managedObjectContext;
@property(nonatomic, retain) NSManagedObjectContext *parentManagedObjectContext;

@property(nonatomic, retain) NSManagedObjectID *editId;
@property(nonatomic, retain) List *currentList;


- (void)dismissSheet;

- (AppDelegate *)app;

- (void)prepare;
- (NSWindow*)windowWithId:(NSManagedObjectID *)editId;
- (NSWindow *)windowWithId:(NSManagedObjectID *)id1 andListId:(NSManagedObjectID *)listId;
@end
