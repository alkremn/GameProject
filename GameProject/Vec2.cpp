#include "Vec2.h"

const Vec2 Vec2::Zero;

std::ostream& operator<<(std::ostream& out, const Vec2& vec) {
	out << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
	return out;
}

bool Vec2::operator==(const Vec2& other) const
{
	return IsEqual(mX, other.mX) && IsEqual(mY, other.mY);
}
bool Vec2::operator!=(const Vec2& other) const
{
	return !(*this == other);
}

Vec2 Vec2::operator+(const Vec2& other) const
{
	return Vec2(mX + other.mX, mY + other.mY);
}
Vec2& Vec2::operator+=(const Vec2& other)
{
	*this = *this + other;
	return *this;
}

Vec2 Vec2::operator-() const
{
	return Vec2(-mX, -mY);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
	return Vec2(mX - other.mX, mY - other.mY);
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	*this = *this - other;
	return *this;
}

Vec2 Vec2::operator*(float scale) const
{
	return Vec2(mX * scale, mY * scale);
}


Vec2& Vec2::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vec2 operator*(float scale, const Vec2& vec)
{
	return vec * scale;
}


Vec2 Vec2::operator/(float scale) const
{
	assert(fabsf(scale) > EPSILON);

	return Vec2(mX / scale, mY / scale);
}


Vec2& Vec2::operator/=(float scale)
{
	*this = *this / scale;
	return *this;
}

float Vec2::Mag() const
{
	return sqrt(Mag2());
}
float Vec2::Mag2() const
{
	return DotProduct(*this);
}

float Vec2::DotProduct(const Vec2& other) const
{
	return mX * other.mX + mY * other.mY;
}

Vec2 Vec2::GetUnitVec() const
{
	float mag = Mag();
	if (mag > EPSILON)
	{
		return *this / mag;
	}
	return Vec2::Zero;
}

Vec2& Vec2::Normalize()
{
	*this = GetUnitVec();
	return *this;
}

float Vec2::Distance(const Vec2& other) const
{
	return (other - *this).Mag();
}

Vec2 Vec2::ProjectOnto(const Vec2& other) const
{
	Vec2 unitVecOther = other.GetUnitVec();
	float dot = DotProduct(unitVecOther);
	return unitVecOther * dot;
}

float Vec2::AngleBetween(const Vec2& other) const
{
	return acosf(GetUnitVec().DotProduct(other.GetUnitVec()));
}

void Vec2::Rotate(float angle, const Vec2& aroundPoint)
{
	float sine = sinf(angle);
	float cosine = cosf(angle);

	Vec2 ourPosition = *this - aroundPoint;

	float xRot = ourPosition.mX * cosine - ourPosition.mY * sine;
	float yRot = ourPosition.mX * sine + ourPosition.mY * cosine;
	*this = Vec2(xRot, yRot) + aroundPoint;
}

Vec2 Vec2::RotationResult(float angle, const Vec2& aroundPoint)
{
	float sine = sinf(angle);
	float cosine = cosf(angle);

	Vec2 ourPosition = *this - aroundPoint;
	
	float xRot = ourPosition.mX * cosine - ourPosition.mY * sine;
	float yRot = ourPosition.mX * sine + ourPosition.mY * cosine;

	return Vec2(xRot, yRot) + aroundPoint;
}
