//
//  Created by imac on 10/25/11.
//


#import "NSString+Support.h"


@implementation NSString (Support)
- (BOOL)empty {
    if (self == nil)
        return NO;
    return ([[self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0);
}
// "psuedo-numeric" comparison
//   -- if both strings begin with digits, numeric comparison on the digits
//   -- if numbers equal (or non-numeric), caseInsensitiveCompare on the remainder

- (NSComparisonResult)psuedoNumericCompare:(NSString *)otherString {

    NSString *left = self;
    NSString *right = otherString;
    NSInteger leftNumber, rightNumber;


    NSScanner *leftScanner = [NSScanner scannerWithString:left];
    NSScanner *rightScanner = [NSScanner scannerWithString:right];

    // if both begin with numbers, numeric comparison takes precedence
    if ([leftScanner scanInteger:&leftNumber] && [rightScanner scanInteger:&rightNumber]) {
        if (leftNumber < rightNumber)
            return NSOrderedAscending;
        if (leftNumber > rightNumber)
            return NSOrderedDescending;

        // if numeric values tied, compare the rest
        left = [left substringFromIndex:[leftScanner scanLocation]];
        right = [right substringFromIndex:[rightScanner scanLocation]];
    }

    return [left caseInsensitiveCompare:right];
}
@end