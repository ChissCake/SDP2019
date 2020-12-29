#include <FEHRandom.h>
#include <FEHLCD.h>#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
using namespace std;
//TO DO: Incomplete functions, indepth comments
class Player
{
private:
 int max_health;
 int health;
 int level;
 int exp;
 int exp_cap;
 int stats[4]; //Health, attack, defense, speed
 char weapon; //weapons should have id values
 int h_pot;
 int kills;
public:
 Player();
 void max_health_change(); //Sets max health
 void exp_level_change(int exp_change); //set exp
 void skill_change_add (int q, int i); //set skill
 void health_change (int health_change); //set health
 void use_h_pot(); //set h_pot
 int gethealth() const;
 int getlevel() const;
 int getstat(int i) const;
 int getexp() const;
 int getweapon()const;
 int num_h_pot() const;
 void kill_tracker();
 int getkills() const;
 void level_up();
};
//Class that tracks enemy as an object
class Enemy
{ 
private:
 int health;
 char name[50];
 int exp;
 int stats[4];
 char dialogue[150];
public:
 Enemy(char a[], int e, int s[], char d[]);
 void Enemy_talk(char dialogue[150]); //setdialogue
 void sethealth(int health); //Health is subtracted from total
 void setexp(int exp_change);
 void setstat(int stat, int num);
 int gethealth() const;
 int getexp() const;
 int getstat(int i) const;
 string getname() const;
 string getdialogue() const;
};
//Class that tracks NPC as an object
class NPC
{
private:
 char name[15];
 char dialogue[150];
public:
 NPC(char a[], char d[]);
 string getname() const;
 string getdialogue() const;
};
int randomEncounter(class Player *, class Enemy *);
int combat(class Player *, class Enemy *, int floor); //cycle between player turn and enemy turn
int playerturn(class Player *, class Enemy *); //attack, defend, heal, flee
int enemyturn(class Player *, class Enemy *); //attack or heals
void pickEnemy(class Enemy *, int floor); //Picks dialogue and Enemy that fights you
 *****INCOMPLETE**** WIP
char movement (int north, int east,int south, int west); //Creates a room which has a limited number of
directions based on the predefined parameters 
int ingame_menu(); //Lets player see equip, inventory, and stats and allows user to quit
void game(class Player *, class Enemy *); //Player can start game, see player stats, and see credits
void gameplay(class Player *, class Enemy *); //contains the actual game
void game_over();
int room1(int k1, class Player *, class Enemy *);
int room2(int k1, class Player *, class Enemy *);
int room3(int k1, class Player *, class Enemy *);
int room4(int k2, class Player *, class Enemy *);
int room5(int k2, class Player *, class Enemy *);
int room6(int k2, class Player *, class Enemy *);
int room7(int k2, class Player *, class Enemy *);
int room8(int k2, class Player *, class Enemy *);
int room9(int k2, class Player *, class Enemy *);
int room10(int k2, class Player *, class Enemy *);
int room11(int k2, class Player *, class Enemy *);
int room12(int k2, class Player *, class Enemy *);
int room13(int k2, class Player *, class Enemy *);
int room14(int k2, class Player *, class Enemy *);
int room15(int k2, class Player *, class Enemy *);
int player_action(int npc);
//Main function
int main(void)
{
 int stats[4] = {1,1,1,1};
 Player * p; 
 Enemy * e.Enemy('Enemy', 2, stats, 'PLACEHOLDER' );
 LCD.WriteLine("Proteus Chronicles")
 game(p,e);
 return 0;
}
//PLAYER member funtions
Player::Player()
{
 health = 10;
 level = 1;
 exp = 0;
 for (int i = 0; i < 4; i++)
 {
 stats[i] = 1;
 }
 weapon = 0;
 h_pot = 3;
 kills = 0;
}
void Player::max_health_change()
{
 max_health = 10 + 2 *stats[1];
}
void Player::exp_level_change(int exp_change)
{
 exp_cap = 10 * level;
 int level_up_check = level;
 if (exp_change + exp >= exp_cap)
 {
 level++; 
 exp = exp_cap - (exp_change + exp);
 }
 if (level > level_up_check)
 {
 level_up();
 }
}
void Player::level_up()
{
 int skill;
 for(int i = 0; i<4;i++)
 {
 stats[i] += 1;
 }
 for (int i = 0; i < 2; i++)
 {
 int k = i;
 LCD.WriteLine("Player has unused skill point(s).");
 LCD.WriteLine("Upgrade a skill: Health(1), Attack(2), Defense(3), or Speed(4). This is
permanent.");
 cin >> skill;
 skill_change_add(skill, 1);
 }
 max_health_change();
 health = max_health;
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
}
void Player::skill_change_add (int q, int i)
{
 stats[q] += i;
}
void Player::health_change (int health_change)
{
 health -= health_change;
}
void Player::use_h_pot() //set h_pot
{ 
 h_pot -= 1;
}
void Player::kill_tracker()
{
 kills +=1;
}
int Player::getkills() const
{
 return kills;
}
int Player::gethealth() const
{
 return health;
}
int Player::getlevel() const
{
 return level;
}
int Player::getstat(int i) const
{
 int k = stats[i];
 return k;
}
int Player::getexp() const
{
 return exp;
}
int Player::getweapon() const
{
 return weapon;
}
int Player::num_h_pot() const
{
 return h_pot;
}
//Enemy member functions
Enemy::Enemy(char a[], int e, int s[], char d[])
{ 
 strcpy(name, a);
 exp = e;
 for (int i = 0; i < 4; i++)
 {
 stats[i] = s[i];
 }
 strcpy(dialogue, d);
 health = 5 * s[0];
}
void Enemy::sethealth(int i)
{
 health = i;
}
void Enemy::setexp(int exp_change)
{
 exp = exp_change;
}
void Enemy::setstat(int stat, int num)
{
 stats[stat] = num;
}
int Enemy::gethealth() const
{
 return health;
}
string Enemy::getname() const
{
 return name;
}
int Enemy::getexp() const
{
 return exp;
}
int Enemy::getstat(int i) const
{
 int k = stats[i];
 return k;
}
string Enemy::getdialogue() const 
{
 return dialogue;
}
//NPC member functions
NPC::NPC(char a[], char d_NPC[])
{
 strcpy(name, a);
 strcpy(dialogue, d_NPC);
}
string NPC::getname() const
{
 return name;
}
string NPC::getdialogue() const
{
 return dialogue;
}
//User Functions
int randomEncounter(class Player * p, class Enemy * e, int floor)
{
 int randnum = rand() % 4;
 int combatval;
 if (rand != 0)
 { LCD.WriteLine("An Enemy appeared!" << endl;
 combatval = combat(p,e, floor);
 }
 return combatval;
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int combat(class Player * p, class Enemy * e, int floor) //cycle between player turn and enemy turn
 Runs on a tick system to determine battle speed
{
 //0- enemy alive
 //1- Enemy dies 
 //2- player defends
 //3- player flees
 //4- Player lives
 //5 - Player dies
 int p_counter;
 int e_counter;
 // WIP- pickEnemy(e,floor);
 e = new Enemy(b_name, exp_base, b_stats, b_d);
 for (int q = 0; q < 100; q++)
 {
 if (q % (25 - p->getstat(4) ) == 0)
 {
 p_counter = playerturn(p,e);
 }
 switch (p_counter)
 {
 case 0:
 break;
 case 2:
 //defend
 p->skill_change_add(3,1);
 break;
 case 1:
 //add exp to player
 LCD.WriteLine("Enemy has died!");
 p->exp_level_change(e->getexp());
 p->kill_tracker();
 return 0;
 break;
 case 3:
 LCD.WriteLine("Player has run away");
 return 0;
 break;
 }
 if (q % (25 - e->getstat(4) ) == 0)
 {
 e_counter = enemyturn(p, e);
 }
 switch (e_counter) 
 {
 case 4:
 break;
 case 5:
 return 1;
 break;
 }
 if (q == 99)
 {
 q = 0;
 }
 if (p_counter == 2)
 {
 p->skill_change_add(3,-1);
 }
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int playerturn(class Player * p, class Enemy * e) //attack, defend, heal, flee //returns 1 to if enemy
is dead, returns 0 if enemy is still alive, returns 2 if player defends, returns 3 if user flees,
{
 int user_prompt;
 int flee;
 while (TRUE)
 {
 //INSERT ICONS *****************************
 switch (user_prompt)
 {
 case (1):
 //attack
 int dmg;
 LCD.WriteLine("PLAYER atttacks");
 dmg = e->getstat(3) - p->getstat(2); 
 e->sethealth(e->gethealth() - dmg);
 LCD.WriteLine("Enemy takes");
 LCD.WriteLine(dmg);
 LCD.WriteLine("damage");
 if( e->gethealth() <= 0)
 {
 return 1;
 }
 else
 {
 return 0;
 }
 break;
 case (2):
 //defend
 return 2;
 break;
 case (3):
 if (p->num_h_pot() > 0)
 {
 //decrease h_pot by one
 //Increase health by 4
 return 0;
 }
 else
 {
 LCD.WriteLine("No more Health pots.");
 }
 break;
 case (4):
 //flee
 if (p->getstat(4) > e->getstat(4) * 2)
 {
 return 3;
 }
 else if (p->getstat(4) >= e->getstat(4))
 {
 flee = rand() % 3; 
 if (flee == 0 || flee == 1)
 {
 LCD.WriteLine("PLAYER successfuly flees.");
 return 3;
 }
 else
 {
 LCD.WriteLine("Player fails to flee.");
 return 0;
 }
 }
 else if (p->getstat(4) < e->getstat(4))
 {
 flee = rand() % 5;
 if (flee == 0)
 {
 LCD.WriteLine("PLAYER succesfuly flees.");
 return 3;
 }
 else
 {
 LCD.WriteLine("Player fails to flee.");
 return 0;
 }
 }
 break;
 default:
 LCD.WriteLine("Input not recognized, try again.");
 break;
 }
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
 return 0;
}
int enemyturn(class Player * p, class Enemy * e) //attack or heals returns 4 if Player is still
alive, returns 5 if Player dies ***INCOMPLETE*** DODGE FUNCTION
{ 
 int heal = rand();
 int dmg;
 if (e->gethealth() < 10)
 {
 if( heal % 3 == 0)
 {
 LCD.WriteLine("ENEMY heals");
 e->sethealth(e->gethealth() + 4);
 }
 }
 LCD.WriteLine("Enemy attacks");
 dmg = p->getstat(3) - e->getstat(2);
 p->health_change(dmg);
 LCD.WriteLine("Player takes");
 LCD.WriteLine(dmg);
 LCD.WriteLine("damage.");
 if (p->gethealth() > 0)
 {
 return 1;
 }
 else
 {
 return 0;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
void pickEnemy(class Enemy * e, int floor) //Picks enemy ****INCOMPLETE****
{
 int rnum = rand();
 int exp_base = 2;
 char b_name[7] = "Bandit";
 int b_stats[4] = {1,1,0,0};
 char b_d[12] = "PLACEHOLDER";
 char ab_name[13] = "Angry Bandit"; 
 int ab_stats[4] = {2,1,2,0};
 char ab_d[12] = "PLACEHOLDER";
 char wb_name[11] = "Wild Beast";
 int wb_stats[4] = {2,3,2,2};
 char wb_d[12] = "PLACEHOLDER";
 //pre defined enemies
 if (floor == 1)
 {
 if ( rnum % 2 == 1)
 {
 Enemy e(b_name, exp_base, b_stats, b_d);
 }
 else
 {
 Enemy e(ab_name, 2 + exp_base, ab_stats, ab_d);
 }
 }
 else if(floor == 2)
 {
 if ( rnum % 2 == 1)
 {
 Enemy e(wb_name, 4 + exp_base, wb_stats, wb_d);
 }
 else
 {
 Enemy e(ab_name, 2 + exp_base, ab_stats, ab_d);
 }
 }
}
char movement (int north, int east,int south, int west) //Creates a room which has a limited number of
directions based on the predefined parameters Determines what direction the player goes in
****INCOMPLETE*****
{
 int user_action;
 LCD.WriteLine("Actions:"); //INSERT ICONS *****************************
 if (north == TRUE)
 {
 }
 if (east == TRUE) 
 {
 }
 if (south == TRUE)
 {
 }
 if (west == TRUE)
 {
 }
 while(TRUE)
 {
 switch (user_action)
 {
 case 1:
 if(north == TRUE)
 {
 return 'N';
 }
 break;
 case 2:
 if(east == TRUE)
 {
 return 'E';
 }
 break;
 case 3:
 if(south == TRUE)
 {
 return 'S';
 }
 break;
 case 4:
 if(west == TRUE)
 {
 return 'W'; 
 }
 break;
 }
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int player_action (int npc)
{
 int user_action;
 int ig_menu;
 while(TRUE)
 {
 //INSERT ICONS *****************************
 switch (user_action)
 {
 case 0:
 ig_menu = ingame_menu();
 return ig_menu;
 break;
 case 1:
 return 1;
 break;
 case 2:
 return 2;
 break;
 }
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
} 
int ingame_menu() //Lets player see equip, inventory, and stats and allows user to quit //0 to return to
menu screen ****INCOMPLETE****
{
 int user_action;
 LCD.WriteLine("Player name ");
 LCD.WriteLine("Health: #/max");
 LCD.WriteLine("attack");
 LCD.WriteLine("defense");
 LCD.WriteLine("speed");
 LCD.WriteLine("Health pots left: #");
 LCD.WriteLine("Equipped");
 //INSERT ICONS *****************************
 if (user_action == 1)
 {
 return user_action;
 }
 else if (user_action == 0)
 {
 return 16;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
void game(class Player * p, class Enemy * e) //Player can start game, see player stats, and see credits //0
to start new game ****INCOMPLETE****
{
 int user_action;
 while(TRUE)
 {
 //INSERT ICONS *****************************
 switch(user_action)
 {
 case 0:
 gameplay(p,e);
 break;
 case 1://stats 
 LCD.WriteLine("games played ");
 LCD.WriteLine("games won");
 break;
 case 2:
 LCD.WriteLine("Credits");
 break;
 default:
 LCD.WriteLine("Error, try again, Menu flag");
 break;
 }
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
void gameplay(class Player * p, class Enemy * e)
{
 int k1, k2;
 //Dialogue about the game
 int room = room1(k1,p,e);
 while(TRUE)
 {
 switch(room)
 {
 case 1:
 room = room1(k1,p,e);
 break;
 case 2:
 room = room2(k1,p,e);
 break;
 case 3:
 room = room3(k1,p,e);
 break;
 case 4:
 room = room4(k2,p,e); 
 break;
 case 5:
 room = room5(k2,p,e);
 break;
 case 6:
 room = room6(k2,p,e);
 break;
 case 7:
 room = room7(k2,p,e);
 break;
 case 8:
 room = room8(k2,p,e);
 break;
 case 9:
 room = room9(k2,p,e);
 break;
 case 10:
 room = room10(k2,p,e);
 break;
 case 11:
 room = room11(k2,p,e);
 break;
 case 12:
 room = room12(k2,p,e);
 break;
 case 13:
 room = room13(k2,p,e);
 break;
 case 14:
 room = room14(k2,p,e);
 break;
 case 15:
 room = room15(k2,p,e);
 break;
 case 16:
 game_over(); 
 return;
 break;
 }
 }
}
void game_over() // *****************************************
{
 int game_over;
 LCD.WriteLine("Game over.");
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room1(int k1,class Player *p, class Enemy * e)//N-1, E-2, S-3, W-4
{
 char move;
 LCD.WriteLine("Welcome!");
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(1,0,0,0);
 if (move == 'N')
 {
 return 2;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room2(int k1,class Player *p, class Enemy * e)
{
 char move;
 int p_act = player_action(0);
 if (p_act == 16)
 { 
 return 16;
 }
 move = movement(1,0,1,1);
 if (move == 'N' && k1 == 1)
 {
 return 4;
 }
 else if( move == 'N')
 {
 LCD.WriteLine("Woah! The house is still burning!");
 }
 if (move == 'W')
 {
 return 3;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room3(int k1,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,0,0);
 if ( move == 'E')
 {
 return 2;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y)); 
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room4(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,1,0);
 if (move == 'E')
 {
 return 5;
 }
 if (move == 'S')
 {
 return 2;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room5(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0); 
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,0,1);
 if (move == 'E')
 {
 return 6;
 }
 if (move == 'W')
 {
 return 4;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room6(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,1,1);
 if (move == 'E')
 {
 return 8;
 }
 if (move == 'W')
 {
 return 5;
 } 
 if (move == 'S')
 {
 return 7;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room7(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(1,0,0,0);
 if (move == 'S')
 {
 return 6;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room8(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2); 
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(1,1,0,1);
 if (move == 'E')
 {
 return 10;
 }
 if (move == 'W')
 {
 return 6;
 }
 if (move == 'S')
 {
 return 9;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room9(int k2,class Player *p, class Enemy * e)
{
 char move;
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,0,1,0);
 if ( move == 'S')
 {
 return 8;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y)); 
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room10(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,1,1);
 if (move == 'E')
 {
 return 11;
 }
 if (move == 'W')
 {
 return 8;
 }
 if (move == 'S')
 {
 return 14;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room11(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters 
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,0,1);
 if (move == 'E')
 {
 return 12;
 }
 if (move == 'W')
 {
 return 10;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room12(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,1,0,1);
 if (move == 'E')
 {
 return 13; 
 }
 if (move == 'W')
 {
 return 11;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room13(int k2,class Player *p, class Enemy * e) //Chest
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(0,0,0,1);
 if (move == 'W')
 {
 return 12;
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room14(int k2,class Player *p, class Enemy * e)
{
 char move;
 player_action(0);
 move = movement(1,0,1,0); 
 if (move == 'S')
 {
 return 10;
 }
 if (move == 'S' && k2 == 1)
 {
 return 15;
 }
 else if (move == 'S')
 {
 LCD.WriteLine("Kill Count Lock");
 }
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
}
int room15(int k2,class Player *p, class Enemy * e)
{
 char move;
 int combat;
 //Random encounters
 combat = randomEncounter(p,e,2);
 int p_act = player_action(0);
 if (p_act == 16)
 {
 return 16;
 }
 move = movement(1,0,1,0);
 if (move == 'N')
 {
 return 14;
 }
 if (move == 'S' )
 {
 LCD.WriteLine("Cheesy Dialogue");
 LCD.WriteLine("To Be Continued");
 return 16;
 } 
 while(!LCD.Touch(&x,&y));
 while(LCD.Touch(&x,&y));
 LCD.Touch(&x,&y);
 LCD.Clear();
} 
