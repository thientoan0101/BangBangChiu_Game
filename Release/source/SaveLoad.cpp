#include <fstream>
#include <vector>

#include "SaveLoad.h"


extern MainObject mainObject;
extern unsigned int die_num;
extern unsigned int die_num_boss;
extern int numThreats;
extern vector<ThreatObject*> listThreats;
extern vector<ThreatObject*> listSub;
extern ThreatObject* pBoss;

extern HP hp;
extern HP hp_boss;

extern int time_of_lv2;




void loadGame(int& type_boss, int& level, Score& score) {
	Reset(type_boss, level, score);
	load(type_boss, level, score);
}





// ---------------------------------- Reset Data ----------------------------------

void Reset(int& type_boss, int& level, Score& score) {
	/*for (int threat = 0; threat < numThreats; threat++) {
		if (listThreats[threat] != NULL) {
			delete listThreats[threat];
			listThreats[threat] = NULL;
		}
	}*/
	listThreats.clear();

	/*for (int subBoss = 0; subBoss < listSub.size(); subBoss++) {
		if (listSub[subBoss] != NULL) {
			delete listSub[subBoss];
			listSub[subBoss] = NULL;
		}
	}*/
	listSub.clear();

	if (gift_upgr_main) {
		delete gift_upgr_main;
		gift_upgr_main = NULL;
	}

	if (gift_hp) {
		delete gift_hp;
		gift_hp = NULL;
	}

	if (gift_rocket) {
		delete gift_rocket;
		gift_rocket = NULL;
	}

	level = 0;

	/*for (int gift = 0; gift < listGifts.size(); gift++) {
		if (listGifts[gift] != NULL) {
			delete listGifts[gift];
			listGifts[gift] = NULL;
		}
	}
	listGifts.clear();*/
}











// ---------------------------------- Save Game ----------------------------------


void saveGame(int type_boss, int level, Score& score) {
	ofstream file("./data/Continue_Game.txt");

	vector<Gift*> listGifts;

	listGifts.push_back(gift_upgr_main);
	listGifts.push_back(gift_hp);
	listGifts.push_back(gift_rocket);

	// ---------------------------------- Global ----------------------------------


	// Level dang choi
	file << level << endl;

	// Khong hieu
	file << activeBoss << endl;
	file << activeSubBoss << endl;
	/*file << bkgn_x << endl;
	file << is_run_screen << endl;
	file << is_quit << endl;*/


	// time_of_lv2
	file << time_of_lv2 << endl;

	// Score
	file << score.getScore() << endl;


	// ---------------------------------- Main ----------------------------------


	// Vi tri cua Main
	file << mainObject.getRect().x << " " << mainObject.getRect().y << endl;

	// Mau cua Main
	file << die_num << endl;

	// Cap do may bay cua Main
	file << mainObject.getType() << endl;

	// So luong dan duoc cua Main
	file << mainObject.getAmoList().size() << endl;

	// Vi tri dan duoc cua Main + is_move
	vector<AmoObject*> amo_list = mainObject.getAmoList();
	for (int amo = 0; amo < amo_list.size(); amo++) {
		file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
		file << amo_list[amo]->getIsMove() << endl;
	}
	amo_list.clear();







	// ---------------------------------- Thread ----------------------------------


	// So luong Thread
	/*file << listThreats.size() << endl;*/

	// Vi tri Threat + is_move + loai + toc do + active_oscillation + step
	// Dan duoc cua Threat
	for (int threat = 0; threat < listThreats.size(); threat++) {
		file << listThreats[threat]->getRect().x << " " << listThreats[threat]->getRect().y << endl;
		file << /*listThreats[threat]->getIsMove() << " " <<*/ listThreats[threat]->getType() << endl;
		file << listThreats[threat]->get_x_delta() << " " << listThreats[threat]->get_y_delta() << endl;
		file << listThreats[threat]->getOscillation() << endl;
		/*file << listThreats[threat]->getStep() << endl;*/

		// So luong dan duoc cua threat
		file << listThreats[threat]->GetAmoList().size() << endl;

		// Vi tri dan duoc cua Threat + is_move + type + toc do
		amo_list = listThreats[threat]->GetAmoList();
		for (int amo = 0; amo < amo_list.size(); amo++) {
			file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
			file << amo_list[amo]->getIsMove() << " " << amo_list[amo]->getType() << endl;
			/*file << amo_list[amo]->get_x_delta() << " " << amo_list[amo]->get_y_delta() << endl;*/
		}
	}
	amo_list.clear();






	// ---------------------------------- Boss ----------------------------------


	//// Vi tri cua Boss
	//file << pBoss->getRect().x << " " << pBoss->getRect().y << endl;

	//// Mau cua Boss
	///*file << die_num_boss << endl;*/

	//// Loai cua Boss
	//file << type_boss << endl;

	//// Toc do cua Boss
	//file << pBoss->get_x_delta() << " " << pBoss->get_y_delta() << endl;

	//// So luong dan duoc cua Boss
	//file << pBoss->GetAmoList().size() << endl;

	//// Vi tri dan duoc cua Boss + is_move + type + toc do
	//amo_list = pBoss->GetAmoList();
	//for (int amo = 0; amo < amo_list.size(); amo++) {
	//	file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
	//	file << amo_list[amo]->getIsMove() << " " << amo_list[amo]->getType() << endl;
	//	/*file << amo_list[amo]->get_x_delta() << " " << amo_list[amo]->get_y_delta() << endl;*/
	//}
	//amo_list.clear();






	// ---------------------------------- Sub Boss ----------------------------------


	// So luong Sub Boss
	file << listSub.size() << endl;

	// Vi tri cua Sub Boss + is_move + type + toc do
	for (int subBoss = 0; subBoss < listSub.size(); subBoss++) {
		file << listSub[subBoss]->getRect().x << " " << listSub[subBoss]->getRect().y << endl;
		file << /*listSub[subBoss]->getIsMove() << " " <<*/ listSub[subBoss]->getType() << endl;
		file << listSub[subBoss]->get_x_delta() << " " << listSub[subBoss]->get_y_delta() << endl;

		// So luong dan duoc cua Sub Boss
		file << listSub[subBoss]->GetAmoList().size() << endl;

		// Vi tri dan duoc cua Sub Boss + is_move + type + toc do
		amo_list = listSub[subBoss]->GetAmoList();
		for (int amo = 0; amo < amo_list.size(); amo++) {
			file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
			file << amo_list[amo]->getIsMove() << " " << amo_list[amo]->getType() << endl;
			/*file << amo_list[amo]->get_x_delta() << " " << amo_list[amo]->get_y_delta() << endl;*/
		}
	}
	amo_list.clear();






	// ---------------------------------- Gift ----------------------------------


	// So luong Gift
	file << listGifts.size() << endl;

	// Vi tri cua Gift + is_move + kieu + toc do + is_create
	for (int gift = 0; gift < listGifts.size(); gift++) {
		file << listGifts[gift]->getRect().x << " " << listGifts[gift]->getRect().y << endl;
		file << listGifts[gift]->getIsMove() << " " << listGifts[gift]->getType() << endl;
		file << listGifts[gift]->getXVal() << " " << listGifts[gift]->getYVal() << endl;
		file << listGifts[gift]->getIsCreate() << endl;
	}
	listGifts.clear();




	file.close();
}

































// ---------------------------------- Load Game ----------------------------------


void load(int& type_boss, int& level, Score& score) {
	ifstream file("./data/Continue_Game.txt");
	int x, y, b, type, x_val, y_val, HP, num_amo, numSubBoss, numGift;
	vector<AmoObject*> amo_list;
	vector<Gift*> listGifts;


	// ---------------------------------- Global ----------------------------------


	// Level dang choi
	file >> level;

	bool ret;
	ret = BackgroundFunc::prepareBackground(level);							// load background theo man
	if (ret == 0) exit(EXIT_FAILURE);

	// Khong hieu
	file >> activeBoss;
	file >> activeSubBoss;
	/*file >> bkgn_x;
	file >> is_run_screen;
	file >> is_quit;*/


	// time_of_lv2
	file >> time_of_lv2;

	// Score
	int temp_score = 0;
	file >> temp_score;
	score.setScore(temp_score);


	// ---------------------------------- Main ----------------------------------


	// Vi tri cua Main
	file >> x >> y;
	mainObject.setRect(x, y);

	// Mau cua Main
	file >> die_num;
	hp.init(die_num);

	// Cap do may bay cua Main
	int type_main;
	file >> type_main;
	mainObject.setType(type_main);

	// Load hinh
	switch (type_main) {
	case MainObject::LEVEL_1:
		mainObject.loadImgObject("./image/main.png");
		break;
	case MainObject::LEVEL_2:
		mainObject.loadImgObject("./image/main_lv2.png");
		break;
	}

	// So luong dan duoc cua Main
	file >> num_amo;

	// Vi tri dan duoc cua Main + is_move
	for (int amo = 0; amo < num_amo; amo++) {
		file >> x >> y >> b;

		AmoObject* p_amo = new AmoObject();
		p_amo->setRect(x, y);
		p_amo->setIsMove(b);


		switch (type_main) {
		case MainObject::LEVEL_1:
			p_amo->setWidthHeight(WIDTH_BULLET, HEIGHT_BULLET);
			p_amo->loadImgObject("./image/bullet.png");
			p_amo->setType(AmoObject::BULLET);

			p_amo->setX_Val(AMO_MAIN_SPEED);

			break;
		case MainObject::LEVEL_2:
			p_amo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			p_amo->loadImgObject("./image/lazer.png");
			p_amo->setType(AmoObject::LAZER);

			p_amo->setX_Val(AMO_MAIN_SPEED);

			break;
		}

		amo_list.push_back(p_amo);
	}
	mainObject.setAmoList(amo_list);
	amo_list.clear();








	// ---------------------------------- Thread ----------------------------------


	// So luong Threat
	/*file >> numThreats;*/

	// Vi tri Threat + is_move + loai + toc do + step
	createListThreatObjects(listThreats, level, numThreats);

	for (int threat = 0; threat < numThreats; threat++) {
		bool active_oscillation;
		int step;

		file >> x >> y;
		file /*>> b*/ >> type;
		file >> x_val >> y_val;
		file >> active_oscillation;
		/*file >> step;*/

		listThreats[threat]->setRect(x, y);
		/*listThreats[threat]->setIsMove(b);*/
		listThreats[threat]->setType(type);
		listThreats[threat]->set_x_delta(x_val); listThreats[threat]->set_y_delta(y_val);

		file >> num_amo;
		for (int amo = 0; amo < num_amo; amo++) {
			file >> x >> y;
			file >> b >> type;
			/*file >> x_val >> y_val;*/

			AmoObject* p_amo = listThreats[threat]->GetAmoList()[amo];
			p_amo->setRect(x, y);
			p_amo->setIsMove(b);
			p_amo->setType(type);
			/*p_amo->setX_Val(x_val); p_amo->setY_Val(y_val);*/
		}
	}







	// ---------------------------------- Boss ----------------------------------


	//// Vi tri cua Boss
	//file >> x >> y;
	//pBoss->setRect(x, y);

	//// Mau cua Boss
	///*file >> die_num_boss;*/
	////hp_boss.init(die_num_boss);

	//// Loai cua Boss
	//file >> type_boss;

	//// Toc do cua Boss
	//file >> x_val >> y_val;
	//pBoss->set_x_delta(x_val); pBoss->set_y_delta(y_val);

	//// so luong dan duoc cua Boss
	//file >> num_amo;

	//// Vi tri dan duoc cua Boss + is_move + type + toc do
	//createBoss(pBoss, level);
	//for (int amo = 0; amo < num_amo; amo++) {
	//	file >> x >> y;
	//	file >> b >> type;
	//	/*file >> x_val >> y_val;*/

	//	AmoObject* p_amo = pBoss->GetAmoList()[amo];
	//	p_amo->setRect(x, y);
	//	p_amo->setIsMove(b);
	//	p_amo->setType(type);
	//	/*p_amo->setX_Val(x_val); p_amo->setY_Val(y_val);*/
	//}







	// ---------------------------------- Sub Boss ----------------------------------


	// So luong Sub Boss
	file >> numSubBoss;
	if (numSubBoss < 0)
		numSubBoss = 0;

	// Vi tri cua SubBoss
	listSub.resize(numSubBoss);
	for (int subBoss = 0; subBoss < listSub.size(); subBoss++) {
		listSub[subBoss] = new ThreatObject;
		createSubBoss(listSub[subBoss], pBoss);

		file >> x >> y;
		file /*>> b*/ >> type;
		file >> x_val >> y_val;

		listSub[subBoss]->setRect(x, y);
		/*listSub[subBoss]->setIsMove(b);*/ listSub[subBoss]->setType(type);
		listSub[subBoss]->set_x_delta(x_val); listSub[subBoss]->set_y_delta(y_val);

		file >> num_amo;
		for (int amo = 0; amo < num_amo; amo++) {
			file >> x >> y;
			file >> b >> type;
			/*file >> x_val >> y_val;*/

			AmoObject* p_amo = listSub[subBoss]->GetAmoList()[amo];
			p_amo->setRect(x, y);
			p_amo->setIsMove(b);
			p_amo->setType(type);
			/*p_amo->setX_Val(x_val); p_amo->setY_Val(y_val);*/
		}
	}








	// ---------------------------------- Gift ----------------------------------


	// So luong Gift
	file >> numGift;

	// Vi tri cua Gift
	for (int gift = 0; gift < numGift; gift++) {
		bool create;
		Gift* p_gift = new Gift();

		file >> x >> y;
		file >> b >> type;
		file >> x_val >> y_val;
		file >> create;

		switch (type) {
		case Gift::UPGRADE_AMO:
			createGift("./image/gift.png", p_gift, Gift::UPGRADE_AMO);
			break;
		case Gift::UPGRADE_SPACESHIP:
			createGift("./image/gift_up_main.png", p_gift, Gift::UPGRADE_SPACESHIP);
			break;
		case Gift::HP:
			createGift("./image/HP_gift.png", p_gift, Gift::HP);
			break;
		}

		p_gift->setRect(x, y);
		/*p_gift->setIsMove(b); p_gift->setType(type);*/
		/*p_gift->setXVal(x_val); p_gift->setYVal(y_val);*/
		p_gift->setIsCreate(create);

		listGifts.push_back(p_gift);
	}


	gift_upgr_main = listGifts[0];
	gift_hp = listGifts[1];
	gift_rocket = listGifts[2];





	file.close();
}