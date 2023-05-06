#pragma once

namespace Sort {
	class HeapSort {
	private:
		static void Swap(int& left, int& right);
		//static void Swap(int arr[], int left, int right);
		static void FirstMaxHeapify(int arr[], int length);
		static void MaxHeapify(int arr[], int currentIndex, int length);
	public:
		static void Sort(int arr[], int length);
	};
}
