#include "Ship.h"

// Реализация ввода параметров корабля из потока
void Ship::In(ifstream &ifst) {
    ifst >> speed >> distance >> displacement_;
    int type_id;
    ifst >> type_id;
    type_ = static_cast<Type>(type_id);
}

// Реализация ввода параметров корабля с помощью рандома
void Ship::InRnd() {
    speed = Transport::rnd100.Get();
    distance = Transport::rnd2000.Get();
    displacement_ = Transport::rnd2000.Get();
    int type_id = Transport::rnd3.Get();
    type_ = static_cast<Type>(type_id);
}

// Реализация вывода параметров корабля в поток
void Ship::Out(ofstream &ofst) {
    string type_to_string;
    switch (type_) {
        case liner:
            type_to_string = "liner";
            break;
        case tow:
            type_to_string = "tow";
            break;
        case tanker:
            type_to_string = "tanker";
            break;
    }
    ofst << "It is a ship: speed = " << speed
         << "; distance = " << distance
         << "; time = " << Time()
         << "; displacement = " << displacement_
         << "; type of ship is " << type_to_string << "\n";
}
