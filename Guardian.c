#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_ADDRESS "192.168.1.1"  // Inserisci qui l'indirizzo IP desiderato
int avvia() {
    //printf("Hai scelto l'opzione 1!\n");
    char pingCommand[50];

    // Costruisci il comando ping con l'indirizzo IP incorporato
    snprintf(pingCommand, sizeof(pingCommand), "ping -c 4 %s", IP_ADDRESS);

    // Esegui il comando ping
    FILE *pingProcess = popen(pingCommand, "r");
    if (!pingProcess) {
        perror("Errore durante l'esecuzione di ping");
        exit(EXIT_FAILURE);
    }

    // Leggi l'output del comando ping
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pingProcess) != NULL) {
        printf("%s", buffer);
    }

    // Chiudi il processo di ping
    int status = pclose(pingProcess);
    if (status == 0) {
        printf("Ping riuscito a %s\n", IP_ADDRESS);
    } else {
        printf("Ping non riuscito a %s\n", IP_ADDRESS);
    }

   return 0;
}

int aggiungi() {

    char ip[50];//IP_ADDRESS

      FILE *file = fopen("ip.txt", "w");
    
    // Controlla se il file è stato aperto correttamente
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    // Scrivi dei valori nel file
        printf("Inserisci l'ip da controllare : ");
        scanf("%s", ip);
        fprintf(file," %s \n",ip);

     // Chiudi il file
        fclose(file);
        
    return 0;
}

void creafile(){
    
    
    
}


int leggi() {

    FILE *file = fopen("ip.txt", "r+");
    //file = fopen("ip.txt", "r");

    // Controlla se il file è stato aperto correttamente
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    // Leggi e stampa i valori dal file
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Letto: %s", buffer);
    }

    // Chiudi il file
    fclose(file);

    return 0;
}

int main() {
    int scelta;
    
    creafile();
    
    do {
        // Pulisce lo schermo
        system("clear");

        // Stampa il menu
        printf("=== Menu === \n");
        printf("1. AVVIA     \n");
        printf("2. AGGIUNGI  \n");
        printf("3. LEGGI     \n");
        printf("0. Esci      \n");

        // Richiede la scelta all'utente
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        // Esegue l'azione corrispondente alla scelta
        switch (scelta) {
            case 1:
                avvia();
                break;
            case 2:
                aggiungi();
                break;
            case 3:
                leggi();
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

        // Pausa per consentire la visualizzazione dei risultati
        printf("\nPremi INVIO per continuare...");
        getchar();
        getchar();  // Due getchar per evitare il newline rimasto nel buffer

    } while (scelta != 0);

    return 0;
}
