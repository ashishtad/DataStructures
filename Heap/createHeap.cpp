//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Creating a Max Heap / Heapify
// Input: Array of elements from which max heap needs to be created
// Algorithm:
// Traverse the array from end and heapify each node.
// 1. Since the leaf nodes are already heapified since no childs so no changes are required.
// 2. Basically start heapify from the parent of last leaf node.Leaf node: (n-1)th index
// 3. Parent node of leaf node = ((n-1)-1)/2 =(n/2 -1) index. Since if an arry starting from 0th index , if an element is at ith index
// then its parent index : (i-1)/2 index
// left child : (2*i)+1 th index
// right child: (2*i)+2 th index
// 4. So start doing heapify from n/2-1 th index.
// 5. Heapify:
// 6. first compare the child nodes, the greater among them if larger than the root then swap the root and larger element.
// 7. Recursively perform for the subtree
// Author: Ashish Tad
// Date: 20/6/2020
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>

using namespace std;

void printMaxHeap(int *ar,int n)
{
	printf("Max Heap elements\n");
	for(int i=0; i<n; ++i)
		printf("%d\t",ar[i]);
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
		if( largeIndex !=rootIndex )
			//swap as root node is less than one of the child nodes
			swap( ar[rootIndex],ar[largeIndex] );

	//Now again heapify the subtree formed after swapping
	Heapify(ar,n,largeIndex);
	

}
void buildHeap(int *ar,int n)
{
	//calculate the first non leaf node i.e last leaf node parent
	int leafNodeParentIndex = (n/2)-1;
	for( int i =leafNodeParentIndex; i>=0; --i )
	{
		Heapify(ar,n,i);
	}


}


int  main()
{

	int n =0;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	int ar[n];
	printf("Enter the elements\n");
	for( int i=0; i<n; ++i )
		scanf("%d",&ar[i]);

	printf("Array elements\n");
	for( int i=0; i<n; ++i )
		printf("%d\t",ar[i]);
	printf("\n");
	buildHeap(ar,n);
	printMaxHeap(ar,n);
	return 0;
}
