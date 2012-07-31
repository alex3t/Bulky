//
//  Project.m
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Project.h"
#import "Account.h"
#import "List.h"


@implementation Project

@dynamic name;
@dynamic account;
@dynamic lists;

-(BOOL)isLeaf
{
    return NO;
}
@end
