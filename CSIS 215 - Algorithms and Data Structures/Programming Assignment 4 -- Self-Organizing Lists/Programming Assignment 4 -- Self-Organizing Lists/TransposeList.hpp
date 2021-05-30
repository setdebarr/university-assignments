#include "SelfOrderedListADT.h"

template <typename E>
class TransposeList : public SelfOrderedListADT<E> {
private:
	Link<E> *head;      // Pointer to list header
	Link<E> *tail;      // Pointer to last element
	int sz;				// Size of list
	int compares;		// Number of compares
public:

	TransposeList() {
		this->sz = 0;
		this->compares = 0;
		this->tail = new Link<E>;
		this->head = this->tail;
	}
	~TransposeList() {

	}

	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	virtual bool find(const E &it) override {
		bool found = false;
		Link<E> *curr = this->head;

		while(curr->next != NULL && !found) {
			curr = curr->next;
			this->compares++;

			if(curr->element == it) {
				found = true;

				if(curr->prev != this->head) {
					Link<E> *temp = curr->prev;
					
					curr->count++;
					curr->prev = temp->prev;
					temp->prev->next = curr;
					temp->prev = curr;
					temp->next = curr->next;
					curr->next = temp;
					
					if(this->tail != curr) {
						temp->next->prev = temp;
					}else {
						temp->next = NULL;
						this->tail = temp;
					}
				}
				break;
			}
		}
		if(!found) {
			add(it);
		}
		return found;
	}

	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is
	//read without your re-order method being called (or the number of compares
	//being incremented.
	//Add new 'it' to the list
	virtual void add(const E &it) override {
		Link<E> *curr = new Link<E>(it, this->tail, this->tail->next);

		if(this->head == this->tail) {
			this->head->next = curr;
		} else {
			this->tail->next = curr;
		}

		this->tail = curr;
		this->sz++;
	}

	//Returns the number of accumulated compares
	virtual int getCompares() const override {
		return this->compares;
	}

	//Returns the size of the list
	virtual int size() const override {
		return this->sz;
	}

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	virtual void printlist() override {
		Link<E> *curr = this->head;

		while(curr->next != NULL) {
			curr = curr->next;
			std::cout << curr->element << "-" << curr->count << " ";
		}
		printf("\n");
	}

	virtual void printlist(int n) override {
		Link<E> *curr = this->head;
		int i = 0;

		while(curr->next != NULL && i < n) {
			++i;
			curr = curr->next;
			std::cout << curr->element << "-" << curr->count << " ";
		}
		printf("\n");
	}
};