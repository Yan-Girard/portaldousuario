#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define euro 6.30
#define dolar 5.34
#define menuprincipal 0
#define menuinicial 1
#define menucriacao 2
#define sair 3

int menuCriacao();
int menuInicial();
int menuPrincipal();

int menuCriacao(){
	FILE *p_dadosdousuario;
	char usuario[50], senha[50];
	
	p_dadosdousuario = fopen("dadosdousuario.txt", "r");
	
	if(p_dadosdousuario == NULL){
		do{
			printf("********************************************************\n");
			printf("*                                                      *\n");
			printf("*           BEM-VINDO AO PORTAL DO USUARIO             *\n");
			printf("*                                                      *\n");
			printf("********************************************************\n\n");
			printf("Por favor, crie um usuario e uma senha, ambos sem espacos, antes de continuar.\n");
			printf("\nUsuario: ");
			scanf("%s", usuario);
			printf("Senha: ");
			scanf("%s", senha);
			if(strlen(senha) > 5 && strcmp(senha, "123456") != 0){
				p_dadosdousuario = fopen("dadosdousuario.txt", "w");
				fprintf(p_dadosdousuario, "%s %s", usuario, senha);
				fclose(p_dadosdousuario);
				printf("\nObrigado por criar sua conta! Voce sera redirecionado para o menu principal!\n\nRedirecionando...\n\n");
				return menuprincipal;
			}else{
				printf("\nA senha deve ter no minimo 6 digitos e ser dierente de 123456!\n\n");
			}
		}while(1);	
	}else{
		fclose(p_dadosdousuario);
	}
}

int menuInicial(){
	char usuario[50], senha[50], usuario_salvo[50], senha_salva[50];
	int opcao = 0;
	FILE *p_dadosdousuario = fopen("dadosdousuario.txt", "r"); 
	
	fscanf(p_dadosdousuario, "%s %s", usuario_salvo, senha_salva);
	fclose(p_dadosdousuario);
	
	do{
		printf("********************************************************\n");
		printf("*                                                      *\n");
		printf("*           BEM-VINDO AO PORTAL DO USUARIO             *\n");
		printf("*                                                      *\n");
		printf("********************************************************\n\n");
		printf("Digite um numero correspondente:\n\n1 - Entrar\n2 - Alterar usuario/senha\n3 - Apagar conta\n4 - Sair\n\nEscolha: ");
		scanf("%d", &opcao);
		
		if(opcao == 1){
			printf("\nUsuario: ");
			scanf("%s", usuario);
			printf("Senha: ");
			scanf("%s", senha);
			
			if(strcmp(usuario, usuario_salvo) == 0 && strcmp(senha, senha_salva) == 0){
				return menuprincipal;
			}else{
				printf("\nUsuario ou senha invalidos!\n\n");
			}
	    }else if(opcao == 2){
	    	printf("\nAntes de continuar, entre com sua conta atual!\n\nUsuario atual: ");
	    	scanf("%s", usuario);
	    	printf("Senha atual: ");
	    	scanf("%s", senha);
	    	
	    	if(strcmp(usuario, usuario_salvo) == 0 && strcmp(senha, senha_salva) == 0){
				printf("\nNovo usuario: ");
				scanf("%s", usuario);
				printf("Nova senha: ");
				scanf("%s", senha);
				
				if(strlen(senha) > 5 && strcmp(senha, "123456") != 0){
					p_dadosdousuario = fopen("dadosdousuario.txt", "w");
					fprintf(p_dadosdousuario, "%s %s", usuario, senha);
					fclose(p_dadosdousuario);
					printf("\nConta alterada com sucesso! Voce sera redirecionado para o menu principal!\n\nRedirecionando...\n\n");
					return menuprincipal;
				}else{
					printf("\nA senha deve ter no minimo 6 digitos e ser dierente de 123456! Voce sera redirecionado para o menu inicial!\n\nRedirecionando...\n\n");
				}
				
			}else{
				printf("\nUsuario ou senha invalidos!\n\nRedirecionando para o menu inicial...\n\n");
			}
		}else if(opcao == 3){
			int resposta;
			printf("\nVoce tem certeza?\n\n1 - Sim\n2 - Nao\n\nEscolha: ");
			scanf("%d", &resposta);
			
			if(resposta == 1){
				if(remove("dadosdousuario.txt") == 0){
					printf("\nConta apagada com sucesso!\n\n");
					return menucriacao;
				}else{
					perror("\nErro ao apagar a conta\n");
				}
				break;
			}else{
				printf("\nConta mantida!\n\n");
				printf("Redirecionando para o menu inicial...\n\n");
			}
			
		}else if(opcao == 4){
			printf("\nSaindo...\n");
			printf("\n********************************************************\n");
			printf("*                                                      *\n");
			printf("*                   SISTEMA ENCERRADO                  *\n");	
			printf("*                                                      *\n");
			printf("********************************************************\n");
			return sair;	
		}else{
			printf("\nOpcao invalida!\n\n");
			printf("Redirecionando para o menu inicial...\n\n");
		}
	}while(1);	
}

int menuPrincipal(){
	int menu = 0, opcao = 0;
	
	while(menu != 5){
		printf("\n********************************************************\n");
		printf("*                                                      *\n");
		printf("*             BEM-VINDO AO MENU PRINCIPAL              *\n");
		printf("*                                                      *\n");
		printf("********************************************************\n\n");
		printf("Escolhas disponiveis:\n\n");
		printf("1 - Pessoal\n2 - Financeiro\n3 - Academico\n4 - Utilidades\n5 - Voltar para o menu inicial(logout)\n\nEscolha: ");
		scanf("%d", &menu);

		switch(menu){		
			case 1:
				printf("\n********************************************************\n");
	    		printf("*                                                      *\n");
	    		printf("*                     MODULO PESSOAL                   *\n");	
	    		printf("*                                                      *\n");
	    		printf("********************************************************\n\n");
	    		
				while(opcao != 3){		
	    			int idade;
	  				float peso, altura, imc;
	  				
					printf("Digite um numero correspondente:\n\n1 - Ver situacao de voto\n2 - Calcular IMC\n3 - Voltar ao menu principal\n\nEscolha: ");
					scanf("%d", &opcao);
					
					switch(opcao){
						case 1:
							printf("\nDigite a sua idade: ");
	  						scanf("%d", &idade);
	  						if(idade >= 18 && idade <= 69){
	    					printf("\nResultado --> Seu voto e obrigatorio!\n\n");
	  						}else if(idade >= 16){
	    					printf("\nResultado --> Seu voto e opcional!\n\n");
	  						}else{
	    					printf("\nResultado --> Voce nao pode votar!\n\n");
	  						}
	  						break;
	  					case 2:	
	  						printf("\nDigite seu peso(Kg): ");
	  						scanf("%f", &peso);	
	  						printf("Digite sua altura(m): ");
	  						scanf("%f", &altura);
	  						altura = altura * altura;
	  						imc = peso / altura;
	  						printf("\nResultado --> IMC = %.2f\n\n", imc);
	  						break;
	  					case 3:
						  printf("\nVoltando...\n");
						  break;	
	  					default:
						  printf("\nOpcao invalida!\n\n");	
					}
				}
				opcao = 0;
    			break;	
			case 2:
				printf("\n********************************************************\n");
	    		printf("*                                                      *\n");
	    		printf("*                   MODULO FINANCEIRO                  *\n");	
	    		printf("*                                                      *\n");
	    		printf("********************************************************\n\n");
	    		
				while(opcao != 4){	
					float sal_mes, sal_ano, diaria, receita_periodo, valor_conver, conver_dolar, conver_euro;
					int dias_trabalhados;
					
					printf("Digite um numero correspondente:\n\n1 - Calcular salario anual\n2 - Calcular receita do periodo\n3 - Converter reais em dolares e euros\n4 - Voltar ao menu principal\n\nEscolha: ");
					scanf("%d", &opcao);
					switch(opcao){
						case 1:
							printf("\nDigite quanto voce ganha por mes: ");
							scanf("%f", &sal_mes);
							sal_ano = sal_mes * 12;
							printf("\nResultado --> Voce ganha %.2f por ano\n\n", sal_ano);
							break;
						case 2:
							printf("\nDigite quantos dias voce trabalhou neste periodo: ");	
							scanf("%d", &dias_trabalhados);
							printf("Digite o preco da sua diaria: ");
							scanf("%f", &diaria);
							receita_periodo = dias_trabalhados * diaria;
							printf("\nResultado --> Receita do periodo = %.2f\n\n", receita_periodo);
							break;
						case 3:
							printf("\nDigite o valor que voce quer converter: ");
							scanf("%f", &valor_conver);
							conver_dolar = valor_conver / dolar;
							conver_euro = valor_conver / euro;
							printf("\nResultado --> %.2f reais = %.2f dolares = %.2f euros\n\n", valor_conver, conver_dolar, conver_euro);	
							break;
						case 4:
							printf("\nVoltando...\n");
							break;	
						default:
							printf("\nOpcao invalida!\n\n");	
					}
				}
				opcao = 0; 			
    			break;
			case 3:
    			printf("\n********************************************************\n");
    			printf("*                                                      *\n");
    			printf("*                    MODULO ACADEMICO                  *\n");	
    			printf("*                                                      *\n");
    			printf("********************************************************\n\n");
    			
				while(opcao != 2){
					float n1, n2, n3, n4, soma, media, d_media;
					
					printf("Digite um numero correspondente:\n\n1 - Calcular media de quatro notas\n2 - Voltar ao menu principal\n\nEscolha: ");
					scanf("%d", &opcao);
					
					switch(opcao){
						case 1:
							printf("\nDigite a primeira nota: ");
			  				scanf("%f", &n1);
			 				printf("Digite a segunda nota: ");
			  				scanf("%f", &n2);
			  				printf("Digite a terceira nota: ");
			  				scanf("%f", &n3);
			  				printf("Digite a quarta nota: ");
			  				scanf("%f", &n4);
			  				soma = n1 + n2 + n3 + n4;
			  				media = soma / 4;
			  				d_media = media * 2;
			
			  				if(media >= 7){
			    				printf("\nResultado --> Aprovado! Sua media foi: %.2f e o dobro da sua media foi: %.2f.\n\n", media, d_media);
			  				}else if(media >= 4){
			    				printf("\nResultado --> Em recuperacao! Sua media foi: %.2f e o dobro da sua media foi: %.2f.\n\n", media, d_media);
			  				}else{
			    				printf("\nResultado --> Reprovado! Sua media foi: %.2f e o dobro da sua media foi: %.2f.\n\n", media, d_media);
			  				}
			  				break;
			  			case 2:
						  printf("\nVoltando...\n");
						  break;
						default:
							printf("\nOpcao invalida!\n\n");  	
					}
				}
				opcao = 0;		
    			break;    
			case 4:
    			printf("\n********************************************************\n");
    			printf("*                                                      *\n");
    			printf("*                   MODULO UTILIDADES                  *\n");	
    			printf("*                                                      *\n");
    			printf("********************************************************\n\n");

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
						break;
				case 5:
					printf("\nVoltando...\n\n");
						return menuinicial;	
					default:
						printf("\nOpcao invalida!\n\n");
			}
		}
	}


	int main() {
		int retorno_menus = 0;
		
		while(1){
			FILE *p_dadosdousuario = fopen("dadosdousuario.txt", "r");
			
			if(p_dadosdousuario == NULL){
				retorno_menus = menuCriacao();
			}else{
				fclose(p_dadosdousuario);
				retorno_menus = menuInicial();
			}
	
			if(retorno_menus == menuprincipal){
				retorno_menus = menuPrincipal();
			}
			
			if(retorno_menus == menucriacao){
				continue;
			}else if(retorno_menus == menuinicial){
				continue;
			}else if(retorno_menus == sair){
				break;
			}
		}
		
		system("pause");
		return 0;
	}










