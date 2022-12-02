class ListDictionary
{
public:
	char pad_0000[0x20];
	class BufferList* keys;
	class BufferList* vals;
};
class BufferList
{
public:
	char pad_0000[0x10];
	int32_t size;
	char pad_0014[0x4];
	void* buffer;
};