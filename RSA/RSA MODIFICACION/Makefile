# Variables.
BIN = bin
SOURCE = src
INC = include

#Nombre del fichero ejecutable.
TARGET = $(BIN)/rsa

# Flags para el compilador.
CXXFLAGS = -std=c++11 -I$(INC)

# Definición del compilador.
CXX = g++ -Ofast

# Definición de ficheros fuente.
SRC = $(SOURCE)/main.cpp $(SOURCE)/rsa.cpp

# Orden que se ejecutará por defecto.
all: clean $(TARGET)

# Regla de ejecución.
$(TARGET):
	@echo "Generando ejecutable."
	@$(CXX) -o $@ $(CXXFLAGS) $(SRC)

# Regla para limpiar el archivo.
clean:
	@echo "Eliminando ejecuatble."
	@rm  -f $(TARGET)

run:
	@make && ./$(TARGET)