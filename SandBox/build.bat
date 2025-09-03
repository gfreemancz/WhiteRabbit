@set PATH=C:/UserData/conan/6ec2e8/1/bin;%PATH%
echo off

cmake --preset default
cd output
cmake --build . -v  %*
if errorlevel 1 (
	REM Print big red ASCII art if build fails
	REM Enable ANSI escape codes for color (Windows 10+)
	echo [31m====================
	echo   BUILD FAILED
	echo ====================[0m
	exit /b 1
)
cmake --install .   
cd..