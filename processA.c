/*This program creates a shared mamory segment, attaches a process to it
and writes some data to the segment
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

int main(){
	int shmid;
	char buff[100];
	void *shared_memory;

	shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT); //It creates a shared memory segment
	printf("Key of shared memory is %d\n", shmid);

	shared_memory = shmat(shmid, NULL, 0);
	printf("The process is attached at %p\n", shared_memory);

	printf("Enter some data to write to shared memory\n");
	read(0, buff, 100); //Read data from the buffer
	strcpy(shared_memory, buff); //Write data to shared Memory

	printf("You wrote:  %s\n",(char*)shared_memory);

}


