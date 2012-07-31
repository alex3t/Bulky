// Chilkat Objective-C header.
// Generic/internal class name =  Mailboxes
// Wrapped Chilkat C++ class name =  CkMailboxes



@interface CkoMailboxes : NSObject {

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

// method: GetName
- (NSString *)GetName: (NSNumber *)index;

// method: HasInferiors
- (BOOL)HasInferiors: (NSNumber *)index;

// method: IsMarked
- (BOOL)IsMarked: (NSNumber *)index;

// method: IsSelectable
- (BOOL)IsSelectable: (NSNumber *)index;


@end
