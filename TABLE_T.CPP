/* Test for Table class

Paul Wilson

*/


# define TESTING

# include "stdatc.h"
# include "table.h"
# include "eiflist.h"


int main()	{


	EifList <int> l (True);
	Table<int, int> TestTab(True);
	EifIterator	TI;
	int i;

	Table<char *, int> tb2(True);

	l.Add (5);

	tb2.Add ("Trevor", 1);

	tb2.Search (1);

	cout << '\n' << tb2.FoundItem() << '\t' << tb2.FoundKey();

	cout << "\nTable empty and count 0:\t" << TestTab.Empty() << '\t';
	cout << TestTab.Count() << '\n';

	cout << "\nIt count: " << TestTab.ItCnt();

	for (i = 0; i < 50; i++)	{
		TestTab.Add (i, i + 10);
	}

	cout << "\nIt count: " << TestTab.ItCnt();
/**/
	TI = TestTab.Iterator();
	while (!TI.Finished())	{
		cout << "\nKey: " << TestTab.Key (TI);
		cout <<"\tItem: " << TestTab.Item (TI);
		cout << "\tIt count: " << TestTab.ItCnt();
		TI.Forth();
	}

/**
	for (TI = TestTab.Iterator(); !TI.Finished(); TI.Forth())	{
		cout << "\nKey: " << TestTab.Key (TI);
		cout <<"\tItem: " << TestTab.Item (TI);
		cout << "\tIt count: " << TestTab.ItCnt();
	}
/**/

	cout << "\nIt count:" << TestTab.ItCnt() << '\n';

	TestTab.Search (90);
	cout << "\n\nNot found (0): " <<	TestTab.Found();

	TestTab.Search (15);

	cout << "\nFound (1): " << TestTab.Found();

	cout << "\nFound item 5: " << TestTab.FoundItem();

	TestTab.Replace (180, 30);

	TestTab.Search (30);

	cout << "\n\nReplace Found (1): " <<	TestTab.Found();

	cout <<"\nReplaced: " << TestTab.FoundItem() << '\n';

	return 0;
}
