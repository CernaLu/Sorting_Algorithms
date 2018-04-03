#include "declare.h"

int main(int argc, char **argv)
{
int cast;
unsigned int N_ofelements;
double *arr;

if(argc < 3)
  {
  printf("\n\nError, not enough command line arguments.\n\n");
  exit(0);
  }
  
cast = atoi( argv[2] );  
N_ofelements = (unsigned int)cast;

allocate(&arr, N_ofelements);
printf("\n\nAllocation succesfull.");
src_File_manage(argv, arr, N_ofelements);
printf("\n\nFILE manage succesfull.");
merge_sort(arr, N_ofelements);
printf("\n\nMerge sort succesfull.");
printf("\n\nWriting sorted array in new file: 'sorted.txt'");
dst_File_manage(arr, N_ofelements);
printf("\n\nsorted array succesfully written in 'sorted.txt'\n\n");

free(arr);
}

void allocate(double **array, unsigned int N_ofelements)
{
*array = malloc( N_ofelements * sizeof(double) );
if(*array == NULL)
  {
  printf("\n\nError during memory allocation\n\n"\
  "in 'allocation()' function.\n\n");
  exit(0);
  }
}

void src_File_manage(char **src, double *dst, unsigned int N_ofelements)
{
unsigned int i;
FILE *sc;
sc = fopen(src[1], "r");

if(sc == NULL)
  {  
  printf("\n\nError opening sorting file\n"\
  "in 'src_File_manage()'.\n\n");
  exit(1);
  }

for(i = 0; i < N_ofelements; i++)
  {
  fscanf(sc, "%lf\n", &dst[i] );
  }

fclose(sc);
}

void dst_File_manage(double *dst, unsigned int N_ofelements)
{
unsigned int i;
FILE *dt;
dt = fopen("sorted.txt", "w+");

if(dt == NULL)
  {
  printf("\n\nError opening or creating 'sorted.txt' file\n"\
  "in 'dst_File_manage()'.\n\n");
  exit(3);
  }

for(i = 0; i < N_ofelements; i++)
  {
  fprintf(dt, "%lf\n", dst[i]);
  }
//fclose(dt);
}

void copy_arr(double *src, double *dst, unsigned int N_ofelements)
{
unsigned int i;
for(i = 0; i < N_ofelements; i++)
  {
  dst[i] = src[i];
  }
}

void merge_sort(double *arr, unsigned int N_ofelements)
{
double *buffer;

allocate(&buffer, N_ofelements);
printf("\n\nAllocation succesfull.");
copy_arr(arr, buffer, N_ofelements);
printf("\n\nCopy of arr succesfull.");
split_merge_sorted(buffer, arr, 0, N_ofelements-1);
printf("\n\nSplit merge sorted success.");

free(buffer);
}

void split_merge_sorted(double *src, double *dst,\
                        unsigned int firstindex, unsigned int lastindex)
{
unsigned int middleindex;

if(lastindex - firstindex < 1)
  return;

middleindex = (firstindex + lastindex) / 2;

split_merge_sorted(dst, src, firstindex, middleindex);
split_merge_sorted(dst, src, middleindex+1, lastindex);
merge_sorted(src, dst, firstindex, middleindex, lastindex);
}

void merge_sorted(double *src, double *dst,\
                          unsigned int firstindex, unsigned int middleindex,\
                          unsigned int lastindex)
{
unsigned int lo_srcindex, hi_srcindex, dstindex;

lo_srcindex = firstindex;
hi_srcindex = middleindex + 1;

for(dstindex = firstindex; dstindex <= lastindex; dstindex++)
  {
  if(lo_srcindex <= middleindex) /* Numbers remain in the lower array part */
    {
    if(hi_srcindex > lastindex) /* No numbers reamin in the higher array part */
      {
      dst[dstindex] = src[lo_srcindex];
      lo_srcindex++;
      }
    else /* Numbers remain in the higher array part */
      {
      if(src[lo_srcindex] < src[hi_srcindex])
        {
        dst[dstindex] = src[lo_srcindex];
        lo_srcindex++;
        }
      else 
        {
        dst[dstindex] = src[hi_srcindex];
        hi_srcindex++;
        }
      } 
    }   
  else /* No numbers remain in the lower array part */
    {
    dst[dstindex] = src[hi_srcindex];
    hi_srcindex++;
    }
  }
}
