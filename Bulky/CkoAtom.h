// Chilkat Objective-C header.
// Generic/internal class name =  Atom
// Wrapped Chilkat C++ class name =  CkAtom



@interface CkoAtom : NSObject {

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

// property getter: NumEntries
- (NSNumber *)NumEntries;

// method: AddElement
- (NSNumber *)AddElement: (NSString *)tag 
	value: (NSString *)value;

// method: AddElementDate
- (NSNumber *)AddElementDate: (NSString *)tag 
	dateTime: (NSDate *)dateTime;

// method: AddElementHtml
- (NSNumber *)AddElementHtml: (NSString *)tag 
	htmlStr: (NSString *)htmlStr;

// method: AddElementXHtml
- (NSNumber *)AddElementXHtml: (NSString *)tag 
	xmlStr: (NSString *)xmlStr;

// method: AddElementXml
- (NSNumber *)AddElementXml: (NSString *)tag 
	xmlStr: (NSString *)xmlStr;

// method: AddEntry
- (void)AddEntry: (NSString *)xmlStr;

// method: AddLink
- (void)AddLink: (NSString *)rel 
	href: (NSString *)href 
	title: (NSString *)title 
	typ: (NSString *)typ;

// method: AddPerson
- (void)AddPerson: (NSString *)tag 
	name: (NSString *)name 
	uri: (NSString *)uri 
	email: (NSString *)email;

// method: DeleteElement
- (void)DeleteElement: (NSString *)tag 
	index: (NSNumber *)index;

// method: DeleteElementAttr
- (void)DeleteElementAttr: (NSString *)tag 
	index: (NSNumber *)index 
	attrName: (NSString *)attrName;

// method: DeletePerson
- (void)DeletePerson: (NSString *)tag 
	index: (NSNumber *)index;

// method: DownloadAtom
- (BOOL)DownloadAtom: (NSString *)url;

// method: GetElement
- (NSString *)GetElement: (NSString *)tag 
	index: (NSNumber *)index;

// method: GetElementAttr
- (NSString *)GetElementAttr: (NSString *)tag 
	index: (NSNumber *)index 
	attrName: (NSString *)attrName;

// method: GetElementCount
- (NSNumber *)GetElementCount: (NSString *)tag;

// method: GetElementDate
- (NSDate *)GetElementDate: (NSString *)tag 
	index: (NSNumber *)index;

// method: GetEntry
- (CkoAtom *)GetEntry: (NSNumber *)index;

// method: GetLinkHref
- (NSString *)GetLinkHref: (NSString *)relName;

// method: GetPersonInfo
- (NSString *)GetPersonInfo: (NSString *)tag 
	index: (NSNumber *)index 
	tag2: (NSString *)tag2;

// method: GetTopAttr
- (NSString *)GetTopAttr: (NSString *)attrName;

// method: HasElement
- (BOOL)HasElement: (NSString *)tag;

// method: LoadXml
- (BOOL)LoadXml: (NSString *)xmlStr;

// method: NewEntry
- (void)NewEntry;

// method: NewFeed
- (void)NewFeed;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetElementAttr
- (void)SetElementAttr: (NSString *)tag 
	index: (NSNumber *)index 
	attrName: (NSString *)attrName 
	attrValue: (NSString *)attrValue;

// method: SetTopAttr
- (void)SetTopAttr: (NSString *)attrName 
	value: (NSString *)value;

// method: ToXmlString
- (NSString *)ToXmlString;

// method: UpdateElement
- (void)UpdateElement: (NSString *)tag 
	index: (NSNumber *)index 
	value: (NSString *)value;

// method: UpdateElementDate
- (void)UpdateElementDate: (NSString *)tag 
	index: (NSNumber *)index 
	dateTime: (NSDate *)dateTime;

// method: UpdateElementHtml
- (void)UpdateElementHtml: (NSString *)tag 
	index: (NSNumber *)index 
	htmlStr: (NSString *)htmlStr;

// method: UpdateElementXHtml
- (void)UpdateElementXHtml: (NSString *)tag 
	index: (NSNumber *)index 
	xmlStr: (NSString *)xmlStr;

// method: UpdateElementXml
- (void)UpdateElementXml: (NSString *)tag 
	index: (NSNumber *)index 
	xmlStr: (NSString *)xmlStr;

// method: UpdatePerson
- (void)UpdatePerson: (NSString *)tag 
	index: (NSNumber *)index 
	name: (NSString *)name 
	uri: (NSString *)uri 
	email: (NSString *)email;


@end
