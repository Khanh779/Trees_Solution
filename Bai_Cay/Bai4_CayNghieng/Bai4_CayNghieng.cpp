#include "Header.h"
void main()
{
	SkewHeap* sh = new SkewHeap;
	Init2(sh);
	//sh = Insert(sh);
	SkewHeap* sh2 = new SkewHeap;
	Init2(sh2);
	//sh2 = Insert(sh2);
	SkewHeap* temp = new SkewHeap;
	temp = Merge(sh, sh2);
	PrintHeap(temp);


	system("pause");
}