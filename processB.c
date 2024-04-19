/*This program attaches a process to a sharedcmemory segment
and reads data from the segment
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

	shmid = shmget((key_t)2345, 1024, 0666); //It gets the id of a shared memory segment, now we dont use IPC_CREAT
	printf("Key of shared memory is %d\n", shmid);

	shared_memory = shmat(shmid, NULL, 0);// attaching
	printf("The process is attached at %p\n", shared_memory);

	printf("This program is for reading data from shared segment, the data was written by processA\n");
	
	printf("Data read from the segment is: %s\n", (char*)shared_memory);


}