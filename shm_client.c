#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <string.h>

// ADD NECESSARY HEADERS

#define SHM_NAME "cameronc_broeking"

typedef struct {
    int pid;
    char birth[25];
    char clientString[10];
    int elapsed_sec;
    double elapsed_msec;
} stats_t;

// Mutex variables
pthread_mutex_t* mutex;

void exit_handler(int sig) {
    // ADD

    // critical section begins
	pthread_mutex_lock(mutex);

    // Client leaving; needs to reset its segment   

	pthread_mutex_unlock(mutex);
	// critical section ends

    exit(0);
}

int main(int argc, char *argv[]) {
	// ADD    

	int pageSize = getpagesize();

	int fd = shm_open(SHM_NAME, O_RDWR, 0660);
	stats_t *shm_ptr = mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	//To write a string to shared memory
//      char *string = strdup("Hello World");
//      strcpy(shm_ptr, string);

	stats_t* data = malloc(sizeof(stats_t));		
	data->pid = 2155;
	char* birth = "birth";
	strcpy(data->birth, birth);
	char* clientString = "clientString";
	strcpy(data->clientString, clientString);
	data->elapsed_sec = 200;
	data-> elapsed_msec = 3300;	

	memcpy(shm_ptr, &data, sizeof(stats_t));
    	sleep(1000);

	// critical section begins
    pthread_mutex_lock(mutex);
        
	// client updates available segment
		
	pthread_mutex_unlock(mutex);
    // critical section ends
        
	while (1) {
        
		// ADD
        
        sleep(1);

		// Print active clients
    }

    return 0;
}

