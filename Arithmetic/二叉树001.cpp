#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int h[101];//用来存放堆的数组
int n;//用来存储堆中元素个数，也就是堆的大小

//交换函数 ，用来交换堆中怕 
void swap(int x ,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return;
 } 
 
 //向下调整函数
 void siftdown (int i)//传入一个需要向下调整的结点编号i，这里传入1；即从堆的顶点开始
 //向下调整 
 {
 	int t,flag=0;//flag用来标记是否需要继续向下调整
	//当i结点有儿子（其实是有左儿子）并且有需要继续调整的时候循环就执行
	while(i*2<=n&&flag==0)
	{
		//先判断和左儿子的关系，并用t记录值较小的结点编号
		if(h[i]>h[i*2])
		{
			
		}
	 } 
  } 











int main(int argc, char** argv) 
{
	
	
	
	return 0;
}
