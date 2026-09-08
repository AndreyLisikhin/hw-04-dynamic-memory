int* erase(const int* arr, int size, int index) {
	int* mass = new int[size - 1];
	for (int i = 0;i < size-1;i++) {
		if (i<index) {
			mass[i] = arr[i];
		}
		else {
			mass[i] = arr[i + 1];
		}

	}
	return mass;

}