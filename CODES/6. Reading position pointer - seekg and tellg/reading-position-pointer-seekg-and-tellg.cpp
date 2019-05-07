#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        tellg - tell get - tell where is the reading pointer
        seekg - seek get - set reading pointer at specified position


        seekg(how_many_bytes_from_the_flag_place, flag);

        possible flags:
        ios::beg - (begin) set from the begin (default)
        ios::end - set from the end
        ios::cur - (current) set from current place
    */

    fstream file;

    file.open("sample.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        string buffer;

        file.seekg(0, ios::end);

        streampos sizeOfFile = file.tellg();

        file.seekg(0);

        cout << "The size of the file is " << sizeOfFile << " bytes" << endl;
        do
        {
            file >> buffer;

            cout << buffer << endl;
        }while (!file.eof());

        if ((file.rdstate() ^ ifstream::eofbit) == 0)
        {
            file.clear();
            cout << file.tellg() << endl;
            file >> buffer;

            cout << buffer << endl;
            //set indicator of place in file to some other place
            // some other operations on file
        }

    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}
