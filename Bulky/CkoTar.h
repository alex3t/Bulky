// Chilkat Objective-C header.
// Generic/internal class name =  Tar
// Wrapped Chilkat C++ class name =  CkTar



@interface CkoTar : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: Charset
- (NSString *)Charset;

// property setter: Charset
- (void)setCharset: (NSString *)input;

// property getter: DirMode
- (NSNumber *)DirMode;

// property setter: DirMode
- (void)setDirMode: (NSNumber *)intVal;

// property getter: DirPrefix
- (NSString *)DirPrefix;

// property setter: DirPrefix
- (void)setDirPrefix: (NSString *)input;

// property getter: FileMode
- (NSNumber *)FileMode;

// property setter: FileMode
- (void)setFileMode: (NSNumber *)intVal;

// property getter: GroupId
- (NSNumber *)GroupId;

// property setter: GroupId
- (void)setGroupId: (NSNumber *)intVal;

// property getter: GroupName
- (NSString *)GroupName;

// property setter: GroupName
- (void)setGroupName: (NSString *)input;

// property getter: HeartbeatMs
- (NSNumber *)HeartbeatMs;

// property setter: HeartbeatMs
- (void)setHeartbeatMs: (NSNumber *)intVal;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: NoAbsolutePaths
- (BOOL)NoAbsolutePaths;

// property setter: NoAbsolutePaths
- (void)setNoAbsolutePaths: (BOOL)boolVal;

// property getter: NumDirRoots
- (NSNumber *)NumDirRoots;

// property getter: ScriptFileMode
- (NSNumber *)ScriptFileMode;

// property setter: ScriptFileMode
- (void)setScriptFileMode: (NSNumber *)intVal;

// property getter: UntarCaseSensitive
- (BOOL)UntarCaseSensitive;

// property setter: UntarCaseSensitive
- (void)setUntarCaseSensitive: (BOOL)boolVal;

// property getter: UntarDebugLog
- (BOOL)UntarDebugLog;

// property setter: UntarDebugLog
- (void)setUntarDebugLog: (BOOL)boolVal;

// property getter: UntarDiscardPaths
- (BOOL)UntarDiscardPaths;

// property setter: UntarDiscardPaths
- (void)setUntarDiscardPaths: (BOOL)boolVal;

// property getter: UntarFromDir
- (NSString *)UntarFromDir;

// property setter: UntarFromDir
- (void)setUntarFromDir: (NSString *)input;

// property getter: UntarMatchPattern
- (NSString *)UntarMatchPattern;

// property setter: UntarMatchPattern
- (void)setUntarMatchPattern: (NSString *)input;

// property getter: UntarMaxCount
- (NSNumber *)UntarMaxCount;

// property setter: UntarMaxCount
- (void)setUntarMaxCount: (NSNumber *)intVal;

// property getter: UserId
- (NSNumber *)UserId;

// property setter: UserId
- (void)setUserId: (NSNumber *)intVal;

// property getter: UserName
- (NSString *)UserName;

// property setter: UserName
- (void)setUserName: (NSString *)input;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// property getter: WriteFormat
- (NSString *)WriteFormat;

// property setter: WriteFormat
- (void)setWriteFormat: (NSString *)input;

// method: AddDirRoot
- (BOOL)AddDirRoot: (NSString *)dirPath;

// method: GetDirRoot
- (NSString *)GetDirRoot: (NSNumber *)index;

// method: ListXml
- (NSString *)ListXml: (NSString *)tarFilename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: Untar
- (NSNumber *)Untar: (NSString *)tarFilename;

// method: UntarBz2
- (BOOL)UntarBz2: (NSString *)tarFilename;

// method: UntarFirstMatchingToMemory
- (NSData *)UntarFirstMatchingToMemory: (NSData *)tarFileBytes 
	matchPattern: (NSString *)matchPattern;

// method: UntarFromMemory
- (NSNumber *)UntarFromMemory: (NSData *)tarFileBytes;

// method: UntarGz
- (BOOL)UntarGz: (NSString *)tarFilename;

// method: UntarZ
- (BOOL)UntarZ: (NSString *)tarFilename;

// method: VerifyTar
- (BOOL)VerifyTar: (NSString *)tarFilename;

// method: WriteTar
- (BOOL)WriteTar: (NSString *)tarFilename;

// method: WriteTarBz2
- (BOOL)WriteTarBz2: (NSString *)outFilename;

// method: WriteTarGz
- (BOOL)WriteTarGz: (NSString *)outFilename;


@end
