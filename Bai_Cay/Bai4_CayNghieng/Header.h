#include <iostream>
using namespace std;
struct SkewHeap
{
	int key;
	SkewHeap* left;
	SkewHeap* right;
};
void Init(SkewHeap* sh);
SkewHeap* Merge(SkewHeap* h1, SkewHeap* h2);
SkewHeap* Insert(SkewHeap* root);
SkewHeap* DeleteMax(SkewHeap* root);
void PreOrder(SkewHeap* root);
void InOrder(SkewHeap* root);
void PostOrder(SkewHeap* root);
void PrintHeap(SkewHeap* root);

void Init2(SkewHeap* sh);
SkewHeap* Decreasekey(SkewHeap* s, SkewHeap* p, int k);