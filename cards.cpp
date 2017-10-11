#include "cards.h"
#include <cstdlib>
#include <iostream>

/* 
You might or might not need these two extra libraries 
#include <iomanip>
#include <algorithm>
*/

Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "Gold"; 
	 break;
      case COPAS: 
         suitName = "Cups"; 
	 break; 
      case ESPADAS: 
         suitName = "Swords"; 
	 break;
      case BASTOS: 
         suitName = "Clubs"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "Ace"; 
	 break; 
      case DOS: 
         rankName = "Two"; 
	 break; 
      case TRES: 
         rankName = "Three"; 
	 break; 
      case CUATRO: 
         rankName = "Four"; 
	 break; 
      case CINCO: 
         rankName = "Five"; 
	 break; 
      case SEIS: 
         rankName = "Six"; 
	 break; 
      case SIETE: 
         rankName = "Seven"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Horse"; 
	 break; 
      case REY: 
         rankName = "King"; 
	 break; 
      default: break;
   }
   return rankName;
} 
   




// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
// Implemente the member functions of the Hand class here.

void Hand::draw(){
	new_card = new Card one_card;
	cards.append(one_card);
}

int Hand::total_rank() const {
	int sum = 0;
	for (auto i : cards){
		sum += i -> get_rank();
	}

	return sum;
}

int Hand::total_cards() const{
	return cards.size();
}
string Hand::get_cards() const{
	string have_cards = "";
	for (auto x : cards){
		have_cards += cards[x] -> get_spanish_rank() + " de " + cards[x] -> get_spanish_suit() + "\t" + "(" + cards[x] -> get_english_rank() + " of " +  cards[x] -> get_english_suit() + ".\t";
	}
	return have_cards;
}

/* *************************************************  Player class
   ************************************************* */
// Implemente the member functions of the Player class here.


void Player::update_money(int input_money){
	money += input_money;
}


int Player::get_amount() const{
	return money;
}
