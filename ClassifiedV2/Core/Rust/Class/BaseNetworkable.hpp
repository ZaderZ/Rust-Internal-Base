class BaseNetworkable : public Component
{
public:
	CLASS("", "BaseNetworkable");

	MEMBER(std::uintptr_t, net);

	auto PlayerDestroyed() -> bool
	{
		if (!this) return false;
		auto k__BackingField = Il2CppWrapper::GetClassFromName("", "BaseNetworkable")->GetFieldFromName("<IsDestroyed>k__BackingField");
		return *reinterpret_cast<bool*>(this + k__BackingField);
	}

};