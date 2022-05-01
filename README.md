# Secure Development Policy Project

Examined C++ code for various vulnerabilities including Buffer Overflow, Assertions, SQL Injections, Static Analysis, and Encryption, and developed remedies to better secure programs. Conforms to current coding standards to ensure compliant code. 

### Buffer Overflow
This portion of the project examined how buffer overflows work and create vulnerabilities in programs. Buffer overflows occur when the data is written of input beyond the bounds of the allocated memory. The occurrence of buffer overflows results in program crashes and an open vulnerability that could be exploited by threat actors.

    const std::string account_number = "CharlieBrown42";
	char user_input[20];
  
    std::cout << "Enter a value: ";
    std::cin >> user_input;

In this section of the program, user_input is an array of 20 characters. This creates a limitation to how much memory the program has allocated, which results in the data overwriting the memory boundaries set for it. As a result, a user could type in a value that has greater than 20 characters and it would overflow the buffer. This vulnerability caused the program to crash. 

![image](https://user-images.githubusercontent.com/79165798/166166429-93ec83cb-a4b6-45e2-9753-d22dea22c432.png)

The issue is mitigated by introducing a character limit that prevents users from entering excessive characters:

    std::cin.width(20);

This line of code limits user input to only 20 characters and thus, prevents the occurrence of buffer overflow. It prevented the program from accepting an excessive amount of characters and crashing. For instance, if a user were to insert the entire alphabet, the program would only accept letters A through T and omit the rest.

![Screenshot (5)](https://user-images.githubusercontent.com/79165798/166167092-8bf07977-195d-4dce-9fa9-5b541fe3ed9a.png)

Through this project, I developed a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources by recognizing, locating, and resolving buffer overflow vulnerabilities in the code. I was able to properly recognize and apply a solution to a buffer overflow that resulted in the crashing of a program and exposure of sensitive information. 

[Buffer Overflow](https://github.com/DIParham/Secure-Development-Policy/blob/main/BufferOverflow.cpp)

### Assertions
The usage of assertions aim to ensure that all conditions are met. Non compliant code would utilize assertions as a method to validate method arguments, such as:

    assert id != NULL;

This practice can result in various implications and other errors that have the potential to open vulnerabilities. Compliant usage of assertions will instruct the program to fail or interrupt if conditions are not met. For this project, assertions are used to test that conditions have been met. For instance, this code block demonstrates the compliant usage of assertions to assert that the collection is indeed empty. If the collection is not empty, the program would fail. 

    // Create a test to verify clear erases the collection
    TEST_F(CollectionTest, VerifyEraseCollection) {
        //clear() function clears and erases the collection
        collection->clear();
        ASSERT_TRUE(collection->empty()); 
    }
    
![Screenshot (7)](https://user-images.githubusercontent.com/79165798/166167512-897dfcf9-511b-4f36-a964-6cfd63fd21ea.png)
    
With this assignment, I developed a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources by utilizing whitebox testing to ensure that the program functions as expected.

[Assertions](https://github.com/DIParham/Secure-Development-Policy/blob/main/Assertions.cpp)

### SQL Injection

SQL Injections are malicious code injection techniques utilized to obtain unauthorized access to an account or other confidential areas. It works by running a statement through a database that is always true. For instance, when a website prompts the user for a username, a SQL injection can be used to gain access to an account or grant a threat actor access to a database full of usernames and passwords. By inserting a SQL statement as login information, it would run the statement on the database. 

By running a SQL statement that is always true, it would return all the information from the database. 

Example: 
    
    UserID: 123 OR 1=1
    
    SELECT* FROM  User WHERE UserID = 123 OR 1=1;
    
Because 1=1 is always true, this statement would return all the rows from the "User" table. This would display other users' login information. 

The SQL Injection project demonstrates the impact of code vulnerable to SQL injection. Prior to mitigating the vulnerability, running the code would display the user login information. 

![image](https://user-images.githubusercontent.com/79165798/166166373-f2269645-08db-4270-98d4-d9cc81c49bbc.png)

To resolve this issue, a regex (regular expression) is utilized to whitelist valid characters and give the program the ability to detect suspected SQL Injections. 

     std::regex expr("[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+");

    //if statement used to set a condition that would detect invalid charcters
    //regex and regex_match used to compare the valid characters to invalid characters
    //if invalid characters are detected, program would throw error
    //else program will continue.

    if (!(std::regex_match(sql, expr))) {
       std::cerr << "SQL Injection Suspected!" << std::endl;
       return false;
    }
    else
    {
        std::cerr << "SQL OK!" << std::endl;
        return true;
    }

![Screenshot (6)](https://user-images.githubusercontent.com/79165798/166167327-efe5a9bb-6999-4a1c-9aab-91728dabd72d.png)

Through this project, I developed a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources by recognizing, locating, and resolving SQL Injection vulnerabilities in the code.
 
[SQL Injection](https://github.com/DIParham/Secure-Development-Policy/blob/main/SQLInjection.cpp)

### Exceptions

An exception is a problem that occurs during program execution. It disrupts the program to have it abnormally terminate. The cause of an exception can revolve around various reasons including invalid data entry, a file that cannot be found, etc. It is important to address exceptions. There are instances where checked exceptions are suppressed or ignored. This is done through the usage of empty try-catch blocks. 

In this portion of the assignment, exceptions were used to try, throw, and catch various errors throughout the program. 

![image](https://user-images.githubusercontent.com/79165798/166165430-7ea022a5-b884-4115-a523-658f222936d5.png)

The first step in resolving the program errors was to run the program to understand the problems associated with it. An issue found with the program was associated with the divide function. It would divide numbers by zero which created in the invalid solution, inf.  
This problem was mitigated by incorporating an if statement which would throw an exception if the variable, den, was equivalent to 0. 

	if (den == 0) {
        	std::cout << "\nRunning Division" << std::endl;
        	throw "Exception Thrown: \n\tDivide - Division by 0! \n";
       
The exception was caught in the following function, do_division(). This printed an error message that prevented the division of a number by 0. The try blocks indicates lines of code that would most likely throw an exception. The catch block specifies the actions to take if an exception is thrown. 

	//divide operation placed in the try block
    	try {
        	auto result = divide(numerator, denominator);
        	std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    	}
    	//if the den = 0, an exception will be thrown and then caught
    	catch (const char* msg) {
        	std::cerr << msg << std::endl;
		
In the bool do_even_more_custom_application_logic(), a standard exception is thrown which indicates a Runtime error. The Runtime error would only occur if the do_even_more_custom_application_logic() is true. If the condition for the Runtime error is met, the error will be thrown. 
The struct, logicError, holds the custom exception which is thrown in the do_custom_application_logic() function and would be caught in the main function. 

  //catches the custom exception logicError
    catch (logicError& error) {
        
        std::cerr <<"\nCustom Exception Caught: "<< error.what() << std::endl;
	
The what() function returns a null terminated sequence that helps to identify the exception that had been thrown.  
In the main() function, the function calls (do_division and do_custom_application_logic) are placed in the try block. The catch block is then used to catch any uncaught exceptions such as the custom exception. 

	//catches the custom exception logicError
    	catch (logicError& error) {
        
       		std::cerr <<"\nCustom Exception Caught: "<< error.what() << std::endl;
   	 }
   	 //this catch block will catch the runtime error if the do_even_more_custom_application_logic function is true. 
   	 catch (std::runtime_error& error) {
        	std::cerr << "\nStandard Exception Caught: " << error.what() << std::endl;
   	 }
	 
A catch-all block is used to ensure any unspecified exception that has been thrown is caught. 

	//a catch all block catches any missed exceptions that would have created issues during the execution of the program
    	//catches all exceptions
	
    	catch (...) {
        	std::cerr << "All Exceptions Caught..." << std::endl;
    	}

The implementation of try-catch blocks prevented errors such as inf from occurring. 

![image](https://user-images.githubusercontent.com/79165798/166166690-c2def094-11a1-4757-81f1-f02dfd8534ff.png)

With this assignment, I developed a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources by utilizing try-catch blocks to ensure that the program handled exceptions properly.

[Exceptions](https://github.com/DIParham/Secure-Development-Policy/blob/main/Exceptions.cpp)
