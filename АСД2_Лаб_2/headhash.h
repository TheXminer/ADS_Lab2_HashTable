#pragma once
#include <iostream>
#define loadFactor 0.4//0.4
#define koef 5//5

using namespace std;

struct Node {
    Node() {
        asymptotic = 0;
        name = "-";
        usefulness = "-";
    }

    Node(int anAsymptotic, string aName, string aUsefulness):
        asymptotic(anAsymptotic),
        name(aName),
        usefulness(aUsefulness) {}
    
    int asymptotic;
    string name;
    string usefulness;
};

struct HashNode {
    long long key;
    Node node;
    HashNode* next;
};

struct LinkedList {
private:
    HashNode* head = nullptr;
public:
    void push_front(long long key, Node list);
    HashNode* get(long long key);
    HashNode* pop_front();
    int size();
    bool remove(long long key);
};

struct HashTable {
private:
    int N = 1000;
    int hashSize = 0;
    LinkedList* bucketsArray = new LinkedList[N];
    int hash(long long key);
public:
    void insert(long long key, Node node);
    Node* find(long long key);
    void erase(long long key);
    int size();
};