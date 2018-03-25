/*
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 자연수 N(1 ≤ N ≤ 1,000)이 주어진다.
두 번째 줄에는 덱에 카드가 놓인 순서대로 N개의 카드 이름이 공백으로 구분되어 주어진다.
카드의 이름은 알파벳 대문자와 ‘-’만으로 이루어져 있으며, 길이는 80이하이다.
*/
/*
각 테스트 케이스마다 주어진 덱을 퍼펙트 셔플한 결과를 한 줄에 카드 이름을 공백으로 구분하여 출력한다.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N_MAX 1000
vector<vector<string>> ret;
vector<int> num;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		num.push_back(n);
		string temp;
		vector<string> deck;
		vector<string> result;

		// deck 카드 이름 입력
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			deck.push_back(temp);
		}

		// 부분정답 출력
		for (int j = 0; j < n; j++)
		{
			if (j % 2 == 0)// 0 2 4 8 ... ex) A B C
			{
				result.push_back(deck[j / 2]);
			}
			else// 1 3 5 7 .... ex) D E F
			{
				result.push_back(deck[(n + j) / 2]);
			}
		}
		ret.push_back(result);
	}
	for (int i = 0; i < T; i++)
	{
		cout << "#" << i + 1 << " ";
		int n = num[i];
		for (int j = 0; j < n; j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}