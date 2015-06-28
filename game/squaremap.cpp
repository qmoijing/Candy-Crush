#include "squaremap.h"
SquareMap::SquareMap(QWidget *parent, int Row, int Col) : QObject(parent)
{
    row=Row;
    col=Col;
    button=new QPushButton(parent);
    button->setGeometry(51*col+60,51*row+25,50,50);
    button->setStyleSheet("border:1px solid;");
    button->setIconSize(button->size());
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
}
SquareMap::~SquareMap()
{
    delete button;
}
void SquareMap::click()
{
    emit Click(row,col);
}
void SquareMap::setnumber()
{
    number=rand()%6+1;
    return;
}
void SquareMap::setpicture()
{
    switch(number)
    {
    case 1:button->setIcon(QIcon(QPixmap(":/red.png")));break;
    case 2:button->setIcon(QIcon(QPixmap(":/blue.png")));break;
    case 3:button->setIcon(QIcon(QPixmap(":/green.png")));break;
    case 4:button->setIcon(QIcon(QPixmap(":/orange.png")));break;
    case 5:button->setIcon(QIcon(QPixmap(":/purple.png")));break;
    case 6:button->setIcon(QIcon(QPixmap(":/yellow.png")));break;
    case 11:button->setIcon(QIcon(QPixmap(":/red1.png")));break;
    case 12:button->setIcon(QIcon(QPixmap(":/blue1.png")));break;
    case 13:button->setIcon(QIcon(QPixmap(":/green1.png")));break;
    case 14:button->setIcon(QIcon(QPixmap(":/orange1.png")));break;
    case 15:button->setIcon(QIcon(QPixmap(":/purple1.png")));break;
    case 16:button->setIcon(QIcon(QPixmap(":/yellow1.png")));break;
    case 21:button->setIcon(QIcon(QPixmap(":/red2.png")));break;
    case 22:button->setIcon(QIcon(QPixmap(":/blue2.png")));break;
    case 23:button->setIcon(QIcon(QPixmap(":/green2.png")));break;
    case 24:button->setIcon(QIcon(QPixmap(":/orange2.png")));break;
    case 25:button->setIcon(QIcon(QPixmap(":/purple2.png")));break;
    case 26:button->setIcon(QIcon(QPixmap(":/yellow2.png")));break;
    case 31:button->setIcon(QIcon(QPixmap(":/red3.png")));break;
    case 32:button->setIcon(QIcon(QPixmap(":/blue3.png")));break;
    case 33:button->setIcon(QIcon(QPixmap(":/green3.png")));break;
    case 34:button->setIcon(QIcon(QPixmap(":/orange3.png")));break;
    case 35:button->setIcon(QIcon(QPixmap(":/purple3.png")));break;
    case 36:button->setIcon(QIcon(QPixmap(":/yellow3.png")));break;
    case 7:button->setIcon(QIcon(QPixmap(":/chocolate.png")));break;
    case 0:button->setIcon(QIcon(QPixmap(":/no pic")));break;
    }
}
void SquareMap::operator -(SquareMap *a)
{
    int tem_number=a->number;
    a->number=number;
    number=tem_number;
    setpicture();
    a->setpicture();
}
