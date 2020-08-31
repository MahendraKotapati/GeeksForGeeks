#include <iostream>
using namespace std;

//Shell sort.
void ShellSort(int arr[], int n)
{
	int gap, j, k, temp;
	// Gap (i) is calculated in this loop.
	for( gap = n/2; gap > 0; gap/=2)
	{
		for(j = gap; j < n; j++)    // insertion sort with 1 is replaced by gap
		{
			for(k = j-gap; k >= 0; k = k-gap)
			{
				if(arr[k+gap] >= arr[k])
				    break;
				else
					swap(arr[k],arr[k+gap]);
			}
		}
	}
}

// Driver Program
int main()
{	
	// sample array.
  int arr[] = {13, 10, 11, 2, 5, 8, 15};
  int n= 7;

  // Printing the unsorted array.
	cout<<"\nUnsorted array: ";
	for (int i = 0; i < n; i++)
		 cout<<arr[i]<< ",";
 
	ShellSort(arr, n);
 
	// Printing the sorted array.
	cout<<"\nAfter Shell sort, the array is: ";
	for (int i = 0; i < n; i++)
		 cout<<arr[i]<< ",";
 
	return 0;
}