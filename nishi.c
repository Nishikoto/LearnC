#include <stdlib.h>
#include <stdio.h>
#include "nishi.h"

static int quse()
{
	return 47;
}

void koto()
{
	//int res = quse();
	printf("Coucou %d :D", quse());
}