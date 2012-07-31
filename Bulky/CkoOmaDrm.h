// Chilkat Objective-C header.
// Generic/internal class name =  OmaDrm
// Wrapped Chilkat C++ class name =  CkOmaDrm



@interface CkoOmaDrm : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: Base64Key
- (NSString *)Base64Key;

// property setter: Base64Key
- (void)setBase64Key: (NSString *)input;

// property getter: ContentType
- (NSString *)ContentType;

// property setter: ContentType
- (void)setContentType: (NSString *)input;

// property getter: ContentUri
- (NSString *)ContentUri;

// property setter: ContentUri
- (void)setContentUri: (NSString *)input;

// property getter: DecryptedData
- (NSData *)DecryptedData;

// property getter: DecryptedData
- (NSMutableData *)DecryptedDataMutable;

// property getter: DrmContentVersion
- (NSNumber *)DrmContentVersion;

// property getter: EncryptedData
- (NSData *)EncryptedData;

// property getter: EncryptedData
- (NSMutableData *)EncryptedDataMutable;

// property getter: Headers
- (NSString *)Headers;

// property setter: Headers
- (void)setHeaders: (NSString *)input;

// property getter: IV
- (NSData *)IV;

// property setter: IV
- (void)setIV: (NSData *)data;

// property getter: IV
- (NSMutableData *)IVMutable;

// property setter: IV
- (void)setIVMutable: (NSMutableData *)data;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// method: CreateDcfFile
- (BOOL)CreateDcfFile: (NSString *)filename;

// method: GetHeaderField
- (BOOL)GetHeaderField: (NSString *)fieldName 
	fieldVal: (NSString *)fieldVal;

// method: LoadDcfData
- (BOOL)LoadDcfData: (NSData *)data;

// method: LoadDcfFile
- (BOOL)LoadDcfFile: (NSString *)filename;

// method: LoadUnencryptedData
- (void)LoadUnencryptedData: (NSData *)data;

// method: LoadUnencryptedFile
- (BOOL)LoadUnencryptedFile: (NSString *)filename;

// method: SaveDecrypted
- (BOOL)SaveDecrypted: (NSString *)filename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetEncodedIV
- (void)SetEncodedIV: (NSString *)encodedIv 
	encoding: (NSString *)encoding;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;


@end
