#pragma once

class Vec3
{
public:
    Vec3();
    Vec3(float x, float y, float z);

    float& x();
    const float x() const;
    float& y();
    const float y() const;
    float& z();
    const float z() const;

    Vec3 operator-() const;
    Vec3& operator+=(const Vec3& a);
    Vec3& operator-=(const Vec3& a);

    Vec3& operator*=(float a);

    float m_arr[3];
};

Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);
Vec3 operator*(const Vec3& a, float b);
Vec3 operator*(float a, const Vec3& b);