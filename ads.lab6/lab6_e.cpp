#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i= (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main()
{
	int n,m;
	cin>>n>>m;
	int k[m][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>k[j][i];
		}
	}
	for(int i=0; i<m; i++)
	{
		quickSort(k[i],0,n-1);
	}
	for(int i=n-1; i>=0; i--)
	{
		for(int j=0; j<m; j++)
		{
			cout<<k[j][i]<<" ";
		}
		cout<<endl;
	}

}
