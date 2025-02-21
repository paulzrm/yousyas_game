#ifndef __fight_cpp_
#define __fight_cpp 
#include "includes.h"
int check(Enemy enemy,Player player){
	pair<int,int>e1,e2,p1,p2;
	e1={enemy.x,enemy.y};
	e2={enemy.x+dx[enemy.dir],enemy.y+dy[enemy.dir]};
	p1={player.x,player.y};
	p2={player.x+dx[player.dir],player.y+dy[player.dir]};
	if(specialRule){
		if(p2==e1)return 1;
		if(p2==e2 or p1==e1 or p1==e2)return 2;
		return 0;
	}
	if(p2==e1 or p2==e2)return 1;//player win
	if(p1==e1 or p1==e2)return 2;//enemy win
	return 0;
}
int checkCrash(){
	if(standardClock-lastUpdate>updateTime)updateEnemyList(),lastUpdate=standardClock;
	if(standardClock-lastGenerate>newEnemyTime and enemies.size()<enemyLimit)newEnemy(enemyEyesight),lastGenerate=standardClock;
	for(int i=0;i<enemies.size();++i){
		Enemy&enemy=enemies[i];
		if(enemy.alive==0)continue;
		int t=check(enemy,player);
		if(t==0)continue;
//		cerr<<"CRASH\n";
//		cerr<<"X,Y: "<<enemy.x<<' '<<enemy.y<<'\n';
//		cerr<<"TYPE: "<<t<<'\n';
//		system("pause");
		if(t==1)eraseEnemy(enemy),enemy.alive=0,++countKill;
		else{
			--player.hp;
			eraseEnemy(enemy);
			enemy.alive=0;
			if(player.hp==0)return 1;//return 1:player dies
		}
	}
	return 0;
}
#endif
