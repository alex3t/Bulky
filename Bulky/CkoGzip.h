// Chilkat Objective-C header.
// Generic/internal class name =  Gzip
// Wrapped Chilkat C++ class name =  CkGzip



@interface CkoGzip : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: Comment
- (NSString *)Comment;

// property setter: Comment
- (void)setComment: (NSString *)input;

// property getter: ExtraData
- (NSData *)ExtraData;

// property setter: ExtraData
- (void)setExtraData: (NSData *)data;

// property getter: ExtraData
- (NSMutableData *)ExtraDataMutable;

// property setter: ExtraData
- (void)setExtraDataMutable: (NSMutableData *)data;

// property getter: Filename
- (NSString *)Filename;

// property setter: Filename
- (void)setFilename: (NSString *)input;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: LastMod
- (NSDate *)LastMod;

// property setter: LastMod
- (void)setLastMod: (NSDate *)dateVal;

// property getter: UseCurrentDate
- (BOOL)UseCurrentDate;

// property setter: UseCurrentDate
- (void)setUseCurrentDate: (BOOL)boolVal;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// method: CompressFile
- (BOOL)CompressFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: CompressFile2
- (BOOL)CompressFile2: (NSString *)inFilename 
	embeddedFilename: (NSString *)embeddedFilename 
	outFilename: (NSString *)outFilename;

// method: CompressFileToMem
- (NSData *)CompressFileToMem: (NSString *)inFilename;

// method: CompressMemToFile
- (BOOL)CompressMemToFile: (NSData *)db 
	outFilename: (NSString *)outFilename;

// method: CompressMemory
- (NSData *)CompressMemory: (NSData *)dbIn;

// method: CompressString
- (NSData *)CompressString: (NSString *)inStr 
	outCharset: (NSString *)outCharset;

// method: CompressStringToFile
- (BOOL)CompressStringToFile: (NSString *)inStr 
	outCharset: (NSString *)outCharset 
	outFilename: (NSString *)outFilename;

// method: Decode
- (NSData *)Decode: (NSString *)str 
	encoding: (NSString *)encoding;

// method: DeflateStringENC
- (NSString *)DeflateStringENC: (NSString *)str 
	charset: (NSString *)charset 
	encoding: (NSString *)encoding;

// method: Encode
- (NSString *)Encode: (NSData *)byteData 
	encoding: (NSString *)encoding;

// method: ExamineFile
- (BOOL)ExamineFile: (NSString *)inGzFilename;

// method: ExamineMemory
- (BOOL)ExamineMemory: (NSData *)inGzData;

// method: InflateStringENC
- (NSString *)InflateStringENC: (NSString *)str 
	charset: (NSString *)charset 
	encoding: (NSString *)encoding;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: ReadFile
- (NSData *)ReadFile: (NSString *)filename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: UnTarGz
- (BOOL)UnTarGz: (NSString *)gzFilename 
	destDir: (NSString *)destDir 
	bNoAbsolute: (BOOL)bNoAbsolute;

// method: UncompressFile
- (BOOL)UncompressFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: UncompressFileToMem
- (NSData *)UncompressFileToMem: (NSString *)inFilename;

// method: UncompressFileToString
- (NSString *)UncompressFileToString: (NSString *)inFilename 
	inCharset: (NSString *)inCharset;

// method: UncompressMemToFile
- (BOOL)UncompressMemToFile: (NSData *)db 
	outFilename: (NSString *)outFilename;

// method: UncompressMemory
- (NSData *)UncompressMemory: (NSData *)dbIn;

// method: UncompressString
- (NSString *)UncompressString: (NSData *)inData 
	inCharset: (NSString *)inCharset;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: WriteFile
- (BOOL)WriteFile: (NSString *)filename 
	binaryData: (NSData *)binaryData;

// method: XfdlToXml
- (NSString *)XfdlToXml: (NSString *)xfdl;


@end
