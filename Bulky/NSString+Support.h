//
//  Created by imac on 10/25/11.
//


#import <Foundation/Foundation.h>

@interface NSString (Support)
- (NSComparisonResult) psuedoNumericCompare:(NSString *)otherString;
- (BOOL) empty;
@end