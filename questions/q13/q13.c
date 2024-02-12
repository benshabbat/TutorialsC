#include "Question.h"
#include <stdio.h>


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

    }

    // Initialize the Date struct members
    new_date->day = day;
    new_date->month = month;
    new_date->year = year;

    // Return a pointer to the created Date struct
    return new_date
}

int date_get_day(const Date* date) {
    
    return date->day;
}

int date_get_month(const Date* date) {
    // TODO: Implement this function
    return date->month;
}

int date_get_year(const Date* date) {
    // TODO: Implement this function
    return 0;
}

void date_free(Date* to_free)
{
}

Time* time_create(int hour, int minute, int second)
{
    return NULL;
}

int time_get_hour(const Time* time) {
    // TODO: Implement this function
    return 0;
}

int time_get_minute(const Time* time) {
    // TODO: Implement this function
    return 0;
}

int time_get_second(const Time* time) {
    // TODO: Implement this function
    return 0;
}

void time_free(Time* to_free)
{
}

DateTime* datetime_create(Date* date, Time* time)
{
    return NULL;
}

const Date* datetime_get_date(const DateTime* dateTime) {
    // TODO: Implement this function
    return NULL;
}

const Time* datetime_get_time(const DateTime* dateTime) {
    // TODO: Implement this function
    return NULL;
}

void datetime_free(DateTime* to_free)
{
}

const char* student_get_name(const Student* student) {
    // TODO: Implement this function
    return NULL;
}

const DateTime* student_get_birth_date(const Student* student) {
    // TODO: Implement this function
    return NULL;
}

const Track student_get_track(const Student* student) {
    // TODO: Implement this function
    return TODO_FILL_MY_VALUES;
}

uint8_t student_get_height(const Student* student) {
    // TODO: Implement this function
    return 0;
}

const uint8_t* student_get_id(const Student* student) {
    // TODO: Implement this function
    return NULL;
}

Student* student_create(DateTime* birthDate, char* name, Track track, uint8_t height, uint8_t* id) {
    // TODO: Implement this function
    return NULL;
}

void student_free(Student* to_free) {
    // TODO: Implement this function
}
