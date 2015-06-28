#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "squaremap.h"
#include "destroy.h"
#include "star.h"
#include "vertical.h"
#include "vertical3.h"
#include "horizontal.h"
#include "horizontal3.h"
#include <cstdlib>
#include <ctime>
namespace Ui {
class game;
}
class game : public QWidget
{
    Q_OBJECT
public:
    explicit game(QWidget *parent=0);
    ~game();
    SquareMap *gameSquare[10][10];
    Destroy *destroy;
    bool JudgeTwoStar(int R1,int C1,int R2,int C2);
    bool JudgeOneStar(int R1,int C1,int R2,int C2);
    bool Judgestripe2(int R1,int C1,int R2,int C2);
    bool JudgeHcrossV(int R1,int C1,int R2,int C2);
    bool JudgeStar(int R,int C);
    bool Judge9(int R,int C);
    bool JudgeHorizontal(int R,int C);
    bool JudgeVertical(int R,int C);
    bool JudgeHorizontal3(int R,int C);
    bool JudgeVertical3(int R,int C);
    void reNewPicture();
    void fillinzero();
    bool Eliminatepossibility();
    void spawnforzero();
    bool cannotplay();
    bool Judge(int first_row,int first_col,int second_row,int second_col);
    int done();
    void score();
    void Step();
    void Stars();
    bool isClicked;
signals:
    void quit(int stars ,int Score);
private slots:
    void SquareClick(int row,int col);
private:
    Ui::game *ui;
    QWidget *mainWindow;
    int step;
    int Score;
    int stars;
    int first_row,first_col;
    int second_row,second_col;
    int record_R,record_C;
};

#endif // GAME_H
