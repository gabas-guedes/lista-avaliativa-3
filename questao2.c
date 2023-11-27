#include <stdio.h>
#include <math.h>
int main()
{
    int tempo;
    double aporte;
    double taxa;
    double valor;

    scanf("%d", &tempo);
    scanf("%lf", &aporte);
    scanf("%lf", &taxa);
    for (int i = 0; i < tempo; i++)
    {
        valor = aporte * (1 + taxa) * ((pow((1 + taxa), i + 1) - 1) / taxa);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i + 1, valor);
    }
    return 0;
}