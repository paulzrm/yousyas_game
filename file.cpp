#ifndef __file_cpp_
#define __file_cpp_
#include "includes.h"
void newFile(){
	countKill=0;
	slowPrint("请输入你的新存档名：");string s;cin>>s;
	fileName=s;
	ofstream ot;
	ot.open(fileName.c_str());
	ot<<Stage<<'\n';
//player info
/*
	int x,y,money,dir;
	int hp;
	bool left;
	int leftx,lefty;
*/
	ot<<Stage<<'\n';
	ot<<player.x<<' '<<player.y<<' '<<player.money<<' '<<player.dir<<'\n';
	ot<<player.hp<<' '<<player.left<<' '<<player.leftx<<' '<<player.lefty<<'\n';
	for(int i=0;i<8;++i)ot<<haveEnd[i]<<' ';
	ot<<skipPlot<<' '<<countKill;
	ot.close();
}
void saveFile(){
	ofstream ot;
	ot.open(fileName.c_str());
	ot<<Stage<<'\n';
	ot<<player.x<<' '<<player.y<<' '<<player.money<<' '<<player.dir<<'\n';
	ot<<player.hp<<' '<<player.left<<' '<<player.leftx<<' '<<player.lefty<<'\n';
	for(int i=0;i<8;++i)ot<<haveEnd[i]<<' ';
	ot<<skipPlot<<' '<<countKill;
	ot.close();
}
void loadFile(){
	slowPrint("请输入你的存档名：");string s;cin>>s;
	fileName=s;
	ifstream in;in.open(s.c_str());
	in>>Stage;
//player info
/*
	int x,y,money,dir;
	int hp;
	bool left;
	int leftx,lefty;
*/
	in>>player.x>>player.y>>player.money>>player.dir;
	in>>player.hp>>player.left>>player.leftx>>player.lefty;
	player.hp=3;
	for(int i=0;i<8;++i)in>>haveEnd[i];
	in>>skipPlot>>countKill;
	in.close();
}
void readFile(){
	ifstream in;in.open(fileName.c_str());
	in>>Stage;
//player info
/*
	int x,y,money,dir;
	int hp;
	bool left;
	int leftx,lefty;
*/
	in>>player.x>>player.y>>player.money>>player.dir;
	in>>player.hp>>player.left>>player.leftx>>player.lefty;
	player.hp=3;
	for(int i=0;i<8;++i)in>>haveEnd[i];
	in>>skipPlot;
	in.close();
}
#endif


