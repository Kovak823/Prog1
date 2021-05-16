#include <string.h>
#include <unistd.h>
#include <stdio.h>

void my_func(char* p, int x)
{
	printf("p is %s and x is %d\n", p, x);
}

int main(){
	printf("Hello World!\n");

		char* h = "Hello";
		char* w = "World";

		printf("%s, %s\n",h, w );

		my_func("foo", 7);
		my_func("asd", 56);
		my_func("alma", 10);
	
	return 0;
}