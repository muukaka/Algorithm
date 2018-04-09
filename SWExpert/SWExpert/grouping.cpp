// Problem(?) Grouping(?)

#include <iostream>
#include <vector>
#include <algorithm>// find()

using namespace std;

/*
Time Complexity : O(n^3)
Space Complexity : O(n)
*/

int N; // 관계 갯수, 2 <= N <= 100*1000
int x, y; // Pair, 1 <= x,y <= 100*1000
int ret = 0;// 그룹수
int main()
{
	// input
	cin >> N;
	// 2차원 벡터 초기화 (arr[6][5]) : vector< vector<int> > arr(6, vector<int>(5,0));
	vector< vector<int> > p(N);
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		//p[i].push_back(x);
		//p[i].push_back(y);

		int group = 0;
		vector<int>::iterator findx;
		vector<int>::iterator findy;
		for (int j = 0; j < i; j++)
		{
			findx = find(p[j].begin(), p[j].end(), x);
			findy = find(p[j].begin(), p[j].end(), y);
			if (findx != p[j].end())
			{
				group = 1;
				p[j].push_back(y);
				break;
			}
			else if (findy != p[j].end())
			{
				group = 1;
				p[j].push_back(x);
				break;
			}
		}
		if (group == 0)
		{
			p[ret].push_back(x);
			p[ret].push_back(y);
			ret++;
		}
	}

	// output
	cout << endl;
	cout << ret-1 << endl;

	return 0;
}

// find() - O(n)
// Binary Search - O(log n)
// sort() - O(n log n)