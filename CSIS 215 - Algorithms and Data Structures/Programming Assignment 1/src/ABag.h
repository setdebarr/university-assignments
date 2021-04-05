/*
* File:   ABag.h
* Author: Sean DeBarr
* CSIS 215-D02
*
* You may use this template to implement your ABag. 
*/

#ifndef ABAG_H
#define ABAG_H

#include "bagADT.h"
#include "book.h"

template <typename E>
class ABag : public Bag<E> {
public:
	// constructors/destructor
	ABag() {}
	ABag(size_t size) {
		this->capacity = size;
		data = new E[bagCapacity()];
		this->used = 0;
	}
	~ABag() {
		delete this->data;
		this->used = 0;
		this->capacity = 0;
	}

	// bag methods: addItem, remove, operator+=, size, etc.

	// Insert a new item into the bag
	virtual bool addItem(const E &item) override {
		if (size() == bagCapacity()) {
			return false;
		}

		data[size()] = item;
		this->used++;
		return true;
	}

	// Removes an item from the bag
	virtual bool remove(E &item) override {
		if (size() == 0) {
			return false;
		}

		for (int i = 0; i < size(); ++i) {
			if (data[i] == item) {
				item = data[i];
				// Shifts each element down by one
				for (int n = i; n < size() - 1; ++n) {
					data[n] = data[n + 1];
				}
				this->used--;
				return true;
			}
		}

		return false;
	}

	// Removes the last item from the bag
	virtual bool removeTop(E &returnValue) override {
		if (size() == 0) {
			return false;
		}

		inspectTop(returnValue);
		this->used--;

		return true;
	}

	// Finds an item in the bag
	virtual bool find(E &returnValue) const override {
		for (int i = 0; i < size(); ++i) {
			if (data[i] == returnValue) {
				returnValue = data[i];
				return true;
			}
		}
		return false;
	}

	// Looks at the last item in the bag
	virtual bool inspectTop(E &item) const override {
		if (size() == 0) {
			return false;
		}

		item = data[size() - 1];
		return true;
	}

	// Empties the bag
	virtual void emptyBag() override {
		this->used = 0;
	}

	// Adds an item to the bag
	virtual bool operator+=(const E &addend) override {
		return addItem(addend);
	}

	// Gets the size of the bag
	virtual int size() const override {
		return this->used;
	}

	// Gets the capacity of the bag
	virtual int bagCapacity() const override {
		return this->capacity;
	}

private:
	E *data; // an array of items
	int used; // number of items the data array currently holds
	size_t capacity; // the number of items the bag can hold (size of array)
};

#endif /* ABAG_H */
