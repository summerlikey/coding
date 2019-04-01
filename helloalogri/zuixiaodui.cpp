//复杂度logN；可以用最小堆进行堆排序，和快速排序速度一样，复杂度O(NlogN)
#include<stdio.h>
using namespace std;
int h[100];
int n;
void swap(int i,int j)
{
	int x=0;
	x=h[i];
	h[i]=h[j];
	h[j]=x;
	return;
}
void siftdown(int i)//传入一个向下调整的节点编号，这里传入1，即从堆顶开始向下调整
{
	int t,flag;
	flag=0;
	while(i*2<=n&&flag==0)
	{
		//判断与左节点的关系，并用t记录较小的节点编号
		if(h[i]>h[i*2])
			t=i*2;
		else
		        t=i;
		//节点可能有右儿子，再与右儿子比较
		if(i*2+1<=n)
		{
		        if(h[t]>h[i*2+1])
			        t=i*2+1;
		}
		//如果发现最小的节点编号不是自己说明有子节点比父节点更小
		if(t!=i)
		{
		        swap(t,i);//交换，
			i=t;//更新i为刚才与他交换的儿子的节点编号，便于接下来继续向下调整
		}
		else
		        flag=1;//说明当前的父节点已经比两个子节点都要小了，不再调整
	}
	return;
}
//向上调整
void siftup(int i)//传入一个需要向上调整的节点编号i
{
	int flag=0;//用来标记是否需要继续向上调整
	if(i==1)
		return;//如果是堆顶，就返回，不需要调整了
	while(i!=1&&flag==0)
	{
		//判断是否比父节点小
		if(h[i]<h[i/2])
			swap(i,i/2);//交换它和它爸爸的位置
		else
			flag=1;//不需要调整了
		i=i/2;//继续下一个调整
	}
}
		
//删除最大 的元素
int deletemax()
{
	int t;
	t=h[1];//用一个临时变量记录堆顶点的值
	h[1]=h[n];//将堆的最后一个点赋值到堆顶
	n--;//堆的元素减少1
	siftdown(1);//向下调整
	return t;//返回最大值
}
//建立堆
void creat()
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		siftdown(i);
	}
}
int main()
{
	int i,num;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
		scanf("%d",&h[i]);
	n=num;
	//建堆
	creat();
	for(i=1;i<=num;i++)
		printf("%d ",deletemax());
	return 0;
}
/*
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
 */


