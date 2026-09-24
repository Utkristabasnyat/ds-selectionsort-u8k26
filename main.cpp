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

    // Selection sort by student ID in ascending order.
    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < count; j++)
        {
            if (students[j].id < students[minIndex].id)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }

    cout << "Student records sorted by ID." << endl;

    // Display the first five records to verify the sort.
    cout << "\nFirst five sorted records:" << endl;

    for (int i = 0; i < 5 && i < count; i++)
    {
        cout << students[i].id << " "
             << students[i].score << endl;
    }

    return 0;
}