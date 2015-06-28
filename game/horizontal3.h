#ifndef HORIZONTAL3_H
#define HORIZONTAL3_H
#include "squaremap.h"
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"
class Horizontal3:public Destroy
{
public:
    Horizontal3();
    virtual ~Horizontal3();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus);
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode);
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus);
};

#endif // HORIZONTAL3_H
