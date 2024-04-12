#include "openHashHeader.h"

int OpenHashTable::hash(long long key) {
	return key % N;
}

void OpenHashTable::insert(long long key, Node node) {
	int currentKey = hash(key);
	Node* getNode = find(key);
	if (getNode) {
		*getNode = node;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (currentKey + alpha * i >= N) {
			currentKey -= N;
		}
		if (hashArray[currentKey + alpha * i].key == -1) {
			hashArray[currentKey + alpha * i].node = node;
			hashArray[currentKey + alpha * i].removed = false;
			currentSize++;
			return;
		}
	}
}

Node* OpenHashTable::find(long long key) {
	int startKey = hash(key);
	int currentKey = startKey;
	//if (hashArray[currentKey].key == -1 && !hashArray[currentKey].removed)
	//	return nullptr;
	//currentKey++;
	//while (currentKey != startKey && hashArray[currentKey].key != -1 || hashArray[currentKey].removed) {
		//if (currentKey == N)
		//	currentKey = 0;
	//	if (hashArray[currentKey].key == key)
	//		return &hashArray[currentKey].node;
	//	currentKey++;
	//}
	for (int i = 0; i < N; i++) {
		if (hashArray[currentKey].key == -1 && !hashArray[currentKey].removed)
			return nullptr;
		if (currentKey == N)
			currentKey = 0;
		if (hashArray[currentKey].key == key)
			return &hashArray[currentKey].node;
	}
	return nullptr;
}

void OpenHashTable::erase(long long key) {
	int startKey = hash(key);
	int currentKey = startKey;
	if (hashArray[currentKey].key == key) {
		hashArray[currentKey].key = -1;
		hashArray[currentKey].removed = true;
	}
	if (hashArray[currentKey].key == -1 && !hashArray[currentKey].removed)
		return;
	currentKey++;
	while (currentKey != startKey && hashArray[currentKey].key != -1 || hashArray[currentKey].removed) {
		if (currentKey == N)
			currentKey = 0;
		if (hashArray[currentKey].key == key) {
			hashArray[currentKey].key = -1;
			hashArray[currentKey].removed = true;
			currentSize--;
			return;
		}
		currentKey++;
	}
}

int OpenHashTable::size() {
	return currentSize;
}