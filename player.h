#pragma once
#include "character.h"
#include <iostream>

enum classes {barbarian, bard, cleric, druid, fighter, monk, paladin, ranger, rogue, sorcerer, warlock, wizard};

class Player : public character {
protected:
	int level;
	classes PCclass;
	int bg;
	float carry = 0;
	string age;
	string height;
	string weight;
	string eyes;
	string skin;
	string hair;
	string special = "None";
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(cereal::base_class<character>(this), level, PCclass, bg, carry, age, height, weight, eyes, skin, hair, special);
	}
public:
	int getLevel()const;
	string getClass()const;
	string getBG() const;
	string getAge() const;
	float getCarry() const;
	string getH() const;
	string getW() const;
	string getEyes() const;
	string getSkin() const;
	string getHair() const;
	string getSpec() const;
	int getssProf(int);

	bool addstr(int, bool = false);
	bool adddex(int, bool = false);
	bool addcon(int, bool = false);
	bool addint(int, bool = false);
	bool addwis(int, bool = false);
	bool addcha(int, bool = false);
	void classSkill();
	void addfeats();
	void featAdder();
	void setBG(int, bool);
	void setAge(string);
	void setCarry(float);
	void setH(string);
	void setW(string);
	void setEyes(string);
	void setSkin(string);
	void setHair(string);
	void setSpec(string);

	void bardSpells();
	void clericSpells();
	void druidSpells();
	void sorcererSpells();
	void warlockSpells();
	void wizardSpells();
	void SpellsbyClass(int, classes, int, bool = false);
	void classSpells();

	void addCarry(float);
	void classRoll(int[], bool);
	void insertRace(int);
	void calcmaxHP();
	void refCarry();
	int calcMaxCarry();
	int profBonus();
	void AbiScoreMethod(int);
	void calcStatFeatures();
	void setstats();
	void listfeatures();
	void displaystats();
	bool report(bool = false);
};