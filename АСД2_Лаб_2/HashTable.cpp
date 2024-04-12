#include "headhash.h"

int HashTable::hash(long long key) {
	key = key % N;
	return key;
}

void HashTable::insert(long long key, Node node) {
	if ((double)size() / N >= loadFactor) {
		N *= koef;
		LinkedList* newList = new LinkedList[N];
		for (int i = 0; i < N / koef; i++) {
			bool isEmpty = false;
			while (!isEmpty) {
				HashNode* savedNode = bucketsArray[i].pop_front();
				if (savedNode) {
					int bucketNumber = hash(savedNode->key);
					HashNode* change = newList[bucketNumber].get(savedNode->key);
					if (change) {
						change->key = savedNode->key;
						change->node = savedNode->node;
					}
					else
						newList[bucketNumber].push_front(savedNode->key, savedNode->node);
					delete savedNode;
				}
				else
					isEmpty = true;
			}
		}
		delete[] bucketsArray;
		bucketsArray = newList;
	}

	int bucketNumber = hash(key);
	Node* change = find(key);
	if (change) {
		*change = node;
		return;
	}
	bucketsArray[bucketNumber].push_front(key, node);
	hashSize++;
}

Node* HashTable::find(long long key) {
	int bucketNumber = hash(key);
	HashNode* returnNode = bucketsArray[bucketNumber].get(key);
	if(returnNode)
		return &returnNode->node;
	return nullptr;
}

void HashTable::erase(long long key) {
	int bucketNumber = hash(key);
	if(bucketsArray[bucketNumber].remove(key))
		hashSize--;
}

int HashTable::size() {
	return hashSize;
}
