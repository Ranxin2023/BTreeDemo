#include "BTree.h"

BTree::BTree()
{
	this->root = nullptr;
}

BTreeNode_Ref BTree::search(int k)
{
	if (this->root == nullptr) {
		return nullptr;
	}
	return this->root->search(k);
}

BTreeNode_Ref BTreeNode::search(int k)
{
	return BTreeNode_Ref();
}
