#ifndef __steps_cpp_
#define __steps_cpp_
#include "includes.h"
void slowPrint(string s){
	for(int i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(20);
	}
}
void slowPrint(string s,string COLOR){
	cout<<COLOR;
	for(int i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(50);
	}
	cout<<ORIGINAL;
}
void slowestPrint(string s,string COLOR){
	cout<<COLOR;
	for(int i=0;i<s.size();++i){
		cout<<s[i];
		Sleep(1000);
	}
	cout<<ORIGINAL;
}
void step0(){
	printTitle();
	Sleep(1000);
	slowPrint("\n\n                       Author:  paulzrm\n");
}
void step1(){
//	if(Stage>=5)return;
	maxCoin=64;
	slowPrint("正在开始游戏\n");
	system("cls");
	clock_t st;
	yousyaColor=BLUE;
	enemyColor=RED;
	inTut=1;
	grid.init(15,15);
	grid.generateEmpty();
	player.setPos(2,8);player.setDir(2); 
	grid.add(player);
	if(Stage!=0)goto EndStage1;
	print(grid,player);
	for(int i=1;i<=5;++i){
		Sleep(1000);
		grid.remove(player);
		player.x++;
		grid.add(player);
		print(grid,player);
	}
	Sleep(2000);
	slowPrint("你：...？\n");
	Sleep(2000);
	slowPrint("这是哪儿...？\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(4000);
	slowPrint("此时，一个声音在你耳边响起：\n");
	Sleep(1000);
	slowPrint("你醒了，");slowPrint("勇者",BLUE),slowPrint("。\n");
	Sleep(2000);
	slowPrint("...\n");
	Sleep(4000);
	slowPrint("你：...");slowPrint("勇者",BLUE),slowPrint("...？\n");
	Sleep(2000);
	slowPrint("那个声音：是的。你是"),slowPrint("勇者",BLUE),slowPrint("被我召唤到了异世界。你需要打败这里的"),slowPrint("魔王",RED),slowPrint("。\n");
	Sleep(2000);
	slowPrint("你：...");slowPrint("魔王",RED),slowPrint("...？\n");
	Sleep(2000);
	slowPrint("那个声音：是的。在那之前，我先来教你在这个世界最基本的战斗方式吧。\n");
	Sleep(2000);
	slowPrint("你可以用 W/A/S/D 向上/下/左/右走。\n");
	Sleep(2000);
	slowPrint("注意到你手上的剑了吗？你可以用键盘的上/下/左/右键去控制它的方向。\n");
	Sleep(2000);
	slowPrint("地图上的#是障碍物，你和你的剑都无法穿过它。\n");
	Sleep(2000);
	slowPrint("地图上还会有"),slowPrint("$",YELLOW),slowPrint("，代表金币，你可以捡起它。一个"),slowPrint("$",YELLOW),slowPrint("价值 10 枚金币。\n");
	Sleep(2000);
	slowPrint("你先来动动吧。\n");
	Sleep(2000);
	slowPrint("任务：收集160枚金币。\n",GREEN); 
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n");
	system("pause");
	system("cls");
	haveCoin=1;
	print(grid,player);
	grid.genCoin();
	while(1){if(die)return; 
		update();
		print(grid,player);
		++standardClock;
		Sleep(100);
		if(player.money>=160)break;
	}
	EndStage1:;
	Stage=max(Stage,1);saveFile();
	if(Stage>=2){if(die)return; 
		clearEnemies(); 
		mov=0;
		for(int i=0;i<6;++i)newEnemy(15);
		grid.genCoin();countKill=0;
		enemyLimit=6;
		goto EndStage2;
	}
	slowPrint("那个声音：好的。现在你已经可以熟练移动了，"),slowPrint("勇者",BLUE),slowPrint("。\n"); 
	Sleep(2000);
	slowPrint("在"),slowPrint("魔王",RED),slowPrint("的领导下，"),slowPrint("魔物",RED),slowPrint("会攻击你。\n");
	slowPrint("魔物",RED),slowPrint("也有武器。如果你的武器碰到了它们的武器或者身体，那么它们就会"),slowPrint("死亡",RED),slowPrint("。\n");
	Sleep(2000); 
	slowPrint("反之，如果"),slowPrint("魔物",RED),slowPrint("的武器或者身体碰到了你的身体，那么你的生命值就会减少。虽然它们也会因此"),slowPrint("死亡",RED),slowPrint("，但这对你而言并不值得，对吧。\n");
	Sleep(2000);
	slowPrint("你的行动永远比"),slowPrint("魔物",RED),slowPrint("提前。\n");
	Sleep(2000); 
	slowPrint("试试和"),slowPrint("魔物",RED),slowPrint("战斗吧。\n");
	Sleep(2000);
	slowPrint("任务：击杀 10 只不移动的魔物。\n",GREEN); 
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n");
	system("pause");
	system("cls");
	clearEnemies();
	Sleep(2000);mov=0;
	for(int i=0;i<6;++i)newEnemy(15);
	print(grid,player);
	grid.genCoin();countKill=0;
	enemyLimit=6;
	while(1){if(die)return; 
		update();
		if(checkCrash())End(0);
		print(grid,player);
		cout<<"当前击杀："<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=10)break;
	}
	Sleep(2000);
	EndStage2:;
	Stage=max(Stage,2);saveFile();
	if(Stage>=3){if(die)return; 
		mov=1;
		clearEnemies();
		for(int i=0;i<6;++i)newEnemy(15);
		grid.genCoin();countKill=0;
		enemyLimit=6;enemySpeed=2;
		goto EndStage3;
	}
	slowPrint("那个声音：好的，现在你已经会攻击了。\n");
	Sleep(2000);
	slowPrint("在真正的世界中，"),slowPrint("魔物",RED),slowPrint("是会移动的。它们有一个视野范围，每只都可能不一样。\n");
	Sleep(2000);slowPrint("魔物",RED),slowPrint("很笨，面朝方向就是它们武器的方向。如果你和某只"),slowPrint("魔物",RED),slowPrint("的距离小于等于它的视野范围，且你处于它面朝方向偏左60度到偏右60度的范围内，那么你就会被它看到。\n");
	Sleep(2000);slowPrint("如果你处于某只"),slowPrint("魔物",RED),slowPrint("的视野范围内，那么它就会径直向你走来。但它很笨，不会绕开障碍物，如果被卡住就不会动了。\n");
	Sleep(2000);slowPrint("没有你视野的"),slowPrint("魔物",RED),slowPrint("会停下或者随机走动。\n");
	Sleep(2000);slowPrint("试试和"),slowPrint("魔物",RED),slowPrint("战斗吧。请小心。\n");
	slowPrint("任务：击杀 10 只移动的魔物。\n",GREEN); 
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n"); 
	system("pause");
	system("cls");
	Sleep(2000);mov=1;
	clearEnemies();
	for(int i=0;i<6;++i)newEnemy(15);
	print(grid,player);
	grid.genCoin();countKill=0;
	enemyLimit=6;enemySpeed=2;
	while(1){if(die)return; 
		update();
		if(checkCrash())End(0);
		updateEnemy();
		if(checkCrash())End(0);
		print(grid,player);
		cout<<"当前击杀："<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=10)break;
	}
	Sleep(2000);
	EndStage3:;
	Stage=max(Stage,3);saveFile();
	if(Stage>=4){if(die)return; 
		clearEnemies(); 
		for(int i=0;i<12;++i)newEnemy(15);
		mov=1;ableC=1;
		player.hp=3;
		grid.genCoin();countKill=0;
		enemyLimit=12;enemySpeed=3;
		goto EndStage4;
	}
	player.money+=100;
	slowPrint("那个声音：好的，现在你已经可以比较熟练的和"),slowPrint("魔物",RED),slowPrint("战斗了\n");
	Sleep(2000);
	slowPrint("作为"),slowPrint("勇者",BLUE),slowPrint("你有一些技能。\n");
	slowPrint("你的面朝方向为你的剑的方向。按下 c 可以在你的身后放下一个人造障碍物。你能够通过它（通过时会清除），而"),slowPrint("魔物",RED),slowPrint("会被阻挡 。\n");
	Sleep(2000);
	slowPrint("放置一个障碍物需要花费 3 枚金币。\n");
	Sleep(2000);
	slowPrint("请试试这个技能吧。\n");
	Sleep(2000);
	slowPrint("任务：存活一分钟。\n",GREEN);
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n"); 
	system("pause");
	system("cls");
	clearEnemies(); 
	for(int i=0;i<12;++i)newEnemy(15);
	print(grid,player);mov=1;ableC=1;
	player.hp=3;
	grid.genCoin();countKill=0;
	enemyLimit=12;enemySpeed=3;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<12)newEnemy(15);
		update();
		if(checkCrash())End(1);
		updateEnemy();
		if(checkCrash())End(1);
		print(grid,player);
		int rem=60-(clock()-st)/CLOCKS_PER_SEC;
		cout<<"还剩："<<rem<<" 秒   \n";
		if(rem<=0)break;
		++standardClock;
		Sleep(250);
	}
	Sleep(2000);
	EndStage4:;Stage=max(Stage,4);
	saveFile();
	if(Stage>=5){if(die)return; 
		ableF=1;mov=1;countKill=0;
		goto EndStage5;
	}
	slowPrint("那个声音：你还有一个技能。在没有设置信标时，你按下 f 可以设置一个信标。\n");
	Sleep(2000); 
	slowPrint("在有信标时按下 f 会立刻传送到信标的位置并回收它。\n");
	Sleep(2000);
	slowPrint("设置信标或者传送均需要花费 5 枚金币。\n");
	Sleep(2000);
	slowPrint("请试试这个技能吧。\n");
	Sleep(2000);
	slowPrint("任务：击杀3个敌人。此时若你和敌人的武器碰到一起，则你也会损失生命\n",GREEN);
	Sleep(2000);
	slowPrint("准备好了就按任意键开始。\n"); 
	system("pause");
	system("cls");
	clearEnemies();
	grid.init(3,30);
	grid.generateEmpty();
	player.setPos(2,12);player.setDir(1);
	grid.add(player);
	ableF=1;mov=1;
	newSpecialEnemy(2,18,3);
	newSpecialEnemy(2,20,3);
	newSpecialEnemy(2,22,3);
	print(grid,player);
	specialRule=1;countKill=0;
	enemyLimit=3;enemySpeed=3;
	while(1){if(die)return; 
		update();
		if(checkCrash())End(1);
		updateEnemy();
		if(checkCrash())End(1);
		print(grid,player);
		cout<<"当前击杀："<<countKill<<"    \n";
		++standardClock;
		Sleep(100);
		if(countKill>=3)break;
		if(enemies.size()==0)End(1);
	}
	slowPrint("那个声音：好的，你现在已经比较熟悉这个世界了。去战斗吧！\n");
	slowPrint("教程      完\n");
	EndStage5:;Stage=max(Stage,5);
	specialRule=0;
	clearEnemies();
	saveFile();
	maxCoin=12;
	saveFile(); 
	system("pause");
	return;
}
void prePlot(){
	if(Stage>=6)return;
	system("cls");
    slowPrint("███ 艾瑞斯 ████████████勇者██████魔王█████████████████████\n");
    Sleep(2000);
    slowPrint("那个声音：欢迎来到艾瑞斯世界，");slowPrint("勇者",BLUE);slowPrint("。这里是神魔博弈的棋盘，也是你命中注定的战场。\n");
    Sleep(2000);
    slowPrint("你：棋盘...？那这些红色的是...？\n");
    Sleep(1500);
    slowPrint("那个声音：正如所见，那些都是");slowPrint("魔王",RED);slowPrint("卡洛梅的爪牙。它们蚕食着四大古陆，而你要做的——\n");
    Sleep(1800);
    slowPrint("你：（打断）四大古陆？\n");
    Sleep(1000);
    
    slowPrint("那个声音：（幻象中浮现四块发光大陆）\n");
    slowPrint("▄▄▄ 赤烬之地 - 燃烧着永恒业火的战场\n");
    slowPrint("封印着「炎核」，由炎之巨人守护的熔岩之心\n\n");
    Sleep(1500);
    slowPrint("▄▄▄ 霜骸冰原 - 时间凝结的极寒坟场\n");
    slowPrint("冰封着「霜心」，被冰霜女巫诅咒的凛冬核心\n\n");
    Sleep(1500);
    slowPrint("▄▄▄ 雷鸣裂谷 - 雷暴永不停息的深渊\n");
    slowPrint("禁锢着「雷纹臂铠」，由风暴领主把持的雷霆武装\n\n");
    Sleep(1500);
    slowPrint("▄▄▄ 影渊圣所 - 光无法抵达的禁忌领域\n");
    slowPrint("沉睡着「虚空之冠」，被暗影贤者守护的终焉王冕\n");
    Sleep(2000);

    slowPrint("你：这些圣器...能彻底消灭");slowPrint("魔王",RED);slowPrint("？\n");
    Sleep(1200);
    slowPrint("那个声音：（发出意味深长的笑声）当然，当四圣器齐聚之时——\n");
    Sleep(1000);
    slowPrint("（幻象突然扭曲，浮现出倒悬的王座）\n");
    slowPrint("那将是新纪元的开端。\n");
    Sleep(1800);

    slowPrint("你注意到幻象中");slowPrint("魔物",RED);slowPrint("身上的纹章了吗？\n");
    slowPrint("那是卡洛梅的烙印，它们会像嗅到血腥的鲨鱼般追踪你。\n");
    Sleep(1500);
    slowPrint("但记住，真正的威胁往往戴着伪善的面具...\n");
    Sleep(2000);
    slowPrint("（幻象突然消失）\n");
    slowPrint("那个声音：是时候了，");slowPrint("勇者",BLUE);slowPrint("。\n");
    
    slowPrint("███ 当前目标 ██ 存活 → 收集 → 抉择 █████████████████████\n");
    Sleep(1500);
    slowPrint("准备好了吗？马上该前往第一个大陆「赤烬之地」了。\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y 我已经准备好了！\n");
    slowPrint("\n\n      N 我还没有准备好...\n");
	while(1){if(die)return; 
    	if(GetAsyncKeyState(VK_Y)){
			Stage=6;
			saveFile(); 
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("那你再想想吧，好了再走\n");
			Sleep(5000);
			slowPrint("准备好了吗？\n"); 
		}
	}
	Stage=6;
	saveFile(); 
	return;
}
void step2(){
	system("cls");
	if(Stage>=7)return;
	maxCoin=6;countKey=0;enemyEyesight=5;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("▄▄▄ 赤烬之地 - 燃烧着永恒业火的战场\n");
		slowPrint("封印着「炎核」，由炎之巨人守护的熔岩之心\n\n");
	    Sleep(1500);
	    slowPrint("「炎核」位于赤烬圣殿，地图上用 S 标记。进入圣殿需要集齐 4 把钥匙，用 K 标记，分布在地图中。你需要集齐它们才能进入圣殿。\n");
		Sleep(1500); 
		slowPrint("这里遍地火焰，导致障碍和金币都较少。");slowPrint("这里的"),slowPrint("魔物"),slowPrint("是炎之巨人，速度较慢，反应也比较迟钝。\n");
		slowPrint("勇者",BLUE),slowPrint("阁下选择这里作为第一个征服点，是很明智的决定。\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("我们到了。");slowPrint("勇者",BLUE),slowPrint("阁下，请小心迎敌。\n");
		system("pause");
		system("cls");		
		saveFile(); 
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(40,40);
	grid.name="「赤烬之地」";
	grid.generate();
	grid.add(player);
	for(int i=0;i<4;++i)grid.genKey();attackWaitTime=2;
	grid.genPalace();enemyLimit=72;enemyEyesight=5;
	for(int i=0;i<64;++i)newEnemy(enemyEyesight);
	print(grid,player);touchPalace=0;countKey=0;
	while(1){
		if(die)return; 
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		cout<<"当前找到的钥匙数量： "<<countKey<<'\n';
		if(countKey==4 and touchPalace==1)break;
		++standardClock;
		Sleep(100);
	}Stage=7;
	skipPlot=0;
	saveFile(); 
}
void step3(){
	system("cls");
	if(Stage>=8)return;enemyEyesight=5;
	if(!skipPlot){
		skipPlot=1;
		slowPrint("（钥匙插入青铜巨门的瞬间，地动山摇）\n");
		slowPrint("你脚下的岩浆突然沸腾，穹顶落下燃烧的巨石！\n"); 
		for(int i=0;i<3;i++) slowPrint("■",RED),Sleep(500);
		slowPrint("\n那个声音：快进去！祂要苏醒了——\n");
		for(int i=0;i<5;++i)slowPrint("."),Sleep(1000);
		slowPrint("你进入了神殿。突然耳边传来一声巨响，青铜巨门合上了。\n");
		slowPrint("还未等你适应眼前的黑暗，神殿中央突然亮起了一座火炬。待你看清四周时，才发现你已被炎之巨人所包围。\n");
		Sleep(1000);
		slowPrint("那个声音：这是你的试炼，"),slowPrint("勇者",BLUE),slowPrint("！你需要坚持90秒，就能获得「炎核」！\n");
		slowPrint("你环顾四周，并没有发现任何退路。而且这里貌似也没法放置障碍物。\n");
		slowPrint("这里还在喷发着岩浆。如果你在一个位置停留超过 6 秒，那么就会受到伤害。\n");
		slowPrint("没办法，只能上了！\n");
		Sleep(1000);
		system("pause");
		system("cls");
	}
	clearEnemies();cantStop=1;
	grid.init(16,16);ableC=0;
	player.init();
	player.setPos(8,8);
	grid.name="「赤烬之地」——圣殿";
	grid.generateEmpty();
	grid.add(player);enemyLimit=12;attackWaitTime=2;
	for(int i=0;i<12;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<6)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		int rem=90-(clock()-st)/CLOCKS_PER_SEC;
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"还剩："<<rem<<" 秒   \n";
		cout<<"再停留 "<<stay<<" 秒就会受到伤害\n";
		if(stay==0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(2);
		}
		if(rem<=0)break;
		++standardClock;
		Sleep(100);
	}
	Stage=8;ableC=1;
	skipPlot=0;
	saveFile();
	slowPrint("终于，你坚持下来了。\n");
	slowPrint("■■■■■■ 炎核共鸣 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	slowPrint("（所有炎巨人突然僵直，化作岩浆流入祭坛）\n"); 
	for(int i=0;i<3;i++) slowPrint("★",RED),Sleep(500);
	slowPrint("\n「炎核」缓缓降落到你掌心，灼痛中传来诡异的温暖\n");
	slowPrint("（炎核表面突然映出你的倒影，");
	slowPrint("双眼泛着红光",RED);slowPrint("）\n");
	slowPrint("低语声：做得很好...第213号■■者...\n",DARKGRAY); 
	Sleep(1500);
	slowPrint("???\n");
	Sleep(1500);
	slowPrint("没等你反应过来，那个声音又出现了。\n");
	slowPrint("那个声音：现在该前往「霜骸冰原」了\n");
	slowPrint("▄▄▄ 霜骸冰原 - 时间静止的极寒坟场\n");
	slowPrint("封印着能够冻结灵魂的「霜心」，由冰霜女巫守护\n\n"); 
    slowPrint("准备好了吗？马上该前往第二个大陆「霜骸冰原」了。\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y 我已经准备好了！\n");
    slowPrint("\n\n      N 我还没有准备好...\n");
	while(1){if(die)return; 
    	if(GetAsyncKeyState(VK_Y)){
			Stage=8;
			saveFile(); 
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("那你再想想吧，好了再走\n");
			Sleep(5000);
			slowPrint("准备好了吗？\n"); 
		}
	}
}
void step4(){
	system("cls");
	if(Stage>=9)return;
	maxCoin=6;countKey=0;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("▄▄▄ 霜骸冰原 - 时间静止的极寒坟场\n");
		slowPrint("封印着「霜心」，由冰霜女巫守护的冰霜之心\n\n");
	    Sleep(1500);
	    slowPrint("「霜心」位于霜骸圣殿，地图上用 S 标记。进入圣殿需要集齐 6 把钥匙，用 K 标记，分布在地图中。你需要集齐它们才能进入圣殿。\n");
		Sleep(1500); 
		slowPrint("这里遍地冰柱，障碍物组成了类似迷宫的地图。");slowPrint("这里的"),slowPrint("魔物"),slowPrint("是冰霜女巫，视野较广但数量较少。\n");
		slowPrint("勇者",BLUE),slowPrint("阁下，请利用好地形吧。\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("我们到了。");slowPrint("勇者",BLUE),slowPrint("阁下，请小心迎敌。\n");
		system("pause");
		system("cls");		
		saveFile(); 
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(40,40);
	grid.name="「霜骸冰原」";
	grid.init();
	player.init();
	grid.generateMaze(6);
	player.setPos(40,40);enemyLimit=48;
	grid.add(player);enemyEyesight=12;attackWaitTime=2;
	for(int i=0;i<32;++i)newEnemy(enemyEyesight);
	for(int i=0;i<4;++i)grid.genCoin();
	while(1){
		if(die)return; 
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		cout<<"当前找到的钥匙数量： "<<countKey<<'\n';
		if(countKey==6 and touchPalace==1)break;
		++standardClock;
		Sleep(100);
	}Stage=9;
	skipPlot=0;
	saveFile(); 
}
void step5(){
    system("cls");
    if(Stage>=10)return;enemyEyesight=12;
    if(!skipPlot){
        skipPlot=1;
        slowPrint("（钥匙插入冰晶巨门的瞬间，刺骨的寒风呼啸而至）\n");
        slowPrint("你脚下的冰面突然崩裂，穹顶坠下锋利的冰锥！\n"); 
        for(int i=0;i<3;i++) slowPrint("▲",CYAN),Sleep(500);
        slowPrint("\n那个声音颤抖着：快进去！祂的凝视要冻结一切——\n");
        for(int i=0;i<5;++i)slowPrint("."),Sleep(1000);
        slowPrint("\n你踏入圣殿的刹那，身后的冰门轰然闭合。\n");
        slowPrint("苍蓝色的冰晶在墙壁上蔓延生长，折射出诡异的幽光。冰雾中浮现出数十个手持冰杖的苍白身影。\n");
        Sleep(1000);
        slowPrint("那个声音带着回响：这是寒冰的试炼，"),slowPrint("勇者",BLUE),slowPrint("！在极寒中存活90秒，就能获得「霜心」！\n");
        slowPrint("你发现地面覆盖着薄脆的冰层，任何人造障碍物都会被立即冻裂。\n");
        slowPrint("极寒的加持下，圣殿中随时可能出现一些天然障碍物。它们也会突然消失。\n");
        slowPrint("刺骨的严寒正在侵蚀你。如果在同一位置停留超过6秒，冰霜就会爬上你的四肢。\n");
        slowPrint("没有退路，唯有前行！\n");
        Sleep(1000);
        system("pause");
        system("cls");
    }
	clearEnemies();cantStop=1;
	grid.init(16,16);ableC=0;
	player.init();
	player.setPos(8,8);
	grid.name="「霜骸冰原」——圣殿";
	grid.generateEmpty();
	grid.add(player);enemyLimit=12;attackWaitTime=2;
	for(int i=0;i<12;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<6)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		grid.updateObstacle();
		int rem=90-(clock()-st)/CLOCKS_PER_SEC;
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"还剩："<<rem<<" 秒   \n";
		cout<<"再停留 "<<stay<<" 秒就会受到伤害\n";
		if(stay==0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(2);
		}
		if(rem<=0)break;
		++standardClock;
		Sleep(100);
	}
    Stage=10;ableC=1;
    skipPlot=0;
    saveFile();
    slowPrint("终于，刺骨的寒风停息了。\n");
    slowPrint("■■■■■■ 霜心共鸣 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("（所有冰霜女巫突然碎裂，化作冰尘飘向祭坛）\n"); 
    for(int i=0;i<3;i++) slowPrint("?",CYAN),Sleep(500);
    slowPrint("\n「霜心」缓缓落入你的掌心，寒意中透出令人不安的脉动\n");
    slowPrint("（霜心内部浮现你的倒影，");
    slowPrint("发梢结满冰晶",CYAN);slowPrint("）\n");
    slowPrint("耳语声：合格了...第213号■■者...\n",DARKGRAY); 
    Sleep(1500);
    slowPrint("???\n");
    Sleep(1500);
    slowPrint("那个声音强行打断了你的思绪。\n");
    slowPrint("那个声音：接下来是「雷鸣裂谷」——风暴领主的领域\n");
    slowPrint("▄▄▄ 雷鸣裂谷 - 永不停歇的雷暴深渊\n");
    slowPrint("沉睡着能操控雷霆的「雷纹臂铠」，小心它的狂怒\n\n"); 
    slowPrint("准备好了吗？即将前往最终试炼之地「雷鸣裂谷」。\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y 我已经准备好了！\n");
    slowPrint("\n\n      N 我还没有准备好...\n");
	while(1){if(die)return; 
    	if(GetAsyncKeyState(VK_Y)){
			Stage=10;
			saveFile(); 
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("那你再想想吧，好了再走\n");
			Sleep(5000);
			slowPrint("准备好了吗？\n"); 
		}
	}
}
void step6(){
	system("cls");
	if(Stage>=11)return;
	maxCoin=10;countKey=0;
	if(!skipPlot){
		skipPlot=1;
	    slowPrint("▄▄▄ 雷鸣裂谷 - 永不停歇的雷暴深渊\n");
		slowPrint("封印着「雷纹臂铠」，由闪电之灵守护的雷暴圣甲\n\n");
	    Sleep(1500);
	    slowPrint("「雷纹臂铠」位于雷鸣圣殿，地图上用 S 标记。进入圣殿需要集齐 8 把钥匙，用 K 标记，分布在地图中。你需要集齐它们才能进入圣殿。\n");
		Sleep(1500); 
		slowPrint("这里的"),slowPrint("魔物"),slowPrint("是闪电之灵，攻击和反应极快但视野较窄。\n");
		slowPrint("勇者",BLUE),slowPrint("阁下，请利用好地形吧。\n");
		for(int i=0;i<10;++i)slowPrint("."),Sleep(1000);
		slowPrint("我们到了。");slowPrint("勇者",BLUE),slowPrint("阁下，请小心迎敌。\n");
		system("pause");
		system("cls");
		saveFile(); 
	}
	clearEnemies();
	grid.init();
	player.init();
	player.setPos(40,40);
	grid.name="「雷鸣裂谷」";
	grid.init();
	player.init();
	grid.generateMaze(8);
	player.setPos(40,40);enemyLimit=54;
	grid.add(player);enemyEyesight=3;
	for(int i=0;i<36;++i)newEnemy(enemyEyesight);
	for(int i=0;i<4;++i)grid.genCoin();
	enemyStopTime=1;attackWaitTime=0; 
	while(1){
		if(die)return; 
		update();
//		cout<<"END update player\n";
//		system("pause");
		if(checkCrash())End(2);
//		cerr<<"END check crash\n";
//		system("pause");
		updateEnemy();
//		cerr<<"END update enemy\n";
//		system("pause");
		if(checkCrash())End(2);
//		cerr<<"END check crash\n";
//		system("pause");
		print(grid,player);
		cout<<"当前找到的钥匙数量： "<<countKey<<'\n';
		if(countKey==8 and touchPalace==1)break;
		++standardClock;
		Sleep(100);
//		system("pause");
//		system("cls");
	}Stage=11;
	skipPlot=0;
	saveFile(); 
}
void step7(){
    system("cls");
    if(Stage>=12)return;enemyEyesight=3;enemyStopTime=1;attackWaitTime=0; 
    if(!skipPlot){
      	 skipPlot=1;
        slowPrint("（钥匙插入雷霆巨门的瞬间，刺眼的雷光划破天际）\n");
        slowPrint("你脚下的地面开始震颤，穹顶降下狂暴的闪电！\n"); 
        for(int i=0;i<3;i++) slowPrint("!",YELLOW),Sleep(500);
        slowPrint("\n那个声音急促地喊道：快进去！风暴领主已经察觉到了你的存在！\n");
        for(int i=0;i<5;++i)slowPrint("."),Sleep(1000);
        slowPrint("\n你冲入圣殿的刹那，身后的巨门被雷霆劈碎。\n");
        slowPrint("空气中弥漫着臭氧的气味，四周的雷云中浮现出数个手持雷枪的闪电之灵。\n");
        Sleep(1000);
        slowPrint("那个声音带着电流般的回响：这是雷霆的试炼，"),slowPrint("勇者",BLUE),slowPrint("！在雷暴中存活90秒，就能获得「雷纹臂铠」！\n");
        slowPrint("你发现地面布满了导电的金属纹路，任何障碍物都会被雷击粉碎。\n");
        slowPrint("雷暴可能生成在圣殿的任意位置，用 x 表示，碰到就会损失生命值。但你身上的装备可以保证不会在距离你2格以内生成。\n");
        slowPrint("狂暴的电流正在干扰你的行动。如果在同一位置停留超过6秒，就会被雷电锁定。\n");
        slowPrint("唯有直面风暴，才能通过试炼！\n");
        Sleep(1000);
        system("pause");
        system("cls");
    }
	clearEnemies();cantStop=1;
	grid.init(16,16);ableC=0;
	player.init();
	player.setPos(8,8);
	grid.name="「雷鸣裂谷」——圣殿";
	grid.generateEmpty();enemyLimit=9;
	grid.add(player);enemyEyesight=3;enemyStopTime=1;attackWaitTime=0; 
	for(int i=0;i<6;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<4)newEnemy(enemyEyesight);
		grid.updateLightening();
		update();
		if(player.hp==0)End(2); 
		if(checkCrash())End(2);
		updateEnemy();
		if(checkCrash())End(2);
		print(grid,player);
		int rem=90-(clock()-st)/CLOCKS_PER_SEC;
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"还剩："<<rem<<" 秒   \n";
		cout<<"再停留 "<<stay<<" 秒就会受到伤害\n";
		if(stay<=0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(2);
		}
		if(rem<=0)break;
		++standardClock;
		Sleep(100);
	}
	Stage=12;ableC=1;
    skipPlot=0;
    saveFile();
    slowPrint("终于，狂暴的雷云消散了。\n");
    slowPrint("■■■■■■ 雷纹共鸣 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("（所有闪电之灵突然崩解，化作电流汇入祭坛）\n"); 
    for(int i=0;i<3;i++) slowPrint("?",YELLOW),Sleep(500);
    slowPrint("\n「雷纹臂铠」缓缓附着在你的手臂上，电流中传来令人战栗的力量\n");
    slowPrint("（臂铠表面映出你的倒影，");
    slowPrint("眼中闪过雷光",YELLOW);slowPrint("）\n");
    slowPrint("轰鸣声：完成了...第213号■■者...\n",DARKGRAY); 
    Sleep(1500);
    slowPrint("???\n");
    Sleep(1500);
    slowPrint("那个声音再次响起，但语气中多了一丝异样。\n");
    slowPrint("那个声音：恭喜你通过了全部试炼！\n");
    slowPrint("接下来是最后一站——「影渊圣所」。\n");
    slowPrint("▄▄▄ 影渊圣所 - 光无法抵达的禁忌领域\n");
    slowPrint("那里沉睡着最后的圣器，等待着你的到来。\n\n"); 
    slowPrint("准备好了吗？即将前往最终之地「影渊圣所」。\n",GREEN);
    Sleep(1500);
    slowPrint("\n\n      Y 我已经准备好了！\n");
    slowPrint("\n\n      N 我还没有准备好...\n");
	while(1){if(die)return; 
    	if(GetAsyncKeyState(VK_Y)){
			Stage=12;
			saveFile(); 
			return;
		}
		if(GetAsyncKeyState(VK_N)){
			slowPrint("那你再想想吧，好了再走\n");
			Sleep(5000);
			slowPrint("准备好了吗？\n"); 
		}
	}
}
void step8() {
	if(Stage>=13)return;
    system("cls");
    slowPrint("■■■■■■ 影渊圣所 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("（踏入圣所的瞬间，你发现所有「圣器」开始共鸣，投射出刺眼的白光）\n");
    slowPrint("那个声音：终于...等到这一刻了...\n", DARKGRAY);
    Sleep(1500);

    // 真相揭示阶段
    slowPrint("白光中浮现出无数战斗回放，那些被你斩杀的「魔物」",RED);
    slowPrint("褪去红色外壳，露出人类的真实样貌！\n");
    for(int i=0;i<3;i++) slowPrint("?",YELLOW),Sleep(500); // 用菱形符号表示数据碎片
    slowPrint("\n机械声：认知过滤器已解除，候选者213号。\n",DARKGRAY);
    Sleep(1000);

    slowPrint("你：那些...都是人类？！\n");
    slowPrint("X-0系统：准确地说，是其他候选者。\n");
    slowPrint("魔王必须从人类中诞生，因为只有人类的恶才能驾驭魔物的力量。\n"); 
    slowPrint("那些红色外壳是认知过滤器——让你以为自己在斩杀魔物。\n",DARKGRAY);
    Sleep(1500);
    
    slowestPrint("喜欢这个游戏吗？\n",L_RED); 
    Sleep(3000);

    slowPrint("（武器突然扭曲变形，显露出真实形态——一柄刻满人类面孔的权杖）\n");
    slowPrint("X-0系统：看看你的「战绩」：");
    slowPrint(to_string(countKill).c_str(), countKill>50?RED:YELLOW);
    slowPrint("次有效击杀\n");
    slowPrint("这些恶意正是魔王之力的来源。\n",DARKGRAY);
    Sleep(2000);

    // 走廊场景生成
    yousyaColor=WHITE;
    grid.init(5,15);
    grid.generateEmpty();
    player.setPos(3,8);
    grid.name="「终焉回廊」";
    for(int y=1;y<=5;y++){
        grid.set(y,1,-2);    // 左侧红色区域（地面有血迹）
        grid.set(y,2,-2);
        grid.set(y,15,-3);   // 右侧蓝色区域（地面有裂痕）
        grid.set(y,14,-3);
    }

    // 环境细节
    slowPrint("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("左侧的红色大门布满弹孔和血迹，门楣刻着「救赎即谎言」。\n");
    slowPrint("右侧的蓝色王座缠绕荆棘与冠冕，基座刻着「力量即真理」。\n"); 
    slowPrint("白色走廊的地面上延伸着两道血迹，分别通往两个方向。\n");

    // 选择引导
    slowPrint("■■■■■■ 人类最后的选择 ■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("[红色大门]",RED);slowPrint(" 尝试回归人类社会\n");
    slowPrint(" - 若你相信人性之善能超越罪恶\n");
    slowPrint(" - 但需要面对自己亲手制造的",RED);slowPrint(to_string(countKill));slowPrint("场屠杀\n");
    slowPrint("[蓝色王座]",BLUE);slowPrint(" 接受魔王加冕\n");
    slowPrint(" - 若你认同恶意才是人类本质\n");
    slowPrint(" - 将获得统御",RED);slowPrint("人类",DARKGRAY);slowPrint("与",BLUE);slowPrint("魔物",DARKGRAY);slowPrint("的双重权柄\n");
    slowPrint("\n移动决定命运：A/←走向救赎  D/→选择权力\n",WHITE);

    // 动态道德提示
    if(countKill > 250){
        slowPrint("（权杖上的人脸正在狞笑，恶意浓度已达"); 
        slowPrint("97%",RED);slowPrint("）\n");
        slowPrint("X-0系统：你已是历代最优秀的候选者。\n",GREEN);
    }else if(countKill < 40){
        slowPrint("（权杖上的人脸闭目流泪，恶意浓度仅"); 
        slowPrint("12%",CYAN);slowPrint("）\n");
        slowPrint("X-0系统：天真的仁慈会害死你。\n",DARKGRAY);
    }
    Sleep(5000);
    system("pause");
    system("cls");
    // 等待输入
    print(grid,player);skipPlot=0;
    while(true){
        update();
        print(grid,player);
        if(player.y <= 2){ // 红色救赎
            slowPrint("（寒风从门缝渗入，带来故乡的气息）                        \n",CYAN);
            slowPrint("确定要赌上人性最后的善？[Y/N]                      \n");
            if(GetAsyncKeyState('Y')){
                slowPrint("警告：若人类拒绝接受，你将当场被处决                \n",RED);
                slowPrint("确定要赌上人性最后的善？[Y/N]                      \n");
                if(GetAsyncKeyState('Y')){
	                Stage=14;
	                return;	
				}
				system("cls");
            }
        }
        else if(player.y >= 14){ // 蓝色权柄
            slowPrint("（王座伸出锁链缠绕你的手腕）                      \n",DARKGRAY); 
            slowPrint("确定要成为第108代魔王？[Y/N]                               \n");
            if(GetAsyncKeyState('Y')){
                slowPrint("认证通过，开始载入统治模块...\n",BLUE);
                Stage=13;
                return;
            }
        }
        Sleep(1000);
    }
}
void step9() {
	yousyaColor=BLUE;
	enemyColor=RED;
    system("cls");
    slowPrint("■■■■■■ 魔王加冕 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("（你踏上蓝色王座的瞬间，锁链从地面升起，缠绕你的四肢）\n");
    slowPrint("X-0系统：开始进行魔王权柄认证...\n", DARKGRAY);
    Sleep(1500);

    // 加冕仪式
    slowPrint("（王座释放出刺眼的蓝光，你的身体开始发生变化）\n");
    slowPrint("X-0系统：检测到恶意浓度：");
    slowPrint(to_string(countKill).c_str(), countKill > 50 ? RED : YELLOW);
    slowPrint("，符合魔王标准。\n");
    Sleep(1000);

    slowPrint("（你的武器彻底变形，化作一柄缠绕黑色火焰的权杖）\n");
    slowPrint("X-0系统：欢迎，第108代魔王。\n", BLUE);
    Sleep(1500);

    // 人类围剿的警告
    slowPrint("（突然，王座周围的屏幕闪烁，显示出一支庞大的军队）\n");
    slowPrint("X-0系统：警告！检测到人类联军正在集结。\n", RED);
    Sleep(1000);

    slowPrint("（画面中，人类军队高举旗帜，旗帜上写着「讨伐魔王」）\n");
    slowPrint("X-0系统：人类已得知你的加冕，他们不会容忍魔王的存在。\n");
    slowPrint("X-0系统：由于上一任魔王已经过世很久，魔界百废待兴，联军很轻松的便攻入了大殿。\n");
    slowPrint("还请"),slowPrint("魔王",BLUE),slowPrint("您亲自上阵，击败来自这三大古陆的联军。\n");
    Sleep(1500);

    // 最终决战提示
    slowPrint("■■■■■■ 最终决战 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("人类联军已抵达影渊圣所外围，战斗即将开始。\n");
    slowPrint("你的目标是击溃人类联军，巩固魔王权柄。\n", RED);
    Sleep(1000);

	slowPrint("魔王",BLUE),slowPrint("阁下，靠您了。\n");
	Sleep(1000); 
	system("pause");
	
	system("cls");
	clearEnemies();cantStop=1;
	grid.init(31,31);ableC=1;ableF=1;
	player.init();
	player.setPos(16,16);
	grid.name="影渊圣所";
	grid.generateEmpty();enemyLimit=18;
	grid.add(player);enemyEyesight=8;enemyStopTime=2;attackWaitTime=2;
	generateLimit=100;
	for(int i=0;i<9;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<6 and generateLimit>0)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(3);
		updateEnemy();
		if(checkCrash())End(3);
		print(grid,player);
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"再停留 "<<stay<<" 秒就会受到伤害\n";
		cout<<"还剩 "<<generateLimit<< "名敌人即将加入战场\n";
		if(stay<=0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(3);
		}
		if(generateLimit+enemies.size()<=0)break;
		++standardClock;
		Sleep(100);
	}
	system("cls");system("cls");
	slowPrint("一切都结束了。\n");
	End(4); 
}
void step10(){
    yousyaColor=RED;  // 玩家颜色变为红色（原人类方颜色）
    enemyColor=BLUE;  // 魔物颜色变为蓝色
    int originalKills = countKill; // 保存原始击杀数

    system("cls");
    slowPrint("■■■■■■ 逃亡之路 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("（你转身冲向红色大门的瞬间，警报声骤然响起）\n");
    slowPrint("X-0系统：检测到叛逃行为！启动清除协议！\n", DARKGRAY);
    Sleep(1500);

    // 逃亡过程
    slowPrint("（背后的圣殿开始崩塌，蓝色能量体从地底涌出）\n");
    slowPrint("X-0系统：检测到恶意残留量：");
    slowPrint(to_string(originalKills).c_str(), originalKills > 50 ? RED : YELLOW);
    slowPrint("，清除优先级：最高级\n");
    Sleep(1000);

    slowPrint("（你的武器突然闪烁红光，变回最初的铁剑形态）\n");
    slowPrint("X-0系统：叛逃者213号，系统将立刻启动清除程序。\n", BLUE);
    Sleep(1500);

    // 魔物追杀警告
    slowPrint("（监控屏幕显示无数蓝色魔物正在集结）\n");
    slowPrint("X-0系统：已释放",BLUE);slowPrint("追猎型魔物",DARKGRAY);slowPrint("12体\n");
    slowPrint("它们对恶意残留有极高敏感度，正在向你逼近！\n", RED);
    Sleep(1000);

    // 最终逃亡提示
    slowPrint("■■■■■■ 生死竞速 ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    slowPrint("你必须坚持到人类援军抵达，或清除所有追击者！\n");
    Sleep(1000);

    slowPrint("那个声音：快跑！它们来了！\n");
    Sleep(1000); 
    system("pause");
    
    // 战斗初始化
    system("cls");
    clearEnemies();
    cantStop=1;
    grid.init(31,31);
    ableC=1;  // 允许放置障碍
    ableF=1;  // 允许传送
    player.init();
    player.setPos(16,16);
    grid.name="荒原逃亡";
	grid.generateEmpty();enemyLimit=18;
	grid.add(player);enemyEyesight=8;enemyStopTime=2;attackWaitTime=2;
	generateLimit=100;
	for(int i=0;i<9;++i)newEnemy(enemyEyesight);
	print(grid,player);lastMove=clock();
	clock_t st;
	st=clock();
	while(1){if(die)return; 
		while(enemies.size()<6 and generateLimit>0)newEnemy(enemyEyesight);
		update();
		if(checkCrash())End(5);
		updateEnemy();
		if(checkCrash())End(5);
		print(grid,player);
		int stay=6-(clock()-lastMove)/CLOCKS_PER_SEC;
		cout<<"再停留 "<<stay<<" 秒就会受到伤害\n";
		cout<<"还剩 "<<generateLimit<< "名敌人即将加入战场\n";
		if(stay<=0){
			--player.hp;
			lastMove=clock();
			if(player.hp==0)End(3);
		}
		if(generateLimit+enemies.size()<=0)break;
		++standardClock;
		Sleep(100);
	}

    system("cls");
    slowPrint(originalKills <= 50 ? "援军及时赶到了！\n" : "你勉强逃出生天...\n");
    End(originalKills <= 50 ? 7 : 6); // 根据原始击杀数选择结局
}
void Play(){
	generateLimit=-1;
	int prevKill=countKill;
	step1();if(die==1)return;
	countKill=prevKill;touchPalace=0;
	prePlot();if(die==1)return;touchPalace=0;
	step2();if(die==1)return;touchPalace=0;
	step3();if(die==1)return;touchPalace=0;
	step4();if(die==1)return;touchPalace=0;
	step5();if(die==1)return;touchPalace=0;
	step6();if(die==1)return;touchPalace=0;
	step7();if(die==1)return;touchPalace=0;
	step8();saveFile();if(die==1)return;touchPalace=0;
	if(Stage==13)step9();
	else step10();
}
#endif
