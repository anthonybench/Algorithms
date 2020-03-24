//================================================
//================================================
// Variable/Printing Tools
// tools.c
//================================================
//================================================
#include "main.h"

// prints white space
void space(int n)
{
    for (int i = 0; i < n; ++i)
        printf("\n");
}

// prints border
void border(char c)
{
    if (tolower(c) == 's')
        printf("=========\n");
    else if (tolower(c) == 'm')
        printf("===================\n");
    else if (tolower(c) == 'l')
        printf("==================================================\n");
    else if (tolower(c) == 'd')
    {
        printf("==================================================\n");
        printf("==================================================\n");
    }
}

/*IMPORTANT: CALL THIS FUNCTION ONCE AT THE START OF THE PROGRAM!*/
/*INITIALIZAES THE RANDOM NUMBER GENERATOR*/
void InitRandom(void)
{
	time_t timestr;

#ifdef _DEBUG
	timestr = 0;
#else
	time(&timestr);
#endif

	srand((unsigned int)timestr);
}

/*RETURNS A RANDOM UNSIGNED INTEGER IN THE INTERVAL [MINVAL,MAXVAL]*/
unsigned int GetRandom(unsigned int minval, unsigned int maxval)
{
	char temp[sizeof(int)];
	int* val;
	int i;
	

	val = (int*)temp;

	for (i = 0; i < sizeof(unsigned int); i++)
	{
		temp[i] = rand() & 0xFF;
	}

	*val = ((*val) % (maxval - minval + 1)) + minval;
	assert((*val <= maxval) && (*val >= minval));
	return  *val;
}

