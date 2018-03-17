#ifndef Dictionary_hpp
#define Dictionary_hpp

#include "stdafx.h"

///为课设高度customized 字典。不通用。

template <typename K, typename V> class Dictionary;

template <typename K, typename V>
class Word {
	friend class Dictionary<K, V>;
public:
    K key;
    V value;
    Word(){};
    Word(const K & k, const V & v): key(k), value(v) {}
};

 
template <typename K, typename V>
class Dictionary {
public:
	Word<K, V> * words;
	int curSize;
	int maxSize;

public:
	Dictionary<K, V>():curSize(0), maxSize(0), words(0) {};
	Dictionary<K, V>(int size);
	//we can dealloc a dict manually. But auto here
	~Dictionary() { words = 0; delete[] words; }

	void output() const;
	void reset(int size);
	 
	int  size() { return curSize; }
	void localize(const string & path);
	void localize1(const string & path);
	void reverseTo(Dictionary<V, K> & receiver) const;
	void setValueForKey(const K & k, const V & v);
	bool objectForKey(const K & k, V & receiver) const;
	void enumerateDictWithBlock(void(*func) (K &, V &)) const;

	template <typename M>
	void enumerateDictWithLambda(M &) const;
	 

};

template <typename K, typename V>
void Dictionary<K, V>::output() const {

	auto printDict = [](K & k, V & v) {
		if (k == '\n') 
			printf("\\n: %s\n", ((string)v).c_str());
		else
			printf("%c : %s\n", k, ((string)v).c_str());
	};
	enumerateDictWithBlock(printDict);
}

template <typename K, typename V>
Dictionary<K, V>::Dictionary(int size) {
	words = new Word<K, V>[size];
	curSize = 0;
	maxSize = size;
}

template<typename K, typename V>
template<typename M>
void Dictionary<K, V>::enumerateDictWithLambda(M & lambda) const
{

}

template <typename K, typename V>
void Dictionary<K, V>::reset(int size) {
	if (words)
		delete[] words;
	curSize = 0;
	maxSize = size;
	words = new Word<K, V>[size];
}
 

template<typename K, typename V>
void Dictionary<K, V>::localize(const string & path) {
	ofstream f_out(path, ios::app);
	f_out << "{\n";
	for (int i = 0; i < curSize; i++)
		f_out << "\t" << words[i].key << " : " << words[i].value << "\n";
	f_out << "}";
	f_out.flush();
	f_out.close();
}

template<typename K, typename V>
void Dictionary<K, V>::localize1(const string & path) {
 
	int len = path.length();
	QStringList list = QString(path.c_str()).split('/');
	list[list.length() - 1] = QString("hfmtree.txt");
	QString ppp = list.join('/');

	string finalPath = ppp.toStdString();
	fileExists(finalPath, 3);

	ofstream f_out(finalPath, ios::app);
	for (int i = 0; i < curSize; i++)
		f_out << words[i].key << ":" << words[i].value << HFMLINE;
	
	f_out.flush();
	f_out.close();
}

template<typename K, typename V>
void Dictionary<K, V>::reverseTo(Dictionary<V, K> & receiver) const {
	receiver.reset(curSize);
	for (int i = 0; i < curSize; i++)
		receiver.setValueForKey(words[i].value, words[i].key);
		
}

template <typename K, typename V>
void Dictionary<K, V>::setValueForKey(const K & k, const V & v) {
	if (curSize == maxSize)
		throw NoMemory();
	words[curSize] = Word<K, V>(k, v);
	curSize++;
}

template <typename K, typename V>
bool Dictionary<K, V>::objectForKey(const K & k, V & receiver) const {
	
	for (int i = 0; i < curSize; i++) {
		if (words[i].key == k) {
			receiver = words[i].value;
			return 1;
		}
	}
	return 0;
}

template <typename K, typename V>
void Dictionary<K, V>::enumerateDictWithBlock(void (func)(K &, V &)) const {
	for (int i = 0; i < curSize; i++) {
		func(words[i].key, words[i].value);
	}
}


#endif /* Dictionary_hpp */
