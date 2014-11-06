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
	IronHelmet = 0,
	SteelHelmet,
	MithrilHelmet,
	IronLegs,
	SteelLegs,
	MithrilLegs,
	IronBody,
	SteelBody,
	MithrilBody,
	IronShield,
	SteelShield,
	MithrilShield
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