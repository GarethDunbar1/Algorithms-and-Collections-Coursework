//Structures and Algorithms Coursework 18/19 - SPFL Top Scorers by B00324366
//This class creates the blueprint for the player binary search tree
//It will allow me to layout which functions I will need at the structure of the tree itself

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"

using namespace std;

class PlayerBinarySearchTree
{
private:
	//creates the structure of the nodes within the tree
	struct tree
	{
		tree* left;
		tree* right;
		Player playerDetails;
	};
	tree* root;

public:
	PlayerBinarySearchTree()
	{
		//set the root to null by default
		root == NULL;
	}

	//functions to be implemented
	void insertPlayer(Player);
	void playerSearch(string searchedPlayerName);
	void print_display();
	void display(tree*);
	void populateTree(PlayerBinarySearchTree *tree);
};
