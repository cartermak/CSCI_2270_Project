CC=gcc
CXX=g++ -shared -fPIC -I/usr/lib/jvm/java-11-oracle/include -I/usr/lib/jvm/java-11-oracle/include/linux
RM=rm -f

SRC=src
BIN=bin
OBJ=$(BIN)/obj

SOURCE_FILES=Connection.cpp swig.cpp strmod.cpp SaveMethod.cpp wordSearch.cpp
OBJECT_FILES=$(subst .cpp,.o,$(SRCS))
#########################################################
# Replacing everything that you told me not to touch... #
#########################################################
EXECUTABLE_FILES = Java_experimenting/mypackage/classes/share.so
OBJECT_FILES     = $(SOURCE_FILES:%.cpp=$(OBJ)/%.o)
# ^^^ A more succinct expression for $(OBJECT_FILES), using
#     http://www.gnu.org/software/make/manual/make.html#Substitution-Refs

build: $(EXECUTABLE_FILES)

clean:
	rm -r -f $(BIN)
	

# http://www.gnu.org/software/make/manual/make.html#Phony-Targets
.PHONY: build clean

$(EXECUTABLE_FILES): $(OBJECT_FILES)
	@$(CXX) $(LDFLAGS) -o $@ $^
    # ^^^ http://www.gnu.org/software/make/manual/make.html#Automatic-Variables
	@echo "Build successful!"

# http://www.gnu.org/software/make/manual/make.html#Static-Pattern
$(OBJECT_FILES): $(OBJ)/%.o: %.cpp
	@echo Compiling $<
    # ^^^ Your terminology is weird: you "compile a .cpp file" to create a .o file.
	@mkdir -p $(@D)
    # ^^^ http://www.gnu.org/software/make/manual/make.html#index-_0024_0028_0040D_0029
	@$(CXX) $(CFLAGS) -o $@ $<
	