//
//  AppDelegate.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"
#import "MainWindowController.h"
#import "PrefsWindowController.h"
#import "Appirater.h"
#import "Feedback.h"
#import "Project.h"
#import "List.h"
#import "Contact.h"
#import "Account.h"
#import "ListSendLog.h"
#import "SendLog.h"
#import "WelcomeWindowController.h"
#import "MAAttachedWindow.h"
#import "SpamCheckerWindowController.h"
#import "StoreHelper.h"

@interface AppDelegate ()
- (void)populateDefaultData;

@end

@implementation AppDelegate


@synthesize mainWindowController = _mainWindowController;
@synthesize prefsWindowController = _prefsWindowController;
@synthesize storeHelper = _storeHelper;
@synthesize isProVersion = _isProVersion;
@synthesize hideProVersionFeatures = _hideProVersionFeatures;
@synthesize hideLiteVersionFeatures = _hideLiteVersionFeatures;


- (void)purchaseSuccess:(NSNotification *)nobj {
    const BOOL pro = self.storeHelper.validatePurchase;
    self.isProVersion = pro;
    self.hideProVersionFeatures = !pro;
    self.hideLiteVersionFeatures = pro;
}

- (id)init {
    self = [super init];
    if (self) {
        _mainWindowController = [[MainWindowController alloc] init];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(purchaseSuccess:)
                                                     name:kInAppPurchaseManagerTransactionSucceededNotification object:nil];
        _storeHelper = [[StoreHelper alloc] init];
    }

    return self;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kInAppPurchaseManagerTransactionSucceededNotification object:nil];

    [__persistentStoreCoordinator release];
    [__managedObjectModel release];
    [__managedObjectContext release];
    [_mainWindowController release];
    [_prefsWindowController release];
    [_welcomeWindowController release];
    [_spamWindowController release];
    [_storeHelper release];
    [super dealloc];
}


- (void)showMainWindow {
//    NSLog(@"showMainWindow");
//    if (_welcomeWindowController)
//    {
//        [_welcomeWindowController close];
//        [_welcomeWindowController release];
//    }
    [[_mainWindowController window] makeKeyAndOrderFront:self];
}

+ (AppDelegate *)instance {
    return (AppDelegate *) [[NSApplication sharedApplication] delegate];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    [self purchaseSuccess:nil];


    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];

    if (![ud boolForKey:@"installed"] && [self countRecords:@"Account" by:nil andValue:nil] == 0) {
        if (!_welcomeWindowController)
            _welcomeWindowController = [[WelcomeWindowController alloc] init];
        [[_welcomeWindowController window] makeKeyAndOrderFront:self];
        [_welcomeWindowController prepare];
    } else
        [self showMainWindow];
//    [self showMainWindow];
//    [self populateDefaultData];
//    [self performSelector:@selector(populateDefaults) withObject:nil]; //performSelectorInBackground

    [Appirater appLaunched:YES];
}


- (BOOL)applicationShouldHandleReopen:(NSApplication *)theApplication hasVisibleWindows:(BOOL)flag {
    if (flag) return YES;

    [self showMainWindow];
    return NO;
}
//
//- (void)applicationWillTerminate:(NSNotification *)theNotification {
//    NSLog(@"applicationWillTerminate");
//    if (_mainWindowController)
//    {
//        [_mainWindowController close];
//    }
//}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication {
    return YES;
}

/**
    Returns the directory the application uses to store the Core Data store file. This code uses a directory named "Bulky" in the user's Library directory.
 */
- (NSURL *)applicationFilesDirectory {

    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSURL *libraryURL = [[fileManager URLsForDirectory:NSApplicationSupportDirectory inDomains:NSUserDomainMask] lastObject];
    return [libraryURL URLByAppendingPathComponent:@"Bulky"];
}

/**
    Creates if necessary and returns the managed object model for the application.
 */
- (NSManagedObjectModel *)managedObjectModel {
    if (__managedObjectModel) {
        return __managedObjectModel;
    }

    NSURL *modelURL = [[NSBundle mainBundle] URLForResource:@"Bulky" withExtension:@"momd"];
    __managedObjectModel = [[NSManagedObjectModel alloc] initWithContentsOfURL:modelURL];
    return __managedObjectModel;
}

/**
    Returns the persistent store coordinator for the application. This implementation creates and return a coordinator, having added the store for the application to it. (The directory for the store is created, if necessary.)
 */
- (NSPersistentStoreCoordinator *)persistentStoreCoordinator {
    if (__persistentStoreCoordinator) {
        return __persistentStoreCoordinator;
    }

    NSManagedObjectModel *mom = [self managedObjectModel];
    if (!mom) {
        NSLog(@"%@:%@ No model to generate a store from", [self class], NSStringFromSelector(_cmd));
        return nil;
    }

    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSURL *applicationFilesDirectory = [self applicationFilesDirectory];
    NSError *error = nil;

    NSDictionary *properties = [applicationFilesDirectory resourceValuesForKeys:[NSArray arrayWithObject:NSURLIsDirectoryKey] error:&error];

    if (!properties) {
        BOOL ok = NO;
        if ([error code] == NSFileReadNoSuchFileError) {
            ok = [fileManager createDirectoryAtPath:[applicationFilesDirectory path] withIntermediateDirectories:YES attributes:nil error:&error];
        }
        if (!ok) {
            [[NSApplication sharedApplication] presentError:error];
            return nil;
        }
    }
    else {
        if ([[properties objectForKey:NSURLIsDirectoryKey] boolValue] != YES) {
            // Customize and localize this error.
            NSString *failureDescription = [NSString stringWithFormat:@"Expected a folder to store application data, found a file (%@).", [applicationFilesDirectory path]];

            NSMutableDictionary *dict = [NSMutableDictionary dictionary];
            [dict setValue:failureDescription forKey:NSLocalizedDescriptionKey];
            error = [NSError errorWithDomain:@"YOUR_ERROR_DOMAIN" code:101 userInfo:dict];

            [[NSApplication sharedApplication] presentError:error];
            return nil;
        }
    }

    NSURL *url = [applicationFilesDirectory URLByAppendingPathComponent:@"Bulky.storedata"];
    NSPersistentStoreCoordinator *coordinator = [[[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel:mom] autorelease];
    if (![coordinator addPersistentStoreWithType:NSSQLiteStoreType configuration:nil URL:url options:nil error:&error]) {
        [[NSApplication sharedApplication] presentError:error];
        return nil;
    }
    __persistentStoreCoordinator = [coordinator retain];

    return __persistentStoreCoordinator;
}

/**
    Returns the managed object context for the application (which is already
    bound to the persistent store coordinator for the application.) 
 */
- (NSManagedObjectContext *)managedObjectContext {
    if (__managedObjectContext) {
        return __managedObjectContext;
    }

    NSPersistentStoreCoordinator *coordinator = [self persistentStoreCoordinator];
    if (!coordinator) {
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        [dict setValue:@"Failed to initialize the store" forKey:NSLocalizedDescriptionKey];
        [dict setValue:@"There was an error building up the data file." forKey:NSLocalizedFailureReasonErrorKey];
        NSError *error = [NSError errorWithDomain:@"YOUR_ERROR_DOMAIN" code:9999 userInfo:dict];
        [[NSApplication sharedApplication] presentError:error];
        return nil;
    }
    __managedObjectContext = [[NSManagedObjectContext alloc] init];
    [__managedObjectContext setPersistentStoreCoordinator:coordinator];

    return __managedObjectContext;
}

/**
    Returns the NSUndoManager for the application. In this case, the manager returned is that of the managed object context for the application.
 */
- (NSUndoManager *)windowWillReturnUndoManager:(NSWindow *)window {
    return [[self managedObjectContext] undoManager];
}

/**
    Performs the save action for the application, which is to send the save: message to the application's managed object context. Any encountered errors are presented to the user.
 */
- (IBAction)saveAction:(id)sender {
    NSError *error = nil;

    if (![[self managedObjectContext] commitEditing]) {
        NSLog(@"%@:%@ unable to commit editing before saving", [self class], NSStringFromSelector(_cmd));
    }

    if (![[self managedObjectContext] save:&error]) {
        NSLog(@"Unresolved error %@, %@", error, [error userInfo]);
        [[NSApplication sharedApplication] presentError:error];
    }
}

- (IBAction)openPrefsAction:(id)sender {
    if (!_prefsWindowController)
        _prefsWindowController = [[PrefsWindowController alloc] initWithContext:self.managedObjectContext];

    [_prefsWindowController showWindow:self.mainWindowController.window forTab:0];
}

- (void)openProductsAction:(id)sender {
    if (!_prefsWindowController)
        _prefsWindowController = [[PrefsWindowController alloc] initWithContext:self.managedObjectContext];

    [_prefsWindowController showWindow:self.mainWindowController.window forTab:1];
}


- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender {

    // Save changes in the application's managed object context before the application terminates.

    if (!__managedObjectContext) {
        return NSTerminateNow;
    }

    if (![[self managedObjectContext] commitEditing]) {
        NSLog(@"%@:%@ unable to commit editing to terminate", [self class], NSStringFromSelector(_cmd));
        return NSTerminateCancel;
    }

    if (![[self managedObjectContext] hasChanges]) {
        return NSTerminateNow;
    }

    NSError *error = nil;
    if (![[self managedObjectContext] save:&error]) {
        NSLog(@"applicationShouldTerminate error %@, %@", error, [error userInfo]);
//
//        BOOL result = [sender presentError:error];
//        if (result) {
//            return NSTerminateCancel;
//        }
//
//        NSString *question = NSLocalizedString(@"Could not save changes while quitting. Quit anyway?", @"Quit without saves error question message");
//        NSString *info = NSLocalizedString(@"Quitting now will lose any changes you have made since the last successful save", @"Quit without saves error question info");
//        NSString *quitButton = NSLocalizedString(@"Quit anyway", @"Quit anyway button title");
//        NSString *cancelButton = NSLocalizedString(@"Cancel", @"Cancel button title");
//        NSAlert *alert = [[[NSAlert alloc] init] autorelease];
//        [alert setMessageText:question];
//        [alert setInformativeText:info];
//        [alert addButtonWithTitle:quitButton];
//        [alert addButtonWithTitle:cancelButton];
//
//        NSInteger answer = [alert runModal];
//
//        if (answer == NSAlertAlternateReturn) {
//            return NSTerminateCancel;
//        }
    }

    return NSTerminateNow;
}



//////////////////////////////////



- (IBAction)feedbackAction:(id)sender {
    [NSApp beginSheet:feedbackSheet modalForWindow:[_mainWindowController window] modalDelegate:self didEndSelector:NSSelectorFromString(@"feedbackSheetDidEnd:returnCode:contextInfo:") contextInfo:nil];
}

- (IBAction)feedbackCloseAction:(id)sender {
    [NSApp endSheet:feedbackSheet returnCode:NSCancelButton];
}

- (IBAction)feedbackSendAction:(id)sender {
    [NSApp endSheet:feedbackSheet returnCode:NSOKButton];
}

- (IBAction)projectAddAction:(id)sender {
    [self.mainWindowController addProjectAction:sender];
}

- (IBAction)projectEditAction:(id)sender {
    [self.mainWindowController editMenuAction:sender];
}

- (IBAction)projectRemoveAction:(id)sender {
    [self.mainWindowController removeMenuAction:sender];
}

- (IBAction)listAddAction:(id)sender {
    [self.mainWindowController addListAction:sender];
}

- (IBAction)listEditAction:(id)sender {
    [self.mainWindowController editMenuAction:sender];
}

- (IBAction)listRemoveAction:(id)sender {
    [self.mainWindowController removeMenuAction:sender];
}

- (IBAction)contactAddAction:(id)sender {
    [self.mainWindowController addContactAction:sender];
}

- (IBAction)contactImportFromABAction:(id)sender {
    [self.mainWindowController importABContactAction:sender];
}

- (IBAction)contactImportFromCSVAction:(id)sender {
    [self.mainWindowController importCSVContactAction:sender];
}

- (IBAction)contactImportFromListAction:(id)sender {
    [self.mainWindowController importFromListAction:sender];
}

- (IBAction)contactEditAction:(id)sender {
    [self.mainWindowController editContactAction:sender];
}

- (IBAction)contactRemoveAction:(id)sender {
    [self.mainWindowController removeContactAction:sender];
}

- (IBAction)openSpamCheckerAction:(id)sender {
    if (!_spamWindowController)
        _spamWindowController = [[SpamCheckerWindowController alloc] init];
    _spamWindowController.parent = self.mainWindowController;
    [_spamWindowController showWindow:self.mainWindowController.window];
    [_spamWindowController checkAction:nil];
}


- (void)feedbackSheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode  contextInfo:(void *)contextInfo {
    if (returnCode == NSOKButton) {
        [Feedback send:feedbackName.stringValue email:feedbackEmail.stringValue type:[feedbackType labelForSegment:feedbackType.selectedSegment] message:feedbackMessage.textStorage.string];
        [feedbackSheet orderOut:self];
        NSAlert *alertPanel = [NSAlert alertWithMessageText:@"Message sent successfully." defaultButton:nil alternateButton:nil otherButton:nil informativeTextWithFormat:@""];
        [alertPanel runModal];
    } else {
        [feedbackSheet orderOut:self];
    }
}


- (NSInteger)countRecords:(NSString *)entityName by:(NSString *)field andValue:(id)v {
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    [request setEntity:[NSEntityDescription entityForName:entityName inManagedObjectContext:self.managedObjectContext]];

    [request setIncludesSubentities:NO]; //Omit subentities. Default is YES (i.e. include subentities)
    if (field && v)
        [request setPredicate:[NSPredicate predicateWithFormat:@"%K == %@", field, v]];

    NSError *err;
    NSUInteger count = [self.managedObjectContext countForFetchRequest:request error:&err];
    if (count == NSNotFound) {
        return 0;
    }

    [request release];
    return count;
}

- (NSInteger)countArray:(NSArray *)arr by:(NSString *)field andValue:(id)v {
    if (field) {
        NSPredicate *predicate = [NSPredicate predicateWithFormat:@"%K == %@", field, v];
        arr = [arr filteredArrayUsingPredicate:predicate];
    }
    return arr.count;
}


- (void)populateDefaultData {
    //StinkyShot@mailinator.com
    //contoso.com
    Account *a = [NSEntityDescription insertNewObjectForEntityForName:@"Account" inManagedObjectContext:[self managedObjectContext]];
    a.name = @"test";
    a.fromName = @"From";
    a.fromEmail = @"www@www.com";
    a.provider = @"GMail";
    a.host = @"smtp.gmail.com";
    a.port = [NSNumber numberWithInt:587];
    a.ssl = [NSNumber numberWithBool:YES];
    a.login = @"redvokdev@gmail.com";
    a.password = @"alexqwerty@4";

    Project *p1 = [NSEntityDescription insertNewObjectForEntityForName:@"Project" inManagedObjectContext:[self managedObjectContext]];
    [p1 setValue:@"Project#1" forKey:@"name"];
    p1.account = a;
    Project *p2 = [NSEntityDescription insertNewObjectForEntityForName:@"Project" inManagedObjectContext:[self managedObjectContext]];
    [p2 setValue:@"Project#2" forKey:@"name"];
    p2.account = a;

    List *l = [NSEntityDescription insertNewObjectForEntityForName:@"List" inManagedObjectContext:[self managedObjectContext]];
    l.name = @"List #1";
    l.project = p1;
    for (int i = 0; i < 90; i++) {
        Contact *c = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self managedObjectContext]];
        c.email = [NSString stringWithFormat:@"user1-%i@contoso.com", i];
        c.name = [NSString stringWithFormat:@"User 1-%i", i];
        c.list = l;
        [l addContactsObject:c];
    }
    Contact *c1 = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self managedObjectContext]];
    c1.email = @"StinkyShot@mailinator.com";
    c1.list = l;
    [l addContactsObject:c1];
    [p1 addListsObject:l];


    List *l2 = [NSEntityDescription insertNewObjectForEntityForName:@"List" inManagedObjectContext:[self managedObjectContext]];
    l2.name = @"List #2";
    l2.project = p1;
    ListSendLog *l2sl = [NSEntityDescription insertNewObjectForEntityForName:@"ListSendLog" inManagedObjectContext:[self managedObjectContext]];
    l2sl.list = l2;
    for (int i = 0; i < 190; i++) {
        Contact *c = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self managedObjectContext]];
        c.email = [NSString stringWithFormat:@"user2-%i@contoso.com", i];
        c.name = [NSString stringWithFormat:@"User 2-%i", i];
        c.list = l2;
        [l2 addContactsObject:c];

        SendLog *sl = [NSEntityDescription insertNewObjectForEntityForName:@"SendLog" inManagedObjectContext:[self managedObjectContext]];
        sl.contact = c;
        sl.listSendLog = l2sl;
        sl.date = [NSDate date];
        if (i % 5) {
            sl.isError = [NSNumber numberWithBool:YES];
            sl.error = @"Undefined error";
        }
    }
    [p1 addListsObject:l2];

    List *l3 = [NSEntityDescription insertNewObjectForEntityForName:@"List" inManagedObjectContext:[self managedObjectContext]];
    l3.name = @"List #3";
    l3.project = p2;
    for (int i = 0; i < 290; i++) {
        Contact *c = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self managedObjectContext]];
        c.email = [NSString stringWithFormat:@"user3-%i@contoso.com", i];
        c.name = [NSString stringWithFormat:@"User 3-%i", i];
        c.list = l3;
        [l3 addContactsObject:c];
    }
    [p2 addListsObject:l3];

    [self saveAction:nil];


}

- (void)showStartupTip {
    [_mainWindowController showStartupTip];

}

- (NSString *)flattenHTML:(NSString *)html {
    BOOL trim = YES;
    NSScanner *theScanner;
    NSString *text = nil;

    theScanner = [NSScanner scannerWithString:html];

    while ([theScanner isAtEnd] == NO) {
        // find start of tag
        [theScanner scanUpToString:@"<" intoString:NULL];
        // find end of tag
        [theScanner scanUpToString:@">" intoString:&text];

        // replace the found tag with a space
        //(you can filter multi-spaces out later if you wish)
        html = [html stringByReplacingOccurrencesOfString:
                [NSString stringWithFormat:@"%@>", text]
                                               withString:@" "];

    } // while //

    // trim off whitespace
    return trim ? [html stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] : html;
}

@end
