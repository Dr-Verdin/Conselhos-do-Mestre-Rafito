#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void policia(char* invasor, char* file);

void policia(char* invasor, char* file){
	FILE *fp;
	int tam1, tam2;
	char *buffer;

	fp = fopen(file, "rb");
	if(fp == NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	tam1 = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	buffer = (char*)malloc(tam1 + 1);
		if(buffer == NULL){
			printf("Erro na alocação de memória\n");
			exit(1);
		}

	fread(buffer, 1, tam1, fp);
	buffer[tam1] = '\0';

	fclose(fp);

	tam2 = strlen(invasor);

	fp = fopen("gojosaturo.bin", "wb");

	for(int i = 0; i <= tam1; i++){
		if(strncmp(buffer + i, invasor, tam2) == 0){
			i += tam2;

			if(buffer[i+1] == ' '){
				i++;
			}
		}
		fprintf(fp, "%c", buffer[i]);
	}

	free(buffer);
}


int main(void){
	char *p, *invasor;
	char file[20];

	p = (char*)malloc(sizeof(char)*100);
	scanf(" %s", p);
	invasor = (char*)malloc(sizeof(char)*(strlen(p)+1));
	strcpy(invasor, p);
	free(p);

	scanf(" %s", file);

	policia(invasor, file);

	free(invasor);

return 0;
}