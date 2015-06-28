#include "horizontal.h"
Horizontal::Horizontal(){}
Horizontal::~Horizontal(){}
int Horizontal::condition(SquareMap *a[10][10],SquareMap *focus)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    if(num!=0&&num!=7){
        if(num<10){
            if(R>=1&&R<=7&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10)
            {return 1;}
            if(R>=2&&R<=8&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10)
            {return 2;}
        }
        else if(num>10){
            num%=10;
            if(R>=1&&R<=7&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10)
            {return 3;}
            if(R>=2&&R<=8&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10)
            {return 4;}
        }
    }
    return 0;
}
void Horizontal::spawn(SquareMap *a[10][10],SquareMap *focus,int mode)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    int Fournum[4]={0};
    switch(mode)
    {
    case 1:
        if(a[R-1][C]->number>10){Fournum[0]=a[R-1][C]->number/10;}
        if(a[R+1][C]->number>10){Fournum[2]=a[R+1][C]->number/10;}
        if(a[R+2][C]->number>10){Fournum[3]=a[R+2][C]->number/10;}
        for(int i=0;i<4;i++)
        {
            Destroy *d;
            switch(Fournum[i])
            {
                case 0:a[R+i-1][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 7:
                    d=new Star;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
            }
        }
        focus->number=num%10+10;
        break;
    case 2:
        if(a[R-2][C]->number>10){Fournum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fournum[1]=a[R-1][C]->number/10;}
        if(a[R+1][C]->number>10){Fournum[3]=a[R+1][C]->number/10;}
        for(int i=0;i<4;i++)
        {
            Destroy *d;
            switch(Fournum[i])
            {
                case 0:a[R+i-2][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-2][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R+i-2][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+i-2][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-2][C]);
                delete d;
                break;
            }
        }
        focus->number=num%10+10;
        break;
    case 3:
        num%=10;
        if(a[R-1][C]->number>10){Fournum[0]=a[R-1][C]->number/10;}
        Fournum[1]=a[R][C]->number/10;
        if(a[R+1][C]->number>10){Fournum[2]=a[R+1][C]->number/10;}
        if(a[R+2][C]->number>10){Fournum[3]=a[R+2][C]->number/10;}
        for(int i=0;i<4;i++)
        {
            Destroy *d;
            switch(Fournum[i])
            {
                case 0:a[R+i-1][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-1][C]);
                delete d;
                break;
            }
        }
        focus->number=num%10+10;
        break;
    case 4:
        num%=10;
        if(a[R-2][C]->number>10){Fournum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fournum[1]=a[R-1][C]->number/10;}
        Fournum[2]=a[R][C]->number/10;
        if(a[R+1][C]->number>10){Fournum[3]=a[R+1][C]->number/10;}
        for(int i=0;i<4;i++)
        {
            Destroy *d;
            switch(Fournum[i])
            {
                case 0:a[R+i-2][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-2][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R+i-2][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+i-2][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-2][C]);
                delete d;
                break;
            }
        }
        focus->number=num%10+10;
        break;
    }
}
void Horizontal::eliminate(SquareMap *a[10][10],SquareMap *focus)
{
    int R=focus->row;
    focus->number=0;
    int Tennum[10]={0};
    Destroy *d;
    for(int i=0;i<10;i++)
    {
        if(a[R][i]->number>10){Tennum[i]=a[R][i]->number/10;}
    }
    for(int i=0;i<10;i++)
    {
        switch(Tennum[i])
        {
        case 0:
            a[R][i]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
        }
    }
}
