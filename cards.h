#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H_
#define CARDS_H_

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


