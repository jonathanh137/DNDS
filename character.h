#pragma once
#include "misc.h"
#include "items.h"
#include "spells.h"
#include <iostream>

class character {
protected:
	string name;
	string race;
	string sex;
	string type;
	string alignment;
	unordered_set<Feature, InvHash<Feature>, InvCmp<Feature>> classfeatures;
	unordered_set<Feature, InvHash<Feature>, InvCmp<Feature>> racefeatures;
	unordered_set<Feature, InvHash<Feature>, InvCmp<Feature>> bgfeatures;
	set<shared_ptr<Spell>, SpellCmp<shared_ptr<Spell>>> spellList;
	unordered_set<string> lang;
	unordered_set<string> weaponProf;
	unordered_set<string> armorProf;
	vector<bool> savingSkillsProf = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };//0:strsave/1:dexsave/2:consave/3:intsave/4:wissave/5:chasave/6:acrobatics/7:animals/8:arcana/9:atheletics/10:deception/11:history/12:insight/13:intimidation/14:investigation/15:medicine/16:nature/17:perception/18:performance/19:persuasion/20:religion/21:sleightofhand/22:stealth/23:survival
	unordered_set<string> toolProf;
	unordered_set<Feature, InvHash<Feature>, InvCmp<Feature>> feats;
	unordered_set<Resource, InvHash<Resource>, InvCmp<Resource>> resources;
	int wallet[5] = { 0 };
	unordered_set<Weapon, InvHash<Weapon>, InvCmp<Weapon>> weaponInv;
	unordered_set<Armor, InvHash<Armor>, InvCmp<Armor>> armorInv;
	unordered_set<Gear, InvHash<Gear>, InvCmp<Gear>> gearInv;
	unordered_set<Tool, InvHash<Tool>, InvCmp<Tool>> toolInv;
	vector<Mount> mounts;
	int stats[13] = { 0 }; //0:maxhp/1:curhp/2:ac/3:spd/4:size/5:str/6:dex/7:con/8:int/9:wis/10:cha/11:initiative/12:Passiveperception
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, race, sex, type, alignment, classfeatures, racefeatures, bgfeatures, spellList, lang, weaponProf, armorProf, savingSkillsProf, toolProf, feats, resources, wallet, weaponInv, armorInv, gearInv, toolInv, mounts, stats);
	}

public:
	string getName() const;
	string getRace() const;
	string getSex() const;
	string getType() const;
	string getAlign() const;
	int getmaxhp() const;
	int getcurhp() const;
	int getac() const;
	int getspd() const;
	int getNsize() const;
	string getsize() const;
	int getstr() const;
	int getdex() const;
	int getcon() const;
	int getint() const;
	int getwis() const;
	int getcha() const;
	int getinit() const;
	int getpasper() const;
	int getCp() const;
	int getSp() const;
	int getEp() const;
	int getGp() const;
	int getPp() const;

	void setType(string);
	void setRace(string);
	void setmaxhp(int);
	void setcurhp(int);
	void setac(int);
	void setspd(int);
	void setsize(int);
	void setstr(int);
	void setdex(int);
	void setcon(int);
	void setint(int);
	void setwis(int);
	void setcha(int);
	void setinit(int);
	void setpasper(int);
	bool setssProf(int, bool = false);
	void setAlign(int);
	void setstats();

	void addmaxhp(int);
	void addcurhp(int);
	void addac(int);
	void addspd(int);
	void addstr(int);
	void adddex(int);
	void addcon(int);
	void addint(int);
	void addwis(int);
	void addcha(int);
	void addresource(string, int, int, int = 0);
	bool addfeature(string, int = 0, string = {});
	//bool addfeature(string, int = 0);
	void delfeature(string, int);
	//void addfeats();
	void addWeaponProf(int = 1);
	void addArtToolProf();
	void addInstrumProf(int = 1);
	void addGamingProf();
	void addToolProf();
	void addlang(int = 1);
	void addCp(int);
	void addSp(int);
	void addEp(int);
	void addGp(int);
	void addPp(int);
	void addWeapon(string, float = 0.0f, int = 1);
	void addArmor(string, float = 0.0f, int = 1);
	void addGear(string, float = 0.0f, int = 1);
	void addTool(string, float = 0.0f);
	void addMount(string, string, int, float);
	void storeItemMount(string, string, float = 0.0f, int = 1, int = 1);
	void storeMoneyMount(string, int, int);
	void addSimpleWep(int = 0, int = 1);
	void addMartialWep(int = 0, int = 1);
	void addBurglar();
	void addDiplomat();
	void addDungeoneer();
	void addExplorer();
	void addEntertainer();
	void addPriest();
	void addScholar();
	void addArtTool();
	void addInstrum();
	string randTrinket();
	void delWeapon(string);
	void delArmor(string);
	void delGear(string);
	void delTool(string);
	unordered_set<Weapon>::iterator findWeapon(string);
	unordered_set<Armor>::iterator findArmor(string);
	unordered_set<Gear>::iterator findGear(string);
	unordered_set<Tool>::iterator findTool(string);
	bool spellLookup(string);

	int calcmod(int);
	void listInv();
	void displaystats();
	void report();
};