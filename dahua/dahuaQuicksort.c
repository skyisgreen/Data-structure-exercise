#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[101],n;

void quicksort (int left,int right)
{
	int i,j,t,temp;
	if(left>right)
	return;
	
	temp=a[left];//��׼��
	i=left;
	j=right;
	while(i!=j)
	{
		//��������˳�����Ҫ
		while(a[j]>=temp&&i<j)
		j--;
		//��������
		while(a[i]<=temp&&i<j)
		i++;
		
		//�����������������е�λ��
		if(i<j)//i��j��û����
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		 } 
	 } 
	 
	 //��׼��λ
	 a[left]=a[i];
	 a[i]=temp;
	 
	 quicksort(left,i-1);//����������ߵģ��ݹ����
	 quicksort(i+1,right);
	 return; 
}


int main(int argc, char *argv[]) {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    
    quicksort(1,n);
	
	//������
	for(i=1;i<=n;i++)
	printf("%d",a[i]); 
	getchar();getchar();
	return 0;
}
