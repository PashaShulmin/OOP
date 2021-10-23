#include "Container.h"

// Конструктор контейнера
Container::Container(int s): len{0}, size_{s} {
    storage_ = new Transport*[s];
}

// Деструктор контейнера
Container::~Container() {
    Clear();
    delete[] storage_;
}

// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage_[i];
    }
    len = 0;
}

// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage_[len] = Transport::StaticIn(ifst)) != nullptr) {
            len++;
        }
    }
}

// Случайный ввод содержимого контейнера
void Container::InRnd(int s) {
    if(s > size_) {
        s = size_;
    }
    while(len < s) {
        if((storage_[len] = Transport::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i + 1 << ": ";
        storage_[i]->Out(ofst);
    }
}

/*
 * Реализация дополнительной функции, выполняющая следующее:
 * Удалить из контейнера те элементы, для которых значение,
 * полученное с использованием функции, общей для всех альтернатив, больше
 * чем среднее арифметическое для всех элементов контейнера, полученное с
 * использованием этой же функции. Остальные элементы передвинуть к
 * началу контейнера с сохранением порядка.
 */
void Container::SpecialFun(ofstream &ofst) {
    ofst << "Before deletion:" << "\n";
    for (int i = 0; i < len; ++i) {
      ofst << i + 1 << ": ";
      storage_[i]->Out(ofst);
    }
    ofst << "After deletion:" << "\n";
    double average = 0;
    for (int i = 0; i < len; ++i) {
        average += storage_[i]->Time();
    }
    average /= len;
    for (int i = 0; i < len; ++i) {
        if (storage_[i]->Time() > average) {
            for (int j = i; j < len - 1; ++j) {
                storage_[j] = storage_[j + 1];
            }
            --len;
            --i;
        }
    }
    for (int i = 0; i < len; ++i) {
      ofst << i + 1 << ": ";
      storage_[i]->Out(ofst);
    }
}
