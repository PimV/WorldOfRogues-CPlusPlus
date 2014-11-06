#pragma once

enum class ItemType 
{
	Sword = 0,
	Shield,
	Helmet,
	Platebody,
	Platelegs,
	HealthPotion,
	ManaPotion,
	ExperiencePotion
};

static const char* item_strings[] = {
	"Sword",
	"Shield",
	"Helmet",
	"Platebody",
	"Platelegs",
	"Health Potion",
	"Mana Potion",
	"Experience Potion"
};