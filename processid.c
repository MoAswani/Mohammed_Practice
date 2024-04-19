#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int i;
	printf("A program to demonstarete simple fork() %d", getpid());


	i = fork();
	printf("\nFork done succesfully and the pid is %d", getppid());

	printf("\nThe parent process id is %d", getppid());

	return 0;
}
