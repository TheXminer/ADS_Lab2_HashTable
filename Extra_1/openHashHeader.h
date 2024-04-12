#pragma once
#include <iostream>
#define alpha 1

using namespace std;

struct Node {
    Node() {
        asymptotic = 0;
        name = "-";
        usefulness = "-";
    }

    Node(int anAsymptotic, string aName, string aUsefulness) :
        asymptotic(anAsymptotic),
        name(aName),
        usefulness(aUsefulness) {}

    int asymptotic;
    string name;
    string usefulness;
};

struct HashNode {
    long long key = -1;
    bool removed = false;
    Node node;
};

struct OpenHashTable {
private:
    int N = 10000;
    int currentSize = 0;
    HashNode* hashArray = new HashNode[N];
    int hash(long long key);
public:
    void insert(long long key, Node node);
    Node* find(long long key);
    void erase(long long key);
    int size();
};