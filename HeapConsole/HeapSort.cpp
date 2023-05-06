#include "HeapSort.h"

using namespace Sort;

void HeapSort::Sort(int arr[], const int length) {
	FirstMaxHeapify(arr, length);
	int remainLength = length;
	Swap(arr[0], arr[--remainLength]);
	while (remainLength > 0) {
		MaxHeapify(arr, 0, remainLength); // heapify root
		Swap(arr[0], arr[--remainLength]);
	}
}

void HeapSort::FirstMaxHeapify(int arr[], const int length) {
	//int current = (length >> 1) + ~0;
	int current = (length >> 1) - 1; // last parent index = Length / 2 -1
	while (current > -1) {
		MaxHeapify(arr, current--, length);
	}
}

//parent = (i - 1)/2, left child = 2i+1, right child = 2i+2
void HeapSort::MaxHeapify(int arr[], const int currentIndex, const int length) {
	int currentChild = currentIndex;
	int leftChild = (currentChild << 1) + 1;
	int rightChild = leftChild + 1;
	bool hasChild = leftChild < length;
	while (hasChild) {
		if (rightChild < length
			&& arr[rightChild] > arr[currentChild]
			&& arr[rightChild] > arr[leftChild]) {
			Swap(arr[rightChild], arr[currentChild]);
			currentChild = rightChild; // go to rigth child
			leftChild = (currentChild << 1) + 1;
			rightChild = leftChild + 1;
			hasChild = leftChild < length;
		}
		else if (arr[leftChild] > arr[currentChild]) {
			Swap(arr[leftChild], arr[currentChild]);
			currentChild = leftChild; // go to left child
			leftChild = (currentChild << 1) + 1;
			rightChild = leftChild + 1;
			hasChild = leftChild < length;
		}
		else
			return; // hasChild = false;
	}
}

void HeapSort::Swap(int& left, int& right) {
	if (left == right)
		return;
	const int temp = left;
	left = right;
	right = temp;
}
