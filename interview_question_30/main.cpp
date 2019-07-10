#include <iostream>
#include "StackWithMin.h"

using namespace std;

void test(const StackWithMin<int>& stack, int expected)
{
    if (stack.min() == expected)
        cout << expected << endl;
    else
        cout << "test failed." << endl;
}

int main()
{
    StackWithMin<int> stack;

    stack.push(3);
    test(stack, 3);

    stack.push(4);
    test(stack, 3);

    stack.push(2);
    test(stack, 2);


    stack.push(3);
    test(stack, 2);

    stack.pop();
    test(stack, 2);

    stack.pop();
    test(stack, 3);

    stack.pop();
    test(stack, 3);

    stack.push(0);
    test(stack, 0);
    return 0;
}

