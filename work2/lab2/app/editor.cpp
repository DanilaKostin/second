#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <list>

#include "text.h"
#include "common.h"

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    const char *arg;
    const char *second_arg;

    text txt = create_text();

    printf("\nEnter help for instructions\n");

    while (1) {
        printf("\ned > ");

        fgets(cmdline, MAXLINE, stdin);


        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        if (strcmp(cmd, "showupfirst") == 0){
            showupfirst(txt);
            continue;
        }

        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }


        if(strcmp(cmd, "m") == 0) {
	    arg = strtok(NULL, " \n");
	    second_arg = strtok(NULL, " \n");
            if (arg == NULL || second_arg == NULL) {
                fprintf(stderr, "Usage: m line_number position\n");
            } else {
                m(txt, atoi(arg), atoi(second_arg));
            }
            continue;
        }

        if (strcmp(cmd, "mle")==0){
            if ((arg = strtok(NULL, " \n")) == NULL){
            fprintf(stderr, "mle line\n");
            }else{
            int line;
            if (sscanf(arg,"%d", &line)>0)
                mle(txt, line);
            else fprintf(stderr, "mle non-negative line\n");
                }
            continue;
        }

        if (strcmp(cmd, "r1ne")==0){
            r1ne(txt);
            continue;}

        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
