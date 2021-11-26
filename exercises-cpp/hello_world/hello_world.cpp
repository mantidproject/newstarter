#include <iostream>

int main(){
    constexpr auto add = [](int x, int y){
        return x + y;
    };
    static_assert(add(1, 2) == 3);  // Ensure C++-17 is actually being used

    std::cout << "Hello World!\n"
              << "You have a working C++-17 Compiler";
    return 0;
}