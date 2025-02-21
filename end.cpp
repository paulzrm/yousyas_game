#ifndef __end_cpp_
#define __end_cpp_
#include "includes.h"
void End(int endId){
//	print(grid,player);
	die=1;
	if(endId==0){
		slowPrint("那个声音：怎么，你连打木偶都能被木偶反杀？我真的找了个"),slowPrint("勇者",BLUE),slowPrint("吗？\n");
		Sleep(2000); 
		slowPrint("达成结局0：找错人了\n");
		haveEnd[0]=1;
		saveFile();
//		exit(0);
	}
	if(endId==1){
		slowPrint("那个声音：就这点智商，怎么能当上"),slowPrint("勇者",BLUE),slowPrint("？菜就多练吧。\n");
		haveEnd[1]=1;
		slowPrint("达成结局1：技不如人\n");
		saveFile();
//		exit(0);
	}
	if(endId==2){
		slowPrint("你被"),slowPrint("魔物",RED),slowPrint("击杀了。任务中道崩殂，这个世界依旧存活于水深火热之中。\n");
		Sleep(2000); 
		slowPrint("达成结局2：出师未捷身先死\n");
		haveEnd[2]=1;
		saveFile();
//		exit(0);
	}
	if (endId == 3) {
	    slowPrint("（你被人类联军的领袖包围，权杖从手中滑落）\n");
	    slowPrint("人类领袖：这就是所谓的魔王？不过是个被力量吞噬的可怜虫罢了。\n");
	    Sleep(1500);
	
	    slowPrint("（你倒在地上，耳边响起X-0系统的最后提示）\n");
	    slowPrint("X-0系统：第108代魔王，任期：3天。\n", DARKGRAY);
	    slowPrint("系统已启动自毁程序，所有数据将在10秒后清除...\n", RED);
	    Sleep(1000);
	
	    slowPrint("（你闭上眼睛，耳边传来人类的欢呼声）\n");
	    slowPrint("人类领袖：魔王已死！我们胜利了！\n");
	    Sleep(2000);
	
	    slowPrint("达成结局3：魔王陨落\n");
	    slowPrint(" - 你的统治如昙花一现，人类再次证明了他们的顽强。\n");
	    slowPrint(" - 但恶意的种子并未消失，新的魔王终将诞生...\n", DARKGRAY);
	
	    haveEnd[3] = 1;
	    saveFile();
	}

	if (endId == 4) {
	    slowPrint("（人类联军的旗帜倒下，最后的抵抗者被魔物吞噬）\n");
	    slowPrint("X-0系统：检测到敌军全面溃败，魔王权柄已稳固。\n", BLUE);
	    Sleep(2000);
	
	    slowPrint("（你站在人类领袖的尸体旁，权杖上的黑色火焰熊熊燃烧）\n");
	    slowPrint("X-0系统：恭喜，第108代魔王。你已证明了自己的价值。\n", GREEN);
	    Sleep(1500);
	
	    slowPrint("（你挥动权杖，魔物大军发出震天的咆哮）\n");
	    slowPrint("X-0系统：四大古陆已臣服于你的脚下，接下来是更广阔的征途...\n", BLUE);
	    Sleep(1000);
	
	    slowPrint("（你望向远方，嘴角浮现出一丝冷笑）\n");
	    slowPrint("你：这只是一个开始。\n");
	    Sleep(2000);
	
	    slowPrint("达成结局4：魔王永恒\n");
	    slowPrint(" - 你以铁腕统治了世界，人类与魔物皆臣服于你的权柄。\n");
	    slowPrint(" - 但权力的巅峰亦是孤独的开始...\n", DARKGRAY);
	
	    haveEnd[4] = 1;
	    
	    Stage=5;skipPlot=0;countKill=0;player.money=0;
	    
	    saveFile();
	}

	if (endId == 5) {
	    slowPrint("（你试图逃离影渊圣所，但魔物大军紧追不舍）\n");
	    slowPrint("X-0系统：警告！检测到高浓度恶意反应，魔物已锁定你的位置。\n", RED);
	    Sleep(2000);
	
	    slowPrint("（你被魔物包围，手中的武器已断裂）\n");
	    slowPrint("魔物：叛徒...必须清除...\n", DARKGRAY);
	    Sleep(1500);
	
	    slowPrint("（你倒在血泊中，耳边响起X-0系统的最后提示）\n");
	    slowPrint("X-0系统：候选者213号，已失去生命体征。\n");
	    slowPrint("系统已启动清除程序，所有数据将在10秒后销毁...\n", RED);
	    Sleep(1000);
	
	    slowPrint("（你的意识逐渐模糊，最后的画面是魔物狰狞的面孔）\n");
	    slowPrint("魔物：这就是背叛的代价...\n", DARKGRAY);
	    Sleep(2000);
	
	    slowPrint("达成结局5：背叛者的末路\n");
	    slowPrint(" - 你试图回归人类，但魔物不会放过叛徒。\n");
	    slowPrint(" - 在魔王与人类之间，你选择了第三条路，却无人接纳。\n", DARKGRAY);
	
	    haveEnd[5] = 1;
	    saveFile();
	}

	if (endId == 6) {
	    slowPrint("（你终于回到人类世界，但迎接你的不是欢呼，而是冰冷的枪口）\n");
	    slowPrint("人类领袖：站住！你这个双手沾满鲜血的怪物！\n");
	    Sleep(2000);
	
	    slowPrint("（你试图解释，但无人愿意倾听）\n");
	    slowPrint("人类士兵：我们看到了你的「战绩」，你杀了多少同胞？\n", RED);
	    Sleep(1500);
	
	    slowPrint("（你被押上审判台，罪名是「反人类罪」）\n");
	    slowPrint("审判官：你已不再是人类，而是魔王的候选者。\n", DARKGRAY);
	    Sleep(1000);
	
	    slowPrint("（你被判处死刑，刑场上下起了大雨）\n");
	    slowPrint("你：我只是...想回家...\n");
	    Sleep(2000);
	
	    slowPrint("达成结局6：无处可归\n");
	    slowPrint(" - 你试图回归人类，但你的过去已成枷锁。\n");
	    slowPrint(" - 在人类眼中，你早已不是同类。\n", DARKGRAY);
	
	    haveEnd[6] = 1;
	    
	    Stage=5;skipPlot=0;countKill=0;player.money=0;
	    
	    saveFile();
	}
	if (endId == 7) {
	    slowPrint("（你终于回到人类世界，迎接你的是复杂的目光）\n");
	    slowPrint("人类领袖：我们听说了你的故事...你选择了回归。\n");
	    Sleep(2000);
	
	    slowPrint("（你低下头，等待审判）\n");
	    slowPrint("人类领袖：但你曾经的罪行无法被抹去。\n", DARKGRAY);
	    Sleep(1500);
	
	    slowPrint("（人群中传来窃窃私语，但最终，领袖伸出了手）\n");
	    slowPrint("人类领袖：我们愿意给你一个机会，因为你选择了人性。\n", GREEN);
	    Sleep(1000);
	
	    slowPrint("（你接过象征「勇者」的徽章，泪水模糊了视线）\n");
	    slowPrint("你：我...会赎罪的。\n");
	    Sleep(2000);
	
	    slowPrint("达成结局7：真正的勇者\n");
	    slowPrint(" - 你选择了回归人类，尽管代价沉重。\n");
	    slowPrint(" - 你最终成为了真正的「勇者」，守护着人类的未来。\n", GREEN);
	
	    haveEnd[7] = 1;
	    
	    Stage=5;skipPlot=0;countKill=0;player.money=0;
	    
	    saveFile();
	}

	system("pause");
}
void viewEndings(){
	if(haveEnd[0])slowPrint("达成结局0：找错人了\n");
	else slowPrint("████████████████\n");
	if(haveEnd[1])slowPrint("达成结局1：技不如人\n");
	else slowPrint("████████████████\n");
	if(haveEnd[2])slowPrint("达成结局2：出师未捷身先死\n");
	else slowPrint("████████████████\n");
	if(haveEnd[3])slowPrint("达成结局3：魔王陨落\n");
	else slowPrint("████████████████\n");
	if(haveEnd[4])slowPrint("达成结局4：魔王永恒\n");
	else slowPrint("████████████████\n");
	if(haveEnd[5])slowPrint("达成结局5：背叛者的末路\n");
	else slowPrint("████████████████\n");
	if(haveEnd[6])slowPrint("达成结局6：无处可归\n");
	else slowPrint("████████████████\n");
	if(haveEnd[7])slowPrint("达成结局7：真正的勇者\n");
	else slowPrint("████████████████\n");
	system("pause");
}
#endif
