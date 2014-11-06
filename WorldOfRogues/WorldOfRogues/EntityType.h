#pragma once

enum class EntityType
{
	Rat = 0,
	Zombie,
	Skeleton,
	Dwarf,
	Boss,
	Player
};

static const char* entity_strings[] = {
	"Rat",
	"Zombie",
	"Skeleton",
	"Dwarf",
	"Boss",
	"Player"
};