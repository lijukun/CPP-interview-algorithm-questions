#include<iostream>
using namespace std;
int f(int m, int n)
{
	if (m == 0 || n == 0)return 0;
	int k;
	while (m%n)
	{
		k = m%n;
		m = n;
		n = k;
	}
	return n;
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout << f(m, n) << endl;
	system("pause");
	return 0;
}