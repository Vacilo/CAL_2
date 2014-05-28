/*
 * main.cpp
 *
 *  Created on: 26/05/2014
 *      Author: Luis
 */


#include <iostream>

#include "Game.h"
#include <string>


int main()
{
	//ficheiro


	string cenas ="de";

	Game game;

game.readFromFile();
	//game.showAllWords();


	//game.addWord("delete");
/*	game.words.push_back("buedecenas");

	game.checkIfWordExists("cde");
	game.checkIfWordExists(cenas);
	game.checkIfWordExists(	game.addLetter(cenas));*/


	game.addPlayer();game.getPlayers()[0].getId();
	game.addPlayer();


	game.allGame("de");

/*	cout<<game.players[0].name<<" asd  "<<game.players[0].id<<endl;
	cout<<game.players[1].name<<" asd  "<<game.players[1].id<<endl;*/

//	game.allGame("de");

	return 0;

}

