// Chilkat Objective-C header.
// Generic/internal class name =  HtmlToXml
// Wrapped Chilkat C++ class name =  CkHtmlToXml



@interface CkoHtmlToXml : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: DropCustomTags
- (BOOL)DropCustomTags;

// property setter: DropCustomTags
- (void)setDropCustomTags: (BOOL)boolVal;

// property getter: Html
- (NSString *)Html;

// property setter: Html
- (void)setHtml: (NSString *)input;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: Nbsp
- (NSNumber *)Nbsp;

// property setter: Nbsp
- (void)setNbsp: (NSNumber *)longVal;

// property getter: Version
- (NSString *)Version;

// property getter: XmlCharset
- (NSString *)XmlCharset;

// property setter: XmlCharset
- (void)setXmlCharset: (NSString *)input;

// method: ConvertFile
- (BOOL)ConvertFile: (NSString *)inHtmlFilename 
	outXmlFilename: (NSString *)outXmlFilename;

// method: DropTagType
- (void)DropTagType: (NSString *)tagName;

// method: DropTextFormattingTags
- (void)DropTextFormattingTags;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: ReadFileToString
- (NSString *)ReadFileToString: (NSString *)filename 
	srcCharset: (NSString *)srcCharset;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetHtmlBytes
- (void)SetHtmlBytes: (NSData *)inData;

// method: SetHtmlFromFile
- (BOOL)SetHtmlFromFile: (NSString *)filename;

// method: ToXml
- (NSString *)ToXml;

// method: UndropTagType
- (void)UndropTagType: (NSString *)tagName;

// method: UndropTextFormattingTags
- (void)UndropTextFormattingTags;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)code;

// method: WriteStringToFile
- (BOOL)WriteStringToFile: (NSString *)str 
	filename: (NSString *)filename 
	charset: (NSString *)charset;

// method: Xml
- (NSString *)Xml;


@end
