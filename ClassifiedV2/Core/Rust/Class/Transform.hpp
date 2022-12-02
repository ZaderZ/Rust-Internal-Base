class Transform
{
public:
	CLASS("UnityEngine", "Transform");

	auto position() -> Vec3
	{
		if (!this) return Vec3::Zero();
		METHOD(Vec3(**) (Transform*), get_position);
		return get_position(this);
	}
};