#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

int main(){

    Player* me = new Player();
    Player* computer = new Player();
    int input_amount = 0;
    bool burst_flag_player = false;
    bool burst_flag_computer = false;
    char answer;
    
    while (0 < me->get_amount() && computer->get_amount() >= -800){
     
    	cout << "You have $" << me->get_amount() << ". Enter bet: ";
	cin >> input_amount;	
    	while(input_amount > me->get_amount() || input_amount == 0){
            cout << "\nNot Enough bet, please try again: ";
            cin.ignore();
            cin >> input_amount;
	}
     	cin.ignore();
        me->draw();
     	cout << "\nYour Cards:\n" << me->show_cards() << endl;
        cout << "Your total is " << me->get_player_value() << ".\n"<< "Do you want another card (y/n)?";
        cin >> answer;
        while (answer == 'y') {
            me->draw();
            cout << "New Card: " << me->show_last_card() << endl;
            cout << "\nYour Cards:\n" << me->show_cards() << endl;
            cout << "Your total is " << me->get_player_value();
	    if(me->get_player_value() > 7.5) break;
	    cout << " Do you want another card (y/n)?";
            cin >> answer;
        }
        
        if (me->get_player_value() > 7.5){
            cout << "\nYou Burst!\n";
            burst_flag_player = true;
            //me->update_money(-input_amount);
        }
        
        while (computer->get_player_value() <= 5.5) {
            computer -> draw();
            cout << "New Card: " << computer->show_last_card() << endl;
            cout << "\nDealer's Cards:\n" << computer->show_cards() << endl;
            cout << "Dealer's total is " << computer->get_player_value() << endl;
        }

        if (computer -> get_player_value() > 7.5){
            cout << "Dealer Bursts!\n";
            burst_flag_computer = true;
        }

        if (burst_flag_player == true && burst_flag_computer == false){
            cout << "Too bad, you loose " << input_amount << endl;
            me -> update_money(-(input_amount));
        }
        else if (burst_flag_player == false && burst_flag_computer == true){
            cout << "You Win " << input_amount << endl;
            me -> update_money(input_amount);
        }
        else if (burst_flag_player == false && burst_flag_computer == false){
            if (me->get_player_value() < computer->get_player_value()){
                cout << "Too bad, you loose" << input_amount << endl;
                me -> update_money(-(input_amount));
            }
            else if (me->get_player_value() > computer->get_player_value()){
                cout << "You Win " << input_amount << endl;
                me -> update_money(input_amount);
            }
            else{
                cout << "Nobody wins!" << endl;
            }
        }
        else{
            cout << "Too bad, you loose" << input_amount << endl;
            me -> update_money(-(input_amount));
        }
        
     }
     
     
    
    
    
    
    
    
    return 0;

}
