#include <iostream>
#include "linked_list.h"

int main() {
	LinkedList<int> myList;
	myList.push_back(24);
	std::cout << myList << std::endl;
	myList.push_back(12);
	std::cout << myList << std::endl;
	myList.pop_back();
	std::cout << myList << std::endl;
	return 0;
}
