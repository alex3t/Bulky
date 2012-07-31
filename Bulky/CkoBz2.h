// Chilkat Objective-C header.
// Generic/internal class name =  Bz2
// Wrapped Chilkat C++ class name =  CkBz2



@interface CkoBz2 : NSObject {

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
- (BOOL)CompressMemToFile: (NSData *)inData 
	outFilename: (NSString *)outFilename;

// method: CompressMemory
- (NSData *)CompressMemory: (NSData *)inData;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: UncompressFile
- (BOOL)UncompressFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: UncompressFileToMem
- (NSData *)UncompressFileToMem: (NSString *)inFilename;

// method: UncompressMemToFile
- (BOOL)UncompressMemToFile: (NSData *)inData 
	outFilename: (NSString *)outFilename;

// method: UncompressMemory
- (NSData *)UncompressMemory: (NSData *)inData;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)regCode;


@end
