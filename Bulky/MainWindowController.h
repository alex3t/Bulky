//
//  Created by imac on 1/29/12.
//


#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <QuartzCore/QuartzCore.h>

@class ProjectWindowController;
@class ListWindowController;
@class ContactWindowController;
@class ImportCSVWindowController;
@class ImportABWindowController;
@class PrefsWindowController;
@class List;
@class Project;
@class ImportFromListWindowController;
@class EmailSender;
@class MAAttachedWindow;


@interface MainWindowController : NSWindowController <NSWindowDelegate> {
    IBOutlet NSTreeController *menuCtrl;
    IBOutlet NSArrayController *contactsCtrl;
    IBOutlet NSArrayController *projectsCtrl;
    IBOutlet NSOutlineView *menuTable;
    IBOutlet NSTableView *contactsTable;
    IBOutlet NSView *contentView;
    IBOutlet NSView *titleView;
    IBOutlet NSView *contactsView;
    IBOutlet NSView *templateView;
    IBOutlet WebView *templateWebView;
    IBOutlet NSProgressIndicator *sendingInd;
    IBOutlet NSToolbarItem *addProjectBtn;
    IBOutlet NSView *newProjectTipView;
    IBOutlet NSTextField *newProjectTipViewLbl;
    IBOutlet NSTextView *templateTxt;

@private
    int _sentIndCount;
    int _contactsForSendCount;
    BOOL _hideContactList;
    BOOL _hideDetailsPlaceholder;
    BOOL _allowEditProject;
    BOOL _allowEditList;
    BOOL _allowEditMenu;
    BOOL _allowAddContact;
    BOOL _allowStart;
    BOOL _allowStartBtn;
    BOOL _hideTemplateBtn;
    BOOL _hideContactsBtn;
    BOOL _hideStopBlastBtn;
    NSView *_currentView;
    NSString *_contactsCountStr;
    NSString *_statusTxt;
    NSDictionary *_templateVars;

    List *_currentList;
    Project *_currentProject;

    ProjectWindowController *_projectWindowCtrl;
    ListWindowController *_listWindowCtrl;
    ContactWindowController *_contactWindowCtrl;
    ImportCSVWindowController *_csvWindowCtrl;
    ImportABWindowController *_abWindowCtrl;
    ImportFromListWindowController *_importFromListWindowCtrl;
    PrefsWindowController *_prefsWindowCtrl;

    CATransition *transition;
    WebScriptObject *webViewScript;
    BOOL skipObserving;
    EmailSender *emailSender;

    MAAttachedWindow *attachedWindow;
}

@property(nonatomic) BOOL hideContactList;
@property(nonatomic) BOOL allowEditProject;
@property(nonatomic) BOOL allowEditList;
@property(nonatomic) BOOL allowAddContact;
@property(nonatomic) BOOL allowStart;
@property(nonatomic) BOOL allowStartBtn;
@property(nonatomic) BOOL allowEditMenu;
@property(nonatomic) BOOL hideTemplateBtn;
@property(nonatomic) BOOL hideContactsBtn;
@property(nonatomic) BOOL hideStopBlastBtn;

@property(nonatomic, retain) ProjectWindowController *projectWindowCtrl;
@property(nonatomic, retain) ListWindowController *listWindowCtrl;
@property(nonatomic, retain) ContactWindowController *contactWindowCtrl;
@property(nonatomic, retain) ImportCSVWindowController *csvWindowCtrl;
@property(nonatomic, retain) ImportABWindowController *abWindowCtrl;
@property(nonatomic, retain) PrefsWindowController *prefsWindowCtrl;
@property(nonatomic, retain) List *currentList;
@property(nonatomic, retain) Project *currentProject;
@property(nonatomic) BOOL hideDetailsPlaceholder;
@property(nonatomic, retain) NSView *currentView;
@property(nonatomic, retain) NSString *contactsCountStr;
@property(nonatomic, retain) ImportFromListWindowController *importFromListWindowCtrl;
@property(nonatomic) int sentIndCount;
@property(nonatomic) int contactsForSendCount;
@property(nonatomic, retain) NSString *statusTxt;
@property(nonatomic, retain) NSDictionary *templateVars;


-(IBAction)addProjectAction:(id)sender;
-(IBAction)editMenuAction:(id)sender;
-(IBAction)removeMenuAction:(id)sender;
-(IBAction)addListAction:(id)sender;
-(IBAction)addContactAction:(id)sender;
-(IBAction)editContactAction:(id)sender;
-(IBAction)removeContactAction:(id)sender;
-(IBAction)importCSVContactAction:(id)sender;
-(IBAction)importABContactAction:(id)sender;
-(IBAction)importFromListAction:(id)sender;
-(IBAction)insertTemplateAction:(id)sender;
-(IBAction)startAction:(id)sender;
-(IBAction)stopAction:(id)sender;
-(IBAction)switchToTemplateAction:(id)sender;
-(IBAction)switchToContactsAction:(id)sender;
-(IBAction)searchContactsAction:(id)sender;
-(IBAction)selectContactsAction:(id)sender;
-(IBAction)duplicateContactsAction:(id)sender;

- (void)showStartupTip;
@end