#include<stdio.h>
#include<string.h>

int  jolly_match(char a[], char b[],int n,int m) {
	int i,j;
	int f = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i] == b[i] && i==j) {
				f = 1;
			}
			else
				f = 0;
		}
	}
	return f;
}

main() {
	char a[40], b[40];
	int n;
	int m;
	int o;
	printf("inizia da a\n");
	scanf("%s", a);
	scanf("%s", b);
	n=strlen(a);
	m = strlen(b);
	o = jolly_match(a, b,n,m);
	if (o == 1) {
		printf("vabeh");
	}
	else
		printf("non vabeh");
}