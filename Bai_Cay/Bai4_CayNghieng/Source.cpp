#include "Header.h"
void Init(SkewHeap* sh)
{
	sh->key = 0;
	sh->left = NULL;
	sh->right = NULL;
}
SkewHeap* Merge(SkewHeap* h1, SkewHeap* h2)
{
	SkewHeap* temp = new SkewHeap;
	if (h1 == NULL)
		return h2;
	else if (h2 == NULL)
		return h1;
	else
	{
		if (h1->key < h2->key)
		{
			temp = h1;
			h1 = h2;
			h2 = temp;
		}
		temp = h1->left;
		h1->left = h1->right;
		h1->right = temp;
		h1->left = Merge(h2, h1->left);
	}
	return h1;
}
SkewHeap* Insert(SkewHeap* root)
{
	int value;
	cout << "Nhap gia tri can chen:";
	cin >> value;
	SkewHeap* temp = new SkewHeap;
	Init(temp);
	temp->key = value;
	root = Merge(root, temp);
	return root;
}
SkewHeap* DeleteMax(SkewHeap* root)
{
	if (root == NULL)
	{
		cout << "Skew Heap rong!";
		return NULL;
	}
	SkewHeap* temp1;
	SkewHeap* temp2;
	temp1 = root->left;
	temp2 = root->right;
	temp1 = Merge(temp1, temp2);
	return temp1;
}

void PreOrder(SkewHeap* root)
{
	if (root == NULL)
		return;
	cout << root->key << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(SkewHeap* root)
{
	if (root == NULL)
		return;
	PreOrder(root->left);
	cout << root->key << " ";
	PreOrder(root->right);
}

void PostOrder(SkewHeap* root)
{
	if (root == NULL)
		return;
	PreOrder(root->left);
	PreOrder(root->right);
	cout << root->key << " ";
}

void PrintHeap(SkewHeap* root)
{
	PreOrder(root);
}

void insert2(SkewHeap* sh, int x)
{
	SkewHeap* temp = new SkewHeap;
	Init(temp);
	temp->key = x;
	sh = Merge(sh, temp);
}

void Init2(SkewHeap* sh)
{
	Init(sh);
	int x=-1;
	while (x != 0) {
		cout << "Nhap gia tri cho phan tu: "; cin >> x;
		insert2(sh, x);
	};

}

SkewHeap* Decreasekey(SkewHeap* s, SkewHeap* p, int k)
{
	if (s == NULL) return s;
	if (s == p && s->key > k) s->key= k;
	Decreasekey(s->left,p,k);
	Decreasekey(s->right,p,k);

	return s;
}
