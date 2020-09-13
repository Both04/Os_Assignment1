#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>  

void main(int argc, char const *argv[]) //เรียกใช้ค่า input ทีได้รับมาซึ่งมีค่าเป็น int,char
{

  int arg = atoi(argv[1]);  //ฟังก์ชันเปลี่ยนค่าจากstring ให้เป็นจำนวนเต็ม
 
  printf("OS 2563 Assignment 1\n");                         // print ข้อความ รหัส และวิชา
  printf("1. 6140207215 Mr.Kantaphon Hothong\n");           // print ข้อมูลของคนแรก
  printf("2. 6140201861 Mr.Nattanon Phumsrikeaw\n");        // print ข้อมูลของคนที่สอง
  printf("3. 6140202703 Miss.Thidarat Phromudom\n");        // print ข้อมูลของคนที่สาม
  printf("\n");                                             // เป็นการ print ค่าเพื่อให้เว้นบรรทัด

  if (fork() == 0)      //คืนค่าสร้าง Child Process
  {
    if (fork() == 0)    //คืนค่าสร้าว Parent Process
    {
      printf("PID is %d", getpid());   // print ค่าpid ด้วยฟังก์ชัน getpid()
      sleep(3); // sleep รอผมลัพธ์ สัก 3 วินาที
      int M1 = arg * 3;                // นำค่าที่ input เข้ามาคูณสามและประกาศเป็นตัวแปร int
      printf(" ,%d\n", M1);            // print ค่าที่ได้จากตัวแปร M1 เป็นจำนวนเต็มบวก 
      
    }
    else
    {
      while (wait(NULL) > 0); //สร้างwhile loop เพื่อรอการprocess ครั้งถัดไป
      {
        printf("Parent PID is %d",getpid());  // print ค่าparent pid ด้วยฟังก์ชัน getpid()
        sleep(3); // sleep รอผมลัพธ์ สัก 3 วินาที
        int M2 = arg * 2;                     // นำค่าที่ input เข้ามาคูณสองและประกาศเป็นตัวแปร int
        printf(" ,%d\n", M2);                 // print ค่าที่ได้จากตัวแปร M2 เป็นจำนวนเต็มบวก
      }   
    }
  }

  else //เรียก Grandparent Process
  {
  
      while (wait(NULL) > 0); //สร้างwhile loop เพื่อรอการprocess ครั้งถัดไป
      {
        printf("Grandparent PID is %d",getpid());  // print ค่าgrandparent pid ด้วยฟังก์ชัน getpid()
        sleep(3); // sleep รอผมลัพธ์ สัก 3 วินาที
        int M3 = arg * 1;                          // นำค่าที่ input เข้ามาคูณหนึ่งและประกาศเป็นตัวแปร int
        printf(" ,%d\n", M3);                      // print ค่าที่ได้จากตัวแปร M3 เป็นจำนวนเต็มบวก
      }
      
      
    }

}
