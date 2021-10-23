#ifndef OOP_TRAIN_H
#define OOP_TRAIN_H

#include "rnd.h"
#include "Transport.h"

class Train : public Transport {
private:
    int railway_carriages_;

public:
    // Ввод параметров поезда из файла
    void In(ifstream &ifst) override;
    // Случайный ввод параметров поезда
    void InRnd() override;
    // Вывод параметров поезда в форматируемый поток
    void Out(ofstream &ofst) override;
};

#endif  // OOP_TRAIN_H
