#include<iostream>
using namespace std;

//�ο���https://www.cnblogs.com/MOBIN/p/5374217.html
/*
HeapSort
������:��������������˶�����
������ô���ѣ���Ϊ����ֵ�ڶѶ���Ȼ��ÿһ�ζ��������ֵ�ŵ� ����� ������棬�����µ�����
��֮���������С���ѡ�

*/
void adjustHeap(int param1, int j, int *inNums);
void HeapSort(int nums, int * inNums);

/*
���� param1 ~ j �������Ķ�
����ѳ��� inNums[param1]������� �������������
*/
void adjustHeap(int param1, int j, int *inNums)
{
	for (int k = param1 * 2 + 1; k < j; k = k * 2 + 1)
	{
		/*
		k + 1 < j :��ֹinNUms[k+1]Խ��
		inNums[k] < inNums[k + 1] : ��kָ��ϴ����һ�߽ڵ�
		*/
		if (k + 1 < j && inNums[k] < inNums[k + 1])
		{
			k++;
		}

		if (inNums[k] > inNums[param1])
		{
			/*
			˵�����ڵ�Ⱥ��ӽڵ�С������һ�£�������ѱ�С
			param1 = k
			*/
			int temp = inNums[param1];
			inNums[param1] = inNums[k];
			inNums[k] = temp;

			param1 = k;
		}
		else
		{
			/*
			˵�����ڵ�Ⱥ��ӽڵ㶼��
			*/
			break;
		}
	}
}

void HeapSort(int nums, int * inNums)
{
	/*
	�ڹ��������ʱ�����ǿ�ʼֻ��Ҫɨ��һ���Ԫ�أ�n/2-1 ~ 0������
	��Ϊֻ����Щ�ڵ����ӽڵ� ���û���ӽڵ� ����Ͳ���Ҫ����
	*/
	for (int i = nums / 2 - 1; i >= 0; i--)
	{
		adjustHeap(i, nums, inNums);
	}

	for (int j = nums - 1; j > 0; j--)
	{
		int temp = inNums[0];
		inNums[0] = inNums[j];
		inNums[j] = temp;

		adjustHeap(0, j, inNums);
	}
}


int main()
{
	int data[] = { 6,5,8,4,7,9,1,3,2 };
	int len = sizeof(data) / sizeof(int);
	HeapSort(len, data);

	for (int i = 0; i<8; i++)
		printf("%d ", data[i]);
	printf("\n");
	return 0;
}
