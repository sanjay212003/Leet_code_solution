//Employee Attendence System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct EmployeeAttendance {
    char name[50];
    char checkInTime[20];
    char checkOutTime[20];
    struct EmployeeAttendance *next;
} EmployeeAttendance;
void addAttendance(EmployeeAttendance **head, char *name, char *checkInTime, char *checkOutTime) {
    EmployeeAttendance *newRecord = (EmployeeAttendance *)malloc(sizeof(EmployeeAttendance));
    if (newRecord == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newRecord->name, name);
    strcpy(newRecord->checkInTime, checkInTime);
    strcpy(newRecord->checkOutTime, checkOutTime);
    newRecord->next = NULL;
    if (*head == NULL) {
        *head = newRecord;
    } else {
        EmployeeAttendance *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        } temp->next = newRecord;
 }  }
void displayAttendance(EmployeeAttendance *head) {
    if (head == NULL) {
        printf("No attendance records found.\n");
        return;
    }
    printf("Employee Attendance Records:\n");
    while (head != NULL) {
        printf("Name: %s,\n Check-In Time: %s\n, Check-Out Time: %s\n", head->name, head->checkInTime, head->checkOutTime);
printf(“\n-------------------------------------------------------------------------\n”);
        head = head->next;
    }
}

int main() {
    EmployeeAttendance *attendanceRecords = NULL;
    addAttendance(&attendanceRecords, "John", "09:00 AM", "05:00 PM");
    addAttendance(&attendanceRecords, "Alice", "08:30 AM", "04:45 PM");
    addAttendance(&attendanceRecords, "Bob", "09:15 AM", "05:30 PM");
    displayAttendance(attendanceRecords);
    return 0;
}
