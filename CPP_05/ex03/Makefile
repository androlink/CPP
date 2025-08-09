NAME = intern

CXX = c++
RM = rm

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98
DFLAGS = -MP -MMD

SRCS = 
SRCS += main.cpp
SRCS += AForm.cpp
SRCS += Bureaucrat.cpp
SRCS += PresidentialPardonForm.cpp
SRCS += RobotomyRequestForm.cpp
SRCS += ShrubberyCreationForm.cpp
SRCS += Intern.cpp

IDIR = includes/
BDIR = .build/
SDIR = srcs/

SFILES = $(SRCS:%=$(SDIR)%)
OFILES = $(SRCS:%.cpp=$(BDIR)%.o)
DFILES = $(SRCS:%.cpp=$(BDIR)%.d)

all:	$(NAME)

-include $(DFILES)

$(NAME): $(OFILES)
	$(CXX) $(CPPFLAGS) -o $@ $(OFILES)

$(BDIR)%.o : $(SDIR)%.cpp
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(DFLAGS) -c $< -o $@ -I $(IDIR)

clean:
	$(RM) -f $(OFILES) $(DFILES)

fclean: clean
	$(RM) -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean re fclean all