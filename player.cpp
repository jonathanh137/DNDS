#include "player.h"

int Player::getLevel() const {
	return level;
}
string Player::getClass() const {
	switch (PCclass) {
	case barbarian: return "Barbarian";
	case bard: return "Bard";
	case cleric: return "Cleric";
	case druid: return "Druid";
	case fighter: return "Fighter";
	case monk: return "Monk";
	case paladin: return "Paladin";
	case ranger: return "Ranger";
	case rogue: return "Rogue";
	case sorcerer: return "Sorcerer";
	case warlock: return "Warlock";
	case wizard: return "Wizard";
	default:
		return "N/A";
	}
}
string Player::getBG() const {
	switch (bg) {
	case 1: return "Acolyte";
	case 2: return "Charlatan";
	case 3: return "Criminal";
	case 4: return "Entertainer";
	case 5: return "Folk Hero";
	case 6: return "Guild Artisan";
	case 7: return "Hermit";
	case 8: return "Noble";
	case 9: return "Outlander";
	case 10: return "Sage";
	case 11: return "Sailor";
	case 12: return "Soldier";
	case 13: return "Urchin";
	case 14: return "Spy";
	case 15: return "Gladiator";
	case 16: return "Guild Merchant";
	case 17: return "Knight";
	case 18: return "Pirate";
	default:
		return "N/A";
	}
}
string Player::getAge() const {
	return age;
}
float Player::getCarry() const {
	return carry;
}
string Player::getH() const {
	return height;
}
string Player::getW() const {
	return weight;
}
string Player::getEyes() const {
	return eyes;
}
string Player::getSkin() const {
	return skin;
}
string Player::getHair() const {
	return hair;
}
string Player::getSpec() const {
	return special;
}
int Player::getssProf(int index) {
	int result = 0;
	if (index == 0 || index == 9)
		result += calcmod(getstr());
	else if (index == 1 || index == 6 || index == 21 || index == 22)
		result += calcmod(getdex());
	else if (index == 2)
		result += calcmod(getcon());
	else if (index == 3 || index == 8 || index == 11 || index == 14 || index == 16 || index == 20)
		result += calcmod(getint());
	else if (index == 4 || index == 7 || index == 12 || index == 15 || index == 17 || index == 23)
		result += calcmod(getwis());
	else if (index == 5 || index == 10 || index == 13 || index == 18 || index == 19)
		result += calcmod(getcha());
	if (savingSkillsProf[index])
		result += profBonus();
	return result;
}

bool Player::addstr(int str, bool flag) {
	if (getstr() + str > 20) {
		if (!flag)
			setstr(20);
		return false;
	}
	stats[5] += str;
	return true;
}
bool Player::adddex(int dex, bool flag) {
	if (getdex() + dex > 20) {
		if (!flag)
			setdex(20);
		return false;
	}
	stats[6] += dex;
	return true;
}
bool Player::addcon(int con, bool flag) {
	if (getcon() + con > 20) {
		if (!flag)
			setcon(20);
		return false;
	}
	stats[7] += con;
	return true;
}
bool Player::addint(int Int, bool flag) {
	if (getint() + Int > 20) {
		if (!flag)
			setint(20);
		return false;
	}
	stats[8] += Int;
	return true;
}
bool Player::addwis(int wis, bool flag) {
	if (getwis() + wis > 20) {
		if (!flag)
			setwis(20);
		return false;
	}
	stats[9] += wis;
	return true;
}
bool Player::addcha(int cha, bool flag) {
	if (getcha() + cha > 20) {
		if (!flag)
			setcha(20);
		return false;
	}
	stats[10] += cha;
	return true;
}
void Player::classSkill() {
	int selector;
	bool flag;
	unordered_set<Feature>::iterator it;
	switch (PCclass) {
	case barbarian: //barbarian
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Animal Handling(1)\n  Athletics(2)\n  Intimidation(3)\n  Nature(4)\n  Perception(5)\n  Survival(6)" << endl;
				selector = intValid(7);
				switch (selector) {
				case 1:
					flag = setssProf(7, true);
					break;
				case 2:
					flag = setssProf(9, true);
					break;
				case 3:
					flag = setssProf(13, true);
					break;
				case 4:
					flag = setssProf(16, true);
					break;
				case 5:
					flag = setssProf(17, true);
					break;
				case 6:
					flag = setssProf(23, true);
					break;
				}
			}
		}
		break;
	case bard: //bard
		for (int i = 0; i < 3; i++) {
			if (i == 0)
				std::cout << "\nChoose Skill(1/3):";
			else if (i == 1)
				std::cout << "\nChoose Skill(2/3):";
			else
				std::cout << "\nChoose Skill(3/3):";
			std::cout << "\n  Acrobatics(1)\n  Animal Handling(2)\n  Arcana(3)\n  Athletics(4)\n  Deception(5)\n  History(6)\n  Insight(7)\n  Intimidation(8)\n  Investigation(9)\n  Medicine(10)\n  Nature(11)\n  Perception(12)\n  Performance(13)\n  Persuasion(14)\n  Religion(15)\n  Sleight of Hand(16)\n  Stealth(17)\n  Survival(18)" << endl;
			selector = intValid(19);
			setssProf(selector + 5);
		}
		break;
	case cleric:	//cleric
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  History(1)\n  Insight(2)\n  Medicine(3)\n  Persuasion(4)\n  Religion(5)" << endl;
				selector = intValid(6);
				switch (selector) {
				case 1:
					flag = setssProf(11, true);
					break;
				case 2:
					flag = setssProf(12, true);
					break;
				case 3:
					flag = setssProf(15, true);
					break;
				case 4:
					flag = setssProf(19, true);
					break;
				case 5:
					flag = setssProf(20, true);
					break;
				}
			}
		}
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Divine Domain: Knowledge"));
		if (it != classfeatures.end()) {
			for (int i = 0; i < 2; i++) {
				flag = false;
				while (!flag) {
					if (i == 0)
						std::cout << "\nChoose Skill(1/2):";
					else
						std::cout << "\nChoose Skill(1/2):";
					std::cout << "\n  Arcana(1)\n  History(2)\n  Nature(3)\n  Religion(4)" << endl;
					selector = intValid(5);
					switch (selector) {
					case 1:
						flag = setssProf(8, true);
						break;
					case 2:
						flag = setssProf(11, true);
						break;
					case 3:
						flag = setssProf(16, true);
						break;
					case 4:
						flag = setssProf(20, true);
						break;
					}
				}
			}
		}
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Divine Domain: Nature"));
		if (it != classfeatures.end()) {
			flag = false;
			while (!flag) {
				std::cout << "\nChoose Skill:\n  Animal Handling(1)\n  Nature(2)\n  Survival(3)" << endl;
				selector = intValid(4);
				switch (selector) {
				case 1:
					flag = setssProf(7, true);
					break;
				case 2:
					flag = setssProf(16, true);
					break;
				case 3:
					flag = setssProf(23, true);
					break;
				}
			}
		}
		break;
	case druid: //druid
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Arcana(1)\n  Animal Handling(2)\n  Insight(3)\n  Medicine(4)\n  Nature(5)\n  Perception(6)\n  Religion(7)\n  Survival(8)" << endl;
				selector = intValid(9);
				switch (selector) {
				case 1:
					flag = setssProf(8, true);
					break;
				case 2:
					flag = setssProf(7, true);
					break;
				case 3:
					flag = setssProf(12, true);
					break;
				case 4:
					flag = setssProf(15, true);
					break;
				case 5:
					flag = setssProf(16, true);
					break;
				case 6:
					flag = setssProf(17, true);
					break;
				case 7:
					flag = setssProf(20, true);
					break;
				case 8:
					flag = setssProf(23, true);
					break;
				}
			}
		}
		break;
	case fighter: //fighter
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Acrobatics(1)\n  Animal Handling(2)\n  Athletics(3)\n  History(4)\n  Insight(5)\n  Intimidation(6)\n  Perception(7)\n  Survival(8)" << endl;
				selector = intValid(9);
				switch (selector) {
				case 1:
					flag = setssProf(6, true);
					break;
				case 2:
					flag = setssProf(7, true);
					break;
				case 3:
					flag = setssProf(9, true);
					break;
				case 4:
					flag = setssProf(11, true);
					break;
				case 5:
					flag = setssProf(12, true);
					break;
				case 6:
					flag = setssProf(13, true);
					break;
				case 7:
					flag = setssProf(17, true);
					break;
				case 8:
					flag = setssProf(23, true);
					break;
				}
			}
		}
		break;
	case monk: //monk
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Acrobatics(1)\n  Athletics(2)\n  History(3)\n  Insight(4)\n  Religion(5)\n  Stealth(6)" << endl;
				selector = intValid(7);
				switch (selector) {
				case 1:
					flag = setssProf(6, true);
					break;
				case 2:
					flag = setssProf(9, true);
					break;
				case 3:
					flag = setssProf(11, true);
					break;
				case 4:
					flag = setssProf(12, true);
					break;
				case 5:
					flag = setssProf(20, true);
					break;
				case 6:
					flag = setssProf(22, true);
					break;
				}
			}
		}
		break;
	case paladin: //paladin
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Athletics(1)\n  Insight(2)\n  Intimidation(3)\n  Medicine(4)\n  Persuasion(5)\n  Religion(6)" << endl;
				selector = intValid(7);
				switch (selector) {
				case 1:
					flag = setssProf(9, true);
					break;
				case 2:
					flag = setssProf(12, true);
					break;
				case 3:
					flag = setssProf(13, true);
					break;
				case 4:
					flag = setssProf(15, true);
					break;
				case 5:
					flag = setssProf(19, true);
					break;
				case 6:
					flag = setssProf(20, true);
					break;
				}
			}
		}
		break;
	case ranger: //ranger
		for (int i = 0; i < 3; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/3):";
				else if (i == 1)
					std::cout << "\nChoose Skill(2/3):";
				else
					std::cout << "\nChoose Skill(3/3):";
				std::cout << "\n  Animal Handling(1)\n  Athletics(2)\n  Insight(3)\n  Investigation(4)\n  Nature(5)\n  Perception(6)\n  Stealth(7)\n  Survival(8)" << endl;
				selector = intValid(9);
				switch (selector) {
				case 1:
					flag = setssProf(7, true);
					break;
				case 2:
					flag = setssProf(9, true);
					break;
				case 3:
					flag = setssProf(12, true);
					break;
				case 4:
					flag = setssProf(14, true);
					break;
				case 5:
					flag = setssProf(16, true);
					break;
				case 6:
					flag = setssProf(17, true);
					break;
				case 7:
					flag = setssProf(22, true);
					break;
				case 8:
					flag = setssProf(23, true);
					break;
				}
			}
		}
		break;
	case rogue: //rogue
		for (int i = 0; i < 4; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/4):";
				else if (i == 1)
					std::cout << "\nChoose Skill(2/4):";
				else if (i == 2)
					std::cout << "\nChoose Skill(3/4):";
				else
					std::cout << "\nChoose Skill(4/4):";
				std::cout << "\n  Acrobatics(1)\n  Athletics(2)\n  Deception(3)\n  Insight(4)\n  Intimidation(5)\n  Investigation(6)\n  Perception(7)\n  Performance(8)\n  Persuasion(9)\n  Sleight of Hand(10)\n  Stealth(11)" << endl;
				selector = intValid(12);
				switch (selector) {
				case 1:
					flag = setssProf(6, true);
					break;
				case 2:
					flag = setssProf(9, true);
					break;
				case 3:
					flag = setssProf(10, true);
					break;
				case 4:
					flag = setssProf(12, true);
					break;
				case 5:
					flag = setssProf(13, true);
					break;
				case 6:
					flag = setssProf(14, true);
					break;
				case 7:
					flag = setssProf(17, true);
					break;
				case 8:
					flag = setssProf(18, true);
					break;
				case 9:
					flag = setssProf(19, true);
					break;
				case 10:
					flag = setssProf(21, true);
					break;
				case 11:
					flag = setssProf(22, true);
					break;
				}
			}
		}
		break;
	case sorcerer: //sorcerer
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Arcana(1)\n  Deception(2)\n  Insight(3)\n  Intimidation(4)\n  Persuasion(5)\n  Religion(6)" << endl;
				selector = intValid(7);
				switch (selector) {
				case 1:
					flag = setssProf(8, true);
					break;
				case 2:
					flag = setssProf(10, true);
					break;
				case 3:
					flag = setssProf(12, true);
					break;
				case 4:
					flag = setssProf(13, true);
					break;
				case 5:
					flag = setssProf(19, true);
					break;
				case 6:
					flag = setssProf(20, true);
					break;
				}
			}
		}
		break;
	case warlock: //warlock
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Arcana(1)\n  Deception(2)\n  History(3)\n  Intimidation(4)\n  Investigation(5)\n  Nature(6)\n  Religion(7)" << endl;
				selector = intValid(8);
				switch (selector) {
				case 1:
					flag = setssProf(8, true);
					break;
				case 2:
					flag = setssProf(10, true);
					break;
				case 3:
					flag = setssProf(11, true);
					break;
				case 4:
					flag = setssProf(13, true);
					break;
				case 5:
					flag = setssProf(14, true);
					break;
				case 6:
					flag = setssProf(16, true);
					break;
				case 7:
					flag = setssProf(20, true);
					break;
				}
			}
		}
		break;
	case wizard: //wizard
		for (int i = 0; i < 2; i++) {
			flag = false;
			while (!flag) {
				if (i == 0)
					std::cout << "\nChoose Skill(1/2):";
				else
					std::cout << "\nChoose Skill(2/2):";
				std::cout << "\n  Arcana(1)\n  History(2)\n  Insight(3)\n  Investigation(4)\n  Medicine(5)\n  Religion(6)" << endl;
				selector = intValid(7);
				switch (selector) {
				case 1:
					flag = setssProf(8, true);
					break;
				case 2:
					flag = setssProf(11, true);
					break;
				case 3:
					flag = setssProf(12, true);
					break;
				case 4:
					flag = setssProf(14, true);
					break;
				case 5:
					flag = setssProf(15, true);
					break;
				case 6:
					flag = setssProf(20, true);
					break;
				}
			}
		}
		break;
	}
}
void Player::addfeats() {
	int counter = 0;
	bool is_in = false;
	bool flag = false;
	bool statflag = false;
	bool metreq = true;
	bool temp = false;
	while (!flag) {
		std::cout << "\nChoose feat:\n  Alert(1)\n  Athlete(2)\n  Actor(3)\n  Charger(4)\n  Crossbow Expert(5)\n  Defensive Duelist(6)\n  Duel Wielder(7)\n  Dungeon Delver(8)\n  Durable(9)\n  Elemental Adept(10)\n  Grappler(11)\n  Great Weapon Master(12)\n  Healer(13)\n  Heavily Armored(14)\n  Heavy Armor Master(15)\n  Inspiring Leader(16)\n  Keen Mind(17)\n  Lightly Armored(18)\n  Linguist(19)\n  Lucky(20)\n  Mage Slayer(21)\n  Magic Initiate(22)\n  Martial Adept(23)\n  Medium Armor Master(24)\n  Mobile(25)\n  Moderately Armored(26)\n  Mounted Combatant(27)\n  Observant(28)\n  Polearm Master(29)\n  Resilient(30)\n  Ritual Caster(31)\n  Savage Attacker(32)\n  Sentinel(33)\n  Sharpshooter(34)\n  Shield Master(35)\n  Skilled(36)\n  Skulker(37)\n  Spell Sniper(38)\n  Tavern Brawler(39)\n  Tough(40)\n  War Caster(41)\n  Weapon Master(42)" << endl;
		int selector = intValid(43);
		switch (selector) {
		case 1:
			temp = addfeature("Alert", 7, "* You gain a +5 bonus to initiative.(added)\n* You can't be surprised while you are conscious.\n* Other creatures don't gain advantage on attack rolls against you as a result of being hidden from you.");
			if (temp)
				setinit(getinit() + 5);
			break;
		case 2:
			temp = addfeature("Athlete", 7, "* Increase your Strength or Dexterity score by 1, to a maximum of 20.(added)\n* When you are prone, standing up uses only 5 feet of your movement.\n* Climbing doesn't halve your speed.\n* You can make a running long jump or a running high jump after moving only 5 feet on foot, rather than 10 feet.");
			if (temp) {
				while (!statflag) {
					std::cout << "Choose Athlete increase:\n  STR(1)\n  DEX(2)" << endl;
					selector = intValid(3);
					if (selector == 1)
						statflag = addstr(1, true);
					else
						statflag = adddex(1, true);
					if (!statflag)
						std::cout << "Selected stat is already maxed..Choose another" << endl;
				}
			}
			break;
		case 3:
			temp = addfeature("Actor", 7, "* Increase your Charisma score by 1, to a maximum of 20.(added)\n* You have advantage on Charisma(Deception) and Charisma(Performance) checks when trying to pass yourself off as a different person.\n* You can mimic the speech of another person or the sounds made by other creatures. You must have heard the person speaking, or heard the creature make the sound, for at least 1 minute. A successful Wisdom(Insight) check contested by your Charisma(Deception) check allows a listener to determine that the effect is faked.");
			if (temp)
				addcha(1);
			break;
		case 4:
			temp = addfeature("Charger", 7, "When you use your action to Dash, you can use a bonus action to make one melee weapon attack or to shove a creature. If you move at least 10 feet in a straight line immediately before taking this bonus action, you either gain a +5 bonus to the attack's damage roll(if you chose to make a melee attack and hit) or push the target up to 10 feet away from you(if you chose to shove and you succeed).");
			break;
		case 5:
			temp = addfeature("Crossbow Expert", 7, "* You ignore the loading quality of crossbows with which you are proficient.\n* Being within 5 feet of a hostile creature doesn't impose disadvantage on your ranged attack rolls.\n* When you use the Attack action and attack with a one-handed weapon, you can use a bonus action to attack with a loaded hand crossbow you are holding.");
			break;
		case 6:
			if (getdex() > 12)
				temp = addfeature("Defensive Duelist", 7, "When you are wielding a finesse weapon with which you are proficient and another creature hits you with a melee attack, you can use your reaction to add your proficiency bonus to your AC for that attack, potentially causing the attack to miss you.");
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 7:
			temp = addfeature("Duel Wielder", 7, "* You gain a +1 bonus to AC while you are wielding a separate melee weapon in each hand.\n* You can use two-weapon fighting even when the one-handed melee weapons you are wielding aren't light.\n* You can draw or stow two one-handed weapons when you would normally be able to draw or stow only one.");
			break;
		case 8:
			temp = addfeature("Dungeon Delver", 7, "* You have advantage on Wisdom (Perception) and Intelligence(Investigation) checks made to detect the presence of secret doors.\n* You have advantage on saving throws made to avoid or resist traps.\n* You have resistance to the damage dealt by traps.\n* You can search for traps while traveling at a normal pace, instead of only at a slow pace.");
			break;
		case 9:
			temp = addfeature("Durable", 7, "* Increase your Constitution score by 1, to a maximum of 20.(added)\n* When you roll a Hit Die to regain hit points, the minimum number of hit points you regain from the roll equals twice your Constitution modifier(minimum of 2).");
			if (temp)
				addcon(1);
			break;
		case 10:
			is_in = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Spellcasting")) != classfeatures.end();
			if (!is_in)
				is_in = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Pact Magic")) != classfeatures.end();
			if (is_in) {
				string tempstring = "Elemental Adept: ";
				string tempdesc = "When you gain this feat, choose one of the following damage types : acid, cold, fire, lightning, or thunder.\nSpells you cast ignore resistance to damage of the chosen type. In addition, when you roll damage for a spell you cast that deals damage of that type, you can treat any 1 on a damage die as a 2.\nYou can select this feat multiple times.Each time you do so, you must choose a different damage type.";
				vector<string> tempType = { "Acid","Cold","Fire","Lightning","Thunder" };
				while (!temp) {
					std::cout << "Choose Elemental Adept type:" << endl;
					for (unsigned int i = 0; i < tempType.size(); i++)
						std::cout << "  " << tempType[i] << "(" << i + 1 << ")" << endl;
					selector = intValid(6);
					temp = addfeature(tempstring + tempType[selector - 1], 7, tempdesc);
					if (!temp)
						std::cout << "Type chosen already..Choose again" << endl;
				}
			}
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 11:
			if (getstr() > 12)
				temp = addfeature("Grappler", 7, "* You have advantage on attack rolls against a creature you are grappling.\n* You can use your action to try to pin a creature grappled by you. To do so, make another grapple check. If you succeed, you and the creature are both restrained until the grapple ends.\n* Creatures that are one size larger than you don't automatically succeed on checks to escape your grapple.");
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 12:
			temp = addfeature("Great Weapon Master", 7, "* On your turn, when you score a critical hit with a melee weapon or reduce a creature to 0 hit points with one, you can make one melee weapon attack as a bonus action.\n* Before you make a melee attack with a heavy weapon that you are proficient with, you can choose to take a -5 penalty to the attack roll. If the attack hits, you add +10 to the attack's damage.");
			break;
		case 13:
			temp = addfeature("Healer", 7, "* When you use a healer's kit to stabilize a dying creature, that creature also regains 1 hit point.\n* As an action, you can spend one use of a healer's kit to tend to a creature and restore 1d6 + 4 hit points to it, plus additional hit points equal to the creature's maximum number of Hit Dice. The creature can't regain hit points from this feat again until it finishes a short or long rest.");
			break;
		case 14:
			is_in = armorProf.find("Medium armor") != armorProf.end();
			if (!is_in)
				is_in = armorProf.find("All armor") != armorProf.end();
			if (is_in) {
				temp = addfeature("Heavily Armored", 7, "* Increase your Strength score by 1, to a maximum of 20.(added)\n* You gain proficiency with heavy armor.(added)");
				if (temp) {
					addstr(1);
					addfeature("Heavy armor", 5);
				}
			}
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 15:
			is_in = armorProf.find("Heavy armor") != armorProf.end();
			if (!is_in)
				is_in = armorProf.find("All armor") != armorProf.end();
			if (is_in) {
				temp = addfeature("Heavy Armor Master", 7, "* Increase your Strength score by 1, to a maximum of 20.(added)\n* While you are wearing heavy armor, bludgeoning, piercing, and slashing damage that you take from non magical weapons is reduced by 3.");
				if (temp)
					addstr(1);
			}
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 16:
			if (getcha() > 12)
				temp = addfeature("Inspiring Leader", 7, "You can spend 10 minutes inspiring your companions, shoring up their resolve to fight. When you do so, choose up to six friendly creatures(which can include yourself) within 30 feet of you who can see or hear you and who can understand you. Each creature can gain temporary hit points equal to your level + your Charisma modifier. A creature can't gain temporary hit points from this feat again until it has finished a short or long rest.");
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 17:
			temp = addfeature("Keen Mind", 7, "* Increase your Intelligence score by 1, to a maximum of 20.(added)\n* You always know which way is north.\n* You always know the number of hours left before the next sunrise or sunset.\n* You can accurately recall anything you have seen or heard within the past month.");
			if (temp)
				addint(1);
			break;
		case 18:
			temp = addfeature("Lightly Armored", 7, "* Increase your Strength or Dexterity score by 1, to a maximum of 20.(added)\n* You gain proficiency with light armor.(added)");
			if (temp) {
				while (!statflag) {
					std::cout << "Choose Lightly Armored increase:\n  STR(1)\n  DEX(2)" << endl;
					selector = intValid(3);
					if (selector == 1)
						statflag = addstr(1, true);
					else
						statflag = adddex(1, true);
					if (!statflag)
						std::cout << "Selected stat is already maxed..Choose another" << endl;
				}
				addfeature("Light armor", 5);
			}
			break;
		case 19:
			temp = addfeature("Linguist", 7, "* Increase your Intelligence score by 1, to a maximum of 20.(added)\n* You learn three languages of your choice.(added)\n* You can ably create written ciphers. Others can't decipher a code you create unless you teach them, they succeed on an Intelligence check(DC equal to your Intelligence score + your proficiency bonus), or they use magic to decipher it.");
			if (temp) {
				addint(1);
				addlang(3);
			}
			break;
		case 20:
			temp = addfeature("Lucky", 7, "You have 3 luck points. Whenever you make an attack roll, an ability check, or a saving throw, you can spend one luck point to roll an additional d20. You can choose to spend one of your luck points after you roll the die, but before the outcome is determined. You choose which of the d20s is used for the attack roll, ability check, or saving throw.\nYou can also spend one luck point when an attack roll is made against you. Roll a d20, and then choose whether the attack uses the attacker's roll or yours. If more than one creature spends a luck point to influence the outcome of a roll, the points cancel each other out; no additional dice are rolled.\nYou regain your expended luck points when you finish a long rest.(added)");
			if (temp) {
				addresource("Luck Point", 3, 2);
			}
			break;
		case 21:
			temp = addfeature("Mage Slayer", 7, "* When a creature within 5 feet of you casts a spell, you can use your reaction to make a melee weapon attack against that creature.\n* When you damage a creature that is concentrating on a spell, that creature has disadvantage on the saving throw it makes to maintain its concentration.\n* You have advantage on saving throws against spells cast by creatures within 5 feet of you.");
			break;
		case 22:
			temp = addfeature("Magic Initiate", 7, "Choose a class: bard, cleric, druid, sorcerer, warlock, or wizard. You learn two cantrips of your choice from that class's spell list.(added)\nIn addition, choose one 1st-level spell from that same list. You learn that spell and can cast it at its lowest level.(added) Once you cast it, you must finish a long rest before you can cast it again.\nYour spellcasting ability for these spells depends on the class you chose : Charisma for bard, sorcerer, or warlock; Wisdom for cleric or druid: or Intelligence for wizard.");
			cout << "\nChoose class spell list:\n  Bard(1)\n  Cleric(2)\n  Druid(3)\n  Sorcerer(4)\n  Warlock(5)\n  Wizard(6)" << endl;
			selector = intValid(7);
			switch (selector) {
			case 1:
				SpellsbyClass(2, bard, 0);
				SpellsbyClass(1, bard, 1);
				break;
			case 2:
				SpellsbyClass(2, cleric, 0);
				SpellsbyClass(1, cleric, 1);
				break;
			case 3:
				SpellsbyClass(2, druid, 0);
				SpellsbyClass(1, druid, 1);
				break;
			case 4:
				SpellsbyClass(2, sorcerer, 0);
				SpellsbyClass(1, sorcerer, 1);
				break;
			case 5:
				SpellsbyClass(2, warlock, 0);
				SpellsbyClass(1, warlock, 1);
				break;
			case 6:
				SpellsbyClass(2, wizard, 0);
				SpellsbyClass(1, wizard, 1);
				break;
			default:
				cout << "Invalid selection "<< endl;
				break;
			}
			break;
		case 23:
			temp = addfeature("Martial Adept", 7, "* You learn two maneuvers of your choice from among those available to the Battle Master archetype in the fighter class. If a maneuver you use requires your target to make a saving throw to resist the maneuver's effects, the saving throw DC equals 8 + your proficiency bonus + your Strength or Dexterity modifier(your choice).(added)\n* If you already have superiority dice, you gain one more; otherwise, you have one superiority die, which is a d6. This die is used to fuel your maneuvers. A superiority die is expended when you use it. You regain your expended superiority dice when you finish a short or long rest.(added)");
			if (temp) {
				vector<string> choices = { "Commander's Strike","Disarming Attack","Distracting Strike","Evasive Footwork","Feinting Attack","Goading Attack","Lunging Attack","Maneuvering Attack","Menacing Attack","Parry","Precision Attack","Pushing Attack","Rally","Riposte","Sweeping Attack","Trip Attack" };
				vector<string> desc = { "When you take the Attack action on your turn, you can forgo one of your attacks and use a bonus action to direct one of your companions to strike. When you do so, choose a friendly creature who can see or hear you and expend one superiority die. That creature can immediately use its reaction to make one weapon attack, adding the superiority die to the attack's damage roll.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to attempt to disarm the target, forcing it to drop one item of your choice that it's holding. You add the superiority die to the attack's damage roll, and the target must make a Strength saving throw. On a failed save, it drops the object you choose. The object lands at its feet.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to distract the creature, giving your allies an opening. You add the superiority die to the attack's damage roll. The next attack roll against the target by an attacker other than you has advantage if the attack is made before the start of your next turn.",
					"When you move, you can expend one superiority die, rolling the die and adding the number rolled to your AC until you stop moving.",
					"You can expend one superiority die and use a bonus action on your turn to feint, choosing one creature within 5 feet of you as your target. You have advantage on your next attack roll against that creature. If that attack hits, add the superiority die to the attack's damage roll.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to attempt to goad the target into attacking you. You add the superiority die to the attack's damage roll, and the target must make a Wisdom saving throw. On a failed save, the target has disadvantage on all attack rolls against targets other than you until the end of your next turn.",
					"When you make a melee weapon attack on your turn, you can expend one superiority die to increase your reach for that attack by 5 feet. If you hit, you add the superiority die to the attack's damage roll.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to maneuver one of your comrades into a more advantageous position. You add the superiority die to the attack's damage roll, and you choose a friendly creature who can see or hear you. That creature can use its reaction to move up to half its speed without provoking opportunity attacks from the target of your attack.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to attempt to frighten the target. You add the superiority die to the attack's damage roll, and the target must make a Wisdom saving throw. On a failed save, it is frightened of you until the end of your next turn.",
					"When another creature dam ages you with a melee attack, you can use your reaction and expend one superiority die to reduce the damage by the number you roll on your superiority die + your Dexterity modifier.",
					"When you make a weapon attack roll against a creature, you can expend one superiority die to add it to the roll. You can use this maneuver before or after making the attack roll, but before any effects of the attack are applied.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to attempt to drive the target back. You add the superiority die to the attack's dam age roll, and if the target is Large or smaller, it must make a Strength saving throw. On a failed save, you push the target up to 15 feet away from you.",
					"On your turn, you can use a bonus action and expend one superiority die to bolster the resolve of one of your companions. When you do so, choose a friendly creature who can see or hear you. That creature gains temporary hit points equal to the superiority die roll + your Charisma modifier.",
					"When a creature misses you with a melee attack, you can use your reaction and expend one superiority die to make a melee weapon attack against the creature. If you hit, you add the superiority die to the attack's damage roll.",
					"When you hit a creature with a melee weapon attack, you can expend one superiority die to attempt to damage another creature with the same attack. Choose another creature within 5 feet of the original target and within your reach. If the original attack roll would hit the second creature, it takes damage equal to the number you roll on your superiority die. The damage is of the same type dealt by the original attack.",
					"When you hit a creature with a weapon attack, you can expend one superiority die to attempt to knock the target down. You add the superiority die to the attack's damage roll, and if the target is Large or smaller, it must make a Strength saving throw. On a failed save, you knock the target prone." };
				for (int i = 0; i < 2; i++) {
					temp = false;
					while (!temp) {
						if (i == 0)
							std::cout << "Choose Martial Adept Maneuver(1/2):";
						else
							std::cout << "Choose Martial Adept Maneuver(2/2):";
						for (unsigned int j = 0; j < choices.size(); j++)
							std::cout << "  " << choices[j] << "(" << j + 1 << ")" << endl;
						selector = intValid(17);
						string s = "Maneuver: " + choices[selector - 1];
						temp = addfeature(s, 0, desc[selector - 1]);
						if (!temp)
							std::cout << "Maneuver already known..Choose again" << endl;
					}
				}
				addresource("Superiority dice(d6)", 1, 0);
			}
			break;
		case 24:
			is_in = armorProf.find("Medium armor") != armorProf.end();
			if (!is_in)
				is_in = armorProf.find("All armor") != armorProf.end();
			if (is_in)
				temp = addfeature("Medium Armor Master", 7, "* Wearing medium armor doesn't impose disadvantage on your Dexterity(Stealth) checks.\n* When you wear medium armor, you can add 3, rather than 2, to your AC if you have a Dexterity of 16 or higher");
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 25:
			temp = addfeature("Mobile", 7, "* Your speed increases by 10 feet.(added)\n* When you use the Dash action, difficult terrain doesn't cost you extra movement on that turn.\n* When you make a melee attack against a creature, you don't provoke opportunity attacks from that creature for the rest of the turn, whether you hit or not.");
			if (temp)
				addspd(10);
			break;
		case 26:
			is_in = armorProf.find("Light armor") != armorProf.end();
			if (!is_in)
				is_in = armorProf.find("All armor") != armorProf.end();
			if (is_in) {
				temp = addfeature("Moderately Armored", 7, "* Increase your Strength or Dexterity score by 1, to a maximum of 20.(added)\n* You gain proficiency with medium armor and shields.(added)");
				if (temp) {
					while (!statflag) {
						std::cout << "Choose Moderately Armored increase:\n  STR(1)\n  DEX(2)" << endl;
						selector = intValid(3);
						if (selector == 1)
							statflag = addstr(1, true);
						else
							statflag = adddex(1, true);
						if (!statflag)
							std::cout << "Selected stat is already maxed..Choose another" << endl;
					}
					addfeature("Medium armor", 5);
					addfeature("Shield", 5);
				}
			}
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 27:
			temp = addfeature("Mounted Combatant", 7, "* You have advantage on melee attack rolls against any unmounted creature that is smaller than your mount.\n* You can force an attack targeted at your mount to target you instead.\n* If your mount is subjected to an effect that allows it to make a Dexterity saving throw to take only half damage, it instead takes no damage if it succeeds on the saving throw, and only half damage if it fails.");
			break;
		case 28:
			temp = addfeature("Observant", 7, "* Increase your Intelligence or Wisdom score by 1, to a maximum of 20.(added)\n* If you can see a creature's mouth while it is speaking a language you understand, you can interpret what it's saying by reading its lips.\n* You have a +5 bonus to your passive Wisdom(Perception) and passive Intelligence(Investigation) scores.(added)");
			if (temp) {
				while (!statflag) {
					std::cout << "Choose Moderately Armored increase:\n  INT(1)\n  WIS(2)" << endl;
					selector = intValid(3);
					if (selector == 1)
						statflag = addint(1, true);
					else
						statflag = addwis(1, true);
					if (!statflag)
						std::cout << "Selected stat is already maxed..Choose another" << endl;
				}
				setpasper(getpasper() + 5);
			}
			break;
		case 29:
			temp = addfeature("Polearm Master", 7, "* When you take the Attack action and attack with only a glaive, halberd, or quarterstaff, you can use a bonus action to make a melee attack with the opposite end of the weapon. The weapon's damage die for this attack is a d4, and the attack deals bludgeoning damage.\n* While you are wielding a glaive, halberd, pike, or quarterstaff, other creatures provoke an opportunity attack from you when they enter your reach.");
			break;
		case 30:
			temp = addfeature("Resilient", 7, "* Increase the chosen ability score by 1, to a maximum of 20.(added)\n* You gain proficiency in saving throws using the chosen ability.(added)");
			if (temp) {
				while (!statflag) {
					std::cout << "Choose Resilient increase:\n  STR(1)\n  DEX(2)\n  CON(3)\n  INT(4)\n  WIS(5)\n  CHA(6)" << endl;
					selector = intValid(7);
					switch (selector) {
					case 1:
						statflag = addstr(1, true);
						savingSkillsProf[0] = true;
						break;
					case 2:
						statflag = adddex(1, true);
						savingSkillsProf[1] = true;
						break;
					case 3:
						statflag = addcon(1, true);
						savingSkillsProf[2] = true;
						break;
					case 4:
						statflag = addint(1, true);
						savingSkillsProf[3] = true;
						break;
					case 5:
						statflag = addwis(1, true);
						savingSkillsProf[4] = true;
						break;
					case 6:
						statflag = addcha(1, true);
						savingSkillsProf[5] = true;
						break;
					}
					if (!statflag)
						std::cout << "Selected stat is already maxed..Choose another" << endl;
				}
			}
			break;
		case 31:
			if (getint() > 12 || getwis() > 12)
				temp = addfeature("Ritual Caster", 7, "You have learned a number of spells that you can cast as rituals. These spells are written in a ritual book, which you must have in hand while casting one of them.\nWhen you choose this feat, you acquire a ritual book holding two 1st-level spells of your choice. Choose one of the following classes: bard, cleric, druid, sorcerer, warlock, or wizard. You must choose your spells from that class's spell list, and the spells you choose must have the ritual tag. The class you choose also determines your spellcasting ability for these spells: Charisma for bard, sorcerer, or warlock; Wisdom for cleric or druid; or Intelligence for wizard.\nIf you come across a spell in written form, such as a magical spell scroll or a wizard's spellbook, you might be able to add it to your ritual book. The spell must be on the spell list for the class you chose, the spell's level can be no higher than half your level(rounded up), and it must have the ritual tag.The process of copying the spell into your ritual book takes 2 hours per level of the spell, and costs 50 gp per level.The cost represents material components you expend as you experiment with the spell to master it, as well as the fine inks you need to record it.");
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 32:
			temp = addfeature("Savage Attacker", 7, "Once per turn when you roll damage for a melee weapon attack, you can reroll the weapon's damage dice and use either total.");
			break;
		case 33:
			temp = addfeature("Sentinel", 7, "* When you hit a creature with an opportunity attack, the creature's speed becomes 0 for the rest of the turn.\n* Creatures within 5 feet of you provoke opportunity attacks from you even if they take the Disengage action before leaving your reach.\n* When a creature within 5 feet of you makes an attack against a target other than you(and that target doesn't have this feat), you can use your reaction to make a melee weapon attack against the attacking creature.");
			break;
		case 34:
			temp = addfeature("Sharpshooter", 7, "* Attacking at long range doesn't impose disadvantage on your ranged weapon attack rolls.\n* Your ranged weapon attacks ignore half cover and three-quarters cover.\n* Before you make an attack with a ranged weapon that you are proficient with, you can choose to take a -5 penalty to the attack roll. If the attack hits, you add +10 to the attack's damage.");
			break;
		case 35:
			temp = addfeature("Shield Master", 7, "* If you take the Attack action on your turn, you can use a bonus action to try to shove a creature within 5 feet of you with your shield.\n* If you aren't incapacitated, you can add your shield's AC bonus to any Dexterity saving throw you make against a spell or other harmful effect that targets only you.\n* If you are subjected to an effect that allows you to make a Dexterity saving throw to take only half damage, you can use your reaction to take no damage if you succeed on the saving throw, interposing your shield between yourself and the source of the effect.");
			break;
		case 36:
			temp = addfeature("Skilled", 7, "You gain proficiency in any combination of three skills or tools of your choice.(added)");
			if (temp) {
				for (int i = 0; i < 3; i++) {
					if (i == 0)
						std::cout << "Choose Skilled proficiency(1/3):";
					else if (i == 1)
						std::cout << "Choose Skilled proficiency(2/3):";
					else
						std::cout << "Choose Skilled proficiency(3/3):";
					std::cout << "\n  Skills(1)\n  Tools(2)" << endl;
					selector = intValid(3);
					if (selector == 1) {
						std::cout << "\nChoose Skill:\n  Acrobatics(1)\n  Animal Handling(2)\n  Arcana(3)\n  Athletics(4)\n  Deception(5)\n  History(6)\n  Insight(7)\n  Intimidation(8)\n  Investigation(9)\n  Medicine(10)\n  Nature(11)\n  Perception(12)\n  Performance(13)\n  Persuasion(14)\n  Religion(15)\n  Sleight of Hand(16)\n  Stealth(17)\n  Survival(18)" << endl;
						selector = intValid(19);
						setssProf(selector + 5);
					}
					else
						addToolProf();
				}
			}
			break;
		case 37:
			if (getdex() > 12)
				temp = addfeature("Skulker", 7, "* You can try to hide when you are lightly obscured from the creature from which you are hiding.\n* When you are hidden from a creature and miss it with a ranged weapon attack, making the attack doesn't reveal your position.\n* Dim light doesn't impose disadvantage on your Wisdom(Perception) checks relying on sight.");
			break;
		case 38:
			is_in = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Spellcasting")) != classfeatures.end();
			if (!is_in)
				is_in = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Pact Magic")) != classfeatures.end();
			if (is_in) {
				vector<string> cantrip;
				spellAbility sA;
				temp = addfeature("Spell Sniper", 7, "* When you cast a spell that requires you to make an attack roll, the spell's range is doubled.\n* Your ranged spell attacks ignore half cover and three-quarters cover.\n* You learn one cantrip that requires an attack roll. Choose the cantrip from the bard, cleric, druid, sorcerer, warlock, or wizard spell list. Your spellcasting ability for this cantrip depends on the spell list you chose from: Charisma for bard, sorcerer, or warlock; Wisdom for cleric or druid; or Intelligence for wizard.(added)");
				while (cantrip.size() == 0) {
					cout << "\nChoose class spell list:\n  Bard(1)\n  Cleric(2)\n  Druid(3)\n  Sorcerer(4)\n  Warlock(5)\n  Wizard(6)" << endl;
					selector = intValid(7);
					switch (selector) {
					case 1: //bard
						cout << "Bards do not have any cantrips with an attack roll..Choose again" << endl;
						//sA = CHA;
						break;
					case 2: // cleric
						cout << "Clerics do not have any cantrips with an attack roll..Choose again" << endl;
						//sA = WIS;
						break;
					case 3: // druid
						cantrip = { "Produce Flame","Thorn Whip" };
						sA = WIS;
						break;
					case 4: // sorcerer
						cantrip = { "Chill Touch","Fire Bolt","Ray of Frost","Shocking Grasp" };
						sA = CHA;
						break;
					case 5: // warlock
						cantrip = { "Chill Touch","Eldritch Blast" };
						sA = CHA;
						break;
					case 6: // wizard
						cantrip = { "Chill Touch","Fire Bolt","Ray of Frost","Shocking Grasp" };
						sA = INTEL;
						break;
					default:
						cout << "Invalid selection" << endl;
						break;
					}
				}
				int ctr = 1;
				bool flag;
				while (ctr <= 1) {
					flag = false;
					std::cout << "\nChoose a cantrip(" << ctr << "/1):" << endl;
					for (unsigned int i = 0; i < cantrip.size(); i++)
						std::cout << "  " << cantrip[i] << "(" << i + 1 << ")" << endl;
					int selector = intValid(cantrip.size() + 1);
					flag = spellLookup(cantrip[selector - 1], sA);
					if (!flag)
						std::cout << "..choose again" << endl;
					else
						ctr++;
				}
			}
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 39:
			temp = addfeature("Tavern Brawler", 7, "* Increase your Strength or Constitution score by 1, to a maximum of 20.(added)\n* You are proficient with improvised weapons and unarmed strikes.(added)\n* Your unarmed strike uses a d4 for damage.\n* When you hit a creature with an unarmed strike or an improvised weapon on your turn, you can use a bonus action to attempt to grapple the target.");
			if (temp) {
				while (!statflag) {
					std::cout << "Choose Tavern Brawler increase:\n  STR(1)\n  CON(2)" << endl;
					selector = intValid(3);
					if (selector == 1)
						statflag = addstr(1, true);
					else
						statflag = addcon(1, true);
					if (!statflag)
						std::cout << "Selected stat is already maxed..Choose another" << endl;
				}
				addfeature("Improvised", 4);
				addfeature("Unarmed", 4);
			}
			break;
		case 40:
			temp = addfeature("Tough", 7, "Your hit point maximum increases by an amount equal to twice your level when you gain this feat. Whenever you gain a level thereafter, your hit point maximum increases by an additional 2 hit points.(added)");
			if (temp)
				addmaxhp(getLevel() * 2);
			break;
		case 41:
			is_in = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Spellcasting")) != classfeatures.end();
			if (!is_in)
				is_in = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Pact Magic")) != classfeatures.end();
			if (is_in)
				temp = addfeature("War Caster", 7, "* You have advantage on Constitution saving throws that you make to maintain your concentration on a spell when you take damage.\n* You can perform the somatic components of spells even when you have weapons or a shield in one or both hands.\n* When a hostile creature's movement provokes an opportunity attack from you, you can use your reaction to cast a spell at the creature, rather than making an opportunity attack. The spell must have a casting time of 1 action and must target only that creature.");
			else {
				std::cout << "Requirement not met" << endl;
				metreq = false;
			}
			break;
		case 42:
			temp = addfeature("Weapon Master", 7, "* Increase your Strength or Dexterity score by 1, to a maximum of 20.(added)\n* You gain proficiency with four weapons of your choice.(added)");
			if (temp) {
				while (!statflag) {
					std::cout << "Choose Weapon Master increase:\n  STR(1)\n  DEX(2)" << endl;
					selector = intValid(3);
					if (selector == 1)
						statflag = addstr(1, true);
					else
						statflag = adddex(1, true);
					if (!statflag)
						std::cout << "Selected stat is already maxed..Choose another" << endl;
				}
				addWeaponProf(4);
			}
			break;
		}
		if (temp)
			flag = true;
		if (!temp && metreq)
			std::cout << "Feat already known..Please choose another" << endl;
	}
}
void Player::featAdder() {
	if (getRace() == "Human(Variant)")
		addfeats();
}
void Player::setBG(int BG, bool money) {
	bg = BG;
	int selector = 0;
	switch (bg) {
	case 1: // "Acolyte"
		setssProf(12);
		setssProf(20);
		addfeature("Shelter of the Faithful", 2, "As an acolyte, you command the respect of those who share your faith, and you can perform the religious ceremonies of your deity. You and your adventuring companions can expect to receive free healing and care at a temple, shrine, or other established presence of your faith, though you must provide any material components needed for spells. Those who share your religion will support you(but only you) at a modest lifestyle.\nYou might also have ties to a specific temple dedicated to your chosen deity or pantheon, and you have a residence there. This could be the temple where you used to serve, if you remain on good terms with it, or a temple where you have found a new home. While near your temple, you can call upon the priests for assistance, provided the assistance you ask for is not hazardous and you remain in good standing with your temple.");
		addlang(2);
		if (!money) {
			std::cout << "\nChoose Holy Symbol:\n  Amulet(1)\n  Emblem(2)\n  Reliquary(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addGear("Holy Symbol: Amulet", 1.0f);
				break;
			case 2:
				addGear("Holy Symbol: Emblem");
				break;
			case 3:
				addGear("Holy Symbol: Reliquary", 2.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Prayer book(1)\n  Prayer wheel(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addGear("Prayer book");
				break;
			case 2:
				addGear("Prayer wheel");
				break;
			}
			addGear("Incense(Stick)", 0.0f, 5);
			addGear("Vestments", 6.0f);
			addGear("Common clothes set", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(15);
		}
		break;
	case 2: // "Charlatan"
		setssProf(10);
		setssProf(21);
		addfeature("Disguise kit", 6);
		addfeature("Forgery kit", 6);
		addfeature("False Identity", 2, "You have created a second identity that includes documentation, established acquaintances, and disguises that allow you to assume that persona. Additionally, you can forge documents including official papers and personal letters, as long as you have seen an example of the kind of document or the handwriting you are trying to copy.");
		addGear("Fine clothes set", 6.0f);
		addTool("Disguise kit", 3.0f);
		if (!money) {
			std::cout << "\nChoose Con Tool:\n  Ten stoppered bottles filled with colored liquid(1)\n  Set of weighted dice(2)\n  Deck of marked cards(3)\n  Signet ring of an imaginary duke(4)" << endl;
			selector = intValid(5);
			switch (selector) {
			case 1:
				addTool("Con Tool: Ten stoppered bottles filled with colored liquid");
				break;
			case 2:
				addTool("Con Tool: Set of weighted dice");
				break;
			case 3:
				addTool("Con Tool: Deck of marked cards");
				break;
			case 4:
				addTool("Con Tool: Signet ring of an imaginary duke");
				break;
			}
			addGear("Pouch(Belt)", 1.0f);
			addGp(15);
		}
		break;
	case 3: // "Criminal"
		setssProf(10);
		setssProf(22);
		std::cout << "\nChoose Variant: Spy?\n  No(1)\n  Yes(2)" << endl;
		selector = intValid(3);
		if (selector == 2)
			bg = 14;
		addGamingProf();
		addfeature("Thieves' tools", 6);
		addfeature("Criminal Contact", 2, "You have a reliable and trustworthy contact who acts as your liaison to a network of other criminals. You know how to get messages to and from your contact, even over great distances; specifically, you know the local messengers, corrupt caravan masters, and seedy sailors who can deliver messages for you.");
		if (!money) {
			addGear("Crowbar", 5.0f);
			addGear("Dark common clothes set with hood", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(15);
		}
		break;
	case 4: // "Entertainer"
		setssProf(6);
		setssProf(18);
		std::cout << "\nChoose Variant:Gladiator?\n  No(1)\n  Yes(2)" << endl;
		selector = intValid(3);
		if (selector == 2) {
			bg = 15;
			addfeature("By Popular Demand", 2, "You can find a place to perform in any place that features combat for entertainment, perhaps a gladiatorial arena or secret pit fighting club. At such a place, you receive free lodging and food of a modest or comfortable standard(depending on the quality of the establishment), as long as you perform each night. In addition, your performance makes you something of a local figure. When strangers recognize you in a town where you have performed, they typically take a liking to you.");
		}
		else
			addfeature("By Popular Demand", 2, "You can always find a place to perform, usually in an inn or tavern but possibly with a circus, at a theater, or even in a noble's court. At such a place, you receive free lodging and food of a modest or comfortable standard(depending on the quality of the establishment), as long as you perform each night. In addition, your performance makes you something of a local figure. When strangers recognize you in a town where you have performed, they typically take a liking to you.");
		addfeature("Disguise kit", 6);
		addInstrumProf();

		if (!money) {
			if (bg == 15) {
				std::cout << "\nChoose Gladiator weapon:\n  Trident(1)\n  Net(2)\n  Whip(3)" << endl;
				selector = intValid(4);
				switch (selector) {
				case 1:
					addWeapon("Trident", 4.0F);
					break;
				case 2:
					addWeapon("Net", 3.0F);
					break;
				case 3:
					addWeapon("Whip", 3.0F);
					break;
				}
			}
			else
				addInstrum();
			std::cout << "Choose Admirer's Favor:\n  Love letter(1)\n  Lock of hair(2)\n  Trinket(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addGear("Admirer's love letter");
				break;
			case 2:
				addGear("Admirer's lock of hair");
				break;
			case 3:
				addGear("Admirer's trinket");
				break;
			}
			addGear("Costume", 4.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(15);
		}
		break;
	case 5: // "Folk Hero"
		setssProf(7);
		setssProf(23);
		addArtToolProf();
		addfeature("Vehicles(Land)", 6);
		addfeature("Rustic Hospitality", 2, "Since you come from the ranks of the common folk, you fit in among them with ease. You can find a place to hide, rest, or recuperate among other commoners, unless you have shown yourself to be a danger to them. They will shield you from the law or anyone else searching for you, though they will not risk their lives for you.");
		if (!money) {
			addArtTool();
			addGear("Shovel", 5.0f);
			addGear("Iron pot", 10.0f);
			addGear("Common clothes set", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(10);
		}
		break;
	case 6: // "Guild Artisan"
		setssProf(12);
		setssProf(19);
		std::cout << "\nChoose Variant:Guild Merchant?\n  No(1)\n  Yes(2)" << endl;
		selector = intValid(3);
		if (selector == 2) {
			bg = 16;
			std::cout << "\nChoose Proficiency option:" << endl;
			std::cout << "  Navigator's tools proficiency(1)\n  Additional language(2)" << endl;
			selector = intValid(3);
			if (selector == 1) {
				addfeature("Navigator's tools", 6);
			}
			else {
				addlang();
			}
		}
		else
			addArtToolProf();
		addfeature("Guild Membership", 2, "As an established and respected member of a guild, you can rely on certain benefits that membership provides. Your fellow guild members will provide you with lodging and food if necessary, and pay for your funeral if needed. In some cities and towns, a guildhall offers a central place to meet other members of your profession, which can be a good place to meet potential patrons, allies, or hirelings.\nGuilds often wield tremendous political power. If you are accused of a crime, your guild will support you if a good case can be made for your innocence or the crime is justifiable. You can also gain access to powerful political figures through the guild, if you are a member in good standing. Such connections might require the donation of money or magic items to the guild's coffers.\nYou must pay dues of 5 gp per month to the guild. If you miss payments, you must make up back dues to remain in the guild's good graces.");
		addlang();
		if (!money) {
			if (bg == 16) {
				addMount("Mule", "Land", 40, 420);
				storeItemMount("Mule", "Cart", 200, 1, 3);
			}
			else
				addArtTool();
			addGear("Guild letter of introduction");
			addGear("Traveler's clothes set", 4.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(15);
		}
		break;
	case 7: // "Hermit"
		setssProf(15);
		setssProf(20);
		addfeature("Herbalism kit", 6);
		addfeature("Discovery", 2, "The quiet seclusion of your extended hermitage gave you access to a unique and powerful discovery. The exact nature of this revelation depends on the nature of your seclusion. It might be a great truth about the cosmos, the deities, the powerful beings of the outer planes, or the forces of nature. It could be a site that no one else has ever seen. You might have uncovered a fact that has long been forgotten, or unearthed some relic of the past that could rewrite history. It might be information that would be damaging to the people who or consigned you to exile, and hence the reason for your return to society.\nWork with your DM to determine the details of your discovery and its impact on the campaign.");
		addlang();
		if (!money) {
			addGear("Scroll case stuffed full of notes from your studies or prayers", 1.0f);
			addGear("Blanket(Winter)", 3.0f);
			addGear("Common clothes set", 3.0f);
			addTool("Herbalism kit", 3.0f);
			addGp(5);
		}
		break;
	case 8: // "Noble"
		setssProf(11);
		setssProf(19);
		std::cout << "\nChoose Variant:Knight?\n  No(1)\n  Yes(2)" << endl;
		selector = intValid(3);
		if (selector == 2) {
			bg = 17;
			addfeature("Retainers", 2, "You have the service of three retainers loyal to your family. These retainers can be attendants or messengers, and one might be a majordomo. Your retainers are commoners who can perform mundane tasks for you, but they do not fight for you, will not follow you into obviously dangerous areas(such as dungeons), and will leave if they are frequently endangered or abused.");
			addGear("Noble lord/lady's token");
		}
		else
			addfeature("Position of Privilege", 2, "Thanks to your noble birth, people are inclined to think the best of you. You are welcome in high society, and people assume you have the right to be wherever you are. The common folk make every effort to accommodate you and avoid your displeasure, and other people of high birth treat you as a member of the same social sphere. You can secure an audience with a local noble if you need to.");
		addGamingProf();
		addlang();
		if (!money) {
			addGear("Fine clothes set", 6.0f);
			addGear("Signet ring");
			addGear("Pedigree scroll");
			addGear("Purse", 1.0f);
			addGp(25);
		}
		break;
	case 9: // "Outlander"
		setssProf(9);
		setssProf(23);
		addInstrumProf();
		addfeature("Wanderer", 2, "You have an excellent memory for maps and geography, and you can always recall the general layout of terrain, settlements, and other features around you. In addition, you can find food and fresh water for yourself and up to five other people each day, provided that the land offers berries, small game, water, and so forth.");
		addlang();
		if (!money) {
			addGear("Arcane focus: Staff", 4.0f);
			addGear("Hunting trap", 25.0f);
			addGear("Animal trophy");
			addGear("Traveler's clothes set", 4.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(10);
		}
		break;
	case 10: // "Sage"
		setssProf(8);
		setssProf(11);
		addfeature("Researcher", 2, "When you attempt to learn or recall a piece of lore, if you do not know that information, you often know where and from whom you can obtain it. Usually, this information comes from a library, scriptorium, university, or a sage or other learned person or creature. Your DM might rule that the knowledge you seek is secreted away in an almost inaccessible place, or that it simply cannot be found. Unearthing the deepest secrets of the multiverse can require an adventure or even a whole campaign.");
		addlang(2);
		if (!money) {
			addGear("Ink bottle(black)");
			addGear("Quill");
			addGear("Small knife");
			addGear("Dead colleague's letter with an unanswered question");
			addGear("Common clothes set", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(10);
		}
		break;
	case 11: // "Sailor"
		setssProf(9);
		setssProf(17);
		std::cout << "\nChoose Variant:Pirate?\n  No(1)\n  Yes(2)" << endl;
		selector = intValid(3);
		if (selector == 2) {
			bg = 18;
			addfeature("Bad Reputation", 2, "No matter where you go, people are afraid of you due to your reputation. When you are in a civilized settlement, you can get away with minor criminal offenses, such as refusing to pay for food at a tavern or breaking down doors at a local shop, since most people will not report your activity to the authorities.");
		}
		else
			addfeature("Ship's Passage", 2, "When you need to, you can secure free passage on a sailing ship for yourself and your adventuring companions. You might sail on the ship you served on, or another ship you have good relations with(perhaps one captained by a former crewmate). Because you're calling in a favor, you can't be certain of a schedule or route that will meet your every need. Your Dungeon Master will determine how long it takes to get where you need to go. In return for your free passage, you and your companions are expected to assist the crew during the voyage.");
		addfeature("Navigator's tools", 6);
		addfeature("Vehicles(Water)", 6);
		if (!money) {
			addWeapon("Belaying pin", 2.0f);
			addGear("Silk rope(50 feet)", 5.0f);
			std::cout << "\nChoose Lucky charm:\n  Rabbit foot(1)\n  Small stone with a hole in the center(2)\n  Random trinket(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addGear("Lucky Charm: Rabbit foot");
				break;
			case 2:
				addGear("Lucky Charm: Small stone with a hole in the center");
				break;
			case 3:
				addGear(randTrinket());
				break;
			}
			addGear("Common clothes set", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(10);
		}
		break;
	case 12: // "Soldier"
		setssProf(9);
		setssProf(13);
		addGamingProf();
		addfeature("Vehicles(Land)", 6);
		addfeature("Military Rank", 2, "You have a military rank from your career as a soldier. Soldiers loyal to your former military organization still recognize your authority and influence, and they defer to you if they are of a lower rank. You can invoke your rank to exert influence over other soldiers and requisition simple equipment or horses for temporary use. You can also usually gain access to friendly military encampments and fortresses where your rank is recognized.");
		if (!money) {
			addGear("Rank insignia");
			std::cout << "\nChoose Enemy trophy:\n  Dagger(1)\n  Broken blade(2)\n  Banner piece(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addGear("Enemy trophy: Dagger");
				break;
			case 2:
				addGear("Enemy trophy: Broken blade");
				break;
			case 3:
				addGear("Enemey trophy: Banner piece");
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Set of bone dice(1)\n  Deck of cards(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addGear("Set of bone dice");
				break;
			case 2:
				addGear("Deck of cards");
				break;
			}
			addGear("Common clothes set", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(10);
		}
		break;
	case 13: // "Urchin"
		setssProf(21);
		setssProf(22);
		addfeature("Disguise kit", 6);
		addfeature("Thieves' tools", 6);
		addfeature("City Secrets", 2, "You know the secret patterns and flow to cities and can find passages through the urban sprawl that others would miss. When you are not in combat, you(and companions you lead) can travel between any two locations in the city twice as fast as your speed would normally allow.");
		if (!money) {
			addGear("Small knife");
			addGear("Map of home city");
			addGear("Pet mouse");
			addGear("Token to remember your parents by");
			addGear("Common clothes set", 3.0f);
			addGear("Pouch(Belt)", 1.0f);
			addGp(10);
		}
		break;
	}
}
void Player::setAge(string nAge) {
	age = nAge;
}
void Player::setCarry(float heavy) {
	carry = heavy;
}
void Player::setH(string nHeight) {
	height = nHeight;
}
void Player::setW(string nWeight) {
	weight = nWeight;
}
void Player::setEyes(string nEyes) {
	eyes = nEyes;
}
void Player::setSkin(string nSkin) {
	skin = nSkin;
}
void Player::setHair(string nHair) {
	hair = nHair;
}
void Player::setSpec(string nSpec) {
	special = nSpec;
}

void Player::bardSpells() {
	switch (getLevel()) {
	case 1:
		SpellsbyClass(2, bard, 0);
		SpellsbyClass(4, bard, 1);
		break;
	default:
		cout << "Invalid Level" << endl;
		break;
	}
}
void Player::clericSpells() {
	switch (getLevel()) {
	case 1:
		SpellsbyClass(3, cleric, 0);
		SpellsbyClass(calcmod(getwis()) + 1, cleric, 1, true);
		break;
	default:
		cout << "Invalid Level" << endl;
		break;
	}
}
void Player::druidSpells() {
	switch (getLevel()) {
	case 1:
		SpellsbyClass(2, druid, 0);
		SpellsbyClass(calcmod(getwis()) + 1, druid, 1, true);
		break;
	default:
		cout << "Invalid Level" << endl;
		break;
	}
}
void Player::sorcererSpells() {
	switch (getLevel()) {
	case 1:
		SpellsbyClass(4, sorcerer, 0);
		SpellsbyClass(2, sorcerer, 1);
		break;
	default:
		cout << "Invalid Level" << endl;
		break;
	}
}
void Player::warlockSpells() {
	switch (getLevel()) {
	case 1:
		SpellsbyClass(2, warlock, 0);
		SpellsbyClass(2, warlock, 1);
		break;
	default:
		cout << "Invalid Level" << endl;
		break;
	}
}
void Player::wizardSpells() {
	switch (getLevel()) {
	case 1:
		SpellsbyClass(3, wizard, 0);
		SpellsbyClass(calcmod(getint()) + 1, wizard, 1, true);
		break;
	default:
		cout << "Invalid Level" << endl;
		break;
	}
}
void Player::SpellsbyClass(int itr, classes cla, int splevel, bool prep) {
	vector<string> spellsList;
	spellAbility Sp;
	if (itr <= 0)
		itr = 1;
	switch (cla) {
	case bard:
		switch (splevel) {
		case 0:
			spellsList = { "Blade Ward","Dancing Lights","Friends","Light","Mage Hand","Mending","Message","Minor Illusion","Prestidigitation","True Strike","Vicious Mockery" };
			break;
		case 1:
			spellsList = { "Animal Friendship","Bane","Charm Person","Comprehend Languages","Cure Wounds","Detect Magic","Disguise Self","Dissonant Whispers","Faerie Fire","Feather Fall","Healing Word","Heroism","Identify","Illusory Script","Longstrider","Silent Image","Sleep","Speak with Animals","Tasha's Hideous Laughter","Thunderwave","Unseen Servant" };
			break;
		}
		Sp = CHA;
		break;
	case cleric:
		switch (splevel) {
		case 0:
			spellsList = { "Guidance","Light","Mending","Resistance","Sacred Flame","Spare the Dying","Thaumaturgy" };
			break;
		case 1:
			spellsList = { "Bane","Bless","Command","Create or Destroy Water","Cure Wounds","Detect Evil and Good","Detect Magic","Detect Poison and Disease","Guiding Bolt","Healing Word","Inflict Wounds","Protection from Evil and Good","Purify Food and Drink","Sanctuary","Shield of Faith" };
			break;
		}
		Sp = WIS;
		break;
	case druid:
		switch (splevel) {
		case 0:
			spellsList = { "Druidcraft","Guidance","Mending","Poison Spray","Produce Flame","Resistance","Shillelagh","Thorn Whip" };
			break;
		case 1:
			spellsList = { "Animal Friendship","Charm Person","Create or Destroy Water","Cure Wounds","Detect Magic","Detect Poison and Disease","Entangle","Faerie Fire","Fog Cloud","Goodberry","Healing Word","Jump","Longstrider","Purify Food and Drink","Speak with Animals","Thunderwave" };
			break;
		}
		Sp = WIS;
		break;
	case sorcerer:
		switch (splevel) {
		case 0:
			spellsList = { "Acid Splash","Blade Ward","Chill Touch","Dancing Lights","Fire Bolt","Friends","Light","Mage Hand","Mending","Message","Minor Illusion","Poison Spray","Prestidigitation","Ray of Frost","Shocking Grasp","True Strike" };
			break;
		case 1:
			spellsList = { "Burning Hands","Charm Person","Chromatic Orb","Color Spray","Comprehend Languages","Detect Magic","Disguise Self","Expeditious Retreat","False Life","Feather Fall","Fog Cloud","Jump","Mage Armor","Magic Missile","Ray of Sickness","Shield","Silent Image","Sleep","Thunderwave","Witch Bolt" };
			break;
		}
		Sp = CHA;
		break;
	case warlock:
		switch (splevel) {
		case 0:
			spellsList = { "Blade Ward","Chill Touch","Eldritch Blast","Friends","Mage Hand","Minor Illusion","Poison Spray","Prestidigitation","True Strike" };
			break;
		case 1:
			spellsList = { "Armor of Agathys","Arms of Hadar","Charm Person","Comprehend Languages","Expeditious Retreat","Hellish Rebuke","Hex","Illusory Script","Protection from Evil and Good","Unseen Servant","Witch Bolt" };
			break;
		}
		Sp = CHA;
		break;
	case wizard:
		switch (splevel) {
		case 0:
			spellsList = { "Acid Splash","Blade Ward","Chill Touch","Dancing Lights","Fire Bolt","Friends","Light","Mage Hand","Mending","Message","Minor Illusion","Poison Spray","Prestidigitation","Ray of Frost","Shocking Grasp","True Strike" };
			break;
		case 1:
			spellsList = { "Alarm","Burning Hands","Charm Person","Chromatic Orb","Color Spray","Comprehend Languages","Detect Magic","Disguise Self","Expeditious Retreat","False Life","Feather Fall","Find Familiar","Fog Cloud","Grease","Identify","Illusory Script","Jump","Longstrider","Mage Armor","Magic Missile","Protection from Evil and Good","Ray of Sickness","Shield","Silent Image","Sleep","Tasha's Hideous Laughter","Tenser's Floating Disk","Thunderwave","Unseen Servant","Witch Bolt" };
			break;
		}
		Sp = INTEL;
		break;
	default:
		break;
	}
	int ctr = 1;
	bool flag;
	while (ctr <= itr) {
		flag = false;
		if(splevel == 0 || cla == bard || cla == sorcerer ||cla == warlock)
			std::cout << "\nLearn";
		else
			std::cout << "\nPrepare";
		std::cout << " a ";
		if (splevel == 0)
			std::cout << "cantrip";
		else {
			if (splevel == 1)
				std::cout << "1st";
			else if (splevel == 2)
				std::cout << "2nd";
			else if (splevel == 3)
				std::cout << "3rd";
			else
				std::cout << splevel << "th";
				std::cout << "-level spell";
		}
				std::cout << "(" << ctr << "/" << itr << "):" << endl;
		for (unsigned int i = 0; i < spellsList.size(); i++)
			std::cout << "  " << spellsList[i] << "(" << i + 1 << ")" << endl;
		int selector = intValid(spellsList.size() + 1);
		if(prep)
			flag = spellLookup(spellsList[selector - 1], Sp, true);
		else
			flag = spellLookup(spellsList[selector - 1], Sp);
		if (!flag)
			std::cout << "..choose again" << endl;
		else
			ctr++;
	}
}
void Player::classSpells() {
	switch (PCclass) {
	case bard:
		bardSpells();
		break;
	case cleric:
		clericSpells();
		break;
	case druid:
		druidSpells();
		break;
	case sorcerer:
		sorcererSpells();
		break;
	case warlock:
		warlockSpells();
		break;
	case wizard:
		wizardSpells();
		break;
	default:
		break;
	}
}

void Player::addCarry(float w) {
	carry += w;
}
void Player::classRoll(int rolls[], bool money) {
	int selector = 0;
	int flag = 0;
	vector<string> templang;
	vector<string> Type1;
	switch (PCclass) {
	case barbarian: //barbarian
		addfeature("Light armor", 5);
		addfeature("Medium armor", 5);
		addfeature("Shield", 5);
		addfeature("Simple weapons", 4);
		addfeature("Martial weapons", 4);
		setssProf(0);
		setssProf(2);
		addfeature("Rage", 0, "In battle, you fight with primal ferocity. On your turn, you can enter a rage as a bonus action.\nWhile raging, you gain the following benefits if you aren't wearing heavy armor:\n* You have advantage on Strength checks and Strength saving throws.\n* When you make a melee weapon attack using Strength, you gain a bonus to the damage roll that increases as you gain levels as a barbarian, as shown in the Rage Damage column of the Barbarian table.\n* You have resistance to bludgeoning, piercing, and slashing damage.\nIf you are able to cast spells, you can't cast them or concentrate on them while raging.\nYour rage lasts for 1 minute. It ends early if you are knocked unconscious or if your turn ends and you haven't attacked a hostile creature since your last turn or taken damage since then. You can also end your rage on your turn as a bonus action.\nOnce you have raged the number of times shown for your barbarian level in the Rages column of the Barbarian table, you must finish a long rest before you can rage again.");
		addresource("Rage", 2, 2);
		addfeature("Unarmored Defense", 0, "While you are not wearing any armor, your Armor Class equals 10 + your Dexterity modifier + your Constitution modifier. You can use a shield and still gain this benefit.(added)");
		if (money) {
			addGp(dRoll(2, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Greataxe(1)\n  Martial Melee Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Greataxe", 7.0f);
				break;
			case 2:
				addMartialWep(1);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Two handaxes(1)\n  Simple Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Handaxe", 2.0f, 2);
				break;
			case 2:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Explorer's Pack(1)\n  Four javelins(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addExplorer();
				break;
			case 2:
				addWeapon("Javelin", 2.0f, 4);
				break;
			}
		}
		break;
	case bard: //bard
		addInstrumProf(3);
		addfeature("Light armor", 5);
		addfeature("Simple weapons", 4);
		addfeature("Hand crossbow", 4);
		addfeature("Longsword", 4);
		addfeature("Rapier", 4);
		addfeature("Shortsword", 4);
		setssProf(1);
		setssProf(5);
		addfeature("Spellcasting", 0, "* Cantrips\n* Spell Slots\n* Spells Known of 1st Level and Higher\n* Spellcasting Ability(Charisma)\n* Ritual Casting\n* Spellcasting Focus(Musical instrument)");
		addresource("Spell Slots(Spellcasting)", 2, 2, 1);
		addfeature("Bardic Inspiration(d6)", 0, "You can inspire others through stirring words or music. To do so, you use a bonus action on your turn to choose one creature other than yourself within 60 feet of you who can hear you. That creature gains one Bardic Inspiration die, a d6.\nOnce within the next 10 minutes, the creature can roll the die and add the number rolled to one ability check, attack roll, or saving throw it makes. The creature can wait until after it rolls the d20 before deciding to use the Bardic Inspiration die, but must decide before the DM says whether the roll succeeds or fails. Once the Bardic Inspiration die is rolled, it is lost. A creature can have only one Bardic Inspiration die at a time.\nYou can use this feature a number of times equal to your Charisma modifier(a minimum of once). You regain any expended uses when you finish a long rest.\nYour Bardic Inspiration die changes when you reach certain levels in this class. The die becomes a d8 at 5th level, a d10 at 10th level, and a d12 at 15th level.(added)");
		if (money) {
			addGp(dRoll(5, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Rapier(1)\n  Longsword(2)\n  Simple Weapon(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addWeapon("Rapier", 2.0f);
				break;
			case 2:
				addWeapon("Longsword", 3.0f);
				break;
			case 3:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Diplomat's Pack(1)\n  Entertainer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addDiplomat();
				break;
			case 2:
				addEntertainer();
				break;
			}
			addInstrum();
			addArmor("Leather armor", 10.0f);
			addWeapon("Dagger", 1.0f);
		}
		break;
	case cleric: //cleric
		addfeature("Light armor", 5);
		addfeature("Medium armor", 5);
		addfeature("Shield", 5);
		addfeature("Simple weapons", 4);
		setssProf(4);
		setssProf(5);
		addfeature("Spellcasting", 0, "* Cantrips\n* Preparing and Casting Spells\n* Spellcasting Ability(Wisdom)\n* Ritual Casting\n* Spellcasting Focus(Holy symbol)");
		addresource("Spell Slots(Spellcasting)", 2, 2, 1);
		std::cout << "\nChoose Divine Domain:\n  Knowledge(1)\n  Life(2)\n  Light(3)\n  Nature(4)\n  Tempest(5)\n  Trickery(6)\n  War(7)" << endl;
		selector = intValid(8);
		switch (selector) {
		case 1:
			addfeature("Divine Domain: Knowledge", 0);
			//addfeature("Divine Domain: Knowledge", 0, "The gods of knowledge-including Oghma, Boccob, Gilean, Aureon, and Thoth-value learning and understanding above all. Some teach that knowledge is to be gathered and shared in libraries and universities, or promote the practical knowledge of craft and invention. Some deities hoard knowledge and keep its secrets to themselves. And some promise their followers that they will gain tremendous power if they unlock the secrets of the multiverse. Followers of these gods study esoteric lore, collect old tomes, delve into the secret places of the earth, and learn all they can. Some gods of knowledge promote the practical knowledge of craft and invention, including smith deities like Gond, Reorx, Onatar, Moradin, Hephaestus, and Goibhniu.");
			addfeature("Blessings of Knowledge", 0, "At 1st level, you learn two languages of your choice.(added)You also become proficient in your choice of two of the following skills: Arcana, History, Nature, or Religion.(added)\nYour proficiency bonus is doubled for any ability check you make that uses either of those skills.");
			addlang(2);
			break;
		case 2:
			addfeature("Divine Domain: Life", 0);
			//addfeature("Divine Domain: Life", 0, "The Life domain focuses on the vibrant positive energy - one of the fundamental forces of the universe that sustains all life. The gods of life promote vitality and health through healing the sick and wounded, caring for those in need, and driving away the forces of death and undeath. Almost any non-evil deity can claim influence over this domain, particularly agricultural deities(such as Chauntea, Arawai, and Demeter), sun gods(such as Lathander, Pelor, and Re-Horakhty), gods of healing or endurance(such as Ilmater, Mishakal, Apollo, and Diancecht), and gods of home and community(such as Hestia, Hathor, and Boldrei).");
			addfeature("Bonus Proficiency", 0, "When you choose this domain at 1st level, you gain proficiency with heavy armor.(added)");
			addfeature("Heavy armor", 5);
			addfeature("Disciple of Life", 0, "Also starting at 1st level, your healing spells are more effective. Whenever you use a spell of 1st level or higher to restore hit points to a creature, the creature regains additional hit points equal to 2 + the spell's level.");
			break;
		case 3:
			addfeature("Divine Domain: Light", 0);
			addfeature("Bonus Cantrip", 0, "When you choose this domain at 1st level, you gain the light cantrip if you don't already know it.(added)");
			spellLookup("Light", WIS);
			addfeature("Warding Flare", 0, "Also at 1st level, you can interpose divine light between yourself and an attacking enemy. When you are attacked by a creature within 30 feet of you that you can see, you can use your reaction to impose disadvantage on the attack roll, causing light to flare before the attacker before it hits or misses. An attacker that can't be blinded is immune to this feature.\nYou can use this feature a number of times equal to your Wisdom modifier(a minimum of once). You regain all expended uses when you finish a long rest.(added)");
			break;
		case 4:
			addfeature("Divine Domain: Nature", 0);
			addfeature("Acolyte of Nature", 0, "At 1st level, you learn one druid cantrip of your choice.(added)\nYou also gain proficiency in one of the following skills of your choice: Animal Handling, Nature, or Survival.(added)");
			SpellsbyClass(1, druid, 0);
			addfeature("Bonus Proficiency", 0, "Also at 1st level, you gain proficiency with heavy armor.(added)");
			addfeature("Heavy armor", 5);
			break;
		case 5:
			addfeature("Divine Domain: Tempest", 0);
			addfeature("Bonus Proficiencies", 0, "At 1st level, you gain proficiency with martial weapons and heavy armor.(added)");
			addfeature("Martial weapons", 4);
			addfeature("Heavy armor", 5);
			addfeature("Wrath of the Storm", 0, "Also at 1st level, you can thunderously rebuke attackers. When a creature within 5 feet of you that you can see hits you with an attack, you can use your reaction to cause the creature to make a Dexterity saving throw. The creature takes 2d8 lightning or thunder damage(your choice) on a failed saving throw, and half as much damage on a successful one.\nYou can use this feature a number of times equal to your Wisdom modifier(a minimum of once). You regain all expended uses when you finish a long rest.(added)");
			break;
		case 6:
			addfeature("Divine Domain: Trickery", 0);
			addfeature("Blessing of the Trickster", 0, "Starting when you choose this domain at 1st level, you can use your action to touch a willing creature other than yourself to give it advantage on Dexterity(Stealth) checks. This blessing lasts for 1 hour or until you use this feature again.");
			break;
		case 7:
			addfeature("Divine Domain: War", 0);
			addfeature("Bonus Proficiencies", 0, "At 1st level, you gain proficiency with martial weapons and heavy armor.(added)");
			addfeature("Martial weapons", 4);
			addfeature("Heavy armor", 5);
			addfeature("War Priest", 0, "From 1st level, your god delivers bolts of inspiration to you while you are engaged in battle. When you use the Attack action, you can make one weapon attack as a bonus action.\nYou can use this feature a number of times equal to your Wisdom modifier(a minimum of once). You regain all expended uses when you finish a long rest.(added)");
			break;
		}
		if (money) {
			addGp(dRoll(5, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Mace(1)\n  Warhammer(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Mace", 4.0f);
				break;
			case 2:
				addWeapon("Warhammer", 2.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Scale Mail(1)\n  Leather Armor(2)\n  Chain Mail(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addArmor("Scale mail", 45.0f);
				break;
			case 2:
				addArmor("Leather armor", 10.0f);
				break;
			case 3:
				addArmor("Chain mail", 55.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Light crossbow and 20 bolts(1)\n  Simple Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Light crossbow", 5.0f);
				addGear("Bolt", 0.075f, 20);
				break;
			case 2:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Priest's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addPriest();
				break;
			case 2:
				addExplorer();
				break;
			}
			addArmor("Shield");
			std::cout << "\nChoose Holy Symbol:\n  Amulet(1)\n  Emblem(2)\n  Reliquary(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addGear("Holy Symbol: Amulet", 1.0f);
				break;
			case 2:
				addGear("Holy Symbol: Emblem");
				break;
			case 3:
				addGear("Holy Symbol: Reliquary", 2.0f);
				break;
			}
		}
		break;
	case druid: //druid
		addfeature("Herbalism kit", 6);
		addfeature("Light armor", 5);
		addfeature("Medium armor", 5);
		addfeature("Shield", 5);
		addfeature("Club", 4);
		addfeature("Dagger", 4);
		addfeature("Dart", 4);
		addfeature("Javelin", 4);
		addfeature("Mace", 4);
		addfeature("Quarterstaff", 4);
		addfeature("Scimitar", 4);
		addfeature("Sickle", 4);
		addfeature("Sling", 4);
		addfeature("Spear", 4);
		setssProf(3);
		setssProf(4);
		addfeature("Druidic", 0, "You know Druidic, the secret language of druids. You can speak the language and use it to leave hidden messages. You and others who know this language automatically spot such a message. Others spot the message's presence with a successful DC 15 Wisdom(Perception) check but can't decipher it without magic.(added)");
		addfeature("Druidic", 3);
		addfeature("Spellcasting", 0, "* Cantrips\n* Preparing and Casting Spells\n* Spellcasting Ability(Wisdom)\n* Ritual Casting\n* Spellcasting Focus(Druidic focus)");
		addresource("Spell Slots(Spellcasting)", 2, 2, 1);
		if (money) {
			addGp(dRoll(2, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Wooden Shield(1)\n  Simple Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addArmor("Shield(Wood)", 6.0f);
				break;
			case 2:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Scimitar(1)\n  Simple Melee Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Scimitar", 3.0f);
				break;
			case 2:
				addSimpleWep(1);
				break;
			}
			addArmor("Leather armor");
			addExplorer();
			std::cout << "\nChoose Druidic Focus:\n  Sprig of mistletoe(1)\n  Totem(2)\n  Wooden staff(3)\n  Yew wand(4)" << endl;
			selector = intValid(5);
			switch (selector) {
			case 1:
				addGear("Sprig of mistletoe");
				break;
			case 2:
				addGear("Totem");
				break;
			case 3:
				addGear("Wooden staff", 4.0f);
				break;
			case 4:
				addGear("Yew wand", 1.0f);
				break;
			}
		}
		break;
	case fighter: //fighter
		addfeature("All armor", 5);
		addfeature("Shield", 5);
		addfeature("Simple weapons", 4);
		addfeature("Martial weapons", 4);
		setssProf(0);
		setssProf(2);
		std::cout << "\nChoose Fighting Style:\n  Archery(1)\n  Defense(2)\n  Dueling(3)\n  Great Weapon Fighting(4)\n  Protection(5)\n  Two-Weapon Fighting(6)" << endl;
		selector = intValid(7);
		switch (selector) {
		case 1:
			addfeature("Fighting Style: Archery", 0, "You gain a +2 bonus to attack rolls you make with ranged weapons.");
			break;
		case 2:
			addfeature("Fighting Style: Defense", 0, "While you are wearing armor, you gain a +1 bonus to AC.");
			break;
		case 3:
			addfeature("Fighting Style: Dueling", 0, "When you are wielding a melee weapon in one hand and no other weapons, you gain a +2 bonus to damage rolls with that weapon.");
			break;
		case 4:
			addfeature("Fighting Style: Great Weapon Fighting", 0, "When you roll a 1 or 2 on a damage die for an attack you make with a melee weapon that you are wielding with two hands, you can reroll the die and must use the new roll, even if the new roll is a 1 or a 2. The weapon must have the two-handed or versatile property for you to gain this benefit.");
			break;
		case 5:
			addfeature("Fighting Style: Protection", 0, "When a creature you can see attacks a target other than you that is within 5 feet of you, you can use your reaction to impose disadvantage on the attack roll. You must be wielding a shield.");
			break; 
		case 6:
			addfeature("Fighting Style: Two-Weapon Fighting", 0, "When you engage in two-weapon fighting, you can add your ability modifier to the damage of the second attack.");
			break;
		}
		addfeature("Second Wind", 0, "You have a limited well of stamina that you can draw on to protect yourself from harm. On your turn, you can use a bonus action to regain hit points equal to 1d 10 + your fighter level.\nOnce you use this feature, you must finish a short or long rest before you can use it again.(added)");
		addresource("Second Wind", 1, 0);
		if (money) {
			addGp(dRoll(5, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "Chain Mail(1)\n  Leather armor, longbow, and 20 arrows(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addArmor("Chain mail", 55.0f);
				break;
			case 2:
				addArmor("Leather armor", 10.0f);
				addWeapon("Longbow", 2.0f);
				addGear("Arrow", 0.05f, 20);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Martial Weapon and shield(1)\n  Two Martial Weapons(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addMartialWep();
				addArmor("Shield", 6.0f);
				break;
			case 2:
				addMartialWep(0, 2);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Light crossbow and 20 bolts(1)\n  Two handaxes(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Light crossbow", 5.0f);
				addGear("Bolt", .075f, 20);
				break;
			case 2:
				addWeapon("Handaxe", 2.0f, 2);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Dungeoneer's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addDungeoneer();
				break;
			case 2:
				addExplorer();
				break;
			}
		}
		break;
	case monk: //monk
		std::cout << "\nChoose Tool Proficiency:\n  Artisan Tool(1)\n  Instrument(2)" << endl;
		selector = intValid(3);
		switch (selector) {
		case 1:
			addArtToolProf();
			break;
		case 2:
			addInstrumProf();
			break;
		}
		addfeature("Simple weapons", 4);
		addfeature("Shortsword", 4);
		setssProf(0);
		setssProf(1);
		addfeature("Unarmored Defense", 0, "Beginning at 1st level, while you are wearing no armor and not wielding a shield, your AC equals 10 + your Dexterity modifier + your Wisdom modifier.(added)");
		addfeature("Martial Arts", 0, "At 1st level, your practice of martial arts gives you mastery of combat styles that use unarmed strikes and monk weapons, which are shortswords and any simple melee weapons that don't have the two-handed or heavy property.\nYou gain the following benefits while you are unarmed or wielding only monk weapons and you aren't wearing armor or wielding a shield:\n* You can use Dexterity instead of Strength for the attack and damage rolls of your unarmed strikes and monk weapons.\n* You can roll a d4 in place of the normal damage of your unarmed strike or monk weapon. This die changes as you gain monk levels, as shown in the Martial Arts column of the Monk table.\n* When you use the Attack action with an unarmed strike or a monk weapon on your turn, you can make one unarmed strike as a bonus action. For example, if you take the Attack action and attack with a quarterstaff, you can also make an unarmed strike as a bonus action, assuming you haven't already taken a bonus action this turn.\nCertain monasteries use specialized forms of the monk weapons. For example, you might use a club that is two lengths of wood connected by a short chain(called a nunchaku) or a sickle with a shorter, straighter blade(called a kama). Whatever name you use for a monk weapon, you can use the game statistics provided for the weapon in chapter 5.");
		if (money) {
			addGp(dRoll(5, 4));
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Shortsword(1)\n  Simple Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Shortsword", 2.0f);
				break;
			case 2:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Dungeoneer's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addDungeoneer();
				break;
			case 2:
				addExplorer();
				break;
			}
			addWeapon("Dart", 0.25f, 10);
		}
		break;
	case paladin: //paladin
		addfeature("All armor", 5);
		addfeature("Shield", 5);
		addfeature("Simple weapons", 4);
		addfeature("Martial weapons", 4);
		setssProf(4);
		setssProf(5);
		addfeature("Divine Sense", 0, "The presence of strong evil registers on your senses like a noxious odor, and powerful good rings like heavenly music in your ears. As an action, you can open your awareness to detect such forces. Until the end of your next turn, you know the location of any celestial, fiend, or undead within 60 feet of you that is not behind total cover. You know the type(celestial, fiend, or undead) of any being whose presence you sense, but not its identity(the vampire Count Strahd von Zarovich, for instance). Within the same radius, you also detect the presence of any place or object that has been consecrated or desecrated, as with the hallow spell.\nYou can use this feature a number of times equal to 1 + your Charisma modifier. When you finish a long rest, you regain all expended uses.(added)");
		addfeature("Lay on Hands", 0, "Your blessed touch can heal wounds. You have a pool of healing power that replenishes when you take a long rest. With that pool, you can restore a total number of hit points equal to your paladin level x 5.\nAs an action, you can touch a creature and draw power from the pool to restore a number of hit points to that creature, up to the maximum amount remaining in your pool.\nAlternatively, you can expend 5 hit points from your pool of healing to cure the target of one disease or neutralize one poison affecting it. You can cure multiple diseases and neutralize multiple poisons with a single use of Lay on Hands, expending hit points separately for each one.\nThis feature has no effect on undead and constructs.(added)");
		addresource("Lay on Hands", getLevel() * 5, 2);
		if (money) {
			addGp(dRoll(5, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Martial Weapon and shield(1)\n  Two Martial Weapons(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addMartialWep();
				addArmor("Shield", 6.0f);
				break;
			case 2:
				addMartialWep(0, 2);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Five javelins(1)\n  Simple Melee Weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Javelin", 2.0f, 5);
				break;
			case 2:
				addSimpleWep(1);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Priest's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addPriest();
				break;
			case 2:
				addExplorer();
				break;
			}
			addArmor("Chain mail");
			std::cout << "\nChoose Holy Symbol:\n  Amulet(1)\n  Emblem(2)\n  Reliquary(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addGear("Holy Symbol: Amulet", 1.0f);
				break;
			case 2:
				addGear("Holy Symbol: Emblem");
				break;
			case 3:
				addGear("Holy Symbol: Reliquary", 2.0f);
				break;
			}
		}
		break;
	case ranger: //ranger
		addfeature("Light armor", 5);
		addfeature("Medium armor", 5);
		addfeature("Shield", 5);
		addfeature("Simple weapons", 4);
		addfeature("Martial weapons", 4);
		setssProf(0);
		setssProf(1);
		std::cout << "\nChoose Favored Enemy:\n  Aberrations(1)\n  Beasts(2)\n  Celestials(3)\n  Constructs(4)\n  Dragons(5)\n  Elementals(6)\n  Fey(7)\n  Fiends(8)\n  Giants(9)\n  Monstrosities(10)\n  Oozes(11)\n  Plants(12)\n  Undead(13)\n  Humanoid(14)" << endl;
		selector = intValid(15);
		switch (selector) {
		case 1:
			addfeature("Favored Enemy: Aberrations", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			addfeature("Deep Speech", 3);
			break;
		case 2:
			addfeature("Favored Enemy: Beasts", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			break;
		case 3:
			addfeature("Favored Enemy: Celestials", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			addfeature("Celestial", 3);
			break;
		case 4:
			addfeature("Favored Enemy: Constructs", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			break;
		case 5:
			addfeature("Favored Enemy: Dragons", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			addfeature("Draconic", 3);
			break;
		case 6:
			addfeature("Favored Enemy: Elementals", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			addfeature("Primordial", 3);
			break;
		case 7:
			addfeature("Favored Enemy: Fey", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			addfeature("Sylvan", 3);
			break;
		case 8:
			addfeature("Favored Enemy: Fiends", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			std::cout << "Choose language:\n  Abyssal(1)\n  Infernal(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addfeature("Abyssal", 3);
				break;
			case 2:
				addfeature("Infernal", 3);
				break;
			}
			break;
		case 9:
			addfeature("Favored Enemy: Giants", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			addfeature("Giant", 3);
			break;
		case 10:
			addfeature("Favored Enemy: Monstrosities", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			break;
		case 11:
			addfeature("Favored Enemy: Oozes", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			break;
		case 12:
			addfeature("Favored Enemy: Plants", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			break;
		case 13:
			addfeature("Favored Enemy: Undead", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
			break;
		case 14:
			int tempselect = 0;
			while (flag < 2) {
				if (flag == 0)
					std::cout << "Choose Humanoid(1/2):";
				else
					std::cout << "Choose Humanoid(2/2):";
				std::cout << "\n  Aarakocra(1)\n  Goblinoid(2)\n  Bullywug(3)\n  Gnome(4)\n  Elf(5)\n  Dwarf(6)\n  Gith(7)\n  Gnoll(8)\n  Grimlock(9)\n  Human(10)\n  Shapechanger(Humanoid)(11)\n  Kenku(12)\n  Kobold(13)\n  Kuo-toa(14)\n  Lizardfolk(15)\n  Merfolk(16)\n  Orc(17)\n  Quaggoth(18)\n  Sahuagin(19)\n  Thri-kreen(20)\n  Troglodyte(21)\n  Yuan-ti(22)" << endl;
				selector = intValid(23);
				if (tempselect != selector) {
					tempselect = selector;
					switch (selector) {
					case 1:
						addfeature("Favored Enemy: Aarakocra", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Aarakocra, Primordial
						templang.push_back("Aarakocra");
						templang.push_back("Primordial");
						break;
					case 2:
						addfeature("Favored Enemy: Goblinoid", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Goblin
						templang.push_back("Goblin");
						break;
					case 3:
						addfeature("Favored Enemy: Bullywug", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Bullywug
						templang.push_back("Bullywug");
						break;
					case 4:
						addfeature("Favored Enemy: Gnome", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Undercommon, Primordial
						templang.push_back("Undercommon");
						templang.push_back("Primordial");
						break;
					case 5:
						addfeature("Favored Enemy: Elf", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Elvish, Undercommon
						templang.push_back("Elvish");
						templang.push_back("Undercommon");
						break;
					case 6:
						addfeature("Favored Enemy: Dwarf", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Dwarvish, Undercommon
						templang.push_back("Dwarvish");
						templang.push_back("Undercommon");
						break;
					case 7:
						addfeature("Favored Enemy: Gith", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Gith
						templang.push_back("Gith");
						break;
					case 8:
						addfeature("Favored Enemy: Gnoll", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Gnoll
						templang.push_back("Gnoll");
						break;
					case 9:
						addfeature("Favored Enemy: Grimlock", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Undercommon
						templang.push_back("Undercommon");
						break;
					case 10:
						addfeature("Favored Enemy: Human", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Draconic
						templang.push_back("Draconic");
						break;
					case 11:
						addfeature("Favored Enemy: Shapechanger(Humanoid)", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures.");
						break;
					case 12:
						addfeature("Favored Enemy: Kenku", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Primordial
						templang.push_back("Primordial");
						break;
					case 13:
						addfeature("Favored Enemy: Kobold", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Draconic
						templang.push_back("Draconic");
						break;
					case 14:
						addfeature("Favored Enemy: Kuo-toa", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Undercommon
						templang.push_back("Undercommon");
						break;
					case 15:
						addfeature("Favored Enemy: Lizardfolk", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Draconic
						templang.push_back("Draconic");
						break;
					case 16:
						addfeature("Favored Enemy: Merfolk", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Primordial
						templang.push_back("Primordial");
						break;
					case 17:
						addfeature("Favored Enemy: Orc", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Orc
						templang.push_back("Orc");
						break;
					case 18:
						addfeature("Favored Enemy: Quaggoth", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Undercommon
						templang.push_back("Undercommon");
						break;
					case 19:
						addfeature("Favored Enemy: Sahuagin", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Sahuagin
						templang.push_back("Sahuagin");
						break;
					case 20:
						addfeature("Favored Enemy: Thri-kreen", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Thri-kreen
						templang.push_back("Thri-kreen");
						break;
					case 21:
						addfeature("Favored Enemy: Troglodyte", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Troglodyte
						templang.push_back("Troglodyte");
						break;
					case 22:
						addfeature("Favored Enemy: Yuan-ti", 0, "Beginning at 1st level, you have significant experience studying, tracking, hunting, and even talking to a certain type of enemy.\nChoose a type of favored enemy: aberrations, beasts, celestials, constructs, dragons, elementals, fey, fiends, giants, monstrosities, oozes, plants, or undead.\nAlternatively, you can select two races of humanoid(such as gnolls and orcs) as favored enemies.\nYou have advantage on Wisdom(Survival) checks to track your favored enemies, as well as on Intelligence checks to recall information about them.\nWhen you gain this feature, you also learn one language of your choice that is spoken by your favored enemies, if they speak one at all.(added)\nYou choose one additional favored enemy, as well as an associated language, at 6th and 14th level. As you gain levels, your choices should reflect the types of monsters you have encountered on your adventures."); //Abyssal, Draconic
						templang.push_back("Abyssal");
						templang.push_back("Draconic");
						break;
					}
					flag++;
				}
				else
					std::cout << "Already chosen. Choose again.." << endl;
			}
			std::cout << "\nChoose language:\n";
			for (unsigned int index = 0; index < templang.size(); ++index)
			{
				std::cout << "  " << templang[index] << "(" << index + 1 << ")\n";
			}
			selector = intValid(templang.size() + 1);
			addfeature(templang[selector - 1], 3);
			break;
		}
		Type1 = { "Arctic","Coast","Desert","Forest","Grassland","Mountain","Swamp","Underdark" };
		std::cout << "Choose Natural Explorer environment:" << endl;
		for (unsigned int i = 0; i < Type1.size(); i++)
			std::cout << "  " << Type1[i] << "(" << i + 1 << ")" << endl;
		selector = intValid(9);
		addfeature("Natural Explorer: " + Type1[selector - 1], 0, "You are particularly familiar with one type of natural environment and are adept at traveling and surviving in such regions. Choose one type of favored terrain: arctic, coast, desert, forest, grassland, mountain, swamp, or the Underdark. When you make an Intelligence or Wisdom check related to your favored terrain, your proficiency bonus is doubled if you are using a skill that you're proficient in.\nWhile traveling for an hour or more in your favored terrain, you gain the following benefits:\n* Difficult terrain doesn't slow your group’s travel.\n* Your group can't become lost except by magical means.\n* Even when you are engaged in another activity while traveling(such as foraging, navigating, or tracking), you remain alert to danger.\n* If you are traveling alone, you can move stealthily at a normal pace.\n* When you forage, you find twice as much food as you normally would.\n* While tracking other creatures, you also learn their exact number, their sizes, and how long ago they passed through the area.\nYou choose additional favored terrain types at 6th and 10th level.");
		if (money) {
			addGp(dRoll(5, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Scale mail(1)\n  Leather armor(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addArmor("Scale mail", 45.0f);
				break;
			case 2:
				addArmor("Leather armor", 10.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Two shortswords(1)\n  Two Simple Melee Weapons(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Shortsword", 2.0f, 2);
				break;
			case 2:
				addSimpleWep(1, 2);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Dungeoneer's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addDungeoneer();
				break;
			case 2:
				addExplorer();
				break;
			}
			addWeapon("Longbow", 2.0f);
			addGear("Quiver", 1.0f);
			addGear("Arrow", 0.05f, 20);
		}
		break;
	case rogue: //rogue
		addfeature("Thieves' tools", 6);
		addfeature("Light armor", 5);
		addfeature("Simple weapons", 4);
		addfeature("Hand crossbow", 4);
		addfeature("Longsword", 4);
		addfeature("Rapier", 4);
		addfeature("Shortsword", 4);
		setssProf(1);
		setssProf(3);
		addfeature("Expertise", 0, "At 1st level, choose two of your skill proficiencies, or one of your skill proficiencies and your proficiency with thieves' tools.Your proficiency bonus is doubled for any ability check you make that uses either of the chosen proficiencies.\nAt 6th level, you can choose two more of your proficiencies(in skills or with thieves' tools) to gain this benefit.");
		addfeature("Sneak Attack", 0, "Beginning at 1st level, you know how to strike subtly and exploit a foe's distraction. Once per turn, you can deal an extra 1d6 damage to one creature you hit with an attack if you have advantage on the attack roll. The attack must use a finesse or a ranged weapon.\nYou don't need advantage on the attack roll if another enemy of the target is within 5 feet of it, that enemy isn't incapacitated, and you don't have disadvantage on the attack roll.\nThe amount of the extra damage increases as you gain levels in this class, as shown in the Sneak Attack column of the Rogue table.");
		addfeature("Thieves' Cant", 0, "During your rogue training you learned thieves' cant, a secret mix of dialect, jargon, and code that allows you to hide messages in seemingly normal conversation. Only another creature that knows thieves' cant understands such messages. It takes four times longer to convey such a message than it does to speak the same idea plainly.\nIn addition, you understand a set of secret signs and symbols used to convey short, simple messages, such as whether an area is dangerous or the territory of a thieves' guild, whether loot is nearby, or whether the people in an area are easy marks or will provide a safe house for thieves on the run.");
		if (money) {
			addGp(dRoll(4, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Rapier(1)\n  Shortsword(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Rapier", 2.0f);
				break;
			case 2:
				addWeapon("Shortsword", 2.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Shortbow and quiver of 20 arrows(1)\n  Shortsword(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Shortbow", 2.0f);
				addGear("Quiver", 1.0f);
				addGear("Arrow", 0.05f, 20);
				break;
			case 2:
				addWeapon("Shortsword", 2.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "Burglar's Pack(1)\n  Dungeoneer's Pack(2)\n  Explorer's Pack(3)" << endl;
			selector = intValid(4);
			switch (selector) {
			case 1:
				addBurglar();
				break;
			case 2:
				addDungeoneer();
				break;
			case 3:
				addExplorer();
				break;
			}
			addArmor("Leather armor", 10.0f);
			addWeapon("Dagger", 1.0f, 2);
			addTool("Thieves' tools", 1.0f);
		}
		break;
	case sorcerer: //sorcerer
		addfeature("Dagger", 4);
		addfeature("Dart", 4);
		addfeature("Quarterstaff", 4);
		addfeature("Sling", 4);
		addfeature("Light crossbow", 4);
		setssProf(2);
		setssProf(5);
		addfeature("Spellcasting", 0, "* Cantrips\n* Spell Slots\n* Spells Known of 1st Level and Higher\n* Spellcasting Ability(Charisma)\n* Spellcasting Focus(Arcane focus)");
		addresource("Spell Slots(Spellcasting)", 2, 2, 1);
		std::cout << "\nChoose Sorcerous Origin:\n  Draconic Bloodline(1)\n  Wild Magic(2)" << endl;
		selector = intValid(3);
		switch (selector) {
		case 1:
			selector = 0;
			addfeature("Draconic", 3);
			addfeature("Sorcerous Origin: Draconic Bloodline", 0);
			Type1 = { "Black","Blue","Brass","Bronze","Copper","Gold","Green","Red","Silver","White" };
			std::cout << "Choose Draconic Ancestor:" << endl;
			for (unsigned int i = 0; i < Type1.size(); i++)
				std::cout << "  " << Type1[i] << "(" << i + 1 << ")" << endl;
			selector = intValid(11);
			addfeature("Draconic Ancestor: " + Type1[selector - 1], 0, "At 1st level, you choose one type of dragon as your ancestor. The damage type associated with each dragon is used by features you gain later. You can speak, read, and write Draconic.(added) Additionally, whenever you make a Charisma check when interacting with dragons, your proficiency bonus is doubled if it applies to the check.");
			addfeature("Draconic Resilience", 0, "As magic flows through your body, it causes physical traits of your dragon ancestors to emerge. At 1st level, your hit point maximum increases by 1 and increases by 1 again whenever you gain a level in this class.(added)\nAdditionally, parts of your skin are covered by a thin sheen of dragon-like scales. When you aren't wearing armor, your AC equals 13 + your Dexterity modifier.(added)");
			addmaxhp(1);
			break;
		case 2:
			addfeature("Sorcerous Origin: Wild Magic", 0);
			addfeature("Wild Magic Surge", 0, "Starting when you choose this origin at 1st level, your spellcasting can unleash surges of untamed magic. Immediately after you cast a sorcerer spell of 1st level or higher, the DM can have you roll a d20. If you roll a 1, roll on the Wild Magic Surge table to create a random magical effect.");
			addfeature("Tides of Chaos", 0, "Starting at 1st level, you can manipulate the forces of chance and chaos to gain advantage on one attack roll, ability check, or saving throw. Once you do so, you must finish a long rest before you can use this feature again.(added) Any time before you regain the use of this feature, the DM can have you roll on the Wild Magic Surge table immediately after you cast a sorcerer spell of 1st level or higher. You then regain the use of this feature.");
			addresource("Tides of Chaos", 1, 2);
			break;
		}
		if (money) {
			addGp(dRoll(3, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Light crossbow and 20 bolts(1)\n  Simple weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Light crossbow", 5.0f);
				addGear("Bolt", 0.075f, 20);
				break;
			case 2:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Component pouch(1)\n  Arcane focus(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addGear("Component pouch", 2.0f);
				break;
			case 2:
				std::cout << "\n Choose Arcane focus:\n  Crystal(1)\n  Orb(2)\n  Rod(3)\n  Staff(4)\n  Wand(5)" << endl;
				selector = intValid(6);
				switch (selector) {
				case 1:
					addGear("Arcane focus: Crystal", 1.0f);
					break;
				case 2:
					addGear("Arcane focus: Orb", 3.0f);
					break;
				case 3:
					addGear("Arcane focus: Rod", 2.0f);
					break;
				case 4:
					addGear("Arcane focus: Staff", 4.0f);
					break;
				case 5:
					addGear("Arcane focus: Wand", 1.0f);
					break;
				}
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Dungeoneer's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addDungeoneer();
				break;
			case 2:
				addExplorer();
				break;
			}
			addWeapon("Dagger", 1.0f, 2);
		}
		break;
	case warlock: //warlock
		addfeature("Light armor", 5);
		addfeature("Simple weapons", 4);
		setssProf(4);
		setssProf(5);
		std::cout << "\nChoose Otherworldly Patron:\n  Archfey(1)\n  Fiend(2)\n  Great Old One(3)" << endl;
		selector = intValid(4);
		switch (selector) {
		case 1:
			addfeature("Otherworldly Patron: Archfey", 0);	
			addfeature("Fey Presence", 0, "Starting at 1st level, your patron bestows upon you the ability to project the beguiling and fearsom e presence of the fey. As an action, you can cause each creature in a 10-foot cube originating from you to make a Wisdom saving throw against your warlock spell save DC. The creatures that fail their saving throws are all charmed or frightened by you(your choice) until the end of your next turn.\nOnce you use this feature, you can't use it again until you finish a short or long rest.(added)");
			addresource("Fey Presence", 1, 0);
			break;
		case 2:
			addfeature("Otherworldly Patron: Fiend", 0);
			addfeature("Dark One's Blessing", 0, "Starting at 1st level, when you reduce a hostile creature to 0 hit points, you gain temporary hit points equal to your Charisma modifier + your warlock level(minimum of 1).");
			break;
		case 3:
			addfeature("Otherworldly Patron: Great Old One", 0);
			addfeature("Awakened Mind", 0, "Starting at 1st level, your alien knowledge gives you the ability to touch the minds of other creatures. You can communicate telepathically with any creature you can see within 30 feet of you. You don't need to share a language with the creature for it to understand your telepathic utterances, but the creature must be able to understand at least one language.");
			break;
		}
		addfeature("Pact Magic", 0, "* Cantrips\n* Spell Slots\n* Spells Known of 1st Level and Higher\n* Spellcasting Ability(Charisma)\n* Spellcasting Focus(Arcane focus)");
		addresource("Spell Slots(Pact Magic)", 1, 0, 1);
		if (money) {
			addGp(dRoll(4, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Light crossbow and 20 bolts(1)\n  Simple weapon(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Light crossbow", 5.0f);
				addGear("Bolt", 0.075f, 20);
				break;
			case 2:
				addSimpleWep();
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Component pouch(1)\n  Arcane focus(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addGear("Component pouch", 2.0f);
				break;
			case 2:
				std::cout << "\nChoose Arcane focus:\n  Crystal(1)\n  Orb(2)\n  Rod(3)\n  Staff(4)\n  Wand(5)" << endl;
				selector = intValid(6);
				switch (selector) {
				case 1:
					addGear("Arcane focus: Crystal", 1.0f);
					break;
				case 2:
					addGear("Arcane focus: Orb", 3.0f);
					break;
				case 3:
					addGear("Arcane focus: Rod", 2.0f);
					break;
				case 4:
					addGear("Arcane focus: Staff", 4.0f);
					break;
				case 5:
					addGear("Arcane focus: Wand", 1.0f);
					break;
				}
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Scholar's Pack(1)\n  Dungeoneer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addScholar();
				break;
			case 2:
				addDungeoneer();
				break;
			}
			addArmor("Leather armor", 10.0f);
			addSimpleWep();
			addWeapon("Dagger", 1.0f, 2);
		}
		break;
	case wizard: //wizard
		addfeature("Dagger", 4);
		addfeature("Dart", 4);
		addfeature("Quarterstaff", 4);
		addfeature("Sling", 4);
		addfeature("Light crossbow", 4);
		setssProf(3);
		setssProf(4);
		addfeature("Spellcasting", 0, "* Cantrips\n* Spellbook\n* Preparing and Casting Spells\n* Spellcasting Ability(Intelligence)\n* Ritual Casting\n* Spellcasting Focus(Arcane focus)");
		addresource("Spell Slots(Spellcasting)", 2, 2, 1);
		addfeature("Arcane Recovery", 0, "You have learned to regain some of your magical energy by studying your spellbook. Once per day when you finish a short rest, you can choose expended spell slots to recover. The spell slots can have a combined level that is equal to or less than half your wizard level(rounded up), and none of the slots can be 6th level or higher.\nFor example, if you’re a 4th-level wizard, you can recover up to two levels worth of spell slots. You can recover either a 2nd-level spell slot or two 1st-level spell slots.");
		if (money) {
			addGp(dRoll(4, 4) * 10);
		}
		else {
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Quarterstaff(1)\n  Dagger(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addWeapon("Quarterstaff", 4.0f);
				break;
			case 2:
				addWeapon("Dagger", 1.0f);
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Component pouch(1)\n  Arcane focus(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addGear("Component pouch", 2.0f);
				break;
			case 2:
				std::cout << "\nChoose Arcane focus:\n  Crystal(1)\n  Orb(2)\n  Rod(3)\n  Staff(4)\n  Wand(5)" << endl;
				selector = intValid(6);
				switch (selector) {
				case 1:
					addGear("Arcane focus: Crystal", 1.0f);
					break;
				case 2:
					addGear("Arcane focus: Orb", 3.0f);
					break;
				case 3:
					addGear("Arcane focus: Rod", 2.0f);
					break;
				case 4:
					addGear("Arcane focus: Staff", 4.0f);
					break;
				case 5:
					addGear("Arcane focus: Wand", 1.0f);
					break;
				}
				break;
			}
			std::cout << "\nChoose equipment option:" << endl;
			std::cout << "  Scholar's Pack(1)\n  Explorer's Pack(2)" << endl;
			selector = intValid(3);
			switch (selector) {
			case 1:
				addScholar();
				break;
			case 2:
				addExplorer();
				break;
			}
			addGear("Spellbook", 3.0f);
		}
		break;
	}
}
void Player::insertRace(int index) {
	setType("Humanoid");
	addfeature("Common", 3);
	int selector = 0;
	int tempselect = 0;
	bool flag = false;
	int premain = 2;
	vector<string> Type1;
	vector<string> Type2;
	string Type3;
	switch (index) {
	case 1:
		addfeature("Draconic", 3);
		setRace("Dragonborn");
		setsize(2);
		addstr(2);
		addcha(1);
		setspd(30);
		Type1 = { "Black","Blue","Brass","Bronze","Copper","Gold","Green","Red","Silver","White" };
		Type2 = { "Acid","Lightning","Fire","Lightning","Acid","Fire","Poison","Fire","Cold","Cold" };
		std::cout << "\nChoose Draconic Ancestry:" << endl;
		for (unsigned int i = 0; i < Type1.size(); i++)
			std::cout << "  " << Type1[i] << "(" << i + 1 << ")" << endl;
		selector = intValid(11);
		if (selector == 7 || selector == 9 || selector == 10)
			Type3 = { " 15 ft. cone (Con save)" };
		else if (selector == 6 || selector == 8)
			Type3 = { " 15 ft. cone (Dex save)" };
		else
			Type3 = { " 5 by 30 ft. line (Dex save)" };
		addfeature("Draconic Ancestry: " + Type1[selector - 1], 1, "You have draconic ancestry. Choose one type of dragon from the Draconic Ancestry table. Your breath weapon and damage resistance are determined by the dragon type, as shown in the table.(added)");
		addfeature("Breath Weapon: " + Type2[selector - 1] + Type3, 1, "You can use your action to exhale destructive energy. Your draconic ancestry determines the size, shape, and damage type of the exhalation. When you use your breath weapon, each creature in the area of the exhalation must make a saving throw, the type of which is determined by your draconic ancestry. The DC for this saving throw equals 8 + your Constitution modifier + your proficiency bonus. A creature takes 2d6 damage on a failed save, and half as much damage on a successful one. The damage increases to 3d6 at 6th level, 4d6 at 11th level, and 5d6 at 16th level.\nAfter you use your breath weapon, you can't use it again until you complete a short or long rest.");
		addfeature("Damage Resistance: " + Type2[selector - 1], 1, "You have resistance to the damage type associated with your draconic ancestry.");
		break;
	case 2:
		addfeature("Dwarvish", 3);
		std::cout << "\nChoose Subrace:\n  Hill(1)\n  Mountain(2)" << endl;
		selector = intValid(3);
		if (selector == 1) {
			setRace("Hill Dwarf");
			addwis(1);
			addfeature("Dwarven Toughness", 1, "Your hit point maximum increases by 1, and it increases by 1 every time you gain a level.(added)");
			addmaxhp(1);
		}
		else {
			setRace("Mountain Dwarf");
			addstr(2);
			addfeature("Dwarven Armor Training", 1, "You have proficiency with light and medium armor.(added)");
			addfeature("Light armor", 5);
			addfeature("Medium armor", 5);
		}
		setsize(2);
		addcon(2);
		setspd(25);
		setSpec("Speed is not reduced by wearing heavy armor");
		addfeature("Darkvision", 1, "Accustomed to life underground, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can't discern color in darkness, only shades of gray.");
		addfeature("Dwarven Resilience", 1, "You have advantage on saving throws against poison, and you have resistance against poison damage.");
		addfeature("Dwarven Combat Training", 1, "You have proficiency with the battleaxe, handaxe, throwing hammer, and warhammer.(added)");
		addfeature("Battleaxe", 4);
		addfeature("Handaxe", 4);
		addfeature("Throwing hammer", 4);
		addfeature("Warhammer", 4);
		addfeature("Tool Proficiency", 1, "You gain proficiency with the artisan's tools of your choice: smith's tools, brewer's supplies, or mason's tools.(added)");
		std::cout << "\nChoose Artisan Tool Proficiency:\n  Smith's tools(1)\n  Brewer's supplies(2)\n  Mason's tools(3)" << endl;
		selector = intValid(4);
		switch (selector) {
		case 1:
			addfeature("Smith's tools", 6);
			break;
		case 2:
			addfeature("Brewer's supplies", 6);
			break;
		case 3:
			addfeature("Mason's tools", 6);
			break;
		}
		addfeature("Stonecunning", 1, "Whenever you make an Intelligence(History) check related to the origin of stonework, you are considered proficient in the History skill and add double your proficiency bonus to the check, instead of your normal proficiency bonus.");
		break;
	case 3:
		addfeature("Elvish", 3);
		std::cout << "Choose Subrace:\n  High(1)\n  Wood(2)\n  Dark(3)" << endl;
		selector = intValid(4);
		switch (selector) {
		case 1:
			setRace("High Elf");
			addint(1);
			setspd(30);
			addfeature("Elf Weapon Training", 1, "You have proficiency with the longsword, shortsword, shortbow, and longbow.(added)");
			addfeature("Longsword", 4);
			addfeature("Shortsword", 4);
			addfeature("Shortbow", 4);
			addfeature("Longbow", 4);
			addfeature("Cantrip", 1, "You know one cantrip of your choice from the wizard spell list. Intelligence is your spellcasting ability for it.(added)");
			SpellsbyClass(1, wizard, 0);
			addfeature("Extra Language", 1, "You can speak, read, and write one extra language of your choice.(added)");
			addlang();
			break;
		case 2:
			setRace("Wood Elf");
			addwis(1);
			setspd(35);
			addfeature("Elf Weapon Training", 1, "You have proficiency with the longsword, shortsword, shortbow, and longbow.(added)");
			addfeature("Longsword", 4);
			addfeature("Shortsword", 4);
			addfeature("Shortbow", 4);
			addfeature("Longbow", 4);
			addfeature("Fleet of Foot", 1, "Your base walking speed increases to 35 feet.(added)");
			addfeature("Mask of the Wild", 1, "You can attempt to hide even when you are only lightly obscured by foliage, heavy rain, falling snow, mist, and other natural phenomena.");
			break;
		case 3:
			setRace("Dark Elf");
			addcha(1);
			setspd(30);
			addfeature("Superior Darkvision", 1, "Your darkvision has a radius of 120 feet.");
			addfeature("Sunlight Sensitivity", 1, "You have disadvantage on attack rolls and on Wisdom(Perception) checks that rely on sight when you, the target of your attack, or whatever you are trying to perceive is in direct sunlight.");
			addfeature("Drow Magic", 1, "You know the dancing lights cantrip.(added) When you reach 3rd level, you can cast the faerie fire spell once per day. When you reach 5th level, you can also cast the darkness spell once per day. Charisma is your spellcasting ability for these spells.");
			spellLookup("Dancing Lights", CHA);
			addfeature("Drow Weapon Training", 1, "You have proficiency with rapiers, shortswords, and hand crossbows.(added)");
			addfeature("Rapier", 4);
			addfeature("Shortsword", 4);
			addfeature("Hand crossbow", 4);
			break;
		}
		setsize(2);
		adddex(2);
		addfeature("Darkvision", 1, "Accustomed to twilit forests and the night sky, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can't discern color in darkness, only shades of gray.");
		addfeature("Keen Senses", 1, "You have proficiency in the Perception skill.(added)");
		setssProf(17);
		addfeature("Fey Ancestry", 1, "You have advantage on saving throws against being charmed, and magic can't put you to sleep.");
		addfeature("Trance", 1, "Elves don't need to sleep. Instead, they meditate deeply, remaining semiconscious, for 4 hours a day. (The Common word for such meditation is \"trance.\") While meditating, you can dream after a fashion; such dreams are actually mental exercises that have become reflexive through years of practice. After resting in this way, you gain the same benefit that a human does from 8 hours of sleep.");
		break;
	case 4:
		addfeature("Gnomish", 3);
		std::cout << "Choose Subrace:\n  Forest(1)\n  Rock(2)" << endl;
		selector = intValid(3);
		if (selector == 1) {
			setRace("Forest Gnome");
			adddex(1);
			addfeature("Natural Illusionist", 1, "You know the minor illusion cantrip. Intelligence is your spellcasting ability for it.(added)");
			spellLookup("Minor Illusion", INTEL);
			addfeature("Speak with Small Beasts", 1, "Through sounds and gestures, you can communicate simple ideas with Small or smaller beasts. Forest gnomes love animals and often keep squirrels, badgers, rabbits, moles, woodpeckers, and other creatures as beloved pets.");
		}
		else {
			setRace("Rock Gnome");
			addcon(1);
			addfeature("Artificer's Lore", 1, "Whenever you make an Intelligence(History) check related to magic items, alchemical objects, or technological devices, you can add twice your proficiency bonus, instead of any proficiency bonus you normally apply.");
			addfeature("Tinker", 1, "You have proficiency with artisan's tools(tinker's tools).(added) Using those tools, you can spend 1 hour and 10 gp worth of materials to construct a Tiny clockwork device(AC 5, 1 hp). The device ceases to function after 24 hours(unless you spend 1 hour repairing it to keep the device functioning), or when you use your action to dismantle it; at that time, you can reclaim the materials used to create it. You can have up to three such devices active at a time.\nWhen you create a device, choose one of the following options:\n* Clockwork Toy. This toy is a clockwork animal, monster, or person, such as a frog, mouse, bird, dragon, or soldier. When placed on the ground, the toy moves 5 feet across the ground on each of your turns in a random direction. It makes noises as appropriate to the creature it represents.\n* Fire Starter. The device produces a miniature flame, which you can use to light a candle, torch, or campfire. Using the device requires your action.\n* Music Box. When opened, this music box plays a single song at a moderate volume. The box stops playing when it reaches the song's end or when it is closed.");
			addfeature("Tinker's tools", 6);
		}
		setsize(1);
		addint(2);
		setspd(25);
		addfeature("Darkvision", 1, "Accustomed to life underground, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can't discern color in darkness, only shades of gray.");
		addfeature("Gnome Cunning", 1, "You have advantage on all Intelligence, Wisdom, and Charisma saving throws against magic.");
		break;
	case 5:
		addfeature("Elvish", 3);
		setRace("Half-Elf");
		std::cout << "Choose ability score(1/2):\n  STR(1)\n  DEX(2)\n  CON(3)\n  INT(4)\n  WIS(5)\n  CHA(6)" << endl;
		while (!flag) {
			if (premain == 1)
				std::cout << "Choose a different ability score(2/2):\n  STR(1)\n  DEX(2)\n  CON(3)\n  INT(4)\n  WIS(5)\n  CHA(6)" << endl;
			selector = intValid(7);
			if (tempselect != selector) {
				tempselect = selector;
				premain--;
				switch (selector) {
				case 1:
					addstr(1);
					std::cout << "STR added.." << endl;
					break;
				case 2:
					adddex(1);
					std::cout << "DEX added.." << endl;
					break;
				case 3:
					addcon(1);
					std::cout << "CON added.." << endl;
					break;
				case 4:
					addint(1);
					std::cout << "INT added.." << endl;
					break;
				case 5:
					addwis(1);
					std::cout << "WIS added.." << endl;
					break;
				case 6:
					addcha(1);
					std::cout << "CHA added.." << endl;
					break;
				}
				if (premain == 0)
					flag = true;
			}
			else
				std::cout << "Stat added already..Choose again" << endl;
		}
		setsize(2);
		addcha(2);
		setspd(30);
		addfeature("Darkvision", 1, "Thanks to your elf blood, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can't discern color in darkness, only shades of gray.");
		addfeature("Fey Ancestry", 1, "You have advantage on saving throws against being charmed, and magic can't put you to sleep.");
		addfeature("Skill Versatility", 1, "You gain proficiency in two skills of your choice.(added)");
		for (int i = 0; i < 2; i++) {
			if (i == 0)
				std::cout << "Choose Skill(1/2):" << endl;
			else
				std::cout << "Choose Skill(2/2):" << endl;
			std::cout << "  Acrobatics(1)\n  Animal Handling(2)\n  Arcana(3)\n  Athletics(4)\n  Deception(5)\n  History(6)\n  Insight(7)\n  Intimidation(8)\n  Investigation(9)\n  Medicine(10)\n  Nature(11)\n  Perception(12)\n  Performance(13)\n  Persuasion(14)\n  Religion(15)\n  Sleight of Hand(16)\n  Stealth(17)\n  Survival(18)" << endl;
			selector = intValid(19);
			setssProf(selector + 5);
		}
		break;
	case 6:
		addfeature("Orc", 3);
		setRace("Half-Orc");
		setsize(2);
		addstr(2);
		addcon(1);
		setspd(30);
		addfeature("Darkvision", 1, "Thanks to your orc blood, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can't discern color in darkness, only shades of gray");
		addfeature("Menacing", 1, "You gain proficiency in the Intimidation skill.(added)");
		setssProf(13);
		addfeature("Relentless Endurance", 1, "When you are reduced to 0 hit points but not killed outright, you can drop to 1 hit point instead. You can't use this feature again until you finish a long rest.");
		addfeature("Savage Attacks", 1, "When you score a critical hit with a melee weapon attack, you can roll one of the weapon's damage dice one additional time and add it to the extra damage of the critical hit.");
		break;
	case 7:
		addfeature("Halfling", 3);
		std::cout << "\nChoose Subrace:\n  Lightfoot(1)\n  Stout(2)" << endl;
		selector = intValid(3);
		if (selector == 1) {
			setRace("Lightfoot Halfling");
			addcha(1);
			addfeature("Naturally Stealthy", 1, "You can attempt to hide even when you are obscured only by a creature that is at least one size larger than you.");
		}
		else {
			setRace("Stout Halfling");
			addcon(1);
			addfeature("Stout Resilience", 1, "You have advantage on saving throws against poison, and you have resistance against poison damage.");
		}
		setsize(1);
		adddex(2);
		setspd(25);
		addfeature("Lucky", 1, "When you roll a 1 on an attack roll, ability check, or saving throw, you can reroll the die and must use the new roll.");
		addfeature("Brave", 1, "You have advantage on saving throws against being frightened.");
		addfeature("Halfling Nimbleness", 1, "You can move through the space of any creature that is of a size larger than yours.");
		break;
	case 8:
		std::cout << "Choose Variant?\n  No(1)\n  Yes(2)" << endl;
		selector = intValid(3);
		if (selector == 1) {
			setRace("Human");
			addstr(1);
			adddex(1);
			addcon(1);
			addint(1);
			addwis(1);
			addcha(1);
		}
		else {
			setRace("Human(Variant)");
			flag = false;
			std::cout << "Choose ability score(1/2):\n  STR(1)\n  DEX(2)\n  CON(3)\n  INT(4)\n  WIS(5)\n  CHA(6)" << endl;
			while (!flag) {
				if (premain == 1)
					std::cout << "Choose a different ability score(2/2):\n  STR(1)\n  DEX(2)\n  CON(3)\n  INT(4)\n  WIS(5)\n  CHA(6)" << endl;
				selector = intValid(7);
				if (tempselect != selector) {
					tempselect = selector;
					premain--;
					switch (selector) {
					case 1:
						addstr(1);
						std::cout << "STR added.." << endl;
						break;
					case 2:
						adddex(1);
						std::cout << "DEX added.." << endl;
						break;
					case 3:
						addcon(1);
						std::cout << "CON added.." << endl;
						break;
					case 4:
						addint(1);
						std::cout << "INT added.." << endl;
						break;
					case 5:
						addwis(1);
						std::cout << "WIS added.." << endl;
						break;
					case 6:
						addcha(1);
						std::cout << "CHA added.." << endl;
						break;
					}
					if (premain == 0)
						flag = true;
				}
				else
					std::cout << "Stat added already..Choose again" << endl;
			}
			std::cout << "Choose Skill:\n  Acrobatics(1)\n  Animal Handling(2)\n  Arcana(3)\n  Athletics(4)\n  Deception(5)\n  History(6)\n  Insight(7)\n  Intimidation(8)\n  Investigation(9)\n  Medicine(10)\n  Nature(11)\n  Perception(12)\n  Performance(13)\n  Persuasion(14)\n  Religion(15)\n  Sleight of Hand(16)\n  Stealth(17)\n  Survival(18)" << endl;
			selector = intValid(19);
			setssProf(selector + 5);
		}
		setsize(2);
		setspd(30);
		break;
	case 9:
		addfeature("Infernal", 3);
		setRace("Tiefling");
		setsize(2);
		addint(1);
		addcha(2);
		setspd(30);
		addfeature("Darkvision", 1, "Thanks to your infernal heritage, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can't discern color in darkness, only shades of gray.");
		addfeature("Hellish Resistance", 1, "You have resistance to fire damage.");
		addfeature("Infernal Legacy", 1, "You know the thaumaturgy cantrip.(added) Once you reach 3rd level, you can cast the hellish rebuke spell once per day as a 2nd-level spell. Once you reach 5th level, you can also cast the darkness spell once per day. Charisma is your spellcasting ability for these spells.");
		spellLookup("Thaumaturgy", CHA);
		break;
	}
}
void Player::calcmaxHP() {
	int temp;
	int mod = calcmod(getcon());
	switch (PCclass) {
	case barbarian: //d12 
		addmaxhp(temp = 12 + mod);
		break;
	case fighter: //d10
	case paladin:
	case ranger:
		addmaxhp(temp = 10 + mod);
		break;
	case bard: //d8
	case cleric:
	case druid:
	case monk:
	case rogue:
	case warlock:
		addmaxhp(temp = 8 + mod);
		break;
	case sorcerer: //d6
	case wizard:
		addmaxhp(temp = 6 + mod);
		break;
	}
	setcurhp(getmaxhp());
}
void Player::refCarry() {
	float heavy = 0;
	heavy += (float)getGp() / (float)50;
	for (auto it = weaponInv.begin(); it != weaponInv.end(); ++it)
	{
		heavy += it->getWeight() * (float)it->getqty();
	}
	for (auto it = armorInv.begin(); it != armorInv.end(); ++it)
	{
		heavy += it->getWeight() * (float)it->getqty();
	}
	for (auto it = toolInv.begin(); it != toolInv.end(); ++it)
	{
		heavy += it->getWeight() * (float)it->getqty();
	}
	for (auto it = gearInv.begin(); it != gearInv.end(); ++it)
	{
		heavy += it->getWeight() * (float)it->getqty();
	}
	setCarry(heavy);
}
int Player::calcMaxCarry() {
	return getstr() * 15;
}
int Player::profBonus() {
	int prof = (int)ceil((float)getLevel()/4.0f) + 1;
	return prof;
}
void Player::AbiScoreMethod(int method) {
	vector<int> tempstats = { 15, 14, 13, 12, 10, 8 };;
	int i;
	int point = 27;
	int temp;
	int selector;
	vector<spellAbility> ScoreDecide = {STR,DEX,CON,INTEL,WIS,CHA};
	switch(method) {
	case 2: // randomize
		for (i = 0; i < 6; i++) {
			tempstats[i] = statrolls();
		}
		break;
	case 3: //point-buy
		std::cout << "\nAbility Score Point Cost:" << endl;
		std::cout << "  Score\tCost\n  8\t0\n  9\t1\n  10\t2\n  11\t3\n  12\t4\n  13\t5\n  14\t7\n  15\t9" << endl;
		i = 1;
		while (i < 7) {
			std::cout << "\nCurrent points: " << point << endl;
			std::cout << "Enter desired ability score(" << i << "/6)" << endl;
			selector = intValid(16, 8);
			switch (selector) {
			case 8:
				temp = point;
				break;
			case 9:
				temp = point - 1;
				break;
			case 10:
				temp = point - 2;
				break;
			case 11:
				temp = point - 3;
				break;
			case 12:
				temp = point - 4;
				break;
			case 13:
				temp = point - 5;
				break;
			case 14:
				temp = point - 7;
				break;
			case 15:
				temp = point - 9;
				break;
			default:
				break;
			}
			if (temp >= 0) {
				point = temp;
				tempstats[i - 1] = selector;
				i++;
			}
			else
				std::cout << "Point cost exceeds remaining points..Choose again" << endl;
		}
		if (point != 0)
			std::cout << "You still have leftover points..Please reallocate stats" << endl;
		while (point != 0) {
			bool valid = false;
			std::cout << "\nCurrent points: " << point << endl;
			std::cout << "Choose ability score to change:" << endl;
			for (i = 0; i < 6; i++) {
				std::cout << tempstats[i] << " ";
			}
			std::cout << endl;
			selector = intValid(16, 8);
			i = 0;
			while(i < 6) {
				if (tempstats[i] == selector) {
					while (!valid) {
						std::cout << "Change " << tempstats[i] << " to: " << endl;
						selector = intValid(16, 8);
						switch (tempstats[i]) {
						case 8:
							temp = point;
							break;
						case 9:
							temp = point + 1;
							break;
						case 10:
							temp = point + 2;
							break;
						case 11:
							temp = point + 3;
							break;
						case 12:
							temp = point + 4;
							break;
						case 13:
							temp = point + 5;
							break;
						case 14:
							temp = point + 7;
							break;
						case 15:
							temp = point + 9;
							break;
						default:
							break;
						}
						switch (selector) {
						case 8:
							break;
						case 9:
							temp -= 1;
							break;
						case 10:
							temp -= 2;
							break;
						case 11:
							temp -= 3;
							break;
						case 12:
							temp -= 4;
							break;
						case 13:
							temp -= 5;
							break;
						case 14:
							temp -= 7;
							break;
						case 15:
							temp -= 9;
							break;
						default:
							break;
						}
						if (temp >= 0) {
							point = temp;
							tempstats[i] = selector;
							valid = true;
						}
						else {
							std::cout << "Point cost exceeds remaining points..Choose again" << endl;
						}
					}
				}
				i++;
			}
			if(!valid) {
				std::cout << "Number not found..Enter a valid number"<< endl;
			}
		}
		break;
	default: //standard
		break;
	}
	std::cout << "\nYour ability scores: " << endl;
	for (i = 0; i < 6; i++) {
		std::cout << tempstats[i] << " ";
	}
	std::cout << endl;
	for (i = 0; i < 6; i++) {
		std::cout << "\nChoose ability score to be set as " << tempstats[i] << ":" << endl;
		for (unsigned int j = 0; j < ScoreDecide.size(); j++) {
			switch (ScoreDecide[j]) {
			case STR:
				std::cout << "  STR(" << j + 1 << ")" << endl;
				break;
			case DEX:
				std::cout << "  DEX(" << j + 1 << ")" << endl;
				break;
			case CON:
				std::cout << "  CON(" << j + 1 << ")" << endl;
				break;
			case INTEL:
				std::cout << "  INT(" << j + 1 << ")" << endl;
				break;
			case WIS:
				std::cout << "  WIS(" << j + 1 << ")" << endl;
				break;
			case CHA:
				std::cout << "  CHA(" << j + 1 << ")" << endl;
				break;
			}
		}
		selector = intValid(ScoreDecide.size() + 1);
		switch (ScoreDecide[selector - 1]) {
		case STR:
			addstr(tempstats[i]);
			break;
		case DEX:
			adddex(tempstats[i]);
			break;
		case CON:
			addcon(tempstats[i]);
			break;
		case INTEL:
			addint(tempstats[i]);
			break;
		case WIS:
			addwis(tempstats[i]);
			break;
		case CHA:
			addcha(tempstats[i]);
			break;
		}
		ScoreDecide.erase(ScoreDecide.begin() + selector - 1);
	}
	/*
	std::sort(tempstats.begin(), tempstats.end(), std::greater<int>());
	switch (PCclass) {
	case barbarian:
		addstr(tempstats[0]);
		addcon(tempstats[1]);
		adddex(tempstats[2]);
		addcha(tempstats[3]);
		addwis(tempstats[4]);
		addint(tempstats[5]);
		break;
	case bard:
		addcha(tempstats[0]);
		adddex(tempstats[1]);
		addcon(tempstats[2]);
		addwis(tempstats[3]);
		addstr(tempstats[4]);
		addint(tempstats[5]);
		break;
	case cleric:
		addwis(tempstats[0]);
		addcon(tempstats[1]);
		addstr(tempstats[2]);
		adddex(tempstats[3]);
		addcha(tempstats[4]);
		addint(tempstats[5]);
		break;
	case druid:
		addwis(tempstats[0]);
		adddex(tempstats[1]);
		addcon(tempstats[2]);
		addcha(tempstats[3]);
		addint(tempstats[4]);
		addstr(tempstats[5]);
		break;
	case fighter:
		addstr(tempstats[0]);
		addcon(tempstats[1]);
		adddex(tempstats[2]);
		addwis(tempstats[3]);
		addcha(tempstats[4]);
		addint(tempstats[5]);
		break;
	case monk:
		adddex(tempstats[0]);
		addwis(tempstats[1]);
		addcon(tempstats[2]);
		addstr(tempstats[3]);
		addcha(tempstats[4]);
		addint(tempstats[5]);
		break;
	case paladin:
		addcha(tempstats[0]);
		addstr(tempstats[1]);
		addcon(tempstats[2]);
		adddex(tempstats[3]);
		addwis(tempstats[4]);
		addint(tempstats[5]);
		break;
	case ranger:
		adddex(tempstats[0]);
		addcon(tempstats[1]);
		addwis(tempstats[2]);
		addstr(tempstats[3]);
		addcha(tempstats[4]);
		addint(tempstats[5]);
		break;
	case rogue:
		adddex(tempstats[0]);
		addwis(tempstats[1]);
		addcon(tempstats[2]);
		addint(tempstats[3]);
		addcha(tempstats[4]);
		addstr(tempstats[5]);
		break;
	case sorcerer:
		addcha(tempstats[0]);
		adddex(tempstats[1]);
		addcon(tempstats[2]);
		addwis(tempstats[3]);
		addint(tempstats[4]);
		addstr(tempstats[5]);
		break;
	case warlock:
		addcha(tempstats[0]);
		addcon(tempstats[1]);
		adddex(tempstats[2]);
		addwis(tempstats[3]);
		addstr(tempstats[4]);
		addint(tempstats[5]);
		break;
	case wizard:
		addint(tempstats[0]);
		adddex(tempstats[1]);
		addcon(tempstats[2]);
		addwis(tempstats[3]);
		addstr(tempstats[4]);
		addcha(tempstats[5]);
		break;
	}
	*/
}
void Player::calcStatFeatures() {
	unordered_set<Feature>::iterator it;
	switch (PCclass) {
	case barbarian:
		setac(10 + calcmod(getdex()) + calcmod(getcon()));
		break;
	case bard:
		setac(10 + calcmod(getdex()));
		addresource("Bardic Inspiration", calcmod(getcha()), 2);
		break;
	case cleric:
		setac(10 + calcmod(getdex()));
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Warding Flare"));
		if (it != classfeatures.end()) {
			addresource("Warding Flare", calcmod(getwis()), 2);
		}
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Wrath of the Storm"));
		if (it != classfeatures.end()) {
			addresource("Wrath of the Storm", calcmod(getwis()), 2);
		}
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("War Priest"));
		if (it != classfeatures.end()) {
			addresource("War Priest", calcmod(getwis()), 2);
		}
		break;
	case druid:
		setac(10 + calcmod(getdex()));
		break;
	case fighter:
		setac(10 + calcmod(getdex()));
		break;
	case monk:
		setac(10 + calcmod(getdex()) + calcmod(getwis()));
		break;
	case paladin:
		setac(10 + calcmod(getdex()));
		addresource("Divine Sense", 1 + calcmod(getcha()), 2);
		break;
	case ranger:
		setac(10 + calcmod(getdex()));
		break;
	case rogue:
		setac(10 + calcmod(getdex()));
		break;
	case sorcerer:
		setac(10 + calcmod(getdex()));
		it = find_if(classfeatures.begin(), classfeatures.end(), find_by_name<Feature>("Draconic Resilience"));
		if (it != classfeatures.end()) {
			setac(13 + calcmod(getdex()));
		}
		break;
	case warlock:
		setac(10 + calcmod(getdex()));
		break;
	case wizard:
		setac(10 + calcmod(getdex()));
		break;
	}
	calcmaxHP();
	setinit(calcmod(getdex()));
	if (savingSkillsProf[17])
		setpasper(10 + calcmod(getwis()) + profBonus());
	else
		setpasper(10 + calcmod(getwis()));
}
void Player::setstats() {
	int selector = 0;
	int tempstats[6];
	bool money = false;
	std::cout << "Enter name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	level = 1;
	setstr(0);
	setdex(0);
	setcon(0);
	setint(0);
	setwis(0);
	setcha(0);

	std::cout << "\nChoose ability score distribution method:\n  Standard Array(1)\n  Random Roll(2)\n  Point-Buy(3)" << endl;
	selector = intValid(4);
	AbiScoreMethod(selector);

	std::cout << "\nStart with starter gear or money? Gear(1) Money(2)" << endl;
	selector = intValid(3);
	if (selector == 2)
		money = true;
	selector = 0;

	std::cout << "\nChoose a race:\n  Dragonborn(1)\n  Dwarf(2)\n  Elf(3)\n  Gnome(4)\n  Half-Elf(5)\n  Half-Orc(6)\n  Halfling(7)\n  Human(8)\n  Tiefling(9)" << endl;
	selector = intValid(10);
	insertRace(selector);
	selector = 0;

	std::cout << "\nChoose a class:\n  Barbarian(1)\n  Bard(2)\n  Cleric(3)\n  Druid(4)\n  Fighter(5)\n  Monk(6)\n  Paladin(7)\n  Ranger(8)\n  Rogue(9)\n  Sorcerer(10)\n  Warlock(11)\n  Wizard(12)" << endl;
	selector = intValid(13);
	PCclass = (classes)(selector - 1);
	classRoll(tempstats, money);
	selector = 0;

	if (getRace() == "High Elf" || getRace() == "Half-Elf" || getRace() == "Human" || getRace() == "Human(Variant)") {
		addlang();
	}

	std::cout << "\nChoose an alignment:\n  Lawful good(1)\n  Neutral good(2)\n  Chaotic good(3)\n  Lawful neutral(4)\n  Neutral(5)\n  Chaotic neutral(6)\n  Lawful evil(7)\n  Neutral evil(8)\n  Chaotic evil(9)" << endl;
	selector = intValid(10);
	setAlign(selector);
	selector = 0;

	std::cout << "\nChoose a background:\n  Acolyte(1)\n  Charlatan(2)\n  Criminal(3)\n  Entertainer(4)\n  Folk Hero(5)\n  Guild Artisan(6)\n  Hermit(7)\n  Noble(8)\n  Outlander(9)\n  Sage(10)\n  Sailor(11)\n  Soldier(12)\n  Urchin(13)" << endl;
	selector = intValid(14);
	setBG(selector, money);
	refCarry();
	selector = 0;
	classSkill();
	featAdder();
	calcStatFeatures();
	classSpells();

	std::cout << "\nEnter age: ";
	std::cin.ignore(INT_MAX, '\n');
	std::getline(std::cin, age);
	if (age.size() > 140)
		age.resize(140);
	std::cout << "\nEnter gender: ";
	std::getline(std::cin, sex);
	if (sex.size() > 140)
		sex.resize(140);
	std::cout << "\nEnter height: ";
	std::getline(std::cin, height);
	if (height.size() > 140)
		height.resize(140);
	std::cout << "\nEnter weight: ";
	std::getline(std::cin, weight);
	if (weight.size() > 140)
		weight.resize(140);
	std::cout << "\nEnter eye color: ";
	std::getline(std::cin, eyes);
	if (eyes.size() > 140)
		eyes.resize(140);
	std::cout << "\nEnter skin color: ";
	std::getline(std::cin, skin);
	if (skin.size() > 140)
		skin.resize(140);
	std::cout << "\nEnter hair color: ";
	std::getline(std::cin, hair);
	if (skin.size() > 140)
		skin.resize(140);

	std::cout << "\n\nMAXHP: " << getmaxhp();
	std::cout << "\nSTR: " << getstr();
	std::cout << "\nDEX: " << getdex();
	std::cout << "\nCON: " << getcon();
	std::cout << "\nINT: " << getint();
	std::cout << "\nWIS: " << getwis();
	std::cout << "\nCHA: " << getcha();
	std::cout << "\nStarting money: " << getGp() << " gp";
	std::cout << "\nCharacter created..." << endl;
}
void Player::listfeatures() {
	std::cout << "  <CLASS FEATURES>" << endl;
	for (auto it = classfeatures.begin(); it != classfeatures.end(); ++it)
	{
		std::cout << "  ~" << it->getName() << "~" << endl;
		if (it->getDesc() != "")
			std::cout << it->getDesc() << endl;
		std::cout << endl;
	}
	std::cout << "  <RACE TRAITS>" << endl;
	for (auto it = racefeatures.begin(); it != racefeatures.end(); ++it)
	{
		std::cout << "  ~" << it->getName() << "~" << endl;
		std::cout << it->getDesc() << endl;
		std::cout << endl;
	}
	std::cout << "  <LANGUAGES>" << endl;
	for (auto it = lang.begin(); it != lang.end(); ++it)
	{
		std::cout << "  " << *it << endl;
	}
	std::cout << "\n  <BACKGROUND FEATURE>" << endl;
	for (auto it = bgfeatures.begin(); it != bgfeatures.end(); ++it)
	{
		std::cout << "  ~" << it->getName() << "~" << endl;
		std::cout << it->getDesc() << endl;
		std::cout << endl;
	}
	if (!feats.empty()) {
		std::cout << "  <FEATS>" << endl;
		for (auto it = feats.begin(); it != feats.end(); ++it)
		{
			std::cout << "  ~" << it->getName() << "~" << endl;
			std::cout << it->getDesc() << endl;
			std::cout << endl;
		}
	}
	std::cout << "  <SAVING THROWS>" << endl;
	if (savingSkillsProf[0])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << "STR: " << setw(2) << getssProf(0) << endl;
	if (savingSkillsProf[1])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << "DEX: " << setw(2) << getssProf(1) << endl;
	if (savingSkillsProf[2])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << "CON: " << setw(2) << getssProf(2) << endl;
	if (savingSkillsProf[3])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << "INT: " << setw(2) << getssProf(3) << endl;
	if (savingSkillsProf[4])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << "WIS: " << setw(2) << getssProf(4) << endl;
	if (savingSkillsProf[5])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << "CHA: " << setw(2) << getssProf(5) << endl;

	std::cout << "\n  <SKILLS>" << endl;
	if (savingSkillsProf[6])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Acrobatics: " << right << setw(2) << getssProf(6) << endl;
	if (savingSkillsProf[7])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Animal Handling " << right << setw(2) << getssProf(7) << endl;
	if (savingSkillsProf[8])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Arcana: " << right << setw(2) << getssProf(8) << endl;
	if (savingSkillsProf[9])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Athletics: " << right << setw(2) << getssProf(9) << endl;
	if (savingSkillsProf[10])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Deception: " << right << setw(2) << getssProf(10) << endl;
	if (savingSkillsProf[11])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "History: " << right << setw(2) << getssProf(11) << endl;
	if (savingSkillsProf[12])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Insight: " << right << setw(2) << getssProf(12) << endl;
	if (savingSkillsProf[13])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Intimidation: " << right << setw(2) << getssProf(13) << endl;
	if (savingSkillsProf[14])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Investigation: " << right << setw(2) << getssProf(14) << endl;
	if (savingSkillsProf[15])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Medicine: " << right << setw(2) << getssProf(15) << endl;
	if (savingSkillsProf[16])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Nature: " << right << setw(2) << getssProf(16) << endl;
	if (savingSkillsProf[17])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Perception: " << right << setw(2) << getssProf(17) << endl;
	if (savingSkillsProf[18])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Performance: " << right << setw(2) << getssProf(18) << endl;
	if (savingSkillsProf[19])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Persuasion: " << right << setw(2) << getssProf(19) << endl;
	if (savingSkillsProf[20])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Religion: " << right << setw(2) << getssProf(20) << endl;
	if (savingSkillsProf[21])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Sleight of Hand: " << right << setw(2) << getssProf(21) << endl;
	if (savingSkillsProf[22])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Stealth: " << right << setw(2) << getssProf(22) << endl;
	if (savingSkillsProf[23])
		std::cout << "  * ";
	else
		std::cout << "    ";
	std::cout << left << setw(17) << "Survival: " << right << setw(2) << getssProf(23) << endl;

	std::cout << "\n  <WEAPON PROFICIENCIES>" << endl;
	for (auto it = weaponProf.begin(); it != weaponProf.end(); ++it)
	{
		std::cout << "  " << *it << endl;
	}
	std::cout << "\n  <ARMOR PROFICIENCIES>" << endl;
	for (auto it = armorProf.begin(); it != armorProf.end(); ++it)
	{
		std::cout << "  " << *it << endl;
	}
	if (!toolProf.empty()) {
		std::cout << "\n  <TOOL PROFICIENCIES>" << endl;
		for (auto it = toolProf.begin(); it != toolProf.end(); ++it)
		{
			std::cout << "  " << *it << endl;
		}
	}
}
void Player::displaystats() {
	std::cout << "  Level: " << getLevel() << endl;
	std::cout << "  Class: " << getClass() << endl;
	std::cout << "  Race: " << getRace() << endl;
	std::cout << "  Type: " << getType() << endl;
	std::cout << "  Size: " << getsize() << endl;
	std::cout << "  Walking Speed: " << getspd() << " feet";
	if (getSpec().compare("None") == 0) {
		std::cout << endl;
	}
	else {
		std::cout << " *" << getSpec() << endl;
	}
	std::cout << "  Alignment: " << getAlign() << endl;
	std::cout << "  Background: " << getBG() << endl;
	std::cout << "  Proficiency Bonus: " << profBonus() << endl;
	std::cout << "  Initiative: " << getinit() << endl;
	std::cout << "  Passive Perception: " << getpasper() << endl;
	std::cout << "  Armor Class: " << getac() << " (Unarmored)" << endl;

	std::cout << "\n  APPEARANCE" << endl;
	std::cout << "  ==========" << endl;
	std::cout << "  Age:    " << getAge() << endl;
	std::cout << "  Sex:    " << getSex() << endl;
	std::cout << "  Eyes:   " << getEyes() << endl;
	std::cout << "  Skin:   " << getSkin() << endl;
	std::cout << "  Hair:   " << getHair() << endl;
	std::cout << "  Height: " << getH() << endl;
	std::cout << "  Weight: " << getW() << endl;

	std::cout << "\n  STATS" << endl;
	std::cout << "  =====" << endl;
	std::cout << "  Max HP: " << setw(2) << getmaxhp() << endl;
	std::cout << "  STR:    " << setw(2) << getstr() << endl;
	std::cout << "  DEX:    " << setw(2) << getdex() << endl;
	std::cout << "  CON:    " << setw(2) << getcon() << endl;
	std::cout << "  INT:    " << setw(2) << getint() << endl;
	std::cout << "  WIS:    " << setw(2) << getwis() << endl;
	std::cout << "  CHA:    " << setw(2) << getcha() << endl;

	if (!resources.empty()) {
		std::cout << "\n  RESOURCES:" << endl;
		std::cout << "  ==========" << endl;
		for (auto it = resources.begin(); it != resources.end(); ++it)
		{
			vector<int> temp = it->getMax();
			if (temp.size() == 9) {
				std::cout << "\n  " << it->getName() << ":" << endl;
				if (temp[0] != 0)
					std::cout << "  1st: " << temp[0] << endl;
				if (temp[1] != 0)
					std::cout << "  2nd: " << temp[1] << endl;
				if (temp[2] != 0)
					std::cout << "  3rd: " << temp[2] << endl;
				if (temp[3] != 0)
					std::cout << "  4th: " << temp[3] << endl;
				if (temp[4] != 0)
					std::cout << "  5th: " << temp[4] << endl;
				if (temp[5] != 0)
					std::cout << "  6th: " << temp[5] << endl;
				if (temp[6] != 0)
					std::cout << "  7th: " << temp[6] << endl;
				if (temp[7] != 0)
					std::cout << "  8th: " << temp[7] << endl;
				if (temp[8] != 0)
					std::cout << "  9th: " << temp[8] << endl;
			}
			else
				std::cout << "  " << it->getName() << ": " << temp[0] << endl;
		}
	}

	std::cout << "\n  FEATURES, TRAITS, & FEATS" << endl;
	std::cout << "  =========================" << endl;
	listfeatures();

	if (!spellList.empty()) {
		std::cout << "\n  SPELLS" << endl;
		std::cout << "  ======";
		bool prepare = false;
		std::cout << "\n  Known Spells: "<< endl;
		for (auto it = spellList.begin(); it != spellList.end(); ++it) {
			if (!prepare && (*it)->getPrepare()) {
				std::cout << "\n  Prepared Spells:" << endl;
				prepare = true;
			}
			std::cout << "\n  " << (*it)->getName() << endl;
			if ((*it)->getLvl() == 0)
				std::cout << "    " << (*it)->getType() << " Cantrip";
			else {
				switch ((*it)->getLvl()) {
				case 1:
					std::cout << "    1st-level ";
					break;
				case 2:
					std::cout << "    2nd-level ";
					break;
				case 3:
					std::cout << "    3rd-level ";
					break;
				default:
					std::cout << "    " << (*it)->getLvl() << "th-level ";
					break;
				}
				std::cout << (*it)->getType();
			}
			if ((*it)->getRitual())
				std::cout << " (ritual)";
			std::cout << endl;
			std::cout << "    Casting Time: " << (*it)->getCastTime() << endl;
			std::cout << "    Range: " << (*it)->getSpellRange() << endl;
			std::cout << "    Components: " << (*it)->getComponents() << endl;
			std::cout << "    Duration: " << (*it)->getDuration() << endl;
			std::cout << (*it)->getDesc() << endl;
		}
	}

	std::cout << "\n  EQUIPMENT" << endl;
	std::cout << "  =========" << endl;
	std::cout << "  Carry Capacity: " << "Current(" << getCarry() << " lbs) Max(" << calcMaxCarry() << " lbs)" << endl;
	std::cout << "  cp: " << getCp() << " || sp: " << getSp() << " || ep: " << getEp() << " || gp: " << getGp() << " || pp: " << getPp() << endl;
	listInv();

	if (mounts.size() > 0) {
		for (unsigned int i = 0; i < mounts.size(); i++) {
			mounts[i].listInv();
		}
	}
}
bool Player::report(bool flag)
{
	bool tracker = false;
	if (!flag) {
		if (name.size() > 20) {
			std::cout << "  " << left << setw(20) << name.substr(0, 20) << "..";
			tracker = true;
		}
		else
			std::cout << "  " << left << setw(22) << name;
		std::cout << "\t" << level << "\t" << getClass() << "     \t" << setw(14) << getRace() << "\t" << right << setw(2) << getstr() << "\t" << setw(2) << getdex() << "\t" << setw(2) << getcon() << "\t" << setw(2) << getint() << "\t" << setw(2) << getwis() << "\t" << setw(2) << getcha() << endl;
	}
	else {
		std::cout << "  " << getName() << endl;
	}
	return tracker;
}