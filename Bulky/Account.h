//
//  Account.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Account : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * fromName;
@property (nonatomic, retain) NSString * fromEmail;
@property (nonatomic, retain) NSString * login;
@property (nonatomic, retain) NSString * password;
@property (nonatomic, retain) NSString * provider;
@property (nonatomic, retain) NSString * host;
@property (nonatomic, retain) NSNumber * port;
@property (nonatomic, retain) NSNumber * ssl;
@property (nonatomic, retain) NSNumber * isDefault;

@end

