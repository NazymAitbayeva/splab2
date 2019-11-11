#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int t = 0;
	pid_t p1 = fork();
	if(p1==0){					
		execlp("python","python","addition.py",argv[1],argv[2],NULL);
		exit(0);
	}
	pid_t p2 = fork();
	if(p2==0){
execlp("java", "java","subtraction.java",argv[1],argv[2],NULL);
		}
	pid_t p3 = fork();
	if(p3==0){
		execlp("node", "node","multiplication.js",argv[1],argv[2],NULL);	
	}
	pid_t p4 = fork();
	if(p4==0){
		execlp("bash", "bash","division.sh",argv[1],argv[2],NULL);
	}
	waitpid(p4,0,0);
	waitpid(p3,0,0);
	waitpid(p2,0,0);
	waitpid(p1,0,0);
	printf("parent: done.\n");
}


