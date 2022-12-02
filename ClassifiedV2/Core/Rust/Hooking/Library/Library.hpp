#pragma once

class HookLib
{
private:
	uintptr_t m_original{ 0 };
public:

	auto InitializeHook(const char* name_space, const char* klass, const char* method, void* our_function) -> void
	{
		auto function = *reinterpret_cast<void**>(Il2CppWrapper::GetClassFromName(name_space, klass)->GetMethodFromName(method));

		if (!function)
		{
			printf("[ DEBUG ] Failed to hook %s.\n", method);
		}
		else
			printf("[ DEBUG ] Hooked %s.\n", method);

		MH_CreateHook((void*)function, our_function, (void**)&m_original);
		MH_EnableHook(function);
	}


	template< typename t>
	auto get_original() -> t
	{
		return reinterpret_cast<t>(m_original);
	}
};