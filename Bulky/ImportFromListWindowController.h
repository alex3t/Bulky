//
//  ImportFromListWindowController.h
//  Bulky
//
//  Created by iMac on 2/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"

@interface ImportFromListWindowController : BaseSheetController
{
    IBOutlet NSProgressIndicator *statusInd;
    IBOutlet NSArrayController *projectsCtrl;
    IBOutlet NSArrayController *listsCtrl;
    IBOutlet NSArrayController *contactsCtrl;

    BOOL skipObserving;
}
-(IBAction)cancelFormAction:(id)sender;
-(IBAction)importFormAction:(id)sender;
-(IBAction)selectContactsAction:(id)sender;

@end
