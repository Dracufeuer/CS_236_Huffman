//
//  HuffmanNode.hpp
//  PR-3
//
//  Created by Marcus Shaw on 11/5/23.
//

#ifndef HuffmanNode_hpp
#define HuffmanNode_hpp

#include <stdio.h>
class HuffmanNode {
public:
    char data; // this is to say what the character is
    int freq; // this is to make sure we know the frequency of the characters
    HuffmanNode* left; // this is to store the node to the left
    HuffmanNode* right; // this is to store the node to the right 
    
    
    
    HuffmanNode (const char = ' ', const int = 0); // this is the default constructor of the class

};


#endif /* HuffmanNode_hpp */
