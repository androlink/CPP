NAME = bsp

CXX = c++
RMF = rm -f

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98
DFLAGS = -MP -MMD

DDIR = $(BDIR)
HDIR = .

SRCS := main.cpp
SRCS += Fixed.cpp
SRCS += Point.cpp
SRCS += bsp.cpp


OFILES = $(SRCS:%.cpp=%.o)
DFILES = $(SRCS:%.cpp=%.d)

all:
	@echo "compiling $(NAME):"
	@$(MAKE) -s $(NAME)

-include $(DFILES)

$(NAME) : $(OFILES)
	$(CXX) $(CPPFLAGS) -o $@ $(OFILES)
	@echo "$(NAME) compilation done";

%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(DFLAGS) -c $< -o $@
	@echo "	$@"

clean	::
	@echo "cleaning $(NAME)";
	@$(RMF) $(OFILES) $(DFILES)

re		::	fclean
	@$(MAKE) -s all

fclean	::	clean
	@$(RMF) $(NAME)

force :

.PHONY: clean re fclean force all