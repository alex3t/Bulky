//
//  List.h
//  Bulky
//
//  Created by iMac on 1/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Project;
@class Contact;


@interface List : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * template;
@property (nonatomic, retain) NSString * subject;
@property (nonatomic, retain) Project *project;
@property (nonatomic, retain) NSSet *contacts;
@property (nonatomic, retain) NSSet * logs;

- (NSString *)parsedSubjectForContact:(Contact *)contact1;

- (NSString *)parsedTemplateForContact:(Contact *)c;

@end

@interface List (CoreDataGeneratedAccessors)

- (void)addContactsObject:(NSManagedObject *)value;
- (void)removeContactsObject:(NSManagedObject *)value;
- (void)addContacts:(NSSet *)values;
- (void)removeContacts:(NSSet *)values;
@end
