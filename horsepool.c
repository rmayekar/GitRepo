/* Header files in C library */
#include<stdio.h>
#include<string.h>
#include<conio.h>

/* Function Prototypes */
void hors_pool(char [],char []);

/* Function main() begins program excution and returns an integer value to the operating system */
int main()
{
	char text[1000],pattern[100];
	int i;

	clrscr();

	printf("\nEnter the text: ");
	scanf("%[^\n]",text);

	printf("\nEnter the Pattern: ");
	scanf("%s",pattern);

	/* Calls the function hors_pool() to perform string matching */
	hors_pool(text,pattern);

	getch();

	return 0; /* Incidate successful termination */
}

void hors_pool(char text [],char pattern [])
{
	int m,n,i,j;
	char shift[400];

	n = strlen(text);
	m = strlen(pattern);

	printf("\nText = %d",n);
	printf("\nPattern = %d",m);

	for(i=0;i<n;i++)
	{
		shift[text[i]] = m;
	}

	for(j=0;j<m-1;j++)
	{
		shift[pattern[j]] = m-1-j;
	}

	for(i=m-1; i<n; i = i+shift[text[i]])
	{
		j = 0;

		while(j<m && pattern[m-1-j] == text[i-j])
		{
			++j;
		}

		if(j == m)
		{
			printf("\nPattern found at Position: %d\n",i-m+2);
			return;
		}
	}

	printf("\nPattern not found\n");
}






/*
OUTPUT:

enter text 
i am very happy
enter pattern string 
happy
pattern found at pos 11 

enter text 
i am very happy
enter pattern string 
hi
pattern not found 

*/

