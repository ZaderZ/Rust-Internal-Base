class Camera
{
public:
	CLASS("UnityEngine", "Camera");

	static auto main() -> Camera*
	{
		METHOD(Camera * (**)(), get_main);
		return get_main();
	}
};