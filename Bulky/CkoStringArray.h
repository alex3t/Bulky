// Chilkat Objective-C header.
// Generic/internal class name =  StringArray
// Wrapped Chilkat C++ class name =  CkStringArray



@interface CkoStringArray : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// property getter: Count
- (NSNumber *)Count;

// property getter: Crlf
- (BOOL)Crlf;

// property setter: Crlf
- (void)setCrlf: (BOOL)boolVal;

// property getter: Trim
- (BOOL)Trim;

// property setter: Trim
- (void)setTrim: (BOOL)boolVal;

// property getter: Unique
- (BOOL)Unique;

// property setter: Unique
- (void)setUnique: (BOOL)boolVal;

// method: Append
- (void)Append: (NSString *)str;

// method: AppendSerialized
- (BOOL)AppendSerialized: (NSString *)encodedStr;

// method: Clear
- (void)Clear;

// method: Contains
- (BOOL)Contains: (NSString *)str;

// method: Find
- (NSNumber *)Find: (NSString *)str 
	firstIndex: (NSNumber *)firstIndex;

// method: FindFirstMatch
- (NSNumber *)FindFirstMatch: (NSString *)str 
	firstIndex: (NSNumber *)firstIndex;

// method: GetString
- (NSString *)GetString: (NSNumber *)index;

// method: GetStringLen
- (NSNumber *)GetStringLen: (NSNumber *)index;

// method: InsertAt
- (void)InsertAt: (NSNumber *)index 
	str: (NSString *)str;

// method: LastString
- (NSString *)LastString;

// method: LoadFromFile
- (BOOL)LoadFromFile: (NSString *)filename;

// method: LoadFromText
- (void)LoadFromText: (NSString *)str;

// method: Pop
- (NSString *)Pop;

// method: Prepend
- (void)Prepend: (NSString *)str;

// method: Remove
- (void)Remove: (NSString *)str;

// method: RemoveAt
- (BOOL)RemoveAt: (NSNumber *)index;

// method: SaveNthToFile
- (BOOL)SaveNthToFile: (NSNumber *)index 
	filename: (NSString *)filename;

// method: SaveToFile
- (BOOL)SaveToFile: (NSString *)filename;

// method: SaveToText
- (NSString *)SaveToText;

// method: Serialize
- (NSString *)Serialize;

// method: Sort
- (void)Sort: (BOOL)ascending;

// method: SplitAndAppend
- (void)SplitAndAppend: (NSString *)str 
	boundary: (NSString *)boundary;

// method: Subtract
- (void)Subtract: (CkoStringArray *)array;

// method: Union
- (void)Union: (CkoStringArray *)array;


@end
