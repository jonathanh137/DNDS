#include "items.h"

string Feature::getName() const {
	return name;
}
string Feature::getDesc() const {
	return desc;
}
void Feature::setName(string Name) {
	name = Name;
}
void Feature::setDesc(string Desc) {
	desc = Desc;
}

string Resource::getName() const {
	return name;
}
vector<int> Resource::getMax() const {
	return max;
}
vector<int> Resource::getCur() const {
	return current;
}
int Resource::getRegen() const {
	return regen;
}
void Resource::setName(string Name) {
	name = Name;
}
void Resource::setMax(int Max, int index) {
	max[index] = Max;
	current[index] = Max;
}
bool Resource::subCur(int Cur, int index) {
	if (current[index] - Cur < 0) {
		std::cout << "Not enough resource" << endl;
		return false;
	}
	current[index] -= Cur;
	return true;
}
void Resource::addSlot(int increase) {
	max.push_back(increase);
	current.push_back(increase);
}
void Resource::setRegen(int Regen) {
	regen = Regen;
}
void Resource::rest(int Type) {
	if (regen == 0 || Type == regen){ //short rest Type 1 long rest Type 2
		for (int i = 0; i < max.size(); i++)
			current[i] = max[i];
	}
}

string Item::getName() const {
	return name;
}
string Item::getType() const {
	return type;
}
vector<string> Item::getProperties() {
	return properties;
}
int Item::getCost() const {
	return cost;
}
string Item::getCoststring() const {
	return coststring;
}
float Item::getWeight() const {
	return weight;
}
int Item::getqty() const {
	return qty;
}
void Item::setName(string Name) {
	name = Name;
}
void Item::setType(string Type) {
	type = Type;
}
void Item::addProperties(string prop) {
	properties.push_back(prop);
}
void Item::setProperties(vector<string> prop) {
	properties = prop;
}
void Item::setCost(int Cost) {
	cost = Cost;
}
void Item::setCoststring(string Cost) {
	coststring = Cost;
}
void Item::setWeight(float Weight) {
	weight = Weight;
}
void Item::setqty(int q) {
	qty = q;
}
void Item::addqty(int q) {
	qty += q;
}

int Weapon::getMelee() const {
	return melee;
}
int Weapon::getRange() const {
	return range;
}
int Weapon::getMaxRange() const {
	return maxrange;
}
int Weapon::getNdamage() const {
	return Ndamage;
}
int Weapon::getSdamage() const {
	return Sdamage;
}
void Weapon::setMelee(int M) {
	melee = M;
}
void Weapon::setRange(int r) {
	range = r;
}
void Weapon::setMaxRange(int r) {
	maxrange = r;
}
void Weapon::setNdamage(int N) {
	Ndamage = N;
}
void Weapon::setSdamage(int S) {
	Sdamage = S;
}
void Weapon::copy(Weapon w) {
	this->setName(w.getName());
	this->setType(w.getType());
	this->setProperties(w.getProperties());
	this->setCost(w.getCost());
	this->setCoststring(w.getCoststring());
	this->setWeight(w.getWeight());
	this->setqty(w.getqty());
	this->setMelee(w.getMelee());
	this->setRange(w.getRange());
	this->setMaxRange(w.getMaxRange());
	this->setNdamage(w.getNdamage());
	this->setSdamage(w.getSdamage());
}

int Armor::getAC() const {
	return AC;
}
void Armor::setAC(int ac) {
	AC = ac;
}
void Armor::copy(Armor a) {
	this->setName(a.getName());
	this->setType(a.getType());
	this->setProperties(a.getProperties());
	this->setCost(a.getCost());
	this->setCoststring(a.getCoststring());
	this->setWeight(a.getWeight());
	this->setqty(a.getqty());
	this->setAC(a.getAC());
}

int Gear::getRange() const {
	return range;
}
int Gear::getMaxRange() const {
	return maxrange;
}
int Gear::getNdamage() const {
	return Ndamage;
}
int Gear::getSdamage() const {
	return Sdamage;
}
void Gear::setRange(int r) {
	range = r;
}
void Gear::setMaxRange(int r) {
	maxrange = r;
}
void Gear::setNdamage(int N) {
	Ndamage = N;
}
void Gear::setSdamage(int S) {
	Sdamage = S;
}
void Gear::copy(Gear g) {
	this->setName(g.getName());
	this->setType(g.getType());
	this->setProperties(g.getProperties());
	this->setCost(g.getCost());
	this->setCoststring(g.getCoststring());
	this->setWeight(g.getWeight());
	this->setqty(g.getqty());
	this->setRange(g.getRange());
	this->setMaxRange(g.getMaxRange());
	this->setNdamage(g.getNdamage());
	this->setSdamage(g.getSdamage());
}

void Tool::copy(Tool t) {
	this->setName(t.getName());
	this->setType(t.getType());
	this->setProperties(t.getProperties());
	this->setCost(t.getCost());
	this->setCoststring(t.getCoststring());
	this->setWeight(t.getWeight());
	this->setqty(t.getqty());
}

string Mount::getName() const{
	return name;
}
string Mount::getType() const {
	return type;
}
int Mount::getspd() const {
	return speed;
}
float Mount::getMaxCarry() const {
	return mcarry;
}
float Mount::getCurCarry() const {
	return ccarry;
}
int Mount::getCp() const {
	return wallet[0];
}
int Mount::getSp() const {
	return wallet[1];
}
int Mount::getEp() const {
	return wallet[2];
}
int Mount::getGp() const {
	return wallet[3];
}
int Mount::getPp() const {
	return wallet[4];
}
void Mount::setName(string Name) {
	name = Name;
}
void Mount::setType(string nType) {
	type = nType;
}
void Mount::setspd(int spd) {
	speed = spd;
}
void Mount::setMaxCarry(float maxCarry) {
	mcarry = maxCarry;
}
void Mount::setCurCarry(float curCarry) {
	ccarry = curCarry;
}
void Mount::addCp(int cp) {
	wallet[0] += cp;
}
void Mount::addSp(int sp) {
	wallet[1] += sp;
}
void Mount::addEp(int ep) {
	wallet[2] += ep;
}
void Mount::addGp(int gp) {
	wallet[3] += gp;
}
void Mount::addPp(int pp) {
	wallet[4] += pp;
}
void Mount::addWeapon(string wep, float weight, int amt) {
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
void Mount::addArmor(string arm, float weight, int amt) {
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
void Mount::addGear(string gear, float weight, int amt) {
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
void Mount::addTool(string tool, float weight, int amt) {
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
	tempclass.addqty(amt);
	toolInv.emplace(tempclass);
	std::cout << tool << " added.." << endl;
}
void Mount::delWeapon(string wep) {
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
void Mount::delArmor(string arm) {
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
void Mount::delGear(string gear) {
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
void Mount::delTool(string tool) {
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
unordered_set<Weapon>::iterator Mount::findWeapon(string wep) {
	unordered_set<Weapon>::iterator result = find_if(weaponInv.begin(), weaponInv.end(), find_by_name<Weapon>(wep));
	/*if (result == weaponInv.end()) {
	std::cout << "Item not found in weapons" << endl;
	}*/
	return result;
}
unordered_set<Armor>::iterator Mount::findArmor(string arm) {
	unordered_set<Armor>::iterator result = find_if(armorInv.begin(), armorInv.end(), find_by_name<Armor>(arm));
	/*if (result == armorInv.end()) {
	std::cout << "Item not found in armors" << endl;
	}*/
	return result;
}
unordered_set<Gear>::iterator Mount::findGear(string gear) {
	unordered_set<Gear>::iterator result = find_if(gearInv.begin(), gearInv.end(), find_by_name<Gear>(gear));
	/*if (result == gearInv.end()) {
	std::cout << "Item not found in gears" << endl;
	}*/
	return result;
}
unordered_set<Tool>::iterator Mount::findTool(string tool) {
	unordered_set<Tool>::iterator result = find_if(toolInv.begin(), toolInv.end(), find_by_name<Tool>(tool));
	/*if (result == toolInv.end()) {
	std::cout << "Item not found in tools" << endl;
	}*/
	return result;
}
void Mount::listInv() {
	std::cout << "\n  MOUNT INFORMATION\n  ==========" << endl;
	std::cout << "  Name: " << getName() << endl;
	std::cout << "  Type: " << getType() << endl;
	std::cout << "  Speed: " << getspd() << " feet" << endl;
	std::cout << "\n  INVENTORY:\n  ==========" << endl;
	std::cout << "  Carry Capacity: " << "Current(" << getCurCarry() << " lbs) Max(" << getMaxCarry() << " lbs)" << endl;
	std::cout << "  cp: " << getCp() << " || sp: " << getSp() << " || ep: " << getEp() << " || gp: " << getGp() << " || pp: " << getPp() << endl;
	if (!weaponInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<WEAPONS>" << endl;
		for (auto it = weaponInv.begin(); it != weaponInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << setw(6) << it->getqty() << endl;
		}
	}
	if (!armorInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<ARMORS>" << endl;
		for (auto it = armorInv.begin(); it != armorInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << setw(6) << it->getqty() << endl;
		}
	}
	if (!toolInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<TOOLS>" << endl;
		for (auto it = toolInv.begin(); it != toolInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << setw(6) << it->getqty() << endl;
		}
	}
	if (!gearInv.empty()) {
		std::cout << "\n  <QUANTITY>\t<WEIGHT(lbs)>\t<GEARS>" << endl;
		for (auto it = gearInv.begin(); it != gearInv.end(); ++it)
		{
			std::cout << "  " << right << setw(6) << it->getqty() << "\t " << setw(6) << it->getWeight() << "\t\t" << it->getName() << endl;
			//std::cout << "  " << left << setw(20) << it->getName() << "\t" << setw(6) << it->getqty() << endl;
		}
	}
}
void Mount::refCarry() {
	float heavy = 0;
	heavy += ((float)getCp() + (float)getSp() + (float)getEp() + (float)getGp() + (float)getPp()) / (float)50;
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
	setCurCarry(heavy);
}