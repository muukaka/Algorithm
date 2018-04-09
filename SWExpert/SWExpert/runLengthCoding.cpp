// Run Length Encoding

#include <iostream>
#include <string>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(n)
*/

int main()
{
	int T; // 1 <= T <= 100
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		// ют╥б
		string s; // 1 <= s <= 200
		cin >> s;

		int len = s.length();
		//cout << len << endl;
		for (int j = 0; j < len; j++)
		{
			int count = 1;
			char start = s[j];
			while (j + 1 < len && s[j] == s[j + 1])
			{
				count++;
				j++;
			}
			cout << count << start;
		}
	}
	cout << endl;
	return 0;
}