
#include <stdio.h>
#include <string.h>
#define MAX_LEN 200
int an1[MAX_LEN+10];
int an2[MAX_LEN+10];
char szLine1[MAX_LEN+10];
char szLine2[MAX_LEN+10];
int main()
{
	scanf("%s", szLine1);
	scanf("%s", szLine2);
	int i, j;

	//The library function memeset sets the sizeof(an1) byte content starting at address an1 to 0.
	//The value of sizeof(an1) is the length of an1
	//The memset function is declared in string.h
	memset( an1, 0, sizeof(an1));
	memset( an2, 0, sizeof(an2));

	//Next, convert the integer in the form of a string stored in szLine1 to an1.
	//An1[0] corresponds to a single digit
	int nLen1 = strlen( szLine1);
	j = 0;
	for( i = nLen1 - 1;i >= 0 ; i --)
		an1[j++] = szLine1[i] - '0';

	int nLen2 = strlen(szLine2);
	j = 0;
	for( i = nLen2 - 1;i >= 0 ; i --)
		an2[j++] = szLine2[i] - '0';

	for( i = 0;i < MAX_LEN ; i ++ ) {
		an1[i] += an2[i];//Add bit by bit
		if( an1[i] >= 10 ) {//See if you want to carry in
			an1[i] -= 10;
			an1[i+1] ++;/carry
		}
	}

	bool bStartOutput = false;//This variable is used to skip the extra 0
	for( i = MAX_LEN; i >= 0; i -- ) {
		if( bStartOutput)
			printf("%d", an1[i]);//If the extra 0 has been skipped, the output
		else if( an1[i] ) {
			printf("%d", an1[i]);
			bStartOutput = true;//When you encounter the first non-zero value, it means that the extra 0 has been skipped.
		}
	}
	if(! bStartOutput )
		printf("0");
	return 0;
}
