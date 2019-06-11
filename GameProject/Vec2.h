#pragma once

#include <iostream>
#include <cassert>

#include "Utils.h"

class Vec2 {
private:
	float mX;
	float mY;

public:
	static const Vec2 Zero;

	Vec2() : Vec2(0, 0) {}
	Vec2(float x, float y) : mX(x), mY(y) {}

	inline void SetX(float x) { mX = x; }
	inline void SetY(float y) { mY = y; }
	inline float GetX() const { return mX; }
	inline float GetY() const { return mY; }

	bool operator==(const Vec2& other) const;
	bool operator!=(const Vec2& other) const;

	float Mag() const;
	float Mag2() const;
	float DotProduct(const Vec2& other) const;
	float Distance(const Vec2& other) const;
	Vec2 ProjectOnto(const Vec2& other) const;
	float AngleBetween(const Vec2& other) const;
	void Rotate(float angle, const Vec2& roundPoint);
	Vec2 RotationResult(float angle, const Vec2& roundPoint);

	Vec2 GetUnitVec() const;
	Vec2& Normalize();
	
	Vec2 operator+(const Vec2& other) const;
	Vec2& operator+=(const Vec2& other);
	Vec2 operator-(const Vec2& other) const;
	Vec2& operator-=(const Vec2& other);
	Vec2 operator*(float scale) const;
	Vec2& operator*=(float scale);
	Vec2 operator/(float scale) const;
	Vec2& operator/=(float scale);
	Vec2 operator-() const;

	friend std::ostream& operator<<(std::ostream& out, const Vec2& vec);
	friend Vec2 operator*(float scale, const Vec2& vec);
};