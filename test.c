//test.c

#include "thread_pool.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* test(void *arg) {
	int i;
	for(i = 0; i < 5; i++) {
		printf("tid:%ld task:%ld\n", pthread_self(), (long)arg);
		fflush(stdout);
		sleep(2);
	}
	return NULL;
}

int main() {
	long i=0;
	thread_pool_t pool;
	
	pool = thread_pool_create(2);
	
	for(i = 0; i < 5; i++) {
		thread_pool_add_task(pool, test, (void*)i);
	}
	
	puts("press enter to terminate ...");
	getchar();
	
	thread_pool_destroy(pool);
	return 0;
}

