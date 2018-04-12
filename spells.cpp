#include "spells.h"

#define SP(s) #s
string SpellNames[] = { SPELLS(SP) };
#undef SP

string totitle(string s)
{
	for (char& c : s)   c = std::tolower(c);
	return s;
}
Spells name_to_Spells(string s)
{
	return Spells(std::find(SpellNames, SpellNames + blankSpell, totitle(s)) - SpellNames);
}

string Spell::getName() const {
	return name;
}
int Spell::getLvl() const {
	return lvl;
}
string Spell::getType() const {
	vector<string> temp = {"Abjuration", "Conjuration", "Divination", "Enchantment", "Evocation", "Illusion", "Necromancy", "Transmutation"};
	return temp[type];
}
string Spell::getCastTime() const {
	switch (cast) {
	case 0:
		return "1 action";
	case 1:
		return "1 bonus action";
	case 2:
		return "1 reaction";
	case 3:
		return "1 minute";
	default:
		return "N/A";
	}
}
bool Spell::getRitual() const {
	return ritual;
}
string Spell::getSpellRange() const {
	if (range == 0)
		return "Self";
	string s; 
	s += to_string(range) + " feet";
	return s;
}
string Spell::getComponents() const {
	string s;
	if (verbal)
		s += "V ";
	if (somatic)
		s += "S ";
	if (!material.empty()) {
		s += "M (";
		s += material;
		s += ")";
	}
	return s;
}
string Spell::getDuration() const {
	if (duration == 0)
		return "Instantaneous";
	string s;
	if (getConcentration())
		s += "Concentration, up to ";
	if (duration == 6)
		return "1 round";
	else if (duration >= 3600) {
		int temp = duration / 3600;
		s += to_string(temp) + " hour";
		if (temp > 1)
			s += "s";
	}
	else if (duration >= 60) {
		int temp = duration / 60;
		s += to_string(temp) + " minute";
		if (temp > 1)
			s += "s";
	}
	return s;
}
bool Spell::getConcentration() const {
	return concentration;
}
string Spell::getDesc() const {
	return desc;
}

AcidSplash::AcidSplash() {
	name = "Acid Splash";
	lvl = 0;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	desc = "You hurl a bubble of acid. Choose one creature within range, or choose two creatures within range that are within 5 feet of each other. A target must succeed on a Dexterity saving throw or take 1d6 acid damage.\nThis spell's damage increases by 1d6 when you reach 5th level (2d6), 11th level (3d6), and 17th level (4d6).";
}
void AcidSplash::effect() {
	
}

BladeWard::BladeWard() {
	name = "Blade Ward";
	lvl = 0;
	type = Abjuration;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 6;
	concentration = false;
	desc = "You extend your hand and trace a sigil of warding in the air. Until the end of your next turn, you have resistance against bludgeoning, piercing, and slashing damage dealt by weapon attacks.";
}
void BladeWard::effect() {

}

ChillTouch::ChillTouch() {
	name = "Chill Touch";
	lvl = 0;
	type = Necromancy;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	duration = 6;
	concentration = false;
	desc = "You create a ghostly, skeletal hand in the space of a creature within range. Make a ranged spell attack against the creature to assail it with the chill of the grave. On a hit, the target takes 1d8 necrotic damage, and it can't regain hit points until the start of your next turn. Until then, the hand clings to the target.\nIf you hit an undead target, it also has disadvantage on attack rolls against you until the end of your next turn.\nThis spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ChillTouch::effect() {

}

DancingLights::DancingLights() {
	name = "Dancing Lights";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	material = "a bit of phosphorus or wychwood, or a glowworm";
	duration = 60;
	concentration = true;
	desc = "You create up to four torch sized lights within range, making them appear as torches, lanterns, or glowing orbs that hover in the air for the duration. You can also combine the four lights into one glowing vaguely humanoid form of Medium size. Whichever form you choose, each light sheds dim light in a 10 foot radius.\nAs a bonus action on your turn, you can move the lights up to 60 feet to a new spot within range. A light must be within 20 feet of another light created by this spell, and a light winks out if it exceeds the spell's range.";
}
void DancingLights::effect() {

}