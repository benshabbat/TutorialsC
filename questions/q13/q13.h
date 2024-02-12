#ifndef __Q_H__
#define __Q_H__

#include <stdint.h>

// Forward declarations of structs
typedef struct Date_t {
	int day;
	int month;
	int year;
} Date;

Date* date_create(int day, int month, int year);
int date_get_day(const Date* date);
int date_get_month(const Date* date);
int date_get_year(const Date* date);
void date_free(Date* to_free);

typedef struct Time_t {
	int hour;
	int minute;
	int second;
} Time;
Time* time_create(int hour, int minute, int second);
int time_get_hour(const Time* time);
int time_get_minute(const Time* time);
int time_get_second(const Time* time);
void time_free(Time* to_free);


typedef struct DateTime_t {
	Date date;
	Time time;
} DateTime;
DateTime* datetime_create(Date* date, Time* time);
const Date* datetime_get_date(const DateTime* dateTime);
const Time* datetime_get_time(const DateTime* dateTime);

// Remember: Free recursively all members
void datetime_free(DateTime* to_free);


// Enum for tracks of study
typedef enum {
	Embedded, TODO_FILL_MY_VALUES
} Track;


// Struct for student information
typedef struct Student_t {
	DateTime birth_date;
	const char* name; 
	Track track;
	uint8_t height;
	const uint8_t* id;
} Student;

// Function prototypes for student management

/// @brief Creates a new student with the given field values.
/// @param id The ID of the student given as an array of 9 elements!
Student* student_create(DateTime* birthDate, char* name, Track track, uint8_t height, uint8_t* id);

// Remember: Free recursively all members
void student_free(Student* to_free);

// Getter function prototypes for student information
const char* student_get_name(const Student* student);
const DateTime* student_get_birth_date(const Student* student);
const Track student_get_track(const Student* student);
uint8_t student_get_height(const Student* student);
const uint8_t* student_get_id(const Student* student);


// This function is already implemented for you
void print_student_data(Student const* to_print);


#endif