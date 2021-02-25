//
//  Vector.h
//  Vector
//
//  Created by Jeff Thibault on 10/16/19.
//  Copyright © 2019 Jeff Thibault. All rights reserved.
//

#include <iostream>

template <typename T> class Vector {
private:
    T* array;
    int length;
    int capacity;

    void expand() {
        T* newArray = new T[2*this->capacity];
        std::copy(this->array, this->array+this->length, newArray);
        delete[] this->array;
        this->array = newArray;
        this->capacity = 2*this->capacity;
    }

public:
    Vector() {
        this->array = new T[16];
        this->length = 0;
        this->capacity = 16;
    }

    int size() {
        return this->length;
    }

    bool isEmpty() {
        return this->length == 0;
    }

    T at(int index) {
        assert(0 <= index < this->length);
        return this->array[index];
    }

    void set(int index, T value) {
        assert(0 <= index < this->length);
        this->array[index] = value;
    }

    void clear() {
        for (auto value : this->array) {
            value = nullptr;
        }
        this->length = 0;
    }

    void push(T value) {
        if (this->length == this->capacity) {
            this->expand();
        }
        this->array[this->length] = value;
        
        this->length++;
    }

    void insertAt(int index, T value) {
        assert(0 <= index < this->length);
        if (index == this->length) {
            this->push(value);
            return;
        }
        
        if (this->length == this->capacity) {
            this->expand();
        }
        
        for (int i = this->length-1; i >= index; i--) {
            this->array[i+1] = this->array[i];
        }
        this->array[index] = value;

        this->length++;
    }

    T pop() {
        T lastElement = this->array[this->length-1];
        this->length--;
        return lastElement;
    }

    void removeAt(int index) {
        for (int i = index; i < this->len; i++) {
            this->arr[i] = this->arr[i+1];
        }
        this->len--;
    }

    void swap(int index1, int index2) {
        T temp = this->array[index1];
        this->array[index1] = this->array[index2];
        this->array[index2] = temp;
    }
    
    void print() {
        std::cout << "[ ";
        for (int i = 0; i < this->length; i++) {
            std::cout << this->array[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    ~Vector() {
        delete[] this->array;
        this->array = nullptr;
    }
};
