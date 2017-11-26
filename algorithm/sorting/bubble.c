void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int arr[], int size) {
	int i, j;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size-i; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
