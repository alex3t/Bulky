// Chilkat Objective-C header.
// Generic/internal class name =  SFtp
// Wrapped Chilkat C++ class name =  CkSFtp

@class CkoSshKey;
@class CkoSFtpDir;


@interface CkoSFtp : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: AccumulateBuffer
- (NSData *)AccumulateBuffer;

// property getter: AccumulateBuffer
- (NSMutableData *)AccumulateBufferMutable;

// property getter: ClientIdentifier
- (NSString *)ClientIdentifier;

// property setter: ClientIdentifier
- (void)setClientIdentifier: (NSString *)input;

// property getter: ClientIpAddress
- (NSString *)ClientIpAddress;

// property setter: ClientIpAddress
- (void)setClientIpAddress: (NSString *)input;

// property getter: ConnectTimeoutMs
- (NSNumber *)ConnectTimeoutMs;

// property setter: ConnectTimeoutMs
- (void)setConnectTimeoutMs: (NSNumber *)intVal;

// property getter: DebugLogFilePath
- (NSString *)DebugLogFilePath;

// property setter: DebugLogFilePath
- (void)setDebugLogFilePath: (NSString *)input;

// property getter: DisconnectCode
- (NSNumber *)DisconnectCode;

// property getter: DisconnectReason
- (NSString *)DisconnectReason;

// property getter: EnableCache
- (BOOL)EnableCache;

// property setter: EnableCache
- (void)setEnableCache: (BOOL)boolVal;

// property getter: FilenameCharset
- (NSString *)FilenameCharset;

// property setter: FilenameCharset
- (void)setFilenameCharset: (NSString *)input;

// property getter: ForceV3
- (BOOL)ForceV3;

// property setter: ForceV3
- (void)setForceV3: (BOOL)boolVal;

// property getter: HeartbeatMs
- (NSNumber *)HeartbeatMs;

// property setter: HeartbeatMs
- (void)setHeartbeatMs: (NSNumber *)intVal;

// property getter: HostKeyFingerprint
- (NSString *)HostKeyFingerprint;

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

// property getter: IdleTimeoutMs
- (NSNumber *)IdleTimeoutMs;

// property setter: IdleTimeoutMs
- (void)setIdleTimeoutMs: (NSNumber *)intVal;

// property getter: InitializeFailCode
- (NSNumber *)InitializeFailCode;

// property getter: InitializeFailReason
- (NSString *)InitializeFailReason;

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

// property getter: MaxPacketSize
- (NSNumber *)MaxPacketSize;

// property setter: MaxPacketSize
- (void)setMaxPacketSize: (NSNumber *)intVal;

// property getter: PasswordChangeRequested
- (BOOL)PasswordChangeRequested;

// property getter: PreserveDate
- (BOOL)PreserveDate;

// property setter: PreserveDate
- (void)setPreserveDate: (BOOL)boolVal;

// property getter: ProtocolVersion
- (NSNumber *)ProtocolVersion;

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

// property getter: TcpNoDelay
- (BOOL)TcpNoDelay;

// property setter: TcpNoDelay
- (void)setTcpNoDelay: (BOOL)boolVal;

// property getter: UtcMode
- (BOOL)UtcMode;

// property setter: UtcMode
- (void)setUtcMode: (BOOL)boolVal;

// property getter: VerboseLogging
- (BOOL)VerboseLogging;

// property setter: VerboseLogging
- (void)setVerboseLogging: (BOOL)boolVal;

// property getter: Version
- (NSString *)Version;

// method: AccumulateBytes
- (NSNumber *)AccumulateBytes: (NSString *)handle 
	maxBytes: (NSNumber *)maxBytes;

// method: Add64
- (NSString *)Add64: (NSString *)n1 
	n2: (NSString *)n2;

// method: AuthenticatePk
- (BOOL)AuthenticatePk: (NSString *)username 
	privateKey: (CkoSshKey *)privateKey;

// method: AuthenticatePw
- (BOOL)AuthenticatePw: (NSString *)login 
	password: (NSString *)password;

// method: AuthenticatePwPk
- (BOOL)AuthenticatePwPk: (NSString *)username 
	password: (NSString *)password 
	privateKey: (CkoSshKey *)privateKey;

// method: ClearAccumulateBuffer
- (void)ClearAccumulateBuffer;

// method: ClearCache
- (void)ClearCache;

// method: ClearSessionLog
- (void)ClearSessionLog;

// method: CloseHandle
- (BOOL)CloseHandle: (NSString *)handle;

// method: Connect
- (BOOL)Connect: (NSString *)hostname 
	port: (NSNumber *)port;

// method: CopyFileAttr
- (BOOL)CopyFileAttr: (NSString *)localFilename 
	remoteFilenameOrHandle: (NSString *)remoteFilenameOrHandle 
	bIsHandle: (BOOL)bIsHandle;

// method: CreateDir
- (BOOL)CreateDir: (NSString *)path;

// method: Disconnect
- (void)Disconnect;

// method: DownloadFile
- (BOOL)DownloadFile: (NSString *)handle 
	toFilename: (NSString *)toFilename;

// method: DownloadFileByName
- (BOOL)DownloadFileByName: (NSString *)remoteFilePath 
	localFilePath: (NSString *)localFilePath;

// method: Eof
- (BOOL)Eof: (NSString *)handle;

// method: GetFileCreateTime
- (NSDate *)GetFileCreateTime: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: GetFileGroup
- (NSString *)GetFileGroup: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: GetFileLastAccess
- (NSDate *)GetFileLastAccess: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: GetFileLastModified
- (NSDate *)GetFileLastModified: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: GetFileOwner
- (NSString *)GetFileOwner: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: GetFilePermissions
- (NSNumber *)GetFilePermissions: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: GetFileSize64
- (NSNumber *)GetFileSize64: (NSString *)filenameOrHandle 
	bFollowLinks: (BOOL)bFollowLinks 
	bIsHandle: (BOOL)bIsHandle;

// method: InitializeSftp
- (BOOL)InitializeSftp;

// method: LastReadFailed
- (BOOL)LastReadFailed: (NSString *)handle;

// method: LastReadNumBytes
- (NSNumber *)LastReadNumBytes: (NSString *)handle;

// method: OpenDir
- (NSString *)OpenDir: (NSString *)path;

// method: OpenFile
- (NSString *)OpenFile: (NSString *)filename 
	access: (NSString *)access 
	createDisp: (NSString *)createDisp;

// method: ReadDir
- (CkoSFtpDir *)ReadDir: (NSString *)handle;

// method: ReadFileBytes
- (NSData *)ReadFileBytes: (NSString *)handle 
	numBytes: (NSNumber *)numBytes;

// method: ReadFileBytes64
- (NSData *)ReadFileBytes64: (NSString *)handle 
	offset64: (NSNumber *)offset64 
	numBytes: (NSNumber *)numBytes;

// method: ReadFileText
- (NSString *)ReadFileText: (NSString *)handle 
	numBytes: (NSNumber *)numBytes 
	charset: (NSString *)charset;

// method: ReadFileText64
- (NSString *)ReadFileText64: (NSString *)handle 
	offset64: (NSNumber *)offset64 
	numBytes: (NSNumber *)numBytes 
	charset: (NSString *)charset;

// method: RealPath
- (NSString *)RealPath: (NSString *)originalPath 
	composePath: (NSString *)composePath;

// method: RemoveDir
- (BOOL)RemoveDir: (NSString *)path;

// method: RemoveFile
- (BOOL)RemoveFile: (NSString *)filename;

// method: RenameFileOrDir
- (BOOL)RenameFileOrDir: (NSString *)oldPath 
	newPath: (NSString *)newPath;

// method: ResumeDownloadFileByName
- (BOOL)ResumeDownloadFileByName: (NSString *)remoteFilePath 
	localFilePath: (NSString *)localFilePath;

// method: ResumeUploadFileByName
- (BOOL)ResumeUploadFileByName: (NSString *)remoteFilePath 
	localFilePath: (NSString *)localFilePath;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetCreateTime
- (BOOL)SetCreateTime: (NSString *)pathOrHandle 
	bIsHandle: (BOOL)bIsHandle 
	createTime: (NSDate *)createTime;

// method: SetLastAccessTime
- (BOOL)SetLastAccessTime: (NSString *)pathOrHandle 
	bIsHandle: (BOOL)bIsHandle 
	lastAccessTime: (NSDate *)lastAccessTime;

// method: SetLastModifiedTime
- (BOOL)SetLastModifiedTime: (NSString *)pathOrHandle 
	bIsHandle: (BOOL)bIsHandle 
	lastModTime: (NSDate *)lastModTime;

// method: SetOwnerAndGroup
- (BOOL)SetOwnerAndGroup: (NSString *)pathOrHandle 
	bIsHandle: (BOOL)bIsHandle 
	owner: (NSString *)owner 
	group: (NSString *)group;

// method: SetPermissions
- (BOOL)SetPermissions: (NSString *)pathOrHandle 
	bIsHandle: (BOOL)bIsHandle 
	perm: (NSNumber *)perm;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: UploadFile
- (BOOL)UploadFile: (NSString *)handle 
	fromFilename: (NSString *)fromFilename;

// method: UploadFileByName
- (BOOL)UploadFileByName: (NSString *)remoteFilePath 
	localFilePath: (NSString *)localFilePath;

// method: WriteFileBytes
- (BOOL)WriteFileBytes: (NSString *)handle 
	data: (NSData *)data;

// method: WriteFileBytes64
- (BOOL)WriteFileBytes64: (NSString *)handle 
	offset64: (NSNumber *)offset64 
	data: (NSData *)data;

// method: WriteFileText
- (BOOL)WriteFileText: (NSString *)handle 
	charset: (NSString *)charset 
	textData: (NSString *)textData;

// method: WriteFileText64
- (BOOL)WriteFileText64: (NSString *)handle 
	offset64: (NSNumber *)offset64 
	charset: (NSString *)charset 
	textData: (NSString *)textData;


@end
