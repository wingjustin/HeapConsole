#include "HeapNode.h"

using namespace BinaryTree;

HeapNode::HeapNode(const int key, string* const data) {
	HeapNode::key = key;
	HeapNode::data = data;

	HeapNode::parent = NULL;
	HeapNode::left = NULL;
	HeapNode::right = NULL;
}

HeapNode::~HeapNode() {
	delete left;
	delete right;

	data = NULL;

	parent = NULL;
	left = NULL;
	right = NULL;
}

int HeapNode::GetKey() {
	return key;
}

string* HeapNode::GetData() {
	return data;
}
