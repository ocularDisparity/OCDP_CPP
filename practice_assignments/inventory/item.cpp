#include "item.h"

/*	HEADER DESCRIPTION:
 *	No two items must use the same item number.
 *	They can share the same name and description, but each item number must be unique.
 *	They can be missing a name or description (or both), but each item must have its own number.
 *	Every item must go in the inventory. No item can be withheld from the inventory.
 */

// constructors
item::item(int itemNo) {
	this->itemNo = itemNo;
}

item::item(std::string name, int itemNo) {
	this->itemNo = itemNo;
	this->name = name;
}

item::item(int itemNo, std::string description) {
	this->itemNo = itemNo;
	this->description = description;
}

item::item(std::string name, int itemNo, std::string description) {
	this->itemNo = itemNo;
	this->name = name;
	this->description = description;
}


// setters
void item::setName(std::string name) {
	this->name = name;
}

void item::setNum(int itemNo) {
	this->itemNo = itemNo;
}

void item::setDesc(std::string description) {
	this->description = description;
}


// getters
std::string item::getName() {
	return name;
}

int item::getNumber() {
	return itemNo;
}

std::string item::getDesc() {
	return description;
}
