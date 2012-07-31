//
//  ABWindowController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"

@interface ImportABWindowController : BaseSheetController {
    IBOutlet NSArrayController *recordsCtrl;
    IBOutlet NSProgressIndicator *saveInd;
@private
    NSArray *_abRecords;
    NSArray *_selectedAbRecords;

}

@property(nonatomic, retain) NSArray *abRecords;
@property(nonatomic, retain) NSArray *selectedAbRecords;


- (IBAction)cancelFormAction:(id)sender;

- (IBAction)importFormAction:(id)sender;

@end
