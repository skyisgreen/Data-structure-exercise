#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x,h,w;
		scanf("%d %d %d ",&x,&h,&w);
		if(x==1)
		{
			if(h<130)
			{
				printf("duo chi yu!") ;
			}else if(h==130)
			{
				printf("wan mei!") ;
			}
			else{
					printf("ni li hai!") ;
			}
			
			if(w<27)
			{
				printf("duo chi rou!") ;
			}else if(w==27)
			{
				printf("wan mei!") ;
			}
			else{
					printf("shao chi rou!") ;
			}
		}
		else 
	
		{
			if(h<129)
			{
				printf("duo chi yu!") ;
			}else if(h==129)
			{
				printf("wan mei!") ;
			}
			else{
					printf("ni li hai!") ;
			}
			
			if(w<25)
			{
				printf("duo chi rou!") ;
			}else if(w==25)
			{
				printf("wan mei!") ;
			}
			else{
					printf("shao chi rou!") ;
			}
		}
	}
	
	return 0;
}
