//
//  Created by imac on 2/27/12.
//


#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface SKProduct (LocalizedPrice)
@property (nonatomic, readonly) NSString *localizedPrice;

@end