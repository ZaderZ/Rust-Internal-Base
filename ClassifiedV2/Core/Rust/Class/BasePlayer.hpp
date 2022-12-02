
class BasePlayer : public BaseCombatEntity
{
public:
	CLASS("", "BasePlayer");

	MEMBER(PlayerModel*, playerModel);
	MEMBER(uintptr_t, playerFlags);
	MEMBER(unsigned long long, userID);
	MEMBER(UnityString*, _displayName);

	bool PlayerValid()
	{
		if (this == nullptr)
			return false;

		if (!this->net())
			return false;

		if (this->PlayerDestroyed())
			return false;


		return true;
	}
	static auto playerList() -> ListDictionary*
	{
		static auto visiblePlayerList = Il2CppWrapper::GetClassFromName("", "BasePlayer")->GetFieldFromName("visiblePlayerList");

		return *reinterpret_cast<ListDictionary**>(*reinterpret_cast<uintptr_t*>(StaticClass() + 0xB8) + visiblePlayerList);
	}
	auto HasFlag(Enums::PlayerFlags flag) -> bool
	{
		return (playerFlags() & uintptr_t(flag)) == uintptr_t(flag);
	}
};