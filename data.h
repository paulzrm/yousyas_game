#ifndef __data__
#define __data__
#define ld long double 
#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};//up,right,down,left
int dy[]={0,1,0,-1};
int enemyStopTime=5;
int eyeSightAngle=4;
int enemyStep=4;
int standardClock;
int enemySpeed=0;
int updateTime=50;
int newEnemyTime=10;
int gridN,gridM;
int haveCoin=0;
int ableF=0,ableC=0;
string yousyaColor,enemyColor;
int mov=0,inTut=1;
int countKill=0;
int haveEnd[10];
int enemyLimit;
int specialRule;
int Stage;
string fileName;
int maxCoin=10;
int skipPlot;
int die;
int countKey;
int touchPalace;
int cantStop;clock_t lastMove;
int attackWaitTime=2;
int enemyEyesight=5;
int generateLimit=-1; 
#endif
