#pragma once

namespace BinaryTree {
	class MaxHeap {
	private:
		bool HealthCheck(HeapNode* current, int& currentHeight, int& diff); // for debug
	protected:
		unsigned int carry; // related to height
		unsigned int length;
		HeapNode* root;

		void Swap(HeapNode& node1, HeapNode& node2);

		//insert
		void Swim(HeapNode& target);
		void InsertNode(HeapNode& newNode);

		//remove
		void Sink(HeapNode& target);
		HeapNode* RemoveRoot();
	public:
		MaxHeap();
		~MaxHeap();

		bool IsEmpty();
		unsigned int GetLength();
		HeapNode* GetRoot();

		void Push(int key, string& data);
		HeapNode* Pop();

		void Clear();

		bool HealthCheck(); // for debug
	};
}
