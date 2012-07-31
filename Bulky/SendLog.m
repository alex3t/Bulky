//
//  SendLog.m
//  Bulky
//
//  Created by iMac on 2/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SendLog.h"
#import "Contact.h"
#import "ListSendLog.h"


@implementation SendLog

@dynamic date;
@dynamic error;
@dynamic isError;
@dynamic contact;
@dynamic listSendLog;

- (NSString *)message {
    NSDateFormatter *dateFormater = [[NSDateFormatter alloc] init];
    [dateFormater setTimeStyle:NSDateFormatterShortStyle];
    [dateFormater setDateStyle:NSDateFormatterShortStyle];
    NSString *r;
    if (self.isError.boolValue) {
        r = [NSString stringWithFormat:@"%@ at %@", self.error, [dateFormater stringFromDate:self.date]];
    } else
        r = [NSString stringWithFormat:@"Sent at %@", [dateFormater stringFromDate:self.date]];
    [dateFormater release];
    return r;
}

-(NSColor *)fontColor
{
    return (self.isError.boolValue ? [NSColor redColor] : [NSColor greenColor] );
}

@end
