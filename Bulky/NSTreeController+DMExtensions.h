//
//  Created by imac on 2/5/12.
//


#import <Foundation/Foundation.h>

@interface NSTreeController (DMExtensions)
- (void)setSelectedObjects:(NSArray *)newSelectedObjects;
- (NSIndexPath *)indexPathToObject:(id)object;
@end