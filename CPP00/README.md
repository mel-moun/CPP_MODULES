Namespace

In C++, namespaces are used to organize code elements such as variables, functions, and classes into logical groups. This helps prevent naming conflicts, especially in large projects where multiple developers may be working on different parts of the codebase.

#include <iostream>

namespace ME
{
    void    print()
    {
        std::cout << "FUNCTION 1" << std::endl;
    }
}

namespace MER
{
    void    print()
    {
        std::cout << "FUNCTION 2" << std::endl;
    }
}

int main()
{
    ME::print();
    MER::print();

    // print(); Compilation Error
}

In the previous example:
* We define two functions named print within separate namespaces : ME and MER.
* Each function outputs a different message to the console.
* By using namespaces, we can call the desired print function by prefixing it with the namespace name followed by '::' 

