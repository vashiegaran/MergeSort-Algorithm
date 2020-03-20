#include<iostream>

using namespace std;
void Merge(int *Arr ,int first,int last, int half);
void MergeSort(int *Arr, int first,int last)
{
	int half;

	if(first<last)
	{
		half=(first+last)/2;
		MergeSort(Arr,first,half);
		MergeSort(Arr,half+1,last);
		Merge(Arr,first,last,half);

	}
}

void Merge(int *Arr ,int first,int last, int half)
{
	
	int tempArr[200] , x,y,z;

	x=first;
	y=first;
	z=half+1;


	while(x<=half && z<=last)
	{
		if(Arr[x]<Arr[z])
		{
			tempArr[y]=Arr[x];
			y++;
			x++;
		}else
		{
			tempArr[y]=Arr[z];
			y++;
			z++;
		}
	}

	while(x<=half)
	{
		tempArr[y]=Arr[x];
		x++;
		y++;
	}

	while(z<=last)
	{
		tempArr[y]=Arr[z];
		z++;
		y++;
	}

	for(int x=0;x<y;x++)
	{
		Arr[x]=tempArr[x];
	}



}



int main()

{

int myarray[200] , num;
cout<<"Enter number of elements to be sorted:";
cin>>num;
cout<<"Enter "<<num<<" elements to be sorted:";
for (int i = 0; i < num; i++) { cin>>myarray[i];}

MergeSort(myarray,0,num);
 cout<<"Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"\t";
    }

}