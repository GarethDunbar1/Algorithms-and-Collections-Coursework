#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;

class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		Player playerDetails;
	};
	tree_node* root; 

public:
	BinarySearchTree()
	{
		root == NULL;
	}

	bool isEmpty() const { return root == NULL; }
	void insert(Player);
	void search(string key);
	void print_preorder();
	void preorder(tree_node*);
	//void fillTree(BinarySearchTree *tree);
};
