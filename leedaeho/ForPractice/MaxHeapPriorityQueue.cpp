#include <stdio.h>
#include <malloc.h>

typedef struct HeapType{
	int heap[200];
	int heap_size;
}HeapType;

HeapType* create(){
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	return heap;
}
void init(HeapType* heap){
	heap->heap_size = 0;
}

void insert_max_heap(HeapType* h, int e){
	//마지막 노드에 할당
	//배열의 마지막 인덱스에 할당
	int hsize = ++h->heap_size;

	int temp;
	//상위 노드보다 크면 스왑 - 루트노드까지
	while(true){
		if(hsize/2 >= 1 && h->heap[hsize/2] < e){
			h->heap[hsize] = h->heap[hsize/2];	
			hsize/=2;
		}else{
			break;
		}
	}
	h->heap[hsize] = e;
}

int delete_max_heap(HeapType* h){
	//마지막 노드를 루트노드에 할당
	int root_node = h->heap[1];
	int hsize = h->heap_size--;
	int last_node = h->heap[hsize];
	int i = 1;
	while(true){
		if(i*2+1 <= hsize && h->heap[i*2] >= h->heap[i*2+1]){
			if(h->heap[i*2] > last_node){
				h->heap[i] = h->heap[i*2];
			}else{
				h->heap[i] = last_node;
				break;
			}
		}else if(i*2+1 <= hsize && h->heap[i*2] < h->heap[i*2+1]){
			if(h->heap[i*2+1] > last_node){
				h->heap[i] = h->heap[i*2+1];
			}else{
				h->heap[i] = last_node;
				break;
			}
		}else if(i*2 == hsize){
			if(h->heap[i*2] > last_node){
				h->heap[i] = h->heap[i*2];	
			}else{
				h->heap[i] = last_node;
				break;
			}
		}else{
			break;
		}
		i *= 2;
	}
	//왼쪽 자식노드가 마지막노드보다 크면 바꿈
	return root_node;
}

int main(){
	int e1 = 10, e2 = 5, e3 = 30;
	int e4, e5, e6;
	HeapType* heap;
	heap = create();//힙 생성
	init(heap);//힙 초기화

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	//삭제
	e4 = delete_max_heap(heap);
	printf("%d ", e4);
	e5 = delete_max_heap(heap);
	printf("%d ", e5);
	e6 = delete_max_heap(heap);
	printf("%d \n", e6);

	free(heap);
	return 0;
}

