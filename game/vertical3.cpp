#include "vertical3.h"
Vertical3::Vertical3(){}
Vertical3::~Vertical3(){}
int Vertical3::condition(SquareMap *a[10][10],SquareMap *focus)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    if(num!=0&&num!=7){
        if(num!=0&&num!=7){
            if(num<10){
                if(R>=1&&R<=8&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10)
                {return 1;}
                if(R>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10)
                {return 2;}
                if(R<=7&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10)
                {return 3;}
            }
            else if(num>10){
                num%=10;
                if(R>=1&&R<=8&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10)
                {return 4;}
                if(R>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10)
                {return 5;}
                if(R<=7&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10)
                {return 6;}
            }
        }
    }
    return 0;
}
void Vertical3::spawn(SquareMap *a[10][10],SquareMap *focus,int mode)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    int Threenum[3]={0};
    switch(mode)
    {
    case 1:
        if(a[R-1][C]->number>10){Threenum[0]=a[R-1][C]->number/10;}
        if(a[R+1][C]->number>10){Threenum[2]=a[R+1][C]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
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
            }
        }
        break;
    case 2:
        if(a[R-2][C]->number>10){Threenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Threenum[1]=a[R-1][C]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
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
            }
        }
        break;
    case 3:
        if(a[R+1][C]->number>10){Threenum[1]=a[R+1][C]->number/10;}
        if(a[R+2][C]->number>10){Threenum[2]=a[R+2][C]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R+i][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R+i][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+i][C]);
                    delete d;
                    break;
            }
        }
        break;
    case 4:
        num%=10;
        if(a[R-1][C]->number>10){Threenum[0]=a[R-1][C]->number/10;}
        Threenum[1]=a[R][C]->number/10;
        if(a[R+1][C]->number>10){Threenum[2]=a[R+1][C]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
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
            }
        }
        break;
    case 5:
        num%=10;
        if(a[R-2][C]->number>10){Threenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Threenum[1]=a[R-1][C]->number/10;}
        Threenum[2]=a[R][C]->number/10;
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
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
            }
        }
        break;
    case 6:
        num%=10;
        Threenum[0]=a[R][C]->number/10;
        if(a[R+1][C]->number>10){Threenum[1]=a[R+1][C]->number/10;}
        if(a[R+2][C]->number>10){Threenum[2]=a[R+2][C]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R+i][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R+i][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+i][C]);
                    delete d;
                    break;
            }
        }
        break;
    }
}
void Vertical3::eliminate(SquareMap *a[10][10],SquareMap *focus){}
