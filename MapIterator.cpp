#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
MapIterator::MapIterator(const Map& m) : map(m)
{
	this->current = m.head;
}


// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
void MapIterator::first() {
	this->current = map.head;
}


// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
void MapIterator::next() {
	if (!this->valid()) {
		throw std::exception();
	}
	this->current = this->current->next;
}


// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
TElem MapIterator::getCurrent(){
	if (!this->valid()) {
		throw std::exception();
	}
	return this->current->info;
}


// Best Case: Theta(1)
// Worst Case: Theta(1)
// Total Complexity: Theta(1)
bool MapIterator::valid() const {
	return this->current != nullptr;
}



