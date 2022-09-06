CC=clang++
SRC_DIR=src
MAIN_SCU=csdb.cxx
CXXFLAGS=-std=c++20 -DNDEBUG -O3
WARN=-fcolor-diagnostics -pedantic -Wextra -Werror -Wall
CC_INCLUDE=/clang64/include
INCLUDES=-I./${SRC_DIR} -I${CC_INCLUDE}
PRJ_NAME=csdb
PRJ_EXE=${PRJ_NAME}.exe
SET_NAME=-o ${PRJ_NAME}


all: ./${SRC_DIR}/${MAIN_SCU}
	${CC} ${CXXFLAGS} ${WARN} ${INCLUDES} ${SET_NAME} ./${SRC_DIR}/${MAIN_SCU}

clean: ./${PRJ_EXE}
	rm -rf ${PRJ_EXE}
