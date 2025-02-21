#ifndef __enemy__cpp_
#define __enemy__cpp_
#include "includes.h"
int dist(Enemy a,Player b){
	return floor(sqrt(1.0*abs(a.x-b.x)*abs(a.x-b.x)+1.0*abs(a.y-b.y)*abs(a.y-b.y)));
}
bool tooNear(Enemy a,Player b){
	if(inTut){
		if(dist(a,b)<5)return 1;
	}else if(dist(a,b)<10)return 1;
	return 0;
}
void newSpecialEnemy(int x,int y,int d){
	Enemy rt;rt.generate(30);
	rt.x=x,rt.y=y,rt.dir=d;
	enemies.push_back(rt);
	drawEnemy(rt);
}
void newEnemy(int eyesight=15){
	if(specialRule)return; 
	if(generateLimit==0)return;
	if(generateLimit!=-1)--generateLimit;
	Enemy rt;rt.generate(eyesight);
	while(!able(rt) or tooNear(rt,player))rt.generate(eyesight);
	rt.moveable=mov;
	enemies.push_back(rt);
	drawEnemy(rt);
}
bool canSee(Enemy a,Player b){
	if(specialRule)a.sight=0;
	if(dist(a,b)>a.sight) return 0;
//	return 1;
	int vx=b.x-a.x,vy=b.y-a.y;
	int ex=dx[a.dir],ey=dy[a.dir];
	int dot=(vx*ex+vy*ey);dot*=dot;
	ld norm_v=vx*vx+vy*vy;
	ld norm_e=ex*ex+ey*ey;
	if(dot<=norm_v*norm_e*eyeSightAngle) return 1;
	return 0;
}
pair<int,int> getDir(Enemy a,Player b){
	if(!canSee(a,b))return {-1,-1};
	int bestDir=-1,minDist=dist(a,b),bestD2=-1;
	for(int d=0;d<4;d++){
		int nx=a.x+dx[d],ny=a.y+dy[d];
		Enemy nextPos=a;
		for(int d2=0;d2<4;++d2){
			nextPos.setPos(nx,ny,d);
			eraseEnemy(a);
			if(!able(nextPos)){
				drawEnemy(a);
				continue;
			}
			drawEnemy(a);
			int newDist=dist(nextPos,b);
			if(newDist<minDist or (newDist==minDist and d2==d)){
				minDist=newDist;
				bestDir=d;
				bestD2=d2;
			}			
		}
	}
//	if(dist(a,b)<5){
//		cerr<<"en "<<a.x<<' '<<a.y<<'\n';
//		cerr<<"pl "<<b.x<<' '<<b.y<<'\n';
//		cerr<<"GETDIR: "<<bestDir<<'\n';
//		system("pause");		
//	}
	return {bestDir,bestD2};
}
void move(Enemy&enemy){
	pair<int,int>p=getDir(enemy,player);
	int t=p.first,t2=p.second;
	enemy.lastmove=standardClock;
	bool fd=0;
	for(int d=0;d<4;++d){
		if(enemy.x+dx[d]==player.x and enemy.y+dy[d]==player.y){
			if(enemy.ready and standardClock-enemy.lastready>attackWaitTime){
				eraseEnemy(enemy);
				enemy.dir=d;
				drawEnemy(enemy);
				return;				
			}
			fd=1; 
			if(!enemy.ready){
				enemy.ready=1;
				enemy.lastready=standardClock;
			}
		}
	}
	if(!fd)enemy.ready=0;
	else return;
	if(t!=-1){
		if((enemy.x+dx[t]==player.x and enemy.y+dy[t]==player.y) or (enemy.x+dx[t]+dx[t2]==player.x and enemy.y+dy[t]+dy[t2]==player.y)){
			if(enemy.ready and standardClock-enemy.lastready>attackWaitTime){
				eraseEnemy(enemy);
				enemy.x+=dx[t];
				enemy.y+=dy[t];
				enemy.dir=t2;
				drawEnemy(enemy);
				return;			
			}
			fd=1; 
			if(!enemy.ready){
				enemy.ready=1;
				enemy.lastready=standardClock;
			}
			return;
		}
		eraseEnemy(enemy);
		enemy.x+=dx[t];
		enemy.y+=dy[t];
		enemy.dir=t2;
		drawEnemy(enemy);
		return;	
	}
	enemy.ready=0;
	if(enemy.step==0){
		if(rand()%enemyStopTime)return;
		vector<int>vdir;vdir.clear();
		for(int d=0;d<4;++d){
			Enemy nextPos=enemy;
			nextPos.dir=d;
			eraseEnemy(enemy);
			if(able(nextPos))vdir.push_back(d);
			drawEnemy(enemy);
		}
		if(vdir.size()==0)return;
		int id=rand()%(int)(vdir.size());
		eraseEnemy(enemy);
		enemy.dir=vdir[id];
		enemy.step=rand()%enemyStep+enemyStep;
		drawEnemy(enemy);
	}else{
		Enemy nextPos=enemy;
		nextPos.x+=dx[nextPos.dir],nextPos.y+=dy[nextPos.dir];
		eraseEnemy(enemy);
		if(able(nextPos)){
			eraseEnemy(enemy);
			enemy=nextPos;
			drawEnemy(enemy);
		}else{
			
		}
		drawEnemy(enemy);
		--enemy.step;
	}
}
void updateEnemy(){
	for(int i=0;i<enemies.size();++i){
		Enemy&enemy=enemies[i];
		if(enemy.alive==0)continue;
		if(standardClock-enemy.lastmove<enemySpeed)continue;
//		eraseEnemy(enemy); 
		move(enemy);
//		drawEnemy(enemy);
	}
}
void updateEnemyList(){
	vector<Enemy>newList;newList.clear();
	for(int i=0;i<enemies.size();++i)if(enemies[i].alive)newList.push_back(enemies[i]);
	enemies=newList;
}
void clearEnemies(){
	for(int i=0;i<enemies.size();++i)enemies[i].alive=0,eraseEnemy(enemies[i]);
	updateEnemyList();
} 
#endif 
