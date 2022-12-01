@ECHO OFF

ECHO ----COMPILING main program DGRAPH

cd "c:\Users\axelw\OneDrive - ITESO\Desktop\Graph\Graph-Container"

gcc main.c Graph.c List\list.c -o test.exe

ECHO ----TASK COMPLETED

ECHO ----RUNNING DGraph.exe

.\test.exe

PAUSE