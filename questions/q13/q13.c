#include "Question.h"
#include <stdio.h>
#include <stdlib.h>

void print_student_data(Student const* to_print) {
    if (to_print) {
        printf("Name: %s\n", student_get_name(to_print));
        printf("Birth Date: %d/%d/%d\n",
            date_get_day(datetime_get_date(student_get_birth_date(to_print))),
            date_get_month(datetime_get_date(student_get_birth_date(to_print))),
            date_get_year(datetime_get_date(student_get_birth_date(to_print))));
        printf("Track: %d\n", student_get_track(to_print));
        printf("Height: %d cm\n", student_get_height(to_print));
        printf("ID: ");
        const uint8_t* id = student_get_id(to_print);
        for (int i = 0; i < 9; ++i) {
            printf("%d", id[i]);
        }
        printf("\n");
    }
}


Date* date_create(int day, int month, int year)
{
    // Allocate memory for the Date struct
    Date* new_date = (Date*)malloc(sizeof(Date));

    // Check if memory allocation was successful
    if (new_date == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the Date struct members
    new_date->day = day;
    new_date->month = month;
    new_date->year = year;

    // Return a pointer to the created Date struct
    return new_date;
}

int date_get_day(const Date* date) {

    return date->day;
}

int date_get_month(const Date* date) {
    return date->month;
}

int date_get_year(const Date* date) {
    return date->year;
}

void date_free(Date* to_free)
{
    free(to_free);
}

Time* time_create(int hour, int minute, int second)
{
    // Allocate memory for the Date struct
    Time* new_time = (Time*)malloc(sizeof(Time));

    // Check if memory allocation was successful
    if (new_time == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the Time struct members
    new_time->hour = hour;
    new_time->minute = minute;
    new_time->second = second;

    // Return a pointer to the created Time struct
    return new_time;
}

int time_get_hour(const Time* time) {
    // TODO: Implement this function
    return time->hour;
}

int time_get_minute(const Time* time) {
    // TODO: Implement this function
    return time->minute;
}

int time_get_second(const Time* time) {
    // TODO: Implement this function
    return time->second;
}

void time_free(Time* to_free)
{
    free(to_free);
}

DateTime* datetime_create(Date* date, Time* time)
{
    // Allocate memory for the DateTime struct
    DateTime* new_datetime = (DateTime*)malloc(sizeof(DateTime));

    if (new_datetime == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Assign the provided Date and Time structs to the DateTime struct members
    new_datetime->date = date;
    new_datetime->time = time;

    // Return a pointer to the created DateTime struct
    return new_datetime;
}

const Date* datetime_get_date(const DateTime* dateTime) {

    return &(dateTime->date);
}

const Time* datetime_get_time(const DateTime* dateTime) {
    // TODO: Implement this function
    return &(dateTime->time);
}

void datetime_free(DateTime* to_free)
{
    free(to_free);
}

const char* student_get_name(const Student* student) {
    // TODO: Implement this function
    return student->name;
}

const DateTime* student_get_birth_date(const Student* student) {
    // TODO: Implement this function
    return &(student->birth_date);
}

const Track student_get_track(const Student* student) {
    // TODO: Implement this function
    return student->track;
}

uint8_t student_get_height(const Student* student) {
    // TODO: Implement this function
    return student->height;
}

const uint8_t* student_get_id(const Student* student) {
    // TODO: Implement this function
    return student->id;
}

Student* student_create(DateTime* birthDate, char* name, Track track, uint8_t height, uint8_t* id) {
    // Allocate memory for the DateTime struct
    Student* new_student = (DateTime*)malloc(sizeof(DateTime));

    // Check if memory allocation was successful
    if (new_student == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Assign the provided Date and Time pointers to the DateTime struct members
    new_student->birth_date = birthDate;
    new_student->name = name;
    new_student->track = track;
    new_student->height = height;
    new_student->id = id;

    // Return a pointer to the created DateTime struct
    return new_student;
}

void student_free(Student* to_free) {
    free(to_free);
}
