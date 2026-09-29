DG Grade Report Filter (FA25 Term GPA)
Sunny Suarez, Director of Scholarship 2026

This C++ program reads a CSV grade report and prints the names of members whose FA25 Term GPA is at or above a chosen threshold (default: 3.5).

Expected CSV Format

Your CSV should contain columns like:

Org Type, Council, Chapter, Last Name, First Name, Student ID, FA25 Term GPA, Institution GPA, Cumulative GPA, Status, Notes

Example row:

Sorority,CPA,Delta Gamma,Alexander,Avery,131405869,3.75,3.73,3.73,Active,

Project Structure

Make sure your project folder looks like this:

CMakeLists.txt

main.cpp

grade_report_file_name.csv

cmake-build-debug/

⚠️ The CSV file must be in the same folder as CMakeLists.txt
⚠️ Do NOT put it inside cmake-build-debug

How to Run in CLion

Place grade_report.csv in the project root folder.

Open CLion.

Click Run.

If you see:

"Could not open grade_report.csv"

Fix it by:

Clicking Run

Clicking Edit Configurations

Setting Working Directory to the folder that contains CMakeLists.txt

What the Program Does

For each student row, the program:

Skips the first 3 lines (extra header/title lines)

Reads Last Name (column index 3)

Reads First Name (column index 4)

Reads FA25 Term GPA (column index 6)

Converts GPA from text to a number

Prints the name if GPA ≥ threshold

Example output:

Avery Alexander - GPA: 3.75

Changing the GPA Requirement

Inside main() there is a constant:

const double GPA_THRESHOLD = 3.5;

To change the requirement, edit only this value.

Example:

const double GPA_THRESHOLD = 3.2;

Using a constant makes the rule easy to modify.

Column Indexes Used

The program uses these column numbers (counting starts at 0):

0 → Org Type

1 → Council

2 → Chapter

3 → Last Name

4 → First Name

5 → Student ID

6 → FA25 Term GPA

If your CSV format changes, update these lines in the code:

if (columnIndex == 3) lastName = column;
if (columnIndex == 4) firstName = column;
if (columnIndex == 6) gpaStr = column;
Why the Program Skips the First 3 Lines

Your exported CSV contains extra lines before the real header.

The program skips them using:

std::getline(file, line);
std::getline(file, line);
std::getline(file, line);

If your file format changes, adjust the number of skipped lines.

Common Problems
1. "stod: no conversion"

This means the GPA column contained something that was not a number (blank cell or text).
The program uses try/catch to safely skip those rows.

2. File will not open

Make sure grade_report.csv is in the correct folder or use a full path:

std::ifstream file("C:/Users/YourName/Desktop/grade_report.csv");
3. Names or GPA look incorrect

Double-check that the column indexes match your CSV layout.

Limitations

The program splits rows using commas.

If a field contains a comma inside quotes, the simple parser may not handle it correctly.

For standard exported grade reports, this usually works fine.

Possible Future Improvements

Count how many members qualify

Save qualifying names to a new CSV file

Sort by GPA highest to lowest

Allow the user to enter the GPA threshold at runtime