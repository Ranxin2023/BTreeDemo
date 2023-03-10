#pragma once
#ifndef BTREE_H
#define BTREE_H
#include<iostream>
#include<vector>
using namespace std;
typedef BTree* BTree_Ref;
typedef BTreeNode* BTreeNode_Ref;
class BTreeNode {
private:
	int degree;
	vector<int>keys;
	vector<BTreeNode_Ref>children;
	int num_of_keys;
	bool leaf;

public:
	BTreeNode(int, bool); 
	void traverse();
	BTreeNode_Ref search(int k);
	void insert(int);
	friend class BTree;
};
class BTree {
private:
	BTreeNode_Ref root;
	int degree;
public:
	BTree(int);
	void traverse();
	BTreeNode_Ref search(int k);
	void insert(int k);
};
#endif // !BTREE_H
