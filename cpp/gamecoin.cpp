#include<bits/stdc++.h>
using namespace std;
use case
1)First one player will be picked random
2)picked player will be guessing the coin value
3)coin will be tossed
4)printing the loosing or winning state of player
actor
1)player 1
2)player 2
3)coin
4)coingame

Now you can go for class diagram

And then before start implementing 
class player{
public:
    string name;
    string coinoption;
    string coinvalue[2] = {"heads","tails"};
    player(){
    }
    player(string name){
        this->name=name;
    }
    string getcoinoption(){
        return coinoption;
    }
    string setcoinoption(string opponent){
        coinoption= (opponent=="heads")?"tails":"heads";
    }
    string getrandcoinoption(){
        int randnum = rand()%2;
        coinoption = coinvalue[randnum];
        return coinoption;
    }
    void didplayerwin(string winningflip){
        if(coinoption==winningflip){
            cout<<"win with flip "<<coinoption<<endl;
        }else{
            cout<<"loose with flip "<<coinoption<<endl;
        }
    }
};
class coin{
public:
    string coinoption;
    coin(){
        string coinvalue[] = {"heads","tails"};
        int randnum = rand()%2;
        coinoption = coinvalue[randnum];
    }
    string getcoinoption(){
        return coinoption;
    }
};
class coingame{
public:
    vector<player>players;
    string coinvalue[2] = {"heads","tails"};
    coin thecoin =  coin();

    coingame(string p1,string p2){
        players.resize(2);
        players[0] =  player(p1);
        players[1] =  player(p2);
    }
    void startgame(){
        int randnum = rand()%2;
        string playerspick = players[randnum].getrandcoinoption();

        int opponentindex = randnum==0?1:0;
        players[opponentindex].setcoinoption(playerspick);
        string winningflip = thecoin.getcoinoption();
        players[0].didplayerwin(winningflip);
        players[1].didplayerwin(winningflip);
    }
};



int main(){
    coingame thecoingame = coingame("mark","tom");
    string useranswer;
    do{
        thecoingame.startgame();
        cout<<"Play Again"<<endl;
        cin>>useranswer;

    }while(useranswer=="y");
}
