
NOM_TEST ?= puce
STATUT ?= release


EXEC_NAME = $(NOM_TEST)

SRC_CHEMIN = src/

INCLUDE = include/


all: clean $(EXEC_NAME)

LIB_SRCS := main.cpp
LIB_SRCS += $(SRC_CHEMIN)map.cpp
LIB_SRCS += $(SRC_CHEMIN)case.cpp
LIB_SRCS += $(SRC_CHEMIN)chien.cpp
LIB_SRCS += $(SRC_CHEMIN)puce.cpp
LIB_SRCS += $(SRC_CHEMIN)display.cpp

LIB_OBJS  = $(LIB_SRCS:.cpp=.o)


CXX = g++ -Wall

THREAD = -lpthread
MATH = -lm

GTK_CFLAGS = `pkg-config gtkmm-3.0 --cflags`
GTK_LIBS = `pkg-config gtkmm-3.0 --libs`

ifeq ($(STATUT), release)
	STATUT_FLAG =
else
	STATUT_FLAG = -g
endif

LIB_CFLAGS = -std=c++11


$(EXEC_NAME): $(LIB_OBJS)
	$(CXX) $(STATUT_FLAG) -o $(EXEC_NAME) $(LIB_OBJS) $(THREAD) $(MATH) $(GTK_LIBS)

.cpp.o:
	$(CXX) $(STATUT_FLAG) -c -I$(INCLUDE) $(LIB_CFLAGS) $(GTK_CFLAGS) -o $@ $<
	
clean:
	rm -f $(LIB_OBJS) $(EXEC_NAME) *~
