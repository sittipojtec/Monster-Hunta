#include <iostream>
using namespace std;
#include "monster.h"
#include "sorting.h"

// Win condition = When exp reaches a certain point(10)

class player {
private:
  string name;
  int job;
  int exp;
  int hp = 20;
  int atk;

public:
  player(string a);
  ~player();
  void profession();
  int monster1(monster &mon);
  int monster2(monster &mon);
  int monster3(monster &mon);
  int playerGetDMG1(monster &m);
  int playerHeal(monster &m);
  void operator++();
  void get(int x);
  void die();
};

void player::profession() {
  int profession;
  cout << "What is your Profession?" << endl;
  cout << "1.Knight" << endl;
  cout << "  Hp: ***   Atk: **  " << endl;
  cout << "2.Assassin" << endl;
  cout << "  Hp: **    Atk: ***" << endl;
  cout << "3.Villager" << endl;
  cout << "  Hp: *     Atk: *  " << endl;
  cout << "If you pick anything other than 1 and 2, you will become a Villager!"
       << endl;
  cout << "Your decision is: ";
  cin >> profession;
  switch (profession) {
  case 1:
    get(1);
    break;
  case 2:
    get(2);
    break;
  default:
    get(3);
    break;
  }
}

player::player(string a) { name = a;}

player::~player() {}

void player::get(int x) {
  if (x == 1) {
    cout << "You Have Selected Knight (40 HP)" << endl;
    hp = 40;
    atk = 6;
    exp = 0;
  } else if (x == 2) {
    cout << "You Have Selected Assassin (30 HP)" << endl;
    hp = 30;
    atk = 8;
    exp = 0;
  } else {
    cout << "You Have Selected Villager (20 HP)" << endl;
    hp = 20;
    atk = 4;
    exp = 0;
  }
  cout << endl;
}

void player::operator++() {
  cout << "Healed 15 hp" << endl;
  hp += 15; // Restore HP when defeat monster
  cout << "Player Remaining Health is: " << hp << endl;
  cout << "Exp +4" << endl;
  exp+=4; //Defeat 3 monsters to win
  cout << "Player exp is " << exp << endl;
        if(exp==10){
          cout<<"10 exp reached!"<<endl;
          cout<<"You have won the game!"<<endl;
        }
  
}

int player::playerGetDMG1(monster &m) {
  int mdmg;
  mdmg = rand() % 4 + 4; // 4-7 DMG
  cout << m.name << " Has Deal " << mdmg << " DMG to You." << endl;
  hp -= mdmg;
  if (hp > 0) {
    cout << "Player Remaining Health is: " << hp << endl;
    return 0;
  } else {
    cout << "Player Remaining Health is: " << 0 << endl;
    return 1;
  }
}

int player::playerHeal(monster &m) {
  int mdmg, heal;
  int mhp = m.mhp;
  heal = rand() % 4 + 7; // Restored 4-10 HP
  hp += heal;
  cout << name << " Has Heal " << heal << " HP" << endl;
  cout << "Player Remaining Health is: " << hp << endl;
  mdmg = rand() % 2 + 4; // 2-5 DMG
  cout << m.name << " Has Deal " << mdmg << " DMG to You." << endl;
  hp -= mdmg;
  if (hp > 0) {
    cout << "Player Remaining Health is: " << hp << endl;
    return 0;
  } else {
    cout << "Player Remaining Health is: " << 0 << endl;
    return 1;
  }
}



int player::monster1(monster &mon) {
  int choice, stop = 0, action, in;
  int c[3];
  monster m("Wild Rat", 20);
  m.appear();
  while (hp >= 1 && stop == 0) {
    cout << "Do what?" << endl;
    cout << "1.Attack" << endl;
    cout << "2.Heal" << endl;
    cout << "Wrong input will choose heal" << endl;
    cin >> in;
    if (in == 1) {
      cout << "Action: Attack" << endl << endl;
    } else {
      cout << "Action: Heal" << endl << endl;
    }
    RanArrayGen(c, 3);
    bubbleSort(c, 3);
    cout<<endl;
    cout<<"Sort the given number Array to determine the result of an action"<< endl;
    action = ArrayGen(c, 3);
    if (action == 1) {
      if (in == 1) {
        choice = 1;
      } else {
        choice = 2;
      }
    } else {
      choice = 3;
    }
    int a, b;
    switch (choice) {
    case 1:
      b = m.attackM(atk);
      if (b == 1) {
        stop = 1;
        break;
      } else {
        a = playerGetDMG1(m);
        break;
      }
    case 2:
      b = playerHeal(m);
      if (b == 1) {
        stop = 1;
        break;
      }
      break;

    default:
      playerGetDMG1(m);
      break;
    }
    cout << endl;
    cout << "=================================" << endl;
  }
  if (hp <= 0) {
    die();
    return 0;
  } else {
    mon.die();
    cout << name << " Has Returned to the Land of Beginning." << endl;
    return 1;
  }
}

int player::monster2(monster &mon) {
  int choice, stop = 0, action, in;
  int c[5];
  monster m("Mummy", 30);
  m.appear();
  while (hp >= 1 && stop == 0) {
    cout << "Do what?" << endl;
    cout << "1.Attack" << endl;
    ;
    cout << "2.Heal" << endl;
    cout << "Wrong input will choose heal" << endl;
    cin >> in;
    if (in == 1) {
      cout << "Action: Attack" << endl << endl;
    } else {
      cout << "Action: Heal" << endl << endl;
    }
    RanArrayGen(c, 3);
    bubbleSort(c, 3);
    cout << "Sort the given number Array to determine the result of an action"
         << endl;
    action = ArrayGen(c, 3);
    if (action == 1) {
      if (in == 1) {
        choice = 1;
      } else {
        choice = 2;
      }
    } else {
      choice = 3;
    }
    int a, b;
    switch (choice) {
    case 1:
      b = m.attackM(atk);
      if (b == 1) {
        stop = 1;
        break;
      } else {
        a = playerGetDMG1(m);
        break;
      }
    case 2:
      b = playerHeal(m);
      if (b == 1) {
        stop = 1;
        break;
      }
      break;

    default:
      playerGetDMG1(m);
      break;
    }
    cout << endl;
    cout << "=================================" << endl;
  }
  if (hp <= 0) {
    die();
    return 0;
  } else {
    mon.die();
    cout << name << " Has Returned to the Land of Beginning." << endl;
    return 1;
  }
}

int player::monster3(monster &mon) {
  int choice, stop = 0, action, in;
  int c[7];
  monster m("Baphomet", 50);
  m.appear();
  while (hp >= 1 && stop == 0) {
    cout << "Do what?" << endl;
    cout << "1.Attack" << endl;
    ;
    cout << "2.Heal" << endl;
    cout << "Wrong input will choose heal" << endl;
    cin >> in;
    if (in == 1) {
      cout << "Action: Attack" << endl << endl;
    } else {
      cout << "Action: Heal" << endl << endl;
    }
    RanArrayGen(c, 3);
    bubbleSort(c, 3);
    cout << "Sort the given number Array to determine the result of an action"
         << endl;
    action = ArrayGen(c, 3);
    if (action == 1) {
      if (in == 1) {
        choice = 1;
      } else {
        choice = 2;
      }
    } else {
      choice = 3;
    }
    int a, b;
    switch (choice) {
    case 1:
      b = m.attackM(atk);
      if (b == 1) {
        stop = 1;
        break;
      } else {
        a = playerGetDMG1(m);
        break;
      }
    case 2:
      b = playerHeal(m);
      if (b == 1) {
        stop = 1;
        break;
      }
      break;

    default:
      playerGetDMG1(m);
      break;
    }
    cout << endl;
    cout << "=================================" << endl;
  }
  if (hp <= 0) {
    die();
    return 0;
  } else {
    mon.die();
    cout << name << " Has Returned to the Land of Beginning." << endl;
    return 1;
  }
}

void player::die() {
  hp = 0;
  cout << name << " Died" << endl;
}