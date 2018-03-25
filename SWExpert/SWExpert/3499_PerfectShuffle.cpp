/*
ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.
�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �ڿ��� N(1 �� N �� 1,000)�� �־�����.
�� ��° �ٿ��� ���� ī�尡 ���� ������� N���� ī�� �̸��� �������� ���еǾ� �־�����.
ī���� �̸��� ���ĺ� �빮�ڿ� ��-�������� �̷���� ������, ���̴� 80�����̴�.
*/
/*
�� �׽�Ʈ ���̽����� �־��� ���� ����Ʈ ������ ����� �� �ٿ� ī�� �̸��� �������� �����Ͽ� ����Ѵ�.
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

		// deck ī�� �̸� �Է�
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			deck.push_back(temp);
		}

		// �κ����� ���
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