#include "editor.h"

Editor::Editor(QWidget *parent) :
    QWidget(parent),
    dataRune(new Data),
    runeMagic(new Magic)
{
    editor = new SpellEditor(dataRune);
    runesBar = new RunesBar(dataRune);
    QScrollArea *scrollEdit = new QScrollArea;
    scrollEdit->setBackgroundRole(QPalette::Dark);
    scrollEdit->setWidget(editor);
    scrollEdit->setAlignment(Qt::AlignCenter);
    scrollEdit->setMinimumSize(700,500);
    scrollEdit->setWidgetResizable(true);

    layout = new QGridLayout;

    layout->addWidget(scrollEdit,0,0);

    scrollEdit = new QScrollArea;
    scrollEdit->setWidget(runesBar);
    scrollEdit->setFixedWidth(158);

    layout->addWidget(scrollEdit,0,1);
    startButton = new QPushButton("Start");

    layout->addWidget(startButton,1,1);
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(runesBar, SIGNAL(runeSelect(Runes::Runes)), editor, SLOT(setRune(Runes::Runes)));
    //Data strange;

    setLayout(layout);
}

void Editor::start()
{
    Character tester(100,20,100,100);
    tester.test();
    runeMagic->generateSpell(editor->getSpellField()).activate(tester,tester,100);
    tester.test();

}
