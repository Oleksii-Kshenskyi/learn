CC=g++
SRC_DIR=src
MAIN_SCU=csdb.cxx
CXXFLAGS=-std=c++20 -DNDEBUG -O3
WARN=-pedantic -Wextra -Werror -Wall
CC_INCLUDE=/mingw64/include
INCLUDES=-I./${SRC_DIR} -I${CC_INCLUDE}
LINK_PATHS=-L/mingw64/bin
LINKING=-lsqlite3 -lsoci_core_4_0 -lsoci_sqlite3_4_0
PRJ_NAME=csdb
PRJ_EXE=${PRJ_NAME}.exe
SET_NAME=-o ${PRJ_NAME}


all: ./${SRC_DIR}/${MAIN_SCU}
	${CC} ${CXXFLAGS} ${WARN} ${INCLUDES} ${LINK_PATHS} ${LINKING} ${SET_NAME} ./${SRC_DIR}/${MAIN_SCU}

clean: ./${PRJ_EXE}
	rm -rf ${PRJ_EXE}
