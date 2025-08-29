#include <string>
#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

   std::cout << "Printing the adresses !" << std::endl
              << "string adress = " << &string << std::endl
              << "stringPTR adress = " << stringPTR << std::endl
              << "stringREF adress = " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Printing the values !" << std::endl
                << "string value = " << string << std::endl
                << "stringPTR value = " << *stringPTR << std::endl
                << "stringREF value = " << stringREF << std::endl;
}