#pragma once

enum class WeaponType
{
	Dagger = 0,
	Sword,
	Axe,
	Hammer,
	Spear,
	Mace,
};

enum class ArmourType
{
	Helmet = 6,
	Legs,
	Body,
	Shield
};

static const char* item_strings[] = {
	"Dagger",
	"Sword",
	"Axe",
	"Hammer",
	"Spear",
	"Mace",
	"Helmet",
	"Legs",
	"Body",
	"Shield"
};