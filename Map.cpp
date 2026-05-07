#include "Map.h"
#include "MapIterator.h"

// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
Map::Map() {
	this->head = nullptr;
	this->tail = nullptr;
	this->nrElements = 0;
}

// Best Case: Theta(n)
// Worst Case: Theta(n)
// Total Complexity: Theta(n)
Map::~Map() {
	DLLNode* current = this->head;
	while (current != nullptr) {
		DLLNode* next = current->next;
		delete current;
		current = next;
	}
}

// Best Case: Theta(1)
// Worst Case: Theta(n)
// Total Complexity: O(n)
TValue Map::add(TKey c, TValue v){
	DLLNode* current = this->head;
	while (current != nullptr) {
		if (current->info.first == c) {
			TValue oldValue = current->info.second;
			current->info.second = v;
			return oldValue;
		}
		current = current->next;
	}
	
	DLLNode* newNode = new DLLNode(std::make_pair(c, v), nullptr, this->tail);
	if (this->tail != nullptr) {
		this->tail->next = newNode;
	} else {
		this->head = newNode;
	}
	this->tail = newNode;
	this->nrElements++;
	
	return NULL_TVALUE;
}

// Best Case: Theta(1)
// Worst Case: Theta(n)
// Total Complexity: O(n)
TValue Map::search(TKey c) const{
	DLLNode* current = this->head;
	while (current != nullptr) {
		if (current->info.first == c) {
			return current->info.second;
		}
		current = current->next;
	}
	return NULL_TVALUE;
}

// Best Case: Theta(1)
// Worst Case: Theta(n)
// Total Complexity: O(n)
TValue Map::remove(TKey c){
	DLLNode* current = this->head;
	while (current != nullptr) {
		if (current->info.first == c) {
			TValue oldValue = current->info.second;
			if (current == this->head && current == this->tail) {
				this->head = nullptr;
				this->tail = nullptr;
			} else if (current == this->head) {
				this->head = this->head->next;
				this->head->prev = nullptr;
			} else if (current == this->tail) {
				this->tail = this->tail->prev;
				this->tail->next = nullptr;
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			delete current;
			this->nrElements--;
			return oldValue;
		}
		current = current->next;
	}
	return NULL_TVALUE;
}


// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
int Map::size() const {
	return this->nrElements;
}

// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
bool Map::isEmpty() const{
	return this->nrElements == 0;
}

// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
MapIterator Map::iterator() const {
	return MapIterator(*this);
}



