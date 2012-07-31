// Chilkat Objective-C header.
// Generic/internal class name =  SFtpDir
// Wrapped Chilkat C++ class name =  CkSFtpDir

@class CkoSFtpFile;


@interface CkoSFtpDir : NSObject {

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

// property getter: NumFilesAndDirs
- (NSNumber *)NumFilesAndDirs;

// property getter: OriginalPath
- (NSString *)OriginalPath;

// method: GetFileObject
- (CkoSFtpFile *)GetFileObject: (NSNumber *)index;

// method: GetFilename
- (NSString *)GetFilename: (NSNumber *)index;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;


@end
