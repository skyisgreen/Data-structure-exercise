#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//α�����
int Search(int *a,int n ,int key) 
{
	int low,high,mid;
	low=1;//��λ
	high=n;//ĩλ
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key<a[mid])
		high=mid-1;
		else if(key>a[mid])
		low=mid+1;
		else
		return mid;
		
	 } 
	 return 0;
}
