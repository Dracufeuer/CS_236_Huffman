//
//  Huffmanmain.cpp
//  PR-3
//  Class: CS 236
//  Semester: Fall 2023
//  Name: Marcus Shaw
//
//  Created by Marcus Shaw on 11/4/23.
//

#include <iostream>
#include "Huffman.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    string a;
    cout << "Enter the string to be encoded: " << '\n';
    getline(cin, a);
    Huffman var;
    var.huffmanBuildTree(a);
    cout << '\n' << "The encoded string is: " << '\n' << var.compress(a) << '\n' ;
    cout << '\n' << "The decoded string is: " << '\n' << var.decompress(var.compress(a)) << '\n' << '\n';
    return 0;
}
