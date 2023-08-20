#include <iostream>
#include <initializer_list>

template <typename T>
auto fun(const std::initializer_list<T> &arg)
{
    T sum = 0;
    for (auto it = arg.begin(); it != arg.end(); ++it)
    {
        sum += *it;
    }
    return sum;
}

int main()
{
    auto arg1 = {1, 2, 3};
    auto arg2 = {1.1, 2.2, 3.3};

    std::cout << "Sum of arg1 = " << fun(arg1) << std::endl;
    std::cout << "Sum of arg2 = " << fun(arg2) << std::endl;

    return 0;
}
