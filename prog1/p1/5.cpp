#include<stdio.h>
#include<math.h>

int main()
{
	int A=2, B=7, L=1;
	float C=3.5;
	
	if(!((5!=10/2) || L && 2 - 5 > 5 - 2 || L) || (!L || L && sqrt(A+B)>=C) || ( (float)B/A == C || B/A > C))
	{
		printf("verdadeiro");
	}
	else
	{
		printf("falso")	;
	}

}

