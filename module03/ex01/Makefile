CFLAGS := -g3 -Wall -Wextra -Werror -std=c++98
EXEC := scaptrap
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp ScavCanonical.cpp ScavBattle.cpp ScavRepair.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all
