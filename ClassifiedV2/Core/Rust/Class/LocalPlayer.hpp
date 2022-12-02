class LocalPlayer
{
public:
	CLASS("", "LocalPlayer");

	static auto Entity() -> BasePlayer*
	{
		METHOD(BasePlayer * (**)(), get_Entity);
		return get_Entity();
	}
};