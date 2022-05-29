// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
using namespace std;
#include  "bst.h"

BST<string> makeTree(const char* name) {
      BST<string> tree;
    ifstream file(name);
    if (!file) {
        cout << "Something wrong" <<"\n";
        throw string("Can not open file!");
    }
    string word = "";
    while (!file.eof()) {
        int ch = int(file.get());
        if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
            word += tolower(ch);
        }
        else {
            if (word != "") {
                tree.Add(word);
                word = "";
            }
        }
    }
    file.close();
    return tree;
}
}
