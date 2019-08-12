template <class T>
class Vector {
	private:
		T* arr;
		int len;
		int capacity;

	public:
		Vector() {
			this->arr = new T[16];
			this->len = 0;
			this->capacity = 16; 
		}
		
		int size() {
			return this->len;
		}

		bool isEmpty() {
			return this->len == 0;
		}

		T at(int index) {
			if (index >= this->len) {
				// error
			} else if (index < 0) {
				// error
			} else {
				return this->arr[index];
			}
		}

		void set(int index, T value) {
			if (index >= this->len) {
				// error
			} else if (index < 0) {
				// error
			} else {
				this->arr[index] = value;
			}
		}

		void clear() {
			for (auto value : this->arr) {
				value = NULL;
			}
			this->len = 0;
		}

		void push(T value) {
			if (this->len == this->capacity) {
				T* new_array = new T[2*this->capacity];
				std::memcpy(new_array, this->arr, sizeof(this->arr));
				delete[] this->arr;
				this->arr = new_array;
				this->capacity = 2*this->capacity;
			} else {
				this->arr[this->len-1] = value;
			}
			this->len++;
		}

		void insertAt(int index, T value) {
			if (this->len == this->capacity) {
				T* new_array = new T[2*this->capacity];
				int i = 0;
				while (i < this->len) {
					if (i == index) {
						new_array[i] = value;
					} else {
						new_array[i] = this->array[i];
						i++;
					}
				}
				delete[] this->arr;
				this->arr = new_array;
				this->capacity = 2*this->capacity;
			} else {
				for (int i = this->len-1, i > index; i--) {
					this->arr[i+1] = this->arr[i];
				}
				this->arr[index] = value;
			}

			this->len++;
		}

		T pop() {
			T last_value = this->arr[this->len-1];
			this->arr[this->len-1] = NULL;
			this->len--;
			return last_value;
		}

		void removeAt(int index) {
			for (int i = index; i < this->len; i++ {
				this->arr[i] = this->arr[i+1];
			}
			this->len--;	
		}

		void swap(int index1, int index2) {
			T temp = this->arr[index1];
			this->arr[index1] = this->arr[index2];
			this->arr[index2] = temp;
		}
};
