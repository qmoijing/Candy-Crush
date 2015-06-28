#include "star.h"
Star::Star(){}
Star::~Star(){}
int Star::condition(SquareMap *a[10][10],SquareMap *focus)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    if(num!=0&&num!=7){
        if(num<10){
            if(R>=2&&R<=7&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10)
            {return 1;}
            if(C>=2&&C<=7&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10)
            {return 2;}
        }
        else if(num>10){
            num%=10;
            if(R>=2&&R<=7&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10)
            {return 3;}
            if(C>=2&&C<=7&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10)
            {return 4;}
        }
    }
    return 0;
}
void Star::spawn(SquareMap *a[10][10],SquareMap *focus,int mode)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    int Fivenum[5]={0};
    switch(mode)
    {
        case 1:
        focus->number=7;
        if(C>=2&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10){a[R][C-2]->number=0;a[R][C-1]->number=0;}
        if(C<=7&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10){a[R][C+1]->number=0;a[R][C+2]->number=0;}
        if(a[R-2][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
        Fivenum[2]=a[R][C]->number;
        if(a[R+1][C]->number>10){Fivenum[3]=a[R+1][C]->number/10;}
        if(a[R+2][C]->number>10){Fivenum[4]=a[R+2][C]->number/10;}
        for(int i=0;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 2:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 1:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            }
        }
        break;
        case 2:
        focus->number=7;
        if(R>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10){a[R-2][C]->number=0;a[R-1][C]->number=0;}
        if(R<=7&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10){a[R+1][C]->number=0;a[R+2][C]->number=0;}
        if(a[R][C-2]->number>10){Fivenum[0]=a[R][C-2]->number/10;}
        if(a[R][C-1]->number>10){Fivenum[1]=a[R][C-1]->number/10;}
        Fivenum[2]=a[R][C]->number;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-2+i]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
            }
        }
        break;
        case 3:
        focus->number=7;
        num%=10;
        if(R>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10){a[R-2][C]->number=0;a[R-1][C]->number=0;}
        if(R<=7&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10){a[R+1][C]->number=0;a[R+2][C]->number=0;}
        if(a[R][C-2]->number>10){Fivenum[0]=a[R][C-2]->number/10;}
        if(a[R][C-1]->number>10){Fivenum[1]=a[R][C-1]->number/10;}
        Fivenum[2]=a[R][C]->number/10;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-2+i]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
            }
        }
        break;
        case 4:
        focus->number=7;
        num%=10;
        if(R>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10){a[R-2][C]->number=0;a[R-1][C]->number=0;}
        if(R<=7&&num==a[R+1][C]->number%10&&num==a[R+2][C]->number%10){a[R+1][C]->number=0;a[R+2][C]->number=0;}
        if(a[R][C-2]->number>10){Fivenum[0]=a[R][C-2]->number/10;}
        if(a[R][C-1]->number>10){Fivenum[1]=a[R][C-1]->number/10;}
        Fivenum[2]=a[R][C]->number/10;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-2+i]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-2+i]);
                    delete d;
                    break;
            }
        }
    }
}
void Star::eliminate(SquareMap *a[10][10],SquareMap *focus)
{
    int number=rand()%6+1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]->number%10==number){a[i][j]->number=0;}
        }
    }
}
