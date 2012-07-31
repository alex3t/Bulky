//
//  PrefsWindowController.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "PrefsWindowController.h"
#import "AppDelegate.h"
#import "CoreDataHelper.h"
#import "MainWindowController.h"
#import "Account.h"
#import "StoreHelper.h"


@interface PrefsWindowController ()
//- (void)productsBuyValidate;

//- (NSArray *)selectedProducts;

- (void)setupStoreViews;

- (void)setupTabItemViews:(NSTabViewItem *)tabViewItem;

- (void)validate;

- (void)save;

@end

@implementation PrefsWindowController

@synthesize saveEnabled = _saveEnabled;
@synthesize parentManagedObjectContext = _parentManagedObjectContext;
@synthesize emailProviders = _emailProviders;
@synthesize hideSmtpDetails = _hideSmtpDetails;
@synthesize emailProvidersKeys = _emailProvidersKeys;
@synthesize hideAccountDetails = _hideAccountDetails;
@synthesize ports = _ports;
@synthesize isProVersion = _isProVersion;
@synthesize isNotProVersion = _isNotProVersion;
@synthesize product = _product;


//@synthesize products = _products;
//@synthesize buyBtnEnabled = _buyBtnEnabled;
//@synthesize saveBtnHidden = _saveBtnHidden;


//- (NSMutableArray *)populateProducts {
//    NSArray *purchasedIds = [[NSUserDefaults standardUserDefaults] objectForKey:@"purchasedIds"];
//    NSMutableArray *pt = [[NSMutableArray alloc] init];
//    for (SKProduct *skProduct in storeHelper.products) {
//        NSMutableDictionary *d = [NSMutableDictionary dictionary];
//        [d setValue:skProduct forKey:@"product"];
//        BOOL isSelected = [purchasedIds containsObject:skProduct.productIdentifier];
//        BOOL isPurchased = [purchasedIds containsObject:skProduct.productIdentifier];
//        [d setValue:[NSNumber numberWithBool:isSelected] forKey:@"isSelected"];
//        [d setValue:[NSNumber numberWithBool:!isPurchased] forKey:@"isNotPurchased"];
//        [pt addObject:d];
//    }
//    self.products = pt;
//    [pt release];
//    return pt;
//}

- (void)setupStoreViews {

    self.isProVersion = AppDelegate.instance.isProVersion;
    self.isNotProVersion = !AppDelegate.instance.isProVersion;

}

- (void)productsPopulated {
//    [self populateProducts];
    self.product = AppDelegate.instance.storeHelper.products.count > 0 ? [AppDelegate.instance.storeHelper.products objectAtIndex:0] : nil;
//    [productsTbl setHidden:NO];
    [productsInd stopAnimation:nil];
    if (self.product)
        [buyBtn setHidden:NO];
//    [self productsBuyValidate];

}
//
//- (void)purchaseSuccess:(NSNotification *)nobj {
//    SKProduct *p = nobj.object;
//    NSLog(@"purchaseSuccess = %@", p.localizedTitle);
//    [self setupStoreViews];
////    [self populateProducts];
////    [productsInd stopAnimation:nil];
//}

- (void)purchaseError:(NSNotification *)nobj {
    SKProduct *p = nobj.object;
    NSLog(@"purchaseError = %@", p.localizedTitle);
    NSAlert *alertPanel = [NSAlert alertWithMessageText:[NSString stringWithFormat:@"An error occurred while purchasing %@", p.localizedTitle] defaultButton:nil alternateButton:nil otherButton:nil informativeTextWithFormat:@"Some error happen. Please try again or contact Apple Support."];
    [alertPanel runModal];
//    [productsInd stopAnimation:nil];
}

- (PrefsWindowController *)initWithContext:(NSManagedObjectContext *)context {
    self = [super initWithWindowNibName:@"PrefsWindow"];
    self.parentManagedObjectContext = context;
    if ([self.parentManagedObjectContext hasChanges]) {
        NSError *error = nil;
        [self.parentManagedObjectContext save:&error];
    }
    NSString *plistPath = [[NSBundle mainBundle] pathForResource:@"emailProviders" ofType:@"plist"];
    self.emailProviders = [NSDictionary dictionaryWithContentsOfFile:plistPath];

    self.ports = [NSArray arrayWithObjects:@"25", @"465", @"587", nil];



    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(productsPopulated)
                                                 name:kInAppPurchaseManagerProductsFetchedNotification object:nil];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(purchaseError:)
                                                 name:kInAppPurchaseManagerTransactionFailedNotification object:nil];


    return self;
}


- (void)setupEmailProviderKeys {

    if ([AppDelegate instance].isProVersion)
    {
        self.emailProvidersKeys = self.emailProviders.allKeys;
    }else{
        NSMutableArray *const mkeys = [NSMutableArray arrayWithArray:self.emailProviders.allKeys];
        [mkeys removeObject:@"Custom SMTP"];
        self.emailProvidersKeys = mkeys;
    }


}

- (void)awakeFromNib {
    [accountsCtrl setSortDescriptors:[NSArray arrayWithObjects:[NSSortDescriptor sortDescriptorWithKey:@"isDefault" ascending:NO], [NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES], nil]];

    [accountsCtrl addObserver:self forKeyPath:@"selection.provider" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selection.fromName" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selection.fromEmail" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selection.login" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selection.password" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selection.host" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selection.port" options:0 context:nil];
    [accountsCtrl addObserver:self forKeyPath:@"selectionIndexes" options:0 context:nil];

    [AppDelegate.instance addObserver:self forKeyPath:@"isProVersion" options:0 context:nil];

//    [productsCtrl addObserver:self forKeyPath:@"arrangedObjects.isSelected" options:0 context:nil];

//    [tabView addObserver:self forKeyPath:@"selectedIdentifier" options:0 context:nil];
    self.hideAccountDetails = [[accountsCtrl selectedObjects] count] <= 0;
    [self setupTabItemViews:tabView.selectedTabViewItem];
    [self setupStoreViews];
    [self setupEmailProviderKeys];
}

- (void)populateProviderFields {
    if ([accountsCtrl.selectedObjects count] > 0) {
        Account *o = [accountsCtrl.selectedObjects objectAtIndex:0];
//        NSLog(@"populateProviderFields=%@",o);
        if ([o.provider isEqualToString:@"Custom SMTP"]) {
            self.hideSmtpDetails = NO;
        } else {
            self.hideSmtpDetails = YES;
            NSDictionary *pd = [self.emailProviders valueForKey:o.provider];
            o.host = [pd valueForKey:@"server"];
            o.port = [pd valueForKey:@"port"];
            o.ssl = [NSNumber numberWithBool:YES];
        }
//        NSLog(@"self.hideSmtpDetails=%i",self.hideSmtpDetails);

    }


}

//- (void)productsBuyValidate {
//    NSArray *selected = [self selectedProducts];
//    self.buyBtnEnabled = selected.count > 0;
//}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    if (accountsCtrl == object) {
        [self validate];
        if ([keyPath isEqualToString:@"selection.provider"]) {
            [self populateProviderFields];
        }
        if ([keyPath isEqualToString:@"selectionIndexes"]) {
            self.hideAccountDetails = [[accountsCtrl selectedObjects] count] <= 0;
        }
    }else{
        if ([keyPath isEqualToString:@"isProVersion"])
        {
            [self setupEmailProviderKeys];
            [self setupStoreViews];
        }
    }
//    else if (object == tabView)
//    {
//
////    else if (object == productsCtrl)
////    {
////        [self productsBuyValidate];
////    }

}

- (void)setupTabItemViews:(NSTabViewItem *)tabViewItem {
    if ([tabViewItem.identifier isEqual:@"1"]) {
        isAccountsTab = YES;
        isProductsTab = NO;
        [saveBtn setHidden:NO];
//            [buyBtn setHidden:YES];
    } else if ([tabViewItem.identifier isEqual:@"2"]) {
        isAccountsTab = NO;
        isProductsTab = YES;
        [saveBtn setHidden:YES];
//            [buyBtn setHidden:NO];
    }
}

- (void)tabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)tabViewItem {

//    NSLog(@"tabViewItem.identifier = %@", tabViewItem.identifier);

    [self setupTabItemViews:tabViewItem];

}

- (NSManagedObjectContext *)managedObjectContext {
    if (_managedObjectContext == nil) {
        _managedObjectContext = [[NSManagedObjectContext alloc] init];
        [_managedObjectContext setPersistentStoreCoordinator:[[self parentManagedObjectContext] persistentStoreCoordinator]];
    }
    return _managedObjectContext;
}


- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:kInAppPurchaseManagerProductsFetchedNotification object:nil];

    [[NSNotificationCenter defaultCenter] removeObserver:self name:kInAppPurchaseManagerTransactionFailedNotification object:nil];

//    [productsCtrl removeObserver:self forKeyPath:@"arrangedObjects.isSelected"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.provider"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.fromName"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.fromEmail"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.login"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.password"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.host"];
    [accountsCtrl removeObserver:self forKeyPath:@"selection.port"];
    [accountsCtrl removeObserver:self forKeyPath:@"selectionIndexes"];

    [_managedObjectContext release];
    [_parentManagedObjectContext release];
    [_emailProviders release];
    [_emailProvidersKeys release];
    [_ports release];
//    [_products release];

    [_product release];
    [super dealloc];
}

#pragma mark Actions

- (IBAction)cancelFormAction:(id)sender {
    [self.managedObjectContext rollback];
    [[self window] endEditingFor:nil];
    [[self window] close];

}

- (IBAction)saveAccountsAction:(id)sender {
    [self save];
    [[self window] endEditingFor:nil];
    [[self window] close];

}

//- (NSArray *)selectedProducts {
//    NSArray *selected = [productsCtrl.arrangedObjects filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"isSelected == YES"]];
//    return selected;
//}

- (IBAction)buyAction:(id)sender {
//    [productsInd startAnimation:nil];
//    NSArray *selected = [self selectedProducts];
    SKProduct *p = [AppDelegate.instance.storeHelper.products objectAtIndex:0];
    [AppDelegate.instance.storeHelper purchase:[NSArray arrayWithObject:p]];
}

- (IBAction)addAccountAction:(id)sender {
    NSManagedObject *no = [[accountsCtrl newObject] autorelease];
    [no setValue:@"GMail" forKey:@"provider"];
    [accountsCtrl addObject:no];
    [accountsCtrl rearrangeObjects];
    NSUInteger row = [[accountsCtrl arrangedObjects] indexOfObjectIdenticalTo:no];
    [accountsTbl editColumn:0 row:row withEvent:nil select:YES];

}

- (IBAction)removeAccountAction:(id)sender {
    NSAlert *alert = [NSAlert alertWithMessageText:@"Are you sure you want to remove the Account?"
                                     defaultButton:@"OK" alternateButton:@"Cancel" otherButton:nil informativeTextWithFormat:@""];
    int choice = [alert runModal];
    if (choice == NSAlertDefaultReturn) {
        [accountsCtrl removeObjects:[accountsCtrl selectedObjects]];
    }

}

#pragma mark Methods


- (void)validate {
    if (!isAccountsTab) return;
    if ([accountsCtrl.selectedObjects count] > 0) {
        NSError *err = nil;
        Account *o = [accountsCtrl.selectedObjects objectAtIndex:0];
        [o validateForInsert:&err];
        self.saveEnabled = err == nil;
    }
}

- (void)save {
    CoreDataHelper *cdh = [[CoreDataHelper alloc] init];
    [cdh saveFrom:self.managedObjectContext to:self.parentManagedObjectContext];
    [cdh release];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"accountsUpdated" object:nil];
}


- (void)showWindow:(NSWindow *)window forTab:(int)i {
    [super showWindow:window];
    if (!AppDelegate.instance.isProVersion && (!AppDelegate.instance.storeHelper.products || AppDelegate.instance.storeHelper.products.count == 0)) {
        [productsInd startAnimation:nil];
        [self setupStoreViews];
        [buyBtn setHidden:YES];
        [AppDelegate.instance.storeHelper loadStore];
    }

    [tabView selectTabViewItemAtIndex:i];
}

- (void)showWindowForProductWithFinisher:(id)o andAction:(SEL)sel {


    MainWindowController *wc = o;
    [self showWindow:wc.window forTab:1];

}


@end
