// AP16DB_TRF1_FLopesSBalduino.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "locale.h"
#include "windows.h"

// application procedures - calling
void menu();
void vendabilhete();
void preco(float p1novo, float p2novo);
void carruagemc1(int a[][14]);
void estatisticasc1(int a[][14]);
void carruagemc2(int b[][14]);
void estatisticasc2(int a[][14]);

// terminal colors
void normal();
void cyan();
void vermelho();
void branco();

// global variables
float precoc1 = 5, precoc2 = 3; //default prices for c1 and c2
int i, j;

// c1 = railway carriage of class 1
// c2 = railway carriage of class 2
int c1[4][14] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
int c2[4][14] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

void main()
{
	setlocale(LC_ALL, "Portuguese");
	preco(precoc1, precoc2);
}

// the application starts with default prices
// and asks the operator if he wants to change them to new ones
void preco(float p1novo, float p2novo)
{
	int mudarpreco;

	cyan();
	printf("\n####################################################");
	printf("\n#####");
	normal();
	printf("	  ALTERAÇÃO DO PREÇO DOS BILHETES      ");
	cyan();
	printf("#####");
	printf("\n####################################################");
	printf("\n#####");
	normal();
	printf("  Deseja alterar os preços dos bilhetes?  ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("                 1 - Sim                  ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("                 2 - Não                  ");
	cyan();
	printf("#####");
	printf("\n####################################################\n");
	normal();

	do
	{
		printf("\nEscreva a opção desejada:   ");
		scanf_s("%d", &mudarpreco);


		if (mudarpreco == 1)
		{
			printf("\nUse vírgulas no caso do novo montante incluir cêntimos! ");
			printf("\n   Introduza o novo preço para a 1ª Classe: ");
			scanf_s("%f", &p1novo);
			printf("   Introduza o novo preço para a 2ª Classe: ");
			scanf_s("%f", &p2novo);
			precoc1 = p1novo;
			precoc2 = p2novo;
			system("cls");
			menu();
		}
		else if (mudarpreco == 2)
		{
			system("cls");
			menu();
		}
	} while (mudarpreco != 1 && mudarpreco != 2);


}

// menu representation 
void menu()
{
	int escolha;

	cyan();
	printf("\n####################################################");
	printf("\n####################################################");
	printf("\n#####");
	normal();
	printf("    BICOMB: Gestão de Venda de Bilhetes   ");
	cyan();
	printf("#####");
	printf("\n####################################################");
	printf("\n####################################################");
	printf("\n#####");
	normal();
	printf("  PREÇOS ESTIPULADOS DESTA VIAGEM         ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("    1ª Classe: %4.2f euros                 ", precoc1);
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("    2ª Classe: %4.2f euros                 ", precoc2);
	cyan();
	printf("#####");
	printf("\n####################################################");
	printf("\n#####");
	normal();
	printf("                                          ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("  [1] Vender Bilhete                      ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("  [2] Consultar carruagens/estatísticas   ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("  [3] Sair                                ");
	cyan();
	printf("#####");
	printf("\n#####");
	normal();
	printf("                                          ");
	cyan();
	printf("#####");
	printf("\n####################################################");
	printf("\n####################################################");
	normal();

	do
	{	// user choice from the menu
		printf("\n\n Escreva a opção desejada:   ");
		scanf_s("%i", &escolha);

		switch (escolha)
		{
		case (1): // selling a ticket
			system("cls");
			vendabilhete();
			break;
		case (2): // checking the railway carriage current status
			
			// representation in the terminal of the c1 and c2
			system("cls");
			printf("______________________________________________________________ ");
			printf("\n ");
			carruagemc1(c1);
			estatisticasc1(c1);

			printf("\n______________________________________________________________ ");
			printf("\n ");
			carruagemc2(c2);
			estatisticasc2(c2);

			// press any key to go back to the main menu
			printf("\n______________________________________________________________ ");
			printf("\nPrima qualquer tecla do teclado para voltar ao menu!");
			system("pause > nul");
			system("cls");
			menu();
			break;
		case (3): // exit
			exit(0);
			break;
		default: // default message: option does not exist
			printf("\nA sua escolha não existe, por favor escolha de novo!\n");
			break;
		}
	} while (escolha != 1 && escolha != 2 && escolha != 3);

//ticket selling
void vendabilhete()
{
	int classepretendida, compraragain;
	char i;

	printf("\nDeseja viajar na Carruagem de Classe: 1 ou 2?   ");
	scanf_s("%d", &classepretendida);

	if (classepretendida == 1)
	{
		system("cls");
		carruagemc1(c1);
		printf("\n\nQual a fila (ABCD) que pretende?   ");
		scanf_s(" %c", &i, 1);
		
		// row A B C D are representations of numbers 1 2 3 4
		// convertion from letters to numbers
		switch (i)
		{
		case 'A':
			i = i - '@';
			break;

		case 'B':
			i = i - '@';
			break;

		case 'C':
			i = i - '@';
			break;

		case 'D':
			i = i - '@';
			break;

		case 'a':
			i = i - '`';
			break;

		case 'b':
			i = i - '`';
			break;

		case 'c':
			i = i - '`';
			break;

		case 'd':
			i = i - '`';
			break;
		}
		printf("Qual o número de lugar que pretende?   ");
		scanf_s("%d", &j);

		// 0 == empty seat and it means it will be sold
		if (c1[(int)i][j] == 0)
		{
			c1[(int)i][j] = 1;
			system("cls");
			printf("\n\tO bilhete foi adquirido com êxito!\n\nDeseja adquirir novamente um bilhete?\n  1-Sim\n  2-Não\n");
			printf("Escreva a opção desejada: ");
			scanf_s("%d", &compraragain);

			// buy again?
			if (compraragain == 1)
			{
				vendabilhete();
			}
			else if (compraragain == 2)
			{
				system("cls");
				menu();
			}

		}

		// 1 == seat taken and it means it will not be possible to sell
		while (c1[(int)i][j] == 1)
		{
			system("cls");
			carruagemc1(c1);
			printf("\n\tO lugar não se encontra livre!\n");
			printf("\n\nQual a fila (ABCD) que pretende?   ");
			scanf_s(" %c", &i, 1);
			
			// row A B C D are representations of numbers 1 2 3 4
			// convertion from letters to numbers
			switch (i)
			{
			case 'A':
				i = i - '@';
				break;

			case 'B':
				i = i - '@';
				break;

			case 'C':
				i = i - '@';
				break;

			case 'D':
				i = i - '@';
				break;

			case 'a':
				i = i - '`';
				break;

			case 'b':
				i = i - '`';
				break;

			case 'c':
				i = i - '`';
				break;

			case 'd':
				i = i - '`';
				break;
			}
			printf("Qual o número de lugar que pretende?   ");
			scanf_s("%d", &j);

			// ticket sold
			if (c1[(int) i][j] == 0)
			{
				c1[(int) i][j] = 1;
				system("cls");
				printf("\n\tO bilhete foi adquirido com êxito!\n\nDeseja adquirir novamente um bilhete?\n  1-Sim\n  2-Não\n");
				printf("Escreva a opção desejada: ");
				scanf_s("%d", &compraragain);

				// buy again?
				if (compraragain == 1)
				{
					vendabilhete();
				}
				else if (compraragain == 2)
				{
					system("cls");
					menu();
				}
			}
		}

	}
	else if (classepretendida == 2)
	{
		system("cls");
		carruagemc2(c2);
		printf("\n\nQual a fila (ABCD) que pretende?   ");
		scanf_s(" %c", &i, 1);
		
		// row A B C D are representations of numbers 1 2 3 4
		// convertion from letters to numbers
		switch (i)
		{
		case 'A':
			i = i - '@';
			break;

		case 'B':
			i = i - '@';
			break;

		case 'C':
			i = i - '@';
			break;

		case 'D':
			i = i - '@';
			break;

		case 'a':
			i = i - '`';
			break;

		case 'b':
			i = i - '`';
			break;

		case 'c':
			i = i - '`';
			break;

		case 'd':
			i = i - '`';
			break;
		}
		printf("Qual o número de lugar que pretende?   ");
		scanf_s("%d", &j);

		if (c2[(int)i][j] == 0)
		{
			c2[(int)i][j] = 1;
			system("cls");
			printf("\n\tO bilhete foi adquirido com êxito!\n\nDeseja adquirir novamente um bilhete?\n  1-Sim\n  2-Não\n");
			printf("Escreva a opção desejada: ");
			scanf_s("%d", &compraragain);

			if (compraragain == 1)
			{
				vendabilhete();
			}
			else if (compraragain == 2)
			{
				system("cls");
				menu();
			}
		}

		while (c2[(int) i][j] == 1)
		{
			system("cls");
			carruagemc2(c2);
			printf("\n\tO lugar não se encontra livre!\n");
			printf("\n\nQual a fila (ABCD) que pretende?   ");
			scanf_s(" %c", &i, 1);

			switch (i)
			{
			case 'A':
				i = i - '@';
				break;

			case 'B':
				i = i - '@';
				break;

			case 'C':
				i = i - '@';
				break;

			case 'D':
				i = i - '@';
				break;

			case 'a':
				i = i - '`';
				break;

			case 'b':
				i = i - '`';
				break;

			case 'c':
				i = i - '`';
				break;

			case 'd':
				i = i - '`';
				break;
			}
			printf("Qual o número de lugar que pretende?   ");
			scanf_s("%d", &j);

			if (c2[(int)i][j] == 0)
			{
				c2[(int)i][j] = 1;
				system("cls");
				printf("\n\tO bilhete foi adquirido com êxito!\n\nDeseja adquirir novamente um bilhete?\n  1-Sim\n  2-Não\n");
				printf("Escreva a opção desejada: ");
				scanf_s("%d", &compraragain);

				if (compraragain == 1)
				{
					vendabilhete();
				}
				else if (compraragain == 2)
				{
					system("cls");
					menu();
				}
			}
		}
	}
}

// visual representation of the railway carriage of class 1
void carruagemc1(int a[][14])
{

	//CARRUAGEM CLASSE 1

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\t\t\tCARRUAGEM 1ª CLASSE\n");
	normal();
	printf("\n ");

	//nº colunas
	printf("       1   2   3   4   5   6   7   8   9   10  11  12  13  14\n");

	printf("   ___________________________________________________________\n");

	// Fila A
	printf("   A  ");

	for (i = 1; i < 2; i++)
	{

		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (a[i][j] == 0)
			{
				branco();
			}
			else if (a[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", a[i][j]);
			normal();
		}
	}
	printf("\n");

	// Fila B
	printf("   B  ");
	for (i = 2; i < 3; i++) {

		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (a[i][j] == 0)
			{
				branco();
			}
			else if (a[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", a[i][j]);
			normal();
		}
	}
	printf("\n");

	//CORREDOR
	printf("      ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_BLUE);
	printf("--------------------------------------------------------");
	normal();
	printf("\n");

	// Fila C
	printf("   C  ");
	for (i = 3; i < 4; i++)
	{
		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (a[i][j] == 0)
			{
				branco();
			}
			else if (a[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", a[i][j]);
			normal();
		}
	}
	printf("\n");

	// Fila D
	printf("   D  ");
	for (i = 4; i < 5; i++)
	{

		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (a[i][j] == 0)
			{
				branco();
			}
			else if (a[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", a[i][j]);
			normal();
		}
	}
}

// visual representation of the railway carriage of class 2
void carruagemc2(int b[][14])
{
	

	// CARRUAGEM CLASSE 2


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("\t\t\tCARRUAGEM 2ª CLASSE\n");
	normal();
	printf("\n ");
	//nº colunas
	printf("       1   2   3   4   5   6   7   8   9   10  11  12  13  14\n");


	printf("   ___________________________________________________________\n");

	// Fila A
	printf("   A  ");
	for (i = 1; i < 2; i++)
	{
		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (b[i][j] == 0)
			{
				branco();
			}
			else if (b[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", b[i][j]);
			normal();
		}
	}
	printf("\n");

	// Fila B
	printf("   B  ");
	for (i = 2; i < 3; i++)
	{
		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (b[i][j] == 0)
			{
				branco();
			}
			else if (b[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", b[i][j]);
			normal();
		}
	}
	printf("\n");

	//CORREDOR
	printf("      ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | FOREGROUND_GREEN);
	printf("--------------------------------------------------------");
	normal();
	printf("\n");

	// Fila C
	printf("   C  ");
	for (i = 3; i < 4; i++)
	{
		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (b[i][j] == 0)
			{
				branco();
			}
			else if (b[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", b[i][j]);
			normal();
		}
	}
	printf("\n");

	// Fila D
	printf("   D  ");
	for (i = 4; i < 5; i++)
	{
		for (j = 1; j < 15; j++)
		{
			//cores dos lugares
			if (b[i][j] == 0)
			{
				branco();
			}
			else if (b[i][j] == 1)
			{
				vermelho();
			}
			printf("  %d ", b[i][j]);

			normal();
		}

	}

}

// statistics of the railway carriage of class 1
void estatisticasc1(int a[][14])
{
	// local variables
	float luglivc1 = 0, lugocuc1 = 0, percbilvenc1 = 0, receita1 = 0;
	
	// empty seats
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 15; j++)
		{
			if (c1[i][j] == 0)
			{
				luglivc1 = luglivc1++;
			}
		}
	}
	printf("\n\nLugares livres: %4.0f", luglivc1);


	// seats taken
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 15; j++)
		{
			if (c1[i][j] == 1)
			{
				lugocuc1 = lugocuc1++;
			}
		}
	}

	// % tickets sold
	percbilvenc1 = lugocuc1 * 100 / 56;
	printf("\nPercentagem de bilhetes vendidos desta carruagem é de %4.2f%%", percbilvenc1);

	// total revenue
	receita1 = precoc1*lugocuc1;
	printf("\nA receita actual é de %4.2f euros", receita1);

}

// statistics of the railway carriage of class 2
void estatisticasc2(int a[][14])
{
	// local variables
	float luglivc2 = 0, lugocuc2 = 0, percbilvenc2 = 0, receita2 = 0;
	
	// empty seats
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 15; j++)
		{
			if (c2[i][j] == 0)
			{
				luglivc2++;
			}
		}
	}
	printf("\n\nLugares livres: %4.0f", luglivc2);
	
	// seats taken
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 15; j++)
		{
			if (c2[i][j] == 1)
			{
				lugocuc2++;
			}
		}
	}

	// % tickets sold
	percbilvenc2 = lugocuc2 * 100 / 56;
	printf("\nPercentagem de bilhetes vendidos desta carruagem é de %4.2f%%", percbilvenc2);


	// total revenue
	receita2 = precoc2*lugocuc2;
	printf("\nA receita actual é de %4.2f euros", receita2);
}

// terminal - default color
void normal()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

// terminal - cyan color
void cyan()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN);
}

// terminal - red color
void vermelho()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_RED);
}

// terminal - white color
void branco()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
}