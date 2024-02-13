#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int calories;
    float weight;
    int height;
    int timesCried;
    float temperature;
    bool hasLotsOfEnergy;
} BabyInfo;

typedef struct {
    char *momName;
    char *dadName;
    BabyInfo babyInfo;
} Family;

int main() {
    // In just one line, set the following field values 
    // using designated initializers:
    // momName=Jennifer, dadName=Bob, babyInfo:weight = 5, hasLotsOfEnergy = true.
    Family family = { "Jennifer","Bob",{.weight=5,.hasLotsOfEnergy=true} };

    // Print the initialized values
    printf("%s %s %.1f %s\n", 
      family.momName, family.dadName, family.babyInfo.weight, 
      family.babyInfo.hasLotsOfEnergy ? "true" : "false");

    return 0;
}