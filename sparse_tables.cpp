#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <fstream>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <numeric> 
#include <cmath> 
#include <bitset> 
#include <stack> 
#include <cassert> 
#include <chrono> 
using namespace std;
#define ifthen(x,y,z) (x ? y : z)
#define forn(i, n) for (int i = 0; i < int(n); i++)

/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
//chrono::high_resolution_clock::now()
//auto end = chrono::high_resolution_clock::now();
//chrono::duration<float> dur = end - st;

int MAX_LOG = 20;
int const MAX_N = 1000000;
int log_a[MAX_N];
int get_max(int l, int r, vector<vector<int>> &ST) {
	int length = r - l ;
	int k = log_a[length];
	return max(ST[l][k], ST[r - (1 << k) + 1][k]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	log_a[1] = 0;
	vector<int> a(n );
	for (int i = 2; i <= n; i++)
	{
		log_a[i] = log_a[i / 2] + 1;
	}
	vector<vector<int>> ST(n + 1, vector<int>(MAX_LOG));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ST[i][0] = a[i];
	}
	for (int k = 1; k < MAX_LOG; k++)
	{
		for (int i = 0; i + (1 << (k - 1)) -1 < n; i++)
		{
			ST[i][k] = max(ST[i][k - 1], ST[i + (1 << (k - 1))][k - 1]);
		}
	}
}
