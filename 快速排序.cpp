#include<iostream>
using namespace std;

/*
快速排序：
一、qsort函数解释：
a[left]~a[right]内的数是无序的，
设置一个key，一轮排序完，key左边的数都比key小，key右边的数都比key大
二、时间复杂度：
每一轮都要从a[left]遍历到a[right],为n
最佳情况下，每一次比key小的值和比key大的值数量相等，每一轮数据量都减半，需要log(n)轮,时间复杂度O(nlog(n))
最差情况下，每一轮都是比key大或比key小的值，每一轮数据量减一，需要n轮，时间复杂度O(n^n)
三、空间复杂度：
主要的内存开销为递归调用层数，最优O(log(n))，最差O(n)
四、优化：
1.key值选择第一个元素作为基准，如果用快排去排一个有序的数组，会出现最坏情况O(n^n)
解决办法：①key值随机选取 rand()%(left + right) + right
②三分取中 key值取 (left + right) / 2
2.快排在处理大量数据时比较好用，数据量小的时候就会退化
解决办法：待排序列够小的时候，比如（right-left）== 10，使用插入排序
3.和key相等的数重复排序
解决办法：每一轮排序完都将与key相等的数聚在key周围
*/
void qsort(int *a, int left, int right)
{
	/*如果左边界限大于或等于右边的界限，说明只剩一个数字无序或者说没有需要整理的数字了*/
	if (left >= right)
	{
		return;
	}

	int i = left;
	int j = right;
	int key = a[left];

	/*
	在组内遍历一遍
	*/
	while (i < j)
	{
		/*
		将right向左移
		*/
		while (i < j && key <= a[j])
		{
			j--;
		}

		a[i] = a[j];

		/*
		将left向右移
		*/
		while (i < j && key >= a[i])
		{
			i++;
		}

		a[j] = a[i];
	}

	a[i] = key;
	qsort(a, left, i - 1);
	qsort(a, i + 1, right);
}