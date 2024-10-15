# Variables
CXX = g++
CXXFLAGS = -lglfw -lGL -lm -pthread
TARGET = main
SRCS = main.cpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS)

# Clean rule to remove the executable
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
