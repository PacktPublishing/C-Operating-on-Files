#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream myFileHandler;

    myFileHandler.open("test.txt");

    if (myFileHandler.is_open())
    {
        cout << "The file has been opened properly";

        myFileHandler << "this is a sample text";

        myFileHandler.close();
    }
    else
        cout <<"a";

    return 0;
}
