//
//  Huffman.hpp
//  PR-3
//
//  Created by Marcus Shaw on 11/4/23.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include "HuffmanNode.hpp"
#include <stdio.h>
#include <map>
#include <string>
#include <queue>
#include <iostream>


using namespace std;
class Huffman {
private:
    map<char, string> key; //This is to save the key for compression and decrompession
    
public:
    Huffman(); // this is the default constructor
    
    map<char, int> tableCreation(string a); // this is for creating the table
    
    void setKey(HuffmanNode* root, char arr[], int top); // this is to set the key for decompression and compression
    void huffmanCodes(); // this is to output the huffman codes 
    void huffmanBuildTree (string a); // this is to build the priority queue that is the huffman tree
    string compress(string a); // this uses the huffman tree to compress the string
    string decompress(string a); // this uses the huffmna tree to decompress the string
    
    
};



#endif /* Huffman_hpp */
