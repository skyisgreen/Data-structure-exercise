#include<stdio.h>



int main()
{ 
    	
	int n;
    scanf("%d",&n);

  for(int w=0;w<n;w++){
  
    int check;
    int x;
    scanf("%d",&x);
    int t=x/100000;//得到十万位
	
	int a=x%100000;
	int b=a/10000; //得到万位
	
	int c=a%10000;
	int d=c/1000;//得到千位 
	
	int e= c%1000;
	int f=e/100;//得到百位
	
	int g=e%100;
	int h=g/10;//得到十位
	
	int i=g%10;//得到个位

	while(n--)
	{
		 
		
		if(t+b+d==f+h+i)
	{
		printf("You are lucky!");
	} 
	else
	{
		printf("Wish you good luck.");
	}
}
	return 0;

}
} 




 

