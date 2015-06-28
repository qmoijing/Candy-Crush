#ifndef SQUAREMAP_H
#define SQUAREMAP_H

#include <QObject>
#include <QPushButton>
#include <cstdlib>
#include <ctime>

class SquareMap : public QObject
{
    Q_OBJECT

public:
    explicit SquareMap(QWidget *parent, int Row, int Col);
    ~SquareMap();
    void setnumber();
    void setpicture();
    void operator -(SquareMap *a);
    int number;
    int row,col;
signals:
    void Click(int row,int col);
private slots:
    void click();
private:
    QPushButton *button;



};

#endif // SQUAREMAP_H
