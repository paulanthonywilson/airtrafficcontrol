/*
Test out the EifList class

Paul Wilson

9/4/96
*/

# include "stdatc.h"
# include "eiflist.h"
# include "eiflist.h"


void IC (int Exp, EifList<int> &);
void Dummy (EifList<int> &);
void DummyIt(int Exp, EifIterator it, EifList<int> &TestList);

int main()	{

	EifList<int> TestList (True), TestList2 (True);
	EifIterator TestIt, *TestItptr;

	int d[] = {1, 2, 3, 1, 4, 5, 6, 7, 8, 8, 9, 10, -1}, i;

	for (i = 0; d [i] != -1; i++)	{
		cout << "\n" << d[i];
		TestList.Add (d[i]);
	}

	cout << "\n\nList Test\n";

	cout << "Should be 10\t" << TestList.Count() << "\n";

	TestList.Remove (11);

	cout << "Should be 10\t" << TestList.Count() << "\n";


	TestList.Remove (9);

	cout << "Should be 9\t" << TestList.Count() << "\n";

	TestList.Search (9);

	cout <<"Should be 0\t" << TestList.Found() << "\n";

	TestList.Search (6);

	cout <<"Should be 1:\t" << TestList.Found() << "\n";

	cout << "Should be 6:\t" << TestList.FoundItem() << "\n";

	IC (0, TestList);

	TestItptr = new EifIterator (TestList);

	IC (1, TestList);


	EifIterator TestIt2 = *TestItptr;

	IC (2, TestList);

	TestIt2 = TestIt;

	IC (1, TestList);

	DummyIt (1, *TestItptr, TestList);

	delete TestItptr;
	TestItptr = NULL;

	IC (0, TestList);

	Dummy (TestList);

	IC (0, TestList);

	TestIt = TestList.Iterator();

	IC (1, TestList);

	while (!TestIt.Finished())	{
		cout <<'\n' << TestList.Item (TestIt);
		TestIt.Forth();
	}

	IC (0, TestList);

	TestIt = TestList2.Iterator();

	IC (0, TestList2);

	TestList2.Add (1);

	TestIt.First();

	IC (1, TestList2);

	TestIt.Forth();

	IC (0, TestList2);

	return 0;
}

void IC (int Exp, EifList<int> &TestList)	{
	cout <<'\n' << "It count should be "<< Exp <<":\t" << TestList.ItCnt() << '\n';
}

void Dummy (EifList<int> &TestList)	{

	int ex = TestList.ItCnt();
	EifIterator it1 (TestList), it2, it3;

	ex++;
	IC (ex, TestList);

	it2 = it3;
	IC (ex, TestList);

	it2 = it1;
	ex++;
	IC (ex, TestList);


}

void DummyIt(int Exp, EifIterator it, EifList<int> &TestList)	{

	Exp++;
	IC (Exp, TestList);

	EifList <char *> StrList (True);

	StrList.Add ("Trevor");

}