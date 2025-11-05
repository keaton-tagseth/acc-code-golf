#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int gnuRead();

int main (void)
{
    int whiteWin, blackWin, draw = 0;
    int total = 0;

    printf("started");
    gnuRead();

    return 0;
}

int gnuRead(){

    int whiteWin, blackWin, draw = 0;
    printf("\nstarted\n");

    FILE *file = fopen("./mega-clean.pgn", "r");

    if(file == NULL){
        perror("File not found");
    }

    char *line = NULL;

    size_t len = 0;
    ssize_t read;

    while((read = getline(&line, &len, file)) != -1){
        if((read == 19 || read == 15) && line[1] == 'R' && line[2] == 'e'){
                if(line[9] == '1'){
                    if(read == 19){
                        draw++;
                    }
                    else{
                        whiteWin++;
                    }
                }
                if(line[9] == '0'){
                    blackWin++;
               }
            
        }
    }
    printf("\n%d", draw);
    printf("\n%d", whiteWin);
    printf("\n%d", blackWin);
    printf("\n%d", draw + whiteWin + blackWin);
    fclose(file);
    return 0;
}
