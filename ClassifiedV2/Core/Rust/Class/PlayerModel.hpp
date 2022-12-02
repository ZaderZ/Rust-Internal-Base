
class PlayerModel
{
public:
	CLASS("", "PlayerModel");

	auto PlayerNPC() -> bool
	{
		if (!this) return false;
		auto npc = Il2CppWrapper::GetClassFromName("", "PlayerModel")->GetFieldFromName("<IsNpc>k__BackingField");
		return *reinterpret_cast<bool*>(this + npc);
	}
};