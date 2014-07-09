#include "spelleditor.h"



Node::Node(QPushButton *button, int x, int y):
    button(button),
    x(x),
    y(y)
{
}

SpellEditor::SpellEditor(Data *data, QWidget *parent)
    : QWidget(parent),
      data(data),
      topRow(0),
      bottomRow(0),
      leftColumn(0),
      rightColumn(0),
      selected(0)
{
    /*Magic runeMagic;
    SpellField field(5,5);

    field.map[2][1] = Runes::Uraz;
    field.map[3][1] = Runes::Uraz;
    field.map[0][2] = Runes::Uraz;
    field.map[3][2] = Runes::Uraz;

    field.map[1][1] = Runes::Fehu;
    field.map[1][2] = Runes::Fehu;
    field.map[2][2] = Runes::Fehu;
    field.map[3][3] = Runes::Fehu;

    field.mainRune.x = 2;
    field.mainRune.y = 1;

    Character tester(100,20,100);

    runeMagic.generateSpell(field).activate(tester,tester,100);
    tester.test();*/

    RuneButton *firstRune = new RuneButton(0,0,data,true);
    //firstRune->setRune(Runes::Fehu);

    leftUplayout = new QGridLayout;
    rightUplayout = new QGridLayout;
    leftDownlayout= new QGridLayout;
    rightDownlayout= new QGridLayout;

    rightDownlayout->addWidget(firstRune,0,0);
    //buttons.push_front(Node(firstRune,0,0));

    leftUplayout->setOriginCorner(Qt::BottomRightCorner);
    //leftUplayout->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    rightUplayout->setOriginCorner(Qt::BottomLeftCorner);

    leftDownlayout->setOriginCorner(Qt::TopRightCorner);

    connect(firstRune, SIGNAL(clicked(RuneButton*,int,int)), this, SLOT(runeClicked(RuneButton*,int,int)));
    connect(firstRune, SIGNAL(clicked(RuneButton*,int,int)), firstRune, SLOT(checked()));

    mainLayout= new QGridLayout;

    mainLayout->setAlignment(Qt::AlignCenter);

    mainLayout->addLayout(leftUplayout,0,0);
    mainLayout->addLayout(rightUplayout,0,1);
    mainLayout->addLayout(leftDownlayout,1,0);
    mainLayout->addLayout(rightDownlayout,1,1);

    setLayout(mainLayout);

}

SpellEditor::~SpellEditor()
{

}

SpellField SpellEditor::getSpellField()
{
    SpellField field(-leftColumn+rightColumn-1, -bottomRow+topRow-1);
    field.mainRune.x = -leftColumn-1;
    field.mainRune.y = topRow;

    for (int x = leftColumn+1,i = 0; x < rightColumn; ++x,++i){;
        for(int y = topRow, n = 0; y > bottomRow; --y, ++n){
            if(y > 0){
                if(x < 0)
                   field.map[i][n] = ((RuneButton*)(leftUplayout->itemAtPosition(y-1, -x+1)->widget()))->getRune();
                else
                   field.map[i][n] = ((RuneButton*)(rightUplayout->itemAtPosition(y-1, x)->widget()))->getRune();
            }
            else{
                if(x < 0)
                   field.map[i][n] = ((RuneButton*)(leftDownlayout->itemAtPosition(-y, -x+1)->widget()))->getRune();
                else
                   field.map[i][n] = ((RuneButton*)(rightDownlayout->itemAtPosition(-y, x)->widget()))->getRune();
            }
        }
    }

    return field;
}

void SpellEditor::addRune(int x, int y)
{
    RuneButton *button = new RuneButton(x,y,data);
    connect(button, SIGNAL(clicked(RuneButton*,int,int)), this, SLOT(runeClicked(RuneButton*,int,int)));

    if(y > 0){
        if(x < 0)
           leftUplayout->addWidget(button, y-1, -x+1);
        else
           rightUplayout->addWidget(button, y-1, x);
    }
    else{
        if(x < 0)
           leftDownlayout->addWidget(button, -y, -x+1);
        else
           rightDownlayout->addWidget(button, -y, x);
    }
}

void SpellEditor::runeClicked(RuneButton *button, int x, int y)
{
    if(x == rightColumn)
        addRightColumn();
    if(x == leftColumn)
        addLeftColumn();
    if(y == topRow)
        addTopRow();
    if(y == bottomRow)
        addBottomRow();
    if(selected)
        selected->unChecked();
    selected = button;
    button->checked();
}

void SpellEditor::setRune(Runes::Runes rune)
{
    qDebug() << "setRune" << rune;
    if(selected)
        selected->setRune(rune);
}

void SpellEditor::addRightColumn()
{
    rightColumn++;
    for(int i = topRow; i >= bottomRow; --i){
        addRune(rightColumn, i);
    }
}

void SpellEditor::addLeftColumn()
{
    leftColumn--;
    for(int i = topRow; i >= bottomRow; --i){
        addRune(leftColumn, i);
    }
}

void SpellEditor::addTopRow()
{
    topRow++;
    for(int i = rightColumn; i >= leftColumn; --i){
        addRune(i, topRow);
    }
}

void SpellEditor::addBottomRow()
{
    bottomRow--;
    for(int i = rightColumn; i >= leftColumn; --i){
        addRune(i, bottomRow);
    }
}
