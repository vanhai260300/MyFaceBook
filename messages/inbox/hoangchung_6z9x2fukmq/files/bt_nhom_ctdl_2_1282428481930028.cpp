#include<stdio.h>
void HV(int &a,int &b)
{
	int tg;
	tg=a;
	a=b;
	b=tg;
}
void sort_NB(int a[],int n)
{
	int i,j;
	for(i=1;i<=n-1;i++)
		for(j=n;j>i;j--)
		{
			if(a[j]<a[j-1])
				HV(a[j],a[j-1]);
		}
}
void sort_Chen(int a[],int n)
{
	int t, j;
	for (int i = 2; i<=n; i++)
	{
		j = i - 1;
		t = a[i];
		while (t<a[j] && j >= 1)
		{
			a[j + 1] = a[j];
			j--;
		}
			a[j + 1] = t;
	}
}
void sort_Chon(int a[],int n)
{
	int i,min,j;
	for(i=1;i<n;i++)
	{
		min=i;
		for(j=i+1;j<=n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		HV(a[min],a[i]);
	}
}
void merge(int* a,int left,int mid,int right)	{
	
	int temp1[mid-left+1];
	int temp2[right-mid];
	int index_array = left;
	
	for(int i = 0; i < mid-left+1; i++)
		temp1[i] = a[index_array++];
		
	for(int i = 0; i < right - mid; i++)
		temp2[i] = a[index_array++];
		
	int index_temp1 = 0,index_temp2 = 0;
	index_array = left;
	
	while(index_temp1 <= mid - left && index_temp2 < right - mid)	{
		
		if(temp1[index_temp1] < temp2[index_temp2]) 	{
			
			a[index_array] = temp1[index_temp1];
			index_temp1++;
		}
		else	{
			
			a[index_array] = temp2[index_temp2];
			index_temp2++;
		}
		index_array++;
	}
	
	while(index_temp1 <= mid - left)	{
		
		a[index_array] = temp1[index_temp1];
		index_array++;
		index_temp1++;
	}
	
	while(index_temp2 < right - mid)	{
		
		a[index_array] = temp2[index_temp2];
		index_array++;
		index_temp2++;
	}
}

void sort_Merge(int* a,int left,int right)	{
	
	int mid = (right+left)/2;
	if(left < right) 	{
	
		sort_Merge(a,left,mid);
		sort_Merge(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
int partition (int a[], int low, int high)
{
    int pivot = a[high];    
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if (left >= right) break;
        HV(a[left], a[right]);
        left++;
        right--;
    }
    HV(a[left], a[high]);
    return left;
}
void sort_Quick(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        sort_Quick(a, low, pi - 1);
        sort_Quick(a, pi + 1, high);
    }
}
void display(int a[],int n)
{
	int i;
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}
main()
{
	int a[50],n,i,choose;
	printf("Nhap n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Nhap so thu %d ",i);
		scanf("%d",&a[i]);
	}
	display(a,n);
	/*
	sap xep noi bot: sort_NB(a,n);
	sap xep chon truc tiep: sort_Chon(a,n);
	sap xep chen: sort_Chen(a,n);
	sap xep tron: sort_Merge(a,1,n);
	sap xep nhanh: sort_Quick(a,1,n);
	*/
}                     
