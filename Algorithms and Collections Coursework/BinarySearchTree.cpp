#include <iostream>
#include <fstream>

#include <string>
#include "Player.h"
#include "BinarySearchTree.h"

using namespace std; 

void BinarySearchTree::insert(Player player)
{
	tree_node* node = new tree_node;
	tree_node* parent;
	node->left = NULL;
	node->right = NULL;
	parent = NULL;

	if (isEmpty()) 
		root = node;
	else
	{
		tree_node* currentNode;
		currentNode = root; 

		while (currentNode)
		{
			parent = currentNode;
			if (node->playerDetails.getPlayerName() > currentNode->playerDetails.getPlayerName()) currentNode = currentNode->right;
			else 
				currentNode = currentNode->left;

		}

		if (node->playerDetails.getPlayerName() < parent->playerDetails.getPlayerName())
			parent->left = node;
		else
			parent->right = node;
	}
}

void BinarySearchTree::search(string key) 
{
	bool playerFound = false; 
	if (isEmpty())
	{
		cout << "The tree is empty." << endl;
		return;
	}

	tree_node* currentNode;
	tree_node* parent;
	currentNode = root;

	while (currentNode != NULL)
	{
		if (currentNode->playerDetails.getPlayerName() == key)
		{
			playerFound = true;
			cout << "Player Name: " << key << " Team Name: " << currentNode->playerDetails.getTeamName() << " Matches Played: " << currentNode->playerDetails.getMatchesPlayed() 
				<< " Goals Scored: " << currentNode->playerDetails.getGoalsScored() << " Assists Made: " << currentNode->playerDetails.getAssistsMade() << endl;
			break;
		}
		else
		{
			parent = currentNode;
			if (key > currentNode->playerDetails.getPlayerName())
				currentNode = currentNode->right;
		}
	}

	if (!playerFound)
	{
		cout << "Player not found!" << endl;
		return;
	}
}

void BinarySearchTree::preorder(tree_node* player)
{
	if (player != NULL)
	{
		cout << "  " << player->playerDetails.getPlayerName() << "  ";
		if (player->left)
			preorder(player->left);
		if (player->right)
			preorder(player->right);
	}
	else return;
}

void BinarySearchTree::print_preorder()
{
	preorder(root);
}

//void BinarySearchTree::fillTree(BinarySearchTree *tree)
//{
//	ifstream file;
//	string playerName, teamName;
//	int matchesPlayed, goalsScored, assistsMade;
//	Player playerDetails;
//
//	file.open("players.txt");
//	if (!file)
//	{
//		cout << "Can't find file" << endl;
//	} 
//
//	while (file >> playerName >> teamName >> matchesPlayed >> goalsScored >> assistsMade)
//	{
//		playerDetails.setPlayerName(playerName);
//		playerDetails.setTeamName(teamName);
//		playerDetails.setMatchesPlayed(matchesPlayed);
//		playerDetails.setGoalsScored(goalsScored);
//		playerDetails.setAssistsMade(assistsMade);
//
//		cout << playerDetails.getPlayerName() << "	" << playerDetails.getTeamName() << "	" << playerDetails.getMatchesPlayed() << "	" << playerDetails.getGoalsScored() << "	" << playerDetails.getAssistsMade() << endl;
//		(*tree).insert(playerDetails);
//	}
//	file.close();
//}