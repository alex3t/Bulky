// Chilkat Objective-C header.
// Generic/internal class name =  Cert
// Wrapped Chilkat C++ class name =  CkCert

@class CkoPrivateKey;
@class CkoPublicKey;


@interface CkoCert : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: CertVersion
- (NSNumber *)CertVersion;

// property getter: Expired
- (BOOL)Expired;

// property getter: ForClientAuthentication
- (BOOL)ForClientAuthentication;

// property getter: ForCodeSigning
- (BOOL)ForCodeSigning;

// property getter: ForSecureEmail
- (BOOL)ForSecureEmail;

// property getter: ForServerAuthentication
- (BOOL)ForServerAuthentication;

// property getter: ForTimeStamping
- (BOOL)ForTimeStamping;

// property getter: IntendedKeyUsage
- (NSNumber *)IntendedKeyUsage;

// property getter: IsRoot
- (BOOL)IsRoot;

// property getter: IssuerC
- (NSString *)IssuerC;

// property getter: IssuerCN
- (NSString *)IssuerCN;

// property getter: IssuerDN
- (NSString *)IssuerDN;

// property getter: IssuerE
- (NSString *)IssuerE;

// property getter: IssuerL
- (NSString *)IssuerL;

// property getter: IssuerO
- (NSString *)IssuerO;

// property getter: IssuerOU
- (NSString *)IssuerOU;

// property getter: IssuerS
- (NSString *)IssuerS;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: OcspUrl
- (NSString *)OcspUrl;

// property getter: Revoked
- (BOOL)Revoked;

// property getter: Rfc822Name
- (NSString *)Rfc822Name;

// property getter: SelfSigned
- (BOOL)SelfSigned;

// property getter: SerialNumber
- (NSString *)SerialNumber;

// property getter: Sha1Thumbprint
- (NSString *)Sha1Thumbprint;

// property getter: SignatureVerified
- (BOOL)SignatureVerified;

// property getter: SubjectC
- (NSString *)SubjectC;

// property getter: SubjectCN
- (NSString *)SubjectCN;

// property getter: SubjectDN
- (NSString *)SubjectDN;

// property getter: SubjectE
- (NSString *)SubjectE;

// property getter: SubjectL
- (NSString *)SubjectL;

// property getter: SubjectO
- (NSString *)SubjectO;

// property getter: SubjectOU
- (NSString *)SubjectOU;

// property getter: SubjectS
- (NSString *)SubjectS;

// property getter: TrustedRoot
- (BOOL)TrustedRoot;

// property getter: ValidFrom
- (NSDate *)ValidFrom;

// property getter: ValidTo
- (NSDate *)ValidTo;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// method: CheckRevoked
- (NSNumber *)CheckRevoked;

// method: ExportCertDer
- (NSData *)ExportCertDer;

// method: ExportCertDerFile
- (BOOL)ExportCertDerFile: (NSString *)filename;

// method: ExportCertPem
- (NSString *)ExportCertPem;

// method: ExportCertPemFile
- (BOOL)ExportCertPemFile: (NSString *)filename;

// method: ExportCertXml
- (NSString *)ExportCertXml;

// method: ExportPrivateKey
- (CkoPrivateKey *)ExportPrivateKey;

// method: ExportPublicKey
- (CkoPublicKey *)ExportPublicKey;

// method: FindIssuer
- (CkoCert *)FindIssuer;

// method: GetEncoded
- (NSString *)GetEncoded;

// method: GetPrivateKeyPem
- (NSString *)GetPrivateKeyPem;

// method: HasPrivateKey
- (BOOL)HasPrivateKey;

// method: LoadFromBase64
- (BOOL)LoadFromBase64: (NSString *)encodedCert;

// method: LoadFromBinary
- (BOOL)LoadFromBinary: (NSData *)buf 
	bufLen: (NSNumber *)bufLen;

// method: LoadFromFile
- (BOOL)LoadFromFile: (NSString *)filename;

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

// method: PemFileToDerFile
- (BOOL)PemFileToDerFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SaveToFile
- (BOOL)SaveToFile: (NSString *)filename;

// method: SetFromEncoded
- (BOOL)SetFromEncoded: (NSString *)encodedCert;

// method: SetPrivateKey
- (BOOL)SetPrivateKey: (CkoPrivateKey *)privKey;

// method: SetPrivateKeyPem
- (BOOL)SetPrivateKeyPem: (NSString *)privKeyPem;


@end
