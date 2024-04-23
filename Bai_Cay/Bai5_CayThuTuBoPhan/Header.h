#include <iostream>
using namespace std;
const int MAX = 100;
struct PriQueue
{
	int list[MAX];
	int count;
};
void init(PriQueue& pq);
bool isEmpty(PriQueue pq);
bool isFull(PriQueue pq);
void insertKey(PriQueue& pq, int key);
void deleteKey(PriQueue& pq);
void deleteKey(PriQueue& pq, int key);
int getFirst(PriQueue pq);
int getParent(int i);
int getLeft(int i);
int getRight(int i);
void shiftDown(PriQueue& pq, int i);
void shiftUp(PriQueue& pq, int i);
void swap(int* x, int* y);

/// <summary>
/// Sap xep theo thu tu uu tien.
/// </summary>
/// <param name="pq">Ham doi.</param>
/// /// <param name="what">0: tu be toi don, 1: tu lon toi be.</param>
PriQueue OrderPriority(PriQueue pq, int what = 0);