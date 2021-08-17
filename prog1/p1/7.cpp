#include<stdio.h>

int main()
{
	int n1, n2, n3, min, meio, max;
	printf("DIGITE TRES NUMEROS: ");
	scanf("%d %d %d", &n1, &n2, &n3);
	if(n1>n2)
	{
		if(n2>n3)
		{
			max=n1;
			meio=n2;
			min=n3;
		}
		else
		{
			max=n3;
			meio=n2;
			min=n1;
		}
	}
	else
	{
		if(n1>n3)
		{
			max=n1;
			meio=n2;
			min=n3;
		}
		else
		{
			max=n3;
			meio=n2;
			min=n1;
		}
	}
	printf("%d %d %d", max, meio, min);
	return 0;
}
