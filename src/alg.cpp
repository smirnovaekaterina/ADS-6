// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;

  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  }

  char lowercase = 'a' - 'A';

  std::string word = "";

  while (!file.eof()) {
    char ch = file.get();
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        if (ch >= 'A' && ch <= 'Z') {
          ch += lowercase;
        }
        word += ch;
    } else if (word != "") {
        tree.add(word);
        word = "";
    }
  }
  file.close();
  return tree;
}
