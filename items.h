#pragma once
#include <C:\dev\Project2\Project2\cereal\cereal.hpp>
#include <C:\dev\Project2\Project2\cereal\archives\binary.hpp>
#include <C:\dev\Project2\Project2\cereal\types\base_class.hpp>
#include <C:\dev\Project2\Project2\cereal\types\vector.hpp>
#include <C:\dev\Project2\Project2\cereal\types\string.hpp>
#include <C:\dev\Project2\Project2\cereal\types\unordered_set.hpp>
#include <C:\dev\Project2\Project2\cereal\types\set.hpp>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Feature {
protected:
	string name;
	string desc;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, desc);
	}
public:
	string getName() const;
	string getDesc() const;
	void setName(string);
	void setDesc(string);
};

class Resource {
protected:
	string name;
	vector<int> max;
	vector<int> current;
	int regen;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, max, current, regen);
	}
public:
	string getName() const;
	vector<int> getMax() const;
	vector<int> getCur() const;
	int getRegen() const;

	void setName(string);
	void setMax(int, int);
	bool subCur(int, int);
	void addSlot(int);
	void setRegen(int);
	void rest(int);
};

class Item {
protected:
	string name;
	string type;
	vector<string> properties;
	int cost;
	string coststring;
	float weight;
	int qty = 0;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, type, properties, cost, coststring, weight, qty);
	}
public:
	string getName() const;
	string getType() const;
	vector<string> getProperties();
	int getCost() const;
	string getCoststring() const;
	float getWeight() const;
	int getqty() const;

	void setName(string);
	void setType(string);
	void addProperties(string);
	void setProperties(vector<string>);
	void setCost(int);
	void setCoststring(string);
	void setWeight(float);
	void setqty(int);

	void addqty(int);
};

class Weapon:public Item {
protected:
	int melee;
	int range;
	int maxrange;
	int Ndamage;
	int Sdamage;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(cereal::base_class<Item>(this), melee, range, maxrange, Ndamage, Sdamage);
	}
public:
	int getMelee() const;
	int getRange() const;
	int getMaxRange() const;
	int getNdamage() const;
	int getSdamage() const;

	void setMelee(int);
	void setRange(int);
	void setMaxRange(int);
	void setNdamage(int);
	void setSdamage(int);
	void copy(Weapon);
};

class Armor:public Item {
protected:
	int AC;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(cereal::base_class<Item>(this), AC);
	}
public:
	int getAC() const;
	void setAC(int);
	void copy(Armor);
};

class Gear :public Item {
protected:
	int range;
	int maxrange;
	int Ndamage;
	int Sdamage;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(cereal::base_class<Item>(this), range, maxrange, Ndamage, Sdamage);
	}
public:
	int getRange() const;
	int getMaxRange() const;
	int getNdamage() const;
	int getSdamage() const;

	void setRange(int);
	void setMaxRange(int);
	void setNdamage(int);
	void setSdamage(int);
	void copy(Gear);
};

class Tool : public Item {
protected:
public:
	void copy(Tool);
};

template<class T>
struct find_by_name {
	find_by_name(const string & Name) : name(Name) {}
	bool operator()(const T & obj) {
		return obj.getName() == name;
	}
private:
	string name;
};

template<class T>
struct InvHash
{
	size_t operator()(const T & obj) const
	{
		return std::hash<std::string>()(obj.getName());
	}
};

template<class T>
struct InvCmp
{
	bool operator()(const T & obj1, const T & obj2) const
	{
		if (obj1.getName() == obj2.getName())
			return true;
		return false;
	}
};

class Mount {
protected:
	string name;
	string type;
	int speed;
	float mcarry;
	float ccarry;
	int wallet[5] = { 0 };
	unordered_set<Weapon, InvHash<Weapon>, InvCmp<Weapon>> weaponInv;
	unordered_set<Armor, InvHash<Armor>, InvCmp<Armor>> armorInv;
	unordered_set<Gear, InvHash<Gear>, InvCmp<Gear>> gearInv;
	unordered_set<Tool, InvHash<Tool>, InvCmp<Tool>> toolInv;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, type, speed, mcarry, ccarry, weaponInv, armorInv, gearInv, toolInv);
	}
public:
	string getName() const;
	string getType() const;
	int getspd() const;
	float getMaxCarry() const;
	float getCurCarry() const;
	int getCp() const;
	int getSp() const;
	int getEp() const;
	int getGp() const;
	int getPp() const;

	void setName(string);
	void setType(string);
	void setspd(int);
	void setMaxCarry(float);
	void setCurCarry(float);
	void addCp(int);
	void addSp(int);
	void addEp(int);
	void addGp(int);
	void addPp(int);
	void addWeapon(string, float = 0.0F, int = 1);
	void addArmor(string, float = 0.0F, int = 1);
	void addGear(string, float = 0.0F, int = 1);
	void addTool(string, float = 0.0F, int = 1);
	void delWeapon(string);
	void delArmor(string);
	void delGear(string);
	void delTool(string);
	unordered_set<Weapon>::iterator findWeapon(string);
	unordered_set<Armor>::iterator findArmor(string);
	unordered_set<Gear>::iterator findGear(string);
	unordered_set<Tool>::iterator findTool(string);

	void listInv();
	void refCarry();
};