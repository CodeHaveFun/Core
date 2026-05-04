:: File build program - @CodeHaveFun
:: Using C++ compiler
@echo off
title Core Project - Corex Builder
cls
echo.

:: DLL File Runtime for ICU (UNICODE)
set icudt79=Corex\bin\icudt79.dll
set icuin79=Corex\bin\icuin79.dll
set icuio79=Corex\bin\icuio79.dll
set icutu79=Corex\bin\icutu79.dll
set icuuc79=Corex\bin\icuuc79.dll
:: Copy DLL File Runtime ^^
set dicudt79=Corex\Frontend\Uni\DLLFile\icudt79.dll
set dicuin79=Corex\Frontend\Uni\DLLFile\icuin79.dll
set dicuio79=Corex\Frontend\Uni\DLLFile\icuio79.dll
set dicutu79=Corex\Frontend\Uni\DLLFile\icutu79.dll
set dicuuc79=Corex\Frontend\Uni\DLLFile\icuuc79.dll

:: Link DLL for ICU (UNICODE)
set libicudt=Corex\Frontend\Uni\DLLFile\libicudt.dll.a
set libicuin=Corex\Frontend\Uni\DLLFile\libicuin.dll.a
set libicuio=Corex\Frontend\Uni\DLLFile\libicuio.dll.a
set libicutu=Corex\Frontend\Uni\DLLFile\libicutu.dll.a
set libicuuc=Corex\Frontend\Uni\DLLFile\libicuuc.dll.a

echo ---------- Corex Builder ----------


echo Checking g++ ...
where g++ >nul 2> nul
if %errorlevel% equ 0 (
    echo.
    echo *OK* - g++ installed!
    echo.
    echo ---- g++ version ----
    echo.
    g++ --version
) else (
    echo.
    echo *NOT FOUND* - g++ did not install!
    echo ** Install g++ to continue **
)
echo.
:: Check old file
if exist "Corex\BuildObj\*.o" (
    echo Deleting old file ^(Object file^)
    del /Q "Corex\BuildObj\*.o"
    echo *OK* Deleted object file ^(BuildObj^)
)
:: Check old file
if exist "Corex\bin\core.exe" (
    echo Deleting old file ^(core.exe^)
    del /Q "Corex\bin\core.exe"
    echo *OK* Deleted core.exe
)

if exist %icudt79% (
    echo Deleting old DLL file ^(bin\icudt79.dll^)
    del /Q %icudt79%
    echo *OK* Deleted bin\icudt79.dll
)
if exist %icuin79% (
    echo Deleting old DLL file ^(bin\icuin79.dll^)
    del /Q %icuin79%
    echo *OK* Deleted bin\icuin79.dll
)
if exist %icuio79% (
    echo Deleting old DLL file ^(bin\icuio79.dll^)
    del /Q %icuio79%
    echo *OK* Deleted bin\icuio79.dll
)
if exist %icutu79% (
    echo Deleting old DLL file ^(bin\icutu79.dll^)
    del /Q %icutu79%
    echo *OK* Deleted bin\icutu79.dll
)
if exist %icuuc79% (
    echo Deleting old DLL file ^(bin\icuuc79.dll^)
    del /Q %icuuc79%
    echo *OK* Deleted bin\icuuc79.dll
)
:: Prepare file and build
echo.
echo Prepare file...
 
:: Build InputGetFile.cpp
echo ^[1/2^] ..\Corex\Frontend\InputGetFile.cpp : Building file...
g++ -c Corex\Frontend\InputGetFile.cpp -o Corex\BuildObj\IGF.o
if %errorlevel% equ 0 (
    echo *OK* - Built: InputGetFile.cpp --^> IGF.o
) else (
    echo ^[1/2^]  *FAIL* - Compilation Failed!
    pause
    exit /b 1
)
:: Build LexerTokenCore.cpp
echo [2/2] ..\Corex\Frontend\LexerTokenCore.cpp : Building file...
g++ -c Corex\Frontend\LexerTokenCore.cpp -o Corex\BuildObj\LTC.o
if %errorlevel% equ 0 (
    echo *OK* - Built: LexerTokenCore.cpp --^> LTC.o
) else (
    echo ^[2/2^]  *FAIL* - Compilation Failed!
    pause
    exit /b 1
)
echo.
echo Copying icudt79.dll (^DLL runtime file - ICU^) to \bin...
copy %dicudt79% Corex\bin
echo Copying icuin79.dll (^DLL runtime file - ICU^) to \bin...
copy %dicuin79% Corex\bin
echo Copying icuio79.dll (^DLL runtime file - ICU^) to \bin...
copy %dicuio79% Corex\bin
echo Copying icutu79.dll (^DLL runtime file - ICU^) to \bin...
copy %dicutu79% Corex\bin
echo Copying icuuc79.dll (^DLL runtime file - ICU^) to \bin...
copy %dicuuc79% Corex\bin
echo.
:: Check file linking DLL File (*.dll.a)
echo Checking file linking dll file - International Components for Unicode (ICU)...
if exist %libicudt% (
    echo *OK* - Frontend\Uni\DLLFile\libicudt.dll.a
) else (
    echo *NOT FOUND* - Missing libicudt.dll.a file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %libicuin% (
    echo *OK* - Frontend\Uni\DLLFile\libicuin.dll.a
) else (
    echo *NOT FOUND* - Missing libicuin.dll.a file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %libicuio% (
    echo *OK* - Frontend\Uni\DLLFile\libicuio.dll.a
) else (
    echo *NOT FOUND* - Missing libicuio.dll.a file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %libicutu% (
    echo *OK* - Frontend\Uni\DLLFile\libicutu.dll.a
) else (
    echo *NOT FOUND* - Missing libicutu.dll.a file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %libicuuc% (
    echo *OK* - Frontend\Uni\DLLFile\libicuuc.dll.a
) else (
    echo *NOT FOUND* - Missing libicuuc.dll.a file ^| The file needs to be updated!
    pause
    exit /b 1
)

echo.
echo Checking again DLL unicode file runtime - International Components for Unicode (ICU)...
if exist %icudt79% (
    echo *OK* - bin\icudt79.dll
) else (
    echo *NOT FOUND* - Missing icudt79.dll file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %icuin79% (
    echo *OK* - bin\icuin79.dll
) else (
    echo *NOT FOUND* - Missing icuin79.dll file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %icuio79% (
    echo *OK* - bin\icuio79.dll
) else (
    echo *NOT FOUND* - Missing icuio79.dll file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %icutu79% (
    echo *OK* - bin\icutu79.dll
) else (
    echo *NOT FOUND* - Missing icutu79.dll file ^| The file needs to be updated!
    pause
    exit /b 1
)
if exist %icuuc79% (
    echo *OK* - bin\icuuc79.dll
) else (
    echo *NOT FOUND* - Missing icuuc79.dll file ^| The file needs to be updated!
    pause
    exit /b 1
)

:: Final: Build main program
echo.
echo ^[FINAL^] ..\Corex\Core.cpp ..\Core\Frontend\Uni\DLLFile\*.dll.a : Building main file appliance (.exe)...
:: IMPORTANT CMD
g++ -I.\Corex\Frontend/Uni ^
    Corex\BuildObj\*.o ^
    Corex\Core.cpp ^
    .\%libicudt% ^
    .\%libicuin% ^
    .\%libicuio% ^
    .\%libicutu% ^
    .\%libicuuc% ^
    -o Corex\bin\core.exe
if %errorlevel% equ 0 (
    echo *OK* - Built object file ^(*.o^) ^| core.cpp ^| linking file ^(*.dll.a^) --^> core.exe 
) else (
    echo *FAIL* - Compilation Failed!
    pause
    exit /b 1
)
pause