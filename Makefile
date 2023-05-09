#-- Directory names
OBJ_DIR = object-file
SRC_DIR = src
BIN_DIR = Exported

#-- Path for  files
PACKAGE_ROOT = .
OBJ_PATH = $(PACKAGE_ROOT)/$(OBJ_DIR)
SRC_PATH = $(PACKAGE_ROOT)/$(SRC_DIR)
BIN_PATH = $(PACKAGE_ROOT)/$(BIN_DIR)

APPLICATION_NAME = toRun
#-- Files list automation
VPATH = $(SRC_PATH)
DEPS = $(wildcard $(SRC_PATH)/*.h)	#wildcard -> carica variabile con lista di file
SOURCES = $(wildcard $(SRC_PATH)/*.cpp)	#wildcard -> carica variabile con lista di file
OBJECTS_TO_LINK = $(patsubst $(SRC_PATH)/%.cpp, $(OBJ_PATH)/%.o, $(SOURCES))

#----------------------------------------------------------------- 
all: $(SOURCES) $(OBJECTS_TO_LINK) makefile $(BIN_PATH)/$(APPLICATION_NAME)

$(BIN_PATH)/$(APPLICATION_NAME) : $(OBJECTS_TO_LINK)
	$(CXX) -o $@ $(OBJECTS_TO_LINK)
	
$(OBJ_PATH)/%.o : %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@

run:
	$(BIN_PATH)/$(APPLICATION_NAME) results.txt

clean:
	@echo "Cleaning..."
	-rm -f $(OBJ_PATH)/*.o $(BIN_PATH)/$(APPLICATION_NAME)
	rm $(BIN_PATH)/*.png
	rm results.txt
	@echo "Done."

backup: 
	-rm -f $(OBJ_PATH)/*.o $(BIN_PATH)/$(APPLICATION_NAME)
	tar czvf ./$(APPLICATION_NAME)$(shell date --iso=seconds).tar.gz ./

setup:
	mkdir $(OBJ_DIR) $(SRC_DIR) $(BIN_DIR)
	touch README.md