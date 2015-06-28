#include "horizontal3.h"
Horizontal3::Horizontal3(){}
Horizontal3::~Horizontal3(){}
int Horizontal3::condition(SquareMap *a[10][10],SquareMap *focus)
{
     int R=focus->row;
     int C=focus->col;
     int num=focus->number;
     if(num!=0&&num!=7){
         if(num<10){
             if(C>=1&&C<=8&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10)
             {return 1;}
             if(C>=2&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
             {return 2;}
             if(C<=7&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10)
             {return 3;}
         }
         else if(num>10){
             num%=10;
             if(C>=1&&C<=8&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10)
             {return 4;}
             if(C>=2&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
             {return 5;}
             if(C<=7&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10)
             {return 6;}
         }
     }
     return 0;
}
void Horizontal3::spawn(SquareMap *a[10][10],SquareMap *focus,int mode)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    int Threenum[3]={0};
    switch(mode)
    {
    case 1:
        if(a[R][C-1]->number>10){Threenum[0]=a[R][C-1]->number/10;}
        if(a[R][C+1]->number>10){Threenum[2]=a[R][C+1]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R][C+i-1]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-1]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-1]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-1]);
                    delete d;
                    break;
            }
        }
        break;
    case 2:
        if(a[R][C-2]->number>10){Threenum[0]=a[R][C-2]->number/10;}
        if(a[R][C-1]->number>10){Threenum[1]=a[R][C-1]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            }
        }
        break;
    case 3:
        if(a[R][C+1]->number>10){Threenum[1]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Threenum[2]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R][C+i]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i]);
                    delete d;
                    break;
            }
        }
        break;
    case 4:
        num%=10;
        if(a[R][C-1]->number>10){Threenum[0]=a[R][C-1]->number/10;}
        Threenum[1]=a[R][C]->number/10;
        if(a[R][C+1]->number>10){Threenum[2]=a[R][C+1]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R][C+i-1]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-1]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-1]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-1]);
                    delete d;
                    break;
            }
        }
        break;
    case 5:
        num%=10;
        if(a[R][C-2]->number>10){Threenum[0]=a[R][C-2]->number/10;}
        if(a[R][C-1]->number>10){Threenum[1]=a[R][C-1]->number/10;}
        Threenum[2]=a[R][C]->number/10;
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            }
        }
        break;
    case 6:
        num%=10;
        Threenum[0]=a[R][C]->number/10;
        if(a[R][C+1]->number>10){Threenum[1]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Threenum[2]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Threenum[i])
            {
                case 0:a[R][C+i]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i]);
                    delete d;
                    break;
            }
        }
        break;
    }
}
void Horizontal3::eliminate(SquareMap *a[10][10],SquareMap *focus){}

