#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

#define MAX_SIZE 20

//The array representation of a heap is NOT sorted!

struct MaxHeap{
	int* array;
	unsigned int size;
	MaxHeap(){
		array = new int[MAX_SIZE];
		size = 0;
	}
	MaxHeap(MaxHeap& me){
		this->array = new int[MAX_SIZE];	
		this->size = me.size;
		for(unsigned int i = 0; i < size; i++)
			this->array[i] = me.array[i];
	}
	void copyFrom(MaxHeap* me){
		this->size = me->size;
		for(unsigned int i = 0; i < size; i++)
			this->array[i] = me->array[i];
	}
	~MaxHeap(){
		delete array;
	}
	//index range: 0-...
	int left(int i){return 2*i + 1;};
	int right(int i){return 2*i + 2;};
	int leftV(int i){return array[left(i)];};
	int rightV(int i){return array[right(i)];};
	int parent(int i){return floor(i / 2);};
	int parentV(int i){return array[parent(i)];};
	void swap(int i, int j){
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	void heapify(int index){
		if(index < 0 || index >= size) return;
		if(left(index) >= size && right(index) >= size) return;
		if( right(index) >= size && left(index) < size && leftV(index) > array[index] ){
			swap(index, left(index));
			heapify(left(index));	
		}else if( right(index) < size && left(index) < size && leftV(index) <= rightV(index) && rightV(index) > array[index]){
			swap(index, right(index));
			heapify(right(index));
		}else if( right(index) < size && left(index) < size && rightV(index) <= leftV(index) && leftV(index) > array[index] ){
			swap(index, left(index));
			heapify(left(index));
		}
	}
	void insert(int val){
		if(size >= MAX_SIZE){
			printf("Max allowable size achieved! \n");
		 	return;
		}
		size++;
		array[size - 1] = val;	
		int i = size - 1;
		while( i > 0){
			if( array[i] > parentV(i) ){
				swap(i, parent(i));
				i = parent(i);
			}else break;
		}
	}
	int getMax(){return array[0];}
	void extractMax(){
		if(size == 0) return;
		if(size == 1) {
			size--;
			return;
		}
		array[0] = array[size - 1];
		size--;
		heapify(0);
	}
	void buildHeap(int* array, int size){
		if(size <0 || size >= MAX_SIZE){
			printf("INVALID size=%d\n", size);
			return;
		}
		this->size = size;
		for(unsigned int i = 0; i < size; i++)
			this->array[i] = array[i];
		for(int i = floor(size/2) - 1; i >= 0; i--){
			heapify(i);
		}
	}
	void printArray(){
		for(unsigned int i = 0; i < size; i++)
			printf(" %d ,", array[i]);
		printf("\n");
	}
	int find(int f){
		//Since a heap is not sorted , we need to iterate through all the elements
		for(int i = 0; i < size; i++)
			if(array[i] == f)
				return i;
		return -1;
	}
	int findKthLargest(int k){
		if(k <= 0 || k > size){
			printf("INVALID k=%d \n", k);
			return 0;
		}
		MaxHeap newH;
		newH.copyFrom(this);
		for(unsigned i = 0; i < k-1 ; i++)
			newH.extractMax();
		return newH.getMax();
	}
	static void sort(int* array, int size){
		if(size <= 0 || size > MAX_SIZE){
			printf("INVALID SIZE=%d\n", size);
			return;
		}
		MaxHeap heap;
		heap.buildHeap(array, size);
		while(heap.size > 0){
			heap.swap(0, heap.size-1);
			heap.size --;
			heap.printArray();
			heap.heapify(0);
			heap.printArray();
		}
		for(unsigned int i = 0; i < size; i++)
			array[i] = heap.array[size-1-i];
	}
};

void printArray(int* array, int size){
	for(int i = 0; i < size; i++)
		printf(" %d ,", array[i]);
	printf("\n");
}

int main(int argc, char** argv){
	
	MaxHeap heap;
	heap.insert(2);
	heap.insert(10);
	heap.insert(5);
	heap.insert(6);
	heap.insert(7);
	heap.printArray();

	int arr[8]={1, 43, 5, 8, 13, 3, 9, 19};
	heap.buildHeap(arr, 8);

	heap.extractMax();

	heap.printArray();

	int k = atoi(argv[1]);
	printf("%d'th largest is:%d \n", k, heap.findKthLargest(k) );
	printf("val=%d is at index=%d \n", 5, heap.find(5));
	printf("val=%d is at index=%d \n", 50, heap.find(50));
	

	printf("unsorted array:\n");
	printArray(arr, 8);
	MaxHeap::sort(arr, 8);
	printf("sorted array:\n");
	printArray(arr, 8);

	return 0;
}

