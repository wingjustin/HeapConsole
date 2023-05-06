#pragma once

#include <string>

using namespace std;

namespace BinaryTree {
	class HeapNode {
		int key;
		string* data;

		HeapNode* parent;
		HeapNode* left;
		HeapNode* right;

		friend class MaxHeap;
		friend class MinHeap;
	public:
		HeapNode(int key, string* data);
		~HeapNode();

		int GetKey();
		string* GetData();
	};
}
