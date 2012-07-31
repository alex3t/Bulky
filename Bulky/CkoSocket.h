// Chilkat Objective-C header.
// Generic/internal class name =  Socket
// Wrapped Chilkat C++ class name =  CkSocket

@class CkoCert;


@interface CkoSocket : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: BigEndian
- (BOOL)BigEndian;

// property setter: BigEndian
- (void)setBigEndian: (BOOL)boolVal;

// property getter: ClientIpAddress
- (NSString *)ClientIpAddress;

// property setter: ClientIpAddress
- (void)setClientIpAddress: (NSString *)input;

// property getter: ClientPort
- (NSNumber *)ClientPort;

// property setter: ClientPort
- (void)setClientPort: (NSNumber *)intVal;

// property getter: ConnectFailReason
- (NSNumber *)ConnectFailReason;

// property getter: DebugConnectDelayMs
- (NSNumber *)DebugConnectDelayMs;

// property setter: DebugConnectDelayMs
- (void)setDebugConnectDelayMs: (NSNumber *)longVal;

// property getter: DebugDnsDelayMs
- (NSNumber *)DebugDnsDelayMs;

// property setter: DebugDnsDelayMs
- (void)setDebugDnsDelayMs: (NSNumber *)longVal;

// property getter: DebugLogFilePath
- (NSString *)DebugLogFilePath;

// property setter: DebugLogFilePath
- (void)setDebugLogFilePath: (NSString *)input;

// property getter: ElapsedSeconds
- (NSNumber *)ElapsedSeconds;

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

// property getter: IsConnected
- (BOOL)IsConnected;

// property getter: KeepSessionLog
- (BOOL)KeepSessionLog;

// property setter: KeepSessionLog
- (void)setKeepSessionLog: (BOOL)boolVal;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: LastMethodFailed
- (BOOL)LastMethodFailed;

// property getter: LocalIpAddress
- (NSString *)LocalIpAddress;

// property getter: LocalPort
- (NSNumber *)LocalPort;

// property getter: MaxReadIdleMs
- (NSNumber *)MaxReadIdleMs;

// property setter: MaxReadIdleMs
- (void)setMaxReadIdleMs: (NSNumber *)longVal;

// property getter: MaxSendIdleMs
- (NSNumber *)MaxSendIdleMs;

// property setter: MaxSendIdleMs
- (void)setMaxSendIdleMs: (NSNumber *)longVal;

// property getter: MyIpAddress
- (NSString *)MyIpAddress;

// property getter: NumSocketsInSet
- (NSNumber *)NumSocketsInSet;

// property getter: NumSslAcceptableClientCAs
- (NSNumber *)NumSslAcceptableClientCAs;

// property getter: ObjectId
- (NSNumber *)ObjectId;

// property getter: ReceivePacketSize
- (NSNumber *)ReceivePacketSize;

// property setter: ReceivePacketSize
- (void)setReceivePacketSize: (NSNumber *)longVal;

// property getter: ReceivedCount
- (NSNumber *)ReceivedCount;

// property setter: ReceivedCount
- (void)setReceivedCount: (NSNumber *)intVal;

// property getter: RemoteIpAddress
- (NSString *)RemoteIpAddress;

// property getter: RemotePort
- (NSNumber *)RemotePort;

// property getter: SelectorIndex
- (NSNumber *)SelectorIndex;

// property setter: SelectorIndex
- (void)setSelectorIndex: (NSNumber *)intVal;

// property getter: SelectorReadIndex
- (NSNumber *)SelectorReadIndex;

// property setter: SelectorReadIndex
- (void)setSelectorReadIndex: (NSNumber *)intVal;

// property getter: SelectorWriteIndex
- (NSNumber *)SelectorWriteIndex;

// property setter: SelectorWriteIndex
- (void)setSelectorWriteIndex: (NSNumber *)intVal;

// property getter: SendPacketSize
- (NSNumber *)SendPacketSize;

// property setter: SendPacketSize
- (void)setSendPacketSize: (NSNumber *)longVal;

// property getter: SessionLog
- (NSString *)SessionLog;

// property getter: SessionLogEncoding
- (NSString *)SessionLogEncoding;

// property setter: SessionLogEncoding
- (void)setSessionLogEncoding: (NSString *)input;

// property getter: SoRcvBuf
- (NSNumber *)SoRcvBuf;

// property setter: SoRcvBuf
- (void)setSoRcvBuf: (NSNumber *)intVal;

// property getter: SoSndBuf
- (NSNumber *)SoSndBuf;

// property setter: SoSndBuf
- (void)setSoSndBuf: (NSNumber *)intVal;

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

// property getter: StringCharset
- (NSString *)StringCharset;

// property setter: StringCharset
- (void)setStringCharset: (NSString *)input;

// property getter: TcpNoDelay
- (BOOL)TcpNoDelay;

// property setter: TcpNoDelay
- (void)setTcpNoDelay: (BOOL)boolVal;

// property getter: UserData
- (NSString *)UserData;

// property setter: UserData
- (void)setUserData: (NSString *)input;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// method: AcceptNextConnection
- (CkoSocket *)AcceptNextConnection: (NSNumber *)maxWaitMs;

// method: AddSslAcceptableClientCaDn
- (BOOL)AddSslAcceptableClientCaDn: (NSString *)certAuthDN;

// method: BindAndListen
- (BOOL)BindAndListen: (NSNumber *)port 
	backlog: (NSNumber *)backlog;

// method: BuildHttpGetRequest
- (NSString *)BuildHttpGetRequest: (NSString *)url;

// method: CheckWriteable
- (NSNumber *)CheckWriteable: (NSNumber *)maxWaitMs;

// method: ClearSessionLog
- (void)ClearSessionLog;

// method: Close
- (void)Close: (NSNumber *)maxWaitMs;

// method: Connect
- (BOOL)Connect: (NSString *)hostname 
	port: (NSNumber *)port 
	ssl: (BOOL)ssl 
	maxWaitMs: (NSNumber *)maxWaitMs;

// method: ConvertFromSsl
- (BOOL)ConvertFromSsl;

// method: ConvertToSsl
- (BOOL)ConvertToSsl;

// method: DnsLookup
- (NSString *)DnsLookup: (NSString *)hostname 
	maxWaitMs: (NSNumber *)maxWaitMs;

// method: GetMyCert
- (CkoCert *)GetMyCert;

// method: GetSslAcceptableClientCaDn
- (NSString *)GetSslAcceptableClientCaDn: (NSNumber *)index;

// method: GetSslServerCert
- (CkoCert *)GetSslServerCert;

// method: InitSslServer
- (BOOL)InitSslServer: (CkoCert *)cert;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: PollDataAvailable
- (BOOL)PollDataAvailable;

// method: ReceiveBytes
- (NSData *)ReceiveBytes;

// method: ReceiveBytesN
- (NSData *)ReceiveBytesN: (NSNumber *)numBytes;

// method: ReceiveBytesToFile
- (BOOL)ReceiveBytesToFile: (NSString *)appendFilename;

// method: ReceiveCount
- (NSNumber *)ReceiveCount;

// method: ReceiveString
- (NSString *)ReceiveString;

// method: ReceiveStringMaxN
- (NSString *)ReceiveStringMaxN: (NSNumber *)maxBytes;

// method: ReceiveStringUntilByte
- (NSString *)ReceiveStringUntilByte: (NSNumber *)byteValue;

// method: ReceiveToCRLF
- (NSString *)ReceiveToCRLF;

// method: ReceiveUntilByte
- (NSData *)ReceiveUntilByte: (NSNumber *)byteValue;

// method: ReceiveUntilMatch
- (NSString *)ReceiveUntilMatch: (NSString *)matchStr;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SelectForReading
- (NSNumber *)SelectForReading: (NSNumber *)timeoutMs;

// method: SelectForWriting
- (NSNumber *)SelectForWriting: (NSNumber *)timeoutMs;

// method: SendByteData
- (BOOL)SendByteData: (NSData *)data;

// method: SendBytes
- (BOOL)SendBytes: (NSData *)byteData 
	numBytes: (NSNumber *)numBytes;

// method: SendCount
- (BOOL)SendCount: (NSNumber *)byteCount;

// method: SendString
- (BOOL)SendString: (NSString *)str;

// method: SetSslClientCert
- (BOOL)SetSslClientCert: (CkoCert *)cert;

// method: SetSslClientCertPem
- (BOOL)SetSslClientCertPem: (NSString *)pemDataOrFilename 
	pemPassword: (NSString *)pemPassword;

// method: SetSslClientCertPfx
- (BOOL)SetSslClientCertPfx: (NSString *)pfxFilename 
	pfxPassword: (NSString *)pfxPassword 
	certSubjectCN: (NSString *)certSubjectCN;

// method: SleepMs
- (void)SleepMs: (NSNumber *)millisec;

// method: StartTiming
- (void)StartTiming;

// method: TakeSocket
- (BOOL)TakeSocket: (CkoSocket *)sock;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)code;


@end
