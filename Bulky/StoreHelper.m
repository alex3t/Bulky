//
//  Created by imac on 2/27/12.
//


#import "StoreHelper.h"
#import "CkoCertStore.h"
#import "AppDelegate.h"
#import "Project.h"
#import "List.h"
#import "validatereceipt.h"

@interface StoreHelper ()
- (void)requestProUpgradeProductData;

@end

@implementation StoreHelper {

}
@synthesize products = _products;
@synthesize finishedDelegate = _finishedDelegate;
@synthesize finishedAction = _finishedAction;


#define kInAppPurchaseProProductId @"proversion"
#define kInAppPurchaseUnlimitedProjectsProductId @"bulkyunlimitedprojects1"
#define kInAppPurchaseUnlimitedListsProductId @""
#define kInAppPurchaseUnlimitedContactsProductId @""

#pragma -
#pragma Public methods


//+ (BOOL)isProVersion {
//    NSString *ver = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"];
//
//    if ([ver isEqualToString:@"1.0"]) return YES;
//    return [[NSUserDefaults standardUserDefaults] boolForKey:@"isProUpgradePurchased"];
//}
//
//+ (void)proceedProjectCreationFrom:(id)target withAction:(SEL)action {
//    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
//    const NSInteger count = [app countRecords:@"Project" by:nil andValue:nil];
//    [StoreHelper proceedStoreValidationFrom:target withAction:action currentCount:count limit:3 message:@"Your current Bulky version limited to 3 Projects"];
//
//}
//
//+ (void)proceedListCreationFrom:(id)target withAction:(SEL)action andProject:(Project *)project {
//    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
//    const NSInteger count = [app countRecords:@"List" by:@"project" andValue:project];
//    [StoreHelper proceedStoreValidationFrom:target withAction:action currentCount:count limit:1 message:@"Your current Bulky version limited to 1 Contact List per Project"];
//
//}
//
//+ (void)proceedContactCreationFrom:(id)target withAction:(SEL)action andList:(List *)list {
//    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
//    const NSInteger count = [app countRecords:@"Contact" by:@"list" andValue:list];
//    [StoreHelper proceedStoreValidationFrom:target withAction:action currentCount:count limit:50 message:@"Your current Bulky version limited to 50 Contacts per List"];
//
//}
//
//+ (void)proceedStoreValidationFrom:(id)target withAction:(SEL)action currentCount:(NSInteger)count limit:(NSInteger)limit message:(NSString *)mess
//{
//    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
//    if ([StoreHelper isProVersion]) {
//        [target performSelector:action withObject:nil];
//    } else {
//
//        if (count + 1 > limit) {
//            NSAlert *alert = [NSAlert alertWithMessageText:mess
//                                             defaultButton:@"Upgrade" alternateButton:@"Cancel" otherButton:nil informativeTextWithFormat:@""];
//            int choice = [alert runModal];
//            if (choice == NSAlertDefaultReturn) {
//                [app openProductsAction:target action:action];
//            }
//        }else{
//            [target performSelector:action withObject:nil];
//        }
//    }
//}

- (void)validate:(NSString *)receiptPath {


}

- (void)validateApp {
    NSString *const appRecPath = [[[NSBundle mainBundle] appStoreReceiptURL] path];
    if ([[NSFileManager defaultManager] fileExistsAtPath:appRecPath] == NO || !validateReceiptAtPath(appRecPath)) {
        NSLog(@"Not Valid App.");
        exit(173);
    }
    NSLog(@"Correctly validated App!");
}

- (BOOL)validatePurchase {
    [self validateApp];
    NSString *const appRecPath = [[[NSBundle mainBundle] appStoreReceiptURL] path];
    NSArray *const purchasesArr = obtainInAppPurchases(appRecPath);
    if (purchasesArr)
    {
//        NSLog(@"purchases arr=%@",purchasesArr);
//        NSLog(@"purchases o=%@", [purchasesArr objectAtIndex:0]);
//        kReceiptInAppProductIdentifier
        NSDictionary * const d = [purchasesArr objectAtIndex:0];

        if ([[d valueForKey:kReceiptInAppProductIdentifier] isEqual:kInAppPurchaseProProductId] && [[d valueForKey:kReceiptInAppQuantity] isEqual:[NSNumber numberWithInt:1]])
        {
            return YES;
        }

    }
    return NO;
}



//
// call this method once on startup
//
- (void)loadStore {
    // restarts any purchases if they were interrupted last time the app was open
    [[SKPaymentQueue defaultQueue] addTransactionObserver:self];

    // get the product description (defined in early sections)
    [self requestProUpgradeProductData];
}

//
// call this before making a purchase
//
- (BOOL)canMakePurchases {
    return [SKPaymentQueue canMakePayments];
}

//
// kick off the upgrade transaction
//
- (void)purchase:(NSArray *)selectedProducts {
    for (SKProduct *product in selectedProducts) {
        SKPayment *payment = [SKPayment paymentWithProduct:product];
        [[SKPaymentQueue defaultQueue] addPayment:payment];
    }
}






#pragma -
#pragma Purchase helpers

//
// saves a record of the transaction by storing the receipt to disk
//
- (void)recordTransaction:(SKPaymentTransaction *)transaction {

    // save the transaction receipt to disk
    [[NSUserDefaults standardUserDefaults] setValue:transaction.transactionIdentifier forKey:[NSString stringWithFormat:@"receipt_%@", transaction.payment.productIdentifier]];
    [[NSUserDefaults standardUserDefaults] synchronize];

}

//
// enable pro features
//
- (void)provideContent:(NSString *)productId {

    // enable the pro features
//    [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"isProUpgradePurchased"];
//    [[NSUserDefaults standardUserDefaults] setBool:YES forKey:[NSString stringWithFormat:@"isProUpgradePurchased_%@", productId]];
//    NSArray *orgArr = [[NSUserDefaults standardUserDefaults] objectForKey:@"purchasedIds"];
//    if (!orgArr)
//        orgArr = [NSArray array];
//    NSMutableArray *marr = [NSMutableArray arrayWithArray:orgArr];
//    [marr addObject:productId];
//    [[NSUserDefaults standardUserDefaults] setObject:[NSArray arrayWithArray:marr] forKey:@"purchasedIds"];

//    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (SKProduct *)findProductById:(NSString *)id {
    for (SKProduct *product in self.products) {
        if ([product.productIdentifier isEqualToString:id])
            return product;
    }
    return NULL;
}

//
// removes the transaction from the queue and posts a notification with the transaction result
//

- (void)finishTransaction:(SKPaymentTransaction *)transaction wasSuccessful:(BOOL)wasSuccessful {
    // remove the transaction from the payment queue.
    [[SKPaymentQueue defaultQueue] finishTransaction:transaction];

    NSDictionary *userInfo = [NSDictionary dictionaryWithObjectsAndKeys:transaction, @"transaction", nil];
    SKProduct *p = [self findProductById:transaction.payment.productIdentifier];
    if (wasSuccessful) {
        // send out a notification that we’ve finished the transaction
        [[NSNotificationCenter defaultCenter] postNotificationName:kInAppPurchaseManagerTransactionSucceededNotification object:p userInfo:userInfo];
    } else {
        // send out a notification for the failed transaction
        [[NSNotificationCenter defaultCenter] postNotificationName:kInAppPurchaseManagerTransactionFailedNotification object:p userInfo:userInfo];
    }
}

//
// called when the transaction was successful
//
- (void)completeTransaction:(SKPaymentTransaction *)transaction {
    [self recordTransaction:transaction];
    [self provideContent:transaction.payment.productIdentifier];
    [self finishTransaction:transaction wasSuccessful:YES];
}

//
// called when a transaction has been restored and and successfully completed
//
- (void)restoreTransaction:(SKPaymentTransaction *)transaction {
    [self recordTransaction:transaction.originalTransaction];
    [self provideContent:transaction.originalTransaction.payment.productIdentifier];
    [self finishTransaction:transaction wasSuccessful:YES];
}

//
// called when a transaction has failed
//
- (void)failedTransaction:(SKPaymentTransaction *)transaction {
    if (transaction.error.code != SKErrorPaymentCancelled) {
        // error!
        [self finishTransaction:transaction wasSuccessful:NO];
    }
    else {
        // this is fine, the user just cancelled, so don’t notify
        [[SKPaymentQueue defaultQueue] finishTransaction:transaction];
    }
}

#pragma mark -
#pragma mark SKPaymentTransactionObserver methods

//
// called when the transaction status is updated
//
- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions {
    for (SKPaymentTransaction *transaction in transactions) {
        switch (transaction.transactionState) {
            case SKPaymentTransactionStatePurchased:
                [self completeTransaction:transaction];
                break;
            case SKPaymentTransactionStateFailed:
                [self failedTransaction:transaction];
                break;
            case SKPaymentTransactionStateRestored:
                [self restoreTransaction:transaction];
                break;
            default:
                break;
        }
    }
}

- (void)requestProUpgradeProductData {
    NSSet *productIdentifiers = [NSSet setWithObjects:kInAppPurchaseProProductId, nil]; //, kInAppPurchaseUnlimitedListsProductId, kInAppPurchaseUnlimitedContactsProductId
    productsRequest = [[SKProductsRequest alloc] initWithProductIdentifiers:productIdentifiers];
    productsRequest.delegate = self;
    [productsRequest start];
}

#pragma mark -
#pragma mark SKProductsRequestDelegate methods

- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response {

    self.products = response.products;
    for (SKProduct *p in  self.products) {
        if (p) {
            NSLog(@"Product title: %@", p.localizedTitle);
            NSLog(@"Product description: %@", p.localizedDescription);
            NSLog(@"Product price: %@", p.price);
            NSLog(@"Product id: %@", p.productIdentifier);
        }

    }


    for (NSString *invalidProductId in response.invalidProductIdentifiers) {
        NSLog(@"Invalid product id: %@", invalidProductId);
    }

    // finally release the reqest we alloc/init’ed in requestProUpgradeProductData
    [productsRequest release];

    [[NSNotificationCenter defaultCenter] postNotificationName:kInAppPurchaseManagerProductsFetchedNotification object:self userInfo:nil];
}

- (void)dealloc {
    [productsRequest release];
    [_products release];
    [_finishedDelegate release];
    [super dealloc];
}


@end