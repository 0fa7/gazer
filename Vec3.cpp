#include "Vec3.hpp"

Vec3::Vec3() :
    m_arr{0.f, 0.f, 0.f}
{
}

Vec3::Vec3(float x, float y, float z) :
    m_arr{x, y, z}
{
}

float& Vec3::x()
{
    return m_arr[0];
}

const float Vec3::x() const
{
    return m_arr[0];
}

float& Vec3::y()
{
    return m_arr[1];
}

const float Vec3::y() const
{
    return m_arr[1];
}

float& Vec3::z()
{
    return m_arr[2];
}

const float Vec3::z() const
{
    return m_arr[2];
}

Vec3 Vec3::operator-() const
{
    return Vec3(-m_arr[0], -m_arr[1], -m_arr[2]);
}

Vec3& Vec3::operator+=(const Vec3& a)
{
    m_arr[0] += a.m_arr[0];
    m_arr[1] += a.m_arr[1];
    m_arr[2] += a.m_arr[2];
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& a)
{
    m_arr[0] -= a.m_arr[0];
    m_arr[1] -= a.m_arr[1];
    m_arr[2] -= a.m_arr[2];
    return *this;
}

Vec3& Vec3::operator*=(float a)
{
    m_arr[0] *= a;
    m_arr[1] *= a;
    m_arr[2] *= a;
    return *this;
}

Vec3 operator+(const Vec3& a, const Vec3& b)
{
    return(Vec3{a.m_arr[0] + b.m_arr[0],
                a.m_arr[1] + b.m_arr[1],
                a.m_arr[2] + b.m_arr[2]});
}

Vec3 operator-(const Vec3& a, const Vec3& b)
{
    return(Vec3{a.m_arr[0] - b.m_arr[0],
                a.m_arr[1] - b.m_arr[1],
                a.m_arr[2] - b.m_arr[2]});
}

Vec3 operator*(const Vec3& a, float b)
{
    return Vec3(a.m_arr[0] * b,
                a.m_arr[1] * b,
                a.m_arr[2] * b);
}

Vec3 operator*(float a, const Vec3& b)
{
    return Vec3(a * b.m_arr[0],
                a * b.m_arr[1],
                a * b.m_arr[2]);
}