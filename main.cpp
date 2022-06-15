#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;
#include "player.h"

int main() {
  int n,b,i,*p,s,diff;
  string name;
  
	int c[12]; //Main Array, that we will inject numbers into
	p = new int[10]; //Sub Array, that we will copy numbers into if we need it
  cout<<"Welcome to the land of beginning."<<endl;
  cout<<"Input your name: ";
  cin>>name;
  player me(name);
  cout<<endl<<"Collect 10 exp to win the game"<<endl<<endl;
  me.profession();
  
  monster mon1("Wild Rat",20);
  s = me.monster1(mon1);

  if (s==0){ //player dead
    cout<<"Thank you for playing"<<endl;
    return 0;
  }
  else{
    ++me;
  }

  monster mon2("Mummy", 30);
  s = me.monster2(mon2);
  if (s==0){ //player dead
    cout<<"Thank you for playing"<<endl;
    return 0;
  }
  else{
    ++me;
  }

  monster mon3("Baphomet",50);
  s = me.monster3(mon3);
  if (s==0){ //player dead
    cout<<"Thank you for playing"<<endl;
    return 0;
  }
  else{
    ++me;
  }


}
