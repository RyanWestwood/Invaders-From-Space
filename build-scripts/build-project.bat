cd ../
set working_dir=%cd%
set library_binaries=%working_dir%/library_binaries
set cmake="cmake"
set generator="-G Visual Studio 17 2022"
set test="-DTESTS=OFF"

CALL :InstallProject Release %library_binaries%
CALL :InstallProject Debug %library_binaries%/Debug

pause 
EXIT /B %ERRORLEVEL%

:InstallProject
if not exist "build" mkdir build
cd build
%cmake% %generator% -A x64 -DCMAKE_BUILD_TYPE=%~1 -S ./../ -DCMAKE_PREFIX_PATH=%~2 %test%
%cmake% --build . --config %~1 --parallel
%cmake% --install %working_dir%/build --prefix %~2 --config %~1
cd ../
echo Project built successfully
EXIT /B 0