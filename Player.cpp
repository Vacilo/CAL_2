/*
 * Player.cpp
 *
 *  Created on: 27/05/2014
 *      Author: Luis
 */
#include "Player.h"

string Player::newPlayer()
{
	string nome;

	cout<<"Introduza o nome"<<endl;
	cin>>nome;

	return nome;
}

void Player::setID(int ID)
{
	id=ID;
}

void Player::setName(string nome)
{
	name=nome;
}

void Player::setLost()
{
	lost=true;
}


int Player::getId()
{
	return id;
}

string Player::getName()
{
	return name;
}

bool Player::getLost()
{
	return lost;
}
