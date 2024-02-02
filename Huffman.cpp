//
//  Huffman.cpp
//  PR-3
//
//  Created by Marcus Shaw on 11/4/23.
//

#include "Huffman.hpp"
using namespace std;

class Compare { // I did not think it was worth making another header and class for just Compare
public:
    bool operator() (HuffmanNode* a, HuffmanNode* b) { // this is to define the priority as frequency
        return a->freq > b->freq;
    }
};



Huffman::Huffman() {
    
}

map<char, int> Huffman::tableCreation(string a) {
    map<char, int> table; // this is the table of the frequency of characters
    for(int i = 0; i < a.size(); i++) {
        table[a.at(i)] += 1;
    }
    return table;
}

void Huffman::huffmanBuildTree(string a) {
    map<char, int> table = tableCreation(a); // this is to get the frequency table
    
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> nodes;
    map<char, int>:: iterator it = table.begin();
    
    while (it != table.end()) { // putting all the values into the priority queue
        HuffmanNode* newNode = new HuffmanNode(it->first, it->second);
        nodes.push(newNode);
        it++;
    }
    
    while ( nodes.size() != 1) { // this is to fully build out the Huffman Encoding Tree with the priority queue
        HuffmanNode* left = nodes.top();
        nodes.pop();
        
        HuffmanNode* right = nodes.top();
        nodes.pop();
        
        HuffmanNode* node = new HuffmanNode('@', left->freq + right->freq);
        node->left = left;
        node->right = right;
        
        nodes.push(node);
    }
    
    HuffmanNode* root = nodes.top();
    
    char arr[100], top = 0;
    setKey(root, arr, top);
    huffmanCodes();
    
    
    
}

void Huffman::setKey(HuffmanNode *root, char arr[], int top) {
    
    if(root->left) {
        arr[top] = '0';
        setKey(root->left, arr, top+1);
    }
    if(root->right) {
        arr[top] = '1';
        setKey(root->right, arr, top+1);
    }
    
    if(!root->left && !root->right) {
        string str1;
        int i = 0;
        while(i < top) {
            str1 = str1 + arr[i];
            i++;
        }
       
        key[root->data] = str1;
    }
}

void Huffman::huffmanCodes() {
    map<char, string>:: iterator it = key.begin();
    cout << '\n' << "Huffman Codes are: " << '\n'<< '\n';
    while (it != key.end()) {
        cout << "character: " << it->first << " string: " << it->second << '\n';
        it++;
    }

}
string Huffman::compress(string a) {
    string str1;
    for(int i = 0; i < a.size(); i++) {
        str1 = str1 + key[a.at(i)]; // this is to make the string that I will use to send to the main
    }
    return str1;
}
string Huffman::decompress(string a) {
    map<string, char> invKey; // this is the inverse map of the key map to use it more easily for decompression
    string cmp; // this will be used to compare the original string to the key
    string str1; // this I will use as the string to return
    map<char, string>:: iterator it = key.begin();
    while(it != key.end()) {
        invKey[it->second] = it->first;
        it++;
    }
    map<string, char>:: iterator hi;
    
    for(int i = 0; i < a.size(); i++) {
        cmp = cmp + a.at(i);
        hi = invKey.find(cmp);
        if(hi != invKey.end()) {
            str1 = str1 + hi->second;
            cmp.clear();
        }
    }
    
    return str1;
}

