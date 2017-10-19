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
     cin.ignore();
        me->draw();
     cout << "\nYour Cards:\n" << me->show_cards() << endl;
        cout << "Your total is " << me->get_rank() << ".\n"<< "Do you want another card (y/n)?";
        cin >> answer;
        while (answer == 'y' && me->get_rank() <= 7.5) {
            me->draw();
            cout << "New Card: " << me->show_last_card() << endl;
            cout << "\nYour Cards:\n" << me->show_cards() << endl;
            cout << "Your total is" << me->get_rank()<< "Do you want another card (y/n)?";
            cin >> answer;
        }
        
        if (me->get_rank() > 7.5){
            cout << "\nYou Burst!\n";
            burst_flag_player = true;
            //me->update_money(-input_amount);
        }
        
        while (computer->get_rank() <= 5.5) {
            computer -> draw();
            cout << "New Card: " << computer->show_last_card() << endl;
            cout << "\nDealer's Cards:\n" << computer->show_cards() << endl;
            cout << "Dealer's total is " << computer->get_rank() << endl;
        }

        if (computer -> get_rank() > 7.5){
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
            if (me->get_rank() < computer->get_rank()){
                cout << "Too bad, you loose" << input_amount << endl;
                me -> update_money(-(input_amount));
            }
            else if (me->get_rank() > computer->get_rank()){
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
