#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "planar.hpp"
#include "point.hpp"

struct Vector : Planar
{
    Vector(Point start, Point end);

    virtual int x() const override;
    virtual int y() const override;
    virtual int abs_sqr() const override;
    virtual ~Vector() = default;

private:
    Point a;
    Point b;
};

#endif
