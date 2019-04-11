CC=gcc
CXX=g++ -Wall -Wextra -std=c++11
RM=rm -f


SRCS=Connection.cpp  hashFunction.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o a.out $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend