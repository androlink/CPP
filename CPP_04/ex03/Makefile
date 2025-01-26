NAME = ex03

CC = c++
RMF = rm -f

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98 -Wshadow
DFLAGS = -MP -MMD

DDIR = $(BDIR)
HDIR = .

SRCS := AMateria.cpp
SRCS += Charcter.cpp
SRCS += Cure.cpp
SRCS += Ice.cpp
SRCS += main.cpp
SRCS += MateriaSource.cpp

OFILES = $(SRCS:%.cpp=%.o)
DFILES = $(SRCS:%.cpp=%.d)

all:
	@echo "compiling $(NAME):"
	@$(MAKE) -s $(NAME)

-include $(DFILES)

$(NAME) : $(OFILES)
	$(CC) $(CPPFLAGS) -o $@ $(OFILES)
	@echo "$(NAME) compilation done";

%.o : %.cpp
	$(CC) $(CPPFLAGS) $(DFLAGS) -c $< -o $@
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