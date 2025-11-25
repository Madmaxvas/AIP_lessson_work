#ifndef POINT_HPP
#define POINT_HPP

#include "planar.hpp"

struct Point : Planar
{
    Point(int xx, int yy);

    virtual int x() const override;
    virtual int y() const override;
    virtual int abs_sqr() const override;
    virtual ~Point() = default;

private:
    int data[2];
};

#endif
