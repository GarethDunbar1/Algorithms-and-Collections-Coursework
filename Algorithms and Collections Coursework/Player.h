#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Player 
{
private:
	string playerName, teamName; 
	int matchesPlayed, goalsScored, assistsMade;

public:
	Player();
	Player(string playerName, string teamName, int matchesPlayed, int goalsScored, int assistsMade);
	string getPlayerName(), getTeamName();
	int getMatchesPlayed(), getGoalsScored(), getAssistsMade();
};