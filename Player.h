/*
 * Player.h
 *
 *  Created on: 27/05/2014
 *      Author: Luis
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

using namespace std;

class Player{
private:
	int id; //id do jogador, pode ser 0 ou 1 pois so pode haver 2 jogadores
	string name;
	bool lost;	//começa em false, qd está true significa q este jogador ja nao pode ganhar (pode haver empate, ou seja, nao ha vencedor)

public:
	string newPlayer(); //novo jogador

	void setID(int ID);
	void setName(string nome);
	void setLost();

	int getId();
	string getName();
	bool getLost();

};



#endif /* PLAYER_H_ */
