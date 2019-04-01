#include <iostream>
#include "Chronometer.hpp"
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

#define ERRTHRESH 1000
#define MULT 1000

void printTestResult(bool Result, const char * TestName){
	
	cout << "\nTest: " << TestName;
	
	if (Result)
		cout << " PASSED.\n";
		
	else 
		cout << " FAILED.\n";
}

void outputResults(auto Result, auto ExpectedValue, auto Error, auto Threshold){
	cout << "Actual value= " << Result << "\nExpected value = " << ExpectedValue;
	cout << " Error = " << Error << "\nError Threshold= " << Threshold << "\n";
	
		  
}

void testError(auto Expected, auto Result, auto ErrorThreshold, const char * TestName){
	
	printTestResult(ErrorThreshold > Result - Expected,  TestName);
    outputResults(Result, Expected , Result - Expected, ErrorThreshold);
}

int main(){
    Chronometer Timer;
    
    cout << "\n If a test fails, all subsequent tests are not valid even if they pass.\n";
    
    // seconds test
    int Interval = 1;
    
    
    Timer.start();
    this_thread::sleep_for(chrono::seconds(Interval));
    Timer.stop();
    
    int Result = Timer.getSec();
    
    printTestResult(Result == Interval,  "getSecond() ");
    outputResults(Result , Interval, Result - Interval, 0);
    
	// test getMillsec
	testError(MULT*Timer.getSec(), Timer.getMillisec(), ERRTHRESH , "getMillisec()");  
		
	// get Microsec
	testError(MULT*Timer.getMillisec(), Timer.getMicrosec(), ERRTHRESH , "getMicrosec()");

	// get Nanosec
	testError(MULT*Timer.getMicrosec(), Timer.getNanosec(), ERRTHRESH , "getNanosec()");	
    
    cout << "\n Testing printing functions\n"; 
    Timer.print("ns");
    Timer.print("us");
    Timer.print("ms");
    Timer.print("s");

    return 0;
}
