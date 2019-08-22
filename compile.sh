g++\
	-Wall -Wextra -Werror -std=c++11\
	-I ./includes\
	-I ./srcs/__tests__\
	-L . -lrt\
	srcs/__tests__/*.cpp
