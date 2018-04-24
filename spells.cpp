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
	case action:
		return "1 action";
	case bonus:
		return "1 bonus action";
	case reaction:
		return "1 reaction";
	case minute:
		return "1 minute";
	case hour:
		return "1 hour";
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
	else if (duration > 86400) {
		int temp = duration / 86400;
		s += to_string(temp) + " day";
		if (temp > 1)
			s += "s";
	}
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
bool Spell::getPrepare() const {
	return prep;
}
string Spell::getDesc() const {
	return desc;
}

AcidSplash::AcidSplash(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You hurl a bubble of acid. Choose one creature within range, or choose two creatures within range that are within 5 feet of each other. A target must succeed on a Dexterity saving throw or take 1d6 acid damage.\nThis spell's damage increases by 1d6 when you reach 5th level (2d6), 11th level (3d6), and 17th level (4d6).";
}
void AcidSplash::effect() {
	
}

BladeWard::BladeWard(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You extend your hand and trace a sigil of warding in the air. Until the end of your next turn, you have resistance against bludgeoning, piercing, and slashing damage dealt by weapon attacks.";
}
void BladeWard::effect() {

}

ChillTouch::ChillTouch(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You create a ghostly, skeletal hand in the space of a creature within range. Make a ranged spell attack against the creature to assail it with the chill of the grave. On a hit, the target takes 1d8 necrotic damage, and it can't regain hit points until the start of your next turn. Until then, the hand clings to the target.\nIf you hit an undead target, it also has disadvantage on attack rolls against you until the end of your next turn.\nThis spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ChillTouch::effect() {

}

DancingLights::DancingLights(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You create up to four torch sized lights within range, making them appear as torches, lanterns, or glowing orbs that hover in the air for the duration. You can also combine the four lights into one glowing vaguely humanoid form of Medium size. Whichever form you choose, each light sheds dim light in a 10 foot radius.\nAs a bonus action on your turn, you can move the lights up to 60 feet to a new spot within range. A light must be within 20 feet of another light created by this spell, and a light winks out if it exceeds the spell's range.";
}
void DancingLights::effect() {

}

Druidcraft::Druidcraft(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "Whispering to the spirits of nature, you create one of the following effects within range:\n* You create a tiny, harmless sensory effect that predicts what the weather will be at your location for the next 24 hours.The effect might manifest as a golden orb for clear skies, a cloud for rain, falling snowflakes for snow, and so on.This effect persists for 1 round.\n* You instantly make a flower blossom, a seed pod open, or a leaf bud bloom.\n* You create an instantaneous, harmless sensory effect, such as falling leaves, a puff of wind, the sound of a small animal, or the faint odor of skunk.The effect must fit in a 5 - foot cube.\n* You instantly light or snuff out a candle, a torch, or a small campfire.";
}
void Druidcraft::effect() {

}

EldritchBlast::EldritchBlast(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "A beam of crackling energy streaks toward a creature within range. Make a ranged spell attack against the target. On a hit, the target takes 1d10 force damage.\nThe spell creates more than one beam when you reach higher levels : two beams at 5th level, three beams at 11th level, and four beams at 17th level.You can direct the beams at the same target or at different ones.Make a separate attack roll for each beam.";
}
void EldritchBlast::effect() {

}

FireBolt::FireBolt(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You hurl a mote of fire at a creature or object within range. Make a ranged spell attack against the target. On a hit, the target takes 1d10 fire damage. A flammable object hit by this spell ignites if it isn't being worn or carried.\nThis spell's damage increases by 1d10 when you reach 5th level (2d10), 11th level (3d10), and 17th level (4d10).";
}
void FireBolt::effect() {

}

Friends::Friends(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "For the duration, you have advantage on all Charisma checks directed at one creature of your choice that isn't hostile toward you. When the spell ends, the creature realizes that you used magic to influence its mood and becomes hostile toward you. A creature prone to violence might attack you. Another creature might seek retribution in other ways(at the DM's discretion), depending on the nature of your interaction with it";
}
void Friends::effect() {

}

Guidance::Guidance(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You touch one willing creature. Once before the spell ends, the target can roll a d4 and add the number rolled to one ability check of its choice. It can roll the die before or after making the ability check. The spell then ends.";
}
void Guidance::effect() {

}

Light::Light(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You touch one object that is no larger than 10 feet in any dimension. Until the spell ends, the object sheds bright light in a 20 foot radius and dim light for an additional 20 feet. The light can be colored as you like. Completely covering the object with something opaque blocks the light. The spell ends if you cast it again or dismiss it as an action.\nIf you target an object held or worn by a hostile creature, that creature must succeed on a Dexterity saving throw to avoid the spell.";
}
void Light::effect() {

}

MageHand::MageHand(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "A spectral, floating hand appears at a point you choose within range. The hand lasts for the duration or until you dismiss it as an action. The hand vanishes if it is ever more than 30 feet away from you or if you cast this spell again.\nYou can use your action to control the hand.You can use the hand to manipulate an object, open an unlocked door or container, stow or retrieve an item from an open container, or pour the contents out of a vial. You can move the hand up to 30 feet each time you use it.\nThe hand can't attack, activate magic items, or carry more than 10 pounds.";
}
void MageHand::effect() {

}

Mending::Mending(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "This spell repairs a single break or tear in an object you touch, such as a broken chain link, two halves of a broken key, a torn cloak, or a leaking wineskin. As long as the break or tear is no larger than 1 foot in any dimension, you mend it, leaving no trace of the former damage.\nThis spell can physically repair a magic item or construct, but the spell can't restore magic to such an object.";
}
void Mending::effect() {

}

Message::Message(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You point your finger toward a creature within range and whisper a message. The target (and only the target) hears the message and can reply in a whisper that only you can hear.\nYou can cast this spell through solid objects if you are familiar with the target and know it is beyond the barrier.Magical silence, 1 foot of stone, 1 inch of common metal, a thin sheet of lead, or 3 feet of wood blocks the spell. The spell doesn't have to follow a straight line and can travel freely around corners or through openings.";
}
void Message::effect() {

}

MinorIllusion::MinorIllusion(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You create a sound or an image of an object within range that lasts for the duration. The illusion also ends if you dismiss it as an action or cast this spell again.\nIf you create a sound, its volume can range from a whisper to a scream. It can be your voice, someone else's voice, a lion's roar, a beating of drums, or any other sound you choose. The sound continues unabated throughout the duration, or you can make discrete sounds at different times before the spell ends.\nIf you create an image of an object -- such as a chair, muddy footprints, or a small chest -- it must be no larger than a 5 foot cube. The image can't create sound, light, smell, or any other sensory effect. Physical interaction with the image reveals it to be an illusion, because things can pass through it.\nIf a creature uses its action to examine the sound or image, the creature can determine that it is an illusion with a successful Intelligence(Investigation) check against your spell save DC. If a creature discerns the illusion for what it is, the illusion becomes faint to the creature.";
}
void MinorIllusion::effect() {

}

PoisonSpray::PoisonSpray(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You extend your hand toward a creature you can see within range and project a puff of noxious gas from your palm. The creature must succeed on a Constitution saving throw or take 1d12 poison damage.\nThis spell's damage increases by 1d12 when you reach 5th level (2d12), 11th level (3d12), and 17th level (4d12).";
}
void PoisonSpray::effect() {

}

Prestidigitation::Prestidigitation(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "This spell is a minor magical trick that novice spellcasters use for practice. You create one of the following magical effects within range:\n* You create an instantaneous, harmless sensory effect, such as a shower of sparks, a puff of wind, faint musical notes, or an odd odor.\n* You instantaneously light or snuff out a candle, a torch, or a small campfire.\n* You instantaneously clean or soil an object no larger than 1 cubic foot.\n* You chill, warm, or flavor up to 1 cubic foot of nonliving material for 1 hour.\n* You make a color, a small mark, or a symbol appear on an object or a surface for 1 hour.\n* You create a nonmagical trinket or an illusory image that can fit in your hand and that lasts until the end of your next turn.\nIf you cast this spell multiple times, you can have up to three of its non instantaneous effects active at a time, and you can dismiss such an effect as an action.";
}
void Prestidigitation::effect() {

}

ProduceFlame::ProduceFlame(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "A flickering flame appears in your hand. The flame remains there for the duration and harms neither you nor your equipment. The flame sheds bright light in a 10 foot radius and dim light for an additional 10 feet. The spell ends if you dismiss it as an action or if you cast it again.\nYou can also attack with the flame, although doing so ends the spell.When you cast this spell, or as an action on a later turn, you can hurl the flame at a creature within 30 feet of you. Make a ranged spell attack. On a hit, the target takes 1d8 fire damage.\nThis spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ProduceFlame::effect() {

}

RayofFrost::RayofFrost(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "A frigid beam of blue white light streaks toward a creature within range. Make a ranged spell attack against the target. On a hit, it takes 1d8 cold damage, and its speed is reduced by 10 feet until the start of your next turn.\nThe spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void RayofFrost::effect() {

}

Resistance::Resistance(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You touch one willing creature. Once before the spell ends, the target can roll a d4 and add the number rolled to one saving throw of its choice. It can roll the die before or after making the saving throw. The spell then ends.";
}
void Resistance::effect() {

}

SacredFlame::SacredFlame(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "Flame like radiance descends on a creature that you can see within range. The target must succeed on a Dexterity saving throw or take 1d8 radiant damage. The target gains no benefit from cover for this saving throw.\nThe spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void SacredFlame::effect() {

}

Shillelagh::Shillelagh(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "The wood of a club or quarterstaff you are holding is imbued with nature's power. For the duration, you can use your spellcasting ability instead of Strength for the attack and damage rolls of melee attacks using that weapon, and the weapon's damage die becomes a d8. The weapon also becomes magical, if it isn't already. The spell ends if you cast it again or if you let go of the weapon.";
}
void Shillelagh::effect() {

}

ShockingGrasp::ShockingGrasp(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "Lightning springs from your hand to deliver a shock to a creature you try to touch. Make a melee spell attack against the target. You have advantage on the attack roll if the target is wearing armor made of metal. On a hit, the target takes 1d8 lightning damage, and it can't take reactions until the start of its next turn.\nThe spell's damage increases by 1d8 when you reach 5th level (2d8), 11th level (3d8), and 17th level (4d8).";
}
void ShockingGrasp::effect() {

}

SparetheDying::SparetheDying(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You touch a living creature that has 0 hit points. The creature becomes stable. This spell has no effect on undead or constructs.";
}
void SparetheDying::effect() {

}

Thaumaturgy::Thaumaturgy(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You manifest a minor wonder, a sign of supernatural power, within range. You create one of the following magical effects within range:\n* Your voice booms up to three times as loud as normal for 1 minute.\n* You cause flames to flicker, brighten, dim, or change color for 1 minute.\n* You cause harmless tremors in the ground for 1 minute.\n* You create an instantaneous sound that originates from a point of your choice within range, such as a rumble of thunder, the cry of a raven, or ominous whispers.\n* You instantaneously cause an unlocked door or window to fly open or slam shut.\n* You alter the appearance of your eyes for 1 minute.\nIf you cast this spell multiple times, you can have up to three of its 1 minute effects active at a time, and you can dismiss such an effect as an action.";
}
void Thaumaturgy::effect() {

}

ThornWhip::ThornWhip(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You create a long, vine-like whip covered in thorns that lashes out at your command toward a creature in range. Make a melee spell attack against the target. If the attack hits, the creature takes 1d6 piercing damage, and if the creature is Large or smaller, you pull the creature up to 10 feet closer to you.\nThis spell's damage increases by 1d6 when you reach 5th level(2d6), 11th level(3d6), and 17th level(4d6).";
}
void ThornWhip::effect() {

}

TrueStrike::TrueStrike(spellAbility sA, bool prepare) {
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
	spellAbi = sA;
	prep = prepare;
	desc = "You extend your hand and point a finger at a target in range. Your magic grants you a brief insight into the target's defenses. On your next turn, you gain advantage on your first attack roll against the target, provided that this spell hasn't ended.";
}
void TrueStrike::effect() {

}

ViciousMockery::ViciousMockery(spellAbility sA, bool prepare) {
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
	prep = prepare;
	desc = "You unleash a string of insults laced with subtle enchantments at a creature you can see within range. If the target can hear you (though it need not understand you), it must succeed on a Wisdom saving throw or take 1d4 psychic damage and have disadvantage on the next attack roll it makes before the end of its next turn.\nThis spell's damage increases by 1d4 when you reach 5th level (2d4), 11th level (3d4), and 17th level (4d4).";
}
void ViciousMockery::effect() {

}

Alarm::Alarm(spellAbility sA, bool prepare) {
	name = "Alarm";
	lvl = 1;
	type = Abjuration;
	cast = minute;
	ritual = true;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a tiny bell and a piece of fine silver wire";
	duration = 28800;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You set an alarm against unwanted intrusion. Choose a door, a window, or an area within range that is no larger than a 20 foot cube. Until the spell ends, an alarm alerts you whenever a Tiny or larger creature touches or enters the warded area. When you cast the spell, you can designate creatures that won't set off the alarm. You also choose whether the alarm is mental or audible.\nA mental alarm alerts you with a ping in your mind if you are within 1 mile of the warded area.This ping awakens you if you are sleeping.\nAn audible alarm produces the sound of a hand bell for 10 seconds within 60 feet.";
}
void Alarm::effect() {

}

AnimalFriendship::AnimalFriendship(spellAbility sA, bool prepare) {
	name = "Animal Friendship";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a morsel of food";
	duration = 86400;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "This spell lets you convince a beast that you mean it no harm. Choose a beast that you can see within range. It must see and hear you. If the beast's Intelligence is 4 or higher, the spell fails. Otherwise, the beast must succeed on a Wisdom saving throw or be charmed by you for the spell's duration. If you or one of your companions harms the target, the spells ends.\nAt Higher Levels.If you cast this spell using a spell slot of 2nd level or higher, you can affect one additional beast for each slot level above 1st.";
}
void AnimalFriendship::effect() {

}

ArmorofAgathys::ArmorofAgathys(spellAbility sA, bool prepare) {
	name = "Armor of Agathys";
	lvl = 1;
	type = Abjuration;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	material = "a cup of water";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A protective magical force surrounds you, manifesting as a spectral frost that covers you and your gear. You gain 5 temporary hit points for the duration. If a creature hits you with a melee attack while you have these hit points, the creature takes 5 cold damage.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, both the temporary hit points and the cold damage increase by 5 for each slot level above 1st.";
}
void ArmorofAgathys::effect() {

}

ArmsofHadar::ArmsofHadar(spellAbility sA, bool prepare) {
	name = "Arms of Hadar";
	lvl = 1;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You invoke the power of Hadar, the Dark Hunger. Tendrils of dark energy erupt from you and batter all creatures within 10 feet of you. Each creature in that area must make a Strength saving throw. On a failed save, a target takes 2d6 necrotic damage and can't take reactions until its next turn. On a successful save, the creature takes half damage, but suffers no other effect.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d6 for each slot level above 1st.";
}
void ArmsofHadar::effect() {

}

Bane::Bane(spellAbility sA, bool prepare) {
	name = "Bane";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a drop of blood";
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "Up to three creatures of your choice that you can see within range must make Charisma saving throws. Whenever a target that fails this saving throw makes an attack roll or a saving throw before the spell ends, the target must roll a d4 and subtract the number rolled from the attack roll or saving throw.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, you can target one additional creature for each slot level above 1st.";
}
void Bane::effect() {

}

Bless::Bless(spellAbility sA, bool prepare) {
	name = "Bless";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a sprinkling of holy water";
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "You bless up to three creatures of your choice within range. Whenever a target makes an attack roll or a saving throw before the spell ends, the target can roll a d4 and add the number rolled to the attack roll or saving throw.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, you can target one additional creature for each slot level above 1st.";
}
void Bless::effect() {

}

BurningHands::BurningHands(spellAbility sA, bool prepare) {
	name = "Burning Hands";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "As you hold your hands with thumbs touching and fingers spread, a thin sheet of flames shoots forth from your outstretched fingertips. Each creature in a 15 foot cone must make a Dexterity saving throw. A creature takes 3d6 fire damage on a failed save, or half as much damage on a successful one.\nThe fire ignites any flammable objects in the area that aren't being worn or carried.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d6 for each slot level above 1st.";
}
void BurningHands::effect() {

}

CharmPerson::CharmPerson(spellAbility sA, bool prepare) {
	name = "Charm Person";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You attempt to charm a humanoid you can see within range. It must make a Wisdom saving throw, and does so with advantage if you or your companions are fighting it. If it fails the saving throw, it is charmed by you until the spell ends or until you or your companions do anything harmful to it. The charmed creature regards you as a friendly acquaintance. When the spell ends, the creature knows it was charmed by you.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, you can target one additional creature for each slot level above 1st.The creatures must be within 30 feet of each other when you target them.";
}
void CharmPerson::effect() {

}

ChromaticOrb::ChromaticOrb(spellAbility sA, bool prepare) {
	name = "Chromatic Orb";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 90;
	verbal = true;
	somatic = true;
	material = "a diamond worth at least 50 gp";
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You hurl a 4-inch-diameter sphere of energy at a creature that you can see within range. You choose acid, cold, fire, lightning, poison, or thunder for the type of orb you create, and then make a ranged spell attack against the target. If the attack hits, the creature takes 3d8 damage of the type you chose.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d8 for each slot level above 1st.";
}
void ChromaticOrb::effect() {

}

ColorSpray::ColorSpray(spellAbility sA, bool prepare) {
	name = "Color Spray";
	lvl = 1;
	type = Illusion;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	material = "a pinch of powder or sand that is colored red, yellow, and blue";
	duration = 6;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A dazzling array of flashing, colored light springs from your hand. Roll 6d10; the total is how many hit points of creatures this spell can effect. Creatures in a 15 foot cone originating from you are affected in ascending order of their current hit points (ignoring unconscious creatures and creatures that can't see).\nStarting with the creature that has the lowest current hit points, each creature affected by this spell is blinded until the spell ends.Subtract each creature's hit points from the total before moving on to the creature with the next lowest hit points. A creature's hit points must be equal to or less than the remaining total for that creature to be affected.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, roll an additional 2d10 for each slot level above 1st.";
}
void ColorSpray::effect() {

}

Command::Command(spellAbility sA, bool prepare) {
	name = "Command";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = false;
	duration = 6;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You speak a one word command to a creature you can see within range. The target must succeed on a Wisdom saving throw or follow the command on its next turn. The spell has no effect if the target is undead, if it doesn't understand your language, or if your command is directly harmful to it.\nSome typical commands and their effects follow.You might issue a command other than one described here.If you do so, the GM determines how the target behaves.If the target can't follow your command, the spell ends.\n* Approach.The target moves toward you by the shortest and most direct route, ending its turn if it moves within 5 feet of you.\n* Drop.The target drops whatever it is holding and then ends its turn.\n* Flee.The target spends its turn moving away from you by the fastest available means.\n* Grovel.The target falls prone and then ends its turn.\n* Halt.The target doesn't move and takes no actions. A flying creature stays aloft, provided that it is able to do so. If it must move to stay aloft, it flies the minimum distance needed to remain in the air.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, you can affect one additional creature for each slot level above 1st.The creatures must be within 30 feet of each other when you target them.";
}
void Command::effect() {

}

CompelledDuel::CompelledDuel(spellAbility sA, bool prepare) {
	name = "Compelled Duel";
	lvl = 1;
	type = Enchantment;
	cast = bonus;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "You attempt to compel a creature into a duel. One creature that you can see within range must make a Wisdom saving throw. On a failed save, the creature is drawn to you, compelled by your divine demand. For the duration, it has disadvantage on attack rolls against creatures other than you, and must make a Wisdom saving throw each time it attempts to move to a space that is more than 30 feet away from you; if it succeeds on this saving throw, this spell doesn't restrict the target's movement for that turn.\nThe spell ends if you attack any other creature, if you cast a spell that targets a hostile creature other than the target, if a creature friendly to you damages the target or casts a harmful spell on it, or if you end your turn more than 30 feet away from the target.";
}
void CompelledDuel::effect() {

}

ComprehendLanguages::ComprehendLanguages(spellAbility sA, bool prepare) {
	name = "Comprehend Languages";
	lvl = 1;
	type = Divination;
	cast = action;
	ritual = true;
	range = 0;
	verbal = true;
	somatic = true;
	material = "a pinch of soot and salt";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "For the duration, you understand the literal meaning of any spoken language that you hear. You also understand any written language that you see, but you must be touching the surface on which the words are written. It takes about 1 minute to read one page of text.\nThis spell doesn't decode secret messages in a text or a glyph, such as an arcane sigil, that isn't part of a written language.";
}
void ComprehendLanguages::effect() {

}

CreateorDestroyWater::CreateorDestroyWater(spellAbility sA, bool prepare) {
	name = "Create or Destroy Water";
	lvl = 1;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a drop of water if creating water or a few grains of sand if destroying it";
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You either create or destroy water.\n* Create Water.You create up to 10 gallons of clean water within range in an open container. Alternatively, the water falls as rain in a 30 foot cube within range, extinguishing exposed flames in the area.\n* Destroy Water.You destroy up to 10 gallons of water in an open container within range. Alternatively, you destroy fog in a 30 foot cube within range.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, you create or destroy 10 additional gallons of water, or the size of the cube increases by 5 feet, for each slot level above 1st.";
}
void CreateorDestroyWater::effect() {

}

CureWounds::CureWounds(spellAbility sA, bool prepare) {
	name = "Cure Wounds";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A creature you touch regains a number of hit points equal to 1d8 + your spellcasting ability modifier. This spell has no effect on undead or constructs.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, the healing increases by 1d8 for each slot level above 1st.";
}
void CureWounds::effect() {

}

DetectEvilandGood::DetectEvilandGood(spellAbility sA, bool prepare) {
	name = "Detect Evil and Good";
	lvl = 1;
	type = Divination;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "For the duration, you know if there is an aberration, celestial, elemental, fey, fiend, or undead within 30 feet of you, as well as where the creature is located. Similarly, you know if there is a place or object within 30 feet of you that has been magically consecrated or desecrated.\nThe spell can penetrate most barriers, but it is blocked by 1 foot of stone, 1 inch of common metal, a thin sheet of lead, or 3 feet of wood or dirt.";
}
void DetectEvilandGood::effect() {

}

DetectMagic::DetectMagic(spellAbility sA, bool prepare) {
	name = "Detect Magic";
	lvl = 1;
	type = Divination;
	cast = action;
	ritual = true;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "For the duration, you sense the presence of magic within 30 feet of you. If you sense magic in this way, you can use your action to see a faint aura around any visible creature or object in the area that bears magic, and you learn its school of magic, if any.\nThe spell can penetrate most barriers, but it is blocked by 1 foot of stone, 1 inch of common metal, a thin sheet of lead, or 3 feet of wood or dirt.";
}
void DetectMagic::effect() {

}

DetectPoisonandDisease::DetectPoisonandDisease(spellAbility sA, bool prepare) {
	name = "Detect Poison and Disease";
	lvl = 1;
	type = Divination;
	cast = action;
	ritual = true;
	range = 0;
	verbal = true;
	somatic = true;
	material = "a yew leaf";
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "For the duration, you can sense the presence and location of poisons, poisonous creatures, and diseases within 30 feet of you. You also identify the kind of poison, poisonous creature, or disease in each case.\nThe spell can penetrate most barriers, but it is blocked by 1 foot of stone, 1 inch of common metal, a thin sheet of lead, or 3 feet of wood or dirt.";
}
void DetectPoisonandDisease::effect() {

}

DisguiseSelf::DisguiseSelf(spellAbility sA, bool prepare) {
	name = "Disguise Self";
	lvl = 1;
	type = Illusion;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You make yourself -- including your clothing, armor, weapons, and other belongings on your person -- look different until the spell ends or until you use your action to dismiss it. You can seem 1 foot shorter or taller and can appear thin, fat, or in between. You can't change your body type, so you must adopt a form that has the same basic arrangement of limbs. Otherwise, the extent of the illusion is up to you.\nThe changes wrought by this spell fail to hold up to physical inspection.For example, if you use this spell to add a hat to your outfit, objects pass through the hat, and anyone who touches it would feel nothing or would feel your head and hair.If you use this spell to appear thinner than you are, the hand of someone who reaches out to touch you would bump into you while it was seemingly still in midair.\nTo discern that you are disguised, a creature can use its action to inspect your appearance and must succeed on an Intelligence(Investigation) check against your spell save DC.";
}
void DisguiseSelf::effect() {

}

DissonantWhispers::DissonantWhispers(spellAbility sA, bool prepare) {
	name = "Dissonant Whispers";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = false;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You whisper a discordant melody that only one creature of your choice within range can hear, wracking it with terrible pain. The target must make a Wisdom saving throw. On a failed save, it takes 3d6 psychic damage and must immediately use its reaction, if available, to move as far as its speed allows away from you. The creature doesn't move into obviously dangerous ground, such as a fire or a pit. On a successful save, the target takes half as much damage and doesn't have to move away. A deafened creature automatically succeeds on the save.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d6 for each slot level above 1st.";
}
void DissonantWhispers::effect() {

}

DivineFavor::DivineFavor(spellAbility sA, bool prepare) {
	name = "Divine Favor";
	lvl = 1;
	type = Evocation;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "Your prayer empowers you with divine radiance. Until the spell ends, your weapon attacks deal an extra 1d4 radiant damage on a hit.";
}
void DivineFavor::effect() {

}

EnsnaringStrike::EnsnaringStrike(spellAbility sA, bool prepare) {
	name = "Ensnaring Strike";
	lvl = 1;
	type = Conjuration;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "The next time you hit a creature with a weapon attack before this spell ends, a writhing mass of thorny vines appears at the point of impact, and the target must succeed on a Strength saving throw or be restrained by the magical vines until the spell ends. A Large or larger creature has advantage on this saving throw. If the target succeeds on the save, the vines shrivel away.\nWhile restrained by this spell, the target takes 1d6 piercing damage at the start of each of its turns. A creature restrained by the vines or one that can touch the creature can use its action to make a Strength check against your spell save DC. On a success, the target is freed.\nAt Higher Levels. If you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d6 for each slot level above 1st.";
}
void EnsnaringStrike::effect() {

}

Entangle::Entangle(spellAbility sA, bool prepare) {
	name = "Entangle";
	lvl = 1;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 90;
	verbal = true;
	somatic = true;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "Grasping weeds and vines sprout from the ground in a 20 foot square starting from a point within range. For the duration, these plants turn the ground in the area into difficult terrain.\nA creature in the area when you cast the spell must succeed on a Strength saving throw or be restrained by the entangling plants until the spell ends.A creature restrained by the plants can use its action to make a Strength check against your spell save DC. On a success, it frees itself.\nWhen the spell ends, the conjured plants wilt away.";
}
void Entangle::effect() {

}

ExpeditiousRetreat::ExpeditiousRetreat(spellAbility sA, bool prepare) {
	name = "Expeditious Retreat";
	lvl = 1;
	type = Transmutation;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "This spell allows you to move at an incredible pace. When you cast this spell, and then as a bonus action on each of your turns until the spell ends, you can take the Dash action.";
}
void ExpeditiousRetreat::effect() {

}

FaerieFire::FaerieFire(spellAbility sA, bool prepare) {
	name = "Faerie Fire";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "Each object in a 20 foot cube within range is outlined in blue, green, or violet light (your choice). Any creature in the area when the spell is cast is also outlined in light if it fails a Dexterity saving throw. For the duration, objects and affected creatures shed dim light in a 10 foot radius.\nAny attack roll against an affected creature or object has advantage if the attacker can see it, and the affected creature or object can't benefit from being invisible.";
}
void FaerieFire::effect() {

}

FalseLife::FalseLife(spellAbility sA, bool prepare) {
	name = "False Life";
	lvl = 1;
	type = Necromancy;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	material = "a small amount of alcohol or distilled spirits)";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "Bolstering yourself with a necromantic facsimile of life, you gain 1d4 + 4 temporary hit points for the duration.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, you gain 5 additional temporary hit points for each slot level above 1st.";
}
void FalseLife::effect() {

}

FeatherFall::FeatherFall(spellAbility sA, bool prepare) {
	name = "Feather Fall";
	lvl = 1;
	type = Transmutation;
	cast = reaction;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = false;
	material = "a small feather or piece of down";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "Choose up to five falling creatures within range. A falling creature's rate of descent slows to 60 feet per round until the spell ends. If the creature lands before the spell ends, it takes no falling damage and can land on its feet, and the spell ends for that creature.";
}
void FeatherFall::effect() {

}

FindFamiliar::FindFamiliar(spellAbility sA, bool prepare) {
	name = "Find Familiar";
	lvl = 1;
	type = Conjuration;
	cast = hour;
	ritual = false;
	range = 10;
	verbal = true;
	somatic = true;
	material = "10 gp worth of charcoal, incense, and herbs that must be consumed by fire in a brass brazier";
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You gain the service of a familiar, a spirit that takes an animal form you choose: bat, cat, crab, frog (toad), hawk, lizard, octopus, owl, poisonous snake, fish (quipper), rat, raven, sea horse, spider, or weasel. Appearing in an unoccupied space within range, the familiar has the statistics of the chosen form, though it is a celestial, fey, or fiend (your choice) instead of a beast.\nYour familiar acts independently of you, but it always obeys your commands. In combat, it rolls its own initiative and acts on its own turn. A familiar can't attack, but it can take other actions as normal.\nWhen the familiar drops to 0 hit points, it disappears, leaving behind no physical form. It reappears after you cast this spell again.\nWhile your familiar is within 100 feet of you, you can communicate with it telepathically. Additionally, as an action, you can see through your familiar's eyes and hear what it hears until the start of your next turn, gaining the benefits of any special senses that the familiar has. During this time, you are deaf and blind with regard to your own senses.\nAs an action, you can temporarily dismiss your familiar. It disappears into a pocket dimension where it awaits your summons. Alternatively, you can dismiss it forever. As an action while it is temporarily dismissed, you can cause it to reappear in any unoccupied space within 30 feet of you.\nYou can't have more than one familiar at a time. If you cast this spell while you already have a familiar, you instead cause it to adopt a new form. Choose one of the forms from the above list. Your familiar transforms into the chosen creature.\nFinally, when you cast a spell with a range of touch, your familiar can deliver the spell as if it had cast the spell.Your familiar must be within 100 feet of you, and it must use its reaction to deliver the spell when you cast it.If the spell requires an attack roll, you use your attack modifier for the roll.";
}
void FindFamiliar::effect() {

}

FogCloud::FogCloud(spellAbility sA, bool prepare) {
	name = "Fog Cloud";
	lvl = 1;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "You create a 20 foot radius sphere of fog centered on a point within range. The sphere spreads around corners, and its area is heavily obscured. It lasts for the duration or until a wind of moderate or greater speed (at least 10 miles per hour) disperses it.\nAt Higher Levels.When you cast this spell using a spell slot of 2nd level or higher, the radius of the fog increases by 20 feet for each slot level above 1st.";
}
void FogCloud::effect() {

}

Goodberry::Goodberry(spellAbility sA, bool prepare) {
	name = "Goodberry";
	lvl = 1;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "a sprig of mistletoe";
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "Up to ten berries appear in your hand and are infused with magic for the duration. A creature can use its action to eat one berry. Eating a berry restores 1 hit point, and the berry provides enough nourishment to sustain a creature for one day.\nThe berries lose their potency if they have not been consumed within 24 hours of the casting of this spell.";
}
void Goodberry::effect() {

}

Grease::Grease(spellAbility sA, bool prepare) {
	name = "Grease";
	lvl = 1;
	type = Conjuration;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	material = "a bit of pork rind or butter";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "Slick grease covers the ground in a 10 foot square centered on a point within range and turns it into difficult terrain for the duration.\nWhen the grease appears, each creature standing in its area must succeed on a Dexterity saving throw or fall prone. A creature that enters the area or ends its turn there must also succeed on a Dexterity saving throw or fall prone.";
}
void Grease::effect() {

}

GuidingBolt::GuidingBolt(spellAbility sA, bool prepare) {
	name = "Guiding Bolt";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	duration = 6;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A flash of light streaks toward a creature of your choice within range. Make a ranged spell attack against the target. On a hit, the target takes 4d6 radiant damage, and the next attack roll made against this target before the end of your next turn has advantage, thanks to the mystical dim light glittering on the target until then.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d6 for each slot level above 1st.";
}
void GuidingBolt::effect() {

}

HailofThorns::HailofThorns(spellAbility sA, bool prepare) {
	name = "Hail of Thorns";
	lvl = 1;
	type = Conjuration;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "The next time you hit a creature with a ranged weapon attack before the spell ends, this spell creates a rain of thorns that sprouts from your ranged weapon or ammunition. In addition to the normal effect of the attack, the target of the attack and each creature within 5 feet of it must make a Dexterity saving throw. A creature takes 1dlO piercing damage on a failed save, or half as much damage on a successful one.\nAt Higher Levels. If you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d10 for each slot level above 1st(to a maximum of 6 d10).";
}
void HailofThorns::effect() {

}

HealingWord::HealingWord(spellAbility sA, bool prepare) {
	name = "Healing Word";
	lvl = 1;
	type = Evocation;
	cast = bonus;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = false;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A creature of your choice that you can see within range regains hit points equal to 1d4 + your spellcasting ability modifier. This spell has no effect on undead or constructs.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the healing increases by 1d4 for each slot level above 1st.";
}
void HealingWord::effect() {

}

HellishRebuke::HellishRebuke(spellAbility sA, bool prepare) {
	name = "Hellish Rebuke";
	lvl = 1;
	type = Evocation;
	cast = reaction;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You point your finger, and the creature that damaged you is momentarily surrounded by hellish flames. The creature must make a Dexterity saving throw. It takes 2d10 fire damage on a failed save, or half as much damage on a successful one.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d10 for each slot level above 1st.";
}
void HellishRebuke::effect() {

}

Heroism::Heroism(spellAbility sA, bool prepare) {
	name = "Heroism";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "A willing creature you touch is imbued with bravery. Until the spell ends, the creature is immune to being frightened and gains temporary hit points equal to your spellcasting ability modifier at the start of each of its turns. When the spell ends, the target loses any remaining temporary hit points from this spell.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, you can target one additional creature for each slot level above 1st.";
}
void Heroism::effect() {

}

Hex::Hex(spellAbility sA, bool prepare) {
	name = "Hex";
	lvl = 1;
	type = Enchantment;
	cast = bonus;
	ritual = false;
	range = 90;
	verbal = true;
	somatic = true;
	material = "the petrified eye of a newt";
	duration = 3600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "You place a curse on a creature that you can see within range. Until the spell ends, you deal an extra 1d6 necrotic damage to the target whenever you hit it with an attack. Also, choose one ability when you cast the spell. The target has disadvantage on ability checks made with the chosen ability.\nIf the target drops to 0 hit points before this spell ends, you can use a bonus action on a subsequent turn of yours to curse a new creature.\nA remove curse cast on the target ends this spell early.\nAt Higher Levels. When you cast this spell using a spell slot of 3rd or 4th level, you can maintain your concentration on the spell for up to 8 hours. When you use a spell slot of 5th level or higher, you can maintain your concentration on the spell for up to 24 hours.";
}
void Hex::effect() {

}

HuntersMark::HuntersMark(spellAbility sA, bool prepare) {
	name = "Hunter's Mark";
	lvl = 1;
	type = Divination;
	cast = bonus;
	ritual = false;
	range = 90;
	verbal = true;
	somatic = false;
	duration = 3600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "You choose a creature you can see within range and mystically mark it as your quarry. Until the spell ends, you deal an extra 1d6 damage to the target whenever you hit it with a weapon attack, and you have advantage on any Wisdom (Perception) or Wisdom (Survival) check you make to find it. If the target drops to 0 hit points before this spell ends, you can use a bonus action on a subsequent turn of yours to mark a new creature.\nAt Higher Levels. When you cast this spell using a spell slot of 3rd or 4th level, you can maintain your concentration on the spell for up to 8 hours. When you use a spell slot of 5th level or higher, you can maintain your concentration on the spell for up to 24 hours.";
}
void HuntersMark::effect() {

}

Identify::Identify(spellAbility sA, bool prepare) {
	name = "Identify";
	lvl = 1;
	type = Divination;
	cast = minute;
	ritual = true;
	range = 5;
	verbal = true;
	somatic = true;
	material = "a pearl worth at least 100 gp and an owl feather";
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You choose one object that you must touch throughout the casting of the spell. If it is a magic item or some other magic imbued object, you learn its properties and how to use them, whether it requires attunement to use, and how many charges it has, if any. You learn whether any spells are affecting the item and what they are. If the item was created by a spell, you learn which spell created it.\nIf you instead touch a creature throughout the casting, you learn what spells, if any, are currently affecting it.";
}
void Identify::effect() {

}

IllusoryScript::IllusoryScript(spellAbility sA, bool prepare) {
	name = "Illusory Script";
	lvl = 1;
	type = Illusion;
	cast = minute;
	ritual = true;
	range = 5;
	verbal = false;
	somatic = true;
	material = "";
	duration = 864000;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You write on parchment, paper, or some other suitable writing material and imbue it with a potent illusion that lasts for the duration.\nTo you and any creatures you designate when you cast the spell, the writing appears normal, written in your hand, and conveys whatever meaning you intended when you wrote the text.To all others, the writing appears as if it were written in an unknown or magical script that is unintelligible. Alternatively, you can cause the writing to appear to be an entirely different message, written in a different hand and language, though the language must be one you know.\nShould the spell be dispelled, the original script and the illusion both disappear.\nA creature with truesight can read the hidden message.";
}
void IllusoryScript::effect() {

}

InflictWounds::InflictWounds(spellAbility sA, bool prepare) {
	name = "Inflict Wounds";
	lvl = 1;
	type = Necromancy;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "Make a melee spell attack against a creature you can reach. On a hit, the target takes 3d10 necrotic damage.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d10 for each slot level above 1st.";
}
void InflictWounds::effect() {

}

Jump::Jump(spellAbility sA, bool prepare) {
	name = "Jump";
	lvl = 1;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "a grasshopper's hind leg";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You touch a creature. The creature's jump distance is tripled until the spell ends.";
}
void Jump::effect() {

}

Longstrider::Longstrider(spellAbility sA, bool prepare) {
	name = "Longstrider";
	lvl = 1;
	type = Transmutation;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "a pinch of dirt";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You touch a creature. The target's speed increases by 10 feet until the spell ends.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, you can target one additional creature for each slot level above 1st.";
}
void Longstrider::effect() {

}

MageArmor::MageArmor(spellAbility sA, bool prepare) {
	name = "Mage Armor";
	lvl = 1;
	type = Abjuration;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "a piece of cured leather";
	duration = 28800;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You touch a willing creature who isn't wearing armor, and a protective magical force surrounds it until the spell ends. The target's base AC becomes 13 + its Dexterity modifier. The spell ends if the target dons armor or if you dismiss the spell as an action.";
}
void MageArmor::effect() {

}

MagicMissile::MagicMissile(spellAbility sA, bool prepare) {
	name = "Magic Missile";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 120;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You create three glowing darts of magical force. Each dart hits a creature of your choice that you can see within range. A dart deals 1d4 + 1 force damage to its target. The darts all strike simultaneously, and you can direct them to hit one creature or several.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the spell creates one more dart for each slot level above 1st.";
}
void MagicMissile::effect() {

}

ProtectionfromEvilandGood::ProtectionfromEvilandGood(spellAbility sA, bool prepare) {
	name = "Protection from Evil and Good";
	lvl = 1;
	type = Abjuration;
	cast = action;
	ritual = false;
	range = 5;
	verbal = true;
	somatic = true;
	material = "holy water or powdered silver and iron, which the spell consumes";
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "Until the spell ends, one willing creature you touch is protected against certain types of creatures: aberrations, celestials, elementals, fey, fiends, and undead.\nThe protection grants several benefits. Creatures of those types have disadvantage on attack rolls against the target.The target also can't be charmed, frightened, or possessed by them. If the target is already charmed, frightened, or possessed by such a creature, the target has advantage on any new saving throw against the relevant effect.";
}
void ProtectionfromEvilandGood::effect() {

}

PurifyFoodandDrink::PurifyFoodandDrink(spellAbility sA, bool prepare) {
	name = "Purify Food and Drink";
	lvl = 1;
	type = Transmutation;
	cast = action;
	ritual = true;
	range = 10;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "All nonmagical food and drink within a 5 foot radius sphere centered on a point of your choice within range is purified and rendered free of poison and disease.";
}
void PurifyFoodandDrink::effect() {

}

RayofSickness::RayofSickness(spellAbility sA, bool prepare) {
	name = "Ray of Sickness";
	lvl = 1;
	type = Necromancy;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A ray of sickening greenish energy lashes out toward a creature within range. Make a ranged spell attack against the target. On a hit, the target takes 2d8 poison damage and must make a Constitution saving throw. On a failed save, it is also poisoned until the end of your next turn.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d8 for each slot level above 1st.";
}
void RayofSickness::effect() {

}

Sanctuary::Sanctuary(spellAbility sA, bool prepare) {
	name = "Sanctuary";
	lvl = 1;
	type = Abjuration;
	cast = bonus;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a small silver mirror";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You ward a creature within range against attack. Until the spell ends, any creature who targets the warded creature with an attack or a harmful spell must first make a Wisdom saving throw. On a failed save, the creature must choose a new target or lose the attack or spell. This spell doesn't protect the warded creature from area effects, such as the explosion of a fireball.\nIf the warded creature makes an attack or casts a spell that affects an enemy creature, this spell ends.";
}
void Sanctuary::effect() {

}

SearingSmite::SearingSmite(spellAbility sA, bool prepare) {
	name = "Searing Smite";
	lvl = 1;
	type = Evocation;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "The next time you hit a creature with a melee weapon attack during the spell's duration, your weapon flares with white - hot intensity, and the attack deals an extra 1d6 fire damage to the target and causes the target to ignite in flames. At the start of each of its turns until the spell ends, the target must make a Constitution saving throw. On a failed save, it takes 1d6 fire damage. On a successful save, the spell ends. If the target or a creature within 5 feet of it uses an action to put out the flames, or if some other effect douses the flames(such as the target being submerged in water), the spell ends. \nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the initial extra damage dealt by the attack increases by 1d6 for each slot level above 1st.";
}
void SearingSmite::effect() {

}

Shield::Shield(spellAbility sA, bool prepare) {
	name = "Shield";
	lvl = 1;
	type = Abjuration;
	cast = reaction;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 6;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "An invisible barrier of magical force appears and protects you. Until the start of your next turn, you have a +5 bonus to AC, including against the triggering attack, and you take no damage from magic missile.";
}
void Shield::effect() {

}

ShieldofFaith::ShieldofFaith(spellAbility sA, bool prepare) {
	name = "Shield of Faith";
	lvl = 1;
	type = Abjuration;
	cast = bonus;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	material = "a small parchment with a bit of holy text written on it";
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "A shimmering field appears and surrounds a creature of your choice within range, granting it a +2 bonus to AC for the duration.";
}
void ShieldofFaith::effect() {

}

SilentImage::SilentImage(spellAbility sA, bool prepare) {
	name = "Silent Image";
	lvl = 1;
	type = Illusion;
	cast = action;
	ritual = false;
	range = 60;
	verbal = true;
	somatic = true;
	material = "a bit of fleece";
	duration = 600;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "You create the image of an object, a creature, or some other visible phenomenon that is no larger than a 15 foot cube. The image appears at a spot within range and lasts for the duration. The image is purely visual; it isn't accompanied by sound, smell, or other sensory effects.\nYou can use your action to cause the image to move to any spot within range. As the image changes location, you can alter its appearance so that its movements appear natural for the image. For example, if you create an image of a creature and move it, you can alter the image so that it appears to be walking.\nPhysical interaction with the image reveals it to be an illusion, because things can pass through it. A creature that uses its action to examine the image can determine that it is an illusion with a successful Intelligence(Investigation) check against your spell save DC. If a creature discerns the illusion for what it is, the creature can see through the image.";
}
void SilentImage::effect() {

}

SleepSpell::SleepSpell(spellAbility sA, bool prepare) {
	name = "Sleep";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 90;
	verbal = true;
	somatic = true;
	material = "a pinch of fine sand, rose petals, or a cricket";
	duration = 60;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "This spell sends creatures into a magical slumber. Roll 5d8; the total is how many hit points of creatures this spell can affect. Creatures within 20 feet of a point you choose within range are affected in ascending order of their current hit points (ignoring unconscious creatures).\nStarting with the creature that has the lowest current hit points, each creature affected by this spell falls unconscious until the spell ends, the sleeper takes damage, or someone uses an action to shake or slap the sleeper awake. Subtract each creature's hit points from the total before moving on to the creature with the next lowest hit points. A creature's hit points must be equal to or less than the remaining total for that creature to be affected.\nUndead and creatures immune to being charmed aren't affected by this spell.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, roll an additional 2d8 for each slot level above 1st.";
}
void SleepSpell::effect() {

}

SpeakwithAnimals::SpeakwithAnimals(spellAbility sA, bool prepare) {
	name = "Speak with Animals";
	lvl = 1;
	type = Divination;
	cast = action;
	ritual = true;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "You gain the ability to comprehend and verbally communicate with beasts for the duration. The knowledge and awareness of many beasts is limited by their intelligence, but at minimum, beasts can give you information about nearby locations and monsters, including whatever they can perceive or have perceived within the past day. You might be able to persuade a beast to perform a small favor for you, at the GM's discretion.";
}
void SpeakwithAnimals::effect() {

}

TashasHideousLaughter::TashasHideousLaughter(spellAbility sA, bool prepare) {
	name = "Tasha's Hideous Laughter";
	lvl = 1;
	type = Enchantment;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "tiny tarts and a feather that is waved in the air";
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "A creature of your choice that you can see within range perceives everything as hilariously funny and falls into fits of laughter if this spell affects it. The target must succeed on a Wisdom saving throw or fall prone, becoming incapacitated and unable to stand up for the duration. A creature with an Intelligence score of 4 or less isn't affected.\nAt the end of each of its turns, and each time it takes damage, the target can make another Wisdom saving throw. The target has advantage on the saving throw if it's triggered by damage. On a success, the spell ends.";
}
void TashasHideousLaughter::effect() {

}

TensersFloatingDisk::TensersFloatingDisk(spellAbility sA, bool prepare) {
	name = "Tenser's Floating Disk";
	lvl = 1;
	type = Conjuration;
	cast = action;
	ritual = true;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a drop of mercury";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "This spell creates a circular, horizontal plane of force, 3 feet in diameter and 1 inch thick, that floats 3 feet above the ground in an unoccupied space of your choice that you can see within range. The disk remains for the duration, and can hold up to 500 pounds. If more weight is placed on it, the spell ends, and everything on the disk falls to the ground.\nThe disk is immobile while you are within 20 feet of it. If you move more than 20 feet away from it, the disk follows you so that it remains within 20 feet of you. It can move across uneven terrain, up or down stairs, slopes and the like, but it can't cross an elevation change of 10 feet or more. For example, the disk can't move across a 10 foot deep pit, nor could it leave such a pit if it was created at the bottom.\nIf you move more than 100 feet from the disk(typically because it can't move around an obstacle to follow you), the spell ends.";
}
void TensersFloatingDisk::effect() {

}

ThunderousSmite::ThunderousSmite(spellAbility sA, bool prepare) {
	name = "Thunderous Smite";
	lvl = 1;
	type = Evocation;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "The first time you hit with a melee weapon attack during this spell's duration, your weapon rings with thunder that is audible within 300 feet of you, and the attack deals an extra 2d6 thunder damage to the target. Additionally, if the target is a creature, it must succeed on a Strength saving throw or be pushed 10 feet away from you and knocked prone.";
}
void ThunderousSmite::effect() {

}

Thunderwave::Thunderwave(spellAbility sA, bool prepare) {
	name = "Thunderwave";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = true;
	duration = 0;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "A wave of thunderous force sweeps out from you. Each creature in a 15 foot cube originating from you must make a Constitution saving throw. On a failed save, a creature takes 2d8 thunder damage and is pushed 10 feet away from you. On a successful save, the creature takes half as much damage and isn't pushed.\nIn addition, unsecured objects that are completely within the area of effect are automatically pushed 10 feet away from you by the spell's effect, and the spell emits a thunderous boom audible out to 300 feet.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d8 for each slot level above 1st.";
}
void Thunderwave::effect() {

}

UnseenServant::UnseenServant(spellAbility sA, bool prepare) {
	name = "Unseen Servant";
	lvl = 1;
	type = Conjuration;
	cast = action;
	ritual = true;
	range = 60;
	verbal = true;
	somatic = true;
	material = "a piece of string and a bit of wood";
	duration = 3600;
	concentration = false;
	spellAbi = sA;
	prep = prepare;
	desc = "This spell creates an invisible, mindless, shapeless force that performs simple tasks at your command until the spell ends. The servant springs into existence in an unoccupied space on the ground within range. It has AC 10, 1 hit point, and a Strength of 2, and it can't attack. If it drops to 0 hit points, the spell ends.\nOnce on each of your turns as a bonus action, you can mentally command the servant to move up to 15 feet and interact with an object. The servant can perform simple tasks that a human servant could do, such as fetching things, cleaning, mending, folding clothes, lighting fires, serving food, and pouring wine. Once you give the command, the servant performs the task to the best of its ability until it completes the task, then waits for your next command.\nIf you command the servant to perform a task that would move it more than 60 feet away from you, the spell ends.";
}
void UnseenServant::effect() {

}

WitchBolt::WitchBolt(spellAbility sA, bool prepare) {
	name = "Witch Bolt";
	lvl = 1;
	type = Evocation;
	cast = action;
	ritual = false;
	range = 30;
	verbal = true;
	somatic = true;
	material = "a twig from a tree that has been struck by lightning";
	duration = 06;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "A beam of crackling, blue energy lances out toward a creature within range, forming a sustained arc of lightning between you and the target. Make a ranged spell attack against that creature. On a hit, the target takes 1d12 lightning damage, and on each of your turns for the duration, you can use your action to deal 1d12 lightning damage to the target automatically. The spell ends if you use your action to do anything else. The spell also ends if the target is ever outside the spell's range or if it has total cover from you.\nAt Higher Levels. When you cast this spell using a spell slot of 2nd level or higher, the initial damage increases by 1d12 for each slot level above 1st.";
}
void WitchBolt::effect() {

}

WrathfulSmite::WrathfulSmite(spellAbility sA, bool prepare) {
	name = "Wrathful Smite";
	lvl = 1;
	type = Evocation;
	cast = bonus;
	ritual = false;
	range = 0;
	verbal = true;
	somatic = false;
	duration = 60;
	concentration = true;
	spellAbi = sA;
	prep = prepare;
	desc = "The next time you hit with a melee weapon attack during this spell's duration, your attack deals an extra 1d6 psychic damage. Additionally, if the target is a creature, it must make a Wisdom saving throw or be frightened of you until the spell ends. As an action, the creature can make a Wisdom check against your spell save DC to steel its resolve and end this spell.";
}
void WrathfulSmite::effect() {

}