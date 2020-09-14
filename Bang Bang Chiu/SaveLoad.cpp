#include "SaveLoad.h"

#include <fstream>


// ---------------------------------- Save Game ----------------------------------


void saveGame(MainObject main, int main_HP, int main_typeAmo, int main_typePlane, unsigned int die_num, vector<ThreatObject*> list_Threats, int numThreat, ThreatObject* pBoss, int type_boss, unsigned int die_num_boss, vector<ThreatObject*> listSubBoss, vector<Gift*> listGifts, int level) {
	ofstream file("Continue_Game.txt");


	// ---------------------------------- Global ----------------------------------


	// Level dang choi
	file << level << endl;

	// Khong hieu
	/*file << activeBoss << endl;
	file << activeSubBoss << endl;
	file << bkgn_x << endl;
	file << is_run_screen << endl;
	file << is_quit << endl;*/







	// ---------------------------------- Main ----------------------------------


	// Vi tri cua Main
	file << main.getRect().x << " " << main.getRect().y << endl;

	// Mau cua Main
	file << main_HP << endl;

	// Cap do may bay cua Main
	/*file << main_typePlane << endl;*/

	// So lan Main trung dan
	file << die_num << endl;

	// Loai dan duoc cua Main
	/*file << main_typeAmo << endl;*/

	// So luong dan duoc cua Main
	file << main.getAmoList().size() << endl;

	// Vi tri dan duoc cua Main + is_move
	vector<AmoObject*> amo_list = main.getAmoList();
	for (int amo = 0; amo < amo_list.size(); amo++) {
		file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
		file << amo_list[amo]->getIsMove() << endl;
	}
	amo_list.clear();







	// ---------------------------------- Thread ----------------------------------


	// So luong Thread
	file << numThreat << endl;

	// Vi tri Threat + is_move + loai + toc do + active_oscillation + step
	// Dan duoc cua Threat
	for (int threat = 0; threat < list_Threats.size(); threat++) {
		file << list_Threats[threat]->getRect().x << " " << list_Threats[threat]->getRect().y << " " << endl;
		file << /*list_Threats[threat]->getIsMove() << " " <<*/ list_Threats[threat]->getType() << endl;
		file << list_Threats[threat]->get_x_delta() << " " << list_Threats[threat]->get_y_delta() << endl;
		file << list_Threats[threat]->getOscillation() << endl;
		/*file << list_Threats[threat]->getStep() << endl;*/

		// So luong dan duoc cua threat
		file << list_Threats[threat]->GetAmoList().size() << endl;

		// Vi tri dan duoc cua Threat + is_move + type + toc do
		amo_list = list_Threats[threat]->GetAmoList();
		for (int amo = 0; amo < amo_list.size(); amo++) {
			file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
			file << amo_list[amo]->getIsMove() << " " << amo_list[amo]->getType() << endl;
			/*file << amo_list[amo]->get_x_delta() << " " << amo_list[amo]->get_y_delta() << endl;*/
		}
	}
	amo_list.clear();






	// ---------------------------------- Boss ----------------------------------


	// Vi tri cua Boss
	file << pBoss->getRect().x << " " << pBoss->getRect().y << endl;

	// Mau cua Boss
	//file << hp << endl;

	// So lan Boss trung dan
	file << die_num_boss << endl;

	// Loai cua Boss
	file << type_boss << endl;

	// Toc do cua Boss
	file << pBoss->get_x_delta() << " " << pBoss->get_y_delta() << endl;

	// So luong dan duoc cua Boss
	file << pBoss->GetAmoList().size() << endl;

	// Vi tri dan duoc cua Boss + is_move + type + toc do
	amo_list = pBoss->GetAmoList();
	for (int amo = 0; amo < amo_list.size(); amo++) {
		file << amo_list[amo]->getRect().x << " " << amo_list[amo]->getRect().y << endl;
		file << amo_list[amo]->getIsMove() << " " << amo_list[amo]->getType() << endl;
		/*file << amo_list[amo]->get_x_delta() << " " << amo_list[amo]->get_y_delta() << endl;*/
	}
	amo_list.clear();






	// ---------------------------------- Sub Boss ----------------------------------


	// So luong Sub Boss
	file << listSubBoss.size() << endl;

	// Vi tri cua Sub Boss + is_move + type + toc do
	for (int subBoss = 0; subBoss < listSubBoss.size(); subBoss++) {
		file << listSubBoss[subBoss]->getRect().x << " " << listSubBoss[subBoss]->getRect().y << endl;
		file << /*listSubBoss[subBoss]->getIsMove() << " " <<*/ listSubBoss[subBoss]->getType() << endl;
		file << listSubBoss[subBoss]->get_x_delta() << " " << listSubBoss[subBoss]->get_y_delta() << endl;

		// So luong dan duoc cua Sub Boss
		file << listSubBoss[subBoss]->GetAmoList().size() << endl;

		// Vi tri dan duoc cua Sub Boss + is_move + type + toc do
		amo_list = listSubBoss[subBoss]->GetAmoList();
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





	file.close();
}

































// ---------------------------------- Load Game ----------------------------------


void loadGame(MainObject& main, int main_HP, int main_typeAmo, int main_typePlane, unsigned int& die_num, vector<ThreatObject*>& list_Threats, int& numThreat, ThreatObject* pBoss, int& type_boss, unsigned int& die_num_boss, vector<ThreatObject*>& listSubBoss, vector<Gift*>& listGifts, int& level) {
	ifstream file("Continue_Game.txt");
	int x, y, b, type, x_val, y_val, HP, num_amo, numSubBoss, numGift;
	vector<AmoObject*> amo_list;


	// ---------------------------------- Global ----------------------------------


	// Level dang choi
	file >> level;

	// Khong hieu
	/*file >> activeBoss;
	file >> activeSubBoss;
	file >> bkgn_x;
	file >> is_run_screen;
	file >> is_quit*/







	// ---------------------------------- Main ----------------------------------


	// Vi tri cua Main
	file >> x >> y;
	main.setRect(x, y);

	// Mau cua Main
	file >> main_HP;
	/*main.setHP(main_HP);*/

	// Cap do may bay cua Main
	/*file >> main_typePlane;*/
	/*main.setType(main_typePlane);*/
	// Load hinh
	/*switch (main_typePlane) {

	}*/

	// So lan Main bi trung dan
	file >> die_num;

	// Loai dan duoc cua Main
	/*file >> main_typeAmo;*/

	// So luong dan duoc cua Main
	file >> num_amo;

	// Vi tri dan duoc cua Main + is_move
	for (int amo = 0; amo < num_amo; amo++) {
		file >> x >> y >> b;

		AmoObject* p_amo = new AmoObject();
		p_amo->setRect(x, y);
		p_amo->setIsMove(b);
		p_amo->setType(main_typeAmo);

		// Load hinh:
		/*switch (main_typeAmo) {

		}*/

		amo_list.push_back(p_amo);
	}
	main.setAmoList(amo_list);
	amo_list.clear();








	// ---------------------------------- Thread ----------------------------------


	// So luong Threat
	file >> numThreat;

	// Vi tri Threat + is_move + loai + toc do + step
	createListThreatObjects(list_Threats, level, numThreat);

	for (int threat = 0; threat < numThreat; threat++) {
		bool active_oscillation;
		int step;

		file >> x >> y;
		file /*>> b*/ >> type;
		file >> x_val >> y_val;
		file >> active_oscillation;
		/*file >> step;*/

		list_Threats[threat]->setRect(x, y);
		/*list_Threats[threat]->setIsMove(b);*/
		list_Threats[threat]->setType(type);
		list_Threats[threat]->set_x_delta(x_val); list_Threats[threat]->set_y_delta(y_val);

		file >> num_amo;
		for (int amo = 0; amo < num_amo; amo++) {
			file >> x >> y;
			file >> b >> type;
			/*file >> x_val >> y_val;*/

			AmoObject* p_amo = list_Threats[threat]->GetAmoList()[amo];
			p_amo->setRect(x, y);
			p_amo->setIsMove(b);
			p_amo->setType(type);
			/*p_amo->setX_Val(x_val); p_amo->setY_Val(y_val);*/
		}
	}







	// ---------------------------------- Boss ----------------------------------


	// Vi tri cua Boss
	file >> x >> y;
	pBoss->setRect(x, y);

	//Mau cua Boss
	/*file >> HP;*/

	// So lan Boss trung dan
	file >> die_num_boss;

	// Loai cua Boss
	file >> type_boss;

	// Toc do cua Boss
	file >> x_val >> y_val;
	pBoss->set_x_delta(x_val); pBoss->set_y_delta(y_val);

	// so luong dan duoc cua Boss
	file >> num_amo;

	// Vi tri dan duoc cua Boss + is_move + type + toc do
	createBoss(pBoss, 4 /*level*/);
	for (int amo = 0; amo < num_amo; amo++) {
		file >> x >> y;
		file >> b >> type;
		/*file >> x_val >> y_val;*/

		AmoObject* p_amo = pBoss->GetAmoList()[amo];
		p_amo->setRect(x, y);
		p_amo->setIsMove(b);
		p_amo->setType(type);
		/*p_amo->setX_Val(x_val); p_amo->setY_Val(y_val);*/
	}







	// ---------------------------------- Sub Boss ----------------------------------


	// So luong Sub Boss
	file >> numSubBoss;

	// Vi tri cua SubBoss
	listSubBoss.resize(numSubBoss);
	for (int subBoss = 0; subBoss < numSubBoss; subBoss++) { // lỗi ở đây
		listSubBoss[subBoss] = new ThreatObject;
		createSubBoss(listSubBoss[subBoss], pBoss);

		file >> x >> y;
		file /*>> b*/ >> type;
		file >> x_val >> y_val;

		listSubBoss[subBoss]->setRect(x, y);
		/*listSubBoss[subBoss]->setIsMove(b);*/ listSubBoss[subBoss]->setType(type);
		listSubBoss[subBoss]->set_x_delta(x_val); listSubBoss[subBoss]->set_y_delta(y_val);

		file >> num_amo;
		for (int amo = 0; amo < num_amo; amo++) {
			file >> x >> y;
			file >> b >> type;
			/*file >> x_val >> y_val;*/

			AmoObject* p_amo = listSubBoss[subBoss]->GetAmoList()[amo];
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

		p_gift->setRect(x, y);
		p_gift->setIsMove(b); p_gift->setType(type);
		p_gift->setXVal(x_val); p_gift->setYVal(y_val);
		p_gift->setIsCreate(create);

		listGifts.push_back(p_gift);
	}








	file.close();
}