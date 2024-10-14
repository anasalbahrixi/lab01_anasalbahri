CXX = g++

lab01: car.o doors.o main.o perf.o
	$(CXX) $^ -o $@

doors.o: doors.hpp
	$(CXX) -c $<

main.o: main.cpp 
	$(CXX) -c $<

perf.o: perf.cpp perf.hpp
	$(CXX) -c $<

car.o: car.cpp car.hpp
	$(CXX) -c $<