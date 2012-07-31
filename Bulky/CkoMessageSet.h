// Chilkat Objective-C header.
// Generic/internal class name =  MessageSet
// Wrapped Chilkat C++ class name =  CkMessageSet



@interface CkoMessageSet : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: Count
- (NSNumber *)Count;

// property getter: HasUids
- (BOOL)HasUids;

// property setter: HasUids
- (void)setHasUids: (BOOL)boolVal;

// method: ContainsId
- (BOOL)ContainsId: (NSNumber *)id;

// method: FromCompactString
- (BOOL)FromCompactString: (NSString *)str;

// method: GetId
- (NSNumber *)GetId: (NSNumber *)index;

// method: InsertId
- (void)InsertId: (NSNumber *)id;

// method: RemoveId
- (void)RemoveId: (NSNumber *)id;

// method: ToCompactString
- (NSString *)ToCompactString;

// method: ToString
- (NSString *)ToString;


@end
