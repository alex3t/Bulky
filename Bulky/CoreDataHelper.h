//
//  Created by imac on 10/26/11.
//


#import <Foundation/Foundation.h>


@interface CoreDataHelper : NSObject
{
    NSMutableDictionary* _lookup;
}
@property(nonatomic, retain) NSMutableDictionary *lookup;

-(void)saveFrom:(NSManagedObjectContext *)current to:(NSManagedObjectContext *)parent;

- (NSManagedObject *)saveObject:(NSManagedObject *)object toContext:(NSManagedObjectContext *)moc;

- (NSManagedObject*)copyObject:(NSManagedObject*)object
                     toContext:(NSManagedObjectContext*)moc
                        parent:(NSString*)parentEntity;
@end