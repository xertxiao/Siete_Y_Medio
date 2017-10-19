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
	Hand(){};
	void draw();
	string get_cards() const;
	string get_lastcard() const;
	int total_rank() const;
	int total_cards() const;
	~Hand() {for (auto i : cards){delete i;}}
private:
	vector<Card* > cards;
};

class Player{
public:
	Player(): money(100){hand = new Hand()}
	void update_money(int input_money);
	void draw() {hand->draw();};	
	int get_totalrank() const;
	string show_cards() const {return hand->get_cards();};
	int get_amount() const;
	~Player() {hand->delete hand;}
//	void write_log() const;


	
private:
	int money;
	Hand* hand;
};


#endif
