// Chilkat Objective-C header.
// Generic/internal class name =  UnixCompress
// Wrapped Chilkat C++ class name =  CkUnixCompress



@interface CkoUnixCompress : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// method: CompressFile
- (BOOL)CompressFile: (NSString *)inFilename 
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

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: UnTarZ
- (BOOL)UnTarZ: (NSString *)zFilename 
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


@end
