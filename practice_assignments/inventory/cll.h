#ifndef CLL.H
#define CLL.H
#include<string>

/*	HEADER DESCRIPTION:
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

class node {
	private:
		item content;
		node* next;
		node* prev;
		int size;
	public:
		//constructors
		
		node(node* next, node* prev);
		node(item content, node* next, node* prev);
		
		//destructor
		~node();
		
		//setters
		
		
		//getters
		node getNext();
		node getPrev();
		
		//class functions
		void addNode();
		void debugList(); // prints content of list
		bool checkDuplicate();
};

node getNext() {
	return 
}

#endif
