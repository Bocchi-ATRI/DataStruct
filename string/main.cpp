#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    bit :: string s1("hello");
    bit :: string s2(s1);
    cout << s1 << endl << s2 << endl;
    return 0;
}
