#include "Plain.h"
#include "Train.h"
#include "Ship.h"

[[maybe_unused]] Random Transport::rnd2000(100, 2000);
[[maybe_unused]] Random Transport::rnd100(1, 100);
[[maybe_unused]] Random Transport::rnd3(1, 3);

double Transport::Time() {
    return distance / speed;
}

// Ввод параметров обобщенного транспорта из файла
Transport *Transport::StaticIn(ifstream &ifdt) {
    int kind_of_transport;
    ifdt >> kind_of_transport;
    Transport* t = nullptr;
    switch (kind_of_transport) {
        case 1:
            t = new Plain;
            break;
        case 2:
            t = new Train;
            break;
        case 3:
            t = new Ship;
            break;
    }
    t->In(ifdt);
    return t;
}

// Случайный ввод обобщенного транспорта
Transport *Transport::StaticInRnd() {
    int kind_of_transport = Transport::rnd3.Get();
    Transport* t = nullptr;
    switch (kind_of_transport) {
        case 1:
            t = new Plain;
            break;
        case 2:
            t = new Train;
            break;
        case 3:
            t = new Ship;
            break;
    }
    t->InRnd();
    return t;
}
