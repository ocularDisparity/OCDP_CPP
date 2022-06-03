#ifndef ITEM_H
#define ITEM_H
#include<string>

/*	HEADER DESCRIPTION:
 *	No two items must use the same item number.
 *	They can share the same name and description, but each item number must be unique.
 *	They can be missing a name or description (or both), but each item must have its own number.
 *	Every item must go in the inventory. No item can be withheld from the inventory.
 */
 
/*	CODING REMINDER:
 *	Remember getters, setters, and constructors.
 *	"If you are writing either one of: destructor, copy constructor, copy assignment operator, 
 *	move constructor, or move assignment operator, you probably need to write the other four".
 */

class item {
	private:
		// member variables
		std::string name;
		int itemNo;
		std::string description;
		
	public:
		// constructors
		item(int);
		item(std::string, int); // name, no description
		item(int, std::string); // description, no name
		item(std::string, int, std::string);
		
		// setters
		void setName(std::string);
		void setNum(int);
		void setDesc(std::string);
		
		// getters
		std::string getName();
		int getNumber();
		std::string getDesc();
};

// KEEP IT SIMPLE, STUPID
/*
// member functions
bool makeItem(int itemNo, cllnode inventory) {
	cllnode currentNode = inventory;
	int count = inventory.size();
	
	bool noDuplicate = true;
	
	while (count != 0) {
		if (currentNode.content.getnumber() != itemNo) {
			throw "Duplicate items numbers! Cannot create a new item of this ID";
		}
		
		currentNode = *currentNode.getNext();
		count -= 1;
	}
	
	return item(itemNo);
}

bool makeItem(std::string name, int itemNo, cllnode inventory) {
	cllnode currentNode = inventory;
	int count = inventory.size();
	
	bool noDuplicate = true;
	
	while (count != 0) {
		if (currentNode.content.getnumber() != itemNo) {
			throw "Duplicate items numbers! Cannot create a new item of this ID";
		}
		
		currentNode = *currentNode.getNext();
		count -= 1;
	}
	
	return item(name, itemNo);
}

bool makeItem(int itemNo, std::string description, cllnode inventory) {
	cllnode currentNode = inventory;
	int count = inventory.size();
	
	bool noDuplicate = true;
	
	while (count != 0) {
		if (currentNode.content.getnumber() != itemNo) {
			throw "Duplicate items numbers! Cannot create a new item of this ID";
		}
		
		currentNode = *currentNode.getNext();
		count -= 1;
	}
	
	return item(itemNo, description);
}

bool makeItem(std::string name, int itemNo, std::string description, cllnode inventory) {
	cllnode currentNode = inventory;
	int count = inventory.size();
	
	while (count != 0) {
		if (currentNode.content.getnumber() != itemNo) {
			throw "Duplicate items numbers! Cannot create a new item of this ID";
		}
		
		currentNode = *currentNode.getNext();
		count -= 1;
	}
	
	return item(name, itemNo, description);
}
*/

#endif
