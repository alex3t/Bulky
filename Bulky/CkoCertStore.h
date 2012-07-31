// Chilkat Objective-C header.
// Generic/internal class name =  CertStore
// Wrapped Chilkat C++ class name =  CkCertStore

@class CkoCert;


@interface CkoCertStore : NSObject {

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

// property getter: NumCertificates
- (NSNumber *)NumCertificates;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// method: FindCertByRfc822Name
- (CkoCert *)FindCertByRfc822Name: (NSString *)name;

// method: FindCertBySerial
- (CkoCert *)FindCertBySerial: (NSString *)serialNumber;

// method: FindCertBySha1Thumbprint
- (CkoCert *)FindCertBySha1Thumbprint: (NSString *)str;

// method: FindCertBySubject
- (CkoCert *)FindCertBySubject: (NSString *)subject;

// method: FindCertBySubjectCN
- (CkoCert *)FindCertBySubjectCN: (NSString *)commonName;

// method: FindCertBySubjectE
- (CkoCert *)FindCertBySubjectE: (NSString *)emailAddress;

// method: FindCertBySubjectO
- (CkoCert *)FindCertBySubjectO: (NSString *)organization;

// method: GetCertificate
- (CkoCert *)GetCertificate: (NSNumber *)index;

// method: LoadPfxData
- (BOOL)LoadPfxData: (NSData *)pfxData 
	password: (NSString *)password;

// method: LoadPfxData2
- (BOOL)LoadPfxData2: (NSData *)buf 
	bufLen: (NSNumber *)bufLen 
	password: (NSString *)password;

// method: LoadPfxFile
- (BOOL)LoadPfxFile: (NSString *)filename 
	password: (NSString *)password;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;


@end
