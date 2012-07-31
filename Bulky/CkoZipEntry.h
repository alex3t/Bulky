// Chilkat Objective-C header.
// Generic/internal class name =  ZipEntry
// Wrapped Chilkat C++ class name =  CkZipEntry

@class CkoString;


@interface CkoZipEntry : NSObject {

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

// property getter: CompressedLength
- (NSNumber *)CompressedLength;

// property getter: CompressionLevel
- (NSNumber *)CompressionLevel;

// property setter: CompressionLevel
- (void)setCompressionLevel: (NSNumber *)longVal;

// property getter: CompressionMethod
- (NSNumber *)CompressionMethod;

// property setter: CompressionMethod
- (void)setCompressionMethod: (NSNumber *)longVal;

// property getter: Crc
- (NSNumber *)Crc;

// property getter: EntryID
- (NSNumber *)EntryID;

// property getter: EntryType
- (NSNumber *)EntryType;

// property getter: FileDateTime
- (NSDate *)FileDateTime;

// property setter: FileDateTime
- (void)setFileDateTime: (NSDate *)dateVal;

// property getter: FileName
- (NSString *)FileName;

// property setter: FileName
- (void)setFileName: (NSString *)input;

// property getter: IsDirectory
- (BOOL)IsDirectory;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: UncompressedLength
- (NSNumber *)UncompressedLength;

// method: AppendData
- (BOOL)AppendData: (NSData *)bdata;

// method: AppendStringAnsi
- (BOOL)AppendStringAnsi: (CkoString *)sdata;

// method: Copy
- (NSData *)Copy;

// method: CopyToBase64
- (NSString *)CopyToBase64;

// method: CopyToHex
- (NSString *)CopyToHex;

// method: Extract
- (BOOL)Extract: (NSString *)dirPath;

// method: ExtractInto
- (BOOL)ExtractInto: (NSString *)dirPath;

// method: Inflate
- (NSData *)Inflate;

// method: InflateToString
- (NSString *)InflateToString: (BOOL)addCR;

// method: InflateToString2
- (NSString *)InflateToString2;

// method: NextEntry
- (CkoZipEntry *)NextEntry;

// method: ReplaceData
- (BOOL)ReplaceData: (NSData *)bdata;

// method: ReplaceStringAnsi
- (BOOL)ReplaceStringAnsi: (CkoString *)sdata;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;


@end
