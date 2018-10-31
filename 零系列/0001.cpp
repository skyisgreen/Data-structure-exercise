#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//调转一个数字的顺序：eg:1234->4321 
int main(int argc, char** argv)
 {
	int a;
	int b;
	scanf("%d",&a); 
	while(a>0)
	{
		b*=10;
		b+=a%10;
		a/=10;
	}
	printf("%d",b);
	
	return 0;
}
