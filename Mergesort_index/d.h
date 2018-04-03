#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int argc, char **argv);
unsigned int allocate_index(unsigned int **array, unsigned int N_ofelements);
unsigned int allocate (double **array, unsigned int N_ofelements);
void index_array (unsigned int *index, unsigned int N_ofelements);
unsigned int src_File_manage (char **src, double *dst, unsigned int N_ofelements);
unsigned int dst_File_manage (unsigned int *index, double *dst,
                             unsigned int N_ofelements);
unsigned int copy_arr (double *src, double *dst, unsigned int N_ofelements);
unsigned int merge_sort (unsigned int *index, double *arr,
                        unsigned int N_ofelements);
unsigned int split_merge_sorted (unsigned int *index,
                                double *src, double *dst,
                                unsigned int firstindex, unsigned int lastindex);
unsigned int merge_sorted (unsigned int *index, double *src, double *dst,
                          unsigned int firstindex, unsigned int middleindex,
                          unsigned int lastindex);