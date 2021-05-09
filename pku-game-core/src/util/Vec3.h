#ifndef OPEN_CRAFT_VEC3_H
#define OPEN_CRAFT_VEC3_H


class Vec3
{
public:
    float x, y, z;

    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

    Vec3(float x, float y, float z) : x(0.0f), y(0.0f), z(0.0f) {}

    Vec3 operator+(Vec3 const &v) const { return {x + v.x, y + v.y, z + v.z}; }

    Vec3 &operator+=(Vec3 const &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3 operator-(Vec3 const &v) const { return {x - v.x, y - v.y, z - v.z}; }

    Vec3 &operator-=(Vec3 const &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    bool operator<(Vec3 const& v) const
    {
        if(x != v.x)
            return x < v.x;
        if(y != v.y)
            return y < v.y;
        return z < v.z;
    }

    bool operator>(Vec3 const& v) const
    {
        if(x != v.x)
            return x > v.x;
        if(y != v.y)
            return y > v.y;
        return z > v.z;
    }

    bool operator==(Vec3 const& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }
};


#endif //OPEN_CRAFT_VEC3_H
