CC=gcc
CXX=g++
RM=rm -f


SRCS=mainMenu.cpp Connection.cpp strmod.cpp SaveMethod.cpp wordSearch.cpp
OBJS=$(subst .cc,.o,$(SRCS))

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