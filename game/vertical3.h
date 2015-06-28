#ifndef VERTICAL3_H
#define VERTICAL3_H
#include "squaremap.h"
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"
class Vertical3:public Destroy
{
public:
    Vertical3();
    virtual ~Vertical3();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus);
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode);
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus);
};

#endif // VERTICAL3_H
