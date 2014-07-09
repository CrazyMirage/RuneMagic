#ifndef SPELEDITORL_H
#define SPELEDITORL_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

#include "runebutton.h"
#include "../Magic_system/magic.h"


struct Node{
    Node(QPushButton* button, int x, int y);
    QPushButton* button;
    int x;
    int y;
};

class SpellEditor : public QWidget
{
    Q_OBJECT

public:
    SpellEditor(Data *data = 0, QWidget *parent = 0);
    ~SpellEditor();

    SpellField getSpellField();

private:
    int topRow;
    int bottomRow;
    int rightColumn;
    int leftColumn;

    RuneButton *selected;

    QGridLayout *leftUplayout;
    QGridLayout *rightUplayout;
    QGridLayout *leftDownlayout;
    QGridLayout *rightDownlayout;

    QGridLayout *mainLayout;

    Data *data;

private slots:
    void addRune(int x, int y);
    void runeClicked(RuneButton* button, int x , int y);

    void setRune(Runes::Runes rune);

    void addRightColumn();
    void addLeftColumn();
    void addTopRow();
    void addBottomRow();

};

#endif // SPELEDITORL_H
