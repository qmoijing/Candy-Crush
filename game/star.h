#ifndef STAR_H
#define STAR_H
#include "squaremap.h"
#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"
#include <ctime>
class Star:public Destroy
{
public:
    Star();
    virtual ~Star();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus);
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode);
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus);
};

#endif // STAR_H
