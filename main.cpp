#include <iostream>
#include <fstream>
using namespace std;

const int MAX_STUDENTS = 150;

// Each record stores a student ID and exam score.
struct Student
{
    int id;
    double score;
};

int main()
{
    Student students[MAX_STUDENTS];
    int count = 0;

    ifstream inputFile("210-lab-13-grades.txt");

    if (!inputFile)
    {
        cout << "Error opening input file." << endl;
        return 1;
    }

    // Read student records into the array of structs.
    while (count < MAX_STUDENTS &&
           inputFile >> students[count].id >> students[count].score)
    {
        count++;
    }

    inputFile.close();

    cout << "Read " << count << " student records" << endl;

    return 0;
}