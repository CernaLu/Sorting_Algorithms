#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void allocate(double **array, unsigned int N_ofelements);
void src_File_manage(char **src, double *dst, unsigned int N_ofelements);
void dst_File_manage(double *dst, unsigned int N_ofelements);
void copy_arr(double *src, double *dst, unsigned int N_ofelements);
void merge_sort(double *arr, unsigned int N_ofelements);
void split_merge_sorted(double *src, double *dst,\
                        unsigned int firstindex, unsigned int lastindex);
void merge_sorted(double *src,double *dst,\
                  unsigned int firstindex, unsigned int middleindex,\
                  unsigned int lastindex);