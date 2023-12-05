#include "declarations.h"
#include "game.cpp"
#include "cards.cpp"
#include "players.cpp"
#include "bot.cpp"
#include "user.cpp"

int main(){

    begin_game();
    player p1(1, "Malay");
    bot p2(2), p3(3), p4(4), p5(5);

    cout<<endl<<"The small blind is "<<small_blind<<" and large bet is "<<2*small_blind<<endl;
    int starting_player_index=no_of_players*(rand()/(1.0+RAND_MAX));

    cout<<"Starting at player "<<players_in_game[starting_player_index]->player_name<<endl;
    collect_small_large_bet(starting_player_index);

    cout<<"Round one of betting begins: \n\nDealing the flop:\n";
    community_cards.print(3);    

    initiate_betting();


    if (players_in_game.size()>1){
        cout<<"Round two of betting begins: \n\nDealing the turn:\n";
        community_cards.print(4); 
        
        initialise_round();
        initiate_betting();

        if (players_in_game.size()>1){
            cout<<"Round three of betting begins: \n\nDealing the river:\n";
            community_cards.print(5); 
        
            initialise_round();
            initiate_betting();
        }
    }

    if (players_in_game.size()==1){
        cout<<"Player "<<players_in_game[0]<<" has won the game\n";
    }

    else{}
}