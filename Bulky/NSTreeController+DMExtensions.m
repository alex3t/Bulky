//
//  Created by imac on 2/5/12.
//


#import "NSTreeController+DMExtensions.h"


@interface NSTreeController (DMExtensions_Private)
- (NSIndexPath *)_indexPathFromIndexPath:(NSIndexPath *)baseIndexPath inChildren:(NSArray *)children
                              childCount:(unsigned int)childCount toObject:(id)object;
@end


@implementation NSTreeController (DMExtensions)

- (void)setSelectedObjects:(NSArray *)newSelectedObjects; {
    NSMutableArray *indexPaths = [NSMutableArray array];
    unsigned int selectedObjectIndex;
    for (selectedObjectIndex = 0; selectedObjectIndex < [newSelectedObjects count];
         selectedObjectIndex++) {
        id selectedObject = [newSelectedObjects objectAtIndex:selectedObjectIndex];
        NSIndexPath *indexPath = [self indexPathToObject:selectedObject];
        if (indexPath)
            [indexPaths addObject:indexPath];
    }

    [self setSelectionIndexPaths:indexPaths];
}

- (NSIndexPath *)indexPathToObject:(id)object; {
    NSArray *children = [self content];
    return [self _indexPathFromIndexPath:nil inChildren:children childCount:[children count]
                                toObject:object];
}

@end


@implementation NSTreeController (DMExtensions_Private)
- (NSIndexPath *)_indexPathFromIndexPath:(NSIndexPath *)baseIndexPath inChildren:(NSArray *)children
                              childCount:(unsigned int)childCount toObject:(id)object; {
    unsigned int childIndex;
    for (childIndex = 0; childIndex < childCount; childIndex++) {
        id childObject = [children objectAtIndex:childIndex];

        NSMutableSet *childsChildren = nil;
        unsigned int childsChildrenCount = 0;
        NSString *leafKeyPath = [self leafKeyPath];
        if (!leafKeyPath || [[childObject valueForKey:leafKeyPath] boolValue] == NO) {
            NSString *countKeyPath = [self countKeyPath];
            if (countKeyPath)
                childsChildrenCount = [[childObject valueForKey:leafKeyPath] unsignedIntValue];
            if (!countKeyPath || childsChildrenCount != 0) {
                NSString *childrenKeyPath = [self childrenKeyPath];
                childsChildren = [childObject mutableSetValueForKey:childrenKeyPath];
                if (!countKeyPath)
                    childsChildrenCount = [childsChildren count];
            }
        }

        BOOL objectFound = [object isEqual:childObject];
        if (!objectFound && childsChildrenCount == 0)
            continue;

        NSIndexPath *indexPath = (baseIndexPath == nil) ? [NSIndexPath indexPathWithIndex:childIndex]
                : [baseIndexPath indexPathByAddingIndex:childIndex];


        if (objectFound)
            return indexPath;

//change NSSet to NSArray and sort
        NSMutableArray *childsChildrenAsArray = [NSMutableArray arrayWithArray:[childsChildren allObjects]];
        [childsChildrenAsArray sortUsingDescriptors:[self sortDescriptors]];

        NSIndexPath *childIndexPath = [self _indexPathFromIndexPath:indexPath inChildren:childsChildrenAsArray
                                                         childCount:childsChildrenCount toObject:object];
        if (childIndexPath)
            return childIndexPath;
    }

    return nil;
}

@end