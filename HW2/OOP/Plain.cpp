#include "Plain.h"

// Реализация ввода параметров самолёта из потока
void Plain::In(ifstream &ifst) {
    ifst >> speed >> distance >> range_ >> capacity_;
}

// Реализация ввода параметров самолёта с помощью рандома
void Plain::InRnd() {
    speed = Transport::rnd100.Get();
    distance = Transport::rnd2000.Get();
    range_ = Transport::rnd2000.Get();
    capacity_ = Transport::rnd100.Get();
}

// Реализация вывода параметров самолёта в поток
void Plain::Out(ofstream &ofst) {
    ofst << "It is a plain: speed = " << speed
         << "; distance = " << distance
         << "; time = " << Time()
         << "; range = " << range_
         << "; capacity = " << capacity_ << "\n";
}
