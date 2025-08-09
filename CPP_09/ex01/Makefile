NAME = RPN

CXX = c++
RM = rm

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98 #-O2 -fsanitize=address,leak
DFLAGS = -MP -MMD

SRCS = 
SRCS += main.cpp 

IDIR = ./
BDIR = .build/
SDIR = ./

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