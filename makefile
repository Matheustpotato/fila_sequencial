# Nome do compilador
CXX = g++
# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -Wextra
# Nome do executável
TARGET = fila
# Arquivo-fonte
SRC = filseque.cpp

# Regra padrão: compila tudo
all: $(TARGET)

# Como gerar o executável a partir do .cpp
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Limpa arquivos gerados
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
