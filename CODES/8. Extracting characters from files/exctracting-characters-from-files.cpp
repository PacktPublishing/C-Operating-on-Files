#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        getline(where to store the extracted characters, how many characters should be taken unlles, seperator(delimiter)) - extracts seperators and delete it
        get(where to store the extracted characters, how many characters should be taken unlles, seperator(delimiter)) - doesn't extract seperator
        ignore(how_many_characters_to_extracte AND TO IGNORE THEM, seperator) - extracts characters

        get();
    */

    fstream file;

    file.open("sample.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        char first, second;
        char buffer[50];

        cin >> buffer;

        cout << buffer << endl;
        do
        {
            file.getline(buffer, 50, ' ');

            second = file.get();

            file.ignore(40, '\n');

            cout << buffer << " " << second << ". " << endl;

        } while(!file.eof());



    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}
