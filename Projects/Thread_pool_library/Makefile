CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -pthread
INCLUDES = -Iinclude

BUILD_DIR = build
BIN_DIR = bin

# Object files
THREAD_POOL_OBJ = $(BUILD_DIR)/thread_pool.o
EXAMPLE_OBJ = $(BUILD_DIR)/example.o
TEST_OBJ = $(BUILD_DIR)/test.o
REAL_WORLD_OBJ = $(BUILD_DIR)/real_world_test.o

# Executables
EXAMPLE_BIN = $(BIN_DIR)/example
TEST_BIN = $(BIN_DIR)/test
REAL_WORLD_BIN = $(BIN_DIR)/real_world_test

all: $(EXAMPLE_BIN) $(TEST_BIN) $(REAL_WORLD_BIN)
	@echo "✅ Build complete!"
	@echo ""
	@echo "Available commands:"
	@echo "  make run         - Run basic demo"
	@echo "  make test        - Run test suite"
	@echo "  make real-world  - Run real-world application tests"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(THREAD_POOL_OBJ): src/thread_pool.cpp include/thread_pool.hpp | $(BUILD_DIR)
	@echo "🔨 Compiling thread_pool.cpp..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(EXAMPLE_OBJ): src/example.cpp include/thread_pool.hpp | $(BUILD_DIR)
	@echo "🔨 Compiling example.cpp..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ): src/test.cpp include/thread_pool.hpp | $(BUILD_DIR)
	@echo "🔨 Compiling test.cpp..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(REAL_WORLD_OBJ): src/real_world_test.cpp include/thread_pool.hpp | $(BUILD_DIR)
	@echo "🔨 Compiling real_world_test.cpp..."
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(EXAMPLE_BIN): $(THREAD_POOL_OBJ) $(EXAMPLE_OBJ) | $(BIN_DIR)
	@echo "🔗 Linking example..."
	@$(CXX) $^ -o $@ $(CXXFLAGS)

$(TEST_BIN): $(THREAD_POOL_OBJ) $(TEST_OBJ) | $(BIN_DIR)
	@echo "🔗 Linking test..."
	@$(CXX) $^ -o $@ $(CXXFLAGS)

$(REAL_WORLD_BIN): $(THREAD_POOL_OBJ) $(REAL_WORLD_OBJ) | $(BIN_DIR)
	@echo "🔗 Linking real_world_test..."
	@$(CXX) $^ -o $@ $(CXXFLAGS)

run: $(EXAMPLE_BIN)
	@echo "🚀 Running basic demo..."
	@echo ""
	@./$(EXAMPLE_BIN)

test: $(TEST_BIN)
	@echo "🧪 Running test suite..."
	@echo ""
	@./$(TEST_BIN)

real-world: $(REAL_WORLD_BIN)
	@echo "🔬 Running real-world tests..."
	@echo ""
	@./$(REAL_WORLD_BIN)

clean:
	@echo "🧹 Cleaning..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR) *.txt

.PHONY: all run test real-world clean
