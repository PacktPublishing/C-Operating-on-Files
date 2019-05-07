#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*
        put(character to put on stream)
    */

    string txt = "thistextisconnected";


 /*   for (int i = 0; i < txt.length(); i++)
    {
        cout.put(txt[i]).put(' ');
    }
*/
    fstream file;

    file.open("test.txt", ios::out | ios::binary);
    if (file.is_open())
    {
        char c;
        do
        {
            c = cin.get();

            file.put(c);
        }while(c!='.');
    }
    else
        cout << "Nie udalo sie poprawnie otworzyc pliku" << endl;


    return 0;
}
