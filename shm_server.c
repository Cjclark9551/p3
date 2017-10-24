#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define SHM_NAME "cameronc_broeking"
// ADD NECESSARY HEADERS

typedef struct {
    int pid;
    char birth[25];
    char clientString[10];
    int elapsed_sec;
    double elapsed_msec;
} stats_t;

// Mutex variables
pthread_mutex_t* mutex;
pthread_mutexattr_t mutexAttribute;

void exit_handler(int sig) 
{
    // ADD
    
	exit(0);
}

int main(int argc, char *argv[]) 
{
    // ADD
	
	// Creating a new shared memory segment
	int fd = shm_open(SHM_NAME, O_RDWR | O_CREAT, 0660);	
       
	int pageSize = getpagesize();

	ftruncate(fd, pageSize); //must find pagesize with system call

	stats_t *shm_ptr = mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
    

	//read with print? and shm_ptr
	sleep(5);
	printf("%d\n", *(shm_ptr)->birth);


	// Initializing mutex
	pthread_mutexattr_init(&mutexAttribute);
	pthread_mutexattr_setpshared(&mutexAttribute, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(mutex, &mutexAttribute);

    while (1) 
	{
		// ADD

        sleep(1);
    }

    return 0;
}

