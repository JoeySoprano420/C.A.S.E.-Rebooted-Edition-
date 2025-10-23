@echo off
REM C.A.S.E. Transpiler Test Suite

echo ================================
echo C.A.S.E. Transpiler Test Suite
echo ================================
echo.

REM Check if transpiler exists
if not exist "bin\case-transpiler.exe" (
    echo Error: Transpiler not found. Run build.bat first.
    exit /b 1
)

set PASS=0
set FAIL=0

REM Test 1: Hello World
echo Test 1: Hello World
bin\case-transpiler.exe examples\hello.case test_hello.cpp >nul 2>&1
if exist test_hello.cpp (
    g++ test_hello.cpp -o test_hello.exe >nul 2>&1
    if exist test_hello.exe (
   echo   [32m? PASS[0m
        set /a PASS+=1
 del test_hello.exe test_hello.cpp >nul 2>&1
    ) else (
        echo   [31m? FAIL (C++ compilation failed)[0m
 set /a FAIL+=1
    )
) else (
    echo   [31m? FAIL (transpilation failed)[0m
    set /a FAIL+=1
)

REM Test 2: Calculator
echo Test 2: Calculator
bin\case-transpiler.exe examples\calculator.case test_calc.cpp >nul 2>&1
if exist test_calc.cpp (
    echo   [32m? PASS (transpilation)[0m
    set /a PASS+=1
    del test_calc.cpp >nul 2>&1
) else (
    echo   [31m? FAIL[0m
    set /a FAIL+=1
)

REM Test 3: Factorial
echo Test 3: Factorial
bin\case-transpiler.exe examples\factorial.case test_fact.cpp >nul 2>&1
if exist test_fact.cpp (
    echo   [32m? PASS (transpilation)[0m
    set /a PASS+=1
    del test_fact.cpp >nul 2>&1
) else (
    echo   [31m? FAIL[0m
    set /a FAIL+=1
)

REM Summary
echo.
echo ================================
echo Results: %PASS% passed, %FAIL% failed
echo ================================

if %FAIL% EQU 0 (
    echo [32mAll tests passed! ?[0m
    exit /b 0
) else (
    echo [31mSome tests failed.[0m
    exit /b 1
)
