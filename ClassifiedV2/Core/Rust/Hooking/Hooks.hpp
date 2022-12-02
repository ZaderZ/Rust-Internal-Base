#define CREATE_HOOK( type, name, args ) inline static HookLib name##hk; static type name args; 

class Hooks
{
private:
	CREATE_HOOK(void, ClientInput, (BasePlayer*, std::uintptr_t));
	CREATE_HOOK(void, TryRepair, (std::uintptr_t));
public:
	static auto Enable() -> void;
	static auto Disable() -> void;
};