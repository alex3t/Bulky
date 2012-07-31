//
//  Contact.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Contact.h"
#import "List.h"
#import "SendLog.h"


@implementation Contact {

}
@dynamic checked;
@dynamic name;
@dynamic logs;
@dynamic title;
@dynamic firstName;
@dynamic lastName;
@dynamic middleName;
@dynamic nickname;
@dynamic companyName;
@dynamic email;
@dynamic mobile;
@dynamic phone;
@dynamic street;
@dynamic city;
@dynamic state;
@dynamic country;
@dynamic zip;
@dynamic custom1;
@dynamic custom2;
@dynamic custom3;
@dynamic list;

@synthesize lastLog = _lastLog;


- (void)populateLastLog {
    if (!self.logs) return;
    NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc] initWithKey:@"date" ascending:NO];
    NSArray *sortDescriptors = [[NSArray alloc] initWithObjects:sortDescriptor, nil];
    NSArray *array = [self.logs sortedArrayUsingDescriptors:sortDescriptors];
    if (array.count > 0) {
        self.lastLog =  [array objectAtIndex:0];
    }
    [sortDescriptor release];
    [sortDescriptors release];
}

- (void)awakeFromFetch {
    [self populateLastLog];
    [self addObserver:self forKeyPath:@"logs" options:0 context:nil];
}
- (void)awakeFromInsert {
    
    [self addObserver:self forKeyPath:@"logs" options:0 context:nil];
}
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    [self populateLastLog];
}

- (void)dealloc {
    [self removeObserver:self forKeyPath:@"logs"];
    [_lastLog release];
    [super dealloc];
}


+ (NSArray *)copyKeys {
    static NSArray *copyKeys = nil;
    if (copyKeys == nil) {
        copyKeys = [[NSArray alloc] initWithObjects:
        @"title",
        @"firstName",
        @"lastName",
        @"middleName",
        @"name",
        @"nickname",
        @"companyName",
        @"email",
        @"mobile",
        @"phone",
        @"street",
        @"city",
        @"state",
        @"country",
        @"zip",
        @"custom1",
        @"custom2",
        @"custom3",
        nil];
    }
    return copyKeys;
}

@end
