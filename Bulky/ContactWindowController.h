//
//  ContactWindowController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"

@class Contact;
@class List;

@interface ContactWindowController : BaseSheetController {
    IBOutlet NSObjectController *objCtrl;
    IBOutlet NSButton *saveAndNewBtn;
    IBOutlet NSButton *cancelBtn;
@private
    Contact *_obj;

    NSArray *_titles;

}


@property(nonatomic, retain) Contact *obj;
@property(nonatomic, retain) NSArray *titles;


- (IBAction)cancelFormAction:(id)sender;

- (IBAction)saveFormAction:(id)sender;

- (IBAction)saveAndNewFormAction:(id)sender;


@end
