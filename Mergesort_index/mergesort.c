#include "declare.h"

int main(int argc, char **argv)
{
unsigned int N_ofelements;
unsigned int operations;
double *arr;
unsigned int *index;
N_ofelements = atoi( argv[2] );

allocate_index(&index, N_ofelements);
allocate(&arr, N_ofelements);
printf("\n\nAllocation succesfull.");
src_File_manage(argv, arr, N_ofelements);
printf("\n\nFILE manage succesfull.");
merge_sort(index, arr, N_ofelements);
printf("\nMerge sort succesfull.");
printf("\nWriting sorted array in new file: 'sorted.txt'");
dst_File_manage(index, arr, N_ofelements);
printf("\nsorted array succesfully written in 'sorted.txt'\n\n");
//printf("\n\nThe minimum is at index %lu, with the value  %lf\n\n", index[0], arr[0]);
free(arr);
free(index);
}

void allocate_index(unsigned  int **array, unsigned  int N_ofelements)
{
*array = malloc( N_ofelements * sizeof(double) );
if(*array == NULL)
  {
  printf("\n\nError during memory allocation\n\n"\
  "in 'allocation()' function.\n\n");
  }
return(0);
}

void allocate(double **array, unsigned  int N_ofelements)
{
*array = malloc( N_ofelements * sizeof(double) );
if(*array == NULL)
  {
  printf("\n\nError during memory allocation\n\n"\
  "in 'allocation()' function.\n\n");
  }
return(0);
}

void index_array(unsigned  int *index, unsigned  int N_ofelements)
{
for(unsigned  int i=0; i < N_ofelements; i++)
  index[i] = i;
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
return(1);
}

void dst_File_manage(unsigned int *index, double *dst,
                             unsigned int N_ofelements)
{
unsigned int i;
FILE *dt;
dt = fopen("sorted.txt", "r+");

if(dt == NULL)
  {
  printf("\n\nError opening or creating 'sorted.txt' file\n"\
  "in 'dst_File_manage()'.\n\n");
  exit(7);
  }
for(i = 0; i < N_ofelements; i++)
  fprintf(dt, "%d %d\n", index[i], (int)dst[i]);
}

void copy_arr(double *src, double *dst, unsigned int N_ofelements)
{
unsigned long int i;
for(i = 0; i < N_ofelements; i++)
  {
  dst[i] = src[i];
  }
}

void merge_sort(unsigned int *index, double *arr,
                        unsigned int N_ofelements)
{

double *buffer;

allocate(&buffer, N_ofelements);
printf("\n\nAllocation succesfull.");
copy_arr(arr, buffer, N_ofelements);
printf("\n\nCopy of arr succesfull.", ID3);
split_merge_sorted(index, buffer, arr, 0, N_ofelements-1);
printf("\n\nSplit merge sorted success.", ID5);

free(buffer);
}

void split_merge_sorted(unsigned int *index,
                                double *src, double *dst,
                                unsigned int firstindex, unsigned int lastindex)
{

unsigned int middleindex;

if(lastindex - firstindex < 1)
{
return(0);
}

middleindex = (firstindex + lastindex) / 2;

split_merge_sorted(index, dst, src, firstindex, middleindex);
split_merge_sorted(index, dst, src, middleindex+1, lastindex);
merge_sorted(index, src, dst, firstindex, middleindex, lastindex);

}

void merge_sorted(unsigned int *index,
                          double *src, double *dst,
                          unsigned int firstindex, unsigned int middleindex,
                          unsigned int lastindex)
{

unsigned int lo_srcindex, hi_srcindex, dstindex;

lo_srcindex = firstindex;
hi_srcindex = middleindex + 1;


for(dstindex = firstindex; dstindex <= lastindex; dstindex++)
  {
  if(lo_srcindex <= middleindex) /* Numbers remain in the lower array part */
    {
    if(hi_srcindex > lastindex) /* No numbers remain in the higher array part */
      {
      dst[dstindex] = src[lo_srcindex];
      index[dstindex] = lo_srcindex;
      lo_srcindex++;
      }
    else /* Numbers remain in the higher array part */
      {
      if(src[lo_srcindex] < src[hi_srcindex])
        {
        dst[dstindex] = src[lo_srcindex];
        index[dstindex]  = lo_srcindex;
        lo_srcindex++;
        }
      else 
        {
        dst[dstindex] = src[hi_srcindex];
        index[dstindex] = hi_srcindex;
        hi_srcindex++;
        }
      } 
    }   
  else /* No numbers remain in the lower array part */
    {
    dst[dstindex] = src[hi_srcindex];
    index[dstindex] = hi_srcindex;
    hi_srcindex++;
    }
  }
}
