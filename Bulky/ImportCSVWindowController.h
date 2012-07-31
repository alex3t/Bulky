//
//  CSVWindowController.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "BaseSheetController.h"

@interface ImportCSVWindowController : BaseSheetController {
    IBOutlet NSProgressIndicator *statusInd;
@private
    BOOL _importBtnEnabled;
    BOOL _excludeFirstRow;
    BOOL _hideFileInfo;
    BOOL _hideStatus;
    NSString *_separator;
    NSString *_fileName;
    NSInteger _recordsNumber;
    NSArray *_contactFields;
    NSArray *_csvFields;
    NSArray *_csvRecords;
}

@property(nonatomic) BOOL importBtnEnabled;
@property(nonatomic) BOOL excludeFirstRow;
@property(nonatomic) BOOL hideFileInfo;
@property(nonatomic) BOOL hideStatus;
@property(nonatomic, retain) NSString *separator;
@property(nonatomic, retain) NSString *fileName;
@property(nonatomic) NSInteger recordsNumber;
@property(nonatomic, retain) NSArray *contactFields;
@property(nonatomic, retain) NSArray *csvFields;
@property(nonatomic, retain) NSArray *csvRecords;

- (IBAction)selectFileAction:(id)sender;

- (IBAction)cancelFormAction:(id)sender;

- (IBAction)importFormAction:(id)sender;

@end
