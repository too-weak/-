/*
无输入
输出：
19 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 第一问
19 1 2 3 4 5 6 7 8 9 11 12 13 14 15 16 17 18 第二问
1 2 3 4 5 6 7 8 9 第三问
9 最终表长度
*/
#include <iostream>
using namespace std;
const int MaxNumber=1000000;
int DeleteMin(int a[],int& n)
{

	int minPos=-1;
	int minValue=MaxNumber;
	for(int i=0;i<n;i++) // 找最小值 以及 最小值得位置
	{
		if(minValue>a[i])
		{
			minValue=a[i];
			minPos=i;
		}
	}
	a[minPos]=a[n-1]; // 用最后一个元素代替最小值
	n--;
	return minValue; // 返回最小值得数值
}
void DeleteAll(int a[],int& n,int x)
{
	int i=0;
	while(i<n)
	{
		if(a[i]==x) // 找到值为x的元素，删除
		{
			for(int j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			n--; // 删除了元素，表长度减少1
		}
		else // 没有找到，将i继续向后移动
		{
			i++;
		}

	}
}
void DeleteOrder(int a[],int& n,int s,int t)
{
	int i=0;
	while(i<n)
	{
		if(a[i]>=s && a[i]<=t) // 寻找值在 s 和 t 之间的元素
		{
			for(int j=i;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			n--;
		}
		else
		{
			i++;
		}
	}
}
int main()
{
	int a[20];
	int length=20;
	for(int i=0;i<20;i++)
	{
		a[i]=i;
	}
	DeleteMin(a,length);
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	DeleteAll(a,length,10);
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	DeleteOrder(a,length,10,20);
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<length<<endl;
	return 0;
}
