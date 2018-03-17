#ifndef LinkedStack_hpp
#define LinkedStack_hpp

#include "Node.hpp"

template <typename T>
class LinkedStack {
    Node<T> * top;
public:
    LinkedStack(): top(0) {}
    ~LinkedStack();

    string output() const;
    bool isEmpty() const { return !top; }
    
    int size() const;
    T Top() const;
    LinkedStack<T> & push(const T & t);
    LinkedStack<T> & pop(T & receiver);
    LinkedStack<T> & pop();
    
};
 
template <typename T>
int LinkedStack<T>::size() const {
    int c = 0;
    Node<T> * n = top;
    while (n) {
        c++;
        n = n->link;
    }
    return c;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    Node<T> * n;
    while (top) {
        n = top->link;
        delete top;
        top = n;
    }
}

///返回T数组为结果，如果带参数则顺带打印
template <typename T>
string LinkedStack<T>::output() const {
    if (!top)
        return string();
    int s = size();
    T * result = new T[s+1];
    Node<T> * n = top;
	for (int i = 0; i < s; i++) {
		result[s - i - 1] = n->data;
		n = n->link;
	}

	result[s] = '\0';
	string str = string((char*)result);
	result[s] = '1';
	delete[] result;
    return str;
}

template <typename T>
T LinkedStack<T>::Top() const {
    if (!top)
        throw OutOfBounds();
    return top->data;
}

template <typename T>
LinkedStack<T> & LinkedStack<T>::push(const T & t) {
    Node<T> * n = new Node<T>;
    n->data = t;
    n->link = top;
    top = n;
    return *this;
}

template <typename T>
LinkedStack<T> & LinkedStack<T>::pop(T & r) {
    if (!top)
        throw OutOfBounds();
    Node<T> * n = top->link;
    r = top->data;
    delete top;
    top = n;
    return *this;
}

template <typename T>
LinkedStack<T> & LinkedStack<T>::pop() {
    if (!top)
        throw OutOfBounds();
    Node<T> * n = top->link;
    delete top;
    top = n;
    return *this;
}

 
#endif /* LinkedStack_hpp */
