#ifndef NINEBLOCK_H
#define NINEBLOCK_H
#include "destroy.h"
#include "horizontal.h"
#include "destroy.h"
#include "vertical.h"
#include "star.h"
class Nineblock:public Destroy
{
public:
    Nineblock();
    virtual ~Nineblock();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus);
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode);
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus);
};

#endif // NINEBLOCK_H
