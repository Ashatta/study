#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Table
{
    public:
        Table(int s) :
            size(s),
            list(new int[s + 1])
        { 
            for (int i = 0; i <= size; ++i)
                list[i] = 0;
        }

        ~Table() { delete[] list; }
        void print();
        void add(int student, int assistant);
        void makeList();

    private:
        int size;
        int * list;
};

void Table::add(int student, int assistant)
{
    if (student > 3 && student <= size &&             
            assistant <= size && list[student] == 0)  
        list[student] = assistant;    
}

void Table::makeList()
{
    for (int i = 4; i <= size; ++i)
        if (list[i] > 3)
        {
            int variant = list[i];
            while (variant > 3)
            {
                variant = list[variant];
                if (variant == list[i]) // если студенты "списали друг у
                    variant = 0;        // друга", считается, что ни один 
            }                           // из них не выполнил задание
            list[i] = variant;
        }
}

void Table::print()
{
    for (int i = 4; i <= size; ++i)
        cout << i << ' ' << list[i] << endl;
}

int main()
{
    string input;
    clog << "Enter name of the input file: ";
    cin >> input;
    ifstream in(input.c_str());
    if (!in)
    {
        cerr << "Error reading from file" << endl;
        return 1;
    }
    
    int studentsNum = 0;
    in >> studentsNum;
    Table list(studentsNum);

    int student = 0;
    int assistant = 0;
    for (int i = 0; !in.eof() && i < studentsNum; ++i)
    {
        in >> student >> assistant;
        list.add(student, assistant);
    }

    list.makeList();

    clog << "The first number is the number of student,\n"
         << "the second one is the number of variant\n" 
         << "'0' means this student must be expelled" << endl;
    list.print();

    in.close();
    return 0;
}

