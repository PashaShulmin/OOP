#ifndef OOP_PLAIN_H
#define OOP_PLAIN_H

#include "rnd.h"
#include "Transport.h"

class Plain : public Transport {
private:
    int range_;
    int capacity_;

public:
    // Ввод параметров самолёта из файла
    void In(ifstream &ifst) override;
    // Случайный ввод параметров самолёта
    void InRnd() override;
    // Вывод параметров самолёта в форматируемый поток
    void Out(ofstream &ofst) override;
};

#endif  // OOP_PLAIN_H
