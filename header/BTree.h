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
	vector<BTreeNode*>children;

public:
	BTreeNode_Ref search(int k);
};
class BTree {
private:
	BTreeNode_Ref root;
	int degree;
public:
	BTree();
	BTreeNode_Ref search(int k);
};
#endif // !BTREE_H
