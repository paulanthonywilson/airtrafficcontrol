

/***************************************************************************/
/***************************************************************************
   LinkList	FUNCTION DEFINITIONS

/***************************************************************************/

# include "linklist.h"

   LinkList::LinkList(Boolean Unique_i, int Id_i)
	// allows duplicate entries unless Unique_i is true
		:
		Unique_c (Unique_i),
		Count_c	(0),
		Head_c (NULL),
		IsNodeFound_c (False),
		FoundNode_c (NULL),
		PreviousToFoundNode_c (NULL),
		ItCnt_c (0),
		Id_c (Id_i)
		{
	}

/***************************************************************************/
	LinkList::~LinkList () {
		DeleteList();
	}

/***************************************************************************/
	void LinkList::DeleteList ()	{
		Node *Crnt, *Next;

		for (Crnt = Head_c; Crnt != NULL; Crnt = Next)	{
			Next = Crnt->Next;
			delete Crnt;
		}
	}
/***************************************************************************/
/***************************************************************************/
	void LinkList::AddNode (LinkListContents *NewContents_i)
	//if NewContents_i is already in list and Unique_c then the item is not added
	// require !Guarded()
		{
		TRAP (!Guarded());

		Boolean  AddNodeOk;
		Node  *NewNode = NULL;


		// if list is set as unique, check if an equal item is already present
		if (!Unique_c)	{
			AddNodeOk = True;
		} else	{
			TRAP (Unique_c);
			SearchNode (NewContents_i);
			AddNodeOk = !IsNodeFound();
		}
		if (AddNodeOk)	{

			//Add the item
			NewNode = new Node (NewContents_i, Head_c);
			TRAP (NewNode->Contents == NewContents_i);
			Head_c = NewNode;
			Count_c++;
		}
	}


/***************************************************************************/
	int LinkList::Count()
	// the number of items in the list
		{
		return Count_c;
	}


/***************************************************************************/
	Boolean LinkList::Empty()
	// False unless the list is empty
		{
		return (Count_c == 0);
	}


/***************************************************************************/
	Boolean LinkList::Inside (EifIterator It_i)
	// False unless It_i is inside the list
		{
		return	(
			!It_i.Finished()		&&
			It_i.LinkList_c == this
		);
	}


/***************************************************************************/
	EifIterator  LinkList::Iterator()
	// Returns an Iterator at first item in list
		{
		return EifIterator(*this);
	}


/***************************************************************************/
	Boolean LinkList::Guarded() // protected :BOOLEAN -- in Eiffel version
	// False unless an EifIterator is traversing the list.
	//if Guarded() then no changes may be made to the list

		{
		return (ItCnt_c > 0);
	}


/***************************************************************************/
	void LinkList::SearchNode (LinkListContents *Contents_i)
	// if an equivalent item is in the list then remove ONE, else do nothing.
	// require !Guarded()
		{
		TRAP (!Guarded());

		Node *Crnt = NULL, *OldCrnt = NULL;

		//Search for item
		IsNodeFound_c = False;
		for (Crnt = Head_c; Crnt != NULL && !IsNodeFound_c; Crnt = Crnt->Next)	{
			if (Contents_i->IsEqual (Crnt->Contents))	{

				IsNodeFound_c = True;
				FoundNode_c = Crnt;
				FoundContents_c = Crnt->Contents;
				PreviousToFoundNode_c = OldCrnt;
			}
			OldCrnt = Crnt;
		}
	}

/***************************************************************************/
	Boolean LinkList::IsNodeFound()	{
		return IsNodeFound_c;
	}

/***************************************************************************/
	Node *LinkList::FoundNode()	{
		return FoundNode_c;
	}
/***************************************************************************/
	Node *LinkList::PreviousToFoundNode()	{
		return PreviousToFoundNode_c;
	}

/***************************************************************************/
	LinkListContents *LinkList::FoundContents()	{
		return FoundContents_c;
	}

/***************************************************************************/
	void LinkList::RemoveNode (LinkListContents *Contents_i)
	/* if an equivalent item is in the list then remove ONE, else do nothing.
	 require !Guarded() */
		{
		SearchNode (Contents_i);
		if (IsNodeFound ())	{
			if (FoundNode() == Head_c)	{
				Head_c = FoundNode()->Next;

			} else {
				TRAP (PreviousToFoundNode() != NULL);
				PreviousToFoundNode()->Next = FoundNode()->Next;
			}
			Count_c--;
			delete FoundNode();
		}

	 }

	LinkListContents *LinkList::ItContents (const EifIterator &It_i)
	// returns the contents which the iterator is pointing to
		{
		return It_i.Crnt_c->Contents;
	}

/***************************************************************************/
//EifIterator definitions
/***************************************************************************/
/***************************************************************************/

	EifIterator::EifIterator()	:
		LinkList_c (NULL),
		Crnt_c (NULL)
		{}


/***************************************************************************/
	EifIterator::EifIterator (LinkList &LinkList_i) :
		LinkList_c (&LinkList_i),
		Crnt_c (LinkList_i.Head_c)
		{
		if (!Finished())	{
			LinkList_c->ItCnt_c++;
		}
	}

/***************************************************************************/
	EifIterator::~EifIterator()	{
		if (!Finished())	{
			LinkList_c->ItCnt_c--;
		}
	}

/***************************************************************************/
	EifIterator::EifIterator (const EifIterator &Other_i) :
		LinkList_c (Other_i.LinkList_c),
		Crnt_c (Other_i.Crnt_c)
		{
		if (!Finished()) {
			LinkList_c->ItCnt_c++;
		}
	}
/***************************************************************************/
	EifIterator &EifIterator::operator = (const EifIterator &Other_i)	{

		if (!Finished())	{
			LinkList_c->ItCnt_c--;
		}
		LinkList_c = Other_i.LinkList_c;
		Crnt_c  = Other_i.Crnt_c;

		if (!Finished())	{
			LinkList_c->ItCnt_c++;
		}

		return *this;
	}

/***************************************************************************/
	Boolean EifIterator::Finished()	{
		return Crnt_c == NULL;
	}
/***************************************************************************/
	void EifIterator::First()
	//Go to the first element in the container
		{
		TRAP (LinkList_c != NULL);
		if (Finished())	{
			LinkList_c->ItCnt_c++;
		}

		Crnt_c = LinkList_c->Head_c;
	}

/***************************************************************************/
	void EifIterator::Forth()
	//Go the the next element in the container
		{

		if (!Finished())	{
			Crnt_c = Crnt_c->Next;
			if (Finished())	{
				LinkList_c->ItCnt_c--;
			}
		}
	}


/***************************************************************************/
	void EifIterator::Stop()
	//Make Finished() true.
		{

		if (!Finished())	{
			TRAP (LinkList_c->ItCnt_c > 0);

			Crnt_c = NULL;
			LinkList_c->ItCnt_c--;
		}
	}
