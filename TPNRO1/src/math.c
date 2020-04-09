/*
 * math.c
 *
 *  Created on: 31 mar. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

float sumar (float a,float b)
{
	return a + b;
}

float resta (float a,float b)
{
	return a - b;
}

float multiplicar (float a,float b)
{
	return a * b;
}

float division (float a,float b)
{
	return a / b;
}

int factorial (int z)
{
    int factorial = 1;
    int i;

    for(i = 1; i <= z;i++)
    {
        factorial = factorial * i;
    }

    return factorial;
}
