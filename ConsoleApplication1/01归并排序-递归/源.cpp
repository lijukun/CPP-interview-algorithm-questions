#include<iostream>
#include<vector>
using namespace std;

/* 归并排序的核心：归并（假设数组vec里L到M是有序的，M到R是有序的，怎么归并成一个有序数组）*/
void Merge(vector<int> &vec, int L, int M, int R)//分治递归时，vec一直是这个，变化的只是下标L、M、R
{
	int LEFT_SIZE = M-L+1;//左边部分的长度，包括M
	int RIGHT_SIZE = R - M;//右边部分的长度，不包括M

	//新建两个数组，并把vec里L到M部分和M到R部分从原数组里拿出来，单独放进两个数组
	vector<int> left(LEFT_SIZE);
	vector<int> right(RIGHT_SIZE);
	for (int i = L; i <= M; i++)
	{
		left[i-L] = vec[i];
	}
	for (int i = M+1; i <=R; i++)
	{
		right[i - (M+1)] = vec[i];
	}
	
	//归并这两个数组
	int i = 0; int j = 0; int k = L;
	while (i < LEFT_SIZE && j < RIGHT_SIZE)//依次比较left数组和right数组元素大小，小的放进原数组L到R区域靠前位置
	{
		if (left[i] < right[j])
		{
			vec[k] = left[i];
			i++;
			k++;
		}
		else
		{
			vec[k] = right[j];
			j++;
			k++;
		}
	}
	while (i<LEFT_SIZE)//right数组的都放完了，left数组还有元素没放回vec，则不用再比较了，直接都放回vec即可
	{
		vec[k] = left[i];
		i++;
		k++;
	}
	while (j<RIGHT_SIZE)//left数组的都放完了，right数组还有元素没放回vec，也不用在比较了，直接放回
	{
		vec[k] = right[j];
		j++;
		k++;
	}

}
/* 前面归并的前提是 L到M、M到R段内元素是有序的，因此用分治思想，迭代直至满足这个条件*/
void MSort(vector<int> &vec, int L, int R)//
{
	if (L == R)
		return;
	else
	{
		int M = (L + R) / 2;
		//一直细分到left和right都只有一个元素时，才会开始执行Merge
		MSort(vec, L, M);//包含vec[M]
		MSort(vec, M+1, R);    //不包含vec[M]
		Merge(vec, L, M, R); //Merge里是把M划到left段的，因此这里要一致
	}
	
}

int main()
{
	vector<int> arr = { 3,6,1,9,5,2,7 };

	MSort(arr, 0, 6);
	//打印
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	

	system("pause");
	return 0;
}