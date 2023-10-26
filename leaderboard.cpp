#include <iostream>
#include <fstream>

using namespace std;

/**
Description:    Function to input high score into the leaderboard
Arguments:
player_name         Container for the board
level               For choosing leaderboard type
time_elapsed        Score of the player
Returns:        None
**/
void enter_leaderboard (string player_name, int level, double time_elapsed){
    if (level == 1){
        ofstream leaderboard("EASY_leaderboard.txt", fstream::app);
        
        if (leaderboard.is_open()){
            leaderboard << endl << time_elapsed << " seconds - " << player_name;
        }
        leaderboard.close();

        return;
    }
    if (level == 2){
        ofstream leaderboard("MEDIUM_leaderboard.txt", fstream::app);
        
        if (leaderboard.is_open()){
            leaderboard << endl << time_elapsed << " seconds - " << player_name;
        }
        leaderboard.close();

        return;
    }
    if (level == 3){
        ofstream leaderboard("HARD_leaderboard.txt", fstream::app);
        
        if (leaderboard.is_open()){
            leaderboard << endl << time_elapsed << " seconds - " << player_name;
        }
        leaderboard.close();

        return;
    }
}

/**
Description:    Function for displaying the leaderboard along with sorting it.
Arguments:
level               For choosing leaderboard type
Returns:        None
**/
void display_leaderboard (int level){
    if (level == 1){
        string line;
        vector <string> scores;
        ifstream leaderboard ("EASY_leaderboard.txt");
        if (leaderboard.is_open())
        {
            while (getline (leaderboard,line)){
                scores.push_back(line);
            }
            leaderboard.close();
            sort(scores.begin(), scores.end());

            cout << "|     EASY LEADERBOARD       |"<< endl;
            cout << "|    TIME     |     NAME     |"<< endl;
            for (int i=0; i < scores.size(); i++){
                cout << scores[i] << endl;
            }

        }
        return;
    }
    if (level == 2){
        string line;
        vector <string> scores;
        ifstream leaderboard ("MEDIUM_leaderboard.txt");
        if (leaderboard.is_open())
        {
            while (getline (leaderboard,line)){
                scores.push_back(line);
            }
            leaderboard.close();
            sort(scores.begin(), scores.end());

            cout << "|     MEDIUM LEADERBOARD     |"<< endl;
            cout << "|    TIME     |     NAME     |"<< endl;
            for (int i=0; i < scores.size(); i++){
                cout << scores[i] << endl;
            }

        }
        return;
    }
    
    if (level == 3){
        string line;
        vector <string> scores;
        ifstream leaderboard ("HARD_leaderboard.txt");
        if (leaderboard.is_open())
        {
            while (getline (leaderboard,line)){
                scores.push_back(line);
            }
            leaderboard.close();
            sort(scores.begin(), scores.end());

            cout << "|     HARD LEADERBOARD       |"<< endl;
            cout << "|    TIME     |     NAME     |"<< endl;
            for (int i=0; i < scores.size(); i++){
                cout << scores[i] << endl;
            }

        }
        return;
    }
}