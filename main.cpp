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

    // Open the required output file.
    ofstream outputFile("210-lab-13-grades-sorted.txt");

    if (!outputFile)
    {
        cout << "Error opening output file." << endl;
        return 1;
    }

    // Write all sorted student records to the output file.
    for (int i = 0; i < count; i++)
    {
        outputFile << students[i].id << " "
                   << students[i].score << endl;
    }

    outputFile.close();

    cout << "Sorted results written to "
         << "210-lab-13-grades-sorted.txt" << endl;

    // Start with the first student as both minimum and maximum.
    int minIndex = 0;
    int maxIndex = 0;

    // Search through all scores for the minimum and maximum.
    for (int i = 1; i < count; i++)
    {
        if (students[i].score < students[minIndex].score)
        {
            minIndex = i;
        }

        if (students[i].score > students[maxIndex].score)
        {
            maxIndex = i;
        }
    }

    cout << "\n--- Summary Statistics ---" << endl;

    cout << "Minimum Score: "
         << students[minIndex].score
         << " (Student ID: "
         << students[minIndex].id << ")" << endl;

    cout << "Maximum Score: "
         << students[maxIndex].score
         << " (Student ID: "
         << students[maxIndex].id << ")" << endl;

    return 0;
}