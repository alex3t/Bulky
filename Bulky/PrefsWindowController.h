//
//  PrefsWindowController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#import <StoreKit/StoreKit.h>



@interface PrefsWindowController : NSWindowController {
    IBOutlet NSArrayController *accountsCtrl;
//    IBOutlet NSArrayController *productsCtrl;
    IBOutlet NSTableView *accountsTbl;
    IBOutlet NSButton *saveBtn;
    IBOutlet NSButton *buyBtn;
    IBOutlet NSTabView *tabView;
//    IBOutlet NSTableView *productsTbl;
    IBOutlet NSProgressIndicator *productsInd;
@private
    BOOL _saveEnabled;
    BOOL _isProVersion;
    BOOL _isNotProVersion;
//    BOOL _buyBtnEnabled;

    BOOL _hideSmtpDetails;
    BOOL _hideAccountDetails;
    NSManagedObjectContext *_managedObjectContext;
    NSManagedObjectContext *_parentManagedObjectContext;
    NSDictionary *_emailProviders;
    NSArray *_emailProvidersKeys;
    NSArray *_ports;
//    NSArray *_products;

    BOOL isAccountsTab;
    BOOL isProductsTab;
    SKProduct *_product;
}
@property(nonatomic, readonly) NSManagedObjectContext *managedObjectContext;
@property(nonatomic) BOOL saveEnabled;
@property(nonatomic, retain) NSManagedObjectContext *parentManagedObjectContext;
@property(nonatomic, retain) NSDictionary *emailProviders;
@property(nonatomic) BOOL hideSmtpDetails;
@property(nonatomic, retain) NSArray *emailProvidersKeys;
@property(nonatomic) BOOL hideAccountDetails;
@property(nonatomic, retain) NSArray *ports;
@property(nonatomic, assign) BOOL isProVersion;
@property(nonatomic, assign) BOOL isNotProVersion;
@property(nonatomic, retain) SKProduct *product;


//@property(nonatomic, retain) NSArray *products;


//@property(nonatomic, assign) BOOL buyBtnEnabled;


- (IBAction)cancelFormAction:(id)sender;
- (IBAction)saveAccountsAction:(id)sender;
- (IBAction)buyAction:(id)sender;
- (IBAction)addAccountAction:(id)sender;
- (IBAction)removeAccountAction:(id)sender;

- (PrefsWindowController *)initWithContext:(NSManagedObjectContext *)context;

- (void)showWindow:(NSWindow *)window forTab:(int)i;

- (void)showWindowForProductWithFinisher:(id)o andAction:(SEL)sel;
@end
