#include <stdio.h>
#include <pthread.h>

pthread_mutex_t locks[2];

void *print_job(void *arg) {
    int i = *(int *)arg;

    pthread_mutex_lock(&locks[i]);
    pthread_mutex_lock(&locks[(i + 1) % 2]);

    printf("Printer Worker %d: Printing object.\n", i);

    pthread_mutex_unlock(&locks[(i + 1) % 2]);
    pthread_mutex_unlock(&locks[i]);
    return NULL;
}

int main(void) {
    int id;
    pthread_t thread;

    pthread_mutex_init(&locks[0], NULL);
    pthread_mutex_init(&locks[1], NULL);

    printf("Enter worker ID (0 or 1): ");
    if (scanf("%d", &id) != 1 || id < 0 || id > 1) {
        fprintf(stderr, "Invalid worker ID. Enter 0 or 1.\n");
        pthread_mutex_destroy(&locks[0]);
        pthread_mutex_destroy(&locks[1]);
        return 1;
    }

    if (pthread_create(&thread, NULL, print_job, &id) != 0) {
        perror("pthread_create");
        pthread_mutex_destroy(&locks[0]);
        pthread_mutex_destroy(&locks[1]);
        return 1;
    }

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&locks[0]);
    pthread_mutex_destroy(&locks[1]);
    return 0;
}
