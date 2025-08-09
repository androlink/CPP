NAME = form

CC = c++
RM = rm

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98
DFLAGS = -MP -MMD

SRCS = 
SRCS += main.cpp
SRCS += Form.cpp
SRCS += Bureaucrat.cpp

IDIR = includes/
BDIR = .build/
SDIR = srcs/

SFILES = $(SRCS:%=$(SDIR)%)
OFILES = $(SRCS:%.cpp=$(BDIR)%.o)
DFILES = $(SRCS:%.cpp=$(BDIR)%.d)

all:	$(NAME)

-include $(DFILES)

$(NAME): $(OFILES)
	$(CC) $(CPPFLAGS) -o $@ $(OFILES)

$(BDIR)%.o : $(SDIR)%.cpp
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(DFLAGS) -c $< -o $@ -I $(IDIR)

clean:
	$(RM) -f $(OFILES) $(DFILES)

fclean: clean
	$(RM) -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean re fclean all