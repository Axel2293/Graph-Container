@ECHO OFF

ECHO ----COMPILING main program DGRAPH test

cd "c:\Users\axelw\OneDrive - ITESO\Desktop\Graph\Graph-Container"

gcc testDGraph.c DGraph.c List\list.c -o testDGraph.exe

ECHO ----TASK COMPLETED

ECHO ----RUNNING testDGraph.exe

.\testDGraph.exe

