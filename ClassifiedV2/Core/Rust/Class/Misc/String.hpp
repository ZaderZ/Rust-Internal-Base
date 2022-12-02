class UnityString
{
public:
	CLASS("System", "String");
public:
	char zpad[0x10]{ };
	int size{ };
	wchar_t buffer[128 + 1];
public:
	UnityString(const wchar_t* st)
	{
		size = min(Crt::wcslen(st), 128);
		for (int idx = 0; idx < size; idx++)
		{
			buffer[idx] = st[idx];
		}
		buffer[size] = 0;
	}
};