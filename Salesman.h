#include <iostream>
#include "Graph.h"
using namespace std;
const int maxn = 20;
int s, min, c;
bool found = false;
int m[maxn]; //òåêóùèé ïóòü
int minm[maxn]; //ìèíèìàëüíûé ïóòü

void Result(int n)
{
	if (found)
	{
		cout << endl;
		cout << "Âåñ ìèíèìàëüíîãî ïóòè: " << min << endl;
		cout << "Ïóòü: ";
		int c = 1;
		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while ((j < n) && (minm[j] != c)) j++;
			cout << j + 1 << "->";
			c++;
		}
		cout << minm[0] << endl;
	}
	else cout << "Ïóòü íå íàéäåí";
}
void Salesman(int x, int n)
{
	if ((c == n) &&
		(matr[x][0] != 0) &&
		(s + matr[x][0] < min))
	{
		found = true;
		min = s + matr[x][0];
		for (int i = 0; i < n; i++) minm[i] = m[i];
	}
	else
	{
		for (int i = 0; i < n; i++)
			if ((i != x) && (matr[x][i] != 0) && (m[i] == 0) && (s + matr[x][i] < min))
			{
				s += matr[x][i];
				c++;
				m[i] = c;
				Salesman(i, n);
				m[i] = 0;
				c--;
				s -= matr[x][i];
			}
	}
}
void Start(int q, int n)
{
	s = 0;
	found = 0;
	min = 32767;
	for (int i = 0; i < n; i++) m[i] = 0;
	c = 1;
	m[q] = c;
	Salesman(q, n);
}
