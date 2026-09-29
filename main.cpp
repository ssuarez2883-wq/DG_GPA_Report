#include <iostream> // lets us print to console
#include <fstream> // lets us read the GPA report
#include <sstream> // lets us split lines using stringstream
#include <string> // lets us use strings

int main() {
    // creates constant variable so code is easier to find
    // CHANGE THIS VARIABLE NUMBER BASED ON WHATEVER GPA YOU WANT AND ABOVE
    const double GPA_THRESHOLD = 3.5;

    // opens file
    std::ifstream file("DG_SP26_Grade_Report_1.csv");

    if (!file.is_open()) {
        //edge case, checks to see if there is an error and stops program before failing
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;

    // skips first lines of file
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);

    double sumGPA=0;
    int counter=0;

    // reads each student row by row
    while (std::getline(file, line)) {
        //breaks row apart by commas
        std::stringstream ss(line);

        std::string column; // stores each column
        std::string lastName; // stores lastname column
        std::string firstName; // stores firstname column
        std::string gpaStr; // stores gpa column

        int columnIndex=0; // keeps track of which column we are on, like an index

        // reads each column separated by commas
        while (std::getline(ss, column, ',')) {
            if (line.rfind("Sorority,", 0) != 0)
                continue;

            //sets each variable equal to the corresponding column
            if (columnIndex == 3) {
                lastName = column;
            }
            if (columnIndex == 4) {
                firstName = column;
            }
            if (columnIndex == 6) {
                gpaStr = column;
            }

            columnIndex++; // goes to the next column
        }

        // if gpa cell is empty, skip
        if (gpaStr.empty()) continue;

        //converts string to a number/double
        double gpa = std::stod(gpaStr);
        const bool PRINT_CONDITION = gpa >= GPA_THRESHOLD;

        sumGPA+=gpa;
        counter++;


        //if gpa >= our threshold, print name!

        if (PRINT_CONDITION) {
            std::cout << firstName << " " << lastName << std::endl; //<< " - GPA: " << gpa << std::endl;
        }

    }
    //std::cout << sumGPA/counter << std::endl;
    return 0;
}