/*
 * Game.cpp
 *
 *  Created on: 26/05/2014
 *      Author: Luis
 */
#include "Game.h"

Game::Game()
{
	word="de";
	final=false;
}


void Game::addLetter()
{
	string op;
	string letter;

	cout<<"Qual a letra que pretende introduzir?"<<endl<<endl;
	cin>>letter;

	cout<<"Deseja introduzir a letra no inicio(i) ou fim(f) ?"<<endl<<endl;
	cin>>op;

	cout << string(20, '\n');


	if(op=="i")
	{
		word=letter+word;
	}
	else if(op=="f")
	{
		word=word+letter;
	}
}


bool Game::checkIfWordExists()
{
	for(unsigned int i=0; i<words.size(); i++)
	{
		if(words[i].find(word) != string::npos)
		{
			cout<<"A palavra "<<word<<" existe!"<<endl;
			return true;
		}
	}

	cout<<"A palavra "<<word<<" nao existe!"<<endl;


	return false;
}

void Game::play(int id)
{
	string oldWord=word;

	cout<<endl<<choosePlayer(id)<<" e' a sua vez !"<<endl;
	string op;
	cout<<"    Deseja adicionar uma letra? (s/n)   "<<"    Se nao adicionar perde o jogo!"<<endl;
	cin>>op;

	if(op=="s")
	{
		addLetter();
		if(!checkIfWordExists())
		{
			word=oldWord;
			if(id==0)
			{
				playerLost(0);
				end(1);
			}
			else
			{
				playerLost(1);
				end(0);
			}

		}
	}
	else
	{
		if(id==0)
		{
			playerLost(0);
			end(1);
		}

		else
		{
			playerLost(1);
			end(0);
		}
	}
}


void Game::end(int id)
{
	final=true;
	string oldWord=word;

	cout<<"Jogador "<<choosePlayer(id)<<" tem a possibilidade de ganhar o jogo!"<<endl;
	cout<<"Introduza a palavra em que estava a pensar"<<endl;
	cin>>word;



	if(checkIfWordExists() && oldWord!=word && wordInsideWord(word, oldWord))
	{
		cout<<"Jogador "<<choosePlayer(id)<<" ganhou o jogo!"<<endl<<"####PARABENS!####"<<endl;
	}
	else
	{
		playerLost(id);

		if(oldWord==word)
		{
			cout<<"Nao pode ganhar o jogo introduzindo a palavra atual em jogo !"<<endl;

			if(!tie())
				cout<<"Jogador "<<choosePlayer(id)<<" perdeu o jogo!"<<endl;
			else
				cout<<"Empate! Nao ha vencedor!"<<endl;
		}
		else if(!wordInsideWord(word, oldWord))
		{
			cout<<"A palavra introduzida nao ingloba a palavra que estava em jogo!"<<endl;

			if(!tie())
				cout<<"Jogador "<<choosePlayer(id)<<" perdeu o jogo!"<<endl;
			else
				cout<<"Empate! Nao ha vencedor!"<<endl;
		}
		else
		{

			if(!tie())
				cout<<"Jogador "<<choosePlayer(id)<<" perdeu o jogo!"<<endl;
			else
				cout<<"Empate! Nao ha vencedor!"<<endl;
		}


		//	cout<<"A palavra que introduziu nao existe!"<<endl;

	}
}


void Game::allGame(string word1)
{
	readFromFile();

	cout << string(20, '\n');


	cout<<"A palavra para começar o jogo e':  "<<word1<<endl<<endl;

	while(!final)
	{
		for(unsigned int i=0; i<2; i++)
		{
			cout<<"A palavra em jogo e': "<<word<<endl;
			play(i);
			if(final)
				break;
		}
	}
}

void Game::addPlayer()
{
	Player player;

	player.setName(player.newPlayer());

	player.setID(players.size());

	players.push_back(player);
}


string Game::choosePlayer(int ID)
{
	string st;

	if(players.size()==0)
	{
		stringstream ss;
		ss<<ID;

		st="Nao existe nenhum jogador com o id "+ss.str()+" !";
	}
	else
	{
		for(unsigned int i=0; i<players.size(); i++)
		{
			if(players[i].getId() == ID)
				st= players[i].getName();
		}
	}
	return st;
}

void Game::playerLost(int id)
{
	for(unsigned int i=0; i<players.size(); i++)
	{
		if(players[i].getId() == id)
		{
			players[i].setLost();
		}
	}
}

bool Game::tie()
{
	if(players[0].getLost()==true && players[1].getLost()==true)

		return true;
	else
		return false;
}

vector<string> Game::getWords()
{
	return words;
}

vector<Player> Game::getPlayers()
{
	return players;
}

void Game::addWord(string word1)
{
	words.push_back(word1);
}


void Game::readFromFile()
{
	ifstream file;
	file.open ("words.txt");
	if (!file.is_open()) return;

	string word;
	while (file >> word)
	{
		words.push_back(word);
	}
}

void Game::showAllWords()
{
	for(unsigned int i=0; i<words.size(); i++)
	{
		cout<<words[i]<<endl;
	}
}

bool Game::wordInsideWord(string word1, string word2)
{
	bool tf=false;

	if(word1.find(word2) != string::npos)
	{
		tf= true;
	}


	return tf;

}
