#include <iostream>
#include <stdexcept>
#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"

Planar* make(size_t id);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);
Planar* most_left(Planar** pls, size_t k);

int main()
{
    Planar* pls[10] = {};
    size_t k = 0;

    for (size_t i = 0; i < 10; ++i)
    {
        try
        {
            pls[k] = make(i % 2);
            k++;
        }
        catch (...)
        {
            free_planars(pls, k);
            return 2;
        }
    }

    Planar* left = most_left(pls, k);
    if (left)
    {
        draw(left);
    }

    free_planars(pls, k);
    return 0;
}

Planar* make(size_t id)
{
    switch (id)
    {
    case 0:
        return new Point(10, 5);
    case 1:
        return new Vector(Point(0, 0), Point(-3, 4));
    default:
        throw std::logic_error("bad id");
    }
}

void free_planars(Planar** pls, size_t k)
{
    for (size_t i = 0; i < k; ++i)
    {
        delete pls[i];
        pls[i] = nullptr;
    }
}

void draw(Planar* pl)
{
    std::cout << pl->x() << " " << pl->y() << "\n";
}

Planar* most_left(Planar** pls, size_t k)
{
    if (k == 0) return nullptr;

    Planar* min_obj = pls[0];
    for (size_t i = 1; i < k; ++i)
    {
        if (pls[i]->x() < min_obj->x())
        {
            min_obj = pls[i];
        }
    }
    return min_obj;
}
