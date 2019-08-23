#include<iostream>
using namespace std;

int Count_1(int n)
{
	int count = 0;
	while (n)
	{
		if (n % 10 == 1)
			count++;
		n = n / 10;
	}
	return count;
}
int main()
{
	int num;
	cin >> num;
	int ans = Count_1(num);
	cout << ans << endl;
	system("pause");
	return 0;
}