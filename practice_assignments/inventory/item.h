#ifndef ITEM.H
#define ITEM.H
#include<node.h>
#include<string>

/*	HEADER DESCRIPTION:
 *	No two items must use the same item number.
 *	They can share the same name and description, but each item number must be unique.
 *	Every item must go in the inventory. No item can be withheld from the inventory.
 */
 
/*	CODING REMINDER:
 *	Remember getters, setters, and constructors.
 *	"If you are writing either one of: destructor, copy constructor, copy assignment operator, 
 *	move constructor, or move assignment operator, you probably need to write the other four".
 */

class item {
	private:
		string name;
		int itemNo;
		string description;
	public:
		// constructors
		item(string name);
		item(string name, int itemNo);
		item(string name, int itemNo, string description);
		// setters
		void setName();
		void setNum();
		void setDesc();
		// getters
		string getname();
		int getnumber();
		string getdesc();
};

// constructors
item::item(string name) {
	this.name = name;
}

item::item(string name, int itemNo) {
	this.name = name;
	this.itemNo = itemNo;
}

item::item(string name, int itemNo, string description) {
	this.name = name;
	this.itemNo = itemNo;
	this.description = description;
}


// setters
void setName(string name) {
	this.name = name;
}

void setNum(int itemNo) {
	this.itemNo = itemNo;
}

void setDesc(string description) {
	this.description = description;
}


// getters
string getname() {
	return this.name;
}

int getnumber() {
	return this.itemNo;
}

string getdesc() {
	return this.description;
}

#endif
