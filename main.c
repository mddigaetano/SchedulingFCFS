#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int nTasks;                                                                 //numero di processi da inserire;
    int i;                                                                      //contatore per ciclo for;
    int prv = 0;                                                                //(previous) conterrà il numero di cicli macchina da aspettare per eseguire processo;
    float avg = 0;                                                              //conterrà risultato finale;
    int *TasksTime;                                                             //puntatore per array dinamico contenente la durata dei processi;
    
    printf("Calcolo del tempo medio di attesa con l'algoritmo di scheduling FCFS\n\n");
    
    printf("Inserisci il numero di processi da immettere: ");
    scanf("%d", &nTasks);
    
    TasksTime = (int*)malloc(nTasks * sizeof(int));                             //allocazione array di nTasks elementi;
    
    printf("\nInserisci il tempo di esecuzione del processo %d: ", 0);
    scanf("%d", &(TasksTime[0]));                                               //inserimento primo valore per inizio ciclo;
    prv=TasksTime[0];                                                           //inizializzazione prv;
    avg = prv;                                                                  //inizializzazione avg;
    for(i=1; i < nTasks; i++){                                                  //partenza dal secondo elemento;
        printf("\nInserisci il tempo di esecuzione del processo %d: ", i);
        scanf("%d", &(TasksTime[i]));                                           //inserimento i-esimo processo;
        
        if(i != nTasks-1){                                                      //controllo per ultimo elemento(deve essere inserito ma non calcolato);
            avg += prv + TasksTime[i];                                          //calcolo avg parziale (nuovo valore avg = precedente-avg + (cicli macchina precedenti + attuale));
            prv += TasksTime[i];                                                //preparazione a iterazione successiva;
        }
    }
    avg = avg/nTasks;                                                           // calcolo finale avg;
    
    printf("\nIl tempo medio di attesa e' uguale a: %f", avg);
                                                                                //inizio calcolo inverso;
    prv=TasksTime[nTasks-1];                                                    //inizializzazione (ultimo valore);
    avg = prv;                                                                  //inizializzazione avg;
    for(i=nTasks - 2; i > 0; i--){                                              //ciclo decrescente (si ferma al penultimo elemento);
        avg += prv + TasksTime[i];
        prv += TasksTime[i];
    }
    avg = avg/nTasks;
    
    printf("\nIl tempo medio di attesa per i processi in ordine inverso e' uguale a: %f\n", avg);
    
    return (EXIT_SUCCESS);
}

