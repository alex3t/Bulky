// Chilkat Objective-C header.
// Generic/internal class name =  Imap
// Wrapped Chilkat C++ class name =  CkImap

@class CkoEmail;
@class CkoMessageSet;
@class CkoEmailBundle;
@class CkoStringArray;
@class CkoCert;
@class CkoMailboxes;
@class CkoPrivateKey;
@class CkoSshKey;


@interface CkoImap : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: AppendSeen
- (BOOL)AppendSeen;

// property setter: AppendSeen
- (void)setAppendSeen: (BOOL)boolVal;

// property getter: AppendUid
- (NSNumber *)AppendUid;

// property getter: AuthMethod
- (NSString *)AuthMethod;

// property setter: AuthMethod
- (void)setAuthMethod: (NSString *)input;

// property getter: AuthzId
- (NSString *)AuthzId;

// property setter: AuthzId
- (void)setAuthzId: (NSString *)input;

// property getter: AutoFix
- (BOOL)AutoFix;

// property setter: AutoFix
- (void)setAutoFix: (BOOL)boolVal;

// property getter: ClientIpAddress
- (NSString *)ClientIpAddress;

// property setter: ClientIpAddress
- (void)setClientIpAddress: (NSString *)input;

// property getter: ConnectTimeout
- (NSNumber *)ConnectTimeout;

// property setter: ConnectTimeout
- (void)setConnectTimeout: (NSNumber *)intVal;

// property getter: ConnectedToHost
- (NSString *)ConnectedToHost;

// property getter: DebugLogFilePath
- (NSString *)DebugLogFilePath;

// property setter: DebugLogFilePath
- (void)setDebugLogFilePath: (NSString *)input;

// property getter: Domain
- (NSString *)Domain;

// property setter: Domain
- (void)setDomain: (NSString *)input;

// property getter: HeartbeatMs
- (NSNumber *)HeartbeatMs;

// property setter: HeartbeatMs
- (void)setHeartbeatMs: (NSNumber *)longVal;

// property getter: HttpProxyAuthMethod
- (NSString *)HttpProxyAuthMethod;

// property setter: HttpProxyAuthMethod
- (void)setHttpProxyAuthMethod: (NSString *)input;

// property getter: HttpProxyHostname
- (NSString *)HttpProxyHostname;

// property setter: HttpProxyHostname
- (void)setHttpProxyHostname: (NSString *)input;

// property getter: HttpProxyPassword
- (NSString *)HttpProxyPassword;

// property setter: HttpProxyPassword
- (void)setHttpProxyPassword: (NSString *)input;

// property getter: HttpProxyPort
- (NSNumber *)HttpProxyPort;

// property setter: HttpProxyPort
- (void)setHttpProxyPort: (NSNumber *)intVal;

// property getter: HttpProxyUsername
- (NSString *)HttpProxyUsername;

// property setter: HttpProxyUsername
- (void)setHttpProxyUsername: (NSString *)input;

// property getter: KeepSessionLog
- (BOOL)KeepSessionLog;

// property setter: KeepSessionLog
- (void)setKeepSessionLog: (BOOL)boolVal;

// property getter: LastAppendedMime
- (NSString *)LastAppendedMime;

// property getter: LastCommand
- (NSString *)LastCommand;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: LastIntermediateResponse
- (NSString *)LastIntermediateResponse;

// property getter: LastResponse
- (NSString *)LastResponse;

// property getter: LoggedInUser
- (NSString *)LoggedInUser;

// property getter: NumMessages
- (NSNumber *)NumMessages;

// property getter: PeekMode
- (BOOL)PeekMode;

// property setter: PeekMode
- (void)setPeekMode: (BOOL)boolVal;

// property getter: Port
- (NSNumber *)Port;

// property setter: Port
- (void)setPort: (NSNumber *)intVal;

// property getter: ReadTimeout
- (NSNumber *)ReadTimeout;

// property setter: ReadTimeout
- (void)setReadTimeout: (NSNumber *)intVal;

// property getter: SelectedMailbox
- (NSString *)SelectedMailbox;

// property getter: SendBufferSize
- (NSNumber *)SendBufferSize;

// property setter: SendBufferSize
- (void)setSendBufferSize: (NSNumber *)intVal;

// property getter: SeparatorChar
- (char)SeparatorChar;

// property setter: SeparatorChar
- (void)setSeparatorChar: (char)ch;

// property getter: SessionLog
- (NSString *)SessionLog;

// property getter: SocksHostname
- (NSString *)SocksHostname;

// property setter: SocksHostname
- (void)setSocksHostname: (NSString *)input;

// property getter: SocksPassword
- (NSString *)SocksPassword;

// property setter: SocksPassword
- (void)setSocksPassword: (NSString *)input;

// property getter: SocksPort
- (NSNumber *)SocksPort;

// property setter: SocksPort
- (void)setSocksPort: (NSNumber *)intVal;

// property getter: SocksUsername
- (NSString *)SocksUsername;

// property setter: SocksUsername
- (void)setSocksUsername: (NSString *)input;

// property getter: SocksVersion
- (NSNumber *)SocksVersion;

// property setter: SocksVersion
- (void)setSocksVersion: (NSNumber *)intVal;

// property getter: Ssl
- (BOOL)Ssl;

// property setter: Ssl
- (void)setSsl: (BOOL)boolVal;

// property getter: SslProtocol
- (NSString *)SslProtocol;

// property setter: SslProtocol
- (void)setSslProtocol: (NSString *)input;

// property getter: SslServerCertVerified
- (BOOL)SslServerCertVerified;

// property getter: StartTls
- (BOOL)StartTls;

// property setter: StartTls
- (void)setStartTls: (BOOL)boolVal;

// property getter: UidNext
- (NSNumber *)UidNext;

// property getter: UidValidity
- (NSNumber *)UidValidity;

// property getter: Version
- (NSString *)Version;

// method: AddPfxSourceData
- (BOOL)AddPfxSourceData: (NSData *)pfxData 
	password: (NSString *)password;

// method: AddPfxSourceFile
- (BOOL)AddPfxSourceFile: (NSString *)pfxFilePath 
	password: (NSString *)password;

// method: AppendMail
- (BOOL)AppendMail: (NSString *)mailbox 
	email: (CkoEmail *)email;

// method: AppendMime
- (BOOL)AppendMime: (NSString *)mailbox 
	mimeText: (NSString *)mimeText;

// method: AppendMimeWithDate
- (BOOL)AppendMimeWithDate: (NSString *)mailbox 
	mimeText: (NSString *)mimeText 
	internalDate: (NSDate *)internalDate;

// method: AppendMimeWithFlags
- (BOOL)AppendMimeWithFlags: (NSString *)mailbox 
	mimeText: (NSString *)mimeText 
	seen: (BOOL)seen 
	flagged: (BOOL)flagged 
	answered: (BOOL)answered 
	draft: (BOOL)draft;

// method: ClearSessionLog
- (void)ClearSessionLog;

// method: Connect
- (BOOL)Connect: (NSString *)hostname;

// method: Copy
- (BOOL)Copy: (NSNumber *)msgId 
	bUid: (BOOL)bUid 
	copyToMailbox: (NSString *)copyToMailbox;

// method: CopyMultiple
- (BOOL)CopyMultiple: (CkoMessageSet *)messageSet 
	copyToMailbox: (NSString *)copyToMailbox;

// method: CopySequence
- (BOOL)CopySequence: (NSNumber *)startSeqNum 
	count: (NSNumber *)count 
	copyToMailbox: (NSString *)copyToMailbox;

// method: CreateMailbox
- (BOOL)CreateMailbox: (NSString *)mailbox;

// method: DeleteMailbox
- (BOOL)DeleteMailbox: (NSString *)mailbox;

// method: Disconnect
- (BOOL)Disconnect;

// method: ExamineMailbox
- (BOOL)ExamineMailbox: (NSString *)mailbox;

// method: Expunge
- (BOOL)Expunge;

// method: ExpungeAndClose
- (BOOL)ExpungeAndClose;

// method: FetchBundle
- (CkoEmailBundle *)FetchBundle: (CkoMessageSet *)messageSet;

// method: FetchBundleAsMime
- (CkoStringArray *)FetchBundleAsMime: (CkoMessageSet *)messageSet;

// method: FetchChunk
- (CkoEmailBundle *)FetchChunk: (NSNumber *)startSeqNum 
	count: (NSNumber *)count 
	failedSet: (CkoMessageSet *)failedSet 
	fetchedSet: (CkoMessageSet *)fetchedSet;

// method: FetchFlags
- (NSString *)FetchFlags: (NSNumber *)msgId 
	bUid: (BOOL)bUid;

// method: FetchHeaders
- (CkoEmailBundle *)FetchHeaders: (CkoMessageSet *)messageSet;

// method: FetchSequence
- (CkoEmailBundle *)FetchSequence: (NSNumber *)startSeqNum 
	numMessages: (NSNumber *)numMessages;

// method: FetchSequenceAsMime
- (CkoStringArray *)FetchSequenceAsMime: (NSNumber *)startSeqNum 
	count: (NSNumber *)count;

// method: FetchSequenceHeaders
- (CkoEmailBundle *)FetchSequenceHeaders: (NSNumber *)startSeqNum 
	numMessages: (NSNumber *)numMessages;

// method: FetchSingle
- (CkoEmail *)FetchSingle: (NSNumber *)msgId 
	bUid: (BOOL)bUid;

// method: FetchSingleAsMime
- (NSString *)FetchSingleAsMime: (NSNumber *)msgId 
	bUid: (BOOL)bUid;

// method: FetchSingleHeader
- (CkoEmail *)FetchSingleHeader: (NSNumber *)msgId 
	bUid: (BOOL)bUid;

// method: FetchSingleHeaderAsMime
- (NSString *)FetchSingleHeaderAsMime: (NSNumber *)msgId 
	bUID: (BOOL)bUID;

// method: GetAllUids
- (CkoMessageSet *)GetAllUids;

// method: GetMailAttachFilename
- (NSString *)GetMailAttachFilename: (CkoEmail *)email 
	attachIndex: (NSNumber *)attachIndex;

// method: GetMailAttachSize
- (NSNumber *)GetMailAttachSize: (CkoEmail *)email 
	attachIndex: (NSNumber *)attachIndex;

// method: GetMailFlag
- (NSNumber *)GetMailFlag: (CkoEmail *)email 
	flagName: (NSString *)flagName;

// method: GetMailNumAttach
- (NSNumber *)GetMailNumAttach: (CkoEmail *)email;

// method: GetMailSize
- (NSNumber *)GetMailSize: (CkoEmail *)email;

// method: GetSslServerCert
- (CkoCert *)GetSslServerCert;

// method: IsConnected
- (BOOL)IsConnected;

// method: IsLoggedIn
- (BOOL)IsLoggedIn;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: ListMailboxes
- (CkoMailboxes *)ListMailboxes: (NSString *)reference 
	wildcardedMailbox: (NSString *)wildcardedMailbox;

// method: Login
- (BOOL)Login: (NSString *)login 
	password: (NSString *)password;

// method: Logout
- (BOOL)Logout;

// method: Noop
- (BOOL)Noop;

// method: RefetchMailFlags
- (BOOL)RefetchMailFlags: (CkoEmail *)emailInOut;

// method: RenameMailbox
- (BOOL)RenameMailbox: (NSString *)fromMailbox 
	toMailbox: (NSString *)toMailbox;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: Search
- (CkoMessageSet *)Search: (NSString *)criteria 
	bUid: (BOOL)bUid;

// method: SelectMailbox
- (BOOL)SelectMailbox: (NSString *)mailbox;

// method: SendRawCommand
- (NSString *)SendRawCommand: (NSString *)rawCommand;

// method: SetDecryptCert2
- (BOOL)SetDecryptCert2: (CkoCert *)cert 
	key: (CkoPrivateKey *)key;

// method: SetFlag
- (BOOL)SetFlag: (NSNumber *)msgId 
	bUid: (BOOL)bUid 
	flagName: (NSString *)flagName 
	value: (NSNumber *)value;

// method: SetFlags
- (BOOL)SetFlags: (CkoMessageSet *)messageSet 
	flagName: (NSString *)flagName 
	value: (NSNumber *)value;

// method: SetMailFlag
- (BOOL)SetMailFlag: (CkoEmail *)email 
	flagName: (NSString *)flagName 
	value: (NSNumber *)value;

// method: SetSslClientCert
- (BOOL)SetSslClientCert: (CkoCert *)cert;

// method: SetSslClientCertPem
- (BOOL)SetSslClientCertPem: (NSString *)pemDataOrFilename 
	pemPassword: (NSString *)pemPassword;

// method: SetSslClientCertPfx
- (BOOL)SetSslClientCertPfx: (NSString *)pfxFilename 
	pfxPassword: (NSString *)pfxPassword 
	certSubjectCN: (NSString *)certSubjectCN;

// method: SshAuthenticatePk
- (BOOL)SshAuthenticatePk: (NSString *)sshLogin 
	privateKey: (CkoSshKey *)privateKey;

// method: SshAuthenticatePw
- (BOOL)SshAuthenticatePw: (NSString *)sshLogin 
	sshPassword: (NSString *)sshPassword;

// method: SshTunnel
- (BOOL)SshTunnel: (NSString *)sshServerHostname 
	sshServerPort: (NSNumber *)sshServerPort;

// method: StoreFlags
- (BOOL)StoreFlags: (NSNumber *)msgId 
	bUid: (BOOL)bUid 
	flagName: (NSString *)flagName 
	value: (NSNumber *)value;

// method: Subscribe
- (BOOL)Subscribe: (NSString *)mailbox;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: Unsubscribe
- (BOOL)Unsubscribe: (NSString *)mailbox;


@end
