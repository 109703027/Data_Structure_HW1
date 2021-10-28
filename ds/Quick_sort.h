#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void DuychPartition(int* arr, int low, int high, int& i, int& j);
void DutchQuickSort(int* arr, int low, int high);

int LomutoPartition(int* arr, int low, int high);
void LomutoQuickSort(int* arr, int low, int high);

int HoarePartition(int* arr, int low, int high);
void HoareQuickSort(int* arr, int low, int high); 

#endif
