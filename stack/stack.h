//
//  main.cpp
//  Stack
//
//  Created by Jeff Thibault on 10/17/19.
//  Copyright © 2019 Jeff Thibault. All rights reserved.
//

#include "LinkedList.h"

template <typename T> class Stack {
	private:
		LinkedList<T> list;
		int length;

	public:
		Stack() {
			this->length = 0;
		}

		int size() {
			return this->length;
		}

		bool isEmpty() {
			return this->length == 0;
		}

		void push(T data) {
			this->list->pushBack(data);
		}

		T pop() {
			T top = this->list->back();
			this->list->popBack();
			return top;
		}
}
