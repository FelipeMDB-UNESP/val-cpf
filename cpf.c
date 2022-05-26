//Felipe Melchior de Britto - 221151478

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int cpf[11];
    int primeiroDigitoValidacao = -1;
    int segundoDigitoValidacao = -1;
    bool flagCpfEhValido = true;

    //scan do cpf
    for(int i = 0; i < 11; i ++){
        scanf("%d", &cpf[i]);
    }

    //validacao do CPF
    int aux[11];
    for(int i = 0; i < 10; i++)
        aux[i] = cpf[i];
    int auxCount = 0;
    int somaCPF = 0;

    //primeira soma
    for(int i = 10; i >=2 && auxCount <=8; i--){
        aux[auxCount] = aux[auxCount] * i;
        somaCPF = somaCPF + aux[auxCount];
        auxCount++;
    }
    printf("%d\n", somaCPF);

    //achando digito de validacao
    int restoDivisao = (somaCPF % 11);
    if(restoDivisao < 2){
        primeiroDigitoValidacao = 0;
    }
    else if(restoDivisao >= 2){
        primeiroDigitoValidacao = 11 - restoDivisao;
    }
    printf("%d\n", primeiroDigitoValidacao);


    //segunda soma
    for(int i = 0; i < 10; i++){
        aux[i] = cpf[i];
    }
    auxCount = 0;
    somaCPF = 0;
    for(int i = 11;  i >=2 && auxCount <=9; i--){
        aux[auxCount] = aux[auxCount] * i;
        somaCPF = somaCPF + aux[auxCount];
        auxCount++;
    }
    printf("%d\n", somaCPF);

    //achando segundo digito de validacao;
    restoDivisao = (somaCPF % 11);
    if(restoDivisao < 2){
        segundoDigitoValidacao = 0;
    }
    else if(restoDivisao >= 2){
        segundoDigitoValidacao = 11 - restoDivisao;
    }
    printf("%d\n", segundoDigitoValidacao);

    /*printf("Para comparaçao o CPF é: ");
    for(int i = 0; i < 11; i ++){
        printf("%d", cpf[i]);
    }printf("\n");*/

    //validacao final

    if(primeiroDigitoValidacao != cpf[9] || segundoDigitoValidacao != cpf[10])
        flagCpfEhValido = false;
    if(flagCpfEhValido)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
