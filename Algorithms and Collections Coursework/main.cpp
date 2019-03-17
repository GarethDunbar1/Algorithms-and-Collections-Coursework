#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "BinarySearchTree.h"

void fillTree(BinarySearchTree *tree)
{
	ifstream file;
	string playerName, teamName;
	int matchesPlayed, goalsScored, assistsMade;
	Player playerDetails;

	file.open("players.txt");
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

int main()
{
	BinarySearchTree tree;
	string playerName, teamName;
	int matchesPlayed, goalsScored, assistsMade;
	Player player, player1;
	fillTree(&tree);
	tree.print_preorder();
	system("PAUSE");

}