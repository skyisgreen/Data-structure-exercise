#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[101],n;

void quicksort (int left,int right)
{
	int i,j,t,temp;
	if(left>right)
	return;
	
	temp=a[left];//基准数
	i=left;
	j=right;
	while(i!=j)
	{
		//从右往左，顺序很重要
		while(a[j]>=temp&&i<j)
		j--;
		//从左往右
		while(a[i]<=temp&&i<j)
		i++;
		
		//交换两个数在数组中的位置
		if(i<j)//i和j还没相遇
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		 } 
	 } 
	 
	 //基准归位
	 a[left]=a[i];
	 a[i]=temp;
	 
	 quicksort(left,i-1);//继续处理左边的，递归过程
	 quicksort(i+1,right);
	 return; 
}


int main(int argc, char *argv[]) {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    
    quicksort(1,n);
	
	//输出结果
	for(i=1;i<=n;i++)
	printf("%d",a[i]); 
	getchar();getchar();
	return 0;
}
