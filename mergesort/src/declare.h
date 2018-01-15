#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int allocation(double **array, unsigned int N_ofelements);
unsigned int File_manage(char **src, double *dst, unsigned int N_ofelements);
unsigned int copy_arr(double *src, double *dst, unsigned int N_ofelements);
unsigned int merge_sort(double *arr, unsigned int N_ofelements);
unsigned int split_merge_sorted(double *src, double *dst,\
                                unsigned int firstindex, unsigned int lastindex);
unsigned int merge_sorted(double *src,double *dst,\
                          unsigned int firstindex, unsigned int middleindex,\
                          unsigned int lastindex);

