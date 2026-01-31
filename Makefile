# Configurações do compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INCLUDE_DIR)
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Arquivos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d)
TARGET = $(BIN_DIR)/biblioteca

# Configuração padrão
MODE ?= release
ifeq ($(MODE), debug)
    CXXFLAGS += $(DEBUG_FLAGS)
else
    CXXFLAGS += $(RELEASE_FLAGS)
endif

# Regra principal
all: $(TARGET)

# Compilar executável
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "Linkando $(TARGET)..."
	$(CXX) $(OBJECTS) -o $@
	@echo "Compilação concluída!"

# Compilar arquivos objeto com dependências automáticas
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Criar diretórios
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Modos de compilação
debug:
	$(MAKE) MODE=debug

release:
	$(MAKE) MODE=release

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Executar programa
run: $(TARGET)
	./$(TARGET)

# Recompilar tudo
rebuild: clean all

# Ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make          - Compila (release)"
	@echo "  make debug    - Compila (debug)"
	@echo "  make clean    - Remove arquivos gerados"
	@echo "  make run      - Compila e executa"
	@echo "  make rebuild  - Limpa e recompila"

# Incluir dependências automáticas
-include $(DEPS)

.PHONY: all debug release clean run rebuild help
