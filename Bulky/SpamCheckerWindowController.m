//
//  SpamCheckerWindowController.m
//  Bulky
//
//  Created by iMac on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SpamCheckerWindowController.h"
#import "MainWindowController.h"
#import "List.h"
#import "CkoEmail.h"
#import "CkoMailMan.h"
#import "Contact.h"
#import "Project.h"
#import "Account.h"
#import "AppDelegate.h"
#import "JSONKit.h"

@interface SpamCheckerWindowController ()


@end

@implementation SpamCheckerWindowController

@synthesize parent = _parent;
@synthesize reportStr = _reportStr;
@synthesize scoreStr = _scoreStr;
@synthesize scoreColor = _scoreColor;

@synthesize enableCheckBtn = _enableCheckBtn;

- (AppDelegate *)app {
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    return app;
}

- (NSString *)buildEmailForList:(List *)list {

    CkoMailMan *mailman = [[[CkoMailMan alloc] init] autorelease];
    BOOL success = [mailman UnlockComponent:@"MAILT34MB34N_6ADE5E140UIY"];
    if (success != YES) {
        NSLog(@"UnlockComponentError=%@", mailman.LastErrorText);
        return nil;
    }
    CkoEmail *email = [[[CkoEmail alloc] init] autorelease];
    NSUndoManager *undoManager = [[self.app managedObjectContext] undoManager];
    [undoManager beginUndoGrouping];
    Contact *contact = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self.app managedObjectContext]];;
    [contact setValue:@"Bill Gordon" forKey:@"name"];
    [contact setValue:@"Apple LLC" forKey:@"companyName"];
    [contact setValue:@"(212) 240-1280" forKey:@"phone"];
    [contact setValue:@"(212) 240-1280" forKey:@"mobile"];
    [contact setValue:@"someemail@gmail.com" forKey:@"email"];
    [contact setValue:@"196 E Broadway" forKey:@"street"];
    [contact setValue:@"New York" forKey:@"city"];
    [contact setValue:@"USA" forKey:@"country"];
    email.Subject = [list parsedSubjectForContact:contact];
    NSString *body = [list parsedTemplateForContact:contact];
    [email SetHtmlBody:[NSString stringWithFormat:@"<html><body>%@</body></html>", body]];
    [email AddPlainTextAlternativeBody:[self.app flattenHTML:body]];
    email.FromAddress = list.project.account.fromEmail;
    email.FromName = list.project.account.fromName;
    [email AddTo:contact.name emailAddress:contact.email];
    [undoManager endUndoGrouping];
    [undoManager undo];

    return [email GetMime];
}

- (void)check:(List *)list {
    
    NSString *email = [self buildEmailForList:list];

    NSError *error = nil;
    NSMutableArray *r = [NSMutableArray array];
    @try {
        NSURL *resource = [NSURL URLWithString:@"http://spamcheck.postmarkapp.com/filter"];
//        NSLog(@"resource = %@", resource);

        NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:resource
                                                           cachePolicy:NSURLRequestUseProtocolCachePolicy
                                                       timeoutInterval:60.0];
        [req setHTTPMethod:@"POST"];
        [req setValue:@"application/json; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
        [req setValue:@"application/json" forHTTPHeaderField:@"Accept"];
//        email = @"test";
//        NSString * str = [NSString stringWithFormat:@"{\"email\":'%@',\"options\":\"long\"}", [email stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
//        NSLog(@"email str1=%@",email);
//        NSLog(@"email str2=%@",[email stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]);
        NSMutableDictionary *rja = [[NSMutableDictionary alloc] init];
        [rja setValue:email forKey:@"email"];
        [rja setValue:@"long" forKey:@"options"];
//        NSLog(@"rja=%@", [rja JSONString]);
        [req setHTTPBody:[[rja JSONString] dataUsingEncoding:NSUTF8StringEncoding]];
        [rja release];
        NSURLResponse *response = nil;
        NSData *responseData = [NSURLConnection sendSynchronousRequest:req returningResponse:&response error:&error];
        if (error) {

            [NSException raise:@"Http error" format:@"error:%@", error];
        }

        JSONDecoder *jsonDecoder = [[JSONDecoder alloc] init];
        id obj = [jsonDecoder objectWithData:responseData];
//        NSLog(@"obj = %@", obj);
        if ([obj valueForKey:@"success"]) {
            [r addObject:[obj valueForKey:@"score"]];
            NSString *report = [obj valueForKey:@"report"];
            report = [report stringByReplacingOccurrencesOfString:@"-0.0 NO_RELAYS              Informational: message was not relayed via SMTP\n" withString:@""];
            report = [report stringByReplacingOccurrencesOfString:@"0.0 HTML_MESSAGE           BODY: HTML included in message\n" withString:@""];
            report = [report stringByReplacingOccurrencesOfString:@"0.0 MIME_QP_LONG_LINE      RAW: Quoted-printable line longer than 76 chars\n" withString:@""];
            report = [report stringByReplacingOccurrencesOfString:@"0.0 T_HK_NAME_FM_FROM      T_HK_NAME_FM_FROM\n" withString:@""];

            [r addObject:report];
        }

        [jsonDecoder release];


    }
    @catch (id theException) {
        NSLog(@"%@", theException);
    }
    @finally {
        [self performSelectorOnMainThread:@selector(finish:) withObject:r waitUntilDone:NO];
    }
}

- (void)finish:(NSArray *)r {
    if (r.count > 0) {
        self.scoreStr = [r objectAtIndex:0];
        self.reportStr = [r objectAtIndex:1];
    }
    [checkInd stopAnimation:self];
    self.enableCheckBtn = YES;
}

- (id)init {
    self = [super initWithWindowNibName:@"SpamCheckerWindow"];

    return self;
}

- (void)windowDidLoad {
    [super windowDidLoad];

    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

- (void)dealloc {
    [_parent release];
    [_reportStr release];
    [_scoreStr release];
    [_scoreColor release];
    [super dealloc];
}

- (IBAction)checkAction:(id)sender {
    self.scoreStr = nil;
    self.reportStr = nil;
    [checkInd startAnimation:self];
    self.enableCheckBtn = NO;
    [self performSelectorInBackground:@selector(check:) withObject:self.parent.currentList];
}


- (IBAction)closeAction:(id)sender {
    [[self window] endEditingFor:nil];
    [[self window] close];


}


@end
