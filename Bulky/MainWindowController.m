//
//  Created by imac on 1/29/12.
//


#import <QuartzCore/QuartzCore.h>
#import "MainWindowController.h"
#import "EmailSender.h"
#import "Contact.h"
#import "List.h"
#import "Project.h"
#import "ProjectWindowController.h"
#import "ListWindowController.h"
#import "ContactWindowController.h"
#import "ImportCSVWindowController.h"
#import "ImportABWindowController.h"
#import "PrefsWindowController.h"
#import "AppDelegate.h"
#import "NSTreeController+DMExtensions.h"
#import "ImportFromListWindowController.h"
#import "Account.h"
#import "MAAttachedWindow.h"
#import "ListSendLog.h"
#import "SendLog.h"
#import "StoreHelper.h"


@interface MainWindowController ()

- (void)blastFinished;


- (AppDelegate *)app;

- (NSArray *)checkedContacts;


- (void)calculateSelectedContacts;

- (NSPredicate *)searchPredicate:(NSString *)str;

- (void)populateTemplate;

- (void)hideStartupTip;


@end

@implementation MainWindowController {

}

@synthesize hideContactList = _hideContactList;
@synthesize allowEditProject = _allowEditProject;
@synthesize allowEditList = _allowEditList;
@synthesize projectWindowCtrl = _projectWindowCtrl;
@synthesize listWindowCtrl = _listWindowCtrl;
@synthesize contactWindowCtrl = _contactWindowCtrl;
@synthesize csvWindowCtrl = _csvWindowCtrl;
@synthesize abWindowCtrl = _abWindowCtrl;
@synthesize prefsWindowCtrl = _prefsWindowCtrl;
@synthesize allowAddContact = _allowAddContact;
@synthesize allowStart = _allowStart;
@synthesize allowEditMenu = _allowEditMenu;
@synthesize hideTemplateBtn = _hideTemplateBtn;
@synthesize hideContactsBtn = _hideContactsBtn;
@synthesize currentList = _currentList;
@synthesize hideStopBlastBtn = _hideStopBlastBtn;
@synthesize allowStartBtn = _allowStartBtn;
@synthesize currentProject = _currentProject;
@synthesize hideDetailsPlaceholder = _hideDetailsPlaceholder;
@synthesize currentView = _currentView;
@synthesize contactsCountStr = _contactsCountStr;
@synthesize importFromListWindowCtrl = _importFromListWindowCtrl;
@synthesize sentIndCount = _sentIndCount;
@synthesize contactsForSendCount = _contactsForSendCount;
@synthesize statusTxt = _statusTxt;
@synthesize templateVars = _templateVars;


- (id)init {
    self = [super initWithWindowNibName:@"MainWindow"];
    if (self) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(selectListMenu:)
                                                     name:@"selectListMenu"
                                                   object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(switchToContactsAction:)
                                                     name:@"switchToContacts"
                                                   object:nil];
        emailSender = [[EmailSender alloc] initWithDelegate:self progressCallback:@selector(emailProgress:) errorCallback:@selector(emailError:) finishCallback:@selector(emailFinished:)];

        self.templateVars = [NSDictionary dictionaryWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"templateVars" ofType:@"plist"]];

    }
    return self;
}

- (void)expandMenuItems {
    [menuTable expandItem:nil expandChildren:YES];
    [menuTable selectRowIndexes:[NSIndexSet indexSetWithIndex:1] byExtendingSelection:NO];
}

- (void)awakeFromNib {
    self.hideContactList = YES;
    self.allowStart = YES;
    self.hideTemplateBtn = YES;
    self.hideContactsBtn = NO;
    self.hideStopBlastBtn = YES;
    self.allowStartBtn = NO;

    [menuCtrl setSortDescriptors:[NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES]]];
    [projectsCtrl setSortDescriptors:[NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES]]];
    [menuCtrl addObserver:self forKeyPath:@"selectedObjects" options:NSKeyValueObservingOptionNew context:nil];
    [contactsCtrl addObserver:self forKeyPath:@"arrangedObjects.checked" options:NSKeyValueObservingOptionNew context:nil];

    [contactsCtrl setSortDescriptors:[NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES]]];


    [self performSelector:@selector(expandMenuItems) withObject:nil afterDelay:0.0];

    titleView.wantsLayer = YES;
    titleView.layer.contents = (id) [NSImage imageNamed:@"bg.png"];

//    NSString *path = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"template.html"];
//    NSString *htmlContent = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
//    NSURL *url = [NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]];
//    [[templateWebView mainFrame] loadHTMLString:htmlContent baseURL:url];

    [contactsTable setDoubleAction:@selector(editContactAction:)];
    [contactsTable setTarget:self];
}

- (void)windowDidLoad {

    [super windowDidLoad];

    NSView *contentVieww = contentView;//[[self window] contentView];
    [contentVieww setWantsLayer:YES];
    [contentVieww addSubview:[self currentView]];
    transition = [CATransition animation];
    [transition setType:kCATransitionPush];
    [transition setSubtype:kCATransitionFromRight];
    NSDictionary *ani = [NSDictionary dictionaryWithObject:transition forKey:@"subviews"];
    [contentVieww setAnimations:ani];
    self.currentView = templateView;
    [templateView setFrame:[contentView frame]];
    [templateView setAutoresizingMask:[contentView autoresizingMask]];
    [contentView addSubview:templateView];
}


- (void)detailContentSwitch {
    NSView *view;
    NSView *view2;
    if (self.currentView == templateView) {
        view = contactsView;
        view2 = templateView;
        self.currentView = contactsView;
        self.hideContactsBtn = YES;
        self.hideTemplateBtn = NO;
        [transition setSubtype:kCATransitionFromRight];

    } else {
        view = templateView;
        view2 = contactsView;
        self.currentView = templateView;
        self.hideContactsBtn = NO;
        self.hideTemplateBtn = YES;
        [transition setSubtype:kCATransitionFromLeft];
    }
    [view setFrame:[contentView frame]];
    [view setAutoresizingMask:[contentView autoresizingMask]];
    [[contentView animator] replaceSubview:view2 with:view];
}

#pragma mark Notifications
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    if (skipObserving) return;

    if ([object isEqual:menuCtrl]) {
        if ([menuCtrl.selectedObjects count] > 0) {
            id o = [menuCtrl.selectedObjects objectAtIndex:0];
            self.allowEditMenu = [o isKindOfClass:[Project class]] || [o isKindOfClass:[List class]];
            self.allowEditList = [o isKindOfClass:[List class]];
            self.hideContactList = ![o isKindOfClass:[List class]];
            self.allowAddContact = [o isKindOfClass:[List class]];
            self.allowStartBtn = self.allowStart && [o isKindOfClass:[List class]];
            if ([o isKindOfClass:[List class]]) {
                self.currentList = o;
                self.currentProject = nil;
                self.hideDetailsPlaceholder = YES;
                [contactsCtrl bind:@"contentSet"
                          toObject:o
                       withKeyPath:@"contacts"
                           options:nil];
                [self calculateSelectedContacts];
                [self populateTemplate];
            } else {
                self.currentProject = o;
                self.currentList = nil;
                self.hideDetailsPlaceholder = NO;
            }
        } else {
            self.allowEditProject = NO;
            self.allowEditList = NO;
            self.hideContactList = YES;
            self.allowAddContact = NO;
            self.allowStartBtn = NO;
            self.currentProject = nil;
            self.currentList = nil;
            self.hideDetailsPlaceholder = NO;
        }
    } else if ([object isEqual:contactsCtrl]) {
        [self calculateSelectedContacts];
    }

}

- (void)selectListMenu:(NSNotification *)n {
    [menuTable expandItem:nil expandChildren:YES];
//    [menuTable selectRowIndexes:[NSIndexSet indexSetWithIndex:2] byExtendingSelection:NO];
    NSManagedObject *list = [[[self app] managedObjectContext] objectWithID:n.object];
    int i1 = 0;
    int ir = 0;
    [projectsCtrl fetchWithRequest:nil merge:NO error:nil];
    [projectsCtrl rearrangeObjects];
    for (int i = 0; i < [projectsCtrl.arrangedObjects count]; i++) {
        Project *p = [projectsCtrl.arrangedObjects objectAtIndex:(NSUInteger) i];
        p.lists.count;
        NSArray *const parr = [p.lists sortedArrayUsingDescriptors:[NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES]]];
        for (int j = 0; j < parr.count; j++) {
            List *l = [parr objectAtIndex:(NSUInteger) j];
            l.name;
            i1++;
            if ([l.objectID isEqual:list.objectID])
            {
                ir = i1;
                break;
            }
        }
        i1++;

    }

//    NSLog(@"ir = %li", ir);

    [menuTable selectRowIndexes:[NSIndexSet indexSetWithIndex:(NSUInteger) ir] byExtendingSelection:NO];


//    NSLog(@"select=%@", [menuCtrl indexPathToObject:list]);
//    const BOOL r = [menuCtrl setSelectionIndexPaths:[NSArray arrayWithObject:[NSIndexSet indexSetWithIndex:2]]];
//    NSLog(@"r=%i",r);


//    [menuCtrl setSelectedObjects:[NSArray arrayWithObject:list]];
//    [self performSelector:@selector(expandMenuItems) withObject:nil afterDelay:0.0];

}

#pragma mark Actions


- (void)sheetDidEnd:(id)sheetDidEnd returnCode:(id)returnCode contextInfo:(id)contextInfo {


}

- (void)showProjectForm:(NSManagedObjectID *)id {
    if (_projectWindowCtrl == nil) {
        _projectWindowCtrl = [[ProjectWindowController alloc] init];
    }
    [self hideStartupTip];
    [NSApp beginSheet:[_projectWindowCtrl windowWithId:id]
       modalForWindow:[self window]
        modalDelegate:self
       didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
          contextInfo:nil];

}

- (void)showListForm:(NSManagedObjectID *)id {
    if (_listWindowCtrl == nil) {
        _listWindowCtrl = [[ListWindowController alloc] init];
    }
    [self hideStartupTip];
    [NSApp beginSheet:[_listWindowCtrl windowWithId:id]
       modalForWindow:[self window]
        modalDelegate:self
       didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
          contextInfo:nil];

}

- (void)showContactForm:(NSManagedObjectID *)id {
    if (_contactWindowCtrl == nil) {
        _contactWindowCtrl = [[ContactWindowController alloc] init];
    }
    [NSApp beginSheet:[_contactWindowCtrl windowWithId:id andListId:self.currentList.objectID]
       modalForWindow:[self window]
        modalDelegate:self
       didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
          contextInfo:nil];
}
//////////////////////////////////////////////////////////////

- (IBAction)addProjectAction:(id)sender {
//    [StoreHelper proceedProjectCreationFrom:self withAction:@selector(showProjectForm:)];
    [self showProjectForm:nil];
}

- (IBAction)editMenuAction:(id)sender {
    if ([menuCtrl.selectedObjects count] > 0) {
        NSManagedObject *o = [menuCtrl.selectedObjects objectAtIndex:0];
        if ([o isKindOfClass:[List class]])
            [self showListForm:o.objectID];
        else
            [self showProjectForm:o.objectID];
    }

}

- (IBAction)removeMenuAction:(id)sender {
    if ([menuCtrl.selectedObjects count] > 0) {
        NSManagedObject *o = [menuCtrl.selectedObjects objectAtIndex:0];
        NSAlert *alert = [NSAlert alertWithMessageText:[NSString stringWithFormat:@"Are you sure remove the '%@'?", [o valueForKey:@"name"]]
                                         defaultButton:@"OK" alternateButton:@"Cancel" otherButton:nil informativeTextWithFormat:@""];
        int choice = [alert runModal];
        if (choice == NSAlertDefaultReturn) {
            [[self app].managedObjectContext deleteObject:o];
            [[self app] saveAction:nil];
            NSError *error;
            [menuCtrl fetchWithRequest:nil merge:NO error:&error];
            [menuCtrl rearrangeObjects];
        }
    }
}


- (IBAction)addListAction:(id)sender {
    [self showListForm:nil];
}

- (IBAction)addContactAction:(id)sender {
//    [StoreHelper proceedContactCreationFrom:self withAction:@selector(showContactForm:) andList:self.currentList];
    [self showContactForm:nil];

}

- (IBAction)editContactAction:(id)sender {
    if ([contactsCtrl.selectedObjects count] > 0) {
        NSManagedObject *o = [contactsCtrl.selectedObjects objectAtIndex:0];
        [self showContactForm:o.objectID];
    }
}

- (IBAction)removeContactAction:(id)sender {
    if ([contactsCtrl.selectedObjects count] > 0) {

        NSAlert *alert = [NSAlert alertWithMessageText:@"Are you sure remove the selected contact(s)?"
                                         defaultButton:@"OK" alternateButton:@"Cancel" otherButton:nil informativeTextWithFormat:@""];
        int choice = [alert runModal];
        if (choice == NSAlertDefaultReturn) {
            for (NSManagedObject *c in contactsCtrl.selectedObjects) {
                [[self app].managedObjectContext deleteObject:c];
            }
            [[self app] saveAction:nil];
        }
    }
}

- (void)showImportFromCSVForm {
    if (_csvWindowCtrl == nil) {
        _csvWindowCtrl = [[ImportCSVWindowController alloc] init];
    }
    [NSApp beginSheet:[_csvWindowCtrl windowWithId:nil andListId:self.currentList.objectID]
       modalForWindow:[self window]
        modalDelegate:self
       didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
          contextInfo:nil];
}

- (IBAction)importCSVContactAction:(id)sender {
//    [StoreHelper proceedContactCreationFrom:self withAction:@selector(showImportFromCSVForm) andList:self.currentList];
    [self showImportFromCSVForm];
}

- (void)showImportABForm {
    if (_abWindowCtrl == nil) {
        _abWindowCtrl = [[ImportABWindowController alloc] init];
    }
    [NSApp beginSheet:[_abWindowCtrl windowWithId:nil andListId:self.currentList.objectID]
       modalForWindow:[self window]
        modalDelegate:self
       didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
          contextInfo:nil];
}

- (IBAction)importABContactAction:(id)sender {
//    [StoreHelper proceedContactCreationFrom:self withAction:@selector(showImportABForm) andList:self.currentList];
    [self showImportABForm];
}

- (void)showImportFromListForm {
    if (_importFromListWindowCtrl == nil) {
        _importFromListWindowCtrl = [[ImportFromListWindowController alloc] init];
    }
    [NSApp beginSheet:[_importFromListWindowCtrl windowWithId:nil andListId:self.currentList.objectID]
       modalForWindow:[self window]
        modalDelegate:self
       didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
          contextInfo:nil];
}

- (IBAction)importFromListAction:(id)sender {
    [self showImportFromListForm];
//    [StoreHelper proceedContactCreationFrom:self withAction:@selector(showImportFromListForm) andList:self.currentList];
}

- (IBAction)insertTemplateAction:(id)sender {
    int tag = ((NSMenuItem *) sender).tag;
    NSDictionary * td = [self.templateVars valueForKey:[NSString stringWithFormat:@"%i", tag]];
    [templateTxt insertText:[td valueForKey:@"value"]];
}


- (IBAction)switchToTemplateAction:(id)sender {
    [self detailContentSwitch];
}

- (IBAction)switchToContactsAction:(id)sender {
    [self detailContentSwitch];

}


- (IBAction)searchContactsAction:(id)sender {
    NSSearchField *searchField = sender;
    NSMutableString *searchText = [NSMutableString stringWithString:[searchField stringValue]];
    // Remove extraenous whitespace
    while ([searchText rangeOfString:@"Â  "].location != NSNotFound) {
        [searchText replaceOccurrencesOfString:@"Â  " withString:@" " options:0 range:NSMakeRange(0, [searchText length])];
    }
    //Remove leading space
    if ([searchText length] != 0) [searchText replaceOccurrencesOfString:@" " withString:@"" options:0 range:NSMakeRange(0, 1)];
    //Remove trailing space
    if ([searchText length] != 0) [searchText replaceOccurrencesOfString:@" " withString:@"" options:0 range:NSMakeRange([searchText length] - 1, 1)];
    if ([searchText length] == 0) {
        [contactsCtrl setFilterPredicate:nil];
        return;
    }

    NSArray *searchTerms = [searchText componentsSeparatedByString:@" "];
    NSMutableArray *subPredicates = [[NSMutableArray alloc] init];
    NSPredicate *searchPredicate;
    if ([searchTerms count] == 1) {
        searchPredicate = [self searchPredicate:searchText];
        [subPredicates addObject:searchPredicate];
    } else {

        for (NSString *term in searchTerms) {
            NSPredicate *p = [self searchPredicate:term];
            [subPredicates addObject:p];
        }

    }

    if (subPredicates.count > 0) {
        NSPredicate *cp = [NSCompoundPredicate andPredicateWithSubpredicates:subPredicates];
        [contactsCtrl setFilterPredicate:cp];
    }
    [subPredicates release];
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
    } else if (tag == 2002) {
        //select last status = nil
        for (Contact *contact in contactsCtrl.arrangedObjects) {
            contact.checked = [NSNumber numberWithBool:NO];
        }
        NSArray *notsent = [contactsCtrl.arrangedObjects filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"lastLog == nil"]];
        for (Contact *contact in notsent) {
            contact.checked = [NSNumber numberWithBool:YES];
        }

    } else if (tag == 2003) {
        //select last status = error
        for (Contact *contact in contactsCtrl.arrangedObjects) {
            contact.checked = [NSNumber numberWithBool:NO];
        }
        NSArray *errsent = [contactsCtrl.arrangedObjects filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"lastLog.isSuccess == NO"]];
        for (Contact *contact in errsent) {
            contact.checked = [NSNumber numberWithBool:YES];
        }
    }
    [self calculateSelectedContacts];
    skipObserving = NO;
}

- (IBAction)duplicateContactsAction:(id)sender {
    NSArray *sc = [contactsCtrl selectedObjects];
    NSUndoManager *undoMgr = [[[self app] managedObjectContext] undoManager];
    [undoMgr beginUndoGrouping];
    for (NSUInteger i = 0; i < sc.count; i++) {
        Contact *c = [[contactsCtrl selectedObjects] objectAtIndex:i];

        NSDictionary *keysDict = [c dictionaryWithValuesForKeys:[Contact copyKeys]];
        NSManagedObject *no = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[[self app] managedObjectContext]];
        [no setValuesForKeysWithDictionary:keysDict];
        [no setValue:c.list forKey:@"list"];
    }

    [[[self app] managedObjectContext] processPendingChanges];
    [undoMgr endUndoGrouping];
    [[self app] saveAction:nil];
}


- (IBAction)startAction:(id)sender {
    Account *acc = self.currentList.project.account;
    if (!acc) {
        NSAlert *alert = [NSAlert alertWithMessageText:@"Please create account for project first."
                                         defaultButton:@"OK" alternateButton:nil otherButton:nil informativeTextWithFormat:@""];
        [alert runModal];
        return;
    }
    NSArray *cs = [self checkedContacts];

    if (cs.count >= 100 && (![acc.provider isEqualToString:@"Custom SMTP"])) {
        NSString *am = [NSString stringWithFormat:@"%@ has limit 100 emails per day", acc.provider];
        NSAlert *alert = [NSAlert alertWithMessageText:am
                                         defaultButton:@"Continue" alternateButton:@"Cancel" otherButton:nil informativeTextWithFormat:@"Do you want to continue?"];
        int choice = [alert runModal];
        if (choice != NSAlertDefaultReturn) {
            return;
        }

    }
//    [emailSender test];
    self.allowStartBtn = NO;
    self.hideStopBlastBtn = NO;
    self.contactsForSendCount = cs.count;
    [sendingInd setHidden:NO];
    [sendingInd startAnimation:self];
    [emailSender performSelectorInBackground:@selector(sendEmails:) withObject:[NSArray arrayWithObjects:cs, self.currentList, nil]];
}


- (IBAction)stopAction:(id)sender {
    [emailSender stop];
    self.statusTxt = @"Stopping...";
//    [self blastFinished];
}




#pragma mark emailer callbacks

- (void)emailError:(id)d {
//auth error
    NSAlert *alert = [NSAlert alertWithMessageText:@"Connection Error"
                                     defaultButton:@"OK" alternateButton:nil otherButton:nil informativeTextWithFormat:@"Please check your account details or internet connection."];
    [alert runModal];
    [self blastFinished];
}

- (void)emailProgress:(id)d {
    self.sentIndCount = self.sentIndCount + 1;
}

- (void)emailStatus:(id)d {
    self.statusTxt = d;
}

- (void)emailFinished:(id)d {
//    [sendBtn setEnabled:YES];
    [self blastFinished];
    NSAlert *alert = [NSAlert alertWithMessageText:@"Emails sent successfully!"
                                     defaultButton:@"OK" alternateButton:nil otherButton:nil informativeTextWithFormat:@""];
    [alert runModal];
}

- (void)emailLogs:(NSDictionary *)listLogData {
    List *list = (List *) [self.app.managedObjectContext objectWithID:[listLogData valueForKey:@"listId"]];
    if (list) {
        NSArray *logs = [listLogData valueForKey:@"logs"];
        if (logs && logs.count > 0) {
            ListSendLog *listLog = [NSEntityDescription insertNewObjectForEntityForName:@"ListSendLog" inManagedObjectContext:[self.app managedObjectContext]];
            listLog.list = list;
            for (NSDictionary *logData in logs) {
                Contact *c = (Contact *) [self.app.managedObjectContext objectWithID:[logData valueForKey:@"contactId"]];
                if (c) {
                    SendLog *log = [NSEntityDescription insertNewObjectForEntityForName:@"SendLog" inManagedObjectContext:[self.app managedObjectContext]];
                    log.contact = c;
                    log.listSendLog = listLog;
                    log.date = [logData valueForKey:@"date"];
                    log.error = [logData valueForKey:@"error"];
                    log.isError = [logData valueForKey:@"isError"];
                    [listLog addLogsObject:log];
                }
            }
        }
    }
    [self.app saveAction:nil];
//    NSError *e = nil;
//    [menuCtrl fetchWithRequest:nil merge:NO error:&e];
    
}


- (void)blastFinished {
    self.allowStartBtn = YES;
    [sendingInd stopAnimation:self];
    [sendingInd setHidden:YES];
    self.hideStopBlastBtn = YES;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"selectListMenu" object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"switchToContacts" object:nil];
    [menuCtrl removeObserver:self forKeyPath:@"selectedObjects"];
    [contactsCtrl removeObserver:self forKeyPath:@"arrangedObjects.checked"];
    [_projectWindowCtrl release];
    [_listWindowCtrl release];
    [_contactWindowCtrl release];
    [_csvWindowCtrl release];
    [_abWindowCtrl release];
    [_prefsWindowCtrl release];
    [_currentList release];
    [_currentProject release];
    [_currentView release];
    [_contactsCountStr release];
    [_importFromListWindowCtrl release];
    [emailSender release];
    [attachedWindow release];
    [_statusTxt release];
    [_templateVars release];
    [super dealloc];
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isGroupItem:(id)item {

    return [[item representedObject] isKindOfClass:[Project class]];
}

#pragma mark Private
- (AppDelegate *)app {
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    return app;
}

- (NSArray *)checkedContacts {
    NSArray *checked = [contactsCtrl.arrangedObjects filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"checked == YES"]];
    return checked;
}

- (void)calculateSelectedContacts {
    NSArray *checked = [self checkedContacts];
    self.contactsCountStr = [NSString stringWithFormat:@"%i/%i", checked.count, [contactsCtrl.arrangedObjects count]];
}

- (NSPredicate *)searchPredicate:(NSString *)str {

    return [NSPredicate predicateWithFormat:@"(name contains[cd] %@) OR (email contains[cd] %@) OR (phone contains[cd] %@) OR (mobile contains[cd] %@) OR (city contains[cd] %@) OR (state contains[cd] %@) OR (zip contains[cd] %@)  OR (companyName contains[cd] %@)", str, str, str, str, str, str, str, str];
}


#pragma mark Webview delegate
+ (BOOL)isSelectorExcludedFromWebScript:(SEL)aSelector {
    return NO;
}

+ (BOOL)isKeyExcludedFromWebScript:(const char *)name {
    return NO;
}

- (void)webView:(WebView *)sender didFailProvisionalLoadWithError:(NSError *)error forFrame:(WebFrame *)frame {
    NSLog(@"Error: %@", [error localizedDescription]);
}

- (void)webView:(WebView *)sender didFailLoadWithError:(NSError *)error forFrame:(WebFrame *)frame {
    NSLog(@"Error: %@", [error localizedDescription]);
}

- (void)populateTemplate {

    if (self.currentList) {
        id template = self.currentList.template == nil ? [NSNull null] : self.currentList.template;
        id r = [webViewScript callWebScriptMethod:@"populate" withArguments:[NSArray arrayWithObjects:template, nil]];
    }

}

- (void)webView:(WebView *)sender didFinishLoadForFrame:(WebFrame *)frame {
//    NSLog(@"didFinishLoadForFrame ");
    if (sender == templateWebView) {
        webViewScript = sender.windowScriptObject;
        [webViewScript setValue:self forKey:@"delegate"];
        [self populateTemplate];
    }
    [[[templateWebView mainFrame] frameView] setAllowsScrolling:YES];
}

- (void)templateValueReturnedFromJS:(id)result {
//    NSLog(@"template return: %@", result);
    if (self.currentList && [result isKindOfClass:[NSString class]]) {
        self.currentList.template = result;
    }
}

- (void)showStartupTip {
//    NSLog(@"attachedWindow=%@",addProjectBtn.view);
//    if (!attachedWindow) {

    NSPoint buttonPoint = NSMakePoint(NSMidX([addProjectBtn.view frame]),
            NSMidY([addProjectBtn.view frame]) + 560);
    attachedWindow = [[MAAttachedWindow alloc] initWithView:newProjectTipView
                                            attachedToPoint:buttonPoint
                                                   inWindow:self.window
                                                     onSide:MAPositionBottom
                                                 atDistance:5.0];//
    [newProjectTipViewLbl setTextColor:[attachedWindow borderColor]];
    [[self window] addChildWindow:attachedWindow ordered:NSWindowAbove];
    [attachedWindow makeKeyAndOrderFront:self];
//        } else {
//            [[addProjectBtn window] removeChildWindow:attachedWindow];
//            [attachedWindow orderOut:self];
//            [attachedWindow release];
//            attachedWindow = nil;
//        }


}

- (void)hideStartupTip {
    if (attachedWindow) {
        [[self window] removeChildWindow:attachedWindow];
        [attachedWindow orderOut:self];
        [attachedWindow release];
        attachedWindow = nil;
    }
}

- (void)windowWillClose:(NSNotification *)notification {
    NSLog(@"main window closed");
    [NSApp terminate:self];
}
@end