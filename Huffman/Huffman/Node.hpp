#ifndef Node_hpp
#define Node_hpp

#include "stdafx.h"

template <typename T> class LinkedQueue;
template <typename T> class LinkedStack;
template <typename T> class LinkedSet;

template <typename T>
class Node {
    friend class LinkedQueue<T>;
    friend class LinkedStack<T>;
    friend class LinkedSet<T>;
public:
    T data;
    Node<T> * link;
	Node<T>(): link(0) {}
};
#endif /* Node_hpp */
