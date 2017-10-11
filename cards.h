#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H_
#define CARDS_H_

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11};

class Card{
public:
	Card();
	string get_spanish_suit() const;
	string get_spanish_rank() const;

	string get_english_suit() const;
	string get_english_rank() const;

	int get_rank() const;

	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;	


};

class Hand{
public:
	Hand() ;
	void draw();
	string get_cards() const;
	int total_rank() const;
	int total_cards() const;
	~Hand() {for (auto i : cards){delete i;}}
private:
	vector<Card* > cards;
};

class Player{
public:
	Player();
	Player(string input_name): name(input_name), money(100) {}
	void update_money(int money);
	
	int print_amount() const;
	
//	void write_log() const;


	
private:
	int money;
	string name;	
};


#endif
