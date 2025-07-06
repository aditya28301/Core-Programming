# NetGuard - Advanced Network Monitor Makefile
# Demonstrates professional build system setup

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -march=native -flto
LDFLAGS = -pthread -static-libgcc -static-libstdc++
TARGET = netGuard
SRCDIR = src
OBJDIR = obj
SOURCES = netGuard.cpp
OBJECTS = $(OBJDIR)/$(SOURCES:.cpp=.o)

# Build configurations
DEBUG_FLAGS = -g -DDEBUG -O0 -fsanitize=address -fsanitize=thread
RELEASE_FLAGS = -DNDEBUG -O3 -march=native -flto

# Default target
all: release

# Release build
release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

# Debug build
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: LDFLAGS += -fsanitize=address -fsanitize=thread
debug: $(TARGET)

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build target
$(TARGET): $(OBJDIR) $(OBJECTS)
	@echo "🔗 Linking $(TARGET)..."
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "✅ Build complete: $(TARGET)"
	@echo "📋 Run with: sudo ./$(TARGET)"

# Compile source files
$(OBJDIR)/%.o: %.cpp
	@echo "🔨 Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Install system-wide (optional)
install: $(TARGET)
	@echo "📦 Installing $(TARGET) to /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/
	sudo chmod +x /usr/local/bin/$(TARGET)
	@echo "✅ Installation complete"

# Performance optimized build
performance: CXXFLAGS += -O3 -march=native -mtune=native -flto -ffast-math -funroll-loops
performance: $(TARGET)
	@echo "🚀 Performance-optimized build complete"

# Static analysis
analyze:
	@echo "🔍 Running static analysis..."
	cppcheck --enable=all --std=c++17 *.cpp
	@echo "✅ Static analysis complete"

# Memory leak check (requires valgrind)
memcheck: debug
	@echo "🧪 Running memory leak detection..."
	sudo valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Performance profiling (requires perf)
profile: release
	@echo "⚡ Running performance profile..."
	sudo perf record -g ./$(TARGET)
	perf report

# Clean build artifacts
clean:
	@echo "🧹 Cleaning build artifacts..."
	rm -rf $(OBJDIR) $(TARGET)
	@echo "✅ Clean complete"

# Show system info
sysinfo:
	@echo "💻 System Information:"
	@echo "   OS: $$(uname -s -r)"
	@echo "   Arch: $$(uname -m)"
	@echo "   CPU: $$(nproc) cores"
	@echo "   Compiler: $$($(CXX) --version | head -n1)"
	@echo "   Build Flags: $(CXXFLAGS)"

# Help target
help:
	@echo "🔧 NetGuard Build System"
	@echo ""
	@echo "Targets:"
	@echo "  all         - Build release version (default)"
	@echo "  release     - Build optimized release version"
	@echo "  debug       - Build debug version with sanitizers"
	@echo "  performance - Build with maximum optimizations"
	@echo "  install     - Install to system (/usr/local/bin)"
	@echo "  analyze     - Run static code analysis"
	@echo "  memcheck    - Run memory leak detection"
	@echo "  profile     - Run performance profiling"
	@echo "  clean       - Remove build artifacts"
	@echo "  sysinfo     - Show system information"
	@echo "  help        - Show this help message"
	@echo ""
	@echo "Usage Examples:"
	@echo "  make                    # Build release version"
	@echo "  make debug              # Build debug version"
	@echo "  make performance        # Maximum optimization"
	@echo "  sudo make install       # Install system-wide"

.PHONY: all release debug performance install analyze memcheck profile clean sysinfo help
