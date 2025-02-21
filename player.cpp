#ifndef __player__cpp_
#define __player__cpp_
#include "includes.h"
#include<windows.h> 
void update(){
	if(player.left){
		int t=grid.c[player.leftx][player.lefty];
		if(t==0 or t==5 or t==6)grid.c[player.leftx][player.lefty]=4;
	}
	if(rand()%32==0 and haveCoin){
		if(!enoughCoin(grid))
			grid.genCoin();
	}
	if(player.left)grid.set(player.leftx,player.lefty,4);
	if(GetAsyncKeyState(VK_W)){
		Player tp=player;
		--tp.x;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
			lastMove=clock();
		}
	}
	if(GetAsyncKeyState(VK_A)){
		Player tp=player;
		--tp.y;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
			lastMove=clock();
		}
	}
	if(GetAsyncKeyState(VK_S)){
		Player tp=player;
		++tp.x;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
			lastMove=clock();
		}
	}
	if(GetAsyncKeyState(VK_D)){
		Player tp=player;
		++tp.y;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
			lastMove=clock();
		}
	}
	if(GetAsyncKeyState(VK_UP)){
		Player tp=player;
		tp.dir=0;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
		}
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		Player tp=player;
		tp.dir=1;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
		}
	}
	if(GetAsyncKeyState(VK_DOWN)){
		Player tp=player;
		tp.dir=2;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
		}
	}
	if(GetAsyncKeyState(VK_LEFT)){
		Player tp=player;
		tp.dir=3;
		if(able(tp)){
			grid.remove(player);
			player=tp;
			grid.add(player);
		}
	}
	if(ableF){
		if(GetAsyncKeyState(VK_F)){
			if(player.money<5)return;
			player.money-=5;
			if(player.left==1){
				grid.remove(player);
				player.x=player.leftx,player.y=player.lefty;
				player.left=0;
				grid.add(player);
			}else{
				player.left=1;
				player.leftx=player.x,player.lefty=player.y;
				grid.set(player.leftx,player.lefty,4);
			}
		}		
	}
	if(ableC){
		if(GetAsyncKeyState(VK_C)){
			int tdir=(player.dir+2)%4;
			int tx=player.x+dx[tdir],ty=player.y+dy[tdir];
			if(ablePoint(tx,ty) and player.money>=3){
				grid.set(tx,ty,5);
				player.money-=3;
			}
		}		
	}
}
#endif
