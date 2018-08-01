#ifndef _CHRONOMETER_HPP_
#define _CHRONOMETER_HPP_

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
            
        /// prints time elapsed in selected unit. Options are milliseconds, nanoseconds, microseconds, and seconds.
        void print(const char unit[]){

            if(unit == "milliseconds"){
                auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
                std::cout << "Time elapsed: " << tmp.count() << " milliseconds\n";

            } else if(unit == "nanoseconds") {
                auto tmp = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);
                std::cout << "Time elapsed: " << tmp.count() << " nanoseconds\n";

            } else if(unit == "microseconds"){
                auto tmp = std::chrono::duration_cast<std::chrono::microseconds>(delta);
                std::cout << "Time elapsed: " << tmp.count() << " microseconds\n";

            } else if(unit == "seconds") {
                auto tmp = std::chrono::duration_cast<std::chrono::seconds>(delta);
                std::cout << "Time elapsed: " << tmp.count() << " seconds\n";

            } else {
                std::cerr << "invalid option selected, defaulting to milliseconds\n";
                auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
                std::cout << "Time elapsed: " << tmp.count() << "milliseconds\n";
            }
        }

        /// return stored number of milliseconds
        auto getMillisec(){
            auto ret = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
            return ret.count();
        }

        /// return stored number of nanoseconds 
        auto getNanosec(){
            auto ret = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);
            return ret.count();
        }

        /// return stored number of microseconds
        auto getMicrosec(){
            auto ret = std::chrono::duration_cast<std::chrono::microseconds>(delta);
            return ret.count();
        }

        /// return stored number of seconds
        auto getSec(){
            auto ret = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
            return ret.count();
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

#endif  // CHRONOMETER
