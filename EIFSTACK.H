/*
Eiffel style stack

Paul Wilson

28/4/96

*/

# ifndef _EIFSTACK_H
# define _EIFSTACK_H

# include "stdatc.h"

template <class G>
struct StackNode {

	StackNode (G Item_i, StackNode<G> *Next_i)  :
		Item (Item_i), Next (Next_i) {}

	G Item;
	StackNode<G> *Next;
}

template <class G>
class EifStack	{

private:

	StackNode<G> *Head_c;

	int Count_c;

public:

	EifStack ();

	void Add (G NewItem_i);

	int Count();

	Boolean Empty();

	G &Item();

	void Remove();

};

/****************************************************************************/
template <class G>
	EifStack<G>::EifStack ()	:
		Head_c (NULL),
		Count_c (0)
		{}

/****************************************************************************/
	template <class G>
	int EifStack<G>::Count ()	{
		return Count_c;
	}

/****************************************************************************/
	template <class G>
	Boolean EifStack<G>::Empty()	{
		return Count_c == 0;
	}
/****************************************************************************/
	template <class G>
	void EifStack<G>::Add (G NewItem_i)	{

		Head_c = new StackNode<G> (NewItem_i, Head_c);
		Count_c++;
	}

/****************************************************************************/
	template <class G>
	G &EifStack<G>::Item()	{
		return Head_c->Item;
	}

/****************************************************************************/
	template <class G>
	void EifStack<G>::Remove()	{
		assert (!Empty());

		StackNode<G> *OldHead = Head_c;
		Head_c = Head_c->Next;

		Count_c--;

		delete OldHead;
	}

# endif