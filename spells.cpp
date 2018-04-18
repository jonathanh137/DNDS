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
	if (range == 5)
		return "Touch";
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

AcidSplash::AcidSplash(spellAbility sA) {
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
	spellAbi = sA;
	desc = "You hurl a bubble of acid. Choose one creature within range, or choose two creatures within range that are within 5 feet of each other. A target must succeed on a Dexterity saving throw or take 1d6 acid damage.\nThis spell's damage increases by 1d6 when you reach 5th level (2d6), 11th level (3d6), and 17th level (4d6).";
}
void AcidSplash::effect() {
	
}

BladeWard::BladeWard(spellAbility sA) {
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

ChillTouch::ChillTouch(spellAbility sA) {
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
	spellAbi = sA;
	desc = "You create a ghostly, skeletal hand in the space of a creature within range. Make a ranged spell attack against the creature to assail it with the chill of the grave. On a hit, the target takes 1d8 necrotic damage, and it can't regain hit points until the start of your next turn. Until then, the hand clings to the target.\nIf you hit an undead target, it also has disadvantage on attack rolls against you until the end of your next turn.\nThis spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ChillTouch::effect() {

}

DancingLights::DancingLights(spellAbility sA) {
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

Druidcraft::Druidcraft(spellAbility sA) {
	name = "Druidcraft";
	lvl = 0;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	desc = "Whispering to the spirits of nature, you create one of the following effects within range:\n* You create a tiny, harmless sensory effect that predicts what the weather will be at your location for the next 24 hours.The effect might manifest as a golden orb for clear skies, a cloud for rain, falling snowflakes for snow, and so on.This effect persists for 1 round.\n* You instantly make a flower blossom, a seed pod open, or a leaf bud bloom.\n* You create an instantaneous, harmless sensory effect, such as falling leaves, a puff of wind, the sound of a small animal, or the faint odor of skunk.The effect must fit in a 5 - foot cube.\n* You instantly light or snuff out a candle, a torch, or a small campfire.";
}
void Druidcraft::effect() {

}

EldritchBlast::EldritchBlast(spellAbility sA) {
	name = "Eldritch Blast";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "A beam of crackling energy streaks toward a creature within range. Make a ranged spell attack against the target. On a hit, the target takes 1d10 force damage.\nThe spell creates more than one beam when you reach higher levels : two beams at 5th level, three beams at 11th level, and four beams at 17th level.You can direct the beams at the same target or at different ones.Make a separate attack roll for each beam.";
}
void EldritchBlast::effect() {

}

FireBolt::FireBolt(spellAbility sA) {
	name = "Fire Bolt";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "You hurl a mote of fire at a creature or object within range. Make a ranged spell attack against the target. On a hit, the target takes 1d10 fire damage. A flammable object hit by this spell ignites if it isn't being worn or carried.\nThis spell's damage increases by 1d10 when you reach 5th level (2d10), 11th level (3d10), and 17th level (4d10).";
}
void FireBolt::effect() {

}

Friends::Friends(spellAbility sA) {
	name = "Friends";
	lvl = 0;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 0;
	verbal = false;
	somatic = true;
	material = "a small amount of makeup applied to the face as this spell is cast";
	duration = 3600;
	concentration = true;
	desc = "For the duration, you have advantage on all Charisma checks directed at one creature of your choice that isn't hostile toward you. When the spell ends, the creature realizes that you used magic to influence its mood and becomes hostile toward you. A creature prone to violence might attack you. Another creature might seek retribution in other ways(at the DM's discretion), depending on the nature of your interaction with it";
}
void Friends::effect() {

}

Guidance::Guidance(spellAbility sA) {
	name = "Guidance";
	lvl = 0;
	type = Divination;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	duration = 60;
	concentration = true;
	desc = "You touch one willing creature. Once before the spell ends, the target can roll a d4 and add the number rolled to one ability check of its choice. It can roll the die before or after making the ability check. The spell then ends.";
}
void Guidance::effect() {

}

Light::Light(spellAbility sA) {
	name = "Light";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = false;
	material = "a firefly or phosphorescent moss";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	desc = "You touch one object that is no larger than 10 feet in any dimension. Until the spell ends, the object sheds bright light in a 20 foot radius and dim light for an additional 20 feet. The light can be colored as you like. Completely covering the object with something opaque blocks the light. The spell ends if you cast it again or dismiss it as an action.\nIf you target an object held or worn by a hostile creature, that creature must succeed on a Dexterity saving throw to avoid the spell.";
}
void Light::effect() {

}

MageHand::MageHand(spellAbility sA) {
	name = "Mage Hand";
	lvl = 0;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	duration = 60;
	concentration = false;
	desc = "A spectral, floating hand appears at a point you choose within range. The hand lasts for the duration or until you dismiss it as an action. The hand vanishes if it is ever more than 30 feet away from you or if you cast this spell again.\nYou can use your action to control the hand.You can use the hand to manipulate an object, open an unlocked door or container, stow or retrieve an item from an open container, or pour the contents out of a vial. You can move the hand up to 30 feet each time you use it.\nThe hand can't attack, activate magic items, or carry more than 10 pounds.";
}
void MageHand::effect() {

}

Mending::Mending(spellAbility sA) {
	name = "Mending";
	lvl = 0;
	type = Transmutation;
	cast = minute;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "two lodestones";
	duration = 0;
	concentration = false;
	desc = "This spell repairs a single break or tear in an object you touch, such as a broken chain link, two halves of a broken key, a torn cloak, or a leaking wineskin. As long as the break or tear is no larger than 1 foot in any dimension, you mend it, leaving no trace of the former damage.\nThis spell can physically repair a magic item or construct, but the spell can't restore magic to such an object.";
}
void Mending::effect() {

}

Message::Message(spellAbility sA) {
	name = "Message";
	lvl = 0;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	material = "a short piece of copper wire";
	duration = 6;
	concentration = false;
	desc = "You point your finger toward a creature within range and whisper a message. The target (and only the target) hears the message and can reply in a whisper that only you can hear.\nYou can cast this spell through solid objects if you are familiar with the target and know it is beyond the barrier.Magical silence, 1 foot of stone, 1 inch of common metal, a thin sheet of lead, or 3 feet of wood blocks the spell. The spell doesn't have to follow a straight line and can travel freely around corners or through openings.";
}
void Message::effect() {

}

MinorIllusion::MinorIllusion(spellAbility sA) {
	name = "Minor Illusion";
	lvl = 0;
	type = Illusion;
	cast = action;
	ritual = false;
	range = 30;
	verbal = false;
	somatic = true;
	material = "a bit of fleece";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	desc = "You create a sound or an image of an object within range that lasts for the duration. The illusion also ends if you dismiss it as an action or cast this spell again.\nIf you create a sound, its volume can range from a whisper to a scream. It can be your voice, someone else's voice, a lion's roar, a beating of drums, or any other sound you choose. The sound continues unabated throughout the duration, or you can make discrete sounds at different times before the spell ends.\nIf you create an image of an object -- such as a chair, muddy footprints, or a small chest -- it must be no larger than a 5 foot cube. The image can't create sound, light, smell, or any other sensory effect. Physical interaction with the image reveals it to be an illusion, because things can pass through it.\nIf a creature uses its action to examine the sound or image, the creature can determine that it is an illusion with a successful Intelligence(Investigation) check against your spell save DC. If a creature discerns the illusion for what it is, the illusion becomes faint to the creature.";
}
void MinorIllusion::effect() {

}

PoisonSpray::PoisonSpray(spellAbility sA) {
	name = "Poison Spray";
	lvl = 0;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 10;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "You extend your hand toward a creature you can see within range and project a puff of noxious gas from your palm. The creature must succeed on a Constitution saving throw or take 1d12 poison damage.\nThis spell's damage increases by 1d12 when you reach 5th level (2d12), 11th level (3d12), and 17th level (4d12).";
}
void PoisonSpray::effect() {

}

Prestidigitation::Prestidigitation(spellAbility sA) {
	name = "Prestidigitation";
	lvl = 0;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 10;
	verbal = true;
	somatic = true;
	duration = 3600;
	concentration = false;
	desc = "This spell is a minor magical trick that novice spellcasters use for practice. You create one of the following magical effects within range:\n* You create an instantaneous, harmless sensory effect, such as a shower of sparks, a puff of wind, faint musical notes, or an odd odor.\n* You instantaneously light or snuff out a candle, a torch, or a small campfire.\n* You instantaneously clean or soil an object no larger than 1 cubic foot.\n* You chill, warm, or flavor up to 1 cubic foot of nonliving material for 1 hour.\n* You make a color, a small mark, or a symbol appear on an object or a surface for 1 hour.\n* You create a nonmagical trinket or an illusory image that can fit in your hand and that lasts until the end of your next turn.\nIf you cast this spell multiple times, you can have up to three of its non instantaneous effects active at a time, and you can dismiss such an effect as an action.";
}
void Prestidigitation::effect() {

}

ProduceFlame::ProduceFlame(spellAbility sA) {
	name = "Produce Flame";
	lvl = 0;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 600;
	concentration = false;
	spellAbi = sA;
	desc = "A flickering flame appears in your hand. The flame remains there for the duration and harms neither you nor your equipment. The flame sheds bright light in a 10 foot radius and dim light for an additional 10 feet. The spell ends if you dismiss it as an action or if you cast it again.\nYou can also attack with the flame, although doing so ends the spell.When you cast this spell, or as an action on a later turn, you can hurl the flame at a creature within 30 feet of you. Make a ranged spell attack. On a hit, the target takes 1d8 fire damage.\nThis spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ProduceFlame::effect() {

}

RayofFrost::RayofFrost(spellAbility sA) {
	name = "Ray of Frost";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "A frigid beam of blue white light streaks toward a creature within range. Make a ranged spell attack against the target. On a hit, it takes 1d8 cold damage, and its speed is reduced by 10 feet until the start of your next turn.\nThe spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void RayofFrost::effect() {

}

Resistance::Resistance(spellAbility sA) {
	name = "Resistance";
	lvl = 0;
	type = Abjuration;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "a miniature cloak";
	duration = 60;
	concentration = true;
	desc = "You touch one willing creature. Once before the spell ends, the target can roll a d4 and add the number rolled to one saving throw of its choice. It can roll the die before or after making the saving throw. The spell then ends.";
}
void Resistance::effect() {

}

SacredFlame::SacredFlame(spellAbility sA) {
	name = "Sacred Flame";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "Flame like radiance descends on a creature that you can see within range. The target must succeed on a Dexterity saving throw or take 1d8 radiant damage. The target gains no benefit from cover for this saving throw.\nThe spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void SacredFlame::effect() {

}

Shillelagh::Shillelagh(spellAbility sA) {
	name = "Shillelagh";
	lvl = 0;
	type = Transmutation;
	cast = bonus;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "mistletoe, a shamrock leaf, and a club or quarterstaff";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	desc = "The wood of a club or quarterstaff you are holding is imbued with nature's power. For the duration, you can use your spellcasting ability instead of Strength for the attack and damage rolls of melee attacks using that weapon, and the weapon's damage die becomes a d8. The weapon also becomes magical, if it isn't already. The spell ends if you cast it again or if you let go of the weapon.";
}
void Shillelagh::effect() {

}

ShockingGrasp::ShockingGrasp(spellAbility sA) {
	name = "Shocking Grasp";
	lvl = 0;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "Lightning springs from your hand to deliver a shock to a creature you try to touch. Make a melee spell attack against the target. You have advantage on the attack roll if the target is wearing armor made of metal. On a hit, the target takes 1d8 lightning damage, and it can't take reactions until the start of its next turn.\nThe spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ShockingGrasp::effect() {

}

SparetheDying::SparetheDying(spellAbility sA) {
	name = "Spare the Dying";
	lvl = 0;
	type = Necromancy;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	desc = "You touch a living creature that has 0 hit points. The creature becomes stable. This spell has no effect on undead or constructs.";
}
void SparetheDying::effect() {

}

Thaumaturgy::Thaumaturgy(spellAbility sA) {
	name = "Thaumaturgy";
	lvl = 0;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = false;
	desc = "You manifest a minor wonder, a sign of supernatural power, within range. You create one of the following magical effects within range:\n* Your voice booms up to three times as loud as normal for 1 minute.\n* You cause flames to flicker, brighten, dim, or change color for 1 minute.\n* You cause harmless tremors in the ground for 1 minute.\n* You create an instantaneous sound that originates from a point of your choice within range, such as a rumble of thunder, the cry of a raven, or ominous whispers.\n* You instantaneously cause an unlocked door or window to fly open or slam shut.\n* You alter the appearance of your eyes for 1 minute.\nIf you cast this spell multiple times, you can have up to three of its 1 minute effects active at a time, and you can dismiss such an effect as an action.";
}
void Thaumaturgy::effect() {

}

ThornWhip::ThornWhip(spellAbility sA) {
	name = "Thorn Whip";
	lvl = 0;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "the stem of a plant with thorns";
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "You create a long, vine-like whip covered in thorns that lashes out at your command toward a creature in range. Make a melee spell attack against the target. If the attack hits, the creature takes 1d6 piercing damage, and if the creature is Large or smaller, you pull the creature up to 10 feet closer to you.\nThis spell's damage increases by 1d6 when you reach 5th level(2d6), 11th level(3d6), and 17th level(4d6).";
}
void ThornWhip::effect() {

}

TrueStrike::TrueStrike(spellAbility sA) {
	name = "True Strike";
	lvl = 0;
	type = Divination;
	cast = action;
	ritual = false;
	range = 30;
	verbal = false;
	somatic = true;
	duration = 6;
	concentration = true;
	desc = "You extend your hand and point a finger at a target in range. Your magic grants you a brief insight into the target's defenses. On your next turn, you gain advantage on your first attack roll against the target, provided that this spell hasn't ended.";
}
void TrueStrike::effect() {

}

ViciousMockery::ViciousMockery(spellAbility sA) {
	name = "Vicious Mockery";
	lvl = 0;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = false;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	desc = "You unleash a string of insults laced with subtle enchantments at a creature you can see within range. If the target can hear you (though it need not understand you), it must succeed on a Wisdom saving throw or take 1d4 psychic damage and have disadvantage on the next attack roll it makes before the end of its next turn.\nThis spell's damage increases by 1d4 when you reach 5th level (2d4), 11th level (3d4), and 17th level (4d4).";
}
void ViciousMockery::effect() {

}