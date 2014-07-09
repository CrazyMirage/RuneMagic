#ifndef RUNESBAR_H
#define RUNESBAR_H

#include <QWidget>
#include <QGridLayout>

#include "runebutton.h"

class RunesBar : public QWidget
{
    Q_OBJECT
public:
    explicit RunesBar(Data *data = 0, QWidget *parent = 0);

private:
    QGridLayout *layout;

    RuneButton **buttons;

    int maxWidth;

    //Data *data;

signals:
    void runeSelect(Runes::Runes rune);


public slots:
    void selectRune(Runes::Runes rune);
    
};

#endif // RUNESBAR_H
