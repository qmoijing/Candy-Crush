#include "game.h"
#include "ui_game.h"
game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    mainWindow=parent;
    ui->label_3->setText("Target:");
    ui->label_4->setText("Get 400 scores in 40 steps");
    step=40;
    Score=0;
    score();
    Step();
    Stars();
    srand(time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            gameSquare[i][j]=new SquareMap(this,i,j);
            connect(gameSquare[i][j],SIGNAL(Click(int,int)),this,SLOT(SquareClick(int,int)));
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            gameSquare[i][j]->setnumber();
            gameSquare[i][j]->setpicture();
            if(j>=2&&gameSquare[i][j]->number==gameSquare[i][j-2]->number&&gameSquare[i][j]->number==gameSquare[i][j-1]->number)
                j--;
            if(i>=2&&gameSquare[i][j]->number==gameSquare[i-2][j]->number&&gameSquare[i][j]->number==gameSquare[i-1][j]->number)
                j--;
        }
    }
}
game::~game()
{
    emit quit(stars,Score);
    delete ui;
}
void game::SquareClick(int R,int C)
{
    if(!isClicked){
        isClicked=true;
        record_R=R;
        record_C=C;
    }else{
        if(record_R==R&&C-1==record_C){
            *gameSquare[record_R][record_C]-gameSquare[R][C];
            if(!Judge(record_R,record_C,R,C)){*gameSquare[R][C]-gameSquare[record_R][record_C];}
            else{done();}
        }
        else if(record_R==R&&C+1==record_C){
            *gameSquare[R][C]-gameSquare[record_R][record_C];
            if(!Judge(record_R,record_C,R,C)){*gameSquare[record_R][record_C]-gameSquare[R][C];}
            else{done();}
        }
        else if (R-1==record_R&&record_C==C){
            *gameSquare[record_R][record_C]-gameSquare[R][C];
            if(!Judge(record_R,record_C,R,C)){*gameSquare[R][C]-gameSquare[record_R][record_C];}
            else{done();}
        }
        else if(R+1==record_R&&record_C==C){
            *gameSquare[R][C]-gameSquare[record_R][record_C];
            if(!Judge(record_R,record_C,R,C)){*gameSquare[record_R][record_C]-gameSquare[R][C];}
            else{done();}
        }
        isClicked=false;
    }
}
bool game::Judge(int first_row,int first_col,int second_row,int second_col)
{
    int result[17]={0};
    result[0]=JudgeTwoStar(first_row,first_col,second_row,second_col);
    result[1]=JudgeOneStar(first_row,first_col,second_row,second_col);
    result[2]=JudgeOneStar(second_row,second_col,first_row,first_col);
    result[3]=Judgestripe2(first_row,first_col,second_row,second_col);
    result[4]=JudgeHcrossV(first_row,first_col,second_row,second_col);
    result[5]=JudgeStar(first_row,first_col);
    result[6]=JudgeStar(second_row,second_col);
    result[7]=Judge9(first_row,first_col);
    result[8]=Judge9(second_row,second_col);
    result[9]=JudgeHorizontal(first_row,first_col);
    result[10]=JudgeHorizontal(second_row,second_col);
    result[11]=JudgeVertical(first_row,first_col);
    result[12]=JudgeVertical(second_row,second_col);
    result[13]=JudgeHorizontal3(first_row,first_col);
    result[14]=JudgeHorizontal3(second_row,second_col);
    result[15]=JudgeVertical3(first_row,first_col);
    result[16]=JudgeVertical3(second_row,second_col);
    reNewPicture();
    for(int i=0;i<17;i++){if(result[i]==true){return true;}}
    return false;
}
bool game::JudgeTwoStar(int R1,int C1,int R2,int C2)
{
    if(gameSquare[R1][C1]->number==7&&gameSquare[R2][C2]->number==7)
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                gameSquare[i][j]->setnumber();
                gameSquare[i][j]->setpicture();
                if(j>=2&&gameSquare[i][j]->number==gameSquare[i][j-2]->number&&gameSquare[i][j]->number==gameSquare[i][j-1]->number)
                    j--;
                if(i>=2&&gameSquare[i][j]->number==gameSquare[i-2][j]->number&&gameSquare[i][j]->number==gameSquare[i-1][j]->number)
                    j--;
            }
        }
        Score=Score+100;
        return true;
    }
    return false;
}
bool game::JudgeOneStar(int R1,int C1,int R2,int C2)
{
    if(gameSquare[R1][C1]->number==7)
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(i!=R2||j!=C2){
                    if(gameSquare[i][j]->number%10==gameSquare[R2][C2]->number%10)
                    {
                        gameSquare[i][j]->number=0;
                    }
                }
            }
        }
        gameSquare[R1][C1]->number=0;
        gameSquare[R2][C2]->number=0;
        Score=Score+60;
        return true;
    }
    return false;
}
bool game::Judgestripe2(int R1,int C1,int R2,int C2)
{
    if(gameSquare[R1][C1]->number/10==1&&gameSquare[R2][C2]->number/10==2)
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(i==R1)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
                if(j==C2)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
            }
        }
        Score=Score+40;
        return true;
    }
    if(gameSquare[R1][C1]->number/10==2&&gameSquare[R2][C2]->number/10==1)
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(i==R2)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
                if(j==C1)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
            }
        }
        Score=Score+40;
        return true;
    }
    return false;
}
bool game::JudgeHcrossV(int R1,int C1,int R2,int C2)
{
    if((gameSquare[R1][C1]->number/10==1||gameSquare[R1][C1]->number/10==2)&&gameSquare[R2][C2]->number/10==3)
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(abs(i-R2)<=1)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
                if(abs(j-C2)<=1)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
            }
        }
        Score=Score+40;
        return true;
    }
    if((gameSquare[R2][C2]->number/10==1||gameSquare[R2][C2]->number/10==2)&&gameSquare[R1][C1]->number/10==3)
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(abs(i-R2)<=1)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
                if(abs(j-C2)<=1)
                {
                    int value=gameSquare[i][j]->number/10;
                    Destroy *d;
                    switch(value)
                    {
                    case 0:gameSquare[i][j]->number=0;break;
                    case 1:
                        d=new Vertical;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 2:
                        d=new Horizontal;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 3:
                        d=new Nineblock;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    case 7:
                        d=new Star;
                        d->eliminate(gameSquare,gameSquare[i][j]);
                        delete d;
                        break;
                    }
                }
            }
        }
        Score=Score+40;
        return true;
    }
    return false;
}
bool game::JudgeStar(int R,int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Star;
    return_value=destroy->condition(gameSquare,gameSquare[R][C]);
    if(return_value){
        switch(return_value)
        {
               case 1:
               destroy->spawn(gameSquare,gameSquare[R][C],1);
               AnySpawn=true;
               Score=Score+30;
               break;
               case 2:
               destroy->spawn(gameSquare,gameSquare[R][C],2);
               AnySpawn=true;
               Score=Score+30;
               break;
               case 3:
               destroy->spawn(gameSquare,gameSquare[R][C],3);
               AnySpawn=true;
               Score=Score+40;
               break;
               case 4:
               destroy->spawn(gameSquare,gameSquare[R][C],4);
               AnySpawn=true;
               Score=Score+40;
               break;
         }
         delete destroy;
         return AnySpawn;
    }
}
bool game::Judge9(int R,int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Nineblock;
    return_value=destroy->condition(gameSquare,gameSquare[R][C]);
    if(return_value){
        switch(return_value)
        {
        case 1:
            destroy->spawn(gameSquare,gameSquare[R][C],1);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 2:
            destroy->spawn(gameSquare,gameSquare[R][C],2);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 3:
            destroy->spawn(gameSquare,gameSquare[R][C],3);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 4:
            destroy->spawn(gameSquare,gameSquare[R][C],4);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 5:
            destroy->spawn(gameSquare,gameSquare[R][C],5);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 6:
            destroy->spawn(gameSquare,gameSquare[R][C],6);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 7:
            destroy->spawn(gameSquare,gameSquare[R][C],7);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 8:
            destroy->spawn(gameSquare,gameSquare[R][C],8);
            Score=Score+15;
            AnySpawn=true;
            break;
        case 9:
            destroy->spawn(gameSquare,gameSquare[R][C],9);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 10:
            destroy->spawn(gameSquare,gameSquare[R][C],10);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 11:
            destroy->spawn(gameSquare,gameSquare[R][C],11);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 12:
            destroy->spawn(gameSquare,gameSquare[R][C],12);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 13:
            destroy->spawn(gameSquare,gameSquare[R][C],13);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 14:
            destroy->spawn(gameSquare,gameSquare[R][C],14);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 15:
            destroy->spawn(gameSquare,gameSquare[R][C],15);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 16:
            destroy->spawn(gameSquare,gameSquare[R][C],16);
            AnySpawn=true;
            Score=Score+20;
            break;
        }
        delete destroy;
        return AnySpawn;
    }
}
bool game::JudgeHorizontal(int R,int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Horizontal;
    return_value=destroy->condition(gameSquare,gameSquare[R][C]);
    if(return_value){
        switch(return_value)
        {
        case 1:
            destroy->spawn(gameSquare,gameSquare[R][C],1);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 2:
            destroy->spawn(gameSquare,gameSquare[R][C],2);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 3:
            destroy->spawn(gameSquare,gameSquare[R][C],3);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 4:
            destroy->spawn(gameSquare,gameSquare[R][C],4);
            AnySpawn=true;
            Score=Score+20;
            break;
        }
        delete destroy;
        return AnySpawn;
    }
}
bool game::JudgeVertical(int R,int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Vertical;
    return_value=destroy->condition(gameSquare,gameSquare[R][C]);
    if(return_value){
        switch(return_value)
        {
        case 1:
            destroy->spawn(gameSquare,gameSquare[R][C],1);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 2:
            destroy->spawn(gameSquare,gameSquare[R][C],2);
            AnySpawn=true;
            Score=Score+15;
            break;
        case 3:
            destroy->spawn(gameSquare,gameSquare[R][C],3);
            AnySpawn=true;
            Score=Score+20;
            break;
        case 4:
            destroy->spawn(gameSquare,gameSquare[R][C],4);
            AnySpawn=true;
            Score=Score+20;
            break;
        }
        delete destroy;
        return AnySpawn;
    }
}
bool game::JudgeHorizontal3(int R,int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Horizontal3;
    return_value=destroy->condition(gameSquare,gameSquare[R][C]);
    if(return_value){
        switch(return_value)
        {
        case 1:
            destroy->spawn(gameSquare,gameSquare[R][C],1);
            AnySpawn=true;
            Score=Score+5;
            break;
        case 2:
            destroy->spawn(gameSquare,gameSquare[R][C],2);
            AnySpawn=true;
            Score=Score+5;
            break;
        case 3:
            destroy->spawn(gameSquare,gameSquare[R][C],3);
            AnySpawn=true;
            Score=Score+5;
            break;
        case 4:
            destroy->spawn(gameSquare,gameSquare[R][C],4);
            AnySpawn=true;
            Score=Score+10;
            break;
        case 5:
            destroy->spawn(gameSquare,gameSquare[R][C],5);
            AnySpawn=true;
            Score=Score+10;
            break;
        case 6:
            destroy->spawn(gameSquare,gameSquare[R][C],6);
            AnySpawn=true;
            Score=Score+10;
            break;
        }
        delete destroy;
        return AnySpawn;
    }
}
bool game::JudgeVertical3(int R,int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy=new Vertical3;
    return_value=destroy->condition(gameSquare,gameSquare[R][C]);
    if(return_value){
        switch(return_value)
        {
        case 1:
            destroy->spawn(gameSquare,gameSquare[R][C],1);
            AnySpawn=true;
            Score=Score+5;
            break;
        case 2:
            destroy->spawn(gameSquare,gameSquare[R][C],2);
            AnySpawn=true;
            Score=Score+5;
            break;
        case 3:
            destroy->spawn(gameSquare,gameSquare[R][C],3);
            AnySpawn=true;
            Score=Score+5;
            break;
        case 4:
            destroy->spawn(gameSquare,gameSquare[R][C],4);
            AnySpawn=true;
            Score=Score+10;
            break;
        case 5:
            destroy->spawn(gameSquare,gameSquare[R][C],5);
            Score=Score+10;
            AnySpawn=true;
            break;
        case 6:
            destroy->spawn(gameSquare,gameSquare[R][C],6);
            AnySpawn=true;
            Score=Score+10;
            break;
        }
        delete destroy;
        return AnySpawn;
    }
}
void game::reNewPicture()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            gameSquare[i][j]->setpicture();
        }
}
void game::fillinzero()
{
    for(int j=0;j<10;j++)
    {
        for(int i=8;i>=0;i--)
        {
            if(gameSquare[i][j]->number!=0)
            {
                int count=0;
                for(int k=9;k>i;k--)
                {
                    if(gameSquare[k][j]->number==0){count++;}
                }
                if(count!=0)
                {
                    gameSquare[i+count][j]->number=gameSquare[i][j]->number;
                    gameSquare[i][j]->number=0;
                }
            }
        }
    }
}
bool game::Eliminatepossibility()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeStar(i,j)){return true;}
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(Judge9(i,j)){return true;}
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeHorizontal(i,j)){return true;}
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeVertical(i,j)){return true;}
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeHorizontal3(i,j)){return true;}
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(JudgeVertical3(i,j)){return true;}
        }
    }
}
void game::spawnforzero()
{
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            if(gameSquare[i][j]->number==0){
                gameSquare[i][j]->setnumber();
                gameSquare[i][j]->setpicture();
                if(j<=7&&gameSquare[i][j]->number==gameSquare[i][j+2]->number&&gameSquare[i][j]->number==gameSquare[i][j+1]->number)
                    j++;
                if(i<=7&&gameSquare[i][j]->number==gameSquare[i+2][j]->number&&gameSquare[i][j]->number==gameSquare[i+1][j]->number)
                    j++;
            }
        }
    }
}
bool game::cannotplay()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            *gameSquare[i][j]-gameSquare[i][j+1];
            int return_value;
            destroy=new Horizontal3;
            return_value=destroy->condition(gameSquare,gameSquare[i][j]);
            if(return_value>0)
            {
                *gameSquare[i][j+1]-gameSquare[i][j];
                delete destroy;
                return false;
            }
            *gameSquare[i][j+1]-gameSquare[i][j];
            delete destroy;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            *gameSquare[i][j]-gameSquare[i][j+1];
            int return_value;
            destroy=new Vertical3;
            return_value=destroy->condition(gameSquare,gameSquare[i][j]);
            if(return_value>0)
            {
                *gameSquare[i][j+1]-gameSquare[i][j];
                delete destroy;
                return false;
            }
            *gameSquare[i][j+1]-gameSquare[i][j];
            delete destroy;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            *gameSquare[j][i]-gameSquare[j+1][i];
            int return_value;
            destroy=new Horizontal3;
            return_value=destroy->condition(gameSquare,gameSquare[j][i]);
            if(return_value>0)
            {
                *gameSquare[j+1][i]-gameSquare[j][i];
                delete destroy;
                return false;
            }
            *gameSquare[j+1][i]-gameSquare[j][i];
            delete destroy;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            *gameSquare[j][i]-gameSquare[j+1][i];
            int return_value;
            destroy=new Vertical3;
            return_value=destroy->condition(gameSquare,gameSquare[j][i]);
            if(return_value>0)
            {
                *gameSquare[j+1][i]-gameSquare[j][i];
                delete destroy;
                return false;
            }
            *gameSquare[j+1][i]-gameSquare[j][i];
            delete destroy;
        }
    }
    return true;
}
int game::done()
{
    while(1){
        fillinzero();
        spawnforzero();
        bool return_value=Eliminatepossibility();
        if(!return_value)break;
    }
    if(cannotplay())
    {
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                gameSquare[i][j]->setnumber();
                gameSquare[i][j]->setpicture();
                if(j>=2&&gameSquare[i][j]->number==gameSquare[i][j-2]->number&&gameSquare[i][j]->number==gameSquare[i][j-1]->number)
                    j--;
                if(i>=2&&gameSquare[i][j]->number==gameSquare[i-2][j]->number&&gameSquare[i][j]->number==gameSquare[i-1][j]->number)
                    j--;
            }
        }
    }
    step--;
    Step();
    score();
    Stars();
    reNewPicture();
    if(step==0)
    {
        emit quit(stars,Score);
        if(Score<400)
        {
            ui->label_3->setText("Level failed!");
            ui->label_4->setText("You did not reach the goal!");
        }
        if(Score>400)
        {
            ui->label_3->setText("Level completed!");
            ui->label_4->setText("You finished the goal!");
        }
        //this->close();
    }
}
void game::score()
{
    int a,b,c,d,e;
    a=Score/10/10/10/10/10;
    b=Score/10/10/10%10;
    c=Score/10/10%10;
    d=Score/10%10;
    e=Score%10;
    switch(a)
    {
    case 0:ui->label_score->setText("0");break;
    case 1:ui->label_score->setText("1");break;
    case 2:ui->label_score->setText("2");break;
    case 3:ui->label_score->setText("3");break;
    case 4:ui->label_score->setText("4");break;
    case 5:ui->label_score->setText("5");break;
    case 6:ui->label_score->setText("6");break;
    case 7:ui->label_score->setText("7");break;
    case 8:ui->label_score->setText("8");break;
    case 9:ui->label_score->setText("9");break;
    }
    switch(b)
    {
    case 0:ui->label_score_2->setText("0");break;
    case 1:ui->label_score_2->setText("1");break;
    case 2:ui->label_score_2->setText("2");break;
    case 3:ui->label_score_2->setText("3");break;
    case 4:ui->label_score_2->setText("4");break;
    case 5:ui->label_score_2->setText("5");break;
    case 6:ui->label_score_2->setText("6");break;
    case 7:ui->label_score_2->setText("7");break;
    case 8:ui->label_score_2->setText("8");break;
    case 9:ui->label_score_2->setText("9");break;
    }
    switch(c)
    {
    case 0:ui->label_score_3->setText("0");break;
    case 1:ui->label_score_3->setText("1");break;
    case 2:ui->label_score_3->setText("2");break;
    case 3:ui->label_score_3->setText("3");break;
    case 4:ui->label_score_3->setText("4");break;
    case 5:ui->label_score_3->setText("5");break;
    case 6:ui->label_score_3->setText("6");break;
    case 7:ui->label_score_3->setText("7");break;
    case 8:ui->label_score_3->setText("8");break;
    case 9:ui->label_score_3->setText("9");break;
    }
    switch(d)
    {
    case 0:ui->label_score_4->setText("0");break;
    case 1:ui->label_score_4->setText("1");break;
    case 2:ui->label_score_4->setText("2");break;
    case 3:ui->label_score_4->setText("3");break;
    case 4:ui->label_score_4->setText("4");break;
    case 5:ui->label_score_4->setText("5");break;
    case 6:ui->label_score_4->setText("6");break;
    case 7:ui->label_score_4->setText("7");break;
    case 8:ui->label_score_4->setText("8");break;
    case 9:ui->label_score_4->setText("9");break;
    }
    switch(e)
    {
    case 0:ui->label_score_5->setText("0");break;
    case 1:ui->label_score_5->setText("1");break;
    case 2:ui->label_score_5->setText("2");break;
    case 3:ui->label_score_5->setText("3");break;
    case 4:ui->label_score_5->setText("4");break;
    case 5:ui->label_score_5->setText("5");break;
    case 6:ui->label_score_5->setText("6");break;
    case 7:ui->label_score_5->setText("7");break;
    case 8:ui->label_score_5->setText("8");break;
    case 9:ui->label_score_5->setText("9");break;
    }
}
void game::Step()
{
    int a,b;
    a=step/10%10;
    b=step%10;
    switch(a)
    {
    case 0:ui->label_step->setText("0");break;
    case 1:ui->label_step->setText("1");break;
    case 2:ui->label_step->setText("2");break;
    case 3:ui->label_step->setText("3");break;
    case 4:ui->label_step->setText("4");break;
    case 5:ui->label_step->setText("5");break;
    case 6:ui->label_step->setText("6");break;
    case 7:ui->label_step->setText("7");break;
    case 8:ui->label_step->setText("8");break;
    case 9:ui->label_step->setText("9");break;
    }
    switch(b)
    {
    case 0:ui->label_step_2->setText("0");break;
    case 1:ui->label_step_2->setText("1");break;
    case 2:ui->label_step_2->setText("2");break;
    case 3:ui->label_step_2->setText("3");break;
    case 4:ui->label_step_2->setText("4");break;
    case 5:ui->label_step_2->setText("5");break;
    case 6:ui->label_step_2->setText("6");break;
    case 7:ui->label_step_2->setText("7");break;
    case 8:ui->label_step_2->setText("8");break;
    case 9:ui->label_step_2->setText("9");break;
    }
}
void game::Stars()
{
    if(Score<400)
    {
        stars=0;
        ui->star1->setPixmap(QPixmap(":/Silver-Star.png"));
        ui->star2->setPixmap(QPixmap(":/Silver-Star.png"));
        ui->star3->setPixmap(QPixmap(":/Silver-Star.png"));
    }
    else if(Score<700)
    {
        stars=1;
        ui->star1->setPixmap(QPixmap(":/Gold Star.png"));
        ui->star2->setPixmap(QPixmap(":/Silver-Star.png"));
        ui->star3->setPixmap(QPixmap(":/Silver-Star.png"));
    }
    else if(Score<1000)
    {
        stars=2;
        ui->star1->setPixmap(QPixmap(":/Gold Star.png"));
        ui->star2->setPixmap(QPixmap(":/Gold Star.png"));
        ui->star3->setPixmap(QPixmap(":/Silver-Star.png"));
    }
    else
    {
        stars=3;
        ui->star1->setPixmap(QPixmap(":/Gold Star.png"));
        ui->star2->setPixmap(QPixmap(":/Gold Star.png"));
        ui->star3->setPixmap(QPixmap(":/Gold Star.png"));
    }
}
