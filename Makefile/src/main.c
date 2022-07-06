#include<stdio.h>
#include "../include/function.h"
#include "../include/sqlite.h"

int json_parse_values(const char *);
void test(int);
int main(){

	function1(5);
	create_db();
	
	int reg = json_parse_values("reg");
	int interrupt = json_parse_values("int");
		
	printf("\treg = %d\n", reg);
	printf("\tint = %d\n", interrupt);
	
	test(5);
	
	return 0;
}
