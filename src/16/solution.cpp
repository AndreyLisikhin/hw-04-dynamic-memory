
int* copy(const int* arr, int size) {
	int* newarr = new int[size];
	for (int i = 0; i < size;i++) {
		newarr[i] = arr[i];
	}
	return newarr;
}