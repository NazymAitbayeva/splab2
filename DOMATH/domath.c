// your code here
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("INCORRECT\n");
		exit(-1);	
	}
	int t = 0;
	pid_t p1 = fork();
	if(p1==0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		t = a+b;
		printf("child1: %d+%d=%d\n",a,b,t);
		exit(0);
	}
	pid_t p2 = fork();
	if(p2==0){	
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		t = a-b;
		printf("child2: %d-%d=%d\n",a,b,t);
		exit(0);
	}
	pid_t p3 = fork();
	if(p3==0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		t = a * b; 
		printf("child3: %d*%d=%d\n",a,b,t);
		exit(0);	
	}
	pid_t p4 = fork();
	if(p4==0){
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		t = a / b; 
		printf("child4: %d/%d=%d\n",a,b,t);
		exit(0);
	}
	waitpid(p4,0,0);
	waitpid(p3,0,0);
	waitpid(p2,0,0);
	waitpid(p1,0,0);
	printf("parent: done.\n");
}
