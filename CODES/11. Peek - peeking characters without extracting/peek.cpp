#include <iostream>

//putback
using namespace std;
int main ()
{
    char c = cin.peek();


    if (c > '0' && c < '9')
    {
        int number;

        cin >> number;

        cout << "Number is: " << number << endl;
    }
    else
    {
        string txt;

        cin >> txt;

        cout << "Text is: " << txt << endl;
    }

    return 0;
}
