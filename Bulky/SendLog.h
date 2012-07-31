//
//  SendLog.h
//  Bulky
//
//  Created by iMac on 2/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Contact, ListSendLog;

@interface SendLog : NSManagedObject

@property (nonatomic, retain) NSDate * date;
@property (nonatomic, retain) NSString * error;
@property (nonatomic, retain) NSNumber *isError;
@property (nonatomic, retain) Contact *contact;
@property (nonatomic, retain) ListSendLog *listSendLog;
@property (nonatomic, readonly) NSString *message;

@end
