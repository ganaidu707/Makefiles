void function1(int number){

	int i =0;
	int result[100];
	for(i = 0;i<number;i++){		
		result[i] = i*i;
		printf("result[%d] = %d\n", i, result[i]);
	}
}
