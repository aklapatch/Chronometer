#include <iostream>
#include "Chronometer.tcc"
#include <vector>
#include<cstring>

#define SIZE 1000

int main(){
    Chronometer timer;

    int * data = new int[SIZE];

    for(int i = 0; i < SIZE; ++i){
        data[i] = i;
    }

    timer.start();

    std::vector<int> test(SIZE);
    for(int j = 0; j < SIZE; ++j){
        test[j] = data[j];
    }

    timer.stop();

    timer.print("microseconds");

    timer.start();

    memcpy(test.data(),data,sizeof(int)*SIZE);

    timer.stop();

    timer.print("microseconds");

    return 0;
}