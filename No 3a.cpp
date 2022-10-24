#include<stdio.h>
#include<stdlib.h>
int quick_delay()
{
	int i,j;
	for(i=0;i<12000;i++)
	{
		for(j=0;j<12000;j++)
		{
		}
	}
	return 0;
}
int delay()
{
	int i,j;
	for(i=0;i<40000;i++)
	{
		for(j=0;j<40000;j++)
		{
		}
	}
	return 0;
}
int clear()
{
	int i;
	for(i=0;i<30;i++)
	{
		printf("\b");
	}
	for(i=0;i<30;i++)
	{
		printf(" ");
	}
	for(i=0;i<30;i++)
	{
		printf("\b");
	}
	return 0;
}
int reveal(int data[6])
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d",data[i]);
		if(i+1 < 5)
		{
			printf(" ");
		}
	}
	return 0;
}
int blink_bubble(int data[6],int ke)
{
	reveal(data);
	delay();
	printf("\b");
	int i;
	ke=5-ke;
	ke*=2;
	ke-=2;
	for(i=0;i<ke;i++)
	{
		printf("\b");
	}
	printf("   ");
	quick_delay();
	clear();
	return 0;
}
int input(int data[6])
{
	data[0]=5;
	data[1]=3;
	data[2]=1;
	data[3]=4;
	data[4]=2;
	printf("data awal: ");
	reveal(data);
	printf("\n");
}
int bubble_sort(int data[6])
{
	printf("proses bubble sort:\n");
	delay();
	int i,j,k,save;
	for(i=4;i>1;i--)
	{
		for(j=0;j<i;j++)
		{
		    reveal(data);
		    delay();
		    clear();
			for(k=0;k<3;k++)
		    {
		    	blink_bubble(data,j);
			}
			clear();
		    quick_delay();
			if(data[j] > data[j+1])
			{
				printf("data ditukar karena %d > %d",data[j],data[j+1]);
				delay();
				clear();
				save=data[j];
				data[j]=data[j+1];
				data[j+1]=save;
			}
		}
	}
	printf("\nhasil:\n");
	reveal(data);
	delay();
	printf("\ndata telah tersorting\n\n");
	return 0;
}
int blink_selection(int data[6],int ke)
{
	reveal(data);
	quick_delay();
	printf("\b");
	int i;
	ke=5-ke;
	ke*=2;
	ke-=2;
	for(i=0;i<ke;i++)
	{
		printf("\b");
	}
	printf(" ");
	quick_delay();
	clear();
	return 0;
}
int selection_sort(int data[6])
{
	printf("proses selection sort:\n");
	delay();
	int i,j,k,min,ke,help;
	for(i=0;i<5;i++)
	{
		reveal(data);
		delay();
		clear();
		min=data[i];
		ke=i;
		for(j=i;j<5;j++)
		{
			for(k=0;k<3;k++)
			{
				blink_selection(data,j);
			}
			if(data[j]<min)
			{
				min=data[j];
				ke=j;
			}
			reveal(data);
			printf(" => minimal %d",min);
			delay();
			clear();
		}
		if(ke != i)
		{
			help=data[ke];
			data[ke]=data[i];
			data[i]=help;
		}
		printf("jadi data ke %d adalah %d",i+1,data[i]);
		delay();
		clear();
	}
	reveal(data);
	printf("\ndata telah tersorting\n\n");
	return 0;
}
int bantu(int data[6],int left,int right)
{
	reveal(data);
	delay();
	clear();
	if(left >= right)
	{
		return 0;
	}
	printf("pivot = data terkiri yaitu %d",data[left]);
	delay();
	clear();
	int i,j,p=left,count=left+1,help;
	for(i=left+1;i<=right;i++)
	{
		for(j=0;j<3;j++)
		{
		    blink_selection(data,i);
		}
		if(data[i] < data[p])
		{
			printf("lebih kecil dari pivot jadi ditukar");
			delay();
			clear();
			clear();
			help=data[i];
			data[i]=data[count];
			data[count]=help;
			count++;
		}
	}
	count--;
	help=data[count];
	data[count]=data[p];
	data[p]=help;
	return bantu(data,left,count-1);
	return bantu(data,count+1,right);
}
int quick_sort(int data[6])
{
	printf("proses quick sort:\n");
	delay();
	bantu(data,0,4);
	reveal(data);
	printf("\ndata telah tersorting\n\n");
	return 0;
}
int searching(int data[6],int left,int right,int find)
{
	int mid;
	printf("batas kiri = %d",data[left]);
	delay();
	clear();
	printf("batas kanan = %d",data[right]);
	delay();
	clear();
	if(find < data[left] || find > data[right])
	{
		printf("data tak ditemukan!\n");
		return 1;
	}
	printf("%d yang dicari ada dalam range",find);
	delay();
	clear();
	mid=right+left;
	mid/=2;
	printf("tengah = %d",data[mid]);
	delay();
	clear();
	if(find < data[mid])
	{
		printf("geser batas kanan ke tengah");
		delay();
		clear();
		right=mid;
		return searching(data,left,right,find);
	}else if(find > data[mid])
	{
		printf("geser batas kanan ke tengah");
		delay();
		clear();
		left=mid;
		return searching(data,left,right,find);
	}else if(find == data[mid])
	{
		printf("%d ditemukan di data ke %d\n\n",find,mid+1);
		delay();
	}
}
int binary_search(int data[6],int find)
{
	int left=0,right=4;
	printf("proses binary search:\n");
	delay();
	searching(data,left,right,find);
	return 0;
}
int inter(int data[6],int left,int right,int find)
{
	int mid;
	printf("batas kiri = %d",data[left]);
	delay();
	clear();
	printf("batas kanan = %d",data[right]);
	delay();
	clear();
	if(find < data[left] || find > data[right])
	{
		printf("data tak ditemukan!\n");
		return 1;
	}
	printf("%d yang dicari ada dalam range",find);
	delay();
	clear();
	mid=(find-data[left])/(data[right]-data[left])*(left-right);
	mid+=left;
	printf("tengah = %d",data[mid]);
	delay();
	clear();
	if(find < data[mid])
	{
		printf("geser batas kanan ke tengah");
		delay();
		clear();
		right=mid;
		return searching(data,left,right,find);
	}else if(find > data[mid])
	{
		printf("geser batas kanan ke tengah");
		delay();
		clear();
		left=mid;
		return searching(data,left,right,find);
	}else if(find == data[mid])
	{
		printf("%d ditemukan di data ke %d\n\n",find,mid+1);
		delay();
	}
}
int interpolation_search(int data[6],int left,int right,int find)
{
	printf("proses interpolation search:\n");
	delay();
	inter(data,left,right,find);
	return 0;
}
int main()
{
	int *data = (int *)malloc(sizeof(int)*9999999);
	input(data);
	bubble_sort(data);
	input(data);
	selection_sort(data);
	input(data);
	quick_sort(data);
	data[0]=1;
	data[1]=4;
	data[2]=6;
	data[3]=9;
	data[4]=29;
	printf("data awal: ");
	reveal(data);
	printf("\ntujuan program mencari angka 4\n");
	delay();
	binary_search(data,4);
	printf("data awal: ");
	reveal(data);
	printf("\ntujuan program mencari angka 4\n");
	interpolation_search(data,0,4,4);
	free(data);
	printf("program telah selesai tanpa ditemukan error :)\n");
	return 0;
}
