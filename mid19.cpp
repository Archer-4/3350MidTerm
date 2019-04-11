//https://github.com/Archer-4/3350MidTerm
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "data.h"

//type defines
typedef double Flt;
typedef Flt Vec[3];

//prototype
Flt vec_length(Vec v);

//Array of vector values
const Flt arr[] = {
   1.0,   0.0,
   1.0,   1.0,
  -1.2,   2.5,
  99.9,  99.9,
   2.2,  -1.2,
   0.0,   0.0
};

int main(int argc, char *argv[])
{
    //Program to calculate vector normalization and length.
	//
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
#ifndef UNIT_TEST
    printf("     x         y         length \n");
    printf("     --------  --------  ---------- \n");
#endif
#ifdef UNIT_TEST
    printf("     x         y         length      actual\n");
    printf("     --------  --------  ----------  ----------\n");
#endif
    //read until sentinel found.
    int i=0;
#ifndef UNIT_TEST
    Vec v = { arr[i*2+0], arr[i*2+1] };
#endif

#ifdef UNIT_TEST
	Vec v = { testArr[i*5+0], testArr[i*5+1], testArr[i*5 +4] };
#endif
    do {
        Flt ret = vec_length(v);
#ifndef UNIT_TEST
        printf("%3i  %8.5lf  %8.5lf  %10.5lf\n", i+1, v[0], v[1], ret);
#endif

#ifdef UNIT_TEST
		if (abs(v[2] - ret) < 0.01)
        printf("%3i  %8.5lf  %8.5lf  %10.5lf  %10.5lf\n", i+1, v[0], v[1], v[2], ret);
		else
        printf("%3i  %8.5lf  %8.5lf  %10.5lf  %10.5lf <-- error\n", i+1, v[0], v[1], v[2], ret);
#endif

        ++i;
#ifndef UNIT_TEST
        v[0] = arr[i*2+0];
        v[1] = arr[i*2+1];
#endif

#ifdef UNIT_TEST
        v[0] = testArr[i*5+0];
        v[1] = testArr[i*5+1];
		v[2] = testArr[i*5+4];
#endif

    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    printf("\nProgram complete.\n\n");
    return 0;
}

Flt vec_length(Vec v)
{
    //Normalize a vector.
    //Return the original length of the vector.
    //
    //input: the 2 components of a vector
    //output: the pre-normalized vector length is returned
    //        the vector argument is scaled to a length of 1.0
    //
    //A degenerate vector causes an error condition.
    //It will return a length of 0.0
    //and an arbitrary vector with length 1.0.
    //
    //calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //check for degenerate vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        //printf("ERROR vector magnitude is zero.\n");
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //vector has a magnitude so continue.
    Flt len = sqrt(dot);
#ifndef UNIT_TEST
    Flt oolen = 1.0 / len;
	v[0] *= oolen;
    v[1] *= oolen;
#endif
    return len;
}
