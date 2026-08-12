


CXX = g++
CXXFLAGS = -Wextra -Wall -Werror -g -MMD

main: appoinment.o patient.o pricingEngine.o storage.o main.o optionOne.o optionTwo.o optionThree.o optionFour.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include *.d

.PHONY: clean

clean:
	rm -f *.o main
