CC=g++
CCLIB=ar
CC_INCLUDE=-I/usr/include
DEFS = -DSERVER_ENGINE
	 
MY_INCLUDE=-I$(PWD) \
		-I../../Common \
		-I../../Common/protobuf/src
					 
CC_LIB=-L/usr/lib \
	-L/lib \
	-lpthread
			 
MY_LIB=

TARGET=libServerEngine.a

OBJPATH=./Linux/

SRCS= $(wildcard ./*.cpp)

#//SRCS=$(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))

OBJS=$(SRCS:.cpp=.o)

#OBJS:=$(notdir $(OBJS))

#OBJS:=$(addprefix $(OBJPATH),$(OBJS))

#$(TARGET):$(OBJS)
#	$(CC) -g -o $(TARGET) $(OBJS) $(CC_LIB) $(MY_LIB)

$(TARGET):$(OBJS)
	$(CCLIB) -rs -o $(TARGET) $(OBJS)
	mv $(OBJS) ../Linux

$(OBJS):%.o:%.cpp
	$(CC) -g -w -c $< -o $@ $(CC_INCLUDE) $(MY_INCLUDE)
	
clean:
	rm $(OBJS) $(TARGET)