#include <iostream>
//建堆以及堆排序 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int h[101];//用来存放堆的数组
int n;//用来存储堆中元素个数，也就是堆的大小

//交换函数 ，用来交换堆中的两个元素的值 
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
		t=i*2;
		else
		t=i;
		
		//如果它有右儿子，再对右儿子进行讨论
		if(i*2+1<=n)
		{
			//如果右儿子更小，更新较小的结点编号 
			if(h[t]>h[i*2+1])
			t=i*2+1;
			 
		 } 
		 
		 //如果发现最小的结点编号不是自己，说明子结点中有比父结点更小的
		 if(t!=i)
		 {
		 	swap(t,i);
		 	i=t;
		  } 
		  else
		       flag=1;
	 } 
	 return;
  } 











int main(int argc, char** argv) 
{
	
	
	
	return 0;
}
