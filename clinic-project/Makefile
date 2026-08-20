


CXX = g++
CXXFLAGS = -Wextra -Wall -Werror -g -MMD

main: appoinment.o patient.o storage.o main.o optionAddation.o optionEdition.o optionSchedule.o optionSearch.o optionFinancial.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include *.d

.PHONY: clean

clean:
	rm -f *.o main *.d
