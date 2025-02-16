#include <stdio.h>
 
int a[500]; //记录人数不超过500的n个人打水时间
 
//快速排序-计算并返回枢轴位置
int split(int low, int high)
{
	a[0] = a[low];
 
	while (low < high)
	{
		while (low < high && a[high] >= a[0])
		{
			high--;
		}
		a[low] = a[high];
 
		while (low < high && a[low] <= a[0])
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = a[0];
	return low;
}
 
//递归快速排序
void Sort(int low, int high)
{
	if (low < high)
	{
        int pr;
		pr = split(low, high);
		Sort(low, pr - 1);
		Sort(pr + 1, high);
	}
}
 
int main() {
	int n, r;	//n个人,r个水龙头
	int i,sum;
	while (scanf("%d %d", &n, &r) != EOF)
	{
		if (n <= 500 && r <= 75 && n >= 0 && r >= 0)
		{
			sum = 0;
			for (i = 1; i <= n; i++)
			{
				scanf("%d", &a[i]);
			}
 
			//水龙头多余或者正好的情况，无需等待花费时间就是打水时间之和
			if (r >= n)
			{
				for (i = 1; i <= n; i++)
				{
					sum += a[i];
				}
			}
			else
			{
				//水龙头不足的情况，每个人花费的时间是排队等待时间+打水时间
				//对打水时间排序，目的是让最快打水的先打水，减少等待时间
				Sort(1, n);
 
				//先计算前r个人无需等待的时间
				for (i = 1; i <= r; i++)
				{
					sum += a[i];
				}
 
				//从r+1个人算每个人花费时间总和=等待时间+打水时间
				for (i = r+1; i <= n; i++)
				{				
					sum = sum + a[i]+a[i-r];
 
					//更新第i个人打水总时间
					a[i] = a[i] + a[i - r];
				}
			}
			printf("%d\n", sum);
		}
	}
 
	return 0;
}