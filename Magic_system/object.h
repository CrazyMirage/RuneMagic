#ifndef OBJECT_H
#define OBJECT_H

#include <QString>

class Object
{
public:
    Object();

    virtual int getHealth() = 0;
    virtual void addHealth(int) = 0;

    virtual int getPower() = 0;
    virtual void addPower(int) = 0;

    virtual int getSpirit() = 0;
    virtual void addSpirit(int) = 0;

    virtual int getConcentration() = 0;
    virtual void addConcentration(int) = 0;

    virtual void test() = 0;

    char getType();

protected:
    char type;

private:

};

#endif // OBJECT_H
