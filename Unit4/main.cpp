#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class game{

public:
    game();
    bool check(int& g);
    void run();

private:
    int number;
    int tries;
    int guess;
};
//  The intro class is extending the welcome class.
class welcome{
    public:
     void greeting(){
        cout << "Welcome to a C++ number-guessing game!\n";     
    }
};

class intro : public welcome{
    public:
        void how_to_play(){
         cout << "Guess a number between 1 and 100!\n";
         cout << "Good luck!\n\n";         
        }
};

game :: game() :  number(rand() % 100 + 1), tries(0), guess(0){}



bool game :: check(int& g){

    if (g > number){
        cout << "Sorry, too high!\n\n";
        return false;
    } else if (g < number){
        cout << "Sorry too low!\n\n";
        return false;
    } else{
        cout << "Great job, you have guessed the number!\n";
        cout << "You did it in " << tries << " attempts!\n\n";
        return true;
    }
}

void game :: run(){

    while (guess != number){
        cout << "Please enter your guess: ";
        cin >> guess;
        ++tries;

        if (check(guess))
            break;
    }
}

int main(){
    srand(static_cast<unsigned int>(time(0)));

    intro htp;
    htp.greeting();
    htp.how_to_play();

    game guessing_game;
    guessing_game.run();

    cin.ignore();
    cin.get();
    return 0;
}