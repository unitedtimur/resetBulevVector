#include <cstdio>
#include <cstdlib>
#include <cstring>

/*-----Scan-----*/
unsigned int ScanfBV(int *n){
	char s[33];
	int i = 0;
	unsigned int Vector = 0, mask = 1;
	gets(s);
	*n = strlen(s);
	for (i = 0; i < *n && s[i]; i++){
		Vector <<= 1;
		if (s[i] == '1') Vector |= mask;

	}
	return Vector;
}

/*-----Print-----*/
void PrintBV(unsigned int Vector, int *n){
	unsigned int mask = 1;
	int i;
	for (i = 0, mask <<= *n - 1; i < *n; i++, mask >>= 1){
		if (mask & Vector) putchar('1');
		else putchar('0');
	}

	printf("\n");
}

int main()
{
	int *n = new int;
	int m, k;
	int i;
	printf("Enter a 'm' and 'n', please: ");
	scanf("%d%d", &m, n);
	getchar();

	unsigned int *bm = new unsigned int[m];

	printf("Enter an elements of Matrix, please:\n");

	for (i = 0; i < m; i++)
	{
		bm[i] = ScanfBV(n);
	}

	printf("Our Matrix\n");
	for (i = 0; i < m; i++)
	{
		PrintBV(bm[i], n);
	}

	/*-----Program-----*/
	printf("Enter a number column, please: ");
	scanf("%u", &k);

	for (int i = 0; i < m; i++){
        unsigned int mask = 1;
        for(int j = 0; j < k; j++, mask <<= 1)
        bm[i] &= ~mask;
	}

    printf("\nRESULT\n");
    for (i = 0; i < m; i++)
	{
		PrintBV(bm[i], n);
	}

	system("PAUSE");
}



