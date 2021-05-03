/* 
 * File:   LRUBufferPool.h
 * Author: Sean DeBarr
 */
#ifndef LRUBUFFERPOOL_H
#define LRUBUFFERPOOL_H

#include "BufferBlock.h"
#include "BufferPoolADT.h"
#include <stdio.h>
#include <fstream>

class LRUBufferPool : public BufferPoolADT {
private:
	int poolSize;
	int blockSize;
	BufferBlock **pool;
	fstream input;
	string file;

public:
	/*
	Constructor gets the filename of the file to be buffered,
	opens the file, and instantiates poolSize buffer blocks by
	reading the file and filling the blocks in order.  When the constructor
	is done the buffer pool blocks should be full with the beginning
	contents of the input file.
	*/
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) {
		this->file = filename;
		this->poolSize = poolSize;
		this->blockSize = blockSize;
		this->pool = new BufferBlock *[this->poolSize];

		input.open(this->file.c_str(), fstream::in | fstream::binary);

		for (int i = 0; i < this->poolSize; ++i) {
			char *data = new char[this->blockSize];

			input.seekg(i * this->blockSize);
			input.read(data, this->blockSize);

			this->pool[i] = new BufferBlock(data, this->blockSize);
			this->pool[i]->setID(i);
		}

		input.close();
	}

	~LRUBufferPool() {
		delete[] this->pool;
	}

	// Copy "sz" bytes from position "pos" of the buffered storage to "space".
	virtual void getBytes(char *space, int sz, int pos) override {
		int id = pos / this->blockSize;
		bool exists = false;
		int index;

		// See if block exists in pool
		for (int i = 0; i < this->poolSize; ++i) {
			if (this->pool[i]->getID() == id) {
				exists = true;
				index = i;
			}
		}

		if (exists) {
			BufferBlock *temp = this->pool[index];
			// Shift all blocks down by 1
			while (index > 0) {
				this->pool[index] = this->pool[index - 1];
				index--;
			}
			this->pool[0] = temp;

		} else {
			// Shift all blocks down by 1
			for (int i = this->poolSize - 1; i > 0; --i) {
				this->pool[i] = this->pool[i - 1];
			}
			char *data = new char[this->blockSize];

			input.open(this->file.c_str(), fstream::in | fstream::binary);
			input.seekg(id * this->blockSize);
			input.read(data, this->blockSize);

			BufferBlock *temp = new BufferBlock(data, this->blockSize);
			this->pool[0] = temp;
			temp->setID(id);
		}

		this->pool[0]->getData(pos, sz, space);
	}

	// Print the order of the buffer blocks using the block id numbers.
	virtual void printBufferBlockOrder() override {
		printf("My buffer block order from most recently used to LRU is:\n\t");

		for (int i = 0; i < this->poolSize; ++i) {
			printf("%d, ", this->pool[i]->getID());
		}
		printf("\n\n");
	}

	// Get the block id number of the least recently used buffer block.
	virtual int getLRUBlockID() override {
		return this->pool[0]->getID();
	}
};

#endif /* LRUBUFFERPOOL_H */