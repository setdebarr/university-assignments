/* 
 * File:   BufferBlock.h
 * Author: Sean DeBarr
 */
#ifndef LRUBUFFERBLOCK_H
#define LRUBUFFERBLOCK_H

#include "BufferBlockADT.h"
#include "constants.h"
#include <stdio.h>

class BufferBlock : public BufferblockADT {
private:
	int blockID;
	int blockSize;
	char *block;

public:
	BufferBlock() {}
	BufferBlock(char *data, int sz = 4096) {
		this->blockSize = sz;
		// Create block with proper size
		block = getCharArray(sz);

		// Fill each block with data
		for (int i = 0; i < this->blockSize; ++i) {
			block[i] = data[i];
		}
	}

	~BufferBlock() {
		delete[] this->block;
	}

	// Read the block from pos to pos + sz-1 (or to the end of the block)
	virtual void getData(int pos, int sz, char *data) override {
		// Get position of data in block
		pos = pos % this->blockSize;

		for (int i = 0; i < sz; ++i) {
			data[i] = block[pos + i];
		}
	}

	// Sets the block ID
	virtual void setID(int id) override {
		this->blockID = id;
	}

	// Returns the block ID
	virtual int getID() const override {
		return this->blockID;
	}

	// Returns the block size
	virtual int getBlocksize() const override {
		return this->blockSize;
	}

	// Returns the block
	virtual char *getBlock() const override {
		return this->block;
	}

	// Sets the block
	virtual void setBlock(char *blk) override {
		this->block = blk;
	}
};

#endif /* LRUBUFFERBLOCK_H */