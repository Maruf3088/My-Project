#include <stdio.h>
#include <string.h>

struct student
{
    char name[100];
    char ID[100];
    float merit;
};

struct subject
{
    char sub_name[100];
    float mark;
    float sub_result;
    float credit;
    float cgpa;
    float multiplication;
};

int main()
{
    int m, n;
    printf("\n\n**************************************************************\n");
    printf("*                    Welcome to My Program                   *\n");
    printf("**************************************************************\n\n");
    printf("\n\n----------------------- CGPA Calculator -----------------------\n\n");
    printf("Enter the Amount of Students : ");
    scanf("%d", &m);
    struct student students[m];

    for (int x = 0; x < m; x++)
    {
        printf("\n");
        printf("Enter student %d Full Name:", x + 1);
        scanf(" %[^\n]s", students[x].name);
        printf("Enter Student %d  ID:", x + 1);
        scanf(" %[^\n]s", students[x].ID);
        printf("\nEnter The Amount of Subjects :");
        scanf("%d", &n);

        struct subject subjects[n];

        for (int i = 0; i < n; i++)
        {
            printf("Subject %d Name:", i + 1);
            scanf(" %[^\n]s", subjects[i].sub_name);
            printf("Mark:");
            scanf("%f", &subjects[i].mark);
            subjects[i].sub_result = subjects[i].mark;
            printf("Credit Hour:");
            scanf("%f", &subjects[i].credit);
            printf("\n");
            if ((subjects[i].sub_result <= 100) && (subjects[i].sub_result >= 80))
            {
                subjects[i].sub_result = 4.00;
            }

            else if ((subjects[i].sub_result <= 79) && (subjects[i].sub_result >= 75))
            {
                subjects[i].sub_result = 3.75;
            }
            else if ((subjects[i].sub_result <= 74) && (subjects[i].sub_result >= 70))
            {
                subjects[i].sub_result = 3.50;
            }
            else if ((subjects[i].sub_result <= 69) && (subjects[i].sub_result >= 65))
            {
                subjects[i].sub_result = 3.25;
            }
            else if ((subjects[i].sub_result <= 64) && (subjects[i].sub_result >= 60))
            {
                subjects[i].sub_result = 3.00;
            }
            else if ((subjects[i].sub_result <= 59) && (subjects[i].sub_result >= 55))
            {
                subjects[i].sub_result = 2.75;
            }
            else if ((subjects[i].sub_result <= 54) && (subjects[i].sub_result >= 50))
            {
                subjects[i].sub_result = 2.50;
            }
            else if ((subjects[i].sub_result <= 49) && (subjects[i].sub_result >= 45))
            {
                subjects[i].sub_result = 2.25;
            }
            else if ((subjects[i].sub_result <= 44) && (subjects[i].sub_result >= 40))
            {
                subjects[i].sub_result = 2.00;
            }
            else
            {
                subjects[i].sub_result = 0.00;
            }

            subjects[i].multiplication = subjects[i].sub_result * subjects[i].credit;
        }

        float credit_sum = 0.00;
        float total_grade = 0.00;

        for (int j = 0; j < n; j++)
        {
            credit_sum += subjects[j].credit;
            total_grade += subjects[j].multiplication;
        }

        float FINAL_RESULT = (total_grade / credit_sum);
        students[x].merit = FINAL_RESULT;

        printf("\n");
        printf("----------------- STUDENT %d RESULT -----------------\n\n", x + 1);
        printf("Student Name : %s\n", students[x].name);
        printf("Student ID: %s\n", students[x].ID);
        printf("\n");

        for (int l = 0; l < n; l++)
        {
            printf("%s Mark : %.2f   ", subjects[l].sub_name, subjects[l].mark);
            printf("Grade : %.2f   ", subjects[l].sub_result);
            printf("Credit Hour : %.2f\n", subjects[l].credit);
            printf("\n");
        }
        printf("\n");
        printf("Total Credit Hour:%.2f\n\n", credit_sum);
        printf("CGPA => %.2f\n\n", FINAL_RESULT);
        printf("------------------------- 0 -------------------------\n");
    }

    for (int j = 0; j < m - 1; j++)
    {
        for (int k = j + 1; k < m; k++)
        {
            if (students[j].merit < students[k].merit)
            {
                struct student temp = students[j];
                students[j] = students[k];
                students[k] = temp;
            }
        }
    }

    printf("\n\n------------ Merit List -------------\n\n");
    for (int l = 0; l < m; l++)
    {
        printf("%d. %s => %s => %.2f\n", l + 1, students[l].name, students[l].ID, students[l].merit);
        printf("\n");
    }

    return 0;
}