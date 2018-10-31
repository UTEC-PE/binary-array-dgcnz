#include "alphabool.h"
#include "binary.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "===========================================================" << endl;
  cout << "Binary Array Practice" << endl;
  cout << "===========================================================" << endl
       << endl;
  boolean b(9);
  b.printMirror();

  std::cout << '\n';
  for (int i = 0; i < 9; ++i) {
    b.bitOn(i);
    b.printMirror();
    std::cout << '\n';
  }

  for (int i = 8; i >= 0; --i) {
    b.bitOff(i);
    b.printMirror();
    std::cout << '\n';
  }

  std::cout << '\n';

  AlphaBool word("uwu");
  word.print();

  return EXIT_SUCCESS;
}
