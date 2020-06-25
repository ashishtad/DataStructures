//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Deleting a Max Heap / HEAP SORT
// Input: Array of elements /maxheap
// Algorithm:
// 1. Remove the first node i.e largest node of Heap/array. Replace it with last leaf node of heap or last node of array.
// 2. Now array/heap is reduced to size n-1. Heapify / adjust to make a heap if its not from zeroth node.
// 3. Heapify:
// 4. first compare the child nodes, the greater among them if larger than the root then swap the root and larger element.
// 5. Recursively perform for the subtree
// 6. For last element left in hep/array simply remove the element and return no heapify is required.
// Time complexity- O(Nlogn)
// SPace Complexity- O(1)
// Author: Ashish Tad
// Date: 23/6/2020
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>

using namespace std;

void printMaxHeap(int *ar,int n)
{
	for(int i=0; i<n; ++i)
		printf("%d\t",ar[i]);
	printf("\n");
}
//Heapify the subtree with rootIndex 
void Heapify( int *ar,int n, int rootIndex )
{
	//left child will be at 2*i+1 th index if parent is at i
	//right child will be at 2*i+2 th index if parent at i
	int leftChildIndex = (2*rootIndex)	+1;
	int rightChildIndex = (2*rootIndex) +2;
	int largeIndex =  rootIndex;
	//compare the two child nodes.
	if( leftChildIndex < n )
	{
		if( (rightChildIndex<n) && (ar[leftChildIndex] >= ar[rightChildIndex]))	
				largeIndex = leftChildIndex;
		else if( rightChildIndex >=n )
				largeIndex = leftChildIndex;
	}
	if( rightChildIndex < n )
	{
		if( (leftChildIndex<n) && (ar[rightChildIndex] >= ar[leftChildIndex]))	
				largeIndex = rightChildIndex;
		else if( leftChildIndex >=n )
				largeIndex = rightChildIndex;
	}

	//Already in heap so return
	if( ar[largeIndex] <= ar[rootIndex] )
		return;
	else
		//swap as root node is less than one of the child nodes
		swap( ar[rootIndex],ar[largeIndex] );

	//Now again heapify the subtree formed after swapping
	Heapify(ar,n,largeIndex);
	

}

void deleteHeap(int *ar, int n)
{

	//For last element in heap
	if( 0==n )
	{
		printf("Last element of heap[%d]\n",ar[0]);
		return;
	}
	printf("Removing node [%d] n=[%d]\n",ar[0],n);
	//remove first node i.e largest and replace with last leaf node/ last mode of max heap
	//Since we are doing heap sort so instead of just removing first node , swap it with last node
	int deletedNode = ar[0];
	//First replace with last node , this to ensure heapify should be proper because we are using same array to store the sorted elements too.
	//usecase: ar[10,8,5]. If we directly swap like swap(ar[0],ar[n-1]) then do heapify then after heapify ar will be [5,8] which is wrong.
	//so first take backup of deleting node. Then replace it with last node and then again replace the last/n-1 th node with the backup node
	ar[0]=ar[n-1];    	
	Heapify(ar,n-1,0);
	ar[n-1] = deletedNode;
	printf("After heapify \n");
	printMaxHeap(ar,n-1);
	deleteHeap(ar,n-1);
}

int  main()
{

	int n =0;
	printf("Enter the max heap no of nodes\n");
	scanf("%d",&n);
	int ar[n];
	printf("Enter the max heap elements\n");
	for( int i=0; i<n; ++i )
		scanf("%d",&ar[i]);

	printf("Heap elements\n");
	printMaxHeap(ar,n);

	deleteHeap(ar,n);
	printf("After deletion heap sort:\n");
	printMaxHeap(ar,n);
	return 0;
}
