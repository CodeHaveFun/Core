@echo off
cls
title Core Project - Build Corex Compiler
echo.


echo ---------- Corex Compiler Building ----------


echo Checking g++ ...
where g++ >nul 2> nul
if %errorlevel% equ 0 (
    echo.
    echo *OK* g++ installed!
    echo.
    echo ---- g++ version ----
    echo.
    g++ --version
) else (
    echo.
    echo *NOT FOUND* g++ did not install!
    echo ** Install g++ to continue **
)
echo.

if exist "Corex\BuildObj\*.o" (
    echo Deleting old file ^(Object file^)
    del /Q "Corex\BuildObj\*.o"
    echo *OK* Deleted object file ^(BuildObj^)
)

if exist "Corex\core.exe" (
    echo Deleting old file ^(core.exe^)
    del /Q "Corex\core.exe"
    echo *OK* Deleted core.exe
)

echo.
echo Prepare file...

:: Build InputGetFile.cpp
echo [1/2] ../Corex/Frontend/InputGetFile.cpp : Building file...
g++ -c Corex/Frontend/InputGetFile.cpp -o Corex/BuildObj/IGF.o
if %errorlevel% equ 0 (
    echo *OK*  InputGetFile.cpp --^> IGF.o
) else (
    echo [1/2]  *FAIL* - Compilation Failed!
    pause
    exit /b 1
)
:: Build LexerTokenCore.cpp
echo [2/2] ../Corex/Frontend/LexerTokenCore.cpp : Building file...
g++ -c Corex/Frontend/LexerTokenCore.cpp -o Corex/BuildObj/LTC.o
if %errorlevel% equ 0 (
    echo *OK*  LexerTokenCore.cpp --^> LTC.o
) else (
    echo [2/2]  *FAIL* - Compilation Failed!
    pause
    exit /b 1
)


echo.
echo [FINAL] ../Corex/Core.cpp : Building maintain file appliance (.exe)
g++ Corex/BuildObj/*.o Corex/Core.cpp -o Corex/core.exe
if %errorlevel% equ 0 (
    echo *OK*  *.o core.exe --^> core.exe
) else (
    echo *FAIL* - Compilation Failed!
    pause
    exit /b 1
)
pause