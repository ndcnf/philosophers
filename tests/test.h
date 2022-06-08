#ifndef TEST_H
# define TEST_H

# include <stdio.h> // printf
# include <unistd.h> // write, usleep
# include <string.h> // memset
# include <stdlib.h> // malloc, free
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_*

typedef struct node
{
	int id;
	struct node *next;
} node;

#endif
