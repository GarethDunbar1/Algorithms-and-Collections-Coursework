//Structures and Algorithms Coursework 18/19 - SPFL Top Scorers by B00324366
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "PlayerBinarySearchTree.h"
int main()
{
	PlayerBinarySearchTree players, *tree = nullptr;
	string searchedPlayerName;
	int menuChoice;

	//creates a visable menu system for the user to allow them to choose which option the would like to take. 
	while (1)
	{
		cout << endl << endl;
		cout << " SPFL Top Scorers " << endl;
		cout << "------------------" << endl;
		cout << " 1. Import data from file " << endl;
		cout << " 2. Display list of players " << endl;
		cout << " 3. Search by Player Name " << endl;
		cout << " 4. Exit " << endl;
		cout << " Please select an option: ";
		cin>>menuChoice;

		switch (menuChoice)
		{
		case 1:
			//Option 1: uses the popualteTree method in the PlayerBinarySearchTree class to read the data from the file.
			tree->populateTree(&players);
			cout << "Tree Filled!" << endl;
			break;
		case 2:
			//Option 2: uses the print_display method in the PlayerBinarySearchTree class to display the data in the tree to the user.
			cout << "Player Name	" << "Team Name	" << "Appearances	" << "Goals	" << "Assists" << endl;
			players.print_display();
			break;
		case 3:
			//Option 3: asks the user to input a players name and then uses the playerSearch method in the PlayerBinarySearchTree class to traverse trough the tree to find the player
			// and if the player is found then displays the players data to the user and if the player isnt found then it will let the user know.
			cout << " Please enter a players name you'd like to search for (eg. Alfredo_Morelos): " << endl;
			cin >> searchedPlayerName;
			players.playerSearch(searchedPlayerName);
			break;
		case 4:
			//Option 4: allows the user to exit the program.
			exit(0);
		}
	}

}