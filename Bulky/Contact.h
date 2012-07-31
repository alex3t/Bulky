//
//  Contact.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class List;
@class SendLog;

@interface Contact : NSManagedObject
{
@private
    SendLog *_lastLog;
    
}
@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSString * firstName;
@property (nonatomic, retain) NSString * lastName;
@property (nonatomic, retain) NSString * middleName;
@property (nonatomic, retain) NSString * nickname;
@property (nonatomic, retain) NSString * companyName;
@property (nonatomic, retain) NSString * email;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * mobile;
@property (nonatomic, retain) NSString * phone;
@property (nonatomic, retain) NSString * street;
@property (nonatomic, retain) NSString * city;
@property (nonatomic, retain) NSString * state;
@property (nonatomic, retain) NSString * country;
@property (nonatomic, retain) NSString * zip;
@property (nonatomic, retain) NSString *custom1;
@property (nonatomic, retain) NSString * custom2;
@property (nonatomic, retain) NSString * custom3;
@property (nonatomic, retain) NSSet * logs;
@property (nonatomic, retain) List *list;

@property(nonatomic, retain) NSNumber *checked;
@property(nonatomic, retain) SendLog *lastLog;


+ (NSArray *)copyKeys;
@end
