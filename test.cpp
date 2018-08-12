#include <iostream>
#include "Chronometer.hpp"
#include <vector>

#define SIZE 1000

int main(){
    Chronometer timer;

    //record time to init array
    timer.start();
    int * data = new int[SIZE];

    int i = SIZE;
    while(i-- )
        data[i] = SIZE;
    
    //get time and print it
    timer.stop();
    std::cout << "Time to init array " << timer.getNanosec() << " nanoseconds\n";
    std::cout << "Time to init array " << timer.getMillisec() << " milliseconds\n";
    std::cout << "Time to init array " << timer.getMicrosec() << " microseconds\n";
    std::cout << "Time to init array " << timer.getSec() << " seconds\n";            

    //record time to init vector.
    timer.start();
    std::vector<int> test(SIZE, SIZE);   

    // and print it
    timer.stop();
    timer.print("nanoseconds");
    timer.print("milliseconds");
    timer.print("microseconds");
    timer.print("seconds");

    delete [] data;
    return 0;
}