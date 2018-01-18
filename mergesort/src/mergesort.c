#include "declare.h"

int main(int argc, char **argv)
{
unsigned int N_ofelements;
unsigned int operations;
unsigned int ID0 = 0;
unsigned int ID1 = 0;
unsigned int IDf = 0;
double *arr;

N_ofelements = atoi( argv[2] );
printf("\n\nExit code success only means that a function was exit successfully,\n"\
       "but doesn't mean that the function did its work properly");
ID0 = allocate(&arr, N_ofelements);
printf("\n\nAllocation succesfull. Exit code %d.", ID0);
ID1 = File_manage(argv, arr, N_ofelements);
printf("\n\nFILE manage succesfull. Exit code %d.", ID1);
IDf = merge_sort(arr, N_ofelements);
printf("\nMerge sort succesfull. Exit code %d.", IDf);

free(arr);
return(6);
}

unsigned int allocate(double **array, unsigned int N_ofelements)
{
*array = malloc( N_ofelements * sizeof(double) );
if(*array == NULL)
  {
  printf("\n\nError during memory allocation\n\n"\
  "in 'allocation()' function.\n\n");
  }
return(0);
}

unsigned int File_manage(char **src, double *dst, unsigned int N_ofelements)
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
return(1);
}

unsigned int copy_arr(double *src, double *dst, unsigned int N_ofelements)
{
unsigned int i;
for(i = 0; i < N_ofelements; i++)
  {
  dst[i] = src[i];
  }
return(2);
}

unsigned int merge_sort(double *arr, unsigned int N_ofelements)
{
unsigned int ID2 = 0;
unsigned int ID3 = 0;
unsigned int ID5 = 0;
double *buffer;

ID2 = allocate(&buffer, N_ofelements);
printf("\n\nAllocation succesfull. Exit code %d.", ID2);
ID3 = copy_arr(arr, buffer, N_ofelements);
printf("\n\nCopy of arr succesfull. Exit code %d.", ID3);
ID5 = split_merge_sorted(buffer, arr, 0, N_ofelements-1);
printf("\n\nSplit merge sorted success. Exit code %d.", ID5);

free(buffer);
return(5);
}

unsigned int split_merge_sorted(double *src, double *dst,\
                                unsigned int firstindex, unsigned int lastindex)
{
unsigned int op = 0;
unsigned int ID4 = 0;
unsigned int middleindex;

if(lastindex - firstindex < 1)
{
return(0);
}

middleindex = (firstindex + lastindex) / 2;

op += split_merge_sorted(dst, src, firstindex, middleindex);
op += split_merge_sorted(dst, src, middleindex+1, lastindex);
op += merge_sorted(src, dst, firstindex, middleindex, lastindex);
printf("\nNumber of operations = %d\n", op);
printf("\n\nMerge sorted success. Exit code %d.", ID4);

return(op);
}

unsigned int merge_sorted(double *src, double *dst,\
                          unsigned int firstindex, unsigned int middleindex,\
                          unsigned int lastindex)
{
unsigned int sorted_numbers = 0;
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
  sorted_numbers++;
  }
return(sorted_numbers++);
}
