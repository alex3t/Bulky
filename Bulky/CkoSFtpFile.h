// Chilkat Objective-C header.
// Generic/internal class name =  SFtpFile
// Wrapped Chilkat C++ class name =  CkSFtpFile



@interface CkoSFtpFile : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: CreateTime
- (NSDate *)CreateTime;

// property getter: FileType
- (NSString *)FileType;

// property getter: Filename
- (NSString *)Filename;

// property getter: Gid
- (NSNumber *)Gid;

// property getter: Group
- (NSString *)Group;

// property getter: IsAppendOnly
- (BOOL)IsAppendOnly;

// property getter: IsArchive
- (BOOL)IsArchive;

// property getter: IsCaseInsensitive
- (BOOL)IsCaseInsensitive;

// property getter: IsCompressed
- (BOOL)IsCompressed;

// property getter: IsDirectory
- (BOOL)IsDirectory;

// property getter: IsEncrypted
- (BOOL)IsEncrypted;

// property getter: IsHidden
- (BOOL)IsHidden;

// property getter: IsImmutable
- (BOOL)IsImmutable;

// property getter: IsReadOnly
- (BOOL)IsReadOnly;

// property getter: IsRegular
- (BOOL)IsRegular;

// property getter: IsSparse
- (BOOL)IsSparse;

// property getter: IsSymLink
- (BOOL)IsSymLink;

// property getter: IsSync
- (BOOL)IsSync;

// property getter: IsSystem
- (BOOL)IsSystem;

// property getter: LastAccessTime
- (NSDate *)LastAccessTime;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: LastModifiedTime
- (NSDate *)LastModifiedTime;

// property getter: Owner
- (NSString *)Owner;

// property getter: Permissions
- (NSNumber *)Permissions;

// property getter: Size64
- (NSNumber *)Size64;

// property getter: Uid
- (NSNumber *)Uid;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;


@end
