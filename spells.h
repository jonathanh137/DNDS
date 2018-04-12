#pragma once
#include "..\Project2\cereal\cereal.hpp"
#include "..\Project2\cereal\types\string.hpp"
#include "..\Project2\cereal\types\memory.hpp"
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

enum castTime {action, bonus, reaction, minute};
enum spellType {Abjuration, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation};

#define SPELLS(SP) \
	SP(acidsplash), \
	SP(bladeward), \
	SP(chilltouch), \
	SP(dancinglights)

#define SP(e) e
enum Spells { SPELLS(SP), blankSpell };
#undef SP

string totitle(string);
Spells name_to_Spells(string);

class Spell {
protected:
	string name;
	int lvl;
	spellType type;
	castTime cast;
	bool ritual;
	int range;
	bool verbal;
	bool somatic;
	string material;
	int duration;
	bool concentration;
	string desc;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, lvl, type, cast, ritual, range, verbal, somatic, material, duration, concentration, desc);
	}
public:
	virtual void effect() = 0;
	string getName() const;
	int getLvl() const;
	string getType() const;
	string getCastTime() const;
	bool getRitual() const;
	string getSpellRange() const;
	string getComponents() const;
	string getDuration() const;
	bool getConcentration() const;
	string getDesc() const;
};

template<class T>
struct SpellCmp
{
	bool operator()(const T obj1, const T obj2) const
	{
		if (obj1->getName() < obj2->getName())
			return true;
		return false;
	}
};

class AcidSplash : public Spell {
public:
	AcidSplash();
	void effect();
};

class BladeWard : public Spell {
public:
	BladeWard();
	void effect();
};

class ChillTouch : public Spell {
public:
	ChillTouch();
	void effect();
};

class DancingLights : public Spell {
public:
	DancingLights();
	void effect();
};

CEREAL_REGISTER_TYPE(AcidSplash);
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, AcidSplash)
CEREAL_REGISTER_TYPE(BladeWard);
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, BladeWard)
CEREAL_REGISTER_TYPE(ChillTouch);
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ChillTouch)
CEREAL_REGISTER_TYPE(DancingLights);
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DancingLights)