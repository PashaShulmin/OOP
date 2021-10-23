#ifndef OOP_TRANSPORT_H
#define OOP_TRANSPORT_H

// transport.h - содержит описание обобщающего транспорта,

#include <fstream>
using namespace std;

#include "rnd.h"

// структура, обобщающая все имеющиеся виды транспорта
class Transport {
protected:
    static Random rnd2000;
    static Random rnd100;
    static Random rnd3;
    int speed;
    double distance;

public:
    virtual ~Transport() = default;
    // Ввод обобщенного транспорта
    static Transport *StaticIn(ifstream &ifdt);
    // Ввод обобщенного транспорта
    virtual void In(ifstream &ifdt) = 0;
    // Случайный ввод обобщенного транспорта
    static Transport *StaticInRnd();
    // Виртуальный метод ввода случайного транспорта
    virtual void InRnd() = 0;
    // Вывод обобщенного транспорта
    virtual void Out(ofstream &ofst) = 0;
    // Функция вычисления времени прохождения пути
    double Time();
};

#endif  // OOP_TRANSPORT_H
