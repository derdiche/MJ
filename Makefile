# Variables
CXX = g++
CXXFLAGS = -lglfw -lGL -lm -pthread -lGLU -lGLEW -pthread -O3 -march=native -funroll-loops -flto
TARGET = main
SRCS = main.cpp

# Règle par défaut
all: $(TARGET)
		./$(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS)

# Clean rule to remove the executable
clean:
	rm -f *.o $(TARGET)

# Phony targets
.PHONY: all clean
