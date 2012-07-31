//
//  Feedback.h
//  DebtManager
//
//  Created by Alexander Tretyakov on 5/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Feedback : NSObject {
@private
    
}
+ (void)send:(NSString *)name email:(NSString *)email type:(NSString *)type message:(NSString *)message;
@end
