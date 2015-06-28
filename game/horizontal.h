#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "squaremap.h"
#include "destroy.h"
#include "vertical.h"
#include "nineblock.h"
#include "star.h"
class Horizontal:public Destroy
{
public:
    Horizontal();
    virtual ~Horizontal();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus);
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode);
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus);
};

#endif // HORIZONTAL_H
