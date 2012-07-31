// Chilkat Objective-C header.
// Generic/internal class name =  FileAccess
// Wrapped Chilkat C++ class name =  CkFileAccess



@interface CkoFileAccess : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: CurrentDir
- (NSString *)CurrentDir;

// property getter: EndOfFile
- (BOOL)EndOfFile;

// property getter: FileOpenError
- (NSNumber *)FileOpenError;

// property getter: FileOpenErrorMsg
- (NSString *)FileOpenErrorMsg;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// method: AppendAnsi
- (BOOL)AppendAnsi: (NSString *)text;

// method: AppendText
- (BOOL)AppendText: (NSString *)text 
	charset: (NSString *)charset;

// method: AppendUnicodeBOM
- (BOOL)AppendUnicodeBOM;

// method: AppendUtf8BOM
- (BOOL)AppendUtf8BOM;

// method: DirAutoCreate
- (BOOL)DirAutoCreate: (NSString *)path;

// method: DirCreate
- (BOOL)DirCreate: (NSString *)path;

// method: DirDelete
- (BOOL)DirDelete: (NSString *)path;

// method: DirEnsureExists
- (BOOL)DirEnsureExists: (NSString *)filePath;

// method: FileClose
- (void)FileClose;

// method: FileCopy
- (BOOL)FileCopy: (NSString *)existing 
	newFilename: (NSString *)newFilename 
	failIfExists: (BOOL)failIfExists;

// method: FileDelete
- (BOOL)FileDelete: (NSString *)filename;

// method: FileExists
- (BOOL)FileExists: (NSString *)filename;

// method: FileRead
- (NSData *)FileRead: (NSNumber *)numBytes;

// method: FileRename
- (BOOL)FileRename: (NSString *)existing 
	newFilename: (NSString *)newFilename;

// method: FileSeek
- (BOOL)FileSeek: (NSNumber *)offset 
	origin: (NSNumber *)origin;

// method: FileSize
- (NSNumber *)FileSize: (NSString *)filename;

// method: FileWrite
- (BOOL)FileWrite: (NSData *)data;

// method: GetTempFilename
- (NSString *)GetTempFilename: (NSString *)dirName 
	prefix: (NSString *)prefix;

// method: OpenForAppend
- (BOOL)OpenForAppend: (NSString *)filePath;

// method: OpenForRead
- (BOOL)OpenForRead: (NSString *)filePath;

// method: OpenForReadWrite
- (BOOL)OpenForReadWrite: (NSString *)filePath;

// method: OpenForWrite
- (BOOL)OpenForWrite: (NSString *)filePath;

// method: ReadBinaryToEncoded
- (NSString *)ReadBinaryToEncoded: (NSString *)filename 
	encoding: (NSString *)encoding;

// method: ReadEntireFile
- (NSData *)ReadEntireFile: (NSString *)filename;

// method: ReadEntireTextFile
- (NSString *)ReadEntireTextFile: (NSString *)filename 
	charset: (NSString *)charset;

// method: ReassembleFile
- (BOOL)ReassembleFile: (NSString *)partsDirPath 
	partPrefix: (NSString *)partPrefix 
	partExtension: (NSString *)partExtension 
	reassembledFilename: (NSString *)reassembledFilename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetCurrentDir
- (BOOL)SetCurrentDir: (NSString *)path;

// method: SplitFile
- (BOOL)SplitFile: (NSString *)fileToSplit 
	partPrefix: (NSString *)partPrefix 
	partExtension: (NSString *)partExtension 
	partSize: (NSNumber *)partSize 
	outputDirPath: (NSString *)outputDirPath;

// method: TreeDelete
- (BOOL)TreeDelete: (NSString *)path;

// method: WriteEntireFile
- (BOOL)WriteEntireFile: (NSString *)filename 
	fileData: (NSData *)fileData;

// method: WriteEntireTextFile
- (BOOL)WriteEntireTextFile: (NSString *)filename 
	fileData: (NSString *)fileData 
	charset: (NSString *)charset 
	includePreamble: (BOOL)includePreamble;


@end
