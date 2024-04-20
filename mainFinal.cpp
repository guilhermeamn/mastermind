#include "pino.h"
#include "Bola.h"
#include "Jogo.h"
#include "JogoX1.h"
#include <string>
#include <limits>
#include "lista.h"

using namespace std;

//FUNCOES AUXILIARES (descricao abaixo)
void retira(Lista <string> &l1, int cores_utilizadas);
void menu(int &comando, int &tipo_jogo, int &cores_utilizadas, int &tamanho_codigo, int &qnt_palpite, Lista <string> &l1);
//---------------------------------------------------------------------



//PROGRAMA PRINCIPAL
int main(){

  //SETANDO OS COMANDOS QUE SERAO UTILIZADOS NO JOGO
  int comando = 0, tipo_jogo = 0, cores_utilizadas = 0, tamanho_codigo = 0, qnt_palpite = 0;
  Lista <string> l1;

  //MENU
  menu(comando,tipo_jogo,cores_utilizadas,tamanho_codigo,qnt_palpite,l1);

  //MODO JOGADOR VS COM
  if(tipo_jogo == 1){

    system("clear");

    //IMPRIME AS CORES DISPONIVEIS PARA O JOGO
    cout << "----------------------------------------------------------";
    cout << "\nCores disponiveis: \n";
    l1.imprime();
    cout << "\n----------------------------------------------------------\n";

    //CRIA UM OBJETO DE JOGO
    Jogo <int> jogo1(tamanho_codigo,qnt_palpite);

    //COM CORES REPETIDAS
    if(comando == 1){
            jogo1.jogar_com_cores_repetidas(cores_utilizadas,tamanho_codigo,l1);
    }

    //SEM CORES REPETIDAS
    else{
            jogo1.jogar_sem_cores_repetidas(cores_utilizadas,tamanho_codigo,l1);
    }

  }

  //MODO JOGADOR VS JOGADOR
  else if(tipo_jogo == 2){

	system("clear");

        //IMPRIME AS CORES DISPONIVEIS NO JOGO
	cout << "----------------------------------------------------------";
	cout << "\nCores disponiveis: \n";
	l1.imprime();
	cout << "\n----------------------------------------------------------\n";

        //CRIA UM OBJETO DE JOGOX1
	JogoX1 <int> jogo1(tamanho_codigo,qnt_palpite);

        //COM CORES REPETIDAS
	if(comando == 1){
		jogo1.jogar_com_cores_repetidas(cores_utilizadas,tamanho_codigo,l1);
	}

	//SEM CORES REPETIDAS
	else{
		jogo1.jogar_sem_cores_repetidas(cores_utilizadas,tamanho_codigo,l1);
	}


  }
/*
  //MODO COM VS JOGADOR
  else if (tipo_jogo == 3){
	  cout << "VOCE PERDEU, JORGE MUITO ESPERTO\n";
  }

  //EXTRA
  else if(tipo_jogo == 5){
	  system("telnet towel.blinkenlights.nl");
  }
*/
    else if(tipo_jogo == 4){
        //SAIR
    }

  return 0;

}
//------------------------------------------------------------------------------------------





/* Retira da lista uma quantidade de (10 - quantidade de cores utilizadas no jogo).
 * PARAMETROS: -Lista;
 *             -Quantidade de cores utilizadas no jogo;
 */
void retira(Lista <string> &l1, int cores_utilizadas){
    int cores = 10 - cores_utilizadas;
    while(cores != 0){
        l1.remove(l1.getCauda());
        cores--;
    }
}

/* Menu com as opçoes de jogo
 * PARAMETROS: -Tipo de jogo (com/sem cores repetidas);
 *             -Quantidade de cores utilizadas;
 *             -Tamanho do codigo;
 *             -Quantidade de palpites;
 *             -Lista com as cores;
 */
void menu(int &comando, int &tipo_jogo, int &cores_utilizadas, int &tamanho_codigo, int &qnt_palpite, Lista <string> &l1){

	//--------- INICIALIZA AS CORES NA LISTA --------
	l1.insere_proximo(l1.getCauda(),"Azul");
	l1.insere_proximo(l1.getCauda(),"Vermelho");
	l1.insere_proximo(l1.getCauda(),"Verde");
	l1.insere_proximo(l1.getCauda(),"Preto");
	l1.insere_proximo(l1.getCauda(),"Amarelo");
	l1.insere_proximo(l1.getCauda(),"Laranja");
	l1.insere_proximo(l1.getCauda(),"Branco");
	l1.insere_proximo(l1.getCauda(),"Roxo");
	l1.insere_proximo(l1.getCauda(),"Marrom");
	l1.insere_proximo(l1.getCauda(),"Cinza");
	//------------------------------------------------
        
        //MENU COM AS OPCOES
	while(tipo_jogo == 0){
            system("clear");
            system("toilet -f pagga     Master Mind");  //FORMATACAO DO TITULO
            cout		<< "\n\n|-------- #1 - Jogo Normal (Jogador X COM) --------|\n"
				<< "|-------- #2 - Dois Jogadores              --------|\n"
				<< "|-------- #3 - Regras                      --------|\n"
				<< "|-------- #4 - Sair                        --------|\n"
				<< endl;
            cout << "\nInsira seu comando: ";
            
            //VERIFICA COMANDO
	    while(!(cin >> tipo_jogo) || tipo_jogo<=0 || tipo_jogo>4){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Comando Incorreto. Tente novamente:" << endl;
	    }

	    //REGRAS
	    if(tipo_jogo == 3){
	      system("clear");
	      cout << "\nNo MasterMind o jogador enfrentara a tarefa de encontrar por meio de logica uma sequencia pre-estabelecida." <<
	      "\nA cada rodada, o jogador podera realizar um chute de uma sequencia de cores a sua escolha, a quantidade e variedade de cores depende da dificuldade." <<
	      "\nA cada chute, e recebido outra sequencia de cores como resposta a sua tentativa, nessa sequencia:\n" <<
	      "\n   Preto - Cor e posicao corretos.\n   Branco - Cor certa, posicao errada.\n   Cinza - Cor e posicao errados." <<
	      "\n\nNo jogo normal, o jogador deve tentar acertar uma sequencia aleatoria gerada pelo computador de acordo com o nivel de dificuldade escolhido:" <<
        "\n Na dificuldade facil, sao 4 cores utilizadas em um codigo de 4 cores com 10 chances de chute, sem repetir cor." <<
        "\n Na dificuldade normal, sao 7 cores utilizadas em um codigo de 5 cores com 7 chances de chute, sem repetir cor." <<
        "\n Na dificuldade dificil, sao 10 cores utilizadas em um codigo de 6 cores com 4 chances de chute, com cores repetidas." <<
        "\n No Personalizado, o jogador escolhe a quantidade de cores, o tamanho do codigo, a quantidade de chutes e se tera ou nao cores repetidas." <<
        "\n O jogador ganha se acertar o codigo antes de acabarem seu chutes."
	      "\n\nNo modo dois jogadores, um jogador escolhe a sequencia, enquanto o outro tenta acertar:" <<
        "\n O jogador 1, que escolheu a sequencia, deve ir nos arquivos do jogo e por sua resposta no documento (resposta.txt) antes de compilar." <<
        "\n O jogador 2, que esta tentando acertar, entra com seu chute, e logo o jogador 1 deve digitar Preto, Branco ou Cinza de acordo com seus significados antes explicados." <<
        "\n O jogador 1 ganha se o jogador 2 esgotar suas tentativas, mas caso o jogador 2 acerte a sequencia ele ganha"
        "\n\nATENCAO: Para funcionamento total as cores entradas tem que ser escritas do mesmo jeito que forem apresentadas, com a inicial maiuscula." <<
        "\n E tambem devem ser entradas uma cor por linha." << endl;
	      cout << "\n               Para voltar, pressione 0."<< endl;


              //VERIFICA COMANDO
              while(!(cin >> tipo_jogo) || tipo_jogo!= 0){
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  cout << "COMANDO INCORRETO. Tente novamente:" << endl;
              }
          }
        }

        system("clear"); //limpa o terminal


        //MODO JOGADOR VS COM
        if(tipo_jogo==1){
            cout << "\n\nEscolha a dificuldade desejada:\n#1 - Facil\n#2 - Normal\n#3 - Dificil\n#4 - Personalizado\n" << endl;
            //VERIFICA COMANDO
            while(!(cin >> comando) || comando<=0 || comando>4){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "COMANDO INCORRETO. Tente novamente:" << endl;
            }

	    //FACIL
	    if(comando == 1){
	      cores_utilizadas = 4;
	      retira(l1,cores_utilizadas);
	      tamanho_codigo = 4;
	      qnt_palpite = 10;
	      comando = 0; //sem cores repetidas
	    }
	    //NORMAL
	    else if(comando == 2){
	      cores_utilizadas = 7;
	      retira(l1,cores_utilizadas);
	      tamanho_codigo = 5;
	      qnt_palpite = 7;
	      comando = 0; //sem cores repetidas
	    }
	    //DIFICIL
	    else if(comando == 3){
	      cores_utilizadas = 10;
	      retira(l1,cores_utilizadas);
	      tamanho_codigo = 6;
	      qnt_palpite = 4;
	      comando = 1; //com cores repetidas
	    }
	    //PERSONALIZADO
	    else{

                system("clear");

                //ESCOLHER SE HA CORES REPETIDAS OU NAO
                cout << "\nCores repetidas? \n#1 - sim\n#0 - nao  \n";
                //VERIFICA COMANDO
                while(!(cin >> comando) || (comando != 0 && comando!=1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalido. Tente novamente:" << endl;
                }

	    	system("clear");

                //ESCOLHER O NUMERO DE CORES
	    	cout << "\nEscolha o número de cores (4~10): ";
                //VERIFICA COMANDO
                while(!(cin >> cores_utilizadas) || cores_utilizadas<4 || cores_utilizadas>10){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalido. Tente novamente:" << endl;
                }
        	
        	retira(l1,cores_utilizadas);

	    	system("clear");

                //ESCOLHER O TAMANHO DO CODIGO
                cout << "\nTamanho do codigo (4~6): ";
                //VERIFICA COMANDO
                while(!(cin >> tamanho_codigo) || tamanho_codigo<4 || tamanho_codigo>6 || (comando == 0 && tamanho_codigo > cores_utilizadas)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalido. Tente novamente (Caso não haja cores repetidas, o tamanho do código não pode ser menor que a quantidade de cores escolhidas anteriormente):" << endl;
                }

                system("clear");

                //ESCOLHER NUMERO MAXIMO DE PALPITES
                cout << "\nNumero maximo de palpites (4~10): ";
                //VERIFICA COMANDO
                while(!(cin >> qnt_palpite) || qnt_palpite<4 || qnt_palpite>10){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalido. Tente novamente:" << endl;
                }


            }
	  }
	  

	  //MODO JOGADOR VS JOGADOR
	  else if(tipo_jogo == 2){

          //ESCOLHER O NUMERO DE CORES
          cout << "\nEscolha o número de cores (4~10): ";
          //VERIFICA COMANDO
          while(!(cin >> cores_utilizadas) || cores_utilizadas<4 || cores_utilizadas>10){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalido. Tente novamente:" << endl;
          }
          
      	  retira(l1,cores_utilizadas);

          system("clear");

          //ESCOLHER TAMANHO DO CODIGO
          cout << "\nTamanho do codigo (4~6): ";  
          //VERIFICA COMANDO
          while(!(cin >> tamanho_codigo) || tamanho_codigo<4 || tamanho_codigo>6){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalido. Tente novamente:" << endl;
          }

          system("clear");

          //ESCOLHER NUMERO MAXIMO DE PALPITES
          cout << "\nNumero maximo de palpites (4~10): ";
          //VERIFICA COMANDO
          while(!(cin >> qnt_palpite) || qnt_palpite<4 || qnt_palpite>10){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalido. Tente novamente:" << endl;
          }

          system("clear");

          //ESCOLHER SE QUER CORES REPETIDAS OU NAO
          cout << "\nCores repetidas? \n#1 - sim\n#0 - nao  \n";
          //VERIFICA COMANDO
          while(!(cin >> comando) || (comando != 0 && comando!=1)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalido. Tente novamente:" << endl;
          }
    }
}
