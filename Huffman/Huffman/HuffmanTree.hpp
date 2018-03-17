//makeTree的用处

#ifndef HuffmanTree_hpp
#define HuffmanTree_hpp

#include "BinaryTree.hpp"
 
 
//template <typename T, typename Q>
class Huffman {
    //template <typename M, typename N>
    //friend BinaryTree<char> HuffmanTree(char *, int *, int);
public:    
    BinaryTree<char> tree;
    int weight;


    Huffman() {}
    Huffman(const int & weigh, const char & data) {
        weight = weigh;
        tree = BinaryTree<char>(data);
    }
	void Delete() { tree.Delete(); }
	///重载读Huffman的值的方法
	operator int() const { return weight; }

};

///参数 data为各个数据，按顺序对应的权重为 weights
//为了项目，，，，Q是char, T是int
//template <typename T, typename Q>

#endif /* HuffmanTree_hpp */

 
