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
    Date* new_date = malloc(sizeof(Date));
    if (new_date) {
        new_date->day = day;
        new_date->month = month;
        new_date->year = year;
    }
    return new_date;
}

int date_get_day(const Date* date) {

    return date ? date->day : -1;
}

int date_get_month(const Date* date) {
    return date ? date->month : -1;
}

int date_get_year(const Date* date) {
    return date ? date->year : -1;
}

void date_free(Date* to_free)
{
    free(to_free);
}

Time* time_create(int hour, int minute, int second)
{
    Time* new_time = malloc(sizeof(Date));
    if (new_time) {
        new_time->hour = hour;
        new_time->minute = minute;
        new_time->second = second;
    }
    return new_time;
}

int time_get_hour(const Time* time) {
    // TODO: Implement this function
    return time ? time->hour : -1;
}

int time_get_minute(const Time* time) {
    // TODO: Implement this function
    return time ? time->minute : -1;
}

int time_get_second(const Time* time) {
    // TODO: Implement this function
    return time ? time->second : -1;
}

void time_free(Time* to_free)
{
    free(to_free);
}

DateTime* datetime_create(Date* date, Time* time)
{
    DateTime* new_datetime = malloc(sizeof(DateTime));
    if (new_datetime) {
        new_datetime->date = date;
        new_datetime->time = time;
    }
    return new_datetime;
}

const Date* datetime_get_date(const DateTime* dateTime) {

    return dateTime ? dateTime->date : NULL;
}

const Time* datetime_get_time(const DateTime* dateTime) {
    // TODO: Implement this function
    return dateTime ? dateTime->time : NULL;
}

void datetime_free(DateTime* to_free)
{
    if (to_free) {
        date_free(to_free->date);
        time_free(to_free->time);
        free(to_free);
    }
}

const char* student_get_name(const Student* student) {
    // TODO: Implement this function
    return student ? student->name : NULL;
}

const DateTime* student_get_birth_date(const Student* student) {
    // TODO: Implement this function
    return student ? student->birth_date : NULL;
}

const Track student_get_track(const Student* student) {
    // TODO: Implement this function
    return student->track;
}

uint8_t student_get_height(const Student* student) {
    // TODO: Implement this function
    return student ? student->height : 0;
}

const uint8_t* student_get_id(const Student* student) {
    // TODO: Implement this function
    return student ? student->id : NULL;
}

Student* student_create(DateTime* birthDate, char* name, Track track, uint8_t height, uint8_t* id) {
    Student* new_student = malloc(sizeof(Student));
    if (new_student) {
        new_student->birth_date = birthDate;
        new_student->name = name; 
        new_student->track = track;
        new_student->height = height;
        memcpy(new_student->id, id, 9 * sizeof(uint8_t));
    }
    return new_student;
}

void student_free(Student* to_free) {
    if (to_free) {
        datetime_free(to_free->birth_date);
        free(to_free->name);
        free(to_free);
    }
}
