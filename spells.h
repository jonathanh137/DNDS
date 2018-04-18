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
enum spellAbility {NONE, STR, DEX, CON, INTEL, WIS, CHA};

#define SPELLS(SP) \
	SP(acidsplash), \
	SP(bladeward), \
	SP(chilltouch), \
	SP(dancinglights), \
	SP(druidcraft), \
	SP(eldritchblast), \
	SP(firebolt), \
	SP(friends), \
	SP(guidance), \
	SP(light), \
	SP(magehand), \
	SP(mending), \
	SP(message), \
	SP(minorillusion), \
	SP(poisonspray), \
	SP(prestidigitation), \
	SP(produceflame), \
	SP(rayoffrost), \
	SP(resistance), \
	SP(sacredflame), \
	SP(shillelagh), \
	SP(shockinggrasp), \
	SP(sparethedying), \
	SP(thaumaturgy), \
	SP(thornwhip), \
	SP(truestrike), \
	SP(viciousmockery)

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
	spellAbility spellAbi;
	string desc;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, lvl, type, cast, ritual, range, verbal, somatic, material, duration, concentration, spellAbi, desc);
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
	AcidSplash(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(AcidSplash)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, AcidSplash)

class BladeWard : public Spell {
public:
	BladeWard(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(BladeWard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, BladeWard)

class ChillTouch : public Spell {
public:
	ChillTouch(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(ChillTouch)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ChillTouch)

class DancingLights : public Spell {
public:
	DancingLights(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(DancingLights)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DancingLights)

class Druidcraft : public Spell {
public:
	Druidcraft(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Druidcraft)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Druidcraft)

class EldritchBlast : public Spell {
public:
	EldritchBlast(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(EldritchBlast)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, EldritchBlast)

class FireBolt : public Spell {
public:
	FireBolt(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(FireBolt)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FireBolt)

class Friends : public Spell {
public:
	Friends(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Friends)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Friends)

class Guidance : public Spell {
public:
	Guidance(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Guidance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Guidance)

class Light : public Spell {
public:
	Light(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Light)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Light)

class MageHand : public Spell {
public:
	MageHand(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(MageHand)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, MageHand)

class Mending : public Spell {
public:
	Mending(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Mending)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Mending)

class Message : public Spell {
public:
	Message(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Message)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Message)

class MinorIllusion : public Spell {
public:
	MinorIllusion(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(MinorIllusion)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, MinorIllusion)

class PoisonSpray : public Spell {
public:
	PoisonSpray(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(PoisonSpray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, PoisonSpray)

class Prestidigitation : public Spell {
public:
	Prestidigitation(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Prestidigitation)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Prestidigitation)

class ProduceFlame : public Spell {
public:
	ProduceFlame(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(ProduceFlame)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ProduceFlame)

class RayofFrost : public Spell {
public:
	RayofFrost(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(RayofFrost)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, RayofFrost)

class Resistance : public Spell {
public:
	Resistance(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Resistance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Resistance)

class SacredFlame : public Spell {
public:
	SacredFlame(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(SacredFlame)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SacredFlame)

class Shillelagh : public Spell {
public:
	Shillelagh(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Shillelagh)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Shillelagh)

class ShockingGrasp : public Spell {
public:
	ShockingGrasp(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(ShockingGrasp)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ShockingGrasp)

class SparetheDying : public Spell {
public:
	SparetheDying(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(SparetheDying)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SparetheDying)

class Thaumaturgy : public Spell {
public:
	Thaumaturgy(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(Thaumaturgy)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Thaumaturgy)

class ThornWhip : public Spell {
public:
	ThornWhip(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(ThornWhip)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ThornWhip)

class TrueStrike : public Spell {
public:
	TrueStrike(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(TrueStrike)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, TrueStrike)

class ViciousMockery : public Spell {
public:
	ViciousMockery(spellAbility = NONE);
	void effect();
};
CEREAL_REGISTER_TYPE(ViciousMockery)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ViciousMockery)