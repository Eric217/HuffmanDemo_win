#pragma once
#ifndef MinHeap_hpp
#define MinHeap_hpp
#include "HuffmanTree.hpp" 

template <typename T>
inline void mySwap(T & v1, T & v2) {
	T temp = v2;
	v2 = v1;
	v1 = temp;
}

///返回的index
template <typename T>
inline int maxChild(T * arr, int leftChld, int length) {
	if (leftChld + 1 == length || arr[leftChld] > arr[leftChld + 1])
		return leftChld;
	return leftChld + 1;
}
 
class MinHeap {
	Huffman * element;
	int maxSize;
	int currentSize;

public:
	MinHeap() {}
	MinHeap(Huffman * arr, int length, int maxSize = -1);
	~MinHeap() { delete[] element; }

	int size() const { return currentSize; }
	Huffman min() const { return element[0]; }
	bool empty() const { return !currentSize; }
	bool full() const { return currentSize == maxSize; }
	void deactive() { element = 0; maxSize = currentSize = 0; }

	MinHeap & push(const Huffman &);
	MinHeap & pop(Huffman &);
	MinHeap & pop();
};

 
MinHeap & MinHeap::push(const Huffman & t) {
	int i = currentSize + 1;
	if (currentSize == maxSize)
		throw NoMemory();
	++currentSize; //t从新的叶节点开始 沿着树上升
	
	while (i != 1 && element[i / 2 - 1] > t) {
		element[i - 1] = element[i / 2 - 1];
		i /= 2;
	}
	element[i - 1] = t;

	return *this;
}


//template <typename T>
MinHeap & MinHeap::pop(Huffman & receiver) {
	if (!currentSize)
		throw OutOfBounds();
	receiver = element[0];
	Huffman data = element[--currentSize];
	element[currentSize] = receiver;
	if (!currentSize)
		return *this;
	int i = 1; //下标
	while (i < currentSize) {
		if (i + 1 < currentSize && element[i] > element[i + 1])
			i++;
		if (data < element[i])
			break;
		element[(i + 1) / 2 - 1] = element[i];
		i = i * 2 + 1;
	}
	element[(1 + i) / 2 - 1] = data;
	return *this;
}

//template <typename T>
MinHeap::MinHeap(Huffman * arr, int length, int mxs) {
	element = arr;
	maxSize = (mxs == -1 ? length : mxs);
	currentSize = length;

	for (int i = currentSize / 2; i > 0; i--) {
		Huffman t = arr[i - 1];
		int c_idx = 2 * i - 1;
		while (c_idx + 1 <= currentSize) {
			if (c_idx + 1 < currentSize && arr[c_idx] > arr[c_idx + 1])
				c_idx++;
			if (t < arr[c_idx])
				break;
			arr[i - 1] = arr[c_idx];
			c_idx = c_idx * 2 + 1;
		}
		int a = (c_idx + 1) / 2 - 1;

		arr[a] = t;
	}
}

//template <typename T>
MinHeap & MinHeap::pop() {
	if (!currentSize)
		throw OutOfBounds();
	Huffman data = element[--currentSize];
	element[currentSize] = element[0];
	if (!currentSize)
		return *this;
	int i = 1; //下标
	while (i < currentSize) {
		if (i + 1 < currentSize && element[i] > element[i + 1])
			i++;
		if (data < element[i])
			break;
		element[(i + 1) / 2 - 1] = element[i];
		i = i * 2 + 1;
	}
	element[(1 + i) / 2 - 1] = data;
	return *this;
}

BinaryTree<char> HuffmanTree(char * data, int * weights, int length) {

	Huffman * initDataSet = new Huffman[length];
	for (int i = 0; i < length; i++)
		initDataSet[i] = Huffman(weights[i], data[i]);

	MinHeap * heap = new MinHeap(initDataSet, length, length);

	for (int i = 1; i < length; i++) {
		Huffman left, right, temp;
		heap->pop(left);
		heap->pop(right);
		temp.weight = left + right;
		if (LEFT_HIGH)
			temp.tree.makeTree(ZERO_SIGN, left.tree, right.tree);
		else
			temp.tree.makeTree(ZERO_SIGN, right.tree, left.tree);

		heap->push(temp);

	}
	Huffman result;
	heap->pop(result);
	heap->deactive();
	delete[] initDataSet;
	delete heap;
	return result.tree;
}

#endif /* MinHeap_hpp */

