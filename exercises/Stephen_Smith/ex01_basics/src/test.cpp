#include <vector>
#include <string>
#include <iostream>


struct a {

    int b = 3;
    int c = 4;

};

int main(int argc, char const *argv[])
{


    std::vector<int> a;


    a.emplace_back(2);
    a.emplace_back(3);
    
    a.emplace_back(2);
    a.emplace_back(3);    
    a.emplace_back(2);
    a.emplace_back(3);   






    for (std::vector<int>::const_iterator iter = a.begin(); iter != a.end() ; ++iter)
    {
        std::cout << *iter << std::endl;
    }
    
    
    
        /* code */
    return 0;
}
