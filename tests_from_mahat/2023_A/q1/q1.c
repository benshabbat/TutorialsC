#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *func(char *str) {
    // אורך המחרוזת החדשה יהיה כמו המחרוזת המקורית
    char *new_str = (char *)malloc(strlen(str) + 1);
    if (new_str == NULL) {
        return NULL; // אין אפשרות להקצות זיכרון
    }

    // תחילת מיקום התווים במחרוזת החדשה
    int new_index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        // אם התו הוא אות גדולכ באנגלית
        if (isupper(str[i])) {
            //מחזירים שגיאה
            return NULL;
        }
    }
    // עוברים על כל תו במחרוזת המקורית
    for (int i = 0; str[i] != '\0'; i++) {
        // אם התו הוא אות קטנה באנגלית
        if (islower(str[i])) {
            // מעתיקים אותו למקום הנכון במחרוזת החדשה
            new_str[new_index++] = str[i];
        }
    }

    // כותבים רווחים בין האותיות לסוף המחרוזת החדשה
    for (int i = 0; str[i] != '\0'; i++) {
        if (!islower(str[i])) {
            new_str[new_index++] = str[i];
        }
    }

    // כותבים את הספרות בסוף המחרוזת החדשה
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            new_str[new_index++] = str[i];
        }
    }

    // מסיימים את המחרוזת החדשה
    new_str[new_index] = '\0';

    return new_str;
}

int main() {
    char str[] = "1 hello my num is 23";
    char *new_str = func(str);
    if (new_str != NULL) {
        printf("New string: %s\n", new_str);
        free(new_str); // חשוב לשחרר את הזיכרון שנקצה
    } else {
        printf("Failed to allocate memory\n");
    }
    return 0;
}