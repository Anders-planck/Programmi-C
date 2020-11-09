#include<stdio.h>
#include <string.h>
#define dim 256

main() {
	int i = 0;

	int cont[26];
	char copy[dim];
	
	for (i = 0; i < 26; i++)
		cont[i] = 0;
	printf("inserire una parola");
	scanf("%s", copy);
	i = 0;
	while (copy[i] != '\0')
	{
		cont[copy[i] - 'a']++;
		i++;
	}
	for (i = 'a'; i <= 'z'; i++)
		printf("%c", i);
	printf("\n");
	for (i = 0; i < 26; i++)
		printf("%d", cont[i]);








}
