#include<iostream>
using namespace std;

//参考：https://www.cnblogs.com/MOBIN/p/5374217.html
/*
HeapSort
堆排序:堆排序就是利用了二叉树
升序就用大根堆，因为最大的值在堆顶，然后每一次都会把最大的值放到 有序堆 的最后面，再重新调整堆
反之，降序就用小根堆。

*/
void adjustHeap(int param1, int j, int *inNums);
void HeapSort(int nums, int * inNums);

/*
调整 param1 ~ j 这个区间的堆
这个堆除了 inNums[param1]是无序的 其他都是有序的
*/
void adjustHeap(int param1, int j, int *inNums)
{
	for (int k = param1 * 2 + 1; k < j; k = k * 2 + 1)
	{
		/*
		k + 1 < j :防止inNUms[k+1]越界
		inNums[k] < inNums[k + 1] : 让k指向较大的那一边节点
		*/
		if (k + 1 < j && inNums[k] < inNums[k + 1])
		{
			k++;
		}

		if (inNums[k] > inNums[param1])
		{
			/*
			说明父节点比孩子节点小，交换一下，让无序堆变小
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
			说明父节点比孩子节点都大
			*/
			break;
		}
	}
}

void HeapSort(int nums, int * inNums)
{
	/*
	在构造有序堆时，我们开始只需要扫描一半的元素（n/2-1 ~ 0）即可
	因为只有这些节点有子节点 如果没有子节点 本身就不需要排序
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
