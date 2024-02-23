# Directories

OBJDIR = obj
SRCDIR = src

# File names
NAME = calculator
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Commands
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20 -Wextra -g -MD
CPPFLAGS = -Iinclude
LDFLAGS =
DEBUGFLAGS = -DMAP
RM = rm -f
ECHO = echo
LIBRAIRIES =

.PHONY: all clean fclean re run debug

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(NAME) $(LIBRAIRIES)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $@

debug:
	make re CXXFLAGS="$(CXXFLAGS) $(DEBUGFLAGS)"

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

-include $(OBJS:.o=.d)
