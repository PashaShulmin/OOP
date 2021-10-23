//
// Created by pasha on 21.10.2021.
//

#ifndef OOP_CONTAINER_H
#define OOP_CONTAINER_H

#include "Transport.h"

// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container(int s);
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst);
    // Дополнительная функция номер 20
    void SpecialFun(ofstream &ofst);
private:
    void Clear();  // Очистка контейнера от данных
    int len;       // текущая длина
    Transport **storage_;
    int size_;
};
#endif  // OOP_CONTAINER_H
