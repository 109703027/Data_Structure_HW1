#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Merge_sort.h"
#include "Quick_sort.h"
#include "Heap_sort.h"
#include "public.h"

int main(int argc,char** argv){
    int i;
    clock_t start,end;
    int index = 10;
    char* method = new char[20];
    strcpy(method, "MergeSort");
    char* filename = new char[20];
    strcpy(filename, " ");

    if((i = ArgPos((char*)"-index",argc,argv)) > 0)
        index = atoi(argv[i+1]);
    if((i = ArgPos((char*)"-method",argc,argv)) > 0)
        strcpy(method,argv[i+1]);
    if((i = ArgPos((char*)"-save",argc,argv)) > 0)
        strcpy(filename,argv[i+1]);

    long size = pow(2,index);
    int* arr = new int[size];
    Random(arr,size);

    start = clock();

    if(strcmp(method,"MergeSort") == 0){
        strcpy(method,"Merge Sort");
        mergeSort(arr,0,size-1);
    }
    else if(strcmp(method,"HeapSort") == 0){
        strcpy(method,"Heap Sort");
        heapSort(arr,size);
    }
    else if(strcmp(method,"LomutoPartition") == 0){
        strcpy(method,"Lomuto Partiton");
        LomutoQuickSort(arr,0,size-1);
    }
    else if(strcmp(method,"HoarePartition") == 0){
        strcpy(method,"Hoare Partiton");
        HoareQuickSort(arr,0,size-1);
    }
    else if(strcmp(method,"DutchPartition") == 0){
        strcpy(method,"Dutch Partiton");
        DutchQuickSort(arr,0,size-1);
    }
    else{
        cout << "Sorting method not found." << endl;
        exit(1);
    }

    end = clock();

    double time = double(end-start) / double(CLOCKS_PER_SEC);

    if(strcmp(filename,"") == 0){
        cout << "Method : " << method << endl;
        cout << "Index : " << index << endl;
        cout << "Size : " << size << endl;
        cout << "Time : " << fixed << time << setprecision(4) << " sec" << endl;
    }
    else{
        ofstream file;

        file.open(filename, ios_base::app);

        file << method << ",";
        file << index << ",";
        file << size << ",";
        file << time << endl;

        file.close();
    }

    return 0;
}
