#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_proc(void* param)
{
    int first = 0;
    int* p0 = (int*)malloc(1024);
    int* p1 = (int*)malloc(1024 * 1024);
    printf("(0x%x): first=%p\n",    pthread_self(), &first);
    printf("(0x%x): p0=%p p1=%p \n", pthread_self(), p0, p1);
    return 0;
}

#define N 5
int main(int argc, char* argv[])
{
    int first = 0;
    int i= 0;
    void* ret = NULL;
    pthread_t tid[N] = {0};
    printf("first=%p\n", &first);
    for(i = 0; i < N; i++)
    {
        pthread_create(tid+i, NULL, thread_proc, NULL);
    }
    for(i = 0; i < N; i++)
    {
        pthread_join(tid[i], &ret);
    }
    return 0;
}
