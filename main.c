#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxInputLength 20

void checkContent(char *p){
    if(*p==' ' || *p==':'){
       p++;
    }
}

int main() {
    char eingabe[MaxInputLength];
    char endExpression[] = "exit";
    unsigned long ergebnisHour = 0;
    unsigned long ergebnisMinute = 0;

    printf("Hello!\n"
           "If you wish to get the total time you have worked on a certain day you want to start with '>' and then proceed"
           "to enter the time you started working and ended separated with a '-'\n"
           "Alternatively you can also enter '<' and the time of beginning, followed by a '+' and the time you worked for, which will give you the time"
           "at which you ended working.\n"
           "Entering a '=' will give you the result. The two operations can not be combined.\n"
           "By typing 'exit' the program will end\n");

    do {
        scanf("%s", &eingabe);
        switch (eingabe[0]) {
            char *ptr;
            unsigned long startHour;
            unsigned long startMinute;
            unsigned long endHour;
            unsigned long endMinute;
            case '>':
                checkContent(ptr);
                startHour = strtoul(ptr, &ptr, 10);
                checkContent(ptr);
                startMinute = strtoul(ptr, &ptr, 10);
                checkContent(ptr);
                endHour = strtoul(ptr, &ptr, 10);
                checkContent(ptr);
                endMinute = strtoul(ptr, &ptr, 10);
                checkContent(ptr);
                ergebnisHour = endHour - startHour;
                ergebnisMinute = endMinute - startMinute;
                if (ergebnisMinute < 0) {
                    ergebnisMinute = -ergebnisMinute;
                }
                break;
            case '<':
                checkContent(ptr);
                startHour = strtoul(eingabe, &ptr, 2);
                checkContent(ptr);
                startMinute = strtoul(ptr, &ptr, 2);
                checkContent(ptr);
                endHour = strtoul(ptr, &ptr, 2);
                checkContent(ptr);
                endMinute = strtoul(ptr, &ptr, 2);
                checkContent(ptr);
                ergebnisHour = startHour + endHour;
                ergebnisMinute = startMinute + endMinute;
                if (ergebnisMinute >= 60) {
                    ergebnisMinute = 0;
                    ergebnisHour++;
                }
                break;
            case '=':
                printf("%luh%lu\n", ergebnisHour, ergebnisMinute);
                break;
        }
    }while(strcmp(eingabe, endExpression));

    return 0;
}
