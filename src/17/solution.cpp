int* concat(const int* a, int size_a, const int* b, int size_b) {
	int* mass = new int[size_a + size_b];
	for (int i = 0;i < size_a + size_b;i++) {
		if (i < size_a) {
			mass[i] = a[i];
		}
		else {
			mass[i] = b[i - size_a];
		}
	}
	return mass;

}