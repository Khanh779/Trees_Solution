
#include "header.h"
int main() {
	PriQueue a,b,c;
	init(a); init(b); init(c);

	for (int i = 0; i < 15; i++)
	{
		insertKey(a, i);
	}


	for (int i = 0; i < a.count; i++)
	{
		cout << a.list[i] << " ";
	}

	/*deleteKey(a);
	for (int i = 0; i < a.count; i++)
	{
		cout << a.list[i] << " ";
	}*/

	cout << "\nTu be toi lon:\n";
	b=OrderPriority(a, 0);
	for (int i = 0; i < b.count; i++)
	{
		cout << b.list[i] << " ";
	}

	cout << "\nTu lon toi be:\n";
	c=OrderPriority(a, 1);
	for (int i = 0; i < c.count; i++)
	{
		cout << c.list[i] << " ";
	}
	cout << endl;
	system("pause");
}