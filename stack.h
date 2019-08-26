#include "linked_list.h"

template <typename T> class Stack {
	private:
		LinkedList<T> list;
		int size;

	public:
		Stack() {
			this->size = 0;
		}

		int size() {
			return this->size;
		}

		bool isEmpty() {
			return this->size == 0;
		}

		void push(T data) {
			this->list->push_back(data);
		}

		T pop() {
			T top = *this->list->tail;
			this->list->pop_back();
			return top;
		}
}
