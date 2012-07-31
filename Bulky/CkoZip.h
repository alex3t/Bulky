// Chilkat Objective-C header.
// Generic/internal class name =  Zip
// Wrapped Chilkat C++ class name =  CkZip

@class CkoZipEntry;
@class CkoStringArray;


@interface CkoZip : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: AppendFromDir
- (NSString *)AppendFromDir;

// property setter: AppendFromDir
- (void)setAppendFromDir: (NSString *)input;

// property getter: CaseSensitive
- (BOOL)CaseSensitive;

// property setter: CaseSensitive
- (void)setCaseSensitive: (BOOL)boolVal;

// property getter: ClearArchiveAttribute
- (BOOL)ClearArchiveAttribute;

// property setter: ClearArchiveAttribute
- (void)setClearArchiveAttribute: (BOOL)boolVal;

// property getter: ClearReadOnlyAttr
- (BOOL)ClearReadOnlyAttr;

// property setter: ClearReadOnlyAttr
- (void)setClearReadOnlyAttr: (BOOL)boolVal;

// property getter: Comment
- (NSString *)Comment;

// property setter: Comment
- (void)setComment: (NSString *)input;

// property getter: DecryptPassword
- (NSString *)DecryptPassword;

// property setter: DecryptPassword
- (void)setDecryptPassword: (NSString *)input;

// property getter: DiscardPaths
- (BOOL)DiscardPaths;

// property setter: DiscardPaths
- (void)setDiscardPaths: (BOOL)boolVal;

// property getter: EncryptKeyLength
- (NSNumber *)EncryptKeyLength;

// property setter: EncryptKeyLength
- (void)setEncryptKeyLength: (NSNumber *)longVal;

// property getter: EncryptPassword
- (NSString *)EncryptPassword;

// property setter: EncryptPassword
- (void)setEncryptPassword: (NSString *)input;

// property getter: Encryption
- (NSNumber *)Encryption;

// property setter: Encryption
- (void)setEncryption: (NSNumber *)longVal;

// property getter: FileCount
- (NSNumber *)FileCount;

// property getter: FileName
- (NSString *)FileName;

// property setter: FileName
- (void)setFileName: (NSString *)input;

// property getter: HasZipFormatErrors
- (BOOL)HasZipFormatErrors;

// property getter: IgnoreAccessDenied
- (BOOL)IgnoreAccessDenied;

// property setter: IgnoreAccessDenied
- (void)setIgnoreAccessDenied: (BOOL)boolVal;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: NumEntries
- (NSNumber *)NumEntries;

// property getter: OemCodePage
- (NSNumber *)OemCodePage;

// property setter: OemCodePage
- (void)setOemCodePage: (NSNumber *)longVal;

// property getter: OverwriteExisting
- (BOOL)OverwriteExisting;

// property setter: OverwriteExisting
- (void)setOverwriteExisting: (BOOL)boolVal;

// property getter: PasswordProtect
- (BOOL)PasswordProtect;

// property setter: PasswordProtect
- (void)setPasswordProtect: (BOOL)boolVal;

// property getter: PathPrefix
- (NSString *)PathPrefix;

// property setter: PathPrefix
- (void)setPathPrefix: (NSString *)input;

// property getter: Proxy
- (NSString *)Proxy;

// property setter: Proxy
- (void)setProxy: (NSString *)input;

// property getter: TempDir
- (NSString *)TempDir;

// property setter: TempDir
- (void)setTempDir: (NSString *)input;

// property getter: TextFlag
- (BOOL)TextFlag;

// property setter: TextFlag
- (void)setTextFlag: (BOOL)boolVal;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// method: AddNoCompressExtension
- (void)AddNoCompressExtension: (NSString *)fileExtension;

// method: AppendBase64
- (CkoZipEntry *)AppendBase64: (NSString *)fileName 
	data: (NSString *)data;

// method: AppendCompressed
- (CkoZipEntry *)AppendCompressed: (NSString *)fileName 
	data: (NSData *)data;

// method: AppendData
- (CkoZipEntry *)AppendData: (NSString *)fileName 
	data: (NSData *)data;

// method: AppendData2
- (CkoZipEntry *)AppendData2: (NSString *)fileName 
	data: (NSString *)data 
	dataLen: (NSNumber *)dataLen;

// method: AppendFiles
- (BOOL)AppendFiles: (NSString *)filePattern 
	recurse: (BOOL)recurse;

// method: AppendFilesEx
- (BOOL)AppendFilesEx: (NSString *)filePattern 
	recurse: (BOOL)recurse 
	saveExtraPath: (BOOL)saveExtraPath 
	archiveOnly: (BOOL)archiveOnly 
	includeHidden: (BOOL)includeHidden 
	includeSystem: (BOOL)includeSystem;

// method: AppendHex
- (CkoZipEntry *)AppendHex: (NSString *)fileName 
	data: (NSString *)data;

// method: AppendMultiple
- (BOOL)AppendMultiple: (CkoStringArray *)fileSpecs 
	recurse: (BOOL)recurse;

// method: AppendNew
- (CkoZipEntry *)AppendNew: (NSString *)fileName;

// method: AppendNewDir
- (CkoZipEntry *)AppendNewDir: (NSString *)dirName;

// method: AppendOneFileOrDir
- (BOOL)AppendOneFileOrDir: (NSString *)fileOrDirName 
	saveExtraPath: (BOOL)saveExtraPath;

// method: AppendString
- (CkoZipEntry *)AppendString: (NSString *)fileName 
	str: (NSString *)str;

// method: AppendString2
- (CkoZipEntry *)AppendString2: (NSString *)fileName 
	str: (NSString *)str 
	charset: (NSString *)charset;

// method: AppendZip
- (BOOL)AppendZip: (NSString *)zipFileName;

// method: CloseZip
- (void)CloseZip;

// method: DeleteEntry
- (BOOL)DeleteEntry: (CkoZipEntry *)entry;

// method: ExcludeDir
- (void)ExcludeDir: (NSString *)dirName;

// method: Extract
- (BOOL)Extract: (NSString *)dirPath;

// method: ExtractInto
- (BOOL)ExtractInto: (NSString *)dirPath;

// method: ExtractMatching
- (BOOL)ExtractMatching: (NSString *)dirPath 
	pattern: (NSString *)pattern;

// method: ExtractNewer
- (BOOL)ExtractNewer: (NSString *)dirPath;

// method: FirstEntry
- (CkoZipEntry *)FirstEntry;

// method: FirstMatchingEntry
- (CkoZipEntry *)FirstMatchingEntry: (NSString *)pattern;

// method: GetDirectoryAsXML
- (void)GetDirectoryAsXML: (NSString *)xml;

// method: GetEntryByID
- (CkoZipEntry *)GetEntryByID: (NSNumber *)entryID;

// method: GetEntryByIndex
- (CkoZipEntry *)GetEntryByIndex: (NSNumber *)index;

// method: GetEntryByName
- (CkoZipEntry *)GetEntryByName: (NSString *)entryName;

// method: GetExclusions
- (CkoStringArray *)GetExclusions;

// method: InsertNew
- (CkoZipEntry *)InsertNew: (NSString *)fileName 
	beforeIndex: (NSNumber *)beforeIndex;

// method: IsNoCompressExtension
- (BOOL)IsNoCompressExtension: (NSString *)fileExtension;

// method: IsPasswordProtected
- (BOOL)IsPasswordProtected: (NSString *)zipFilename;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: NewZip
- (BOOL)NewZip: (NSString *)zipFileName;

// method: OpenFromByteData
- (BOOL)OpenFromByteData: (NSData *)byteData;

// method: OpenFromMemory
- (BOOL)OpenFromMemory: (NSData *)zipFileInMemory 
	dataLen: (NSNumber *)dataLen;

// method: OpenFromWeb
- (BOOL)OpenFromWeb: (NSString *)url;

// method: OpenZip
- (BOOL)OpenZip: (NSString *)zipFileName;

// method: QuickAppend
- (BOOL)QuickAppend: (NSString *)zipFilename;

// method: RemoveNoCompressExtension
- (void)RemoveNoCompressExtension: (NSString *)fileExtension;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetCompressionLevel
- (void)SetCompressionLevel: (NSNumber *)level;

// method: SetExclusions
- (void)SetExclusions: (CkoStringArray *)excludePatterns;

// method: SetPassword
- (void)SetPassword: (NSString *)password;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)regCode;

// method: Unzip
- (NSNumber *)Unzip: (NSString *)dirPath;

// method: UnzipInto
- (NSNumber *)UnzipInto: (NSString *)dirPath;

// method: UnzipMatching
- (NSNumber *)UnzipMatching: (NSString *)dirPath 
	pattern: (NSString *)pattern 
	verbose: (BOOL)verbose;

// method: UnzipMatchingInto
- (NSNumber *)UnzipMatchingInto: (NSString *)dirPath 
	pattern: (NSString *)pattern 
	verbose: (BOOL)verbose;

// method: UnzipNewer
- (NSNumber *)UnzipNewer: (NSString *)dirPath;

// method: VerifyPassword
- (BOOL)VerifyPassword;

// method: WriteToMemory
- (NSData *)WriteToMemory;

// method: WriteZip
- (BOOL)WriteZip;

// method: WriteZipAndClose
- (BOOL)WriteZipAndClose;


@end
