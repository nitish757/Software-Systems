/*============================================================== 
Name : 27d.c
Author : Nitish Mahapatre
Description:Write a program to execute ls -Rl by the following system calls
                d. execv
Date: 31th Aug, 2024
=================================================================
*/
#include<stdio.h>
#include<unistd.h>
void main(){
    printf("Executing 'ls -Rl' using execv:\n");
    char *argv_v[] = { "ls", "-Rl", NULL };
    execv("/bin/ls", argv_v);
    perror("execv failed");
}
/*================================================================
Output:
Executing 'ls -Rl' using execv:
.:
total 468
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1541 Aug 30 22:08  10.c
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 18608 Aug 27 22:46  11
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1723 Aug 30 22:01  11.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1540 Aug 30 22:02  12.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1353 Aug 31 11:06  13.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1502 Aug 29 15:54  14.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   772 Aug 29 15:55  15.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1383 Aug 30 15:53  16a.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1372 Aug 30 16:11  16b.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1128 Aug 31 11:51  17a.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  2119 Aug 31 12:00  17b.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   587 Aug 31 11:27  17sample.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1971 Aug 31 12:18  18a.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  2175 Aug 31 14:41  18b.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   737 Aug 31 12:13  18c.c
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16672 Aug 31 12:19  18exe
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   800 Aug 30 19:57  19.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1135 Aug 31 12:10  20.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   845 Aug 30 22:48  21.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1410 Aug 30 23:29  22.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1083 Aug 30 23:53  23.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1039 Aug 31 01:24  24.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1990 Aug 31 01:39  25.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   884 Aug 31 15:02  26.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  6657 Aug 31 15:19  27a.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  6720 Aug 31 15:30  27b.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   210 Aug 31 15:36 "27c'.c"
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  6899 Aug 31 15:43  27c.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   498 Aug 31 15:45  27d.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1024 Aug 31 10:08  28.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   751 Aug 31 10:06 '28.h>'
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  2644 Aug 31 10:28  29.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   532 Aug 30 21:36  2.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   924 Aug 31 10:47  30.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   737 Aug 30 21:40  3.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   729 Aug 30 21:58  4.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1024 Aug 30 22:07  5.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   627 Aug 30 22:00  6.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   876 Aug 30 21:57  7.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   889 Aug 30 21:57  8.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre  1646 Aug 30 22:08  9.c
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16096 Aug 31 15:45  a.out
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   875 Aug 30 19:48  c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre   875 Aug 30 19:49  c.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 30 21:49  copy7
-rw-r--r-- 1 nitish-mahapatre nitish-mahapatre    19 Aug 30 21:53  copy8
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16256 Aug 24 17:20  creatfile
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16080 Aug 31 10:22  exe28
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16344 Aug 31 10:23  exe29
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16328 Aug 24 20:05  exe5
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16248 Aug 24 17:26  exe8
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16176 Aug 24 17:57  exe9
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre    44 Aug 24 17:22  file
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 24 20:06  file_0.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre    19 Aug 22 08:59  file1
-rw-r--r-- 1 nitish-mahapatre nitish-mahapatre    30 Aug 27 14:04  file10.txt
-rw-r--r-- 1 nitish-mahapatre nitish-mahapatre    90 Aug 27 22:47  file11.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 29 09:59  file12.txt
-rw-rw-r-T 1 nitish-mahapatre nitish-mahapatre    13 Aug 30 15:51  file16a.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre    64 Aug 30 16:01  file16b.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 24 20:06  file_1.txt
-rw------- 1 nitish-mahapatre nitish-mahapatre    19 Aug 22 09:08  file2
-rw-r--r-- 1 nitish-mahapatre nitish-mahapatre    23 Aug 30 23:28  file22.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 24 20:06  file_2.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 24 20:07  file_3.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 24 20:07  file_4.txt
-rw------- 1 nitish-mahapatre nitish-mahapatre    19 Aug 24 16:51  file7
-rw------- 1 nitish-mahapatre nitish-mahapatre    20 Aug 30 21:47  file7.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre    28 Aug 24 17:24  file8.txt
-rw-rw-r-- 3 nitish-mahapatre nitish-mahapatre    19 Aug 27 13:50  hardLink.txt
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre    20 Aug 27 22:54  hello.txt
prw-rw-r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug  9 19:44  myfifo
-rwxr--r-- 1 nitish-mahapatre nitish-mahapatre     0 Aug 30 21:37  myfile3
-rw------- 1 nitish-mahapatre nitish-mahapatre    16 Aug 11 18:20  myfile4.txt
-rw------- 1 nitish-mahapatre nitish-mahapatre   110 Aug 24 20:07  nohup.out
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16048 Aug 11 13:02  prog1c
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16008 Aug  9 20:21  prog2
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16048 Aug 11 17:49  prog3
-rwxrwxr-x 1 nitish-mahapatre nitish-mahapatre 16048 Aug 11 18:21  prog4
drwxrwxr-x 2 nitish-mahapatre nitish-mahapatre  4096 Aug 27 23:58  Q1
lrwxrwxrwx 1 nitish-mahapatre nitish-mahapatre     9 Aug 27 22:54  Symlink.txt -> hello.txt
-rw-rw-r-- 3 nitish-mahapatre nitish-mahapatre    19 Aug 27 13:50  target.txt
-rw-r--r-- 1 nitish-mahapatre nitish-mahapatre     4 Aug 31 11:57  ticket.txt

./Q1:
total 12
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre 654 Aug 30 22:04 1a.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre 630 Aug 30 22:04 1b.c
-rw-rw-r-- 1 nitish-mahapatre nitish-mahapatre 716 Aug 30 22:05 1c.c*/