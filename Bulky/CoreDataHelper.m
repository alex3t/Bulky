//
//  Created by imac on 10/26/11.
//


#import "CoreDataHelper.h"


@implementation CoreDataHelper {

}
@synthesize lookup = _lookup;

-(void)saveFrom:(NSManagedObjectContext *)current to:(NSManagedObjectContext *)parent
{
    NSNotificationCenter *dnc = [NSNotificationCenter defaultCenter];
          [dnc addObserverForName:NSManagedObjectContextDidSaveNotification
                           object:current queue:nil
                       usingBlock:^(NSNotification *notification)
         {
           [parent mergeChangesFromContextDidSaveNotification:notification];
         }];
        NSError *error;
        if (![current save:&error])
          {
              NSLog(@"Unresolved error %@, %@", error, [error userInfo]);
          }

          [dnc removeObserver:self
                         name:NSManagedObjectContextDidSaveNotification
                       object:current];
}


- (NSManagedObject *)saveObject:(NSManagedObject *)object toContext:(NSManagedObjectContext *)moc {
    NSUndoManager *docUndoMgr = [moc undoManager];
    [docUndoMgr beginUndoGrouping];

    NSManagedObject *object2 = [self copyObject:object toContext:moc parent:nil];

    [moc processPendingChanges];
    [docUndoMgr endUndoGrouping];
    return object2;
}

- (NSManagedObject *)copyObject:(NSManagedObject *)object
                      toContext:(NSManagedObjectContext *)moc
                         parent:(NSString *)parentEntity; {
    NSError *error = nil;
    NSString *entityName = [[object entity] name];
    NSManagedObject *newObject = nil;
    if ([moc objectRegisteredForID:object.objectID])
        newObject = [moc objectWithID:object.objectID];
    else
        newObject = [NSEntityDescription
                insertNewObjectForEntityForName:entityName
                         inManagedObjectContext:moc];


//    if (![moc save:&error])
//    {
//        NSLog(@"Unresolved error %@, %@", error, [error userInfo]);
//    }

    [[self lookup] setObject:newObject forKey:[object objectID]];

    NSArray *attKeys = [[[object entity] attributesByName] allKeys];
    NSDictionary *attributes = [object dictionaryWithValuesForKeys:attKeys];

    [newObject setValuesForKeysWithDictionary:attributes];

    id oldDestObject = nil;
    id temp = nil;
    NSDictionary *relationships = [[object entity] relationshipsByName];
    for (NSString *key in [relationships allKeys]) {

        NSRelationshipDescription *desc = [relationships valueForKey:key];
        NSString *destEntityName = [[desc destinationEntity] name];
        if ([destEntityName isEqualToString:parentEntity]) continue;

        if ([desc isToMany]) {

            NSMutableSet *newDestSet = [NSMutableSet set];

            for (oldDestObject in [object valueForKey:key]) {
                temp = [[self lookup] objectForKey:[oldDestObject objectID]];
                if (!temp) {
                    temp = [self copyObject:oldDestObject
                                  toContext:moc
                                     parent:entityName];
                }
                [newDestSet addObject:temp];
            }

            [newObject setValue:newDestSet forKey:key];

        } else {
            oldDestObject = [object valueForKey:key];
            if (!oldDestObject) continue;

            temp = [[self lookup] objectForKey:[oldDestObject objectID]];
            if (!temp && ![destEntityName isEqualToString:parentEntity]) {
                temp = [self copyObject:oldDestObject
                              toContext:moc
                                 parent:entityName];
            }

            [newObject setValue:temp forKey:key];
        }
    }

    return newObject;
}

- (void)dealloc {
    [_lookup release];
    [super dealloc];
}
@end