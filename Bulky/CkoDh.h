// Chilkat Objective-C header.
// Generic/internal class name =  Dh
// Wrapped Chilkat C++ class name =  CkDh



@interface CkoDh : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: G
- (NSNumber *)G;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: P
- (NSString *)P;

// property getter: Version
- (NSString *)Version;

// method: CreateE
- (NSString *)CreateE: (NSNumber *)numBits;

// method: FindK
- (NSString *)FindK: (NSString *)e;

// method: GenPG
- (BOOL)GenPG: (NSNumber *)numBits 
	g: (NSNumber *)g;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetPG
- (BOOL)SetPG: (NSString *)p 
	g: (NSNumber *)g;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: UseKnownPrime
- (void)UseKnownPrime: (NSNumber *)index;


@end
