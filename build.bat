@echo off
REM C.A.S.E. Programming Language - Build Script (Windows)
REM Builds the transpiler from source

echo Building C.A.S.E. Transpiler...

REM Check for Visual Studio
where cl >nul 2>nul
if %ERRORLEVEL% EQU 0 (
 set COMPILER=cl
    goto :compile
)

REM Check for g++
where g++ >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    set COMPILER=g++
    goto :compile
)

echo Error: No C++ compiler found.
echo Please install Visual Studio or MinGW.
exit /b 1

:compile
if not exist bin mkdir bin

if "%COMPILER%"=="cl" (
    echo Compiling with MSVC...
    cl /std:c++14 /EHsc src\transpiler\main.cpp /Fe:bin\case-transpiler.exe /I src\transpiler\include /O2
) else (
    echo Compiling with g++...
    g++ -std=c++14 src\transpiler\main.cpp -o bin\case-transpiler.exe -I src\transpiler\include -O2
)

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ================================================
    echo Build successful!
    echo Transpiler created at: bin\case-transpiler.exe
    echo ================================================
    echo.
    echo Usage:
    echo   bin\case-transpiler.exe input.case [output.cpp]
    echo.
    echo Try:
    echo   bin\case-transpiler.exe examples\hello.case
  echo   g++ compiler.cpp -o hello.exe
    echo   hello.exe
) else (
    echo.
    echo Build failed!
    exit /b 1
)
