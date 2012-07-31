// Chilkat Objective-C header.
// Generic/internal class name =  Bounce
// Wrapped Chilkat C++ class name =  CkBounce

@class CkoEmail;
@class CkoString;


@interface CkoBounce : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: BounceAddress
- (NSString *)BounceAddress;

// property getter: BounceData
- (NSString *)BounceData;

// property getter: BounceType
- (NSNumber *)BounceType;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: Version
- (NSString *)Version;

// method: ExamineEmail
- (BOOL)ExamineEmail: (CkoEmail *)email;

// method: ExamineEml
- (BOOL)ExamineEml: (NSString *)emlFilename;

// method: ExamineMime
- (BOOL)ExamineMime: (CkoString *)mimeString;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;


@end
