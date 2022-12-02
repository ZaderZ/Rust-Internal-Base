
class Component
{
public:
	CLASS("UnityEngine", "Component");

	auto transform() -> Transform*
	{
		if (!this) return nullptr;
		METHOD(Transform * (**)(Component*), get_transform);
		return get_transform(this);
	}
};