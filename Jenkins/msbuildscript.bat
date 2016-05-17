:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Environment setup
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
set VS_VERSION=14
call "%VS140COMNTOOLS%\..\..\VC\vcvarsall.bat" amd64
:: %1 is the full path to the msbuild executable
:: %2 is the configuration Release/Debug etc
:: %3 is the full path to the solution

%1 %2 %3
