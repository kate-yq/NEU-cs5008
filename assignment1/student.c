#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int id;
    char *name;
    float gpa;
} student_type;

void changeID(student_type* std){
    printf("Do you want to change the student ID?(y/n)\n");

    char ans;
    scanf(" %c", &ans);

    if (ans == 'y' || ans == 'Y'){
        printf("Please input new ID: ");
        scanf("%d", &std->id);
    }
    printf("Now the name is: %d.\n", std->id);
}

void changeName(student_type* std){
    printf("Do you want to change the student name?(y/n)\n");

    char ans;
    scanf(" %c", &ans);

    if (ans == 'y' || ans == 'Y'){
        printf("Please input new name: ");
        scanf("%s", std->name);
    }
    printf("Now the name is: %s.\n", std->name);
}

void changeGPA(student_type* std){
    printf("Do you want to change the student GPA?(y/n)\n");
    
    char ans;
    scanf(" %c", &ans);

    if (ans == 'y' || ans == 'Y'){
        float newGPA;
        printf("Please input new GPA: ");
        scanf("%f", &newGPA);

        if (newGPA<0 || newGPA>4){
            printf("Cannot change to this GPA.\n");
            printf("The GPA remains %.2f\n", std->gpa);
        } else {
            std->gpa = newGPA;
            printf("Now the GPA is: %.2f\n", std->gpa);
        }
    }
}

int main() {
    student_type student;
    student.name = (char*)malloc(256);

    printf("Please input the Name, StudentID, and GPA for the student.\n");
    printf("Name: ");
    scanf("%s", student.name);
    printf("StudentId: ");
    scanf("%d", &student.id);
    printf("GPA: ");
    scanf("%f", &student.gpa);

    changeName(&student);
    changeID(&student);
    changeGPA(&student);

    free(student.name);
    return 0;
}