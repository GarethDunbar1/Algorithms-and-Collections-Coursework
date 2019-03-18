#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;

class BinarySearchTree
{
private:
	struct tree
	{
		tree* left;
		tree* right;
		Player playerDetails;
	};
	tree* root;

public:
	BinarySearchTree()
	{
		root == NULL;
	}

	bool isEmpty() const { return root == NULL; }
	void insert(Player);
	void search(string key);
	void print_preorder();
	void preorder(tree*);
	void fillTree(BinarySearchTree *tree);
};
