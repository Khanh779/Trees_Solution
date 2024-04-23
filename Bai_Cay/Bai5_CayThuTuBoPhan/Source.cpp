#include "Header.h"

void init(PriQueue& pq)
{
	pq.count = 0;
}
bool isEmpty(PriQueue pq)
{
	return pq.count == 0;
}
bool isFull(PriQueue pq)
{
	return pq.count == MAX;
}
void insertKey(PriQueue& pq, int key)
{
	if (pq.count ==MAX) {
		return;
	}
	int i = pq.count;
	pq.list[i] = key;
	shiftUp(pq, i);	
	pq.count++;
}

int getFirst(PriQueue pq)//top
{
	if (pq.count == 0)
	{
		cout << "khong co phan tu";
		return 0;
	}
	return pq.list[0];
}
int getParent(int i)
{
	return (i - 1) / 2;
}
int getLeft(int i)
{
	return (2 * i + 1);
}
int getRight(int i)
{
	return (2 * i + 2);
}
void shiftDown(PriQueue& pq, int i)
{
	//lấy con trái và con phải của nút tại vị trí i
	int left = getLeft(i);
	int right = getRight(i);
	int smallest = i;
	//so sánh pqlist[i] với trái và phải để tìm giá trị nhỏ nhất
		if (left < pq.count && pq.list[left] < pq.list[i])
		{
			smallest = left;
		}
	if (right < pq.count && pq.list[right] <
		pq.list[smallest])
	{
		smallest = right;
	}
	if (smallest != i)
	{
		swap(pq.list[i], pq.list[smallest]);
		shiftDown(pq, smallest);
	}
}
void shiftUp(PriQueue& pq, int  i) {
	if (pq.list[getParent(i)] > pq.list[i])
	{
		swap(pq.list[i], pq.list[getParent(i)]);
		shiftUp(pq, getParent(i));
	}
}
void deleteKey(PriQueue& pq)
{
	int key;
	cout << "\nNhap gia tri can xoa khoi hang doi: "; cin >> key;
	deleteKey(pq, key);
	cout << "Da xoa phan tu " << key<<"\n";
}
void deleteKey(PriQueue& pq, int key) {
	int index = -1;
	for (int i = 0; i < pq.count; i++) {
		if (pq.list[i] == key) {
			index = i;
			break;
		}
	}
	pq.count--;
	if (index == -1)
		cout << " ham da dc xoa" << endl;

}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int findMinOfLoc(PriQueue a, int start, int fromX)
{
	int temp = a.list[start], loc = start;
	for (int i = start; i < a.count; i++)
	{
		if (a.list[i] < temp) {
			temp = a.list[i];
			loc = i;
		}
	}
	return loc;
}

int findMaxOfLoc(PriQueue a, int start, int fromX)
{
	int temp = a.list[start], loc = start;
	for (int i = start; i < a.count; i++)
	{
		if (a.list[i] > temp) {
			temp = a.list[i];
			loc = i;
		}
	}
	return loc;
}

PriQueue OrderPriority(PriQueue pq, int what)
{
	PriQueue a; init(a);
	a.count = pq.count;
	for (int i = 0; i < a.count; i++)
	{
		a.list[i] = pq.list[i];
	}


	int temp = a.list[0], start = 0, loc=0;
	for (int i = start; i < a.count; i++)
	{
		if (what == 0)
		{
			loc = findMinOfLoc(a, i, temp);
			temp = a.list[loc];
		}
		if (what==1) {
			loc = findMaxOfLoc(a, i, temp);
			temp = a.list[loc];
		}
		
		swap(a.list[i], a.list[loc]);
		start++;
	}
	return a;
}
