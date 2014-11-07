#include "BaseInventory.h"
#include "Platebody.h"
#include <iostream>

BaseInventory::BaseInventory(void)
{
}

void BaseInventory::addItem(BaseItem* item, int amount) {
	if (item->getCount() == 0) {
		item->setCount(1);
	}
	if (amount < 0 || amount > item->getCount()) {
		amount = item->getCount();
	}
	if (this->hasItem(item->toString())) {
		BaseItem* invItem = this->getItem(item->toString());

		invItem->setCount(invItem->getCount() + amount);
	} else {
		items[item->toString()] = item;
	}
}

void BaseInventory::removeItem(BaseItem* item, int amount) {
	if (amount < 0 || amount > item->getCount()) {
		amount = item->getCount();
	}
	if (this->hasItem(item->toString())) {
		BaseItem* invItem = this->getItem(item->toString());
		invItem->setCount(invItem->getCount() - amount);
		if (invItem->getCount() <= 0) {
			items.erase(items.find(item->toString()));
		}
	}
}

BaseItem* BaseInventory::getItem(std::string itemString) {
	if (this->hasItem(itemString)) {
		return this->items[itemString];
	} 
	return nullptr;
}

bool BaseInventory::hasItem(std::string itemString) {
	if (this->items.find(itemString) != this->items.end()) {
		return true;

	}
	return false;
}

std::string BaseInventory::toString() {
	std::string inventory = "";
	int itemCount = 0;
	for(std::map<std::string, BaseItem*>::iterator it = items.begin(); it != items.end(); ++it)
	{
		inventory.append(it->second->toString());
		inventory.append(" (x" + std::to_string(it->second->getCount()) + ") \t");
		itemCount++;
		if (itemCount % 4 == 0) {
			inventory.append("\n");
		}
	}
	if (itemCount == 0) {
		inventory = "No items in your inventory.";
	}
	return inventory;
}

std::map<std::string, BaseItem*>* BaseInventory::getItems() {
	return &this->items;
}

std::string BaseInventory::itemInformation(BaseItem* item) {
	return "todo";
	//return item->getInformation();
}


BaseInventory::~BaseInventory(void)
{
	for(auto itr = items.begin(); itr != items.end(); itr++)
	{
		delete itr->second;
	}
}
