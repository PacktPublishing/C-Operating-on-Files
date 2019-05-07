#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        write
    */

    fstream file;

    file.open("sample.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        char sample[] = "sample text";

        cout << sizeof(sample) << endl;

        file.write(sample, 60);
    }
    else
        cout << "I couldnt open the file" << endl;



    return 0;
}
