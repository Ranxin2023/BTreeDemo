#include "../header/BTree.h"

BTree::BTree(int t) :degree(t), root(nullptr)
{

}

void BTree::traverse()
{
	if (this->root != nullptr) {
		root->traverse();
	}
}


void BTreeNode::traverse()
{
	for (int i = 0; i < this->num_of_keys; i++) {
		if (this->leaf == false) {
			this->children[i]->traverse();
		}
		cout << " " << this->keys[i];
	}
	//subtree traverse
	if (this->leaf == false) {
		this->children[this->num_of_keys]->traverse();
	}
}

BTreeNode_Ref BTree::search(int k)
{
	if (this->root == nullptr) {
		return nullptr;
	}
	return this->root->search(k);
}

void BTree::insert(int k)
{
	if (this->root == nullptr) {
		this->root = new BTreeNode(this->degree, true);
	}
	this->root->insert(k);
}

BTreeNode::BTreeNode(int _t, bool leaf)
{
	this->degree = _t;
	this->leaf = leaf;
	//allocate maximum size of BTree
	this->keys.resize(2*this->degree+1);
	this->children.resize(2*this->degree);
	this->num_of_keys = 0;
}

BTreeNode_Ref BTreeNode::search(int k)
{
	//find the keys greater or equals to k
	
	int idx = 0;
	while (idx<this->num_of_keys && k>this->keys[idx]) {
		idx++;
	}
	if (this->keys[idx] == k) {
		return this;
	}
	//greater means search fails, this condition can be used as insertion
	if (this->leaf == true) {
		return nullptr;
	}
	//recurse search for key k
	return this->children[idx]->search(k);
}

void BTreeNode::insert(int k)
{
	int idx = 0;
	while (idx<this->num_of_keys && k>this->keys[idx]) {
		idx++;
	}
	if (this->keys[idx] == k) {
		return;
	}
	if (this->leaf == true) {
		//make a copy of original BTree
		
		//If greater than 2*degree, make the leaf false
		if (this->num_of_keys == 2 * this->degree) {
			this->children[idx] = new BTreeNode(this->degree, true);
			this->leaf = false;
			//insert to the child of children idx
			return this->children[idx]->insert(k);
		}
		else {
			vector<BTreeNode_Ref>original_children = this->children;
			this->num_of_keys++;
			this->children[idx] = new BTreeNode(this->degree, true);
			for (int i = idx + 1; i < this->num_of_keys; i++) {
				this->children[i + 1] = original_children[i];
			}
			return ;
		}
	}
	return this->children[idx]->insert(k);
}
