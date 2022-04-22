#include<stdio.h>
#include <math.h>

 void swap(int *a, int *b) 
 {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
void MAXheapify(int arr[], int n, int i) 
{
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
	  MAXheapify(arr, n, largest);
  }
}
  
  void BuildHeap(int arr[],int n)
  {
  	for (int i = n / 2 - 1; i >= 0; i--)
  	{
	  MAXheapify(arr, n, i);
	  }
      
  }
  
  void HeapSort(int arr[],int n)
  {
  	BuildHeap(arr,n);
  	
  	 for(int i = n - 1; i >= 0; i--) 
	 {
      swap(&arr[0], &arr[i]);

     // Heapify root element to get highest element at root again
      MAXheapify(arr, i, 0);
     }
  }
  
  void printArray(int arr[], int n) 
  {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  // Driver code
  int main() {
    int arr[] = {9,2,1,10,4,3,7,8,11,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    HeapSort(arr, n);
  
    printf("Sorted array is \n");
    printArray(arr, n);
  }
  

