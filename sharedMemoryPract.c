#include<sys/types.h>

#define MSIZ 27

main(){
	char c;
	int shmid;
	key_t key = 123;
	char *shm, *s;

	if((shmid = shmget(key, MSIZ, IPC_CREAT | 0666)) < 0){
			error("Something went wrong");
			exit(1);

			}

	if((shm = shat(shmid, NULL, 0)) == (char *) -1 ){
		error("Something went wrong 2");
		exit(1);
	}

	//Put data into shared memory
	s = shm;
	for(c = 1; c<=26; c++){
		*s++ =c ;
		*s = '\0';
	}

	//wait untill process B changes the first number
	while(*shm != '*') sleep(1);
	shmdt(shm);
	exit(0);
}
