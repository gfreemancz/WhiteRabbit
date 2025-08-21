@set PATH=C:/UserData/conan/6ec2e8/1/bin;%PATH%


cmake --preset default
cd build
cmake --build . -v  %*
cmake --install .   
cd..