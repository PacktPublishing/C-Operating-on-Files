#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        bad() - badbit(1) - returns true if there is an error like writing to file which was opened only for reading (ios::in)
        fail() - failbit(4) - returns true if we try to assign string to integer while reading from file or when badbit situation happens

        eof() - eofbit(2) - returns true if the file opened to read reaches the End of File


        1 - 001
        2 - 010
        4 - 100

        bitwise operators: & | ^

        ^
        110 - 6
        010 - 2
        100 - 4
        ^
        010
        010
        000

        good() - goodbit(0) - returns true if everything is fine (if any of the above flags are false)

        rdstate() - ReaD State
        clear() - clear state
    */

    fstream file;

    file.open("sample.txt", ios::in);

    if (file.is_open())
    {
        string buffer;

        do
        {
            file >> buffer;

            cout << buffer << endl;
        }while (!file.eof());

        cout << (file.rdstate() ^ ifstream::eofbit) << endl;
        if ((file.rdstate() ^ ifstream::eofbit) == 0)
        {
            file.clear();
            //set indicator of place in file to some other place
            // some other operations on file
        }


        cout << file.rdstate();



    }
    else
        cout << "The file couldn't be opened properly" << endl;



    return 0;
}
