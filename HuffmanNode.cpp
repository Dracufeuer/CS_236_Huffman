//
//  HuffmanNode.cpp
//  PR-3
//
//  Created by Marcus Shaw on 11/5/23.
//

#include "HuffmanNode.hpp"
using namespace std;
HuffmanNode::HuffmanNode(const char a, const int b) {
    data = a;
    freq = b;
    left = right = NULL;
}


