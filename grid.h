#ifndef __grid__h_
#define __grid__h_
#include<bits/stdc++.h>
using namespace std;
struct Grid{
	int n,m;
	int c[133][133];
	string name;
	void init();
	void init(int N,int M);
	void test();
	void generateEmpty();
	void generate();
	void genCoin();
	void remove(Player p);
	void add(Player&p);
	void set(int x,int y,int d){c[x][y]=d;}
    int getId(int x,int y);
	void genKey();
	void genPalace();
    void generateMaze(int keyNumber);
    void updateObstacle();
    void updateLightening();
}grid;
void shit();
char trans(int x);
bool ablePoint(int x,int y);
bool able(Player p);
void drawEnemy(Enemy enemy);
void eraseEnemy(Enemy enemy);
void print(Grid g,Player p);
bool enoughCoin(Grid g);
#endif
