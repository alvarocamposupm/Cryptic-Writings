#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void my_text();
void SPLicensePlates (char text[],int n);

int main()
{

    return 0;
}

void my_text(){

    char *inputext;
    int size;
    printf("Input the size of the text:\n");
    scanf("%d", &size);

    inputext = (char *)malloc((size + 1) * sizeof(char));

    if (inputext == NULL) {
        printf("Memory fault.\n");
    }

    printf("Type the your text:\n");
    scanf(" %[^\n]s", inputext);
    system("cls");
    printf("%s\n", inputext);
}

void SPLicensePlates (char text[],int n)
{
    int i;
    int nplates = 0;
    char plates[100][8];
    for (i = 0; i < strlen(text) - 6; i++) {
        if (isdigit(text[i]) && isdigit(text[i+1]) && isdigit(text[i+2]) && isdigit(text[i+3]) &&
            isupper(text[i+4]) && isupper(text[i+5]) && isupper(text[i+6]) &&
            text[i+4] != 'Ñ' && text[i+4] != 'Q' &&
            text[i+5] != 'Ñ' && text[i+5] != 'Q' &&
            text[i+6] != 'Ñ' && text[i+6] != 'Q') {
            sprintf(plates[nplates], "%c%c%c%c%c%c%c",
                    text[i], text[i+1], text[i+2], text[i+3],
                    text[i+4], text[i+5], text[i+6]);
            nplates++;
        }
    }
    printf("Se encontraron %d matrículas españolas:\n", nplates);
    for (i = 0; i < nplates; i++)
        printf("%s\n", plates[i]);
}
