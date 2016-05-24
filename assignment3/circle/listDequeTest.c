#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque(); 
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("%g\n", frontCirListDeque(q));
	printf("%g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printCirListDeque(q);
	printf("in Reverse:\n");
	reverseCirListDeque(q);
	printf("After Reverse:\n");
	printCirListDeque(q);
	return 0;
}
