#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,j,len;
	char f;
	char str[32289];
	scanf("%d %c\n",&n,&f);
	gets(str);//�ӱ�׼�����豸���ַ�����������������޶�ȡ��
	//�����ж����ޣ��Իس�������ȡ�����Գ���ԱӦ��ȷ��buffer�Ŀռ��㹻���Ա���ִ�ж�����ʱ�����������
	
	len = strlen(str);
	if(n>=len)
	{
		for(i=0;i<n-len;i++)
		{
			putchar(f);
		}
		
		for(j=0;str[j]!='\0';j++)//str[j]!='\0'��ʾ�ַ������� 
		{
			printf("%c",str[j]);
		}
	}
	else{
		for(i=len-n;str[i]!='\0';i++)
		{
				printf("%c",str[i]);
		}
	}
	return 0;
}
