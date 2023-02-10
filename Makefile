# EXECUTABLE
NAME		= ft_containers
NAME_TEST	= test_containers

# HEADERS
INC_DIR 	= ./includes/
INC_FILES	= Stack.hpp
INCLUDE		= $(addprefix $(INC_DIR)/, $(INC_FILES))

# SOURCES
SRC_DIR		= ./srcs
SRC_FILES	= main.cpp

# TEST
TEST_DIR	= objs_test
STD_OBJS	= $(addprefix $(TEST_DIR)/, $(SRC_FILES:.cpp=.o))

# OBJS
OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.cpp=.o))

# COMMANDS
RM			= rm -rf
CC			= c++

# COLORS
RESET		=	\033[0m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
WHITE		=	\033[1;37m
ORANGE		=	\033[1;38;5;208m
UP			=	\033[A
CUT			=	\033[K

# FLAGS
CPPFLAGS	= -Wall -Wextra -Werror -g -std=c++98

# RULES

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
				@echo "$(CUT)$(BLUE)clang $(RESET)$(notdir $@)"
				@printf "$(UP)"

$(TEST_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I$(INC_DIR) -DSTD -c $< -o $@
				@echo "$(CUT)$(BLUE)clang $(RESET)$(notdir $@)"
				@printf "$(UP)"

all:	$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $^ -o $@
				@echo "$(CUT)$(GREEN)✔ $(NAME) created$(RESET)"

fclean:	clean
				@$(RM) $(NAME) diff.log ft_test.log std_test.log
				@echo "$(RED)✘ fclean$(RESET)"

test:	$(NAME_TEST)

DIFF			=	-@diff -sc --suppress-common-lines ft_test.log std_test.log

$(NAME_TEST):	$(OBJS) $(STD_OBJS)
				@$(CC) $(CFLAGS) $(STD_OBJS) -o $(NAME_TEST)
				@./$(NAME_TEST) > std_test.log
				@$(RM) $(STD_OBJS) $(TEST_DIR)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@./$(NAME) > ft_test.log
				@$(RM) $(OBJS) $(OBJS_DIR)
				@$(DIFF) > diff.log
				@$(DIFF)
				@rm ft_test.log std_test.log $(NAME) $(NAME_TEST)

clean:
				@$(RM) $(OBJS) $(OBJS_DIR)
				@echo "$(RED)✘ clean$(RESET)"



re:		fclean all

.PHONY:	all clean fclean re test diff