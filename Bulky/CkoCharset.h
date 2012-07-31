// Chilkat Objective-C header.
// Generic/internal class name =  Charset
// Wrapped Chilkat C++ class name =  CkCharset



@interface CkoCharset : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: AltToCharset
- (NSString *)AltToCharset;

// property setter: AltToCharset
- (void)setAltToCharset: (NSString *)input;

// property getter: ErrorAction
- (NSNumber *)ErrorAction;

// property setter: ErrorAction
- (void)setErrorAction: (NSNumber *)intVal;

// property getter: FromCharset
- (NSString *)FromCharset;

// property setter: FromCharset
- (void)setFromCharset: (NSString *)input;

// property getter: LastErrorHtml
- (NSString *)LastErrorHtml;

// property getter: LastErrorText
- (NSString *)LastErrorText;

// property getter: LastErrorXml
- (NSString *)LastErrorXml;

// property getter: LastInputAsHex
- (NSString *)LastInputAsHex;

// property getter: LastInputAsQP
- (NSString *)LastInputAsQP;

// property getter: LastOutputAsHex
- (NSString *)LastOutputAsHex;

// property getter: LastOutputAsQP
- (NSString *)LastOutputAsQP;

// property getter: SaveLast
- (BOOL)SaveLast;

// property setter: SaveLast
- (void)setSaveLast: (BOOL)boolVal;

// property getter: ToCharset
- (NSString *)ToCharset;

// property setter: ToCharset
- (void)setToCharset: (NSString *)input;

// property getter: Version
- (NSString *)Version;

// method: CharsetToCodePage
- (NSNumber *)CharsetToCodePage: (NSString *)charsetName;

// method: CodePageToCharset
- (NSString *)CodePageToCharset: (NSNumber *)codePage;

// method: ConvertData
- (NSData *)ConvertData: (NSData *)inData;

// method: ConvertFile
- (BOOL)ConvertFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: ConvertFileNoPreamble
- (BOOL)ConvertFileNoPreamble: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: ConvertFromUnicode
- (NSData *)ConvertFromUnicode: (NSData *)uniData;

// method: ConvertHtml
- (NSData *)ConvertHtml: (NSData *)htmlIn;

// method: ConvertHtmlFile
- (BOOL)ConvertHtmlFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: ConvertToUnicode
- (NSData *)ConvertToUnicode: (NSData *)mbData;

// method: EntityEncodeDec
- (NSString *)EntityEncodeDec: (NSString *)inStr;

// method: EntityEncodeHex
- (NSString *)EntityEncodeHex: (NSString *)inStr;

// method: GetHtmlCharset
- (NSString *)GetHtmlCharset: (NSData *)htmlData;

// method: GetHtmlFileCharset
- (NSString *)GetHtmlFileCharset: (NSString *)htmlFilename;

// method: HtmlDecodeToStr
- (NSString *)HtmlDecodeToStr: (NSString *)str;

// method: HtmlEntityDecode
- (NSData *)HtmlEntityDecode: (NSData *)inData;

// method: HtmlEntityDecodeFile
- (BOOL)HtmlEntityDecodeFile: (NSString *)inFilename 
	outFilename: (NSString *)outFilename;

// method: IsUnlocked
- (BOOL)IsUnlocked;

// method: LowerCase
- (NSString *)LowerCase: (NSString *)inStr;

// method: ReadFile
- (NSData *)ReadFile: (NSString *)filename;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetErrorBytes
- (void)SetErrorBytes: (NSData *)data 
	dataLen: (NSNumber *)dataLen;

// method: SetErrorString
- (void)SetErrorString: (NSString *)str;

// method: UnlockComponent
- (BOOL)UnlockComponent: (NSString *)unlockCode;

// method: UpperCase
- (NSString *)UpperCase: (NSString *)inStr;

// method: UrlDecodeStr
- (NSString *)UrlDecodeStr: (NSString *)inStr;

// method: VerifyData
- (BOOL)VerifyData: (NSString *)charset 
	charData: (NSData *)charData;

// method: VerifyFile
- (BOOL)VerifyFile: (NSString *)charset 
	filename: (NSString *)filename;

// method: WriteFile
- (BOOL)WriteFile: (NSString *)filename 
	dataBuf: (NSData *)dataBuf;


@end
