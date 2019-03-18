#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "BinarySearchTree.h"

using namespace std; 
typedef string treeType;

void BinarySearchTree::insert(Player player)
{
	tree* node = new tree;
	tree* parent;
	node->playerDetails = player;
	node->left = NULL;
	node->right = NULL;
	parent = NULL;

	if (isEmpty()) 
		root = node;
	else
	{
		tree* currentNode;
		currentNode = root; 

		while (currentNode)
		{
			parent = currentNode;
			if (node->playerDetails.getPlayerName() > currentNode->playerDetails.getPlayerName()) 
				currentNode = currentNode->right;
			else 
				currentNode = currentNode->left;

		}

		if (node->playerDetails.getPlayerName() < parent->playerDetails.getPlayerName())
			parent->left = node;
		else
			parent->right = node;
	}
}

void BinarySearchTree::fillTree(BinarySearchTree *tree)
{
	ifstream file;
	string playerName, teamName;
	int matchesPlayed, goalsScored, assistsMade;
	Player playerDetails;

	file.open("Players.txt");
	if (!file)
	{
		cout << "Can't find file" << endl;
	}

	while (file >> playerName >> teamName >> matchesPlayed >> goalsScored >> assistsMade)
	{
		playerDetails.setPlayerName(playerName);
		playerDetails.setTeamName(teamName);
		playerDetails.setMatchesPlayed(matchesPlayed);
		playerDetails.setGoalsScored(goalsScored);
		playerDetails.setAssistsMade(assistsMade);

		cout << playerDetails.getPlayerName() << "	" << playerDetails.getTeamName() << "	" << playerDetails.getMatchesPlayed() << "	" << playerDetails.getGoalsScored() << "	" << playerDetails.getAssistsMade() << endl;
		(*tree).insert(playerDetails);
	}
	file.close();
}

void BinarySearchTree::search(string searchedPlayersName)
{
	bool playerFound = false;
	tree *currentNode, *parent;
	currentNode = root;

	if (isEmpty())
	{
		cout << " Tree is empty!" << endl;
		return;
	}

	while (currentNode != NULL)
	{
		if (currentNode->playerDetails.getPlayerName() == searchedPlayersName)
		{
			playerFound = true;
			cout << " Player's Name: " << currentNode->playerDetails.getPlayerName() << endl;
			cout << " Team's Name: " << currentNode->playerDetails.getTeamName() << endl;
			cout << " Matches Played: " << currentNode->playerDetails.getMatchesPlayed() << endl;
			cout << " Goals Scored: " << currentNode->playerDetails.getGoalsScored() << endl;
			cout << " Assists Made: " << currentNode->playerDetails.getAssistsMade() << endl;
			break;
		}
		else
		{
			parent = currentNode;
			if (searchedPlayersName > currentNode->playerDetails.getPlayerName())
			{ 
				currentNode = currentNode->right;
			}
			else 
			{
				currentNode = currentNode->left;
			}
				
		}
	}

	if (!playerFound)
	{
		cout << " Player not found " << endl;
		return;
	}
}

void BinarySearchTree::preorder(tree* player)
{
	if (player != NULL)
	{
		cout << "  " << player->playerDetails.getPlayerName() << "  ";
		if (player->left)
			preorder(player->left);
		if (player->right)
			preorder(player->right);
	}
	else
	{
		cout << "Tree Empty" << endl;
	}
}

void BinarySearchTree::print_preorder()
{
	preorder(root);
}

