@ECHO OFF

ECHO ----COMPILING Test for SET container

cd "c:\Users\axelw\OneDrive - ITESO\Desktop\Graph\Graph-Container\Set"

gcc main.c set.c -o Test.exe

ECHO ----TASK COMPLETED

ECHO ----RUNNING Test.exe

.\Test.exe
