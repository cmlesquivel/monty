#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *archivo;
	char caracteres[100];

	if (argc > 1)
	{
		archivo = fopen(argv[1],"r");

		if (archivo == NULL)
		{
			printf("Error lectura");
			exit(1);
		}
		else
		{
			printf("\nEl contenido del archivo de prueba es \n\n");
			while (feof(archivo) == 0)
			{
				fgets(caracteres,100,archivo);
				printf("%s",caracteres);
			}
			system("PAUSE");
		}
		fclose(archivo);
	}
	else
	{
		printf("Error");
	}
}
