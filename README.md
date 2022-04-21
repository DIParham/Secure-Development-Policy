#Secure Development Policy Project

Examined C++ code for various vulnerabilities including Buffer Overflow, Assertions, Exceptions, Static Analysis, and Encryption, and developed remedies to better secure programs. Conforms to current coding standards to ensure compliant code. 

###Buffer Overflow
This portion of the project examined how buffer overflows work and create vulnerabilities in programs. Buffer overflows occur when the data is written of input beyond the bounds of the allocated memory. The occurrence of buffer overflows results in program crashes and an open vulnerability that could be exploited by threat actors. 

The issue is mitigated by introducing a character limit that prevents users from entering excessive characters:

std::cin.width(20);

This line of code limits user input to only 20 characters and thus, prevents the occurrence of buffer overflow. 

[Buffer Overflow](
