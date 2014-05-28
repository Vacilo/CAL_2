/*
 * Game.h
 *
 *  Created on: 26/05/2014
 *      Author: Luis
 */

#ifndef GAME_H_
#define GAME_H_


#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


class Game{
private:
	bool final; 				//bool para ver se o jogo terminou
	string word;				//palavra em jogo, atualiza a cada jogada
	vector<string> words;		//vetor com as palavras
	vector<Player> players;		//vetor com os 2 jogadores

public:
	Game();
	void addLetter();			//adicionar letras a uma palavra (inicio ou fim)
	bool checkIfWordExists();	//verificar se o novo conjunto de letras existe em alguma palavra do dicionario

	void play(int id);			//jogada de 1 jogador
	void end(int id);			//decidir vencedor
	void allGame(string word1);	//jogo

	void addPlayer();			//adicionar 1 jogador
	string choosePlayer(int ID);//retorna o nome do jogador como id ID

	void playerLost(int id);	//mudar bool Lost do jogador, ou seja, o jogador com id id já nao pode ganhar,
	//mas pode haver empate caso o outro jogador nao adivinhe a palavra
	bool tie();					//verificar se ha empate

	vector<string> getWords();	//devolve o vector do dicionario
	vector<Player> getPlayers();//devolve o vector com os jogadores

	void addWord(string word1);	//adicionar uma palavra ao dicionario

	void readFromFile();		//ler as palavras do ficheiro e colocar no dicionario
	void showAllWords();		//cout das palavras todas (1 por linha)
	bool wordInsideWord(string word1, string word2);	//check if word2 is inside of word2
};

#endif /* GAME_H_ */
