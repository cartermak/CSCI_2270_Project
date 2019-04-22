CC=gcc
CXX=g++ -shared -fPIC -I/usr/lib/jvm/java-11-oracle/include -I/usr/lib/jvm/java-11-oracle/include/linux
RM=rm -f


SRCS=Connection.cpp swig.cpp strmod.cpp SaveMethod.cpp wordSearch.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: a.out

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) -o Java_experimenting/mypackage/classes/share.so $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend