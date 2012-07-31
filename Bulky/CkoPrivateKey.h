// Chilkat Objective-C header.
// Generic/internal class name =  PrivateKey
// Wrapped Chilkat C++ class name =  CkPrivateKey



@interface CkoPrivateKey : NSObject {

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

// method: GetPkcs8
- (NSData *)GetPkcs8;

// method: GetPkcs8Encrypted
- (NSData *)GetPkcs8Encrypted: (NSString *)password;

// method: GetPkcs8EncryptedPem
- (NSString *)GetPkcs8EncryptedPem: (NSString *)password;

// method: GetPkcs8Pem
- (NSString *)GetPkcs8Pem;

// method: GetRsaDer
- (NSData *)GetRsaDer;

// method: GetRsaPem
- (NSString *)GetRsaPem;

// method: GetXml
- (NSString *)GetXml;

// method: LoadEncryptedPem
- (BOOL)LoadEncryptedPem: (NSString *)pemStr 
	password: (NSString *)password;

// method: LoadEncryptedPemFile
- (BOOL)LoadEncryptedPemFile: (NSString *)filename 
	password: (NSString *)password;

// method: LoadPem
- (BOOL)LoadPem: (NSString *)str;

// method: LoadPemFile
- (BOOL)LoadPemFile: (NSString *)filename;

// method: LoadPkcs8
- (BOOL)LoadPkcs8: (NSData *)data;

// method: LoadPkcs8Encrypted
- (BOOL)LoadPkcs8Encrypted: (NSData *)data 
	password: (NSString *)password;

// method: LoadPkcs8EncryptedFile
- (BOOL)LoadPkcs8EncryptedFile: (NSString *)filename 
	password: (NSString *)password;

// method: LoadPkcs8File
- (BOOL)LoadPkcs8File: (NSString *)filename;

// method: LoadRsaDer
- (BOOL)LoadRsaDer: (NSData *)data;

// method: LoadRsaDerFile
- (BOOL)LoadRsaDerFile: (NSString *)filename;

// method: LoadXml
- (BOOL)LoadXml: (NSString *)xml;

// method: LoadXmlFile
- (BOOL)LoadXmlFile: (NSString *)filename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SavePkcs8EncryptedFile
- (BOOL)SavePkcs8EncryptedFile: (NSString *)password 
	filename: (NSString *)filename;

// method: SavePkcs8EncryptedPemFile
- (BOOL)SavePkcs8EncryptedPemFile: (NSString *)password 
	filename: (NSString *)filename;

// method: SavePkcs8File
- (BOOL)SavePkcs8File: (NSString *)filename;

// method: SavePkcs8PemFile
- (BOOL)SavePkcs8PemFile: (NSString *)filename;

// method: SaveRsaDerFile
- (BOOL)SaveRsaDerFile: (NSString *)filename;

// method: SaveRsaPemFile
- (BOOL)SaveRsaPemFile: (NSString *)filename;

// method: SaveXmlFile
- (BOOL)SaveXmlFile: (NSString *)filename;


@end
