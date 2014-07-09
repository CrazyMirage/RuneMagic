#include "magic.h"



Position::Position(int x, int y):
    x(x), y(y)
{
}



SpellField::SpellField(int x, int y):
    size(x,y),mainRune(-1,-1)
{
    //qDebug() << size.x;
    map = new Runes::Runes*[x];
    for (int i = 0; i < x; ++i){
        map[i] = new Runes::Runes[y];
        for(int n = 0; n < y; ++n)
            map[i][n] = Runes::End;
    }
    //qDebug() << size.y;
}


Magic::Magic()
{
    runes = new Rune*[Runes::End];
    for (int i = 0; i < Runes::End; ++i) {
        runes[i] = 0;
    }

    inizializeRunes();
    //testRunes();
    testEffects();
}

Magic::~Magic()
{
    for (int i = 0; i < Runes::End; ++i) {
        delete runes[i];
    }
    delete [] runes;
}

void Magic::inizializeRunes()
{
    /*Rune fehu("Fehu", 5, Runes::Neutral, &fehuEffect);
    Rune uraz("Uraz", 5, Runes::Neutral, &urazEffect);*/

    runes[Runes::Fehu] = new FehuRune();
    runes[Runes::Uraz] = new UrazRune();
    runes[Runes::Thurisaz] = new ThurisazRune();
    //runes[1] = uraz;
}

Spell Magic::generateSpell(SpellField field)
{
    QList<Position> list;
    QList<ActiveEffect> effects;
    QList<ActiveEffect>::iterator iter;
    ActiveEffect* worker;

    //crating mask for field
    bool **mask = new bool*[field.size.x];
    for (int i = 0; i < field.size.x; ++i){
        mask[i] = new bool[field.size.y];
        for(int n = 0; n < field.size.y; ++n)
            if(field.map[i][n] != Runes::End)
                mask[i][n] = true;
            else
                mask[i][n] = false;
    }

    if(field.mainRune.x > -1 && field.mainRune.y > -1 && field.map[field.mainRune.x][field.mainRune.y] != Runes::End){
        Position current(field.mainRune.x,field.mainRune.y);

        ActiveEffect work;
        Effect effect;
        int cost = 0;

        Rune *mainRune = runes[field.map[current.x][current.y]];
        work.effect = mainRune->combinationEffect(field.map[current.x][current.y]);
        work.coefficient = 1;
        effects.append(work);
        cost += mainRune->getCost();
        mask[current.x][current.y] = false;

        //select next rune
        if(current.x > 0 && mask[current.x-1][current.y]){
            list.append(Position(current.x-1,current.y));
            mask[current.x-1][current.y] = false;
        }
        if(current.x < field.size.x-1 && mask[current.x+1][current.y]){
            list.append(Position(current.x+1,current.y));
            mask[current.x+1][current.y] = false;
        }
        if(current.y > 0 && mask[current.x][current.y-1]){
            list.append(Position(current.x,current.y-1));
            mask[current.x][current.y-1] = false;
        }
        if(current.y < field.size.y-1 && mask[current.x][current.y+1]){
            list.append(Position(current.x,current.y+1));
            mask[current.x][current.y+1] = false;
        }


        while(!list.isEmpty()){
            current = list.first();

            //qDebug() << current.x << " " << current.y;

            list.pop_front();
            effect = mainRune->combinationEffect(field.map[current.x][current.y]);
            bool flag = true;
            for(iter = effects.begin(); iter != effects.end(); iter++){
                if(iter->effect == effect)
                {
                    iter->coefficient++;
                    flag = false;
                    break;
                }
            }
            if(flag){
                work.effect = effect;
                effects.append(work);
            }
            cost += runes[field.map[current.x][current.y]]->getCost();

            //select next rune
            if(current.x > 0&& mask[current.x-1][current.y]){
                list.append(Position(current.x-1,current.y));
                mask[current.x-1][current.y] = false;
            }
            if(current.x < field.size.x-1 && mask[current.x+1][current.y]){
                list.append(Position(current.x+1,current.y));
                mask[current.x+1][current.y] = false;
            }
            if(current.y > 0 && mask[current.x][current.y-1]){
                list.append(Position(current.x,current.y-1));
                mask[current.x][current.y-1] = false;
            }
            if(current.y < field.size.y-1 && mask[current.x][current.y+1]){
                list.append(Position(current.x,current.y+1));
                mask[current.x][current.y+1] = false;
            }

        }
        int size;
        worker = new ActiveEffect[size = effects.size()];
        for(int i = 0; i < size; i++){
            worker[i] = effects.first();
            effects.pop_front();
        }
        return Spell("Success", cost, worker, size);
    }
    return Spell("Error", 1,worker, 0);
}

void Magic::testEffects()
{
    Effect work;
    Character tester(100,20,100,100);
    for(int i = 0; i < Runes::End; ++i){
        if(runes[i] != 0){
            qDebug() << i;
            for(int n = 0; n < Runes::End; ++n){
                work = runes[i]->combinationEffect((Runes::Runes)n);
                if(work != 0){
                    work(tester,2);
                    tester.test();
                }
            }
            qDebug() << " ";
        }
    }
}

void Magic::testRunes()
{
    for(int i = 0; i < Runes::End; ++i){
        //if(runes[i] != 0)
            //runes[i]->effect(Character());
    }
    qDebug() << " ";
}


