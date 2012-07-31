//
//  List.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "List.h"
#import "Project.h"
#import "Contact.h"


@implementation List

@dynamic subject;
@dynamic logs;
@dynamic template;
@dynamic name;
@dynamic project;
@dynamic contacts;

- (BOOL)isLeaf {
    return YES;
}

- (NSString *)parseTemplate:(NSString *)t forContact:(Contact *)c {
    NSArray *tags = [[NSArray alloc] initWithObjects:@"NAME", @"TITLE", @"COMPANY_NAME", @"EMAIL", @"NICKNAME", @"PHONE"
            , @"MOBILE", @"STREET", @"CITY", @"ZIP", @"COUNTRY", @"STATE", @"CUSTOM1", @"CUSTOM2", @"CUSTOM3", nil];
    NSString *r = t;
    for (NSString *tag in tags) {
        NSString *replacement = [NSString stringWithFormat:@"[%@]",tag];
        NSString *field = tag.lowercaseString;
        if ([tag isEqualToString:@"COMPANY_NAME"])
            field = @"companyName";
        NSString *valueForKey = [c valueForKey:field];
        if (!valueForKey)
            valueForKey = @"";
        r = [r stringByReplacingOccurrencesOfString:replacement withString:valueForKey];
    }
    [tags release];
    return r;
}

- (NSString *)parsedSubjectForContact:(Contact *)c {
    if (!c || !self.subject) return nil;

    return [self parseTemplate:self.subject forContact:c];
}
- (NSString *)parsedTemplateForContact:(Contact *)c {
    if (!c || !self.template) return nil;

    return [self parseTemplate:self.template forContact:c];
}
@end
