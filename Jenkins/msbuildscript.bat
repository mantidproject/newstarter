setlocal enableextensions enabledelayedexpansion
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Setup environment and call msbuild
:: %1 Specifies build configuration
:: all other arguments are passed to msbuild
:: All arguments are passed on to msbuild
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:: Use 64-bit version of the compiler
call "%VS140COMNTOOLS%\..\..\VC\vcvarsall.bat" amd64

:: Call msbuild
msbuild /nologo /p:Configuration=%1 %2 %3 %4 %5 %6 %7 %8 %9
