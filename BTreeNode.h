#ifndef MYSINGLYLIST_H
#define MYSINGLYLIST_H

template <class T,int M>
class BTreeNode {
private:
	bool leaf;
	int keyTally;
	T keys;
	friend BTree<T, M>;

public:
	BTreeNode();
	BTreeNode(const T&);

};

#endif
