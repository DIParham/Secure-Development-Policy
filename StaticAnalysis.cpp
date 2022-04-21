// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

//custom exception
struct logicError : std::exception {
    const char* what() const throw() {
        return "\n\tLogic Exception Occurred...";
    }
};
bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;
    throw std::runtime_error("\n\tRuntime Error Exception\n");
    return true;
}



void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
   
        std::cout << "Running Custom Application Logic." << std::endl;
     //try-catch block wraps the function and throws std::exception  
    try{
        throw std::exception("\n\tException Error Occurred");
    if (do_even_more_custom_application_logic())
    {
        
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        
    }

   
    }
    //catches and prints message and results from what() function
    catch (std::exception& ex) {
        std::cerr <<"\nError Occurred: " << ex.what() << std::endl;
    }
    // TODO: Throw a custom exception derived from std::exception
   //  and catch it explictly in main
    std::cout << "Leaving Custom Application Logic." << std::endl;

    //throws custom exception
    throw logicError(); 
  

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    //if the variable, den is equal to 0, it will throw an exception
    //a numerator divided by 0 results in infinity 
 
    if (den == 0) {
        std::cout << "\nRunning Division" << std::endl;
        throw "Exception Thrown: \n\tDivide - Division by 0! \n";
       
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;
   
    //divide operation placed in the try block
    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    //if the den = 0, an exception will be thrown and then caught
    catch (const char* msg) {
        std::cerr << msg << std::endl;
        
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
      try {
        do_division();
        do_custom_application_logic();
       
    }
      //catches the custom exception logicError
    catch (logicError& error) {
        
        std::cerr <<"\nCustom Exception Caught: "<< error.what() << std::endl;
    }
    //this catch block will catch the runtime error if the do_even_more_custom_application_logic function is true. 
    catch (std::runtime_error& error) {
        std::cerr << "\nStandard Exception Caught: " << error.what() << std::endl;
    }
    //a catch all block catches any missed exceptions that would have created issues during the execution of the program
    
    //catches all exceptions
    catch (...) {
        std::cerr << "All Exceptions Caught..." << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
