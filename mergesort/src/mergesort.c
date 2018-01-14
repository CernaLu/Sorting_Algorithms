#include "declare.h"

int main(int argc, char** argv)
{
unsigned int N_ofelements;
double *arr;

N_ofelements = atoi( argv[2] );
//allocation(double **array, unsigned int N_ofelements);
allocation(&arr, N_ofelements);
File_manage(argv, arr, N_ofelements);

free(arr);
return(0);
}

void allocation(double **array, unsigned int N_ofelements)
{
*array = malloc( N_ofelements * sizeof(double) );
if(*array == NULL)
  {
  printf("\n\nError during memory allocation\n\n"\
  "in 'allocation()' function.\n\n");
  }
}

void File_manage(char **src, double *dst, unsigned int N_ofelements)
{
unsigned int i;
FILE *fp;
fp = fopen(src[1], "r");
if(fp == NULL)
  {  
  printf("\n\nError opening sorting file\n"\
  "in 'File_manage()'.\n\n");
  exit(0);
  }
for(i = 0; i < N_ofelements; i++)
  {
  fscanf(fp, "%lf\n", &dst[i] );
  }
fclose(fp);
}

unsigned int merge_sort(double *arr, unsigned int N_ofelements)
{
double *buffer;
unsigned int N_ofoperations = 0;
copy_arr(arr, buffer, N_ofelements);
//operations = N + split_merge_sorted();
free(buffer);
return(N_ofoperations);
}

void copy_arr(double *src, double *dst, unsigned int N_ofelements)
{
unsigned int i;
for(i = 0; i < N_ofelements; i++)
  {
  dst[i] = src[i];
  }
}


