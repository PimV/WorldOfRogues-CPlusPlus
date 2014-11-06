#pragma once

enum class WeaponType
{
	Dagger = 0,
	Sword,
	Axe,
	Hammer,
	Spear,
	Mace,
	Longsword,
	Battleaxe,
	Greatsword,
};

static const char* weapon_strings[] = {
	"Dagger",
	"Sword",
	"Axe",
	"Hammer",
	"Spear",
	"Mace",
	"Longsword",
	"Battleaxe",
	"Greatsword",
};

enum class ArmourType
{
	IronHelmet = 9,
	SteelHelmet = 10,
	MithrilHelmet = 11,
	IronLegs = 12,
	SteelLegs = 13,
	MithrilLegs = 14,
	IronBody = 15,
	SteelBody = 16,
	MithrilBody = 17,
	IronShield = 18,
	SteelShield = 19,
	MithrilShield = 20
};

static const char* armour_strings[] = {
	"Iron Helmet",
	"Steel Helmet",
	"Mithril Helmet",
	"Iron Legs",
	"Steel Legs",
	"Mithril Legs",
	"Iron Body",
	"Steel Body",
	"Mithril Body",
	"Iron Shield",
	"Steel Shield",
	"Mithril Shield"
};