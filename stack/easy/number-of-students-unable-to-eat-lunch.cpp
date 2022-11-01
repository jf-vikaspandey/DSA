#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int sizeStudent = students.size();
    queue<int> studentQue;

    for (int i = 0; i < sizeStudent; i++)
    {
        studentQue.push(students[i]);
    }

    int rotation = 0;
    int i = 0;
    while (studentQue.size() && rotation < studentQue.size())
    {
        if (studentQue.front() == sandwiches[i])
        {
            rotation = 0;
            i++;
            studentQue.pop();
        }
        else
        {

            int currentStudent = studentQue.front();
            studentQue.pop();
            studentQue.push(currentStudent);
            rotation++;
        }
    }

    return rotation;
}

int main()
{

    vector<int> student;
    student.push_back(1);
    student.push_back(1);
    student.push_back(1);

    student.push_back(0);
    student.push_back(0);
    student.push_back(1);

    vector<int> sandwiches;
    sandwiches.push_back(1);
    sandwiches.push_back(0);
    sandwiches.push_back(0);
    sandwiches.push_back(0);
    sandwiches.push_back(1);
    sandwiches.push_back(1);

    int a = countStudents(student, sandwiches);

    cout << a;
    return 0;
}