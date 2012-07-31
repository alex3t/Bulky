// Chilkat Objective-C header.
// Generic/internal class name =  DirTree
// Wrapped Chilkat C++ class name =  CkDirTree



@interface CkoDirTree : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: BaseDir
- (NSString *)BaseDir;

// property setter: BaseDir
- (void)setBaseDir: (NSString *)input;

// property getter: DoneIterating
- (BOOL)DoneIterating;

// property getter: FileSize32
- (NSNumber *)FileSize32;

// property getter: FileSize64
- (NSNumber *)FileSize64;

// property getter: FullPath
- (NSString *)FullPath;

// property getter: FullUncPath
- (NSString *)FullUncPath;

// property getter: IsDirectory
- (BOOL)IsDirectory;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: Recurse
- (BOOL)Recurse;

// property setter: Recurse
- (void)setRecurse: (BOOL)boolVal;

// property getter: RelativePath
- (NSString *)RelativePath;

// method: AdvancePosition
- (BOOL)AdvancePosition;

// method: BeginIterate
- (BOOL)BeginIterate;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;


@end
