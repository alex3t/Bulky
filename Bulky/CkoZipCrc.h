// Chilkat Objective-C header.
// Generic/internal class name =  ZipCrc
// Wrapped Chilkat C++ class name =  CkZipCrc



@interface CkoZipCrc : NSObject {

	@private
		void *m_obj;

}

- (id)init;
- (void)dealloc;
- (void)dispose;
- (void *)CppImplObj;
- (void)setCppImplObj: (void *)pObj;

// method: BeginStream
- (void)BeginStream;

// method: CalculateCrc
- (NSNumber *)CalculateCrc: (NSData *)byteData;

// method: EndStream
- (NSNumber *)EndStream;

// method: FileCrc
- (NSNumber *)FileCrc: (NSString *)filename;

// method: MoreData
- (void)MoreData: (NSData *)byteData;

// method: ToHex
- (NSString *)ToHex: (NSNumber *)crc;


@end
