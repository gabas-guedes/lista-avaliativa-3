#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int diasvalidos(char dias[15])
{
    int valid = 0;
    char *days[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(dias, days[i]) == 0)
        {
            valid = 1;
            break;
        }
    }

    return valid;
}
int placavalida(char *placa)
{

    if (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        placa[3] == '-' && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]))
    {
        return 1;
    }
    else if (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
             isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))
    {
        return 1;
    }

    return 0;
}
int ultimodiasvalidosultimonumero(char *dia, char *placa)
{
    int x = strlen(placa);

    int ultimonumero = placa[x - 1] - '0';

    if ((ultimonumero == 0 || ultimonumero == 1) && strcmp(dia, "SEGUNDA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimonumero == 2 || ultimonumero == 3) && strcmp(dia, "TERCA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimonumero == 4 || ultimonumero == 5) && strcmp(dia, "QUARTA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimonumero == 6 || ultimonumero == 7) && strcmp(dia, "QUINTA-FEIRA") == 0)
    {
        return 1;
    }
    else if ((ultimonumero == 8 || ultimonumero == 9) && strcmp(dia, "SEXTA-FEIRA") == 0)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char placa[9];
    char dia[15];

    scanf("%s", placa);
    scanf("%s", dia);

    if (!placavalida(placa) && !diasvalidos(dia))
    {
        printf("Placa invalida\nDia da semana invalido\n");
    }
    else if (!placavalida(placa))
    {
        printf("Placa invalida\n");
    }
    else if (!diasvalidos(dia))
    {
        printf("Dia da semana invalido\n");
    }
    else if (ultimodiasvalidosultimonumero(dia, placa))
    {

        printf("%s nao pode circular %s\n", placa, strlwr(dia));
    }
    else if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)
    {
        printf("Nao ha proibicao no fim de semana\n");
    }
    else if (!ultimodiasvalidosultimonumero(dia, placa))
    {
        printf("%s pode circular %s\n", placa, strlwr(dia));
    }

    return 0;
}