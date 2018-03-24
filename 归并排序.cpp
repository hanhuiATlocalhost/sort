#include<iostream>
using namespace std;
/*
�ȶ��������㷨
��� O(nlog(n)) ƽ��O(nlog(n)) �O(nlog(n))
��Ҫһ���������ʱ���� tempArr����
*/
/*
��sourceArr[left]~sourceArr[mid]��sourceArr[mid + 1]~sourceArr[right]�����������ڵľֲ�����
���ȫ������
�������������ڵ�Ԫ�� ����ķ��뵽tempArr��
�ٽ�tempArr�е�Ԫ��д�ص�sourceArr
*/
void Merge(int *sourceArr, int *tempArr, int left, int mid, int right);

/*
MergeSort(s, t, left, mid);
MergeSort(s, t, mid + 1, right);
Merge(s, t, left, mid, right);
*/
void MergeSort(int *sourceArr, int *tempArr, int left, int right);

/*
�鲢�����Ϊ������һ���Ƿ��Σ�һ��������
*/
void Merge(int *sourceArr, int *tempArr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i != mid + 1 && j != right + 1)
	{
		if (sourceArr[i] > sourceArr[j])
		{
			tempArr[k++] = sourceArr[j++];
		}
		else
		{
			tempArr[k++] = sourceArr[i++];
		}
	}

	while (i != mid + 1)
	{
		tempArr[k++] = sourceArr[i++];
	}

	while (j != right + 1)
	{
		tempArr[k++] = sourceArr[j++];
	}

	for (i = left; i <= right; i++)
	{
		sourceArr[i] = tempArr[i];
	}
}

void MergeSort(int *sourceArr, int *tempArr, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(sourceArr, tempArr, left, mid);
		MergeSort(sourceArr, tempArr, mid + 1, right);
		Merge(sourceArr, tempArr, left, mid, right);
	}
}

/*

int main(int argc, char * argv[])
{
	int a[8] = { 50, 10, 20, 30, 70, 40, 80, 60 };
	int i, b[8];
	MergeSort(a, b, 0, 7);
	for (i = 0; i<8; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

*/