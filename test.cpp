#include <iostream>
#include "Chronometer.hpp"
#include <vector>

#define SIZE 10000000

int main(){
    Chronometer timer;

    //record time to init array
    timer.start();
    int * data = new int[SIZE];

    int i = SIZE;
    while(i-- ){
        data[i] = SIZE;
    }
    
    //get time and print it
    timer.stop();
    std::cout << "Time to init array " << timer.getNanosec() << " nanoseconds\n";
    std::cout << "Time to init array " << timer.getMillisec() << " milliseconds\n";
    std::cout << "Time to init array " << timer.getMicrosec() << " microseconds\n";
    std::cout << "Time to init array " << timer.getSec() << " seconds\n";            

    delete [] data;

    //record time to init vector.
    timer.start();
    std::vector<int> test(SIZE, SIZE);   

    // and print it
    timer.stop();
    timer.print("ns");
    timer.print("ms");
    timer.print("us");
    timer.print("s");

    return 0;
}
