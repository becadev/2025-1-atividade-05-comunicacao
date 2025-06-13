#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

char buffer[1024];
int mensagem_lida = 0;

void *escritor(void *arg) {
    strcpy(buffer, "Olá, comunicação com threads!\n");
    printf("Escritor (thread): Mensagem escrita.\n");
    sleep(1);  // Simula tempo
    return NULL;
}

void *leitor(void *arg) {
    while (!mensagem_lida) {
        sleep(1);  // Espera
    }
    printf("Leitor (thread): %s", buffer);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, escritor, NULL);
    sleep(1);
    mensagem_lida = 1;
    pthread_create(&t2, NULL, leitor, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
