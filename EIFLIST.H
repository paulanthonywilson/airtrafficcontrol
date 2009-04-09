/*
Best try implementation of the eiffel/s list class and iterator.  The
function protected has been renamed as Guarded to avoid confusion\clash with
the C++ keyword protected.  My naming conventions have been adopted.

Note that a count of active iterators is kept, to determine whether the table
should be guarded.  This involves the count being decremented when an active
iterator is destroyed.  The Borland Turbo C++ v3.0 compiler (at least) does
not call a destructor for a function result within a for statement. eg
	for (Iter = Tabl.Iterator();0;)
results in a count of TWO iterators in Tabl, one of which cannot be destroyed.
	Iter = Tabl.Iterator();
is OK.


Paul Wilson

9/4/96

ver 0.1
using LinkList as Base class
22/4/96 PW

*/


# ifndef _EIFLIST_H
# define _EIFLIST_H

# include "stdatc.h"
# include "linklist.h"



template <class G>
class EifListContents :public LinkListContents	{

	G  Item;

	EifListContents (G Item_i) :
		Item (Item_i)	{}

	virtual Boolean IsEqual (LinkListContents *Other_i)	{

		return ((EifListContents<G> * ) Other_i)->Item ==  Item;
	}

	friend EifList<G>;
};


template <class G>
class EifList	: public LinkList {

private:
	G				*FoundItem_c;
	Boolean 		Found_c;

public:


	EifList (Boolean Unique_i);
	// allows duplicate entries unless Unique_i is true

	EifList (Boolean Unique_i, int Id_i);
	// allows duplicate entries unless Unique_i is true

	void Add (G NewItem_i);
	//if NewItem_i is already in list and Unique_c then the item is not added
	// require !Guarded()

	Boolean Found();
	// False unless the last call to search was succesful

	G &FoundItem();
	// The item found by the last call to search; only valid is Found is True

	G &Item (EifIterator  It_i);
	// The item to which the EifIterator is pointing

	void Remove (G Item_i);
	/* if an item == Item_i is in the list then remove ONE, else do nothing.
	 require !Guarded() */

	void Search (G Item_i);
	/* If an item in the list == Item_i, set Found to True and FoundItem to
	 the item found; otherwise set Found to False.
	*/

};

/***************************************************************************/
	template <class G>
	EifList<G>::EifList (Boolean Unique_i) :
		LinkList (Unique_i)
		{}


/***************************************************************************/
	template <class G>
	EifList<G>::EifList (Boolean Unique_i, int Id_i) :
		LinkList (Unique_i, Id_i)
		{}


/***************************************************************************/
	template <class G>
	void EifList<G>::Add (G NewItem_i)
	//if NewItem_i is already in list and Unique_c then the item is not added
	// require !Guarded()
		{

		EifListContents<G> *NewContent = new EifListContents<G> (NewItem_i);

		AddNode (NewContent);
	}


/***************************************************************************/
	template <class G>
	Boolean EifList<G>::Found()
	// False unless the last call to search was succesful
		{
		return Found_c;
	}

/***************************************************************************/
	template <class G>
	G &EifList<G>::FoundItem()
	// The item found by the last call to search; only valid is Found is True
		{
		return *FoundItem_c;
	}


/**************************************************************************/
	template <class G>
	G &EifList<G>::Item (EifIterator  It_i)
	// The item to which the EifIterator is pointing
		{

		EifListContents<G> *Contents =
			(EifListContents<G> *) ItContents (It_i);
		return Contents->Item;
	}



/***************************************************************************/
	template <class G>
	void EifList<G>::Remove (G Item_i)
	// if an item == Item_i is in the list then remove ONE, else do nothing.
	// require !Guarded()
		{
		EifListContents<G> ContentsToRemove (Item_i);

		RemoveNode (&ContentsToRemove);
	}
/***************************************************************************/
	template <class G>
	void EifList<G>::Search (G Item_i)
	// If an item in the list == Item_i, set Found to True and FoundItem to
	// the item found; otherwise set Found to False.
		{
		EifListContents<G> SearchContents (Item_i);

		SearchNode (&SearchContents);

		Found_c = IsNodeFound();

		if (Found_c)	{
			FoundItem_c = &((EifListContents<G> *) FoundContents() )->Item;
		}
	}



/**/

# endif

