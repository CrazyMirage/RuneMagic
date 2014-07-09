#include "runesbar.h"

RunesBar::RunesBar(Data *data, QWidget *parent) :
    QWidget(parent)
{
    maxWidth = 3;

    layout = new QGridLayout;

    buttons = new RuneButton*[Runes::End + 1];
    for(int i = 0,n=-1; i < Runes::End+1; ++i){
        buttons[i] = new RuneButton((Runes::Runes)i, data);
        connect(buttons[i], SIGNAL(clicked(Runes::Runes)), this, SLOT(selectRune(Runes::Runes)));
        if(!(i%maxWidth)) n++;
        layout->addWidget(buttons[i],n,i%maxWidth);
    }
    setLayout(layout);
}

void RunesBar::selectRune(Runes::Runes rune)
{
    qDebug() << "selectRune" << rune;
    emit runeSelect(rune);
}
