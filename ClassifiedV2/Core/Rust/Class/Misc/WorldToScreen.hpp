namespace world // no fucking idea how to keep this cleaner :|
{
	static Camera* main = nullptr;

	static auto viewMatrix() -> Matrix
	{
		auto camera_ = *reinterpret_cast<std::uintptr_t*>(main + 0x10);
		if (!camera_) {
			return {};
		}

		auto matrix = *reinterpret_cast<Matrix*>(camera_ + 0x2e4);
		if (!matrix.m) {
			return {};
		}
		return matrix;
	}
	static auto screen_transform(const Vec3 EntityPos, Vec2& ScreenPos) -> bool
	{
		auto matrix = viewMatrix();

		if (!matrix.m) {
			return false;
		}
		const auto temp = matrix.transpose();

		auto translation_vector = Vec3{ temp[3][0], temp[3][1], temp[3][2] };
		auto up = Vec3{ temp[1][0], temp[1][1], temp[1][2] };
		auto right = Vec3{ temp[0][0], temp[0][1], temp[0][2] };

		float w = translation_vector.Dot(EntityPos) + temp[3][3];

		if (w < 0.098f) {
			return false;
		}

		float x = up.Dot(EntityPos) + temp._24;
		float y = right.Dot(EntityPos) + temp._14;

		ScreenPos.x = screen_center.x * (1 + y / w);
		ScreenPos.y = screen_center.y * (1 - x / w);

		//ScreenPos = out;

		return true;
	}


}