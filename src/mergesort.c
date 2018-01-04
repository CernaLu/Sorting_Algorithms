#include "declare.h"

int main(int argc, char** argv)
{ 
int N_ofelements;
N_ofelements = atoi( argv[2] );
double *arr = malloc( N_ofelements * sizeof(double) );
FILE *fp;
fp = fopen(argv[1], "r");

if(*arr == NULL)
  {
  printf("\n\nError during memory allocation.\n\n");
  }
if(fp == NULL)
  {  
  printf("Error opening sorting file");
  }

for(int i = 0; i < N_ofelements; i++)
  {
  fscanf(fp, "%lf\n", &arr[i] );
  }

fclose(fp);
free(arr);
return(0);
}
