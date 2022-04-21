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

[Assertions](https://github.com/DIParham/Secure-Development-Policy/blob/main/Assertions.cpp)

### SQL Injection
