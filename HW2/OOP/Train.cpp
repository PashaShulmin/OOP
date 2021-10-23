#include "Train.h"

// Реализация ввода параметров поезда из потока
void Train::In(ifstream &ifst) {
    ifst >> speed >> distance >> railway_carriages_;
}

// Реализация ввода параметров поезда с помощью рандома
void Train::InRnd() {
    speed = Transport::rnd100.Get();
    distance = Transport::rnd2000.Get();
    railway_carriages_ = Transport::rnd100.Get();
}

// Реализация вывода параметров поезда в поток
void Train::Out(ofstream &ofst) {
    ofst << "It is a train: speed = " << speed
         << "; distance = " << distance
         << "; time = " << Time()
         << "; number of railway carriages = " << railway_carriages_ << "\n";
}
