@echo off
title Sorting Analysis
echo Start Compiling

g++ *.cpp -o analysis
echo Compiling done.
Start "" "analysis.exe"

echo Analysing done. Start shutting down in 60s.
pause
shutdown -s -t 60
