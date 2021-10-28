#include "public.h"

int ArgPos(char* str, int argc, char** argv){
    int a;

    for(a = 1 ; a <  argc ; a++) if (!strcmp(str, argv[a])){
        if(a == argc - 1){
            cout << "Argument missing for " << str << endl;
            exit(1);
        }

        return a;
    }

    return -1;
}

void Random(int* arr,long size){
    srand(time(NULL));

    for(auto i=0;i<size;++i)
        arr[i] = rand()%1000+1;
}

void printArray(int* arr, int size)
{
    for (auto i = 0; i < size; i++)
        cout << arr[i] << " ";
}
