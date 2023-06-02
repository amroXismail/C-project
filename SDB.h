#include "STD.h"
#ifndef SDB_H_
#define SDB_H_
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 
} student;

bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry(uint32 Student_ID,
                  uint32 Student_year,
                  uint32 Course1_ID,
                  uint32 Course1_grade,
                  uint32 Course2_ID,
                  uint32 Course2_grade,
                  uint32 Course3_ID,
                  uint32 Course3_grade,
                  student* DbPtr);
void SDB_DeletEntry (uint32 id, student Db[]);
bool SDB_ReadEntry (uint32 id,student Db[]);
void SDB_GetList (student Db[]);
bool SDB_IdExists (uint32 id,student Db[]);
void SDB_APP ();
#endif