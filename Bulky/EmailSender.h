//
//  Created by imac on 10/12/11.
//





//#import "SKPSMTPMessage.h"
//#import <MailCore/MailCore.h>

//@class CWSMTP;

@class Account;
@class List;

@interface EmailSender : NSObject  { //<SKPSMTPMessageDelegate>
//    CWSMTP *smtp;
    id delegate;
    SEL progressCallBack;
//    SEL statusCallBack;
    SEL errorCallBack;
    SEL finishCallBack;

    int _numberOfMessages;
    int _numberOfSentMessages;
    NSArray *_emails;
    BOOL _stopped;
}

@property(nonatomic) int numberOfMessages;
@property(nonatomic, retain) NSArray *emails;
@property(nonatomic) int numberOfSentMessages;
@property(nonatomic) BOOL stopped;


- (id)initWithDelegate:(id)delegate progressCallback:(SEL)pcallBack errorCallback:(SEL)ecallBack finishCallback:(SEL)fc;
- (void)sendEmails:(NSArray *)params;

- (void)stop;

@end