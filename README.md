# Secure Development Policy Project

Examined C++ code for various vulnerabilities including Buffer Overflow, Assertions, Exceptions, Static Analysis, and Encryption, and developed remedies to better secure programs. Conforms to current coding standards to ensure compliant code. 

### Buffer Overflow
This portion of the project examined how buffer overflows work and create vulnerabilities in programs. Buffer overflows occur when the data is written of input beyond the bounds of the allocated memory. The occurrence of buffer overflows results in program crashes and an open vulnerability that could be exploited by threat actors. 

The issue is mitigated by introducing a character limit that prevents users from entering excessive characters:

    std::cin.width(20);

This line of code limits user input to only 20 characters and thus, prevents the occurrence of buffer overflow. 

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
    
With this assignment, I developed a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources by utilizing whitebox testing to ensure that the program functions as expected.

[Assertions](https://github.com/DIParham/Secure-Development-Policy/blob/main/Assertions.cpp)

### SQL Injection

SQL Injections are malicious code injection techniques utilized to obtain unauthorized access to an account or other confidential areas. It works by running a statement through a database that is always true. For instance, when a website prompts the user for a username, a SQL injection can be used to gain access to an account or grant a threat actor access to a database full of usernames and passwords. By inserting a SQL statement as login information, it would run the statement on the database. 

By running a SQL statement that is always true, it would return all the information from the database. 

Example: 
    UserID: 123 OR 1=1
    
    SELECT* FROM  User WHERE UserID = 123 OR 1=1;
    
Because 1=1 is always true, this statement would return all the rows from the "User" table. This would display other users' login information. 

The SQL Injection project demonstrates the impact of code vulnerable to SQL injection. Prior to mitigating the vulnerability, running the code would display the user login information. To resolve this issue, a regex (regular expression) is utilized to whitelist valid characters and give the program the ability to detect suspected SQL Injections. 

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

Through this project, I developed a security mindset that anticipates adversarial exploits in software architecture and designs to expose potential vulnerabilities, mitigate design flaws, and ensure privacy and enhanced security of data and resources by recognizing, locating, and resolving SQL Injection vulnerabilities in the code.
 
[SQL Injection](https://github.com/DIParham/Secure-Development-Policy/blob/main/SQLInjection.cpp)
