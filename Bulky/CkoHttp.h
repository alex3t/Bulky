// Chilkat Objective-C header.
// Generic/internal class name =  Http
// Wrapped Chilkat C++ class name =  CkHttp

@class CkoHttpResponse;
@class CkoCert;
@class CkoHttpRequest;


@interface CkoHttp : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: Accept
- (NSString *)Accept;

// property setter: Accept
- (void)setAccept: (NSString *)input;

// property getter: AcceptCharset
- (NSString *)AcceptCharset;

// property setter: AcceptCharset
- (void)setAcceptCharset: (NSString *)input;

// property getter: AcceptLanguage
- (NSString *)AcceptLanguage;

// property setter: AcceptLanguage
- (void)setAcceptLanguage: (NSString *)input;

// property getter: AllowGzip
- (BOOL)AllowGzip;

// property setter: AllowGzip
- (void)setAllowGzip: (BOOL)boolVal;

// property getter: AutoAddHostHeader
- (BOOL)AutoAddHostHeader;

// property setter: AutoAddHostHeader
- (void)setAutoAddHostHeader: (BOOL)boolVal;

// property getter: AwsAccessKey
- (NSString *)AwsAccessKey;

// property setter: AwsAccessKey
- (void)setAwsAccessKey: (NSString *)input;

// property getter: AwsSecretKey
- (NSString *)AwsSecretKey;

// property setter: AwsSecretKey
- (void)setAwsSecretKey: (NSString *)input;

// property getter: ClientIpAddress
- (NSString *)ClientIpAddress;

// property setter: ClientIpAddress
- (void)setClientIpAddress: (NSString *)input;

// property getter: ConnectTimeout
- (NSNumber *)ConnectTimeout;

// property setter: ConnectTimeout
- (void)setConnectTimeout: (NSNumber *)longVal;

// property getter: Connection
- (NSString *)Connection;

// property setter: Connection
- (void)setConnection: (NSString *)input;

// property getter: CookieDir
- (NSString *)CookieDir;

// property setter: CookieDir
- (void)setCookieDir: (NSString *)input;

// property getter: DebugLogFilePath
- (NSString *)DebugLogFilePath;

// property setter: DebugLogFilePath
- (void)setDebugLogFilePath: (NSString *)input;

// property getter: DefaultFreshPeriod
- (NSNumber *)DefaultFreshPeriod;

// property setter: DefaultFreshPeriod
- (void)setDefaultFreshPeriod: (NSNumber *)longVal;

// property getter: DigestAuth
- (BOOL)DigestAuth;

// property setter: DigestAuth
- (void)setDigestAuth: (BOOL)boolVal;

// property getter: EventLogCount
- (NSNumber *)EventLogCount;

// property getter: FetchFromCache
- (BOOL)FetchFromCache;

// property setter: FetchFromCache
- (void)setFetchFromCache: (BOOL)boolVal;

// property getter: FinalRedirectUrl
- (NSString *)FinalRedirectUrl;

// property getter: FollowRedirects
- (BOOL)FollowRedirects;

// property setter: FollowRedirects
- (void)setFollowRedirects: (BOOL)boolVal;

// property getter: FreshnessAlgorithm
- (NSNumber *)FreshnessAlgorithm;

// property setter: FreshnessAlgorithm
- (void)setFreshnessAlgorithm: (NSNumber *)longVal;

// property getter: HeartbeatMs
- (NSNumber *)HeartbeatMs;

// property setter: HeartbeatMs
- (void)setHeartbeatMs: (NSNumber *)longVal;

// property getter: IgnoreMustRevalidate
- (BOOL)IgnoreMustRevalidate;

// property setter: IgnoreMustRevalidate
- (void)setIgnoreMustRevalidate: (BOOL)boolVal;

// property getter: IgnoreNoCache
- (BOOL)IgnoreNoCache;

// property setter: IgnoreNoCache
- (void)setIgnoreNoCache: (BOOL)boolVal;

// property getter: KeepEventLog
- (BOOL)KeepEventLog;

// property setter: KeepEventLog
- (void)setKeepEventLog: (BOOL)boolVal;

// property getter: LMFactor
- (NSNumber *)LMFactor;

// property setter: LMFactor
- (void)setLMFactor: (NSNumber *)longVal;

// property getter: LastContentType
- (NSString *)LastContentType;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: LastHeader
- (NSString *)LastHeader;

// property getter: LastModDate
- (NSString *)LastModDate;

// property getter: LastResponseHeader
- (NSString *)LastResponseHeader;

// property getter: LastStatus
- (NSNumber *)LastStatus;

// property getter: Login
- (NSString *)Login;

// property setter: Login
- (void)setLogin: (NSString *)input;

// property getter: LoginDomain
- (NSString *)LoginDomain;

// property setter: LoginDomain
- (void)setLoginDomain: (NSString *)input;

// property getter: MaxConnections
- (NSNumber *)MaxConnections;

// property setter: MaxConnections
- (void)setMaxConnections: (NSNumber *)longVal;

// property getter: MaxFreshPeriod
- (NSNumber *)MaxFreshPeriod;

// property setter: MaxFreshPeriod
- (void)setMaxFreshPeriod: (NSNumber *)longVal;

// property getter: MaxResponseSize
- (NSNumber *)MaxResponseSize;

// property setter: MaxResponseSize
- (void)setMaxResponseSize: (NSNumber *)ulongVal;

// property getter: MaxUrlLen
- (NSNumber *)MaxUrlLen;

// property setter: MaxUrlLen
- (void)setMaxUrlLen: (NSNumber *)longVal;

// property getter: MimicFireFox
- (BOOL)MimicFireFox;

// property setter: MimicFireFox
- (void)setMimicFireFox: (BOOL)boolVal;

// property getter: MimicIE
- (BOOL)MimicIE;

// property setter: MimicIE
- (void)setMimicIE: (BOOL)boolVal;

// property getter: MinFreshPeriod
- (NSNumber *)MinFreshPeriod;

// property setter: MinFreshPeriod
- (void)setMinFreshPeriod: (NSNumber *)longVal;

// property getter: NegotiateAuth
- (BOOL)NegotiateAuth;

// property setter: NegotiateAuth
- (void)setNegotiateAuth: (BOOL)boolVal;

// property getter: NtlmAuth
- (BOOL)NtlmAuth;

// property setter: NtlmAuth
- (void)setNtlmAuth: (BOOL)boolVal;

// property getter: NumCacheLevels
- (NSNumber *)NumCacheLevels;

// property setter: NumCacheLevels
- (void)setNumCacheLevels: (NSNumber *)longVal;

// property getter: NumCacheRoots
- (NSNumber *)NumCacheRoots;

// property getter: Password
- (NSString *)Password;

// property setter: Password
- (void)setPassword: (NSString *)input;

// property getter: ProxyAuthMethod
- (NSString *)ProxyAuthMethod;

// property setter: ProxyAuthMethod
- (void)setProxyAuthMethod: (NSString *)input;

// property getter: ProxyDomain
- (NSString *)ProxyDomain;

// property setter: ProxyDomain
- (void)setProxyDomain: (NSString *)input;

// property getter: ProxyLogin
- (NSString *)ProxyLogin;

// property setter: ProxyLogin
- (void)setProxyLogin: (NSString *)input;

// property getter: ProxyPartialUrl
- (BOOL)ProxyPartialUrl;

// property setter: ProxyPartialUrl
- (void)setProxyPartialUrl: (BOOL)boolVal;

// property getter: ProxyPassword
- (NSString *)ProxyPassword;

// property setter: ProxyPassword
- (void)setProxyPassword: (NSString *)input;

// property getter: ProxyPort
- (NSNumber *)ProxyPort;

// property setter: ProxyPort
- (void)setProxyPort: (NSNumber *)longVal;

// property getter: ReadTimeout
- (NSNumber *)ReadTimeout;

// property setter: ReadTimeout
- (void)setReadTimeout: (NSNumber *)longVal;

// property getter: RedirectVerb
- (NSString *)RedirectVerb;

// property setter: RedirectVerb
- (void)setRedirectVerb: (NSString *)input;

// property getter: Referer
- (NSString *)Referer;

// property setter: Referer
- (void)setReferer: (NSString *)input;

// property getter: RequiredContentType
- (NSString *)RequiredContentType;

// property setter: RequiredContentType
- (void)setRequiredContentType: (NSString *)input;

// property getter: SaveCookies
- (BOOL)SaveCookies;

// property setter: SaveCookies
- (void)setSaveCookies: (BOOL)boolVal;

// property getter: SendBufferSize
- (NSNumber *)SendBufferSize;

// property setter: SendBufferSize
- (void)setSendBufferSize: (NSNumber *)intVal;

// property getter: SendCookies
- (BOOL)SendCookies;

// property setter: SendCookies
- (void)setSendCookies: (BOOL)boolVal;

// property getter: SessionLogFilename
- (NSString *)SessionLogFilename;

// property setter: SessionLogFilename
- (void)setSessionLogFilename: (NSString *)input;

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

// property getter: SslProtocol
- (NSString *)SslProtocol;

// property setter: SslProtocol
- (void)setSslProtocol: (NSString *)input;

// property getter: UpdateCache
- (BOOL)UpdateCache;

// property setter: UpdateCache
- (void)setUpdateCache: (BOOL)boolVal;

// property getter: UseIEProxy
- (BOOL)UseIEProxy;

// property setter: UseIEProxy
- (void)setUseIEProxy: (BOOL)boolVal;

// property getter: UserAgent
- (NSString *)UserAgent;

// property setter: UserAgent
- (void)setUserAgent: (NSString *)input;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// property getter: WasRedirected
- (BOOL)WasRedirected;

// method: AddCacheRoot
- (void)AddCacheRoot: (NSString *)dir;

// method: AddQuickHeader
- (BOOL)AddQuickHeader: (NSString *)name 
	value: (NSString *)value;

// method: ClearInMemoryCookies
- (void)ClearInMemoryCookies;

// method: CloseAllConnections
- (BOOL)CloseAllConnections;

// method: Download
- (BOOL)Download: (NSString *)url 
	filename: (NSString *)filename;

// method: DownloadAppend
- (BOOL)DownloadAppend: (NSString *)url 
	filename: (NSString *)filename;

// method: EventLogName
- (NSString *)EventLogName: (NSNumber *)index;

// method: EventLogValue
- (NSString *)EventLogValue: (NSNumber *)index;

// method: ExtractMetaRefreshUrl
- (NSString *)ExtractMetaRefreshUrl: (NSString *)html;

// method: GenTimeStamp
- (NSString *)GenTimeStamp;

// method: GetCacheRoot
- (NSString *)GetCacheRoot: (NSNumber *)index;

// method: GetCookieXml
- (NSString *)GetCookieXml: (NSString *)domain;

// method: GetDomain
- (NSString *)GetDomain: (NSString *)url;

// method: GetHead
- (CkoHttpResponse *)GetHead: (NSString *)url;

// method: GetRequestHeader
- (NSString *)GetRequestHeader: (NSString *)name;

// method: GetServerSslCert
- (CkoCert *)GetServerSslCert: (NSString *)domain 
	port: (NSNumber *)port;

// method: GetUrlPath
- (NSString *)GetUrlPath: (NSString *)url;

// method: HasRequestHeader
- (BOOL)HasRequestHeader: (NSString *)name;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: PostBinary
- (NSString *)PostBinary: (NSString *)url 
	byteData: (NSData *)byteData 
	contentType: (NSString *)contentType 
	md5: (BOOL)md5 
	gzip: (BOOL)gzip;

// method: PostMime
- (CkoHttpResponse *)PostMime: (NSString *)url 
	mime: (NSString *)mime;

// method: PostUrlEncoded
- (CkoHttpResponse *)PostUrlEncoded: (NSString *)url 
	req: (CkoHttpRequest *)req;

// method: PostXml
- (CkoHttpResponse *)PostXml: (NSString *)url 
	xmlDoc: (NSString *)xmlDoc 
	charset: (NSString *)charset;

// method: PutBinary
- (NSString *)PutBinary: (NSString *)url 
	byteData: (NSData *)byteData 
	contentType: (NSString *)contentType 
	md5: (BOOL)md5 
	gzip: (BOOL)gzip;

// method: PutText
- (NSString *)PutText: (NSString *)url 
	textData: (NSString *)textData 
	charset: (NSString *)charset 
	contentType: (NSString *)contentType 
	md5: (BOOL)md5 
	gzip: (BOOL)gzip;

// method: QuickDeleteStr
- (NSString *)QuickDeleteStr: (NSString *)url;

// method: QuickGet
- (NSData *)QuickGet: (NSString *)url;

// method: QuickGetObj
- (CkoHttpResponse *)QuickGetObj: (NSString *)url;

// method: QuickGetStr
- (NSString *)QuickGetStr: (NSString *)url;

// method: QuickPutStr
- (NSString *)QuickPutStr: (NSString *)url;

// method: RemoveQuickHeader
- (BOOL)RemoveQuickHeader: (NSString *)name;

// method: RemoveRequestHeader
- (void)RemoveRequestHeader: (NSString *)name;

// method: RenderGet
- (NSString *)RenderGet: (NSString *)url;

// method: ResumeDownload
- (BOOL)ResumeDownload: (NSString *)url 
	filename: (NSString *)filename;

// method: S3_CreateBucket
- (BOOL)S3_CreateBucket: (NSString *)bucketName;

// method: S3_DeleteBucket
- (BOOL)S3_DeleteBucket: (NSString *)bucketName;

// method: S3_DeleteObject
- (BOOL)S3_DeleteObject: (NSString *)bucketName 
	objectName: (NSString *)objectName;

// method: S3_DownloadBytes
- (NSData *)S3_DownloadBytes: (NSString *)bucketName 
	objectName: (NSString *)objectName;

// method: S3_DownloadFile
- (BOOL)S3_DownloadFile: (NSString *)bucketName 
	objectName: (NSString *)objectName 
	localFilePath: (NSString *)localFilePath;

// method: S3_DownloadString
- (NSString *)S3_DownloadString: (NSString *)bucketName 
	objectName: (NSString *)objectName 
	charset: (NSString *)charset;

// method: S3_ListBucketObjects
- (NSString *)S3_ListBucketObjects: (NSString *)bucketName;

// method: S3_ListBuckets
- (NSString *)S3_ListBuckets;

// method: S3_UploadBytes
- (BOOL)S3_UploadBytes: (NSData *)objectContent 
	contentType: (NSString *)contentType 
	bucketName: (NSString *)bucketName 
	objectName: (NSString *)objectName;

// method: S3_UploadFile
- (BOOL)S3_UploadFile: (NSString *)localFilePath 
	contentType: (NSString *)contentType 
	bucketName: (NSString *)bucketName 
	ObjectName: (NSString *)ObjectName;

// method: S3_UploadString
- (BOOL)S3_UploadString: (NSString *)objectContent 
	charset: (NSString *)charset 
	contentType: (NSString *)contentType 
	bucketName: (NSString *)bucketName 
	ObjectName: (NSString *)ObjectName;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetCookieXml
- (BOOL)SetCookieXml: (NSString *)domain 
	cookieXml: (NSString *)cookieXml;

// method: SetRequestHeader
- (void)SetRequestHeader: (NSString *)name 
	value: (NSString *)value;

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

// method: SynchronousRequest
- (CkoHttpResponse *)SynchronousRequest: (NSString *)domain 
	port: (NSNumber *)port 
	ssl: (BOOL)ssl 
	req: (CkoHttpRequest *)req;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: UrlDecode
- (NSString *)UrlDecode: (NSString *)str;

// method: UrlEncode
- (NSString *)UrlEncode: (NSString *)str;

// method: XmlRpc
- (NSString *)XmlRpc: (NSString *)urlEndpoint 
	xmlIn: (NSString *)xmlIn;

// method: XmlRpcPut
- (NSString *)XmlRpcPut: (NSString *)urlEndpoint 
	xmlIn: (NSString *)xmlIn;


@end
