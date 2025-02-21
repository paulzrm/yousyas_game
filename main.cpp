#include "includes.cpp"
using namespace std;
int main(){
	yousyaColor=BLUE;
	enemyColor=RED;
	hideCursor(); 
	srand(time(NULL));
	player.init();
	while(1){
		if(die){
			system("cls");
			step0();
			die=0;
		}
		bgn:;
		static const string clear_screen="\033[H";
		cout<<clear_screen;
		step0();GetAsyncKeyState(VK_E);
		slowPrint("\n      C 继续游戏\n");
		slowPrint("\n\n      L 读取存档\n");
		slowPrint("\n\n      N 新游戏\n");
		slowPrint("\n\n      V 查看已解锁结局\n");
		slowPrint("\n\n      E 退出游戏\n");
		while(1){
			char c=getch(); 
			if(c=='l'){
				loadFile();
				Play();
			}if(die)break;
			if(c=='c'){
				readFile();
				Play();
			}if(die)break;
			if(c=='n'){
				newFile();
				Play();
			}if(die)break;
			if(c=='v'){
				loadFile();
				viewEndings();
				system("cls");
				goto bgn;
			}if(die)break;
			if(c=='e'){
//				saveFile();
				exit(0);
			}if(die)break;
			if(die)break;
		}
	}
//	enemyColor=RED;
//	yousyaColor=BLUE; 
//	grid.init();
//	player.init();
//	grid.generateMaze();
//	player.setPos(40,40);
//	grid.add(player);
//	for(int i=0;i<64;++i)newEnemy(5);
////	exit(0);
//	while(1){
//		update();
//		if(checkCrash())End(2);
//		updateEnemy();
//		if(checkCrash())End(2);
//		print(grid,player);
//		++standardClock;
//		Sleep(200);
//	}
}
