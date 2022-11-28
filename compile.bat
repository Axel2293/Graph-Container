@ECHO OFF

ECHO ----COMPILING main program DGRAPH

cd "c:\Users\axelw\OneDrive - ITESO\Desktop\Graph\Graph-Container"

gcc main.c Graph.c Set\set.c -o DGraph.exe

ECHO ----TASK COMPLETED

ECHO ----RUNNING DGraph.exe

.\DGraph.exe

PAUSE