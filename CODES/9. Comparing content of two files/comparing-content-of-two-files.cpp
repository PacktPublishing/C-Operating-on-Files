#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;

bool areFilesEqual(fstream *, fstream *);
int sizeOfFile(fstream *);
int main()
{
    /*
        read(where to read, how many bytes to read);
        memcmp it stands memory compare
    */

    fstream file1, file2;

    file1.open("sample.txt", ios::in | ios::binary | ios::ate);
    file2.open("sample2.txt", ios::in | ios::binary | ios::ate);

    if (file1.is_open() && file2.is_open())
    {
        if (areFilesEqual(&file1, &file2))
        {
            cout << "Files are equal";
        }
        else
            cout << "Files are not the same" << endl;

    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}
bool areFilesEqual(fstream *a, fstream *b)
{
    int fileSize1 = sizeOfFile(a);
    int fileSize2 = sizeOfFile(b);

    if (fileSize1 == fileSize2)
    {
        int BUFFER_SIZE;

        if(fileSize1 > 1024)
            BUFFER_SIZE = 1024;
        else
            BUFFER_SIZE = fileSize1;

        char *file1buffer = new char[BUFFER_SIZE];
        char *file2buffer = new char[BUFFER_SIZE];

        do
        {
            a->read(file1buffer, BUFFER_SIZE);
            b->read(file2buffer, BUFFER_SIZE);

            if (memcmp(file1buffer, file2buffer, BUFFER_SIZE) != 0)
            {
                cout << "Files are not equal, at least one of the byte was different" << endl;

                delete [] file1buffer;
                delete [] file2buffer;
                return false;
            }
        }while(a->good() && b->good());

        delete [] file1buffer;
        delete [] file2buffer;
        return true;
    }
    else
    {
        cout << "Size of Files are not equal" << endl;
        return false;
    }
}
int sizeOfFile(fstream * file)
{
    file->seekg(0, ios::end);
    int sizeOfFile = file->tellg();
    file->seekg(0, ios::beg);
    return sizeOfFile;
}
