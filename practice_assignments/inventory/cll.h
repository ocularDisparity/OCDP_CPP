#ifndef CLL_H
#define CLL_H
#include "item.h"

/*	HEADER DESCRIPTION:
 *	Circular Linked List
 *	It's like a doubly-linked list, but the list loops back around instead of hitting a null pointer.
 *	Keeping a size variable so that its easier to keep track of certain things.
 *	The addNode function will add the node to the "end" of the list, right before the loop-around.
 *	Everything else should be self-explanatory.
 */
 
/*	CODING REMINDER:
 *	Remember getters, setters, and constructors.
 *	"If you are writing either one of: destructor, copy constructor, copy assignment operator, 
 *	move constructor, or move assignment operator, you probably need to write the other four".
 */

class cllnode {
	private:
		item content;
		cllnode* next;
		cllnode* prev;
		int size;
		
	public:
		// constructors
		cllnode(cllnode* next, cllnode* prev);
		cllnode(item content, cllnode* next, cllnode* prev);
		
		// destructor
		~cllnode();
		
		// copy constructor
		
		
		// copy assignment operator
		
		
		// move constructor
		
		
		// move assignment operator
		
		
		//setters
		
		
		//getters
		item getItem();
		cllnode* getNext();
		cllnode* getPrev();
		int getSize();
		
		//member functions
		void addNode();
		void insertItem();
		void sort();
		void debugList(); // prints content of list
		bool checkDuplicate();
};

#endif
