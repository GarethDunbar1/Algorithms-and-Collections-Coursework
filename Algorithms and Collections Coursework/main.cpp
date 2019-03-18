#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree players, *tree = nullptr;
	string searchedPlayerName;
	int menuChoice;
	
	tree->fillTree(&players);
	//tree.print_preorder();
	//system("PAUSE");

	while (1)
	{
		cout << endl << endl;
		cout << " SPFL Top Scorers " << endl;
		cout << "------------------" << endl;
		cout << " 0. Display un-sorted list " << endl;
		cout << " 1. Display alphabetically sorted list " << endl;
		cout << " 2. Search by Player Name " << endl;
		cout << " 3. Search by Team Name " << endl;
		cout << " 4. Exit " << endl;
		cout << " Please select an option: ";
		cin>>menuChoice;

		switch (menuChoice)
		{
		case 0:
			players.print_preorder();
			break;
		case 1:
			break;
		case 2:
			cout << " Please enter a players name (eg. Alfredo_Morelos): " << endl;
			cin >> searchedPlayerName;
			players.search(searchedPlayerName);
			break;
		case 3:
			break;
		case 4:
			exit(0);

		}
	}

}