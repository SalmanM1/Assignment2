// Include the Assignment2 header file which contains the declarations for the classes used in this file.
#include "Assignment2.h"
#include <iostream>

using namespace std;

// Implementation of the Employee class
// Constructor for Employee, initializes hourly rate and weekly hours
Employee::Employee(double rate, double hours) : hourly_rate(rate), weekly_hours(hours) {}

// Implementation of the Professional class which inherits from Employee
Professional::Professional(double salary, double vacationDays) : Employee(0, 0), monthly_salary(salary), days_of_vacation(vacationDays) {}

double Professional::calculate_weekly_salary() const {
    return monthly_salary / 4.0;
}

double Professional::health_care_contributions() const {
    return (monthly_salary / 4)* 0.05;
}

double Professional::vacation_days_earned() {
    return 1; 
}

// Implementation of the NonProfessional class which inherits from Employee
NonProfessional::NonProfessional(double rate, double hours) : Employee(rate, hours), total_worked_hours(0) {}

double NonProfessional::calculate_weekly_salary() const {
    return hourly_rate * weekly_hours;
}

double NonProfessional::health_care_contributions() const {
    return (hourly_rate * weekly_hours) * 0.03;
}

double NonProfessional::vacation_days_earned() {
    total_worked_hours += weekly_hours;
    return 4;
}


int main() {
    // Test the functionality of the Single_Linked_List
    Single_Linked_List<int> list;
    list.push_back(10);
    list.push_front(5);
    list.insert(1, 7);
    list.remove(2);
    std::cout << "Expected Front: 5, Actual: " << list.front() << std::endl;
    std::cout << "Expected Back: 7, Actual: " << list.back() << std::endl;
    std::cout << "Expected Size: 2, Actual: " << list.size() << std::endl;
    std::cout << "-------------------\n";

    // Test the functionality of the Employee classes (Professional and NonProfessional)
    Professional prof(4000, 20);
    NonProfessional nonProf(25, 40);

    std::cout << "Expected Professional Weekly Salary: $" << (4000 / 4) << ", Actual: $" << prof.calculate_weekly_salary() << "\n";
    std::cout << "Expected Professional Health Care Contributions: $" << (4000 / 4 * 0.05) << ", Actual: $" << prof.health_care_contributions() << "\n";
    std::cout << "Expected Professional Vacation Days Earned This Week: " << (5 * 0.2) << " days, Actual: " << prof.vacation_days_earned() << " days\n";
    std::cout << "-------------------\n";
    std::cout << "Expected NonProfessional Weekly Salary: $" << (25 * 40) << ", Actual: $" << nonProf.calculate_weekly_salary() << "\n";
    std::cout << "Expected NonProfessional Health Care Contributions: $" << (25 * 40 * 0.03) << ", Actual: $" << nonProf.health_care_contributions() << "\n";
    std::cout << "Expected NonProfessional Vacation Days Earned This Week: " << (40 / 10.0) << " hours, Actual: " << nonProf.vacation_days_earned() << " hours\n";
    std::cout << "-------------------\n";

    return 0;
}