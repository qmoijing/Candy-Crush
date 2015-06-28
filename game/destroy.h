#ifndef DESTROY_H
#define DESTROY_H
#include"squaremap.h"
class Destroy
{
public:
    Destroy();
    virtual ~Destroy();
    virtual int condition(SquareMap *a[10][10],SquareMap *focus)=0;
    virtual void spawn(SquareMap *a[10][10],SquareMap *focus,int mode)=0;
    virtual void eliminate(SquareMap *a[10][10],SquareMap *focus)=0;
};

#endif // DESTROY_H
