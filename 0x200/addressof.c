#include <stdio.h>

int main() {
	int int_var = 5;
	int *int_ptr;
	
	int_ptr = &int_var; // put the address of int_var into int_ptr
	printf("%d",int_ptr);
	return 0;
}
