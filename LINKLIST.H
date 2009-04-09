/*
A simple linked list implementation intended as a base container class

Do not assign to heir within a for statement.


Paul Wilson

9/4/96

*/

# ifndef _LINKLIST_H
# define _LINKLIST_H


# include "stdatc.h"


class LinkListContents	{

	virtual Boolean IsEqual (LinkListContents *Other_i) = DEFERRED;

	friend class LinkList;

};

struct Node	{

	Node (LinkListContents *Contents_i, Node *Next_i) :
		Next (Next_i),
		Contents (Contents_i)	{}

	virtual ~Node()	{
		delete Contents;
	}

	Node *Next;
	LinkListContents *Contents;

	friend class LinkList;
	friend class EifIterator;
};

class LinkList	{

	int Id_c;

private:
	Node 		*Head_c; 	//first item
	int 		Count_c;	// number of items
	Boolean		Unique_c;	// duplicate entries not allowed

	Boolean IsNodeFound_c;
	Node *FoundNode_c;
	LinkListContents *FoundContents_c;
	Node *PreviousToFoundNode_c;


	int 		ItCnt_c;	// number of Iterators traversing the container

protected:

	void AddNode (LinkListContents *NewContents_i);
	//if an equivalent item is already in list and Unique_c then the node is
	// not added
	// require !Guarded()

	void RemoveNode (LinkListContents *Contents_i);
	/* if an equivalent item is in the list then remove ONE, else do nothing.
	 require !Guarded() */

	 void SearchNode (LinkListContents *Contents_i);
	/* If an item in the list == Contents_i, set IsNodeFound to True and FoundNode
	to  the node found, and PreviousToFoundNode to the Node before the node
	found (or NULL if the found node is the head); otherwise set Found to
	False.
	*/

	LinkListContents *ItContents (const EifIterator &It_i);
	// returns the pointer to contents which the iterator is pointing to

	Boolean IsNodeFound();

	Node *FoundNode();

	LinkListContents *FoundContents();

	Node *PreviousToFoundNode();

	LinkListContents *NodeContents (const Node &Node_i);

	LinkList (Boolean Unique_i, int Id_i = 0);
	// allows duplicate entries unless Unique_i is true

	virtual ~LinkList ();

	void DeleteList();

public:

	int ItCnt()	{
		return ItCnt_c;
	}

	int Count();
	// the number of items in the list

	Boolean Empty();
	// False unless the list is empty

	Boolean Inside (EifIterator It_i);
	// False unless It_i is inside the list

	EifIterator Iterator ();
	// returns iterator prepared to traverse the list

	Boolean Guarded(); // protected :BOOLEAN -- in Eiffel version
	/* False unless an Iterator is traversing the list.
	if Guarded() then no changes may be made to the list
	*/

	friend EifIterator;

};


class EifIterator	{

private:
	LinkList	*LinkList_c;
	Node	*First_c;
	Node  *Crnt_c;

public:
	EifIterator (LinkList &LinkList_i);
	EifIterator();
	virtual ~EifIterator();
	EifIterator (const EifIterator &Other_i);
	EifIterator &operator = (const EifIterator &Other_i);

	Boolean Finished();
	void First();     //Go to the first element in the container
	void Forth();	  //Go to the next element in the container
	void Stop();	  //Make Finished() true

	friend LinkList;

};
# endif



/**/