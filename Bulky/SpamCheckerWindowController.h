//
//  SpamCheckerWindowController.h
//  Bulky
//
//  Created by iMac on 2/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MainWindowController;

@interface SpamCheckerWindowController : NSWindowController
{
    IBOutlet NSProgressIndicator *checkInd;

@private
    MainWindowController *_parent;
    NSString *_reportStr;
    NSString *_scoreStr;
    NSColor *_scoreColor;

    BOOL _enableCheckBtn;
}
@property(nonatomic, retain) MainWindowController *parent;
@property(nonatomic, retain) NSString *reportStr;
@property(nonatomic, retain) NSString *scoreStr;
@property(nonatomic, retain) NSColor *scoreColor;

@property(nonatomic) BOOL enableCheckBtn;


-(IBAction)checkAction:(id)sender;
-(IBAction)closeAction:(id)sender;
@end
