#ifndef VERTICAL_H
#define VERTICAL_H
#include "destroy.h"
#include "horizontal.h"
#include "nineblock.h"
#include "squaremap.h"
#include "star.h"
class Vertical :public Destroy
{
public:
    Vertical();
    virtual ~Vertical();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus);
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode);
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus);
};

#endif // VERTICAL_H
