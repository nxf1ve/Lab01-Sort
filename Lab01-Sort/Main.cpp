#include <iostream>
using namespace std;

void swap(int& firstElement, int& secondElement) {
	int temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}
void shakerSort(int array[], int n) {
	bool swapped = 1;
	int start = 0;
	int end = n - 1;
	while (swapped) {
		swapped = 0;
		for (int i = start; i < end; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		--end;
		swapped = 0;
		for (int i = end - 1; i >= start; --i) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				swapped = 1;
			}
		}
		++start;
	}
}


void merge(int array[], int start, int middle, int end, int tempArray[]) {
	int left = start;
	int right = middle + 1;
	int length = end - start + 1;
	for (int i = 0; i < length; i++) {
		if (right > end || (left <= middle && array[left] < array[right])) {
			tempArray[i] = array[left];
			left++;
		}
		else {
			tempArray[i] = array[right];
			right++;
		}
	}
	for (int i = 0; i < length; i++)
		array[i + start] = tempArray[i];
}

void mergeSort(int array[], int start, int end, int tempArray[]) {
	if (start == end) return;
	int middle = (start + end) / 2;
	mergeSort(array, start, middle, tempArray);
	mergeSort(array, middle+1, end, tempArray);
	merge(array, start, middle, end, tempArray);

}

void main() {
	int array[] = { 211, 156, -12, 31, 214, 1211 };
	const int n = sizeof(array) / sizeof(array[0]);
	int tempArray[n];
	cout << "Initial array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	//shakerSort(array, n);
	mergeSort(array, 0, n - 1, tempArray);
	cout << "\nSorted array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}


}