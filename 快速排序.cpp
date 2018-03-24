#include<iostream>
using namespace std;

/*
��������
һ��qsort�������ͣ�
a[left]~a[right]�ڵ���������ģ�
����һ��key��һ�������꣬key��ߵ�������keyС��key�ұߵ�������key��
����ʱ�临�Ӷȣ�
ÿһ�ֶ�Ҫ��a[left]������a[right],Ϊn
�������£�ÿһ�α�keyС��ֵ�ͱ�key���ֵ������ȣ�ÿһ�������������룬��Ҫlog(n)��,ʱ�临�Ӷ�O(nlog(n))
�������£�ÿһ�ֶ��Ǳ�key����keyС��ֵ��ÿһ����������һ����Ҫn�֣�ʱ�临�Ӷ�O(n^n)
�����ռ临�Ӷȣ�
��Ҫ���ڴ濪��Ϊ�ݹ���ò���������O(log(n))�����O(n)
�ġ��Ż���
1.keyֵѡ���һ��Ԫ����Ϊ��׼������ÿ���ȥ��һ����������飬���������O(n^n)
����취����keyֵ���ѡȡ rand()%(left + right) + right
������ȡ�� keyֵȡ (left + right) / 2
2.�����ڴ����������ʱ�ȽϺ��ã�������С��ʱ��ͻ��˻�
����취���������й�С��ʱ�򣬱��磨right-left��== 10��ʹ�ò�������
3.��key��ȵ����ظ�����
����취��ÿһ�������궼����key��ȵ�������key��Χ
*/
void qsort(int *a, int left, int right)
{
	/*�����߽��޴��ڻ�����ұߵĽ��ޣ�˵��ֻʣһ�������������˵û����Ҫ�����������*/
	if (left >= right)
	{
		return;
	}

	int i = left;
	int j = right;
	int key = a[left];

	/*
	�����ڱ���һ��
	*/
	while (i < j)
	{
		/*
		��right������
		*/
		while (i < j && key <= a[j])
		{
			j--;
		}

		a[i] = a[j];

		/*
		��left������
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