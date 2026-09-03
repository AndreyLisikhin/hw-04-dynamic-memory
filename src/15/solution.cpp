#include <iostream>
int* createArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size;  i++) {
		arr[i] = 0;
	}
	return arr;
}
void clear_array(int* p) {
	delete[] p;
}