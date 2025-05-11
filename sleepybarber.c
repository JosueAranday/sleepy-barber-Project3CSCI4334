#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

// Global or Shared Variables
int emptyChairs = 2;    //Initially 2, then changed to 5
sem_t mutex, chair, waitingClient;

int nextClient(){       // Function to generate the next client's ID
    static int client_id = 0;
    return ++client_id;
}

void takeChair(int client){       //Function to simulate taking a seat
    printf("Client %d is taking a seat.\n", client);
}

void takeClient(){                // Function to simulate the barber taking a cient
    printf("Barber is taking a cient.\n");
}

void* client(void* arg){
    while(1){
        //
        sleep(1);
    }
    return NULL;
}

void* barber(void* arg) {
    while (1) {
        // You'll add your logic here based on the pseudocode
        sleep(1); // Simulate time between actions
    }
    return NULL;
}

int main(){
    sem_init(&mutex, 0, 1);           // Mutual exclusion
    sem_init(&chair, 0, 2);           // First try had 2 chairs
    sem_init(&waitingClient, 0, 0);     // Sitting clients

    pthread_t barber_thread;    // Barber threads, similar to consumer threads
    pthread_create(&barber_thread, NULL, barber, NULL);

    pthread_t client_threads[5];      //Client threads, 5 for now
    for (int i = 0; i < 5; i++) {
        pthread_create(&client_threads[i], NULL, client, NULL);
    }

    pthread_join(barber_thread, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_join(client_threads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&chair);
    sem_destroy(&waitingClient);

    return 0;
}