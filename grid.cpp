#ifndef __grid__cpp_
#define __grid__cpp_
#include "includes.h"
void Grid::init(){
	name="";
	n=80,m=80;
	gridN=n,gridM=m;
	memset(c,0,sizeof(c));
}
void Grid::init(int N,int M){
	n=N,m=M;
	gridN=n,gridM=m;
	memset(c,0,sizeof(c));
}
void Grid::test(){
	for(int t=1;t<=128;++t){
		int tx=rand()%n+1,ty=rand()%m+1;
		if(abs(tx-64)+abs(ty-64)>5)c[tx][ty]=-1;
	}
	for(int t=1;t<=64;++t){
		int tx=rand()%n+1,ty=rand()%m+1;
		if(abs(tx-64)+abs(ty-64)>5 and c[tx][ty]==0)c[tx][ty]=6;
	}
}
void Grid::generateEmpty(){
	for(int i=1;i<=n;++i)c[i][1]=c[i][m]=-1;
	for(int i=1;i<=m;++i)c[1][i]=c[n][i]=-1;
}
void Grid::generate(){
	for(int i=1;i<=n;++i)c[i][1]=c[i][m]=-1;
	for(int i=1;i<=m;++i)c[1][i]=c[n][i]=-1;
	test();
}
void Grid::add(Player&p){
	if(c[p.x][p.y]==6)player.money+=10;
	if(c[p.x+dx[p.dir]][p.y+dy[p.dir]]==6)player.money+=10;
	if(c[p.x][p.y]==11)++countKey;
	if(c[p.x+dx[p.dir]][p.y+dy[p.dir]]==11)++countKey;
	if(c[p.x][p.y]==10 or c[p.x+dx[p.dir]][p.y+dy[p.dir]]==10)touchPalace=1;
	if(c[p.x][p.y]==12 or c[p.x+dx[p.dir]][p.y+dy[p.dir]]==12)p.hp=max(0,p.hp-1);
	c[p.x][p.y]=1;
	if(p.dir%2==0)c[p.x+dx[p.dir]][p.y+dy[p.dir]]=2;
	else c[p.x+dx[p.dir]][p.y+dy[p.dir]]=3;
}
void Grid::remove(Player p){
	c[p.x][p.y]=0;
	c[p.x+dx[p.dir]][p.y+dy[p.dir]]=0;
}
void Grid::genCoin(){
	int cnt=16;
	if(inTut)cnt=3;
	for(int t=1;t<=cnt;++t){
		int tx=rand()%n+1,ty=rand()%m+1;
		if(abs(tx-player.x)+abs(ty-player.y)>5 and c[tx][ty]==0)c[tx][ty]=6;
	}
}
void Grid::genKey(){
	while(1){
		int x=rand()%n+1,y=rand()%m+1;
//		cerr<<"? "<<x<<' '<<y<<'\n';
		if(c[x][y]!=0)continue;
		if(abs(x-64)+abs(y-64)<40)continue;
		int fd=0;
		for(int tx=max(1,x-12);tx<=min(n,x+12);++tx){
			for(int ty=max(1,y-12);ty<=min(m,y+12);++ty){
				if(c[tx][ty]==11){
					fd=1;
					break;
				}
			}
			if(fd)break;
		}
		if(fd)continue;
		c[x][y]=11;
		break;
	}
//	cerr<<"FD!!!\n";system("pause");
}
void Grid::genPalace(){
	while(1){
		int x=rand()%n+1,y=rand()%m+1;
		if(c[x][y]!=0)continue;
		if(abs(x-64)+abs(y-64)<40)continue;
		int fd=0;
		for(int tx=max(1,x-12);tx<=min(n,x+12);++tx){
			for(int ty=max(1,y-12);ty<=min(m,y+12);++ty){
				if(c[tx][ty]==11){
					fd=1;
					break;
				}
			}
			if(fd)break;
		}
		if(fd)continue;
		c[x][y]=10;
		break;
	}
}
bool ablePoint(int x,int y){
	if(x<1 or y<1 or x>grid.n or y>grid.m)return 0;
	if(grid.c[x][y]==-1)return 0;
	if(countKey<4 and grid.c[x][y]==10)return 0;
	return 1;
}
bool able(Player p){
	if(ablePoint(p.x,p.y) and ablePoint(p.x+dx[p.dir],p.y+dy[p.dir]))return 1;
	return 0;
}
bool ablePointEnemy(int x,int y){
	if(x<1 or y<1 or x>grid.n or y>grid.m)return 0;
	if(grid.c[x][y]==0 or grid.c[x][y]==1 or grid.c[x][y]==2 or grid.c[x][y]==3 or grid.c[x][y]==4)return 1;
	return 0;
}
bool able(Enemy p){
	if(ablePointEnemy(p.x,p.y) and ablePointEnemy(p.x+dx[p.dir],p.y+dy[p.dir]))return 1;
	return 0;
}
char trans(int x){
	if(x==-2)return '&';
	if(x==-3)return '@';
	if(x==-1)return '#';
	if(x==0)return ' ';
	if(x==1 or x==7)return 'O';
	if(x==2 or x==8)return '|';
	if(x==3 or x==9)return '-';
	if(x==4)return 'P';
	if(x==5)return '*';
	if(x==6)return '$';
	if(x==10)return 'S';
	if(x==11)return 'K';
	if(x==12)return 'X';
	exit(-1);
}
void eraseEnemy(Enemy enemy){
	grid.c[enemy.x][enemy.y]=0;
	grid.c[enemy.x+dx[enemy.dir]][enemy.y+dy[enemy.dir]]=0;
}
void drawEnemy(Enemy enemy){
	grid.c[enemy.x][enemy.y]=7;
	if(enemy.dir%2==0)grid.c[enemy.x+dx[enemy.dir]][enemy.y+dy[enemy.dir]]=8;
	else grid.c[enemy.x+dx[enemy.dir]][enemy.y+dy[enemy.dir]]=9;
}
void shit(){
	for(int i=1;i<=grid.n;++i){
		for(int j=1;j<=grid.m;++j){
			int c=grid.c[i][j];
			if(c==7 or c==8 or c==9)grid.c[i][j]=0;
		}
	}
	for(int i=0;i<enemies.size();++i){
		Enemy enemy=enemies[i];
		if(enemy.alive==0)continue;
		drawEnemy(enemy);
	}
} 
void print(Grid g,Player p) {
	g.remove(p);
	g.add(p);
    static const string clear_screen = "\033[H"; // ANSI 光标回到左上角
    cout << clear_screen; // 直接将光标移动到屏幕左上角，而不是清空整个屏幕
    int sx = max(1, p.x - 8), sy = max(1, p.y - 10);
    int ex = min(g.n, max(sx+16,p.x + 8)), ey = min(g.m, max(sy+20,p.y + 10));
	sx = max(1, min(sx,ex-16)), sy = max(1, min(sy,ey-20));
	shit();
	if(g.name!="")cout<<g.name<<'\n'; 
    for (int i = sx; i <= ex; ++i) {
        for (int j = sy; j <= ey; ++j) {
        	int c=g.c[i][j];
            if(c==1 or c==2 or c==3) {
                cout << yousyaColor << trans(c) << ORIGINAL; 
			}else if(c==4){
            	cout << GREEN << trans(c) << ORIGINAL; 
			}else if(c==5){
				cout << WHITE << trans(c) << ORIGINAL; 
			}else if(c==6){
				cout << YELLOW << trans(c) << ORIGINAL; 
			}else if(c==7 or c==8 or c==9){
				cout << enemyColor << trans(c) << ORIGINAL; 
			}else if(c==11){
				cout<< CYAN << trans(c) << ORIGINAL;
			}else if(c==10){
				cout<< GREEN << trans(c)<< ORIGINAL;
			}else if(c==12){
				cout<< L_PURPLE << trans(c) <<ORIGINAL;
			}else if(c==-2){
				cout<< RED << trans(c) << ORIGINAL;
			}else if(c==-3){
				cout<< BLUE <<trans(c) << ORIGINAL;
			}else{
                cout << trans(c);
	        }
    	}
        cout << '\n';
    }
    cout<<"你的坐标："<<"("<<player.x<<","<<player.y<<")";
    cout<<"                               \n"; 
    if(player.left){
    	cout<<"信标坐标： "<<"("<<player.leftx<<","<<player.lefty<<")"; 
	}else cout<<"未设置信标";cout<<"                               \n"; 
    cout<<"金币: "<<player.money;cout<<"                               \n"; 
    cout<<"生命："<<player.hp;cout<<"                                \n";
    cout<<"累计击杀："<<countKill<<"                          \n";
    cout.flush(); // 立即刷新缓冲区
}
bool enoughCoin(Grid g){
	int cnt=0;
	for(int i=0;i<512;++i){
		int x=rand()%g.n+1,y=rand()%g.m+1;
		if(g.c[x][y]==6)++cnt;
	}
	return cnt>=maxCoin;
}
struct Dsu{
	int fa[20000];
	void init(){for(int i=0;i<20000;++i)fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);} 
}dsu;
int Grid::getId(int x,int y){
	return (x-1)*m+y;
}
void Grid::generateMaze(int keyNumber){
	memset(c, -1, sizeof(c));
//	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)c[i][j]=1;
	vector<pair<int,int> >edges;edges.clear();
	for(int i=2;i<=n;i+=4){
		for(int j=2;j<=m;j+=4){
			if(i+4<=n)edges.push_back({getId(i,j),getId(i+4,j)});
			if(j+4<=m)edges.push_back({getId(i,j),getId(i,j+4)});
		}
	}
	random_shuffle(edges.begin(),edges.end());
	dsu.init();
	for(auto p:edges){
		int x=p.first,y=p.second;
		int sx=(x-1)/m+1,sy=(x-1)%m+1;
		int ex=(y-1)/m+1,ey=(y-1)%m+1;
		x=dsu.find(x),y=dsu.find(y);
		if(x==y and rand()%8!=0)continue;
//		if(x==y)continue;
		dsu.fa[x]=y;
		for(int i=sx;i<=ex+1;++i)for(int j=sy;j<=ey+1;++j)c[i][j]=0;
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			cout<<c[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	system("pause");
	for(int e=0;e<8;++e){
		int x=rand()%n+1,y=rand()%m+1;
		if(x+8<=n and y+8<=m and x>1 and y>1){
			for(int i=x;i<x+8;++i)for(int j=y;j<y+8;++j)c[i][j]=0;
		}
	}
	for(int i=n/2-3;i<=n/2+4;++i)for(int j=m/2-3;j<=m/2+4;++j)c[i][j]=0;
	for(int i=0;i<keyNumber;++i)genKey();
	genPalace();
}

void Grid::updateObstacle(){
	for(int i=2;i<=n-1;++i){
		for(int j=2;j<=n-1;++j){
			if(c[i][j]==0){
				if(rand()%1280==0)c[i][j]=-1;
			}else if(c[i][j]==-1){
				if(rand()%256==0)c[i][j]=0;
			}
		}
	}
}

void Grid::updateLightening(){
	for(int i=2;i<=n-1;++i){
		for(int j=2;j<=n-1;++j){
			if(abs(i-player.x)+abs(j-player.y)<2)continue;
			if(c[i][j]==0){
				if(rand()%4096==0)c[i][j]=12;
			}else if(c[i][j]==12){
				if(rand()%256==0)c[i][j]=0;
			}
		}
	}
}

#endif
