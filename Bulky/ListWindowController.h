//
//  ListWindowController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"

@class List;

@interface ListWindowController : BaseSheetController
{
    IBOutlet NSObjectController *objCtrl;
    IBOutlet NSArrayController *projectsCtrl;
    IBOutlet NSArrayController *projectsForCopyCtrl;
    IBOutlet NSArrayController *listsForCopyCtrl;
    IBOutlet NSProgressIndicator *savingInd;
@private
    List *_obj;
    BOOL _allowSelectList;
    BOOL _hideCopyBlock;

}
@property(nonatomic, retain) List *obj;
@property(nonatomic) BOOL allowSelectList;
@property(nonatomic) BOOL hideCopyBlock;


- (IBAction)cancelFormAction:(id)sender;
- (IBAction)saveFormAction:(id)sender;
- (IBAction)checkForCopyAction:(id)sender;
@end
