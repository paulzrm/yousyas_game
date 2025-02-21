#ifndef __enemy__h_
#define __enemy__h_
#include<bits/stdc++.h>
using namespace std;
struct Enemy{
	int x,y,dir,sight;
	int moveable;
	int step,lastmove,alive;
	int lastready,ready; 
	void generate(int eyesight=4){
		moveable=1;lastready=0,ready=0;
		x=rand()%gridN+1,y=rand()%gridM+1;
		dir=rand()%4;lastmove=0;alive=1;
		sight=rand()%eyesight+eyesight;
	}
	void setPos(int xx,int yy,int dd){
		x=xx,y=yy,dir=dd;
	}
};
vector<Enemy>enemies;
Enemy newEnemy();
int dist(Enemy a,Player b);
bool tooNear(Enemy a,Player b);
bool canSee(Enemy a,Player b); 
pair<int,int> getDir(Enemy a,Player b);
void move(Enemy&enemy);
void updateEnemy();
void newSpecialEnemy(int x,int y,int d);
void updateEnemyList();
void clearEnemies();
#endif
