#ifndef __player__h_
#define __player__h_
#include<bits/stdc++.h>
using namespace std;
struct Player{
	int x,y,money,dir;
	int hp;
	bool left;
	int leftx,lefty;
	void init(){
		leftx=0,lefty=0;
		money=0;left=0;
		dir=0;hp=3;
	}
	void setPos(int xx,int yy){
		x=xx;
		y=yy;
	}
	void setDir(int d){
		dir=d;
	}
}player;
void update();
#endif
