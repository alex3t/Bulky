//
//  ListSendLog.h
//  Bulky
//
//  Created by iMac on 2/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class List;

@interface ListSendLog : NSManagedObject

@property (nonatomic, retain) List *list;
@property (nonatomic, retain) NSSet *logs;
@end

@interface ListSendLog (CoreDataGeneratedAccessors)

- (void)addLogsObject:(NSManagedObject *)value;
- (void)removeLogsObject:(NSManagedObject *)value;
- (void)addLogs:(NSSet *)values;
- (void)removeLogs:(NSSet *)values;
@end
