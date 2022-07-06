#include<stdio.h>
#include<stdlib.h>

void test(int size){

	int i = 0;
	
	int *p = malloc(size*sizeof(*p));
	
	if((p == NULL)){
		printf("Memory not allocated.\n");
		p = malloc(size*sizeof(*p));
	}
	
	for(i=0;i<size;i++){
		p[i] = i*i*i;
	}
	
	for(i = 0;i<size; i++){
		printf("pinter(%d) = %d\n", i, *(p+i));
	}
	
	free(p);

}

int main(){
	test(5);

	return 0;
}
