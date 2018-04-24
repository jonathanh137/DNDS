#pragma once
#include "..\Project2\cereal\cereal.hpp"
#include "..\Project2\cereal\types\string.hpp"
#include "..\Project2\cereal\types\memory.hpp"
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

enum castTime {action, bonus, reaction, minute, hour};
enum spellType {Abjuration, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation};
enum spellAbility {STR, DEX, CON, INTEL, WIS, CHA};

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
	SP(viciousmockery), \
	SP(alarm), \
	SP(animalfriendship), \
	SP(armorofagathys), \
	SP(armsofhadar), \
	SP(bane), \
	SP(bless), \
	SP(burninghands), \
	SP(charmperson), \
	SP(chromaticorb), \
	SP(colorspray), \
	SP(command), \
	SP(compelledduel), \
	SP(comprehendlanguages), \
	SP(createordestroywater), \
	SP(curewounds), \
	SP(detectevilandgood), \
	SP(detectmagic), \
	SP(detectpoisonanddisease), \
	SP(disguiseself), \
	SP(dissonantwhispers), \
	SP(divinefavor), \
	SP(ensnaringstrike), \
	SP(entangle), \
	SP(expeditiousretreat), \
	SP(faeriefire), \
	SP(falselife), \
	SP(featherfall), \
	SP(findfamiliar), \
	SP(fogcloud), \
	SP(goodberry), \
	SP(grease), \
	SP(guidingbolt), \
	SP(hailofthorns), \
	SP(healingword), \
	SP(hellishrebuke), \
	SP(heroism), \
	SP(hex), \
	SP(huntersmark), \
	SP(identify), \
	SP(illusoryscript), \
	SP(inflictwounds), \
	SP(jump), \
	SP(longstrider), \
	SP(magearmor), \
	SP(magicmissile), \
	SP(protectionfromevilandgood), \
	SP(purifyfoodanddrink), \
	SP(rayofsickness), \
	SP(sanctuary), \
	SP(searingsmite), \
	SP(shield), \
	SP(shieldoffaith), \
	SP(silentimage), \
	SP(sleep), \
	SP(speakwithanimals), \
	SP(tashashideouslaughter), \
	SP(tensersfloatingdisk), \
	SP(thunderoussmite), \
	SP(thunderwave), \
	SP(unseenservant), \
	SP(witchbolt), \
	SP(wrathfulsmite)

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
	bool prep;
	string desc;
	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(name, lvl, type, cast, ritual, range, verbal, somatic, material, duration, concentration, spellAbi, prep, desc);
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
	bool getPrepare() const;
	string getDesc() const;
};

template<class T>
struct SpellCmp
{
	bool operator()(const T obj1, const T obj2) const
	{
		return (((obj1->getPrepare() < obj2->getPrepare()) && (obj1->getName() != obj2->getName())) || ((obj1->getPrepare() == obj2->getPrepare()) && (obj1->getLvl() < obj2->getLvl())) || ((obj1->getPrepare() == obj2->getPrepare()) && (obj1->getLvl() == obj2->getLvl()) && (obj1->getName() < obj2->getName())));
	}
};

//cantrips
class AcidSplash : public Spell {
public:
	AcidSplash() {}
	AcidSplash(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(AcidSplash)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, AcidSplash)

class BladeWard : public Spell {
public:
	BladeWard() {}
	BladeWard(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(BladeWard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, BladeWard)

class ChillTouch : public Spell {
public:
	ChillTouch() {}
	ChillTouch(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ChillTouch)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ChillTouch)

class DancingLights : public Spell {
public:
	DancingLights() {}
	DancingLights(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DancingLights)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DancingLights)

class Druidcraft : public Spell {
public:
	Druidcraft() {}
	Druidcraft(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Druidcraft)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Druidcraft)

class EldritchBlast : public Spell {
public:
	EldritchBlast() {}
	EldritchBlast(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(EldritchBlast)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, EldritchBlast)

class FireBolt : public Spell {
public:
	FireBolt() {}
	FireBolt(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(FireBolt)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FireBolt)

class Friends : public Spell {
public:
	Friends() {}
	Friends(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Friends)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Friends)

class Guidance : public Spell {
public:
	Guidance() {}
	Guidance(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Guidance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Guidance)

class Light : public Spell {
public:
	Light() {}
	Light(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Light)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Light)

class MageHand : public Spell {
public:
	MageHand() {}
	MageHand(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(MageHand)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, MageHand)

class Mending : public Spell {
public:
	Mending() {}
	Mending(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Mending)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Mending)

class Message : public Spell {
public:
	Message() {}
	Message(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Message)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Message)

class MinorIllusion : public Spell {
public:
	MinorIllusion() {}
	MinorIllusion(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(MinorIllusion)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, MinorIllusion)

class PoisonSpray : public Spell {
public:
	PoisonSpray() {}
	PoisonSpray(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(PoisonSpray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, PoisonSpray)

class Prestidigitation : public Spell {
public:
	Prestidigitation() {}
	Prestidigitation(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Prestidigitation)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Prestidigitation)

class ProduceFlame : public Spell {
public:
	ProduceFlame() {}
	ProduceFlame(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ProduceFlame)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ProduceFlame)

class RayofFrost : public Spell {
public:
	RayofFrost() {}
	RayofFrost(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(RayofFrost)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, RayofFrost)

class Resistance : public Spell {
public:
	Resistance() {}
	Resistance(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Resistance)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Resistance)

class SacredFlame : public Spell {
public:
	SacredFlame() {}
	SacredFlame(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(SacredFlame)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SacredFlame)

class Shillelagh : public Spell {
public:
	Shillelagh() {}
	Shillelagh(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Shillelagh)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Shillelagh)

class ShockingGrasp : public Spell {
public:
	ShockingGrasp() {}
	ShockingGrasp(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ShockingGrasp)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ShockingGrasp)

class SparetheDying : public Spell {
public:
	SparetheDying() {}
	SparetheDying(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(SparetheDying)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SparetheDying)

class Thaumaturgy : public Spell {
public:
	Thaumaturgy() {}
	Thaumaturgy(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Thaumaturgy)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Thaumaturgy)

class ThornWhip : public Spell {
public:
	ThornWhip() {}
	ThornWhip(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ThornWhip)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ThornWhip)

class TrueStrike : public Spell {
public:
	TrueStrike() {}
	TrueStrike(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(TrueStrike)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, TrueStrike)

class ViciousMockery : public Spell {
public:
	ViciousMockery() {}
	ViciousMockery(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ViciousMockery)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ViciousMockery)

//1st-level spells
class Alarm : public Spell {
public:
	Alarm() {}
	Alarm(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Alarm)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Alarm)

class AnimalFriendship : public Spell {
public:
	AnimalFriendship() {}
	AnimalFriendship(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(AnimalFriendship)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, AnimalFriendship)

class ArmorofAgathys : public Spell {
public:
	ArmorofAgathys() {}
	ArmorofAgathys(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ArmorofAgathys)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ArmorofAgathys)

class ArmsofHadar : public Spell {
public:
	ArmsofHadar() {}
	ArmsofHadar(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ArmsofHadar)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ArmsofHadar)

class Bane : public Spell {
public:
	Bane() {}
	Bane(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Bane)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Bane)

class Bless : public Spell {
public:
	Bless() {}
	Bless(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Bless)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Bless)

class BurningHands : public Spell {
public:
	BurningHands() {}
	BurningHands(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(BurningHands)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, BurningHands)

class CharmPerson : public Spell {
public:
	CharmPerson() {}
	CharmPerson(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(CharmPerson)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, CharmPerson)

class ChromaticOrb : public Spell {
public:
	ChromaticOrb() {}
	ChromaticOrb(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ChromaticOrb)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ChromaticOrb)

class ColorSpray : public Spell {
public:
	ColorSpray() {}
	ColorSpray(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ColorSpray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ColorSpray)

class Command : public Spell {
public:
	Command() {}
	Command(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Command)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Command)

class CompelledDuel : public Spell {
public:
	CompelledDuel() {}
	CompelledDuel(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(CompelledDuel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, CompelledDuel)

class ComprehendLanguages : public Spell {
public:
	ComprehendLanguages() {}
	ComprehendLanguages(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ComprehendLanguages)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ComprehendLanguages)

class CreateorDestroyWater : public Spell {
public:
	CreateorDestroyWater() {}
	CreateorDestroyWater(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(CreateorDestroyWater)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, CreateorDestroyWater)

class CureWounds : public Spell {
public:
	CureWounds() {}
	CureWounds(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(CureWounds)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, CureWounds)

class DetectEvilandGood : public Spell {
public:
	DetectEvilandGood() {}
	DetectEvilandGood(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DetectEvilandGood)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DetectEvilandGood)

class DetectMagic : public Spell {
public:
	DetectMagic() {}
	DetectMagic(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DetectMagic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DetectMagic)

class DetectPoisonandDisease : public Spell {
public:
	DetectPoisonandDisease() {}
	DetectPoisonandDisease(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DetectPoisonandDisease)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DetectPoisonandDisease)

class DisguiseSelf : public Spell {
public:
	DisguiseSelf() {}
	DisguiseSelf(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DisguiseSelf)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DisguiseSelf)

class DissonantWhispers : public Spell {
public:
	DissonantWhispers() {}
	DissonantWhispers(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DissonantWhispers)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DissonantWhispers)

class DivineFavor : public Spell {
public:
	DivineFavor() {}
	DivineFavor(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(DivineFavor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, DivineFavor)

class EnsnaringStrike : public Spell {
public:
	EnsnaringStrike() {}
	EnsnaringStrike(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(EnsnaringStrike)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, EnsnaringStrike)

class Entangle : public Spell {
public:
	Entangle() {}
	Entangle(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Entangle)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Entangle)

class ExpeditiousRetreat : public Spell {
public:
	ExpeditiousRetreat() {}
	ExpeditiousRetreat(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ExpeditiousRetreat)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ExpeditiousRetreat)

class FaerieFire : public Spell {
public:
	FaerieFire() {}
	FaerieFire(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(FaerieFire)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FaerieFire)

class FalseLife : public Spell {
public:
	FalseLife() {}
	FalseLife(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(FalseLife)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FalseLife)

class FeatherFall : public Spell {
public:
	FeatherFall() {}
	FeatherFall(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(FeatherFall)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FeatherFall)

class FindFamiliar : public Spell {
public:
	FindFamiliar() {}
	FindFamiliar(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(FindFamiliar)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FindFamiliar)

class FogCloud : public Spell {
public:
	FogCloud() {}
	FogCloud(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(FogCloud)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, FogCloud)

class Goodberry : public Spell {
public:
	Goodberry() {}
	Goodberry(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Goodberry)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Goodberry)

class Grease : public Spell {
public:
	Grease() {}
	Grease(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Grease)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Grease)

class GuidingBolt : public Spell {
public:
	GuidingBolt() {}
	GuidingBolt(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(GuidingBolt)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, GuidingBolt)

class HailofThorns : public Spell {
public:
	HailofThorns() {}
	HailofThorns(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(HailofThorns)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, HailofThorns)

class HealingWord : public Spell {
public:
	HealingWord() {}
	HealingWord(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(HealingWord)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, HealingWord)

class HellishRebuke : public Spell {
public:
	HellishRebuke() {}
	HellishRebuke(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(HellishRebuke)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, HellishRebuke)

class Heroism : public Spell {
public:
	Heroism() {}
	Heroism(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Heroism)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Heroism)

class Hex : public Spell {
public:
	Hex() {}
	Hex(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Hex)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Hex)

class HuntersMark : public Spell {
public:
	HuntersMark() {}
	HuntersMark(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(HuntersMark)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, HuntersMark)

class Identify : public Spell {
public:
	Identify() {}
	Identify(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Identify)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Identify)

class IllusoryScript : public Spell {
public:
	IllusoryScript() {}
	IllusoryScript(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(IllusoryScript)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, IllusoryScript)

class InflictWounds : public Spell {
public:
	InflictWounds() {}
	InflictWounds(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(InflictWounds)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, InflictWounds)

class Jump : public Spell {
public:
	Jump() {}
	Jump(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Jump)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Jump)

class Longstrider : public Spell {
public:
	Longstrider() {}
	Longstrider(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Longstrider)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Longstrider)

class MageArmor : public Spell {
public:
	MageArmor() {}
	MageArmor(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(MageArmor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, MageArmor)

class MagicMissile : public Spell {
public:
	MagicMissile() {}
	MagicMissile(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(MagicMissile)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, MagicMissile)

class ProtectionfromEvilandGood : public Spell {
public:
	ProtectionfromEvilandGood() {}
	ProtectionfromEvilandGood(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ProtectionfromEvilandGood)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ProtectionfromEvilandGood)

class PurifyFoodandDrink : public Spell {
public:
	PurifyFoodandDrink() {}
	PurifyFoodandDrink(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(PurifyFoodandDrink)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, PurifyFoodandDrink)

class RayofSickness : public Spell {
public:
	RayofSickness() {}
	RayofSickness(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(RayofSickness)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, RayofSickness)

class Sanctuary : public Spell {
public:
	Sanctuary() {}
	Sanctuary(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Sanctuary)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Sanctuary)

class SearingSmite : public Spell {
public:
	SearingSmite() {}
	SearingSmite(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(SearingSmite)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SearingSmite)

class Shield : public Spell {
public:
	Shield() {}
	Shield(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Shield)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Shield)

class ShieldofFaith : public Spell {
public:
	ShieldofFaith() {}
	ShieldofFaith(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ShieldofFaith)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ShieldofFaith)

class SilentImage : public Spell {
public:
	SilentImage() {}
	SilentImage(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(SilentImage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SilentImage)

class SleepSpell : public Spell {
public:
	SleepSpell() {}
	SleepSpell(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(SleepSpell)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SleepSpell)

class SpeakwithAnimals : public Spell {
public:
	SpeakwithAnimals() {}
	SpeakwithAnimals(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(SpeakwithAnimals)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, SpeakwithAnimals)

class TashasHideousLaughter : public Spell {
public:
	TashasHideousLaughter() {}
	TashasHideousLaughter(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(TashasHideousLaughter)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, TashasHideousLaughter)

class TensersFloatingDisk : public Spell {
public:
	TensersFloatingDisk() {}
	TensersFloatingDisk(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(TensersFloatingDisk)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, TensersFloatingDisk)

class ThunderousSmite : public Spell {
public:
	ThunderousSmite() {}
	ThunderousSmite(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(ThunderousSmite)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, ThunderousSmite)

class Thunderwave : public Spell {
public:
	Thunderwave() {}
	Thunderwave(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(Thunderwave)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, Thunderwave)

class UnseenServant : public Spell {
public:
	UnseenServant() {}
	UnseenServant(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(UnseenServant)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, UnseenServant)

class WitchBolt : public Spell {
public:
	WitchBolt() {}
	WitchBolt(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(WitchBolt)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, WitchBolt)

class WrathfulSmite : public Spell {
public:
	WrathfulSmite() {}
	WrathfulSmite(spellAbility, bool);
	void effect();
};
CEREAL_REGISTER_TYPE(WrathfulSmite)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Spell, WrathfulSmite)