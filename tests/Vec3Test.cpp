#include <gtest/gtest.h>

#include "Vec3.hpp"

TEST(Vec3Test, DefaultConstructor)
{
    const Vec3 sut;

    EXPECT_FLOAT_EQ(0.f, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(0.f, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(0.f, sut.m_arr[2]);
}

TEST(Vec3Test, OverloadedConstructor)
{
    const float expX = 1.f;
    const float expY = 2.f;
    const float expZ = 3.f;
    const Vec3 sut{expX, expY, expZ};

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);
}

TEST(Vec3Test, XYZGetters)
{
    const float expX = 1.f;
    const float expY = 2.f;
    const float expZ = 3.f;
    Vec3 sut{expX, expY, expZ};

    EXPECT_FLOAT_EQ(expX, sut.x());
    EXPECT_FLOAT_EQ(expY, sut.y());
    EXPECT_FLOAT_EQ(expZ, sut.z());

    // const getters
    const Vec3 sutConst{expX, expY, expZ};

    EXPECT_FLOAT_EQ(expX, sutConst.x());
    EXPECT_FLOAT_EQ(expY, sutConst.y());
    EXPECT_FLOAT_EQ(expZ, sutConst.z());
}

TEST(Vec3Test, XYZSetters)
{
    const float expX = 1.f;
    const float expY = 2.f;
    const float expZ = 3.f;
    Vec3 sut;

    EXPECT_FLOAT_EQ(0.f, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(0.f, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(0.f, sut.m_arr[2]);

    sut.x() = expX;
    sut.y() = expY;
    sut.z() = expZ;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);

}

TEST(Vec3Test, OperatorAssignment)
{
    const float expX = 8.5f;
    const float expY = 4.f;
    const float expZ = 6.f;
    Vec3 a{expX, expY, expZ};

    const Vec3 sut = a;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);
}

TEST(Vec3Test, OperatorAddition)
{
    const float aX = 8.5f;
    const float aY = 4.f;
    const float aZ = 6.f;

    const float bX = 8.5f;
    const float bY = 4.f;
    const float bZ = 6.f;
    
    const float expX = aX + bX;
    const float expY = aY + bY;
    const float expZ = aZ + bZ;
    
    Vec3 a{aX,aY, aZ};
    Vec3 b{bX, bY, bZ};

    Vec3 sut = a + b;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);

    sut = a;
    sut += b;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);
}

TEST(Vec3Test, OperatorSubtraction)
{
    float aX = 8.5f;
    float aY = 4.f;
    float aZ = 6.f;

    float bX = 8.5f;
    float bY = 4.f;
    float bZ = 6.f;
    
    float expX = aX - bX;
    float expY = aY - bY;
    float expZ = aZ - bZ;
    
    Vec3 a{aX,aY, aZ};
    Vec3 b{bX, bY, bZ};

    Vec3 sut = a - b;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);

    sut = a;
    sut -= b;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);

    sut = a;
    expX = aX;
    expY = aY;
    expZ = aZ;

    sut = -sut;

    EXPECT_FLOAT_EQ(-expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(-expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(-expZ, sut.m_arr[2]);
}

TEST(Vec3Test, OperatorMultiplication)
{
    const float a = 8.5f;

    const float bX = 8.5f;
    const float bY = 4.f;
    const float bZ = 6.f;
    
    const float expX = a * bX;
    const float expY = a * bY;
    const float expZ = a * bZ;

    Vec3 b(bX, bY, bZ);

    Vec3 sut = b * a;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);

    sut = Vec3();

    sut = a * b;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);

    sut = b;

    sut *= a;

    EXPECT_FLOAT_EQ(expX, sut.m_arr[0]);
    EXPECT_FLOAT_EQ(expY, sut.m_arr[1]);
    EXPECT_FLOAT_EQ(expZ, sut.m_arr[2]);
}