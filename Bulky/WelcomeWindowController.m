//
//  WelcomeWindowController.m
//  Bulky
//
//  Created by iMac on 2/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "WelcomeWindowController.h"
#import "Account.h"
#import "AppDelegate.h"
#import "Project.h"
#import "Contact.h"
#import "List.h"

@interface WelcomeWindowController ()
- (void)populateProviderFields;

- (void)finish:(BOOL)b;

- (void)validate;

- (AppDelegate *)app;


@end

@implementation WelcomeWindowController

@synthesize saveEnabled = _saveEnabled;
@synthesize hideSmtpDetails = _hideSmtpDetails;
@synthesize emailProviders = _emailProviders;
@synthesize emailProvidersKeys = _emailProvidersKeys;
@synthesize account = _account;
@synthesize ports = _ports;


- (WelcomeWindowController *)init {
    self = [super initWithWindowNibName:@"WelcomeWindow"];

    NSString *plistPath = [[NSBundle mainBundle] pathForResource:@"emailProviders" ofType:@"plist"];
    self.emailProviders = [NSDictionary dictionaryWithContentsOfFile:plistPath];
    self.emailProvidersKeys = self.emailProviders.allKeys;
    self.ports = [NSArray arrayWithObjects:@"25", @"465", @"587", nil];

    return self;
}

- (void)windowWillClose:(NSNotification *)notification {
    NSLog(@"welcome window closed");
//    [self.managedObjectContext rollback];
    NSUserDefaults *standardUserDefaults = [NSUserDefaults standardUserDefaults];
    [standardUserDefaults setBool:YES forKey:@"installed"];
    [standardUserDefaults synchronize];
    [[self app] showMainWindow];
    [[self app] showStartupTip];
}

- (void)awakeFromNib {

}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
//    [self validate];
//    NSLog(@"keypath=%@", keyPath);
    [self validate];
    if ([keyPath isEqualToString:@"provider"]) {
        [self populateProviderFields];
    }
}

- (void)populateProviderFields {

    if ([self.account.provider isEqualToString:@"Custom SMTP"]) {
        self.hideSmtpDetails = NO;
    } else {
        self.hideSmtpDetails = YES;
        NSDictionary *pd = [self.emailProviders valueForKey:self.account.provider];
        self.account.host = [pd valueForKey:@"server"];
        self.account.port = [pd valueForKey:@"port"];
        self.account.ssl = [NSNumber numberWithBool:YES];
    }


}

- (void)dealloc {
    [self.account removeObserver:self forKeyPath:@"provider"];
    [self.account removeObserver:self forKeyPath:@"fromName"];
    [self.account removeObserver:self forKeyPath:@"fromEmail"];
    [self.account removeObserver:self forKeyPath:@"login"];
    [self.account removeObserver:self forKeyPath:@"password"];
    [self.account removeObserver:self forKeyPath:@"host"];
    [self.account removeObserver:self forKeyPath:@"port"];
    [_emailProviders release];
    [_emailProvidersKeys release];
    [_account release];
    [_ports release];
    [super dealloc];
}

- (IBAction)skipAction:(id)sender {
    [self.managedObjectContext rollback];
    [[self window] endEditingFor:nil];
    [[self window] close];
}


- (void)save {

    self.account.isDefault = [[[NSNumber alloc] initWithBool:YES] autorelease];
//    Project *p1 = [NSEntityDescription insertNewObjectForEntityForName:@"Project" inManagedObjectContext:[self managedObjectContext]];
//    [p1 setValue:@"Sample Project" forKey:@"name"];
//    p1.account = self.account;
//    List *l = [NSEntityDescription insertNewObjectForEntityForName:@"List" inManagedObjectContext:[self managedObjectContext]];
//        l.name = @"Bulky developers";
//        l.project = p1;
//
//            Contact *c = [NSEntityDescription insertNewObjectForEntityForName:@"Contact" inManagedObjectContext:[self managedObjectContext]];
//            c.email = @"alex";
//            c.name = @"";
//            c.list = l;
//            [l addContactsObject:c];

    [[self app] saveAction:nil];
}

- (IBAction)saveAction:(id)sender {
    [self save];
    [[self window] endEditingFor:nil];
    [[self window] close];
}


- (void)validate {
    NSError *err = nil;
    [self.account validateForInsert:&err];
    self.saveEnabled = err == nil;
}

- (AppDelegate *)app {
    AppDelegate *app = (AppDelegate *) [[NSApplication sharedApplication] delegate];
    return app;
}

- (NSManagedObjectContext *)managedObjectContext {
    return self.app.managedObjectContext;
}

- (void)prepare {
    self.account = [NSEntityDescription insertNewObjectForEntityForName:@"Account" inManagedObjectContext:[self managedObjectContext]];
    self.account.name = @"Default";
    [self.account addObserver:self forKeyPath:@"provider" options:0 context:nil];
    [self.account addObserver:self forKeyPath:@"fromName" options:0 context:nil];
    [self.account addObserver:self forKeyPath:@"fromEmail" options:0 context:nil];
    [self.account addObserver:self forKeyPath:@"login" options:0 context:nil];
    [self.account addObserver:self forKeyPath:@"password" options:0 context:nil];
    [self.account addObserver:self forKeyPath:@"host" options:0 context:nil];
    [self.account addObserver:self forKeyPath:@"port" options:0 context:nil];
    [self validate];
    [self populateProviderFields];
    [[self window] makeFirstResponder:fromNameFld];
}
@end
