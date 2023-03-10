#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxInputLength 20

char *checkContent(char *p) {
    if (*p == ' ' || *p == ':' || *p == '-' || *p == 'h') {
        p++;
        p = checkContent(p);
        return p;
    } else {
        if (*p == '0') {
            p++;
            return p;
        }
    }
    return p;
}

int main() {
    setbuf(stdout, 0);
    char eingabe[MaxInputLength];
    char endExpression[MaxInputLength] = "exit\n";
    unsigned long ergebnisHour = 0;
    unsigned long ergebnisMinute = 0;

    printf("Hello!\n"
           "If you wish to get the total time you have worked on a certain day you want to enter the times like this: >HH:MM-HH:MM\n"
           "Alternatively you can also enter '<HH:MM+HH:MM', which will give you the time at which you ended working.\n"
           "To add multiple work hours use '+HH:MM HH:MM', only enter two per line.\n"
           "Entering a '=' will give you the result. The previous operations may not be combined.\n"
           "By typing 'exit' the program will end\n");

    do {
        fgets(eingabe, MaxInputLength, stdin);
        char *ptr = &eingabe[1];
        unsigned long startHour;
        unsigned long startMinute;
        unsigned long endHour;
        unsigned long endMinute;
        switch (eingabe[0]) {
            case '>':
                ptr = checkContent(ptr);
                startHour = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                startMinute = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                endHour = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                endMinute = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                ergebnisHour = endHour - startHour;
                ergebnisMinute = endMinute - startMinute;
                if (ergebnisMinute < 0) {
                    ergebnisMinute = -ergebnisMinute;
                    ergebnisHour = ergebnisHour - 1;
                }
                break;
            case '<':
                ptr = checkContent(ptr);
                startHour = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                startMinute = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                endHour = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                endMinute = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                ergebnisHour = startHour + endHour;
                ergebnisMinute = startMinute + endMinute;
                if (ergebnisMinute >= 60) {
                    ergebnisMinute = ergebnisMinute - 60;
                    ergebnisHour++;
                }
                break;
            case '+':
                ptr = checkContent(ptr);
                startHour = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                startMinute = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                endHour = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                endMinute = strtoul(ptr, &ptr, 0);
                ptr = checkContent(ptr);
                ergebnisHour = ergebnisHour + startHour + endHour;
                ergebnisMinute = ergebnisMinute + startMinute + endMinute;
                if (ergebnisMinute >= 60) {
                    int i = ergebnisMinute / 60;
                    ergebnisHour += i;
                    ergebnisMinute = ergebnisMinute % 60;
                }
                break;
            case '=':
                printf("%lu:%lu\n", ergebnisHour, ergebnisMinute);
                ergebnisMinute = 0;
                ergebnisHour = 0;
                break;
        }
    } while (strcmp(eingabe, endExpression) != 0);

    return 0;
}
