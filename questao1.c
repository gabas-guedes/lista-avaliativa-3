#include <stdio.h>
#include <string.h>
int romanoparadecimal(char romano)
{
    switch (romano)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
int main()
{
    char romano[12];
    int i;
    int total = 0;
    gets(romano);
    int tamanho = strlen(romano);
    for (i = 0; i < tamanho; i++)
    {

        int decimal = romanoparadecimal(romano[i]);
        if (romanoparadecimal(romano[i + 1]) > decimal)
        {
            total -= decimal;
        }
        else
        {
            total += decimal;
        }
    }
    int totalbinario;
    int notprintf0 = 0;
    printf("%s na base 2: ", romano);
    for (int j = 10; j >= 0; j--)
    {
        totalbinario = (total >> j) & 1;
        if (totalbinario == 1 || notprintf0)
        {
            printf("%d", totalbinario);
            notprintf0 = 1;
        }
    }
    printf("\n");
    printf("%s na base 10: %d\n", romano, total);
    printf("%s na base 16: %x\n", romano, total);
    return 0;
}
