FEE_PATH=/data/billing8/user/gucb/test2/
SRC_PATH=${FEE_PATH}/src
INC_PATH=${FEE_PATH}/include
BIN_PATH=${FEE_PATH}/bin
OBJ_PATH=${FEE_PATH}/obj


#预编译环境
ORAINC    = ${ORACLE_HOME}/rdbms/public
ORALIBS   = -L ${ORACLE_HOME}/lib  -locci  -lclntsh

#编译器环境
CC        = xlC
CFLAGS    = -brtl -q64 -O -lc -bnoquiet
CCINC     = -I$(ORAINC) -I$(INC_PATH)
CCLIB     = $(ORALIBS)
LINK.CC   = $(CC) $(CFLAGS) $(CCINC) $(CCLIB)
COMP.CC   = $(CC) $(CFLAGS) $(CCINC)

TARGET = ${BIN_PATH}/test
all: $(TARGET)

clean:
        -@rm -f ${OBJ_PATH}/* ${BIN_PATH}/test ${BIN_PATH}/core

${BIN_PATH}/test : ${OBJ_PATH}/test.o $(OBJ_PATH)/Config.o ${OBJ_PATH}/MyApplication.o
        $(LINK.CC) -o ${BIN_PATH}/test $(OBJ_PATH)/Config.o ${OBJ_PATH}/MyApplication.o

#${OBJ_PATH}/DBOper.o : $(SRC_PATH)/DBOper.cpp
#        $(COMP.CC) -o $@ -c $(SRC_PATH)/DBOper.cpp -I $(INC_PATH) 

${OBJ_PATH}/Config.o : $(SRC_PATH)/Config.cpp
        $(COMP.CC) -o $@ -c $(SRC_PATH)/Config.cpp -I $(INC_PATH)

${OBJ_PATH}/MyApplication.o : $(SRC_PATH)/MyApplication.cpp
        $(COMP.CC) -o $@ -c $(SRC_PATH)/MyApplication.cpp -I $(INC_PATH)

#${OBJ_PATH}/Student.o : $(SRC_PATH)/Student.cpp
       # $(COMP.CC) -o $@ -c $(SRC_PATH)/Student.cpp -I $(INC_PATH)
#${OBJ_PATH}/FileOper.o : $(SRC_PATH)/FileOper.cpp
        #$(COMP.CC) -o $@ -c $(SRC_PATH)/FileOper.cpp -I $(INC_PATH)

#${OBJ_PATH}/test.o : $(SRC_PATH)/test.cpp
        #$(COMP.CC) -o $@ -c $(SRC_PATH)/test.cpp 

