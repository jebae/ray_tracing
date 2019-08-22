# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	@printf "$(KGRN)[ray_tracing]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = g++

# lib name
NAME = librt.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

# compiler options
CFLAGS = -Wall -Wextra -Werror -std=c++14

INCLUDES = -I ./$(INCDIR)

# srcs
SRC_MATH = vec4.cpp\
	camera.cpp\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_MATH:.cpp=.o))

# compile objs
HEADERS = $(INCDIR)/vec4.hpp\
	$(INCDIR)/camera.hpp\

$(OBJDIR)/%.o : $(SRCDIR)/math/%.cpp $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[ray_tracing] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[ray_tracing] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re
