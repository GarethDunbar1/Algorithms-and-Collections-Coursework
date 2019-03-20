//Structures and Algorithms Coursework 18/19 - SPFL Top Scorers by B00324366
//This class implements the different getters and setters that will be used to store and display the different pieces of data that is being used throughout the program. 
#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std; 

Player::Player()
{
}

Player::Player(string player_Name, string team_Name, int matches_Played, int goals_Scored, int assists_Made)
{
	playerName = player_Name;
	teamName = team_Name;
	matchesPlayed = matches_Played;
	goalsScored = goals_Scored;
	assistsMade = assists_Made;
}

void Player::setPlayerName(string player_Name)
{
	playerName = player_Name;
}

void Player::setTeamName(string team_Name)
{
	teamName = team_Name;
}

void Player::setMatchesPlayed(int matches_Played)
{
	matchesPlayed = matches_Played;
}

void Player::setGoalsScored(int goals_Scored)
{
	goalsScored = goals_Scored;
}

void Player::setAssistsMade(int assists_Made)
{
	assistsMade = assists_Made;
}

string Player::getPlayerName()
{
	return playerName;
}

string Player::getTeamName()
{
	return teamName;
}

int Player::getMatchesPlayed()
{
	return matchesPlayed;
}

int Player::getGoalsScored()
{
	return goalsScored;
}

int Player::getAssistsMade()
{
	return assistsMade;
}