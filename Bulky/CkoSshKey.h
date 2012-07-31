// Chilkat Objective-C header.
// Generic/internal class name =  SshKey
// Wrapped Chilkat C++ class name =  CkSshKey



@interface CkoSshKey : NSObject {

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

// property getter: IsDsaKey
- (BOOL)IsDsaKey;

// property getter: IsPrivateKey
- (BOOL)IsPrivateKey;

// property getter: IsRsaKey
- (BOOL)IsRsaKey;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: Password
- (NSString *)Password;

// property setter: Password
- (void)setPassword: (NSString *)input;

// method: FromOpenSshPrivateKey
- (BOOL)FromOpenSshPrivateKey: (NSString *)keyStr;

// method: FromOpenSshPublicKey
- (BOOL)FromOpenSshPublicKey: (NSString *)keyStr;

// method: FromPuttyPrivateKey
- (BOOL)FromPuttyPrivateKey: (NSString *)keyStr;

// method: FromRfc4716PublicKey
- (BOOL)FromRfc4716PublicKey: (NSString *)keyStr;

// method: FromXml
- (BOOL)FromXml: (NSString *)xmlKey;

// method: GenFingerprint
- (NSString *)GenFingerprint;

// method: GenerateDsaKey
- (BOOL)GenerateDsaKey: (NSNumber *)numBits;

// method: GenerateRsaKey
- (BOOL)GenerateRsaKey: (NSNumber *)numBits 
	exponent: (NSNumber *)exponent;

// method: LoadText
- (NSString *)LoadText: (NSString *)filename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SaveText
- (BOOL)SaveText: (NSString *)strToSave 
	filename: (NSString *)filename;

// method: ToOpenSshPrivateKey
- (NSString *)ToOpenSshPrivateKey: (BOOL)bEncrypt;

// method: ToOpenSshPublicKey
- (NSString *)ToOpenSshPublicKey;

// method: ToPuttyPrivateKey
- (NSString *)ToPuttyPrivateKey: (BOOL)bEncrypt;

// method: ToRfc4716PublicKey
- (NSString *)ToRfc4716PublicKey;

// method: ToXml
- (NSString *)ToXml;


@end
