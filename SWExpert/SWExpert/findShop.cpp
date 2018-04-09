// 클래스 연산자 오버로딩

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>//sort()
#include <cmath>// sqrt(), pow()
using namespace std;
/*
Time Complexity : O(nlogn)
Space Complexity : O(n)
*/
int xx, yy;// 0 <= x,y <= 9999
int num;

class Shop
{
public:
	int x, y;
	string name;
	int coupon;
};

bool operator<(const Shop& s1, const Shop& s2)
{
	// 유클리디안 거리
	int s1dst = (int)sqrt(pow(xx - s1.x, 2) + pow(yy - s1.y, 2)) / 100;
	int s2dst = (int)sqrt(pow(xx - s2.x, 2) + pow(yy - s2.y, 2)) / 100;
	// 1. 거리순
	if (s1dst < s2dst)
		return true;
	else if (s1dst > s2dst)
		return false;
	// 2. 쿠폰순
	if (s1.coupon > s2.coupon)
		return true;
	else if (s1.coupon < s2.coupon)
		return false;
	// 3. 이름순
	if (s1.name < s2.name)
		return  true;
	return false;
}

int main()
{
	// Input
	cin >> xx >> yy;
	cin >> num;
	vector<Shop> s(num);
	for (int i = 0; i < num; i++)
	{
		cin >> s[i].x >> s[i].y;
		cin >> s[i].name;
		cin >> s[i].coupon;
	}

	sort(s.begin(), s.end());

	// output
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		cout << s[i].x << " " << s[i].y << " ";
		cout << s[i].name << " ";
		cout << s[i].coupon << endl;
	}

}