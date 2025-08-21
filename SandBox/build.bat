REM cmake -G "MinGW Makefiles" -B ./output
cmake --preset default
cd build
cmake --build . -v  %*
cmake --install .   
cd..