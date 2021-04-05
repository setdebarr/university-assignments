/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Sean DeBarr
* CSIS 215-D02
*
* You may use this template to implement your Dictionary
*/

#ifndef BDICTIONARY_H
#define BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
	// constructors/destructor
	BDictionary(size_t dictSize) {
		dictionary = new ABag<KVpair<Key, E>>(dictSize);
	}
	~BDictionary() {
	}

	// methods: clear, insert, remove, removeAny, find, size, etc.

	// Reinitialize dictionary
	virtual void clear() override {
		this->dictionary->emptyBag();
	}

	// Insert a record into dictionary
	virtual bool insert(const Key &k, const E &e) override {
		KVpair<Key, E> temp(k, e);
		return *(this->dictionary) += temp;
	}

	// If a record is found, removes it
	virtual bool remove(const Key &k, E &rtnVal) override {
		KVpair<Key, E> temp(k, rtnVal);
		if (this->dictionary->remove(temp)) {
			rtnVal = temp.value();
			return true;
		}
		return false;
	}

	// Removes the last item in the dictionary
	virtual bool removeAny(E &returnValue) override {
		KVpair<Key, E> temp;
		if (this->dictionary->removeTop(temp)) {
			returnValue = temp.value();
			return true;
		}
		return false;
	}

	// Finds record in dictionary
	virtual bool find(const Key &k, E &returnValue) const override {
		KVpair<Key, E> temp(k, returnValue);
		if (this->dictionary->find(temp)) {
			returnValue = temp.value();
			return true;
		}
		return false;
	}

	// Returns the size of the dictionary
	virtual int size() override {
		return dictionary->size();
	}

private:
	//Pointer to a ABag object.  You'll need to instantiate the bag in your constructor:
	// dictionary = new ABag<KVpair<Key, E>>(size) or something similar depending on how
	// you've implemented your ABag constructor(s).
	//This pointer gives you access to the bag which stores your data and provides the
	//functions you need to build your dictionary.
	ABag<KVpair<Key, E>> *dictionary;
};

#endif /* BDICTIONARY_H */
