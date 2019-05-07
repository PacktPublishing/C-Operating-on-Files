#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Person
{
    string name;
    string surname;
    short age;
    string telephone;
};
short peopleInDataBase;
Person people[20];

void requireEnter();

void addPerson();
void showPeople();
void savePeopleToFile();
void loadPeopleFromFile();
void searchDatabase();
void removePersonFromDatabase();

int main()
{
    char test;
    loadPeopleFromFile();

    do
    {
        cout << "Number of People in Database: " << peopleInDataBase << endl;
        cout << "MENU: " << endl;

        cout << "1. Add Person" << endl;
        cout << "2. Show All People" << endl;
        cout << "3. Save People to File" << endl;
        cout << "4. Load People from File" << endl;
        cout << "5. Search for a Person" << endl;
        cout << "6. Remove Person from DataBase" << endl;

        cout << endl;

        test = getch();

        switch(test)
        {
            case '1':
                addPerson();
                break;
            case '2':
                showPeople();
                break;
            case '3':
                savePeopleToFile();
                break;
            case '4':
                loadPeopleFromFile();
                break;
            case '5':
                searchDatabase();
                break;
            case '6':
                removePersonFromDatabase();
                break;
        }


        requireEnter();
        system("cls");
    }while(test != 27);


    return 0;
}
void requireEnter()
{
    cout << "Click Enter to continue... " << endl;
    while(getch() != 13);
}
void addPerson()
{
    cout << "Type name: ";
    cin >> people[peopleInDataBase].name;

    cout << "Type surname: ";
    cin >> people[peopleInDataBase].surname;

    cout << "Type age: ";
    cin >> people[peopleInDataBase].age;

    cout << "Type telephone: ";
    cin >> people[peopleInDataBase].telephone;

    peopleInDataBase++;
}
void showPeople()
{
    if(peopleInDataBase > 0)
    {
        for (int i = 0; i < peopleInDataBase; i++)
        {
            cout << "Person index: " << (i+1) << endl;
            cout << "Name: " << people[i].name << endl;
            cout << "Surname: " << people[i].surname << endl;
            cout << "Age: " << people[i].age << endl;
            cout << "Telephone: " << people[i].telephone << endl << endl;
        }
    }
    else
        cout << "There is nobody in database."  << endl;
}
void savePeopleToFile()
{
    ofstream file("database.txt");

    if (file.is_open())
    {
        file << peopleInDataBase << endl;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            file << people[i].name << endl;
            file << people[i].surname << endl;
            file << people[i].age << endl;
            file << people[i].telephone << endl;
        }

        file.close();
    }
    else
        cout << "I couldnt save to database" << endl;

}
void loadPeopleFromFile()
{
    ifstream file("database.txt");

    if (file.is_open())
    {
        file >> peopleInDataBase;

        if (peopleInDataBase > 0)
        {
            /*for (int i = 0; i < peopleInDataBase; i++)
            {
                file >> people[i].name;
                file >> people[i].surname;
                file >> people[i].age;
                file >> people[i].telephone;
            }*/
            int i = 0;
            do
            {
                file >> people[i].name;
                file >> people[i].surname;
                file >> people[i].age;
                file >> people[i].telephone;

                i++;
            }while(!file.eof());

            cout << "People has been loaded properly. " << endl;
        }
        else
            cout << "Databse is Empty" << endl;
    }
    else
        cout << "The file database.txt doesnt exist" << endl;
}
void searchDatabase()
{
    if (peopleInDataBase > 0)
    {
        string name;
        cout << "Type a name of person you want to look for: ";
        cin >> name;

        for (int i = 0; i < peopleInDataBase; i++)
        {
            if (name == people[i].name)
            {
                cout << "Person index: " << (i+1) << endl;
                cout << "Name: " << people[i].name << endl;
                cout << "Surname: " << people[i].surname << endl;
                cout << "Age: " << people[i].age << endl;
                cout << "Telephone: " << people[i].telephone << endl << endl;
            }
        }
    }
    else
        cout << "There is nobody in database what do you want to look for??!" << endl;


}
void removePersonFromDatabase()
{
    if (peopleInDataBase > 0)
    {
        short index;
        cout << "Who do you want to remove? Type index: " << endl;
        cin >> index;

        if (peopleInDataBase >= index)
        {
            for (short k = index; k < peopleInDataBase; k++)
            {
                people[k-1].name = people[k].name;
                people[k-1].surname = people[k].surname;
                people[k-1].age = people[k].age;
                people[k-1].telephone = people[k].telephone;
            }

            peopleInDataBase--;
            savePeopleToFile();
        }
        else
            cout << "There is nobody like that" << endl;
    }
    else
        cout << "There is nothing to remove" << endl;
}
