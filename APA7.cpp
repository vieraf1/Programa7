#include "iostream"
#include "cstdlib"
#include "math.h"
#include "conio.h"
#include "windows.h" 
#include "string"
#include <iomanip>
using namespace std;

struct cliente 
{
	string nome;
	string cpf;
	string rg;
	int idade;
	string nascimento;
	double salario;
	string rua; 
	int nume;
	string bairro;
	string cidade;
	string estado;
};
struct cliente cad[10];

void armazenar(int novalinha, string no, string cp, string g, int idad, string nas, double sa, string r, int numero, string ba, string ci, string es)
{
	cad[novalinha].nome = no;
	cad[novalinha].cpf = cp;
	cad[novalinha].rg = g;
	cad[novalinha].idade = idad;
	cad[novalinha].nascimento = nas;
	cad[novalinha].salario = sa;
	cad[novalinha].rua = r;
	cad[novalinha].nume = numero;
	cad[novalinha].bairro = ba;
	cad[novalinha].cidade = ci;
	cad[novalinha].estado = es;
}

void exibir(int novalinha)
{
	system("cls");
	setlocale (LC_ALL, "portuguese");
	
	cout <<"\n   Nome  -    CPF   -    RG    -  Idade  -  Data de Nascimento  -  Salário  -  Nome da Rua  -  Número da Casa  -  Bairro  -  Cidade  -  Estado" << endl;
	
	for(int i=0; i <= novalinha; i++)
    cout <<"\n" << cad[i].nome << " - " << cad[i].cpf << " - " << cad[i].rg << " - " << cad[i].idade << " - " << cad[i].nascimento << " - " << cad[i].salario << " - " << cad[i].rua << " - " << cad[i].nume << " - " << cad[i].bairro << " - " << cad[i].cidade << " - " << cad[i].estado << endl;
    
    cout << "\n\n";
	system("pause");
}


void excluir(int line)
{
	string comparador;
	int validador = 0;
	int pos[10];
	int po = 0;
	int j = 0;
	
	system("cls");
	cout << "\nDigite o CPF(com pontos e traços) a ser procurado: " << endl;
	cin >> comparador;
	
	for (int i=0; i<=line; i ++)
	{
		if (cad[i].cpf == comparador)
		{
			validador = 1;
			pos[po] = i; 
			po ++;
		}
	}
	
	if (validador == 1)
	{
	   po = po - 1;
	   for (j=0; j <= po; j ++)
	   {
	   cad[pos[j]].nome = '\0';
	   cad[pos[j]].cpf = '\0';
	   cad[pos[j]].rg = '\0';
	   cad[pos[j]].idade = 0;
	   cad[pos[j]].nascimento = '\0';
	   cad[pos[j]].salario = 0.0;
	   cad[pos[j]].rua = '\0';
	   cad[pos[j]].nume = 0;
	   cad[pos[j]].bairro = '\0';
	   cad[pos[j]].cidade = '\0';
	   cad[pos[j]].estado = '\0';
	   
	   
	   cout << "\n Linha excluída";
	  }
	}
	else
	{
		cout << "\nNão foi encontrado nenhum registro com o CPF digitado.";
	}
	    cout << "\n";
	    system("pause");
}

void consultar(int line)
{
	string comparador;
	int validador = 0;
	int pos[10];
	int po = 0;
	
	system("cls");
	cout << "\nDigite o CPF(com pontos e traços) a ser procurado: " << endl;
	cin >> comparador;
	
	for (int i = 0; i <= line; i++)
	{
		if (cad[i].cpf == comparador)
		{
			validador = 1;
			pos[po] = i; 
			po ++;
		}
	}
	
	if (validador == 1)
	{
	   po = po - 1;
	   for (int j = 0; j <= po; j++)
	   cout <<"\n" << cad[pos[j]].nome << " - " << cad[pos[j]].cpf << " - " << cad[pos[j]].rg << " - " << cad[pos[j]].idade << " - " << cad[pos[j]].nascimento << " - " << cad[pos[j]].salario << " - " << cad[pos[j]].rua << " - " << cad[pos[j]].nume << " - " << cad[pos[j]].bairro << " - " << cad[pos[j]].cidade << " - " << cad[pos[j]].estado << endl;	
		
	}
	else
	{
		cout << "\nNão foi encontrado nenhum registro com o CPF digitado.";
	}
	    cout << "\n";
	    system("pause");
}

void alterar(int line)
{
	string comparador;
	string novo;
	int validador = 0;
	int pos = 0;
	int i = 0;
	
	system("cls");
	cout << "\nDigite o Nome Completo a ser procurado: " << endl;
	cin >> comparador;
	
	while (validador == 0)
	{
	for (i = 0; i <= line; i++)
	{
		if (cad[i].nome == comparador)
		{
		    pos = i;
			validador = 1;
		}
	}
	   if(line < i && validador != 1)
	   {
	   	validador = 2;
	   }
    }
	
	if (validador == 1)
	{
	   cout << "\nDigite o nome a ser armazenado no lugar do antigo: " << endl;
	   cin.ignore();
	   getline(cin,novo);
	   cad[pos].nome = novo; 
	   cout << "\n\nTroca de valores feita!";
	}
	else
	{
		cout << "\nNão foi encontrado nenhum registro com o Nome digitado.";
	}
	    cout << "\n";
	    system("pause");
}

int menu()
{
	     int tecla;
         system("cls");
	     cout << "\n**Tela Inicial**\n";
         cout << "\n1 - Inserir";
         cout << "\n2 - Consultar por CPF";
         cout << "\n3 - Excluir linha por CPF";
         cout << "\n4 - Alterar Nome";
         cout << "\n5 - Exibir Tabela";
         cout << "\n6 - Sair \n" << endl;
         cin >> tecla;
		  
return tecla;}

int contmenu()
{
	int tecla = 0, linha = -1;
	string nom, RG, CPF, data, ru;
	string bai, cid, est;
	int ida, num;
	double sal;
	while (tecla != 6)
	{
		 tecla = menu(); 
		 
		 switch(tecla)
		 {
		 	case 1:
		 	    {
		 	    	 system("cls");
		 	    	 cin.ignore();
		 	    	 
		 	    	 cout << "\nDigite o seu nome: ";
		 	    	 getline(cin,nom);
		 	    	 
		 	    	 cout << "\nDigite o seu CPF, incluindo pontos e traços: ";
		 	    	 cin >> CPF;
		 	    	 
		 	    	 cout << "\nDigite o seu RG, incluindo pontos e traços: ";
		 	    	 cin >> RG;
		 	    	
					 cout << "\nDigite a sua idade: ";
					 cin >> ida;
					 
					 cout << "\nDigite sua data de nascimento, com as barras e apenas dois digitos no ano: ";
					 cin >> data; 
					 
					 cout << "\nDigite o seu salário(usar ponto no lugar da vírgula): ";
					 cin >> sal; 
					 
					 cout << "\nDigite o nome da rua que você mora: ";
		 	    	 cin >> ru;
		 	    	 
		 	    	 cout << "\nDigite o número da casa que você mora: ";
		 	    	 cin >> num;
		 	    	 
		 	    	 cin.ignore();
		 	    	 cout << "\nDigite o nome do bairro que você mora: ";
		 	         getline(cin,bai);	 
		 	    	 
		 	    	 cout << "\nDigite o nome da cidade que você mora: ";
		 	         getline(cin,cid);
		 	    	 
		 	    	 cout << "\nDigite o nome do estado que você mora: ";
		 	         getline(cin,est);
					 
					 cout << "\n";
					 linha ++;
					 armazenar(linha, nom, CPF, RG, ida, data, sal, ru, num, bai, cid, est);
			         break;
			    }
			
			case 2:
				{
					if (linha >= 0)
					{
						consultar(linha);
					}
					break;
				}
			case 3:
				{
					if (linha >= 0)
					{
					    excluir(linha);	
					}
					break;
				}
			case 4:
				{
					if (linha >= 0)
					{
						alterar(linha);
					}
					break;
				}
			case 5:
				{
					if (linha >= 0)
					{
					   exibir(linha);
					}
					break;
				}	
		 }
	}
return 0;}

int main()
{
	setlocale (LC_ALL, "portuguese");
	contmenu();

return 0;}
