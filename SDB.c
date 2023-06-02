#include "SDB.h"
#include <stdio.h>
#include<conio.h>
int8 last_entry = -1;

bool SDB_IsFull ()
{
    if (last_entry==9)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
uint8 SDB_GetUsedSize()
{
    return last_entry+1;
    
}
bool SDB_AddEntry(uint32 Student_ID,
                  uint32 Student_year,
                  uint32 Course1_ID,
                  uint32 Course1_grade,
                  uint32 Course2_ID,
                  uint32 Course2_grade,
                  uint32 Course3_ID,
                  uint32 Course3_grade,
                  student Db[])
{
    if (SDB_IsFull())
    {
        return 0;
    }
    else
    {
        int8 listIndex = last_entry+1;
        Db[listIndex].Student_ID = Student_ID;
        Db[listIndex].Student_year = Student_year;
        Db[listIndex].Course1_ID = Course1_ID;
        Db[listIndex].Course1_grade = Course1_grade;
        Db[listIndex].Course2_ID = Course2_ID;
        Db[listIndex].Course2_grade = Course2_grade;
        Db[listIndex].Course3_ID = Course3_ID;
        Db[listIndex].Course3_grade = Course3_grade;
        last_entry++;
        return 1;
    }
}
void SDB_DeletEntry (uint32 id, student Db[])
{
    int8 index = -1;
    for (int8 i = 0; i <= last_entry; i++)
    {
        if (Db[i].Student_ID == id)
        {
            index = i;
            break;
        }
        
    }
    if (index != -1)
    {
        for (int8 i = index+1; i <= last_entry; i++)
        {
            Db[i-1] = Db[i];
        }
        printf("User Deleted\n");
        last_entry--;
    }
    else
    {
        printf("User not found\n");
    }
    
}
bool SDB_ReadEntry (uint32 id, student Db[])
{
    int8 index = -1;
    for (int8 i = 0; i <= last_entry; i++)
    {
        if (Db[i].Student_ID == id)
        {
            index = i;
            break;
        }
        
    }
    if (index == -1)
    {
        printf("Not found\n");
        return 0;
    }
    else
    {
        printf("Student ID: %d\nStudent year: %d\nCourse 1 ID: %d\nCourse 1 grade: %d\nCourse 2 ID: %d\nCourse 2 grade: %d\nCourse 3 ID: %d\nCourse 3 Grade: %d\n",Db[index].Student_ID,Db[index].Student_year,Db[index].Course1_ID,Db[index].Course1_grade,Db[index].Course2_ID,Db[index].Course2_grade,Db[index].Course3_ID,Db[index].Course3_grade);
        return 1;
    }
    
    
}
void SDB_GetList (student Db[])
{
    for (int8 i = 0; i <= last_entry; i++)
    {
        printf("Student ID: %d\n",Db[i].Student_ID);
    }
    
}
bool SDB_IdExists (uint32 id,student Db[])
{
    for (int8 i = 0; i <= last_entry; i++)
    {
        if (Db[i].Student_ID == id)
        {
            return 1;
        }
        
    }
    return 0;
}



void SDB_APP ()
{
    student StudentDB[10];
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    uint8 option;
    
    
    do
    {
        printf("1. To add entry, enter 1\n2. To get used size of database, enter 2\n3. To read student data, enter 3\n4. To get the list of all student IDs, enter 4\n5. To check if ID exists, enter 5\n6. To delete student data, enter 6\n7. To check if database is full, enter 7\n8. To exit enter 0\n");
        scanf("%d",&option);
        fflush(stdin);
        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("Enter data: ");
            scanf("%d%d%d%d%d%d%d%d",&Student_ID,&Student_year,&Course1_ID,&Course1_grade,&Course2_ID,&Course2_grade,&Course3_ID,&Course3_grade);
            fflush(stdin);
            if(SDB_AddEntry(Student_ID, Student_year, Course1_ID, Course1_grade, Course2_ID, Course2_grade, Course3_ID, Course3_grade, StudentDB))
            {
                printf("User added\n");
            }
            else
            {
                printf("DB Full\n");
            }
            break;
        case 2:
            printf("Used size: %d", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter student id: ");
            scanf("%d", &Student_ID);
            fflush(stdin);
            SDB_ReadEntry(Student_ID,StudentDB);
            break;
        case 4:
            SDB_GetList(StudentDB);
            break;
        case 5:
            printf("Enter student id: ");
            scanf("%d", &Student_ID);
            fflush(stdin);
            if(SDB_IdExists(Student_ID,StudentDB))
            {
                printf("This id exists\n");
            }
            else
            {
                printf("Not found\n");
            }
            
            break;
        case 6:
            printf("Enter student id: ");
            scanf("%d", &Student_ID);
            fflush(stdin);
            SDB_DeletEntry(Student_ID,StudentDB);
            break;
        case 7:
            if(SDB_IsFull())
            {
                printf("Database is full");
            }
            else
            {
                printf("Database is not full");
            }
            
            break;
        
        default:
            break;
        }
        printf("Enter anything to continue");
        getchar();
        fflush(stdin);
        printf("\e[1;1H\e[2J"); //Escape sequence to clear terminal NOTE: might not work on certain terminals
    } while (option != 0);
    
}