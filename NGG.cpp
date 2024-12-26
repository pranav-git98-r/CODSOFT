#include<bits/stdc++.h>
using namespace std;
int main(){
srand(time(nullptr));//seeds the random number for getting random no. every time program is runned.
int random=1+(rand()%100);//sets limit from 1 to 1000
int value,count=1;
cout<<"---------WELCOME TO GUESS THE NUMBER GAME---------\n\n\n ";
while(true){
    
    
    cout<<"INSTRUCTION:Here you have to guess a number between 1 to 100\n";
    
    cout<<"Guess the number:\n";
    cin>>value;

    if(value>random){
        cout<<"Too high! Try Again.\n";
        count++;
    }
    else if(value<random){
        cout<<"Too low! Try Again.\n";
        count++;
    }
    else{
        cout<<"Congrtultions you guessed the number right in "<<count<<" turns\n\n\n";
        break;
    }
}

}