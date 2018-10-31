#ifndef BINARY_H
#define BINARY_H

#include <cmath>
#include <iostream>

class boolean {
private:
  char *bools;
  int size;
  int numberOfBits;

public:
  explicit boolean(int numberOfBits_) : numberOfBits(numberOfBits_) {
    this->size = ceil(numberOfBits_ / 8.0);
    this->bools = new char[this->size]();
  }

  // The sole purpose of this constructor is to create a boolean array of 8
  // bools based on the character c
  explicit boolean(char c, int numberOfBits_) : numberOfBits(numberOfBits_) {
    this->size = ceil(numberOfBits_ / 8.0);

    this->bools = new char[this->size]();
    this->bools[0] = c;
  }

  inline void bitOn(int pos) { this->bools[pos / 8] |= (1 << (pos % 8)); }
  inline void bitOff(int pos) { this->bools[pos / 8] &= ~(1 << (pos % 8)); }

  inline bool operator[](int pos) const {
    return ((bools[pos / 8] & (1 << (pos % 8))));
  }
  // bool &operator[](int pos) { return true; }

  void print() const {
    for (int i = 0, length = this->numberOfBits; i < length; ++i) {
      std::cout << (*(this))[i];
    }
  }

  void printPoint() const {
    for (int i = 0, length = this->numberOfBits; i < length; ++i) {
      std::cout << ((*(this))[i] == 0 ? '.' : 'x');
    }
  }

  void printReverse() const {
    for (int i = this->numberOfBits - 1; i >= 0; --i) {
      std::cout << (*(this))[i];
    }
  }
  void printMirror() const {
    for (int i = 0, length = this->numberOfBits; i < length; ++i) {
      std::cout << (*(this))[i];
    }

    for (int i = this->numberOfBits - 1; i >= 0; --i) {
      std::cout << (*(this))[i];
    }
  }

  void clear() { delete[] bools; }

  ~boolean() { this->clear(); }
};

#endif
