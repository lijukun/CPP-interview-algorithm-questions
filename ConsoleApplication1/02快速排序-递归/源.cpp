#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &vec, int m, int n)
{
	int temp = vec[m];
	vec[m] = vec[n];
	vec[n] = temp;
}
int Partition(vector<int>& vec, int low, int high)
{
	int pivotkey = vec[low];
	while (low<high)
	{
		while (low<high&&vec[high]>=pivotkey)
			high--;
		swap(vec, low, high);
		while (low < high&&vec[low] <= pivotkey)
			low++;
		swap(vec, low, high);
	}
	return low;
}
void QSort(vector<int>& vec, int low, int high)
{
	if (low >= high)
		return;
	else
	{
		int pivot = Partition(vec, low, high);
		QSort(vec, low, pivot - 1);
		QSort(vec, pivot + 1, high);
	}
}

int main()
{
	vector<int> a = { 1,2,1,3,1,7,5,2,3,86,4 };
	QSort(a, 0, a.size() - 1);

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}