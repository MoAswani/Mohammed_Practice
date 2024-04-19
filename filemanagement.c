#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>

int main(){
	int fd,fd1,sz;
	/*

	fd = creat("myfile.txt", S_IREAD);
	if (fd == -1){
		printf("Error in creating hte file\n");
		printf("The error number is %d ",errno);
		perror("Program");
	}
	else{
		printf("Myfile.txt createdsuccesfully in read only mode");
	}
	*/
	
	fd1 = open("myfile.txt", O_WRONLY);
	sz = write(fd, "Hello world", 12);

	if (sz <= 0){
		perror("Program");
		exit(1);
	}
	else{
		printf("Myfile.txt written on to succesfully");
	}

	close(fd1);

	return 0;
}
