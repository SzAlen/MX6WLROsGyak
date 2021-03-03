#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fPointer;
    fPointer = fopen("szabo.txt", "w");
    fprintf(fPointer, "Nev: Szabo Alen \nSzak: Programtervezo informatikus \nNeptunkod: MX6WLR \n");
    fclose(fPointer);
    return 0;
}
