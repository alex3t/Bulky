// Chilkat Objective-C header.
// Generic/internal class name =  Rss
// Wrapped Chilkat C++ class name =  CkRss



@interface CkoRss : NSObject {

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

// property getter: NumChannels
- (NSNumber *)NumChannels;

// property getter: NumItems
- (NSNumber *)NumItems;

// method: AddNewChannel
- (CkoRss *)AddNewChannel;

// method: AddNewImage
- (CkoRss *)AddNewImage;

// method: AddNewItem
- (CkoRss *)AddNewItem;

// method: DownloadRss
- (BOOL)DownloadRss: (NSString *)url;

// method: GetAttr
- (NSString *)GetAttr: (NSString *)tag 
	attrName: (NSString *)attrName;

// method: GetChannel
- (CkoRss *)GetChannel: (NSNumber *)index;

// method: GetCount
- (NSNumber *)GetCount: (NSString *)tag;

// method: GetDate
- (NSDate *)GetDate: (NSString *)tag;

// method: GetImage
- (CkoRss *)GetImage;

// method: GetInt
- (NSNumber *)GetInt: (NSString *)tag;

// method: GetItem
- (CkoRss *)GetItem: (NSNumber *)index;

// method: GetString
- (NSString *)GetString: (NSString *)tag;

// method: LoadRssFile
- (BOOL)LoadRssFile: (NSString *)filename;

// method: LoadRssString
- (BOOL)LoadRssString: (NSString *)rssString;

// method: MGetAttr
- (NSString *)MGetAttr: (NSString *)tag 
	index: (NSNumber *)index 
	attrName: (NSString *)attrName;

// method: MGetString
- (NSString *)MGetString: (NSString *)tag 
	index: (NSNumber *)index;

// method: MSetAttr
- (BOOL)MSetAttr: (NSString *)tag 
	index: (NSNumber *)index 
	attrName: (NSString *)attrName 
	value: (NSString *)value;

// method: MSetString
- (BOOL)MSetString: (NSString *)tag 
	index: (NSNumber *)index 
	value: (NSString *)value;

// method: NewRss
- (void)NewRss;

// method: Remove
- (void)Remove: (NSString *)tag;

// method: SaveLastError
- (BOOL)SaveLastError: (NSString *)filename;

// method: SetAttr
- (void)SetAttr: (NSString *)tag 
	attrName: (NSString *)attrName 
	value: (NSString *)value;

// method: SetDate
- (void)SetDate: (NSString *)tag 
	dateTime: (NSDate *)dateTime;

// method: SetDateNow
- (void)SetDateNow: (NSString *)tag;

// method: SetInt
- (void)SetInt: (NSString *)tag 
	value: (NSNumber *)value;

// method: SetString
- (void)SetString: (NSString *)tag 
	value: (NSString *)value;

// method: ToXmlString
- (NSString *)ToXmlString;


@end
