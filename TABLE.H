/*
Best try implementation of the eiffel/s Table class and iterator.  The
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

10/4/96
ver 0.0
*/
# define TESTING

# ifndef _TABLE_H
# define _TABLE_H

# include "stdatc.h"
# include "linklist.h"


template <class G, class K>
class TableContents :public LinkListContents	{

	G  Item;

	K  Key;

	TableContents (G Item_i, K Key_i) :
		Item (Item_i),
		Key  (Key_i)	{}

	virtual Boolean IsEqual (LinkListContents *Other_i)	{

		return ((TableContents<G, K> * ) Other_i)->Key ==  Key;
	}

	friend Table<G, K>;
	friend TableKeyOnlyContents<G, K>;
};

template <class G, class K>
class TableKeyOnlyContents :public LinkListContents	{

	K  Key;

	TableKeyOnlyContents (K Key_i) :
		Key  (Key_i)	{}

	virtual Boolean IsEqual (LinkListContents *Other_i)	{


		return ((TableContents<G, K> * ) Other_i)->Key ==  Key;
	}

	friend Table<G, K>;
};


template <class G, class K>
class Table	: public LinkList{

private:
	G				*FoundItem_c;
	K				*FoundKey_c;
	Boolean 		Found_c;

public:


	Table (Boolean Unique_i, int Id_i = 0);
	// allows duplicate key entries unless Unique_i is true

	void Add (G NewItem_i, K NewKey_i);
	//if NewKey_i is already in table and Unique_c then the item is not added
	// require !Guarded()

	Boolean Found();
	// False unless the last call to search was succesful

	G &FoundItem();
	// The item found by the last call to search; only valid is Found is True

	G &Item (const EifIterator  &It_i);
	// The item to which the TbIterator is pointing

	void Remove (const K &Key_i);
	/* if an Key == Key_i is in the table then remove ONE, else do nothing.
	 require !Guarded() */

	void Search (const K &Key_i);
	/* If Key_i is in the table, set Found to True and FoundItem to
	 the item found; otherwise set Found to False.
	*/

	K &FoundKey();
	// Return key found during last call to search.  Only valid if Found() is
	// true

	K &Key (const EifIterator  &It_i);
	// The key to which the TbIterator is pointing

	void Replace (const G &Replacement_i, const K &Key_i);
	// if Key_i is present replace its item with Replacement_i, else
	// make a new entry

};

/***************************************************************************/
/***************************************************************************
	FUNCTION DEFINITIONS

/***************************************************************************/

	template<class G, class K>
	Table<G, K>::Table(Boolean Unique_i, int Id_i)
	// allows duplicate entries unless Unique_i is true
		:
		LinkList (Unique_i, Id_i),
		Found_c (False),
		FoundKey_c (NULL),
		FoundItem_c (NULL)
		{}


/***************************************************************************/
	template <class G, class K>
	void Table<G, K>::Add (G NewItem_i, K NewKey_i)
	//if NewItem_i is already in list and Unique_c then the item is not added
	// require !Guarded()
		{
		assert (!Guarded());

		TableContents<G, K> *NewContent =
			new TableContents<G, K> (NewItem_i, NewKey_i);
		AddNode (NewContent);

	}


/***************************************************************************/
	template <class G, class K>
	Boolean Table<G, K>::Found()
	// False unless the last call to search was successful
		{
		return Found_c;
	}


/***************************************************************************/
	template <class G, class K>
	G &Table<G, K>::FoundItem()
	// The item found by the last call to search; only valid is Found is True
		{
		return *FoundItem_c;
	}


/***************************************************************************/
	template <class G, class K>
	K &Table<G, K>::FoundKey()
	// The key found by the last call to search; only valid is Found is True
		{
		return *FoundKey_c;
	}


/***************************************************************************/
	template <class G, class K>
	G &Table<G, K>::Item (const EifIterator &It_i)
	// The item to which the TbIterator is pointing
		{
		assert (Inside (It_i));

		TableContents<G,K> *Contents =
			(TableContents<G, K> *) ItContents (It_i);

		return Contents->Item;
	}

/***************************************************************************/
	template <class G, class K>
	K &Table<G, K>::Key (const EifIterator &It_i)
	// The item to which the TbIterator is pointing
		{
		assert (Inside (It_i));

		TableContents<G,K> *Contents =
			(TableContents<G, K> *) ItContents (It_i);

		return Contents->Key;
	}

/***************************************************************************/
	template <class G, class K>
	void Table<G, K>::Remove (const K &Key_i)
	// if a Key_i is in the list then remove ONE, else do nothing.
	// require !Guarded()
		{
		assert (!Guarded());

		TableKeyOnlyContents<G, K> RemoveContents (Key_i);

		RemoveNode (&RemoveContents);
	}

/***************************************************************************/
	template <class G, class K>
	void Table<G, K>::Search (const K &Key_i)
	// If Key_i set Found to True and FoundItem to
	// the item found; otherwise set Found to False.
		{
		TableKeyOnlyContents<G, K> SearchContents (Key_i);

		SearchNode (&SearchContents);

		Found_c = IsNodeFound();

		if (Found_c)	{
			FoundItem_c = &((TableContents <G, K> *) FoundContents())->Item;
			FoundKey_c  = &((TableContents <G, K> *) FoundContents())->Key;
		}

	}

/***************************************************************************/
	template <class G, class K>
	void Table<G, K>::Replace (const G &Replacement_i, const K &Key_i)
	// if Key_i is present replace its item with Replacement_i, else
	// make a new entry
		{
		Node *ReplaceNode;
		TableContents<G, K>	*ReplaceContents =
			new TableContents<G, K> (Replacement_i, Key_i);

		SearchNode (ReplaceContents);

		if (IsNodeFound())	{
			ReplaceNode = new Node (ReplaceContents, FoundNode()->Next);
			PreviousToFoundNode()->Next = ReplaceNode;
			delete FoundNode();

		} else	{
			AddNode (ReplaceContents);
		}
	}

/**/

# endif