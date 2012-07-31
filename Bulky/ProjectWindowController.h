//
//  ProjectWindowController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"

@class Project;

@interface ProjectWindowController : BaseSheetController
{
    IBOutlet NSObjectController *objCtrl;
    IBOutlet NSArrayController *accountsCtrl;
@private
    Project *_obj; 


}
@property(nonatomic, retain) Project *obj;


-(IBAction)openAccountPrefsActions:(id)sender;
- (IBAction)cancelFormAction:(id)sender;
- (IBAction)saveFormAction:(id)sender;

@end
