#include<bits/stdc++.h>
using namespace std;

struct Course {
    string courseName;
    int creditHours;
    float gradePoints;
};

class CGPACalculator {
private:
    vector<Course> courses;
public:
    void addCourse(string name, int credits, float gradePoints) {
        courses.push_back({name, credits, gradePoints});
    }

    float calculateCGPA(){
        float totalGradePoints = 0;
        int totalCredits = 0;
        for (auto& course : courses) {
            totalGradePoints += course.gradePoints * course.creditHours;
            totalCredits += course.creditHours;
        }
        return (totalCredits > 0) ? totalGradePoints / totalCredits : 0;
    }

    void displayGrades(){
        cout << "\nCourse Details:\n";
        cout << left << setw(20) << "Course Name"
             << setw(15) << "Credit Hours"
             << "Grade Points\n";
        for (auto& course : courses) {
            cout << left << setw(20) << course.courseName
                 << setw(15) << course.creditHours
                 << course.gradePoints << "\n";
        }
    }
};

int main() {
    CGPACalculator calculator;
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        string courseName;
        int creditHours;
        float gradePoints;
        cout << "\nEnter details for course " << (i + 1) << ":\n";
        cout << "Course Name: ";
        cin>>courseName;
        cout << "Credit Hours: ";
        cin >> creditHours;
        cout << "Grade Points: ";
        cin >> gradePoints;
        calculator.addCourse(courseName, creditHours, gradePoints);
    }
    calculator.displayGrades();
    float cgpa = calculator.calculateCGPA();
    cout << "\nCumulative Grade Point Average (CGPA): " << fixed << setprecision(2) << cgpa << "\n";
    return 0;
}
