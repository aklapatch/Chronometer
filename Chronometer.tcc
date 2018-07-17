#ifndef _CHRONOMETER_TCC_
#define _CHRONOMETER_TCC_

//a simple class for timing programs
#include <chrono>
#include <iostream>

class Chronometer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> begin;
        std::chrono::duration<double> delta;

    public:

        Chronometer(){ }

        /// initializes with start time
        Chronometer(std::chrono::time_point<std::chrono::high_resolution_clock> in){
            begin = in;
        }

        ~Chronometer() {}

        /// records start time
        void start() {
            begin = std::chrono::high_resolution_clock::now();
        }

        /// records end time and computes delta
        void stop(){
            delta = std::chrono::high_resolution_clock::now() - begin;
        }

        void print(const char unit[], const char message[]){

            if(unit == "milliseconds")
                delta = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
            else if(unit == "nanoseconds")
                delta = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);
            else if(unit == "microseconds")
                delta = std::chrono::duration_cast<std::chrono::microseconds>(delta);
            else if(unit == "seconds")
                delta = std::chrono::duration_cast<std::chrono::seconds>(delta);
            else {
                std::cerr << "invalid option selected, defaulting to milliseconds\n";
                delta = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
            }

            if(message == NULL)
                std::cout << "Time elapsed: " << delta.count() << "\n";
            else   
                std::cout << "Time elapsed " << message << " " << delta.count() << "\n";
        }

        /// prints time elapsed in selected unit. Options are milliseconds, nanoseconds, microseconds, and seconds.
        void print(const char unit[]){

            if(unit == "milliseconds")
                delta = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
            else if(unit == "nanoseconds")
                delta = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);
            else if(unit == "microseconds")
                delta = std::chrono::duration_cast<std::chrono::microseconds>(delta);
            else if(unit == "seconds")
                delta = std::chrono::duration_cast<std::chrono::seconds>(delta);
             else {
                std::cerr << "invalid option selected, defaulting to milliseconds\n";
                delta = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
            }

            std::cout << "Time elapsed: " << delta.count() << "\n";
        }

        /// Returns recorded duration.
        auto getDuration(){
            return delta;
        }

        /// Sets start time
        void setStart(std::chrono::time_point<std::chrono::high_resolution_clock> in){
            begin = in;
        }
};

#endif  // CHRONOMETER_TCC
