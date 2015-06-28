#include "nineblock.h"
Nineblock::Nineblock(){}
Nineblock::~Nineblock(){}
int Nineblock::condition(SquareMap *a[10][10],SquareMap *focus)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    if(num!=0&&num!=7){
        /*一般糖果*/
        if(num<10){
            if(R>=2&&C>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
            {return 1;}//_|
            if(R<=7&&C>=2&&num==a[R+2][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
            {return 2;}//┐
            if(R>=2&&C<=7&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R][C+2]->number%10&&num==a[R][C+1]->number%10)
            {return 3;}//|_
            if(R<=7&&C<=7&&num==a[R+2][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C+2]->number%10&&num==a[R][C+1]->number%10)
            {return 4;}//┌
            if(R<=7&&C>=1&&C<=8&&num==a[R+2][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10)
            {return 7;}//ㄒ
            if(R>=1&&R<=8&&C>=2&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
            {return 6;}//-|
            if(R>=2&&C>=1&&C<=8&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10)
            {return 8;}//┴
            if(R>=1&&R<=8&&C<=7&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10)
            {return 5;}//├
        }
        /*特殊糖果*/
        else if(num>10){
            num%=10;
            if(R>=2&&C>=2&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
            {return 9;}//_|
            if(R<=7&&C>=2&&num==a[R+2][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
            {return 10;}//┐
            if(R>=2&&C<=7&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R][C+2]->number%10&&num==a[R][C+1]->number%10)
            {return 11;}//|_
            if(R<=7&&C<=7&&num==a[R+2][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C+2]->number%10&&num==a[R][C+1]->number%10)
            {return 12;}//┌
            if(R<=7&&C>=1&&C<=8&&num==a[R+2][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10)
            {return 15;}//ㄒ
            if(R>=1&&R<=8&&C>=2&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C-2]->number%10&&num==a[R][C-1]->number%10)
            {return 14;}//-|
            if(R>=2&&C>=1&&C<=8&&num==a[R-2][C]->number%10&&num==a[R-1][C]->number%10&&num==a[R][C-1]->number%10&&num==a[R][C+1]->number%10)
            {return 16;}//┴
            if(R>=1&&R<=8&&C<=7&&num==a[R-1][C]->number%10&&num==a[R+1][C]->number%10&&num==a[R][C+1]->number%10&&num==a[R][C+2]->number%10)
            {return 13;}//├
        }
    }
    return 0;
}
void Nineblock::spawn(SquareMap *a[10][10],SquareMap *focus,int mode)
{
    int R=focus->row;
    int C=focus->col;
    int num=focus->number;
    int Fivenum[5]={0};
    switch(mode)
    {
    case 1:
        if(C<=8&&num==a[R][C+1]->number%10){a[R][C+1]->number=0;}
        if(R<=8&&num==a[R+1][C]->number%10){a[R+1][C]->number=0;}
        if(a[R-2][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
                                 //Fivenum[2]=a[R][C]->number;
        if(a[R][C-1]->number>10){Fivenum[3]=a[R][C-1]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[4]=a[R][C-2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-2][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-i+2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 7:
                    d=new Star;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
            }
        }
        focus->number=num%10+30;
        break;
    case 2:
        if(C<=8&&num==a[R][C+1]->number%10){a[R][C+1]->number=0;}
        if(R>=1&&num==a[R-1][C]->number%10){a[R-1][C]->number=0;}
        if(a[R+2][C]->number>10){Fivenum[0]=a[R+2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R+1][C]->number/10;}
                                 //Fivenum[2]=a[R][C]->number;
        if(a[R][C-1]->number>10){Fivenum[3]=a[R][C-1]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[4]=a[R][C-2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+2-i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-i+2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 7:
                    d=new Star;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
            }
        }
        focus->number=num%10+30;
        break;
    case 3:
        if(C>=1&&num==a[R][C-1]->number%10){a[R][C-1]->number=0;}
        if(R<=8&&num==a[R+1][C]->number%10){a[R+1][C]->number=0;}
        if(a[R-2][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
                                 //Fivenum[2]=a[R][C]->number;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 7:
                    d=new Star;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 7:
                    d=new Star;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            }
        }
        focus->number=num%10+30;
        break;
    case 4:
        if(C>=1&&num==a[R][C-1]->number%10){a[R][C-1]->number=0;}
        if(R>=1&&num==a[R+1][C]->number%10){a[R-1][C]->number=0;}
        if(a[R+2][C]->number>10){Fivenum[0]=a[R+2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R+1][C]->number/10;}
                                 //Fivenum[2]=a[R][C]->number;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+2-i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 5:
        if(a[R-1][C]->number>10){Fivenum[0]=a[R-1][C]->number/10;}
                                 //Fivenum[1]=a[R][C]->number;
        if(a[R+1][C]->number>10){Fivenum[2]=a[R+1][C]->number/10;}
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+i-1][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 2:
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
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 6:
        if(a[R-1][C]->number>10){Fivenum[0]=a[R-1][C]->number/10;}
                                 //Fivenum[1]=a[R][C]->number;
        if(a[R+1][C]->number>10){Fivenum[2]=a[R+1][C]->number/10;}
        if(a[R][C-1]->number>10){Fivenum[3]=a[R][C-1]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[4]=a[R][C-2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+i-1][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 2:
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
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-i+2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C-i+2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;break;
    case 7:
        if(a[R-1][C]->number>10){Fivenum[0]=a[R+2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R+1][C]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[2]=a[R][C-1]->number/10;}
                                 //Fivenum[3]=a[R][C]->number;
        if(a[R][C-1]->number>10){Fivenum[4]=a[R][C+1]->number/10;}
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+2-i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int i=2;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-3]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-3]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;break;
    case 8:
        if(a[R-1][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[2]=a[R][C-1]->number/10;}
                                 //Fivenum[3]=a[R][C]->number;
        if(a[R][C-1]->number>10){Fivenum[4]=a[R][C+1]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-2][C]);
                delete d;
                break;
            }
        }
        for(int i=2;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-3]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-3]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;break;
    case 9:
        num%=10;
        if(C<=8&&num==a[R][C+1]->number%10){a[R][C+1]->number=0;}
        if(R<=8&&num==a[R+1][C]->number%10){a[R+1][C]->number=0;}
        if(a[R-2][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
                                 Fivenum[2]=a[R][C]->number/10;
        if(a[R][C-1]->number>10){Fivenum[3]=a[R][C-1]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[4]=a[R][C-2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-2][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-i+2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C-i+2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 10:
        num%=10;
        if(C<=8&&num==a[R][C+1]->number%10){a[R][C+1]->number=0;}
        if(R>=1&&num==a[R-1][C]->number%10){a[R-1][C]->number=0;}
        if(a[R+2][C]->number>10){Fivenum[0]=a[R+2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R+1][C]->number/10;}
                                 Fivenum[2]=a[R][C]->number/10;
        if(a[R][C-1]->number>10){Fivenum[3]=a[R][C-1]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[4]=a[R][C-2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+2-i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-i+2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C-i+2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 11:
        num%=10;
        if(C>=1&&num==a[R][C-1]->number%10){a[R][C-1]->number=0;}
        if(R<=8&&num==a[R+1][C]->number%10){a[R+1][C]->number=0;}
        if(a[R-2][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R-1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
                                 Fivenum[2]=a[R][C]->number/10;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 12:
        num%=10;
        if(C>=1&&num==a[R][C-1]->number%10){a[R][C-1]->number=0;}
        if(R>=1&&num==a[R+1][C]->number%10){a[R-1][C]->number=0;}
        if(a[R+2][C]->number>10){Fivenum[0]=a[R+2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R+1][C]->number/10;}
                                 Fivenum[2]=a[R][C]->number/10;
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+2-i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 13:
        num%=10;
        if(a[R-1][C]->number>10){Fivenum[0]=a[R-1][C]->number/10;}
                                 Fivenum[1]=a[R][C]->number/10;
        if(a[R+1][C]->number>10){Fivenum[2]=a[R+1][C]->number/10;}
        if(a[R][C+1]->number>10){Fivenum[3]=a[R][C+1]->number/10;}
        if(a[R][C+2]->number>10){Fivenum[4]=a[R][C+2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+i-1][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 2:
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
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 14:
        num%=10;
        if(a[R-1][C]->number>10){Fivenum[0]=a[R-1][C]->number/10;}
                                 Fivenum[1]=a[R][C]->number/10;
        if(a[R+1][C]->number>10){Fivenum[2]=a[R+1][C]->number/10;}
        if(a[R][C-1]->number>10){Fivenum[3]=a[R][C-1]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[4]=a[R][C-2]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+i-1][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+i-1][C]);
                    delete d;
                    break;
                case 2:
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
        for(int i=3;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C-i+2]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C-i+2]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C-i+2]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    case 15:
        num%=10;
        if(a[R-1][C]->number>10){Fivenum[0]=a[R+2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R+1][C]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[2]=a[R][C-1]->number/10;}
                                 Fivenum[3]=a[R][C]->number/10;
        if(a[R][C-1]->number>10){Fivenum[4]=a[R][C+1]->number/10;}
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R+2-i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R+2-i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int i=2;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-3]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-3]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;break;
    case 16:
        num%=10;
        if(a[R-1][C]->number>10){Fivenum[0]=a[R-2][C]->number/10;}
        if(a[R+1][C]->number>10){Fivenum[1]=a[R-1][C]->number/10;}
        if(a[R][C-2]->number>10){Fivenum[2]=a[R][C-1]->number/10;}
                                 Fivenum[3]=a[R][C]->number/10;
        if(a[R][C-1]->number>10){Fivenum[4]=a[R][C+1]->number/10;}
        for(int i=0;i<3;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R-2+i][C]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R-2+i][C]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R+i-2][C]);
                delete d;
                break;
            }
        }
        for(int i=2;i<5;i++)
        {
            Destroy *d;
            switch(Fivenum[i])
            {
                case 0:a[R][C+i-3]->number=0;break;
                case 1:
                    d=new Vertical;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 2:
                    d=new Horizontal;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
                case 3:
                    d=new Nineblock;
                    d->eliminate(a,a[R][C+i-3]);
                    delete d;
                    break;
            case 7:
                d=new Star;
                d->eliminate(a,a[R][C+i-3]);
                delete d;
                break;
            }
        }
        focus->number=num%10+30;
        break;
    }
}
void Nineblock::eliminate(SquareMap *a[10][10],SquareMap *focus)
{
    int R=focus->row;
    int C=focus->col;
    focus->number=0;
    Destroy *d;
    int Eightnum[8]={0};
    if(R>=1&&C>=1&&a[R-1][C-1]->number>10){Eightnum[0]=a[R-1][C-1]->number/10;}
    if(R>=1&&a[R-1][C]->number>10){Eightnum[1]=a[R-1][C]->number/10;}
    if(R>=1&&C<=8&&a[R-1][C+1]->number>10){Eightnum[2]=a[R-1][C+1]->number/10;}
    if(C>=1&&a[R][C-1]->number>10){Eightnum[3]=a[R][C-1]->number/10;}
    if(C<=8&&a[R][C+1]->number>10){Eightnum[4]=a[R][C+1]->number/10;}
    if(R<=8&&C>=1&&a[R+1][C-1]->number>10){Eightnum[5]=a[R+1][C-1]->number/10;}
    if(R<=8&&a[R+1][C]->number>10){Eightnum[6]=a[R+1][C]->number/10;}
    if(R<=8&&C<=8&&a[R+1][C+1]->number>10){Eightnum[7]=a[R+1][C+1]->number/10;}
    if(R-1>=0&&C-1>=0)
    {
        switch(Eightnum[0])
        {
        case 0:a[R-1][C-1]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R-1][C-1]);
            delete d;
            break;
        }
    }
    if(R-1>=0)
    {
        switch(Eightnum[1])
        {
        case 0:a[R-1][C]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R-1][C]);
            delete d;
            break;
        }
    }
    if(R-1>=0&&C+1<=9)
    {
        switch(Eightnum[2])
        {
        case 0:a[R-1][C-1]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R-1][C+1]);
            delete d;
            break;
        }
    }
    if(C-1>=0)
    {
        switch(Eightnum[3])
        {
        case 0:a[R][C-1]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R][C-1]);
            delete d;
            break;
        }
    }
    if(C+1<=9)
    {
        switch(Eightnum[4])
        {
        case 0:a[R][C+1]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R][C+1]);
            delete d;
            break;
        }
    }
    if(R+1<=9&&C-1>=0)
    {
        switch(Eightnum[5])
        {
        case 0:a[R+1][C-1]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R+1][C-1]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R+1][C-1]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R+1][C-1]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R+1][C-1]);
            delete d;
            break;
        }
    }
    if(R+1<=9)
    {
        switch(Eightnum[6])
        {
        case 0:a[R+1][C]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R+1][C]);
            delete d;
            break;
        }
    }
    if(R+1<=9&&C+1<=9)
    {
        switch(Eightnum[7])
        {
        case 0:a[R+1][C+1]->number=0;break;
        case 2:
            d=new Vertical;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        case 1:
            d=new Horizontal;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        case 3:
            d=new Nineblock;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        case 7:
            d=new Star;
            d->eliminate(a,a[R+1][C+1]);
            delete d;
            break;
        }
    }
}

