#ifndef ALPHABOOL_H
#define ALPHABOOL_H
#include "binary.h"
#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

typedef unsigned char uchar;

class AlphaBool {
private:
  std::vector<std::vector<boolean *>> word;

  const std::map<char, std::vector<boolean *>> alphabet = {
      {'u',
       {new boolean(0, 8), new boolean(66, 8), new boolean(66, 8),
        new boolean(66, 8), new boolean(66, 8), new boolean(66, 8),
        new boolean(126, 8), new boolean(0, 8)}},
      {'w',
       {new boolean(0, 8), new boolean(66, 8), new boolean(66, 8),
        new boolean(66, 8), new boolean(90, 8), new boolean(102, 8),
        new boolean(66, 8), new boolean(0, 8)}}};

public:
  explicit AlphaBool(std::string word_) {
    std::cout << "\n********** " << word_ << " *********\n";
    for (auto const &c : word_) {
      this->word.push_back(this->alphabet.at(c));
    }
  }
  void print() const {
    for (int line = 0; line < 8; ++line) {
      for (auto const &characterLineAt : this->word) {
        characterLineAt[line]->printPoint();
      }
      std::cout << '\n';
    }
  }
};

#endif
