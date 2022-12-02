class Vec3
{
public:
	float x, y, z;

	Vec3() {
		x = y = z = 0.f;
	}

	Vec3(float fx, float fy, float fz) {
		x = fx;
		y = fy;
		z = fz;
	}

	static Vec3 Zero() {
		return Vec3(0.0f, 0.0f, 0.0f);
	}

	static Vec3 One() {
		return Vec3(1.0f, 1.0f, 1.0f);
	}

	static Vec3 Up() {
		return Vec3(0.0f, 1.0f, 0.0f);
	}

	static Vec3 Down() {
		return Vec3(0.0f, -1.0f, 0.0f);
	}

	static Vec3 Left() {
		return Vec3(-1.0f, 0.0f, 0.0f);
	}

	static Vec3 Right() {
		return Vec3(1.0f, 0.0f, 0.0f);
	}

	static Vec3 Forward() {
		return Vec3(0.0f, 0.0f, 1.0f);
	}

	static Vec3 Back() {
		return Vec3(0.0f, 0.0f, -1.0f);
	}
	static float Clamp01(float value)
	{
		if (value < 0.f)
			return 0.f;
		else if (value > 1.f)
			return 1.f;
		else
			return value;
	}

	static Vec3 Lerp(Vec3 a, Vec3 b, float t)
	{
		t = Clamp01(t);
		return Vec3(
			a.x + (b.x - a.x) * t,
			a.y + (b.y - a.y) * t,
			a.z + (b.z - a.z) * t
		);
	}

	Vec3 operator+(const Vec3& input) const {
		return Vec3{ x + input.x, y + input.y, z + input.z };
	}

	Vec3 operator+(const float& input) const {
		return Vec3{ x + input, y + input, z + input };
	}

	Vec3 operator-(const Vec3& input) const {
		return Vec3{ x - input.x, y - input.y, z - input.z };
	}

	Vec3 operator/(float input) const {
		return Vec3{ x / input, y / input, z / input };
	}

	Vec3 operator*(float input) const {
		return Vec3{ x * input, y * input, z * input };
	}

	Vec3 operator*(Vec3 input) const {
		return Vec3{ x * input.x, y * input.y, z * input.z };
	}

	Vec3 operator/(Vec3 input) const {
		return Vec3{ x / input.x, y / input.y, z / input.z };
	}

	bool operator>(float input) const
	{
		if (x > input) return true;
		if (y > input) return true;
		if (z > input) return true;
		return false;
	}

	bool operator<(float input) const
	{
		if (x < input) return true;
		if (y < input) return true;
		if (z < input) return true;
	}

	float& operator[](int i) {
		return ((float*)this)[i];
	}

	float operator[](int i) const {
		return ((float*)this)[i];
	}

	Vec3& operator-=(const Vec3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}

	Vec3& operator+=(const Vec3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vec3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}

	Vec3& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		return *this;
	}

	bool operator==(const Vec3& input) const {
		return x == input.x && y == input.y && z == input.z;
	}
	bool operator!=(const Vec3& input) const {
		if (x != input.x || y != input.y || z != input.z)
			return true;

		return false;
	}

	void make_absolute() {
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
	}

	float UnityMagnitude()
	{
		return (float)sqrt((double)(this->x * this->x + this->y * this->y + this->z * this->z));
	}

	float magnitude2d()
	{
		return sqrt(x * x + z * z);
		//return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float magnitude()
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float length_sqr() const {
		return (x * x) + (y * y) + (z * z);
	}

	float length() const {
		return std::sqrt(length_sqr());
	}

	float length_2d() const {
		return std::sqrt((x * x) + (y * y));
	}

	void UnityNormalize()
	{
		Vec3 tis(x, y, z);
		float num = Vec3(x, y, z).magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vec3().Zero();
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;
	}

	Vec3 normalized() const {
		return { x / length(), y / length(), z / length() };
	}

	Vec3 midPoint(Vec3 v2) {
		return Vec3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
	}

	float dot_product(float input) const {
		return (x * input) + (y * input) + (z * input);
	}

	float dot_product(Vec3 input) const {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}

	float distance(Vec3 input) const {
		return (*this - input).length();
	}

	float distance_2d(Vec3 input) const {
		return (*this - input).length_2d();
	}


	bool empty() const {
		return x == 0.f && y == 0.f && z == 0.f;
	}

	inline float UnityDot(Vec3 lhs, Vec3 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	inline float Dot(const Vec3& Vec2) {
		return this->x * Vec2.x + this->y * Vec2.y + this->z * Vec2.z;
	}

	inline Vec3 Cross(const Vec3& Vec2) {
		return Vec3(this->y * Vec2.z - this->z * Vec2.y, this->z * Vec2.x - this->x * Vec2.z, this->x * Vec2.y - this->y * Vec2.x);
	}

	inline float Distance(const Vec3& Dst) {
		return sqrtf(pow((this->x - Dst.x), 2) + pow((this->y - Dst.y), 2) + pow((this->z - Dst.z), 2));
	}
};