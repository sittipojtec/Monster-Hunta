#include <iostream>
#include <string>
using namespace std;

class monster{
public:
  string name;
  int mhp;
	monster(string n,int h);
  ~monster();
  void appear();
  int attackM(int);
  void die();
};

monster::monster(string n, int h){
  name = n;
  mhp = h;
}

void monster::appear(){
  cout<<"================================="<<endl;
  cout<<name<<" Appear: "<<mhp<<" HP"<<endl<<endl;
}

monster::~monster(){
	//Something about being annihilated.
}


int monster::attackM(int atk){
  int dmg;
  dmg = rand()%(atk+1)+4; //Player DMG
  cout<<"You Have Dealt "<<dmg<<" DMG to "<<name<<endl;
  mhp -= dmg;
  if (mhp<=0){
    cout<<name<<" has been knocked out "<<endl;
    return 1;
  }
  else{
	cout<<name<<" Remaining Health is: "<<mhp<<endl<<endl;
    return 0;
    }
}


void monster::die(){
  mhp=0;
  cout<<name<<" Destroyed"<<endl;
}


