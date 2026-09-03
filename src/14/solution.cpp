#include <iostream>
int* createNumber(int value) {
	int* p = new int(value);
	return p;
}

void clear_number(int* p) {
	delete p;

}