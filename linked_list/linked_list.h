#include <iostream>

template <typename T> class LinkedList {
	private:
		struct Node {
			T data;	
			Node* next;
			Node* prev;
		};
		
		Node* head;
		Node* tail;
		int length;

	public:
		LinkedList() {
			this->head = nullptr;
			this->tail = nullptr;
			this->length = 0;
		}

		int size() {
			return this->length;
		}

		bool isEmpty() {
			return this->length == 0;
		}

		T front() {
			return this->head->data;
		}

		T back() {
			return this->tail->data;
		}

		void push_front(T data) {
			Node* newNode = new Node {data, this->head, nullptr};
			if (this->length == 0) {
				this->head = newNode;
				this->tail = newNode;
			} else {	
				this->head->prev = newNode;
				this->head = this->head->prev;
			}
			this->length++;
		}

		void pop_front() {
			this->head = this->head->next;
			delete this->head->prev;
			this->length--;
		}

		void push_back(T data) {
			Node* newNode = new Node {data, nullptr, this->tail};
			if (this->length == 0) {
				this->head = newNode;
				this->tail = newNode;
			} else {
				this->tail->next = newNode;
				this->tail = this->tail->next;
			}
			this->length++;
		}		

		void pop_back() {
			this->tail = this->tail->prev;
			delete this->tail->next;
			this->tail->next = nullptr;
			this->length--;
		}

		void insertAt(int index, T data) {
			Node* iter = this->head;
			for (int i = 0; i < index; i++) {
				iter = iter->next;
			}

			Node* newNode = new Node {data, iter, iter->prev};
			iter->prev->next = newNode;
			iter->prev = newNode;
			this->legnth++;
		}

		void removeAt(int index) {
			if (index == 0)
				this->pop_front();
			else if (index == this->size-1)
				this->pop_back();
			else {
				Node* iter = this->head;
				for (int i = 0; i < index; i++) {
					iter = iter->next;
				}

				iter->prev->next = iter->next;
				iter->next->prev = iter->prev;
				delete iter;
				this->length--;
			}
		}

		void clear() {
			Node* iter = this->head;
			for (int i = 0; i < this->size; i++) {
				delete iter;
			}
			this->head = nullptr;
			this->tail = nullptr;
		}


		void reverse() {
			this->head = this->tail;
			Node* iter = this->tail;
			while (iter != nullptr) {
				Node* temp = iter->next;
				iter->next = iter->prev;
				iter->prev = temp;
				iter = iter->next;
			}
			this->tail = iter->prev;
		}

		void toString() {
			Node* iter = this->head;
			std::cout << "[ ";
			while (iter != nullptr) {
				std::cout << iter->data << " ";
				iter = iter->next;
			}
			std::cout << "]" << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, LinkedList& list) {
			Node* iter = list.head;
			os << "[ ";
			while (iter != nullptr) {
				os << iter->data << " ";
				iter = iter->next;
			}
			os << "]";
			return os;
		}
};
