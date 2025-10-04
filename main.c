#include <stdio.h>

int main(){
    int opcao=0;
    int num;
    int a,b;
    float r;
    int segundos;
    int horas,minutos,resto;

    while(opcao!=5){
        printf("\nUTILIDADES\n");
        printf("1 Par ou Impar\n");
        printf("2 Numero entre 10-50\n");
        printf("3 Area e perimetro\n");
        printf("4 Segundos em horas e minutos\n");
        printf("5 Sair\n");
        printf("Escolha: ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                printf("Digite um numero: ");
                scanf("%d",&num);
                if(num%2==0){
                    printf("eh par\n");
                }else{
                    printf("eh impar\n");
                }
            break;


            case 2:
                printf("Digite um numero: ");
                scanf("%d",&num);
                if(num>=10 && num<=50){
                    printf("esta entre 10-50\n");
                }else{
                    printf("nao esta no intervalo\n");
                }
            break;


            case 3:
                printf("1 - Circulo\n");
                printf("2 - Retangulo\n");
                int figura;
                scanf("%d",&figura);
                if(figura==1){
                    printf("Raio: ");
                    scanf("%f",&r);
                    float areacirculo=3.14*r*r;
                    float perimetrocirculo=2*3.14*r;
                    printf("Area: %.2f\n",areacirculo);
                    printf("Perimetro: %.2f\n",perimetrocirculo);
                }else{
                    printf("Lado A: ");
                    scanf("%d",&a);
                    printf("Lado B: ");
                    scanf("%d",&b);
                    int arearetangulo=a*b;
                    int periretangulo=2*(a+b);
                    printf("Area: %d\n",arearetangulo);
                    printf("Perimetro: %d\n",periretangulo);
                }
            break;



            case 4:
                printf("Digite os segundos: ");
                scanf("%d",&segundos);
                horas=segundos/3600;
                resto=segundos%3600;
                minutos=resto/60;
                printf("%d segundos = %d horas e %d minutos\n",segundos,horas,minutos);
            break;



            case 5:
                printf("tchauuu\n");
            break;

            default:
                printf("opcao invalida\n");
        }
    }

    return 0;
}
