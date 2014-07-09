#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>

#include "data.h"
#include "spelleditor.h"
#include "runesbar.h"

class Editor : public QWidget
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = 0);
    
private:
    //QScrollArea *scroll;
    SpellEditor  *editor;
    QGridLayout *layout;
    QPushButton *startButton;
    RunesBar *runesBar;

    Data *dataRune;

    Magic *runeMagic;

signals:
    
public slots:
    void start();
};

#endif // EDITOR_H
