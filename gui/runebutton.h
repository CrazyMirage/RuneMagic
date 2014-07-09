#ifndef RUNEBUTTON_H
#define RUNEBUTTON_H

#include <QPushButton>
#include <QIcon>

#include "data.h"
#include "../Magic_system/runes/rune.h"

class RuneButton : public QPushButton
{
    Q_OBJECT
public:
    RuneButton(int x, int y, Data *data = 0, bool mainRune = false, QWidget *parent = 0);
    RuneButton(Runes::Runes rune, Data *data = 0, QWidget *parent = 0);
    Runes::Runes getRune();

private:
    int x;
    int y;
    bool mainRune;
    Runes::Runes rune;
    Data* data;

signals:
    void clicked(RuneButton*, int x, int y);
    void clicked(Runes::Runes);

public slots:
    void clickedSlot();
    void checked();
    void unChecked();
    void setRune(Runes::Runes rune);
    void clear();
};

#endif // RUNEBUTTON_H
