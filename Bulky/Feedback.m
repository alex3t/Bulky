//
//  Feedback.m
//  DebtManager
//
//  Created by Alexander Tretyakov on 5/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Feedback.h"
#import "JSONKit.h"
//#import <EDMessage/EDMessage.h>

@implementation Feedback

+ (void)send:(NSString *)name email:(NSString *)email type:(NSString *)type message:(NSString *)message {
    NSURL *url = [NSURL URLWithString:@"http://bulkyapp.com/support_api"];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    NSString *v = @"Apple Store";

    [request setHTTPMethod:@"POST"];
    [request setValue:@"application/json; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
    NSMutableDictionary *rja = [[NSMutableDictionary alloc] init];
    [rja setValue:email forKey:@"email"];
    [rja setValue:name forKey:@"name"];
    [rja setValue:type forKey:@"type"];
    [rja setValue:message forKey:@"message"];
    [rja setValue:v forKey:@"ver"];
    [request setHTTPBody:[[rja JSONString] dataUsingEncoding:NSUTF8StringEncoding]];
    [rja release];

    NSURLResponse *response;
    NSError *err;
    [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:&err];
}

- (void)dealloc {
    [super dealloc];
}

@end
