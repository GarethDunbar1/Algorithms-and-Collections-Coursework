//Structures and Algorithms Coursework 18/19 - SPFL Top Scorers by B00324366
//This class is where I implement the binary search tree and its functions
//The class has uses the functions declared in the Player header class and the PlayerBinarySearchTree header class to populate, search and display the nodes of the tree 
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "PlayerBinarySearchTree.h"
using namespace std; 
typedef string treeType;


void PlayerBinarySearchTree::insertPlayer(Player player)
{
	// This method will allow me to insert the players data to binary search tree in the order of their first names
	tree* node = new tree;
	tree* parent;
	node->playerDetails = player;
	node->left = NULL;
	node->right = NULL;
	parent = NULL;
 
	if(root == NULL)
		root = node;
	else
	{
		tree* currentNode;
		currentNode = root; 

		while (currentNode)
		{
			parent = currentNode;
			//check to see if the new players first name comes before or after the current players name so we can determine if the player will go to the left or right side of the tree
			if (node->playerDetails.getPlayerName() > currentNode->playerDetails.getPlayerName()) // if the new players name is after the current players name then we will test it again 
				currentNode = currentNode->right;												//against the player to the right of the current player if not then we will test it against
			else																				//the player to the left of the current player and so on until we find where to insert it
				currentNode = currentNode->left;
		}

		if (node->playerDetails.getPlayerName() < parent->playerDetails.getPlayerName())
			parent->left = node;
		else
			parent->right = node;
	}
}

void PlayerBinarySearchTree::populateTree(PlayerBinarySearchTree *tree)
{
	//this section of code was sourced online and can be found here: 
	https://www.daniweb.com/programming/software-development/threads/327525/binary-search-tree-file-reading?fbclid=IwAR347WJMTYQ-rFiQeW8aKfMO3zw15YHqvltSRLGFIhWzgfs3VbRDcq0cdxo
	//this method reads the data from the player.txt file that contains of the data on the players and then passes it to the insertPlayer method to be inserted into the tree
	ifstream file;
	string playerName, teamName;
	int matchesPlayed, goalsScored, assistsMade;
	Player playerDetails;

	file.open("Players.txt"); //check for the file and if it can find the file then let the user know
	if (!file) 
	{
		cout << "Can't find file" << endl;
	}

	while (file >> playerName >> teamName >> matchesPlayed >> goalsScored >> assistsMade)
	{
		//reads data from the file and sets it to the variables so it can be stored in the tree
		playerDetails.setPlayerName(playerName);
		playerDetails.setTeamName(teamName);
		playerDetails.setMatchesPlayed(matchesPlayed);
		playerDetails.setGoalsScored(goalsScored);
		playerDetails.setAssistsMade(assistsMade);
		(*tree).insertPlayer(playerDetails);
	}
	file.close();
}

void PlayerBinarySearchTree::playerSearch(string searchedPlayersName)
{
	// this method will take the name that was entered by the user and travese through the tree to try and find it and if it does then display that players details to the user. 
	bool playerFound = false;
	tree *currentNode, *parent;
	currentNode = root;

	if (root == NULL)
	{
		cout << " Tree is empty!" << endl;
		return;
	}

	while (currentNode != NULL) // this will keep travering through the tree until the currentNode no longer has data attached to it
	{
		if (currentNode->playerDetails.getPlayerName() == searchedPlayersName)
		{
			playerFound = true;
			//display the details of the player to the user
			cout << " Player Name	" << "Team Name	" << "Appearances	" << "Goals	" << "Assists" << endl;
			cout << currentNode->playerDetails.getPlayerName() << "	" << currentNode->playerDetails.getTeamName() << "		" << currentNode->playerDetails.getMatchesPlayed() << "		" << currentNode->playerDetails.getGoalsScored() << "	" << currentNode->playerDetails.getAssistsMade() << endl;
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

void PlayerBinarySearchTree::display(tree* player)
{
	//this method quite simply traverses through the tree and displays all of the data held in each node to the user.
	if (player != NULL)
	{
		cout << player->playerDetails.getPlayerName() << "	" << player->playerDetails.getTeamName() << "		" << player->playerDetails.getMatchesPlayed() << "		" << player->playerDetails.getGoalsScored() << "	" << player->playerDetails.getAssistsMade() << endl;
		if (player->left)
			display(player->left);
		if (player->right)
			display(player->right);
	}
	else
	{
		cout << "Tree Empty" << endl;
	}
}

void PlayerBinarySearchTree::print_display()
{
	display(root);
}