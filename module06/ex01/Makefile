CFLAGS := -g3 -Wall -Wextra -Werror -std=c++98
EXEC := serializer
SRCS := main.cpp serializer.cpp
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