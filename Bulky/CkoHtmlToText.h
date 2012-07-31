// Chilkat Objective-C header.
// Generic/internal class name =  HtmlToText
// Wrapped Chilkat C++ class name =  CkHtmlToText



@interface CkoHtmlToText : NSObject {

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

// property getter: RightMargin
- (NSNumber *)RightMargin;

// property setter: RightMargin
- (void)setRightMargin: (NSNumber *)intVal;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: ReadFileToString
- (NSString *)ReadFileToString: (NSString *)filename 
	srcCharset: (NSString *)srcCharset;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: ToText
- (NSString *)ToText: (NSString *)html;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)code;

// method: WriteStringToFile
- (BOOL)WriteStringToFile: (NSString *)str 
	filename: (NSString *)filename 
	charset: (NSString *)charset;


@end
