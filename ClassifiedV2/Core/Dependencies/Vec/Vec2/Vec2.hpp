class Vec2 {
public:
	float x, y;

	inline Vec2() {
		x = y = 0.f;
	}

	inline Vec2 operator/(float v) const {
		return Vec2(x / v, y / v);
	}

	inline Vec2(float X, float Y) {
		x = X; y = Y;
	}

	inline Vec2 operator-(const Vec2& v) const {
		return Vec2(x - v.x, y - v.y);
	}

	inline Vec2 operator+(const Vec2& v) const {
		return Vec2(x + v.x, y + v.y);
	}

	inline Vec2& operator+=(const Vec2& v) {
		x += v.x; y += v.y; return *this;
	}

	inline Vec2 operator/(const Vec2& v) const {
		return Vec2(x / v.x, y / v.y);
	}

	inline float Distance(const Vec2& Dst) {
		return sqrt(powf(this->x - Dst.x, 2) + powf(this->y - Dst.y, 2));
	}
	float Distance2D(Vec2  vInput) const {
		return sqrt(powf(x - vInput.x, 2) + powf(y - vInput.y, 2));
	}
	inline bool Zero() const
	{
		return (x <= 0.f || y <= 0.f);

		return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
	}
	bool Empty() const {
		return x == 0.f && y == 0.f;
	}
};