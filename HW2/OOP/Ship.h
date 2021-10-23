//
// Created by pasha on 20.10.2021.
//

#ifndef OOP_SHIP_H
#define OOP_SHIP_H

#include "rnd.h"
#include "Transport.h"

class Ship : public Transport {
private:
    int displacement_;
    enum Type { liner = 1, tow = 2, tanker = 3 };
    Type type_;

public:
    // Ввод параметров поезда из файла
    void In(ifstream &ifst) override;
    // Случайный ввод параметров поезда
    void InRnd() override;
    // Вывод параметров поезда в форматируемый поток
    void Out(ofstream &ofst) override;
};

#endif  // OOP_SHIP_H
