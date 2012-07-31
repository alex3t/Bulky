//
//  Project.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Account, List;

@interface Project : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) Account *account;
@property (nonatomic, retain) NSSet *lists;
@end

@interface Project (CoreDataGeneratedAccessors)

- (void)addListsObject:(List *)value;
- (void)removeListsObject:(List *)value;
- (void)addLists:(NSSet *)values;
- (void)removeLists:(NSSet *)values;
@end
