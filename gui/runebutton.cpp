#include "runebutton.h"

RuneButton::RuneButton(int x, int y, Data* data, bool mainRune, QWidget *parent) :
    QPushButton(parent),
    x(x), y(y),
    mainRune(mainRune),
    data(data)
{
    connect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
    if(mainRune)
        setStyleSheet("background: white; border: 2px solid green");
    else
        setStyleSheet("background: white; border: none");
    setFixedSize(40,40);
    setRune(Runes::End);
}

RuneButton::RuneButton(Runes::Runes rune, Data* data, QWidget *parent):
    QPushButton(parent),
    data(data)
{
    connect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
    setRune(rune);
    setFixedSize(40,40);
}

Runes::Runes RuneButton::getRune()
{
    return rune;
}


void RuneButton::clickedSlot()
{
    emit clicked(this,x,y);
    emit clicked(rune);
}

void RuneButton::checked()
{
    if(mainRune)
        setStyleSheet("background: red; border: 2px solid green");
    else
        setStyleSheet("background: red; border: none");
}

void RuneButton::unChecked()
{
    if(mainRune)
        setStyleSheet("background: white; border: 2px solid green");
    else
        setStyleSheet("background: white; border: none");
}

void RuneButton::setRune(Runes::Runes rune)
{
    this->rune = rune;
    qDebug() << data->getRuneImage(rune);
    if(rune == Runes::End)
        setIcon(QIcon());
    else
        setIcon(*(data->getRuneImage(rune)));
    setIconSize(QSize(100,100));
}

void RuneButton::clear()
{
    setStyleSheet("background-image: none");
}
