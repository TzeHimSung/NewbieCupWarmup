echo "Compiling..." && \
g++-14 -O2 ./main.cpp -o ./main.out -std=c++17 -Wall -Werror -Wextra && \
echo "Compiled!" && \
echo "------------" && \
./main.out
