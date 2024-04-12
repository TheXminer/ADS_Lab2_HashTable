#include "headhash.h"

void LinkedList::push_front(long long key, Node node) {
	HashNode* newNode = new HashNode();
	newNode->key = key;
	newNode->node = node;
	newNode->next = head;
	head = newNode;
}

HashNode* LinkedList::get(long long key) {
	HashNode* getNode = head;
	if (!head)
		return nullptr;
	while (getNode) {
		if (getNode->key == key)
			return getNode;
		getNode = getNode->next;
	}
	return nullptr;
}

HashNode* LinkedList::pop_front() {
	if (!head)
		return nullptr;
	HashNode* save_head = head;
	head = head->next;
	return save_head;
}

int LinkedList::size() {
	HashNode* checkNode = head;
	int current_size = 0;
	while (checkNode) {
		checkNode = checkNode->next;
		current_size++;
	}
	return current_size;
}

bool LinkedList::remove(long long key) {
	HashNode* deleteNode = head;
	HashNode* link = nullptr;
	int counter = 0;
	while (deleteNode) {
		if (deleteNode->key == key) {
			if (link)
				link->next = deleteNode->next;
			else
				head = head->next;
			delete deleteNode;
			return true;
		}
		link = deleteNode;
		deleteNode = deleteNode->next;
	}
	return false;
}

//void LinkedList::clear() {
//	while (head) {
//		HashNode* save_head = head;
//		head = head->next;
//		delete save_head;
//	}
//}

//void LinkedList::incert(Node node, int position) {
//	if (position <= 0)
//		return;
//	if (!head || position == 1) {
//		push_front(node);
//		return;
//	}
//	HashNode* checkNode = head;
//	for (int i = 1; i < position - 1; i++) {
//		if (!checkNode->next) {
//			return;
//		}
//		checkNode = checkNode->next;
//	}
//	HashNode* newNode = new HashNode();
//	newNode->node = node;
//	newNode->next = checkNode->next;
//	checkNode->next = newNode;
//}