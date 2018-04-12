#include "character.h"

string character::getName() const {
	return name;
}
string character::getRace() const {
	return race;
}
string character::getSex() const {
	return sex;
}
string character::getType() const {
	return type;
}
string character::getAlign() const {
	string temp;
	for (int i = 0; i < 2; i++) {
		switch (alignment[i]) {
		case 'L':
			temp.append("Lawful ");
			break;
		case 'N':
			temp.append("Neutral ");
			break;
		case 'C':
			temp.append("Chaotic ");
			break;
		case 'G':
			temp.append("Good");
			break;
		case 'E':
			temp.append("Evil");
			break;
		default:
			break;
		}
	}
	return temp;
}
int character::getmaxhp() const {
	return stats[0];
}
int character::getcurhp() const {
	return stats[1];
}
int character::getac() const {
	return stats[2];
}
int character::getspd() const {
	return stats[3];
}
int character::getNsize() const {
	return stats[4];
}
string character::getsize() const {
	switch (stats[4]) {
	case 0: return "Tiny (1/4 Square)";
	case 1: return "Small (1 Square)";
	case 2: return "Medium (1 Square)";
	case 3: return "Large (4 Squares)";
	case 4: return "Huge (9 Squares)";
	case 5: return "Gargantuan (16 Squares)";
	default: return 0;
	}
}
int character::getstr() const {
	return stats[5];
}
int character::getdex() const {
	return stats[6];
}
int character::getcon() const {
	return stats[7];
}
int character::getint() const {
	return stats[8];
}
int character::getwis() const {
	return stats[9];
}
int character::getcha() const {
	return stats[10];
}
int character::getinit() const {
	return stats[11];
}
int character::getpasper() const {
	return stats[12];
}
int character::getCp() const {
	return wallet[0];
}
int character::getSp() const {
	return wallet[1];
}
int character::getEp() const {
	return wallet[2];
}
int character::getGp() const {
	return wallet[3];
}
int character::getPp() const {
	return wallet[4];
}

void character::setType(string nType) {
	type = nType;
}
void character::setRace(string nRace) {
	race = nRace;
}
void character::setmaxhp(int maxhp) {
	stats[0] = maxhp;
}
void character::setcurhp(int curhp) {
	stats[1] = curhp;
}
void character::setac(int ac) {
	stats[2] = ac;
}
void character::setspd(int spd) {
	stats[3] = spd;
}
void character::setsize(int size) {
	stats[4] = size;
}
void character::setstr(int str) {
	stats[5] = str;
}
void character::setdex(int dex) {
	stats[6] = dex;
}
void character::setcon(int con) {
	stats[7] = con;
}
void character::setint(int Int) {
	stats[8] = Int;
}
void character::setwis(int wis) {
	stats[9] = wis;
}
void character::setcha(int cha) {
	stats[10] = cha;
}
void character::setinit(int init) {
	stats[11] = init;
}
void character::setpasper(int pasper) {
	stats[12] = pasper;
}
bool character::setssProf(int index, bool special) {
	int selector;
	if (savingSkillsProf[index] == true) {
		cout << "Skill already known..try again" << endl;
		if (special)
			return false;
		else {
			std::cout << "\nChoose another Skill:\n  Acrobatics(1)\n  Animal Handling(2)\n  Arcana(3)\n  Athletics(4)\n  Deception(5)\n  History(6)\n  Insight(7)\n  Intimidation(8)\n  Investigation(9)\n  Medicine(10)\n  Nature(11)\n  Perception(12)\n  Performance(13)\n  Persuasion(14)\n  Religion(15)\n  Sleight of Hand(16)\n  Stealth(17)\n  Survival(18)" << endl;
			selector = intValid(19);
			setssProf(selector + 5);
		}
	}
	savingSkillsProf[index] = true;
	return true;
}
void character::setAlign(int index) {
	switch (index) {
	case 1:
		alignment = "LG";
		break;
	case 2:
		alignment = "NG";
		break;
	case 3:
		alignment = "CG";
		break;
	case 4:
		alignment = "LN";
		break;
	case 5:
		alignment = " N";
		break;
	case 6:
		alignment = "CN";
		break;
	case 7:
		alignment = "LE";
		break;
	case 8:
		alignment = "NE";
		break;
	case 9:
		alignment = "CE";
		break;
	}
}
void character::setstats() {
	std::cout << "Enter name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "\nEnter STR: ";
	std::cin >> stats[5];
	std::cout << "\nEnter DEX: ";
	std::cin >> stats[6];
	std::cout << "\nEnter CON: ";
	std::cin >> stats[7];
	std::cout << "\nEnter INT: ";
	std::cin >> stats[8];
	std::cout << "\nEnter WIS: ";
	std::cin >> stats[9];
	std::cout << "\nEnter CHA: ";
	std::cin >> stats[10];
	std::cout << "\nCharacter created..." << endl;
}

void character::addmaxhp(int maxhp) {
	stats[0] += maxhp;
}
void character::addcurhp(int curhp) {
	stats[1] += curhp;
}
void character::addac(int ac) {
	stats[2] = ac;
}
void character::addspd(int spd) {
	stats[3] = spd;
}
void character::addstr(int str) {
	stats[5] += str;
}
void character::adddex(int dex) {
	stats[6] += dex;
}
void character::addcon(int con) {
	stats[7] += con;
}
void character::addint(int Int) {
	stats[8] += Int;
}
void character::addwis(int wis) {
	stats[9] += wis;
}
void character::addcha(int cha) {
	stats[10] += cha;
}
void character::addresource(string Name, int max, int rest, int select) {
	Resource r;
	r.setName(Name);
	r.addSlot(max);
	r.setRegen(rest);
	if (select == 1) { //Spell slots
		for (int i = 0; i < 8; i++)
			r.addSlot(0);
	}
	resources.emplace(r);
}
bool character::addfeature(string F, int index, string D) {
	pair<unordered_set<string>::iterator, bool> temp;
	pair<unordered_set<Feature>::iterator, bool> Newtemp;
	Feature object;
	object.setName(F);
	object.setDesc(D);
	switch (index) {
	case 1:
		Newtemp = racefeatures.emplace(object);
		break;
	case 2:
		Newtemp = bgfeatures.emplace(object);
		break;
	case 3:
		temp = lang.emplace(F);
		break;
	case 4:
		temp = weaponProf.emplace(F);
		break;
	case 5:
		temp = armorProf.emplace(F);
		break;
	case 6:
		temp = toolProf.emplace(F);
		if (!temp.second) {
			std::cout << "Tool Proficiency already known..Please choose another" << endl;
			addToolProf();
		}
		break;
	case 7:
		Newtemp = feats.emplace(object);
		break;
	default:
		Newtemp = classfeatures.emplace(object);
		break;
	}
	return Newtemp.second;
}
void character::delfeature(string F, int index) {
	unordered_set<Feature>::iterator it;
	switch (index) {
	case 1:
		it = find_if(racefeatures.begin(), racefeatures.end(), find_by_name<Feature>(F));
		if (it != racefeatures.end())
			racefeatures.erase(it);
		break;
	case 2:
		it = find_if(bgfeatures.begin(), bgfeatures.end(), find_by_name<Feature>(F));
		if (it != bgfeatures.end())
			bgfeatures.erase(it);
		break;
	case 3:
		lang.erase(F);
		break;
	case 4:
		weaponProf.erase(F);
		break;
	case 5:
		armorProf.erase(F);
		break;
	case 6:
		toolProf.erase(F);
		break;
	case 7:
		it = find_if(feats.begin(), feats.end(), find_by_name<Feature>(F));
		if (it != feats.end())
			feats.erase(it);
	default:
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>(F));
		if (it != classfeatures.end())
			classfeatures.erase(it);
		break;
	}
}
void character::addWeaponProf(int repeat) {
	vector<string> weaponList = { "Club","Dagger","Greatclub","Handaxe","Javelin","Light hammer","Mace","Quarterstaff","Sickle","Spear","Light crossbow","Dart","Shortbow","Sling","Battleaxe","Flail","Glaive","Greataxe","Greatsword","Halberd","Lance","Longsword","Maul","Morningstar","Pike","Rapier","Scimitar","Shortsword","Trident","War pick","Warhammer","Whip","Blowgun","Hand crossbow","Heavy crossbow","Longbow","Net" };
	pair<unordered_set<string>::iterator, bool> temp;
	if (weaponProf.find("Martial weapons") != weaponProf.end())
		weaponList.erase(weaponList.begin() + 14, weaponList.end());
	if (weaponProf.find("Simple weapons") != weaponProf.end())
		weaponList.erase(weaponList.begin(), weaponList.begin() + 14);
	if (weaponList.size() == 0)
		std::cout << "You are proficient with all weapons" << endl;
	else {
		for (int j = 0; j < repeat; j++) {
			bool flag = false;
			while (!flag) {
				if (repeat == 1)
					std::cout << "\nChoose Weapon Proficiency:" << endl;
				else
					std::cout << "\nChoose Weapon Proficiency(" << j + 1 << "/" << repeat << "):" << endl;
				for (unsigned int i = 0; i < weaponList.size(); i++)
					std::cout << "  " << weaponList[i] << "(" << i + 1 << ")" << endl;
				int selector = intValid(weaponList.size() + 1);
				temp = weaponProf.emplace(weaponList[selector - 1]);
				if (temp.second)
					flag = true;
				else
					std::cout << "Already proficient in that weapon..Choose another" << endl;
			}
		}
	}
}
void character::addArtToolProf() {
	bool flag = false;
	pair<unordered_set<string>::iterator, bool> temp;
	while (!flag) {
		std::cout << "\nChoose Artisan Tool Proficiency:\n  Alchemist's supplies(1)\n  Brewer's supplies(2)\n  Calligrapher's supplies(3)\n  Carpenter's tools(4)\n  Cartographer's tools(5)\n  Cobbler's tools(6)\n  Cook's utensils(7)\n  Glassblower's tools(8)\n  Jeweler's tools(9)\n  Leatherworker's tools(10)\n  Mason's tools(11)\n  Painter's supplies(12)\n  Potter's tools(13)\n  Smith's tools(14)\n  Tinker's tools(15)\n  Weaver's tools(16)\n  Woodcarver's tools(17)" << endl;
		int selector = intValid(18);
		switch (selector) {
		case 1:
			temp = toolProf.emplace("Alchemist's supplies");
			break;
		case 2:
			temp = toolProf.emplace("Brewer's supplies");
			break;
		case 3:
			temp = toolProf.emplace("Calligrapher's supplies");
			break;
		case 4:
			temp = toolProf.emplace("Carpenter's tools");
			break;
		case 5:
			temp = toolProf.emplace("Cartographer's tools");
			break;
		case 6:
			temp = toolProf.emplace("Cobbler's tools");
			break;
		case 7:
			temp = toolProf.emplace("Cook's utensils");
			break;
		case 8:
			temp = toolProf.emplace("Glassblower's tools");
			break;
		case 9:
			temp = toolProf.emplace("Jeweler's tools");
			break;
		case 10:
			temp = toolProf.emplace("Leatherworker's tools");
			break;
		case 11:
			temp = toolProf.emplace("Mason's tools");
			break;
		case 12:
			temp = toolProf.emplace("Painter's supplies");
			break;
		case 13:
			temp = toolProf.emplace("Potter's tools");
			break;
		case 14:
			temp = toolProf.emplace("Smith's tools");
			break;
		case 15:
			temp = toolProf.emplace("Tinker's tools");
			break;
		case 16:
			temp = toolProf.emplace("Weaver's tools");
			break;
		case 17:
			temp = toolProf.emplace("Woodcarver's tools");
			break;
		}
		if (temp.second)
			flag = true;
		else
			std::cout << "\nTool Proficiency already known..Please choose another" << endl;
	}
}
void character::addInstrumProf(int repeat) {
	vector<string> instrum = { "Bagpipes","Drum","Dulcimer","Flute","Lute","Lyre","Horn","Pan flute","Shawm","Viol" };
	pair<unordered_set<string>::iterator, bool> temp;
	for (int j = 0; j < repeat; j++) {
		bool flag = false;
		while (!flag) {
			if (repeat == 1)
				std::cout << "\nChoose Tool Proficiency:" << endl;
			else
				std::cout << "\nChoose Tool Proficiency(" << j + 1 << "/" << repeat << "):" << endl;
			for (unsigned int i = 0; i < instrum.size(); i++)
				std::cout << "  " << instrum[i] << "(" << i + 1 << ")" << endl;
			int selector = intValid(11);
			temp = toolProf.emplace(instrum[selector - 1]);
			if (temp.second)
				flag = true;
			else
				std::cout << "Tool Proficiency already known..Please choose another" << endl;
		}
	}
}
void character::addGamingProf() {
	bool flag = false;
	pair<unordered_set<string>::iterator, bool> temp;
	while (!flag) {
		std::cout << "\nChoose Tool Proficiency:\n  Dice set(1)\n  Dragonchess set(2)\n  Playing card set(3)\n  Three-Dragon Ante set(4)" << endl;
		int selector = intValid(5);
		switch (selector) {
		case 1:
			temp = toolProf.emplace("Dice set");
			break;
		case 2:
			temp = toolProf.emplace("Dragonchess set");
			break;
		case 3:
			temp = toolProf.emplace("Playing card set");
			break;
		case 4:
			temp = toolProf.emplace("Three-Dragon Ante set");
			break;
		}
		if (temp.second)
			flag = true;
		else
			std::cout << "Tool Proficiency already known..Please choose another" << endl;
	}
}
void character::addToolProf() {
	std::cout << "\nChoose Tool Proficiency:\n  Artisan Tool(1)\n  Disguise kit(2)\n  Forgery kit(3)\n  Gaming set(4)\n  Herbalism kit(5)\n  Musical Instrument(6)\n  Navigator's tools(7)\n  Poisoner's kit(8)\n  Thieves' tools(9)\n  Vehicles(Land)(10)\n  Vehicles(Water)(11)" << endl;
	int selector = intValid(12);
	switch (selector) {
	case 1:
		addArtToolProf();
		break;
	case 2:
		addfeature("Disguise kit", 6);
		break;
	case 3:
		addfeature("Forgery kit", 6);
		break;
	case 4:
		addGamingProf();
		break;
	case 5:
		addfeature("Herbalism kit", 6);
		break;
	case 6:
		addInstrumProf();
		break;
	case 7:
		addfeature("Navigator's tools", 6);
		break;
	case 8:
		addfeature("Poisoner's kit", 6);
		break;
	case 9:
		addfeature("Thieves' tools", 6);
		break;
	case 10:
		addfeature("Vehicles(Land)", 6);
		break;
	case 11:
		addfeature("Vehicles(Water)", 6);
		break;
	}
}
void character::addlang(int repeat) {
	vector<string> langList = { "Dwarvish","Elvish","Giant","Gnomish","Goblin","Halfling","Orc","Abyssal","Celestial","Draconic","Deep Speech","Infernal","Primordial","Sylvan","Undercommon" };
	for (int j = 0; j < repeat; j++) {
		bool flag = false;
		pair<unordered_set<string>::iterator, bool> temp;
		while (!flag) {
			if (repeat == 1)
				std::cout << "\nChoose Language:" << endl;
			else
				std::cout << "\nChoose Language(" << j + 1 << "/" << repeat << "):" << endl;
			for (unsigned int i = 0; i < langList.size(); i++)
				std::cout << "  " << langList[i] << "(" << i + 1 << ")" << endl;
			int selector = intValid(16);
			temp = lang.emplace(langList[selector - 1]);
			if (temp.second)
				flag = true;
			else
				std::cout << "Language already known..Please choose another" << endl;
		}
	}
}
void character::addCp(int cp) {
	wallet[0] += cp;
}
void character::addSp(int sp) {
	wallet[1] += sp;
}
void character::addEp(int ep) {
	wallet[2] += ep;
}
void character::addGp(int gp) {
	wallet[3] += gp;
}
void character::addPp(int pp) {
	wallet[4] += pp;
}
void character::addWeapon(string wep, float weight, int amt) {
	unordered_set<Weapon>::iterator temp = findWeapon(wep);
	Weapon tempclass;
	if (temp != weaponInv.end()) {
		tempclass.copy(*temp);
		weaponInv.erase(temp);
	}
	else {
		tempclass.setName(wep);
		tempclass.setWeight(weight);
	}
	tempclass.addqty(amt);
	weaponInv.emplace(tempclass);
	std::cout << wep << " added.." << endl;
}
void character::addArmor(string arm, float weight, int amt) {
	unordered_set<Armor>::iterator temp = findArmor(arm);
	Armor tempclass;
	if (temp != armorInv.end()) {
		tempclass.copy(*temp);
		armorInv.erase(temp);
	}
	else {
		tempclass.setName(arm);
		tempclass.setWeight(weight);
	}
	tempclass.addqty(amt);
	armorInv.emplace(tempclass);
	std::cout << arm << " added.." << endl;
}
void character::addGear(string gear, float weight, int amt) {
	unordered_set<Gear>::iterator temp = findGear(gear);
	Gear tempclass;
	if (temp != gearInv.end()) {
		tempclass.copy(*temp);
		gearInv.erase(temp);
	}
	else {
		tempclass.setName(gear);
		tempclass.setWeight(weight);
	}
	tempclass.addqty(amt);
	gearInv.emplace(tempclass);
	std::cout << gear << " added.." << endl;
}
void character::addTool(string tool, float weight) {
	unordered_set<Tool>::iterator temp = findTool(tool);
	Tool tempclass;
	if (temp != toolInv.end()) {
		tempclass.copy(*temp);
		toolInv.erase(temp);
	}
	else {
		tempclass.setName(tool);
		tempclass.setWeight(weight);
	}
	tempclass.addqty(1);
	toolInv.emplace(tempclass);
	std::cout << tool << " added.." << endl;
}
void character::addMount(string name, string type, int speed, float carry) {
	Mount mount;
	mount.setName(name);
	mount.setType(type);
	mount.setspd(speed);
	mount.setMaxCarry(carry);
	mounts.push_back(mount);
}
void character::storeItemMount(string mountName, string name, float weight, int amt, int select) {
	vector<Mount>::iterator result = find_if(mounts.begin(), mounts.end(), find_by_name<Mount>(mountName));
	if (result != mounts.end()) {
		switch (select) {
		case 1:
			result->addWeapon(name, weight, amt);
			break;
		case 2:
			result->addArmor(name, weight, amt);
			break;
		case 3:
			result->addGear(name, weight, amt);
			break;
		case 4:
			result->addTool(name, weight, amt);
			break;
		}
		result->refCarry();
	}
	else
		std::cout << "Mount does not exist" << endl;
}
void character::storeMoneyMount(string mountName, int amt, int type) {
	vector<Mount>::iterator result = find_if(mounts.begin(), mounts.end(), find_by_name<Mount>(mountName));
	if (result != mounts.end()) {
		if (wallet[type] - amt < 0) {
			std::cout << "Not enough coins" << endl;
			return;
		}
		wallet[type] -= amt;
		switch (type) {
		case 0:
			result->addCp(amt);
			break;
		case 1:
			result->addSp(amt);
			break;
		case 2:
			result->addEp(amt);
			break;
		case 3:
			result->addGp(amt);
			break;
		case 4:
			result->addPp(amt);
			break;
		}
		result->refCarry();
	}
	else
		std::cout << "Mount does not exist" << endl;
}
void character::addSimpleWep(int select, int repeat) {
	int selector = 0;
	vector<string> weaponList = { "Club","Dagger","Greatclub","Handaxe","Javelin","Light hammer","Mace","Quarterstaff","Sickle","Spear","Light crossbow","Dart","Shortbow","Sling" };
	for (int j = 0; j < repeat; j++) {
		switch (select) {
		case 1:
			if (repeat == 1)
				std::cout << "\nChoose Simple Melee Weapon:" << endl;
			else
				std::cout << "\nChoose Simple Melee Weapon(" << j + 1 << "/" << repeat << "):" << endl;
			for (int i = 0; i < 10; i++)
				std::cout << "  " << weaponList[i] << "(" << i + 1 << ")" << endl;
			selector = intValid(11);
			break;
		default:
			if (repeat == 1)
				std::cout << "\nChoose Simple Weapon:" << endl;
			else
				std::cout << "\nChoose Simple Weapon(" << j + 1 << "/" << repeat << "):" << endl;
			for (int i = 0; i < 14; i++)
				std::cout << "  " << weaponList[i] << "(" << i + 1 << ")" << endl;
			selector = intValid(15);
			break;
		}
		switch (selector) {
		case 1:
			addWeapon("Club", 2.0f);
			break;
		case 2:
			addWeapon("Dagger", 1.0f);
			break;
		case 3:
			addWeapon("Greatclub", 10.0f);
			break;
		case 4:
			addWeapon("Handaxe", 2.0f);
			break;
		case 5:
			addWeapon("Javelin", 2.0f);
			break;
		case 6:
			addWeapon("Light hammer", 2.0f);
			break;
		case 7:
			addWeapon("Mace", 4.0f);
			break;
		case 8:
			addWeapon("Quarterstaff", 4.0f);
			break;
		case 9:
			addWeapon("Sickle", 2.0f);
			break;
		case 10:
			addWeapon("Spear", 3.0f);
			break;
		case 11:
			addWeapon("Light crossbow", 5.0f);
			break;
		case 12:
			addWeapon("Dart", 0.25f);
			break;
		case 13:
			addWeapon("Shortbow", 2.0f);
			break;
		case 14:
			addWeapon("Sling");
			break;
		}
	}
}
void character::addMartialWep(int select, int repeat) {
	int selector = 0;
	vector<string> weaponList = { "Battleaxe","Flail","Glaive","Greataxe","Greatsword","Halberd","Lance","Longsword","Maul","Morningstar","Pike","Rapier","Scimitar","Shortsword","Trident","War pick","Warhammer","Whip","Blowgun","Hand crossbow","Heavy crossbow","Longbow","Net" };
	for (int j = 0; j < repeat; j++) {
		switch (select) {
		case 1:
			if (repeat == 1)
				std::cout << "\nChoose Martial Melee Weapon:" << endl;
			else
				std::cout << "\nChoose Martial Melee Weapon(" << j + 1 << "/" << repeat << "):" << endl;
			for (int i = 0; i < 18; i++)
				std::cout << "  " << weaponList[i] << "(" << i + 1 << ")" << endl;
			selector = intValid(19);
			break;
		default:
			if (repeat == 1)
				std::cout << "\nChoose Martial Weapon:" << endl;
			else
				std::cout << "\nChoose Martial Weapon(" << j + 1 << "/" << repeat << "):" << endl;
			for (int i = 0; i < 23; i++)
				std::cout << "  " << weaponList[i] << "(" << i + 1 << ")" << endl;
			selector = intValid(24);
			break;
		}
		switch (selector) {
		case 1:
			addWeapon("Battleaxe", 4.0f);
			break;
		case 2:
			addWeapon("Flail", 2.0f);
			break;
		case 3:
			addWeapon("Glaive", 6.0f);
			break;
		case 4:
			addWeapon("Greataxe", 7.0f);
			break;
		case 5:
			addWeapon("Greatsword", 6.0f);
			break;
		case 6:
			addWeapon("Halberd", 6.0f);
			break;
		case 7:
			addWeapon("Lance", 6.0f);
			break;
		case 8:
			addWeapon("Longsword", 3.0f);
			break;
		case 9:
			addWeapon("Maul", 10.0f);
			break;
		case 10:
			addWeapon("Morningstar", 4.0f);
			break;
		case 11:
			addWeapon("Pike", 18.0f);
			break;
		case 12:
			addWeapon("Rapier", 2.0f);
			break;
		case 13:
			addWeapon("Scimitar", 3.0f);
			break;
		case 14:
			addWeapon("Shortsword", 2.0f);
			break;
		case 15:
			addWeapon("Trident", 4.0f);
			break;
		case 16:
			addWeapon("War pick", 2.0f);
			break;
		case 17:
			addWeapon("Warhammer", 2.0f);
			break;
		case 18:
			addWeapon("Whip", 3.0f);
			break;
		case 19:
			addWeapon("Blowgun", 1.0f);
			break;
		case 20:
			addWeapon("Hand crossbow", 3.0f);
			break;
		case 21:
			addWeapon("Heavy crossbow", 18.0f);
			break;
		case 22:
			addWeapon("Longbow", 2.0f);
			break;
		case 23:
			addWeapon("Net", 3.0f);
			break;
		}
	}
}
void character::addBurglar() {
	addGear("Backpack", 5.0f);
	addGear("Ball bearings", 0.002f, 1000);
	addGear("String(10 feet)", 1.0f);
	addGear("Bell");
	addGear("Candle", 0.0f, 5);
	addGear("Crowbar", 5.0f);
	addGear("Hammer", 3.0f);
	addGear("Piton", 0.25f, 10);
	addGear("Hooded Lantern", 2.0f);
	addGear("Oil flask", 1.0f, 2);
	addGear("Rations(1 Day)", 2.0f, 5);
	addGear("Tinderbox", 1.0f);
	addGear("Waterskin", 5.0f);
	addGear("Hempen rope(50 feet)", 10.0f);
}
void character::addDiplomat() {
	addGear("Chest", 25.0f);
	addGear("Map/Scroll case", 1.0f, 2);
	addGear("Fine clothes set", 6.0f);
	addGear("Ink bottle");
	addGear("Ink pen");
	addGear("Lamp", 1.0f);
	addGear("Oil flask", 1.0f, 2);
	addGear("Paper", 0.0f, 5);
	addGear("Perfume(vial)");
	addGear("Sealing wax");
	addGear("Soap");
}
void character::addDungeoneer() {
	addGear("Backpack", 5.0f);
	addGear("Crowbar", 5.0f);
	addGear("Hammer", 3.0f);
	addGear("Piton", 0.25f, 10);
	addGear("Torch", 1.0f, 10);
	addGear("Tinderbox", 1.0f);
	addGear("Rations(1 Day)", 2.0f, 10);
	addGear("Waterskin", 5.0f);
	addGear("Hempen rope(50 feet)", 10.0f);
}
void character::addExplorer() {
	addGear("Backpack", 5.0f);
	addGear("Bedroll", 7.0f);
	addGear("Mess kit", 1.0f);
	addGear("Tinderbox", 1.0f);
	addGear("Torch", 1.0f, 10);
	addGear("Rations(1 Day)", 2.0f, 10);
	addGear("Waterskin", 5.0f);
	addGear("Hempen rope(50 feet)", 10.0f);
}
void character::addEntertainer() {
	addGear("Backpack", 5.0f);
	addGear("Bedroll", 7.0f);
	addGear("Costume", 4.0f, 2);
	addGear("Candle", 0.0f, 5);
	addGear("Rations(1 Day)", 2.0f, 5);
	addGear("Waterskin", 5.0f);
	addTool("Disguise kit", 3.0f);
}
void character::addPriest() {
	addGear("Backpack", 5.0f);
	addGear("Blanket", 3.0f);
	addGear("Candle", 0.0f, 10);
	addGear("Tinderbox", 1.0f);
	addGear("Alms box", 1.0f);
	addGear("Incense(Block)", 0.0f, 2);
	addGear("Censer", 1.0f);
	addGear("Vestments", 6.0f);
	addGear("Rations(1 Day)", 2.0f, 2);
	addGear("Waterskin", 5.0f);
}
void character::addScholar() {
	addGear("Backpack", 5.0f);
	addGear("Book of lore", 5.0f);
	addGear("Ink bottle");
	addGear("Ink pen");
	addGear("Parchment", 0.0f, 10);
	addGear("Little bag of sand", 1.0f);
	addGear("Small knife");
}
void character::addArtTool() {
	std::cout << "\nChoose Artisan tool:\n  Alchemist's supplies(1)\n  Brewer's supplies(2)\n  Calligrapher's supplies(3)\n  Carpenter's tools(4)\n  Cartographer's tools(5)\n  Cobbler's tools(6)\n  Cook's utensils(7)\n  Glassblower's tools(8)\n  Jeweler's tools(9)\n  Leatherworker's tools(10)\n  Mason's tools(11)\n  Painter's supplies(12)\n  Potter's tools(13)\n  Smith's tools(14)\n  Tinker's tools(15)\n  Weaver's tools(16)\n  Woodcarver's tools(17)" << endl;
	int selector = intValid(18);
	switch (selector) {
	case 1:
		addTool("Alchemist's supplies", 8.0f);
		break;
	case 2:
		addTool("Brewer's supplies", 9.0f);
		break;
	case 3:
		addTool("Calligrapher's supplies", 5.0f);
		break;
	case 4:
		addTool("Carpenter's tools", 6.0f);
		break;
	case 5:
		addTool("Cartographer's tools", 6.0f);
		break;
	case 6:
		addTool("Cobbler's tools", 5.0f);
		break;
	case 7:
		addTool("Cook's utensils", 8.0f);
		break;
	case 8:
		addTool("Glassblower's tools", 5.0f);
		break;
	case 9:
		addTool("Jeweler's tools", 2.0f);
		break;
	case 10:
		addTool("Leatherworker's tools", 5.0f);
		break;
	case 11:
		addTool("Mason's tools", 8.0f);
		break;
	case 12:
		addTool("Painter's supplies", 5.0f);
		break;
	case 13:
		addTool("Potter's tools", 3.0f);
		break;
	case 14:
		addTool("Smith's tools", 8.0f);
		break;
	case 15:
		addTool("Tinker's tools", 10.0f);
		break;
	case 16:
		addTool("Weaver's tools", 5.0f);
		break;
	case 17:
		addTool("Woodcarver's tools", 5.0f);
		break;
	}
}
void character::addInstrum() {
	std::cout << "\nChoose Musical Instrument:\n  Bagpipes(1)  \n  Drum(2)\n  Dulcimer(3)\n  Flute(4)\n  Lute(5)\n  Lyre(6)\n  Horn(7)\n  Pan flute(8)\n  Shawm(9)\n  Viol(10)" << endl;
	int selector = intValid(11);
	switch (selector) {
	case 1:
		addTool("Bagpipes", 6.0f);
		break;
	case 2:
		addTool("Drum", 3.0f);
		break;
	case 3:
		addTool("Dulcimer", 10.0f);
		break;
	case 4:
		addTool("Flute", 1.0f);
		break;
	case 5:
		addTool("Lute", 2.0f);
		break;
	case 6:
		addTool("Lyre", 2.0f);
		break;
	case 7:
		addTool("Horn", 2.0f);
		break;
	case 8:
		addTool("Pan flute", 2.0f);
		break;
	case 9:
		addTool("Shawm", 1.0f);
		break;
	case 10:
		addTool("Viol", 1.0f);
		break;
	}
}
string character::randTrinket() {
	vector<string> trinket = { "A mummified goblin hand","A piece of crystal that faintly glows in the moonlight","A gold coin minted in an unknown land","A diary written in a language you don't know","A brass ring that never tarnishes","An old chess piece made from glass","A pair of knucklebone dice, each with a skull symbol on the side that would normally show six pips","A small idol depicting a nightmarish creature that gives you unsettling dreams when you sleep near it","A rope necklace from which dangles four mummified elf fingers","The deed for a parcel of land in a realm unknown to you",
		"A 1-ounce block made from an unknown material","A small cloth doll skewered with needles","A tooth from an unknown beast","An enormous scale, perhaps from a dragon","A bright green feather","An old divination card bearing your likeness","A glass orb filled with moving smoke","A 1-pound egg with a bright red shell","A pipe that blows bubbles","A glass jar containing a weird bit of flesh floating in pickling fluid",
		"A tiny gnome-crafted music box that plays a song you dimly remember from your childhood","A small wooden statuette of a smug halfling","A brass orb etched with strange runes","A multicolored stone disk"," A tiny silver icon of a raven","A bag containing forty-seven humanoid teeth, one of which is rotten","A shard of obsidian that always feels warm to the touch","A dragon's bony talon hanging from a plain leather necklace","A pair of old socks","A blank book whose pages refuse to hold ink, chalk, graphite, or any other substance for marking",
		"A silver badge in the shape of a five-pointed star","A knife that belonged to a relative","A glass vial filled with nail clippings","A rectangular metal device with two tiny metal cups on one end that throws sparks when wet","A white, sequined glove sized for a human","A vest with one hundred tiny pockets","A small, weightless stone block","A tiny sketch portrait of a goblin","An empty glass vial that smells of perfume when opened","A gemstone that looks like a lump of coal when examined by anyone but you",
		"A scrap of cloth from an old banner","A rank insignia from a lost legionnaire","A tiny silver bell without a clapper","A mechanical canary inside a gnomish lamp","A tiny chest carved to look like it has numerous feet on the bottom","A dead sprite inside a clear glass bottle","A metal can that has no opening but sounds as if it is filled with liquid, sand, spiders, or broken glass (your choice)","A glass orb filled with water, in which swims a clockwork goldfish","A silver spoon with an M engraved on the handle","A whistle made from gold-colored wood",
		"A dead scarab beetle the size of your hand","Two toy soldiers, one with a missing head","A small box filled with different-sized buttons","A candle that can't be lit","A tiny cage with no door","An old key","An indecipherable treasure map","A hilt from a broken sword","A rabbit's foot","A glass eye",
		"A cameo carved in the likeness of a hideous person","A silver skull the size of a coin","An alabaster mask","A pyramid of sticky black incense that smells very bad","A nightcap that, when worn, gives you pleasant dreams","A single caltrop made from bone","A gold monocle frame without the lens","A 1-inch cube, each side painted a different color","A crystal knob from a door","A small packet filled with pink dust",
		"A fragment of a beautiful song, written as musical notes on two pieces of parchment","A silver teardrop earring made from a real teardrop","The shell of an egg painted with scenes of human misery in disturbing detail","A fan that, when unfolded, shows a sleeping cat","A set of bone pipes","A four-leaf clover pressed inside a book discussing manners and etiquette","A sheet of parchment upon which is drawn a complex mechanical contraption","An ornate scabbard that fits no blade you have found so far","An invitation to a party where a murder happened","A bronze pentacle with an etching of a rat's head in its center",
		"A purple handkerchief embroidered with the name of a powerful archmage","Half of a floorplan for a temple, castle, or some other structure","A bit of folded cloth that, when unfolded, turns into a stylish cap","A receipt of deposit at a bank in a far-flung city","A diary with seven missing pages","An empty silver snuffbox bearing an inscription on the surface that says \"dreams\"","An iron holy symbol devoted to an unknown god","A book that tells the story of a legendary hero's rise and fall, with the last chapter missing","A vial of dragon blood","An ancient arrow of elven design",
		"A needle that never bends","An ornate brooch of dwarven design","An empty wine bottle bearing a pretty label that says, \"The Wizard of Wines Winery, Red Dragon Crush, 331422-W\"","A mosaic tile with a multicolored, glazed surface","A petrified mouse","A black pirate flag adorned with a dragon's skull and crossbones","A tiny mechanical crab or spider that moves about when it's not being observed","A glass jar containing lard with a label that reads, \"Griffon Grease\"","A wooden box with a ceramic bottom that holds a living worm with a head on each end of its body","A metal urn containing the ashes of a hero" };
	string text = "Lucky Charm: ";
	int index = rand() % 100;
	if (index == 46) {
		std::cout << "A metal can that has no opening but sounds as if it is filled with liquid(1), sand(2), spiders(3), or broken glass(4)" << endl;
		int selector = intValid(5);
		switch (selector) {
		case 1:
			text.append("A metal can that has no opening but sounds as if it is filled with liquid");
			break;
		case 2:
			text.append("A metal can that has no opening but sounds as if it is filled with sand");
			break;
		case 3:
			text.append("A metal can that has no opening but sounds as if it is filled with spiders");
			break;
		case 4:
			text.append("A metal can that has no opening but sounds as if it is filled with broken glass");
			break;
		}
	}
	else
		text.append(trinket[index]);
	return text;
}
void character::delWeapon(string wep) {
	unordered_set<Weapon>::iterator temp = findWeapon(wep);
	Weapon tempclass;
	if (temp != weaponInv.end()) {
		if (temp->getqty() == 1)
			weaponInv.erase(temp);
		else {
			tempclass.copy(*temp);
			tempclass.addqty(-1);
			weaponInv.erase(temp);
			weaponInv.emplace(tempclass);
		}
	}
	else
		std::cout << "Item not found" << endl;
}
void character::delArmor(string arm) {
	unordered_set<Armor>::iterator temp = findArmor(arm);
	Armor tempclass;
	if (temp != armorInv.end()) {
		if (temp->getqty() == 1)
			armorInv.erase(temp);
		else {
			tempclass.copy(*temp);
			tempclass.addqty(-1);
			armorInv.erase(temp);
			armorInv.emplace(tempclass);
		}
	}
	else
		std::cout << "Item not found" << endl;
}
void character::delGear(string gear) {
	unordered_set<Gear>::iterator temp = findGear(gear);
	Gear tempclass;
	if (temp != gearInv.end()) {
		if (temp->getqty() == 1)
			gearInv.erase(temp);
		else {
			tempclass.copy(*temp);
			tempclass.addqty(-1);
			gearInv.erase(temp);
			gearInv.emplace(tempclass);
		}
	}
	else
		std::cout << "Item not found" << endl;
}
void character::delTool(string tool) {
	unordered_set<Tool>::iterator temp = findTool(tool);
	Tool tempclass;
	if (temp != toolInv.end()) {
		if (temp->getqty() == 1)
			toolInv.erase(temp);
		else {
			tempclass.copy(*temp);
			tempclass.addqty(-1);
			toolInv.erase(temp);
			toolInv.emplace(tempclass);
		}
	}
	else
		std::cout << "Item not found" << endl;
}
unordered_set<Weapon>::iterator character::findWeapon(string wep) {
	unordered_set<Weapon>::iterator result = find_if(weaponInv.begin(), weaponInv.end(), find_by_name<Weapon>(wep));
	return result;
}
unordered_set<Armor>::iterator character::findArmor(string arm) {
	unordered_set<Armor>::iterator result = find_if(armorInv.begin(), armorInv.end(), find_by_name<Armor>(arm));
	return result;
}
unordered_set<Gear>::iterator character::findGear(string gear) {
	unordered_set<Gear>::iterator result = find_if(gearInv.begin(), gearInv.end(), find_by_name<Gear>(gear));
	return result;
}
unordered_set<Tool>::iterator character::findTool(string tool) {
	unordered_set<Tool>::iterator result = find_if(toolInv.begin(), toolInv.end(), find_by_name<Tool>(tool));
	return result;
}
bool character::spellLookup(string name) {
	string temp = name;
	temp.erase(std::remove_if(temp.begin(), temp.end(), std::isspace), temp.end());
	temp = totitle(temp);
	pair<set<shared_ptr<Spell>>::iterator, bool> flag;
	switch (name_to_Spells(temp)) {
	case acidsplash:
		flag = spellList.emplace(new AcidSplash());
		break;
	case bladeward:
		flag = spellList.emplace(new BladeWard());
		break;
	case chilltouch:
		flag = spellList.emplace(new ChillTouch());
		break;
	case dancinglights:
		flag = spellList.emplace(new DancingLights());
		break;
	default:
		cout << "Spell not found" << endl;
		return false;
		break;
	}
	if (!flag.second)
		return false;
	return true;
}

int character::calcmod(int abscore) {
	switch (abscore) {
	case 1: return -5;
	case 2:
	case 3: return -4;
	case 4:
	case 5: return -3;
	case 6:
	case 7: return -2;
	case 8:
	case 9: return -1;
	case 10:
	case 11: return 0;
	case 12:
	case 13: return 1;
	case 14:
	case 15: return 2;
	case 16:
	case 17: return 3;
	case 18:
	case 19: return 4;
	case 20:
	case 21: return 5;
	case 22:
	case 23: return 6;
	case 24:
	case 25: return 7;
	case 26:
	case 27: return 8;
	case 28:
	case 29: return 9;
	case 30: return 10;
	default:
		return 0;
	}
}
void character::listInv() {
	if (!weaponInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<WEAPONS>" << endl;
		for (auto it = weaponInv.begin(); it != weaponInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << right << setw(6) << it->getqty() << endl;
		}
	}
	if (!armorInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<ARMORS>" << endl;
		for (auto it = armorInv.begin(); it != armorInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << right << setw(6) << it->getqty() << endl;
		}
	}
	if (!toolInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<TOOLS>" << endl;
		for (auto it = toolInv.begin(); it != toolInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << right << setw(6) << it->getqty() << endl;
		}
	}
	if (!gearInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<GEARS>" << endl;
		for (auto it = gearInv.begin(); it != gearInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << right << setw(6) << it->getqty() << endl;
		}
	}
}
void character::displaystats() {
	std::cout << "STR: " << getstr() << endl;
	std::cout << "DEX: " << getdex() << endl;
	std::cout << "CON: " << getcon() << endl;
	std::cout << "INT: " << getint() << endl;
	std::cout << "WIS: " << getwis() << endl;
	std::cout << "CHA: " << getcha() << endl;
}
void character::report()
{
	if (name.size() > 20)
		std::cout << left << setw(20) << name.substr(0, 20) << "..";
	else
		std::cout << left << setw(22) << name;
	std::cout << "\t" << stats[5] << "\t" << stats[6] << "\t" << stats[7] << "\t" << stats[8] << "\t" << stats[9] << "\t" << stats[10] << endl;
}