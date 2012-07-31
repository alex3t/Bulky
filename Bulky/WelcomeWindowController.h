//
//  WelcomeWindowController.h
//  Bulky
//
//  Created by iMac on 2/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//



@class Account;

@interface WelcomeWindowController : NSWindowController <NSWindowDelegate> {
    IBOutlet NSTextField *fromNameFld;
@private
    Account *_account;
    BOOL _saveEnabled;
    BOOL _hideSmtpDetails;
    NSDictionary *_emailProviders;
    NSArray *_emailProvidersKeys;
    NSArray *_ports;
}

@property(nonatomic) BOOL saveEnabled;
@property(nonatomic) BOOL hideSmtpDetails;
@property(nonatomic, retain) NSDictionary *emailProviders;
@property(nonatomic, retain) NSArray *emailProvidersKeys;
@property(nonatomic, retain) Account *account;
@property(nonatomic, retain) NSArray *ports;


- (IBAction)skipAction:(id)sender;

- (NSManagedObjectContext *)managedObjectContext;

- (IBAction)saveAction:(id)sender;

- (void)prepare;
@end
