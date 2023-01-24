CXX = g++
CXXFLAGS = -ljpeg -lpng
SOURCES = main.cpp src/ASCIIPic.cpp src/ImageBuilder.cpp src/JPEGBuilder.cpp src/PNGBuilder.cpp src/BMPBuilder.cpp src/TemplatePrint.cpp src/TemplatePrintImpl.cpp src/TemplatePrintDynImpl.cpp src/StrategyLight.cpp src/StrategyDark.cpp
EXECUTABLE = ASCIIPic
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm $(OBJECTS)

remove:
	rm $(OBJECTS) $(EXECUTABLE)