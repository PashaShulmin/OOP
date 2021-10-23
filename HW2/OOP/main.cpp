// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование

#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <cstring>
#include <ctime>

#include "Container.h"
#include "Plain.h"
#include "Train.h"
#include "Ship.h"

void errMessage1() {
  cout << "incorrect command line!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
  cout << "incorrect qualifier value!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n";
}

int main(int argc, char* argv[]) {
  unsigned int start_time =  clock();
  if(argc != 5) {
    errMessage1();
    return 1;
  }

  cout << "Start"<< endl;
  Container c{10000};

  ////cout << "argv[1] = " << argv[1] << "\n";
  if(!strcmp(argv[1], "-f")) {
    ifstream ifst(argv[2]);
    c.In(ifst);
  }
  else if(!strcmp(argv[1], "-n")) {
    auto size = atoi(argv[2]);
    if((size < 1) || (size > 10000)) {
      cout << "incorrect numer of figures = "
           << size
           << ". Set 0 < number <= 10000\n";
      return 3;
    }
    // системные часы в качестве инициализатора
    srand(static_cast<unsigned int>(time(0)));
    // Заполнение контейнера генератором случайных чисел
    c.InRnd(size);
  }
  else {
    errMessage2();
    return 2;
  }

  // Вывод содержимого контейнера в файл
  ofstream ofst1(argv[3]);
  ofst1 << "Filled container:\n";
  c.Out(ofst1);

  // Вторая часть задания
  ofstream ofst2(argv[4]);
  c.SpecialFun(ofst2);

  cout << "Stop"<< endl;
  unsigned int end_time = clock(); // конечное время
  cout << "Time of work is " << end_time - start_time << " ms";
  return 0;
}
