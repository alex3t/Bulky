//
//  AppDelegate.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MainWindowController;
@class PrefsWindowController;
@class WelcomeWindowController;
@class MAAttachedWindow;
@class SpamCheckerWindowController;
@class StoreHelper;

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
    IBOutlet NSPanel *feedbackSheet;
    IBOutlet NSTextField *feedbackName;
    IBOutlet NSTextField *feedbackEmail;
    IBOutlet NSSegmentedControl *feedbackType;
    IBOutlet NSTextView *feedbackMessage;


    MainWindowController *_mainWindowController;
    PrefsWindowController *_prefsWindowController;
    WelcomeWindowController *_welcomeWindowController;
    SpamCheckerWindowController *_spamWindowController;

    NSPersistentStoreCoordinator *__persistentStoreCoordinator;
    NSManagedObjectModel *__managedObjectModel;
    NSManagedObjectContext *__managedObjectContext;

    StoreHelper *_storeHelper;
    BOOL _isProVersion;
    BOOL _hideProVersionFeatures;
    BOOL _hideLiteVersionFeatures;
}


@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property(nonatomic, retain) MainWindowController *mainWindowController;
@property(nonatomic, retain) PrefsWindowController *prefsWindowController;
@property(nonatomic, retain) StoreHelper *storeHelper;
@property(nonatomic, assign) BOOL isProVersion;
@property(nonatomic, assign) BOOL hideProVersionFeatures;
@property(nonatomic, assign) BOOL hideLiteVersionFeatures;


- (IBAction)saveAction:(id)sender;
- (IBAction)openPrefsAction:(id)sender;
- (IBAction)openProductsAction:(id)sender;
- (IBAction)feedbackAction:(id)sender;
- (IBAction)feedbackCloseAction:(id)sender;
- (IBAction)feedbackSendAction:(id)sender;

- (IBAction)projectAddAction:(id)sender;
- (IBAction)projectEditAction:(id)sender;
- (IBAction)projectRemoveAction:(id)sender;

- (IBAction)listAddAction:(id)sender;
- (IBAction)listEditAction:(id)sender;
- (IBAction)listRemoveAction:(id)sender;

- (IBAction)contactAddAction:(id)sender;
- (IBAction)contactImportFromABAction:(id)sender;
- (IBAction)contactImportFromCSVAction:(id)sender;
- (IBAction)contactImportFromListAction:(id)sender;
- (IBAction)contactEditAction:(id)sender;
- (IBAction)contactRemoveAction:(id)sender;

- (IBAction)openSpamCheckerAction:(id)sender;


- (NSInteger)countRecords:(NSString *)entityName by:(NSString *)field andValue:(id)v;
- (NSInteger)countArray:(NSArray *)arr by:(NSString *)field andValue:(id)v;

- (void)showMainWindow;


- (void)showStartupTip;

- (NSString *)flattenHTML:(NSString *)html;
+ (AppDelegate *) instance;
@end
