#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>

void swap(int *a, int *b); //交換a b 
void random(int *num, int len);//隨機 
void democolor(int *num, int len, int *color, int spec);//num字串, len長度, color字串顏色字串 0黑 15白, spec特別數字沒有打-1 
void printradixbukkit(int *num, int *temp, int len);
//void mergetext(int *num, int left, int right, int i, int j);
void printcounttable(int *count, int add);


void quicksort(int *num,int len, int left, int right);//快速排序 
void bubblesort(int *num,int len);//泡沫排序傳入數列,長度 
void selectionsort(int *num, int len);//selectionsort排序 
void insertionsort(int *num, int len);
void radixSort(int *num, int len);
void merge(int *num, int left, int right);
void mergesort(int *num, int left, int right);
void countingsort(int *num, int len);

int main()
{
	int gd=9, gm=2;

	int stnum[13],num[13],len=13;
	int i,type,quit=0;
	int *color=(int*)malloc(sizeof(int)*len);
	for(i=0; i<len; i++)
	{
		color[i]=15;
	}
	
	random(stnum, len);
	while(quit==0)
	{	
		
		for(i=0;i<len;i++)
		{
			num[i]=stnum[i];
			printf("%3d ", num[i]);
		}
		printf("\n");
		printf("輸入要的模式:\n1.Counting Sort\n2.Selection Sort\n3.Insertion Sort\n4.Bubble Sort\n5.Quick Sort\n6.Merge Sort\n7.Radix Sort\n8.重新生成亂數\n9.離開\n");
		scanf("%d",&type);
		initgraph(&gd,&gm,"c:\\tc");//開啟視窗
		
		switch(type)
		{
			case 1:
			{
				countingsort(num, len);
			}break;
			case 2:
			{
				selectionsort(num, len);
			}break;
			case 3:
			{
				insertionsort(num, len);
			}break;
			case 4:
			{
				bubblesort(num, len);
			}break;
			case 5:
			{
				quicksort(num, len, 0, len-1);
			}break;
			case 6:
			{
				mergesort(num, 0, len-1);
			}break;	
			case 7:
			{
				radixSort(num, len);
			}break;	
			case 8:
			{
				random(stnum, len);
			}break;	
			case 9:
			{
				quit=1;
			}break;				
		}
		democolor(num, len, color, -1);
		delay(1500);
		closegraph();//關閉視窗 
	}
}

void bubblesort(int *num, int len)
{
	int i,j,t,*color,k;
	color=(int*)malloc(sizeof(int)*len);
	for(i=0;i<len-1;i++)
	{ 
		for(j=0;j<len-i-1;j++)
			if(num[j]>num[j+1])
			{				
				for(k=0; k<len; k++)
				{
					if(k==j||k==j+1)
					{
						color[k]=10;
					}
					else if(k>len-i-1)
					{
						color[k]=14;
					}
					else
					{
						color[k]=15;
					}					
				}
				democolor(num, len, color, -1);
				swap(&num[j],&num[j+1]);
			}
	}
	
}

void quicksort(int *num,int len, int left, int right )
{
	int pivot,i,j,k;
	int *color=(int*)malloc(sizeof(int)*len);
	if(left<right)
	{
		i=left+1;
		j=right;
		pivot=num[left];//設定基準 
    	while (1)
    	{
	        while (i <= right)
	        {
	            if (num[i] > pivot)
	            {
	                break;
	            }
	
	            i = i + 1;
	        }
	
	        while (j > left)
	        {
	            if (num[j] < pivot)
	            {
	                break;
	            }
	            j = j - 1;
	        }
	
	        if (i > j) 
			{
				 break; 
			}
			//demo(num, len, i, j, -1, num[left]);
			for(k=0;k<len;k++)//調顏色 
			{
				if(k==i||k==j)//要交換的 綠色 
				{
					color[k]=10;
				}
				else if(k>=left&&k<=right)
				{
					color[k]=14;//變動範圍 黃色 
				}
				else
				{
					color[k]=15;//其他白色 
				}
			}
			democolor(num, len, color, pivot);
			swap(&num[i], &num[j]);
    	}
		if(left!=j)
		{
    		for(k=0;k<len;k++)//調顏色 
				{
					if(k==left||k==j)
					{
						color[k]=8;// 
					}
					else if(k>=left&&k<=right)
					{
						color[k]=14;//變動範圍 黃色 
					}
					else
					{
						color[k]=15;//其他白色 
					}
				}
			democolor(num, len, color, pivot);
		 	swap(&num[left], &num[j]);
		}
   		quicksort(num, len, left, j - 1);
   		quicksort(num, len, j + 1, right);
	}
}

void selectionsort(int *num, int len)
{
	int i, j, min_index,k;
	int *color=(int*)malloc(sizeof(int)*len);
    for (i=0;i<len;i++) // N改為N-1更精準
    {
        // 從尚未排序的數字當中，找出最小的數字。
        // （它也是全部數字當中第i小的數字。）
        min_index = i;
        for(k=0; k<len; k++)
        {
        	if(k==min_index)
        	{
        		color[k]=6;
			}
			else if(k<i)
			{
				color[k]=14;
			}
			else
			{
				color[k]=15;
			}
		}
		democolor(num, len, color, num[min_index]);
		
        for (j=i+1;j<len;j++)
        {

            //demo(num, len, j, -1, -1, num[min_index]);
        	for(k=0; k<len; k++)
       	 	{
        		if(k==min_index)
        		{
        			color[k]=6;
				}
				else if(k==j)
				{
					color[k]=12;
				}
				else if(k<i)
				{
					color[k]=14;
				}
				else 
				{
					color[k]=15;
				}
			} 
			democolor(num, len, color, num[min_index]);
			if (num[j] < num[min_index])
                min_index = j;

		}
               
        for(k=0; k<len; k++)
        {
        	if(k==i||k==min_index)
        	{
        		color[k]=10;
			}
			else if(k<i)
			{
				color[k]=14;
			}
			else
			{
				color[k]=15;
			}
		}
		democolor(num, len, color, num[min_index]);
		swap(&num[i], &num[min_index]);// 把第i小的數字，放在第i個位置。
    }
}

void insertionsort(int *num, int len)
{
	int i, j, pivot,k;
	int *color=(int*)malloc(sizeof(int)*len);
    for(i=1;i<len;i++)
    {
        pivot = num[i];
        for(j=i-1;j>=0;j--)
        {
            if(pivot < num[j])
            {
                num[j+1] = num[j];  // 先行往右挪              
        	}
            else
                break;

        	for(k=0; k<len; k++)
			{
        		if(k==j)
        		{
        			color[k]=0;
				}
				else if(k<=i)
				{
					color[k]=14;
				}
				else
				{
					color[k]=15;
				}
			}
			democolor(num, len, color, pivot);
 		}
        num[j+1] = pivot; // 插入

       	for(k=0; k<len; k++)
		{
        	if(k==j+1)
        	{
        		color[k]=10;
			}
			else if(k<=i)
			{
				color[k]=14;
			}
			else
			{
				color[k]=15;
			}
		}
		democolor(num, len, color, pivot);
    }
}

void radixSort(int *num, int len) 
{
    int temp[13][13] = {0}; 
    int order[13] = {0}; 
    int i,j,k;
    int *color=(int*)malloc(sizeof(int)*len);
    
    int n = 1, flag = 1;
    while(flag) 
	{         
        flag = 0;
        for(i = 0; i < 13; i++) 
		{ 
            int lsd = ((num[i] / n) % 10); 
            temp[lsd][order[lsd]] = num[i]; 
            order[lsd]++; 
            printradixbukkit(num, &temp[0][0], len);
        } 
        
        // 重新排列
        k = 0;
        for(i = 0; i < 13; i++) 
		{ 
            if(order[i] != 0)  
			{
                for(j = 0; j < order[i]; j++, k++) 
				{ 
                    num[k] = temp[i][j];
					if(num[k]/n>=10)
					{
						flag = 1;
					} 
                    temp[i][j]=0;
                } 
            }
            order[i] = 0; 
        } 
        for(i=0; i<len; i++)
        {
        	color[i]=15;
		}
		democolor(num, len, color, -1);
        n = n*10; 
    }     
}

void mergesort(int *num, int left, int right)
{
    int mid = (left+right)/2;
    
    if(left<right)
    {
        mergesort(num, left, mid);
        mergesort(num, mid+1, right);
        merge(num, left, right);
    }
}

void merge(int *num, int left, int right)//鎖死13 
{
	int tmp[13];
    int i, j, k, c, t;
    int mid = (left + right) / 2;
    int color[13],allin[13];

    for(c=0; c<13; c++)
    {
    	if(c<=right && c>=left)
    	{
    		allin[c] = 0;
		}
		else
		{
    		allin[c] = num[c];
    	}
	}
	
    for (k=0,i=left,j= mid+1; i<= mid||j<=right; k++)//k計數器 
    {
    	t = k+left;
    	for(c = 0; c<13; c++)
    	{
    		if(c>=left && c<=t)
    		{
    			color[c] = 14;
			}
			else if (c>t && c<=right)
			{
				color[c] = 10;
			}
			else
			{
				color[c] = 15;
			}
		}
		//democolor(allin, 13, color, -1);
    	//mergetext(num, left, right, i, j);
    	
        if(i>mid)//分辨哪邊要進去陣列 
        {       
            tmp[k] = num[j];
            allin[t] = num[j];	
			j++;
    	}
        else if(j>right)
        {
            tmp[k] = num[i];
            allin[t] = num[i];
            i++;
		}
        else if(num[i]<num[j])
		{
            tmp[k] = num[i];
            allin[t] = num[i];
            i++;
		}
        else
		{
            tmp[k] = num[j];
            allin[t] = num[j];
        	j++;
    	}
    	
    	democolor(allin, 13, color, -1);
    	//mergetext(num, left, right, i, j);
    }

    for(i=left,k=0; i<=right; i++,k++)
        num[i] = tmp[k];
}

void countingsort(int *num, int len)
{
    // 歸類並標記
    int count[101] = {0}, i, k;
    for (i=0; i<len; i++)
    {
    	count[num[i]]++;
    	printcounttable(count, num[i]);
	} 
 
    // 計數陣列的索引值大小順序，正是元素大小順序。
    for (i=0, k=0; k<len; i++)
    {
    	while (count[i]--)
        {
        	num[k] = i;
        	k++;
		}
	}            
}

void printcounttable(int *count, int add)
{
	int i,j;
	char tnum[]={"[00]"};
	char hundred[]={"[100]"};
	char dnum[4];
	
	for(i=0 ; i<10; i++)
	{
		for(j=0; j<10;j++)
		{
			tnum[1]=i+48;
			tnum[2]=j+48;
			itoa(count[10*i+j], dnum, 10);
			if(10*i+j == add)
			{
				setcolor(10);
			}
			else if (count[10*i+j] != 0)
			{
				setcolor(12);
			}
			else
			{
				setcolor(15);
			}
			outtextxy(j*40, i*40, tnum);
			outtextxy(j*40, 15+i*40,dnum);
		}
	}
	
	itoa(count[100], dnum, 10);
	if(100 == add)
	{
		setcolor(10);
	}
	else if (count[100] != 0)
	{
		setcolor(12);
	}
	else
	{
		setcolor(15);
	}
	outtextxy(200, 400, hundred);
	outtextxy(200, 15+400, dnum);
	
	delay(500);
}

void democolor(int *num, int len, int *color, int spec)//顯示a,b位置互換 
{
	cleardevice();//清除畫面 
	int i;
	char dnum[4];
	if(spec>=0)
	{
		itoa(spec, dnum, 10);//整數轉字串 
		setfillstyle(1,6);
		setcolor(6);
		outtextxy(420,450,dnum);//輸出文字 
		bar(420,440-spec*4,420+25,440);//輸出長條圖			
	}
	
	for(i=0;i<len;i++)
	{
		itoa(num[i], dnum, 10);//整數轉字串 
		setfillstyle(1,color[i]);
		setcolor(color[i]);
		outtextxy(30*i,450,dnum);//輸出文字 
		bar(30*i,440-num[i]*4,30*i+25,440);//輸出長條圖 
	}
	delay(500);
}

void printradixbukkit(int *num, int *temp, int len)
{
	cleardevice();
	int count,i,j;
	char dnum[4];
	for(i=0; i<len; i++)
	{
		itoa(num[i], dnum, 10);
		outtextxy(30*i,0,dnum);
	}
	
	for(i=0; i<10; i++)
	{
		itoa(i, dnum, 10);
		outtextxy(45*i,50,dnum);
		count=0;
		for(j=0; j<len; j++)
		{
			if(temp[i*13+j]!=0)
			{
				itoa(temp[i*13+j], dnum, 10);
				outtextxy(45*i,100+count*20,dnum);
				count++;
			}
		}
	}
	delay(500);
}

/*void mergetext(int *num, int left, int right, int i, int j)
{
	char dnum[4];
	int t;
	int mid = (left + right) / 2;
	
	for(t = left; t <= mid; t++)
	{
		itoa(num[t], dnum, 10);
		if(t < i)
		{
			setcolor(0);
		}
		else
		{
			setcolor(15);
		}
		outtextxy(400+30*t, 100, dnum);
	}
	for(t = mid+1; t <= right; t++)
	{
		itoa(num[t], dnum, 10);
		if(t < j)
		{
			setcolor(0);
		}
		else
		{
			setcolor(15);
		}
		outtextxy(400+30*t, 300, dnum);
	}
	//delay(500);
}*/

void random(int *num, int len)
{
	srand(time(NULL));
	int flag[100] = {0}, i;
	for(i=0;i<13;i++)
	{
		num[i] = 1+rand()%100;
		if(flag[num[i]-1]==1)
		{
			i--;
			continue;
		}
		flag[num[i]-1] = 1;
		len++;
	}
}

void swap(int *a, int *b) 
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
