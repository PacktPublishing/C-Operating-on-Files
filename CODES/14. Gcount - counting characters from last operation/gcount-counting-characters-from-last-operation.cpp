#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        gcount - Getcharacter Count - get count of extracted characters from last extraction operation
    */

    fstream file;

    file.open("sample.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        char buffer[250];
        do
        {
            file.getline(buffer, 250);

            cout << buffer << " " << file.gcount() << endl;
        }while(!file.eof());
    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}
