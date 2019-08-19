template <typename T> class LinkedList {
	private:
		struct Node = {
			T data;	
			Node* next;
			Node* prev;
		};
	
		int size;

	public:
		T* head;
		T* tail;

		LinkedList() {
			this->head = NULL;
			this->tail = NULL;
			this->size = 0;
		}

		int size() {
			return this->size;
		}

		bool isEmpty() {
			return this->size == 0;
		}

		T front() {
			return this->head->data;
		}

		T back() {
			return this->tail->data;
		}

		void push_front(T data) {
			Node* newNode = new Node {data, this->head, NULL};
			this->head->prev = newNode;
			this->head = newNode;
			this->size++;
		}

		void pop_front() {
			this->head = this->head->next;
			delete this->head->prev
			this->size--;
		}

		void push_back(T data) {
			Node* newNode = new Node {data, NULL, this->tail};
			this->tail->next = newNode;
			this->tail = newNode;
			this->size++;
		}		

		void pop_back() {
			this->tail = this->tail->prev;
			delete this->tail->next
			this->tail->next = NULL;
			this->size--;
		}

		void insertAt(int index, T data) {
			Node* iter = this->head;
			for (int i = 0; i < index; i++) {
				iter = iter->next;
			}

			Node* newNode = new Node {data, iter, iter->prev};
			iter->prev->next = newNode;
			iter->prev = newNode;
			this->size++;
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
				this->size--;
			}
		}

		void clear() {
			Node* iter = this->head;
			for (int i = 0; i < this->size; i++) {
				delete iter;
			}
			this->head = NULL;
			this->tail = NULL;
		}


		void reverse() {
			this->head = this->tail;
			Node* iter = this->tail;
			while (iter != NULL) {
				Node* temp = iter->next;
				iter->next = iter->prev;
				iter-prev = temp;
				iter = iter->next;
			}
			this->tail = iter->prev;
		}
};
