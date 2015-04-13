CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		header/*.h cpp/*.cpp

LIBS =		-I header/ -I cpp/ -lboost_system -lboost_thread

TARGET =	bin/obd-connector

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	clean $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
