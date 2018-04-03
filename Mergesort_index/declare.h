#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int argc, char **argv);
void allocate_index(unsigned int **array, unsigned int N_ofelements);
void allocate (double **array, unsigned int N_ofelements);
void index_array (unsigned int *index, unsigned int N_ofelements);
void src_File_manage (char **src, double *dst, unsigned int N_ofelements);
void dst_File_manage (unsigned int *index, double *dst,
                             unsigned int N_ofelements);
void copy_arr (double *src, double *dst, unsigned int N_ofelements);
void merge_sort (unsigned int *index, double *arr,
                        unsigned int N_ofelements);
void split_merge_sorted (unsigned int *index,
                                double *src, double *dst,
                                unsigned int firstindex, unsigned int lastindex);
void merge_sorted (unsigned int *index, double *src, double *dst,
                          unsigned int firstindex, unsigned int middleindex,
                          unsigned int lastindex);