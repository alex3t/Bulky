//
//  Created by imac on 10/12/11.
//


//http://www.example-code.com/objc/smtp_gmailSsl.asp
//#import <Pantomime/Pantomime.h>
//#import <EDMessage/EDMessage.h>
#import "EmailSender.h"
#import "CkoMailMan.h"
#import "CkoEmail.h"
#import "Account.h"
#import "Contact.h"
#import "List.h"
#import "Project.h"
#import "CkoMht.h"
#import "AppDelegate.h"


@interface EmailSender ()


@end

@implementation EmailSender

@synthesize numberOfMessages = _numberOfMessages;
@synthesize emails = _emails;
@synthesize numberOfSentMessages = _numberOfSentMessages;
@synthesize stopped = _stopped;

- (AppDelegate *)app {
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    return app;
}

- (id)initWithDelegate:(id)delegateArg progressCallback:(SEL)pcallBack  errorCallback:(SEL)ecallBack finishCallback:(SEL)fc {
    self = [super init];
    if (self) {
        delegate = delegateArg;
        progressCallBack = pcallBack;
//        statusCallBack = scallBack;
        errorCallBack = ecallBack;
        finishCallBack = fc;
    }
    return self;
}




- (void)sendEmails:(NSArray *)params{
    NSArray *contacts = [params objectAtIndex:0];
    List *list = [params objectAtIndex:1];
    self.stopped = NO;
    NSMutableString *strOutput = [NSMutableString stringWithCapacity:1000];
    CkoMailMan *mailman = [[[CkoMailMan alloc] init] autorelease];
    BOOL success = [mailman UnlockComponent:@"30-day trial"];//@"30-day trial"
    if (success != YES) {
        [strOutput appendString:mailman.LastErrorText];
        [strOutput appendString:@"\n"];
        NSLog(@"UnlockComponentError=%@", strOutput);
        return;
    }

    //  Set the SMTP server.
    Account *acc = list.project.account;
    mailman.SmtpUsername = acc.login;
    mailman.SmtpPassword = acc.password;
    mailman.SmtpHost = acc.host;
    mailman.SmtpSsl = acc.ssl.boolValue;
    mailman.SmtpPort = acc.port;

    [delegate performSelectorOnMainThread:@selector(emailStatus:) withObject:@"Connecting..." waitUntilDone:NO];

    BOOL coonectionSuccess = [mailman OpenSmtpConnection];
    if (coonectionSuccess) {
        NSMutableDictionary *listLog = [NSMutableDictionary dictionary];
        [listLog setValue:list.objectID forKey:@"listId"];
        NSMutableArray *logs = [NSMutableArray array];
        [delegate performSelectorOnMainThread:@selector(emailStatus:) withObject:@"Sending the messages..." waitUntilDone:NO];
        for (int i = 0; i < contacts.count; i++) {
            if (self.stopped)
                break;
            Contact *contact = [contacts objectAtIndex:(NSUInteger) i];
            if (!contact.email)
                continue;

            CkoEmail *email = [[[CkoEmail alloc] init] autorelease];
            email.Subject = [list parsedSubjectForContact:contact];
            NSString *body = [list parsedTemplateForContact:contact];
            email.Body = body;
//            [email SetHtmlBody:[NSString stringWithFormat:@"<html><body>%@</body></html>",body]];
//            [email AddPlainTextAlternativeBody:[self.app flattenHTML:body] ];

            email.FromAddress = acc.fromEmail;
            email.FromName = acc.fromName;
            [email AddTo:contact.name emailAddress:contact.email];

            success = [mailman SendEmail:email];
            
            NSMutableDictionary *log = [NSMutableDictionary dictionary];
            [log setValue:[NSDate date] forKey:@"date"];
            [log setValue:contact.objectID forKey:@"contactId"];
            if (success != YES) {
                [strOutput appendString:mailman.LastErrorText];
                NSLog(@"SendEmailError=%@", strOutput);
                [log setValue:[NSNumber numberWithBool:YES] forKey:@"isError"];
                [log setValue:mailman.LastErrorText forKey:@"error"];
            } else {
//                [delegate performSelectorOnMainThread:statusCallBack withObject:@"Sending the messages..." waitUntilDone:NO];
                [delegate performSelectorOnMainThread:progressCallBack withObject:nil waitUntilDone:NO];
                NSLog(@"sent to:%@", contact.email);
                [log setValue:[NSNumber numberWithBool:NO] forKey:@"isError"];
            }
            [logs addObject:log];
        }
        [listLog setValue:logs forKey:@"logs"];
        [delegate performSelectorOnMainThread:@selector(emailLogs:) withObject:listLog waitUntilDone:NO];
        [delegate performSelectorOnMainThread:finishCallBack withObject:nil waitUntilDone:NO];
        
        success = [mailman CloseSmtpConnection];
        if (success != YES) {
            [strOutput appendString:@"Connection to SMTP server not closed cleanly."];
            [strOutput appendString:@"\n"];
        }

        [strOutput appendString:@"Mail Sent!"];
        [strOutput appendString:@"\n"];

        NSLog(@"ok=%@", strOutput);
//        [delegate performSelectorOnMainThread:statusCallBack withObject:@"Emails Sent!" waitUntilDone:NO];

    } else {
        [strOutput appendString:mailman.LastErrorText];
        [strOutput appendString:@"\n"];
        NSLog(@"ConnectionError=%@", strOutput);
//        [delegate performSelectorOnMainThread:statusCallBack withObject:@"Authentication failed!" waitUntilDone:NO];
        [delegate performSelectorOnMainThread:errorCallBack withObject:nil waitUntilDone:NO];
    }


}

- (void)stop {
    self.stopped = YES;
}


- (void)dealloc {
    [_emails release];
    [super dealloc];
}

@end