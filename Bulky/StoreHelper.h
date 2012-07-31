#import <StoreKit/StoreKit.h>

@class Project;
@class List;

#define kInAppPurchaseManagerProductsFetchedNotification @"kInAppPurchaseManagerProductsFetchedNotification"
#define kInAppPurchaseManagerTransactionFailedNotification @"kInAppPurchaseManagerTransactionFailedNotification"
#define kInAppPurchaseManagerTransactionSucceededNotification @"kInAppPurchaseManagerTransactionSucceededNotification"


@interface StoreHelper : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver> {
    id _finishedDelegate;
    SEL _finishedAction;
    NSArray *_products;
    SKProductsRequest *productsRequest;
}
@property(nonatomic, retain) NSArray *products;
@property(nonatomic, retain) id finishedDelegate;
@property(nonatomic, assign) SEL finishedAction;


- (void)validateApp;
- (BOOL)validatePurchase;
- (void)loadStore;
- (BOOL)canMakePurchases;
- (void)purchase:(NSArray *)selectedProducts;

//+ (BOOL)isProVersion;
//+ (void)proceedProjectCreationFrom:(id)target withAction:(SEL)action;
//+ (void)proceedListCreationFrom:(id)target withAction:(SEL)action andProject:(Project *)project;
//+ (void)proceedContactCreationFrom:(id)target withAction:(SEL)action andList:(List *)list;
//
//+ (void)proceedStoreValidationFrom:(id)target withAction:(SEL)action currentCount:(NSInteger)count limit:(NSInteger)limit message:(NSString *)mess;


@end