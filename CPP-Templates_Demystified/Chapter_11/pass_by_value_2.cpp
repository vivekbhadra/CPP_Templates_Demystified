#include <iostream>
template<typename T>
void print_values(const T x, const T y)
{
    x = 50;
    y = 30;
    std::cout << " from print_values: x = "
              << x
              << " y = "
              << y << std::endl;
}
int main()
{
    int var1 = 10;
    int var2 = 20;
    print_values(var1, var2);
    std::cout << " from main: var1 = "
              << var1
              << " var2 = "
              << var2 << std::endl;
    return 0;
}
