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
	void setPlayerName(string player_Name), setTeamName(string team_Name), setMatchesPlayed(int matches_Played), setGoalsScored(int goals_Scored), setAssistsMade(int assists_Made);
};