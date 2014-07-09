#include "data.h"

Data::Data()
{
    qDebug()<<"Data";
    QFile file(":/files/runes.inf");
    try{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw((QString)"We coudn't open file.");
    }

    catch(QString e)
    {
            qDebug()<< e;
            return;
    }
    QString line;
    runeImages =  new QIcon*[Runes::End];
    for(int i = 0; i < Runes::End; i++)
        runeImages[i] = 0;
    for(int k = 0; !file.atEnd(); ++k){
        line = file.readLine();
        line.chop(1);
        runeImages[k] = new QIcon(line);
        qDebug()<<k << runeImages[k] <<"Data" << line;
    }
}

QIcon *Data::getRuneImage(Runes::Runes rune)
{
    return runeImages[rune];
}
