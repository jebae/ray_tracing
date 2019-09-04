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
CFLAGS = -Wall -Wextra -Werror -std=c++11

INCLUDES = -I ./$(INCDIR)

LIBS = -lmlx\
	 -L. -lrt\

FRAMEWORKS = -framework AppKit\
	-framework OpenGL\

# srcs
SRC_MATH = vec4.cpp\
	camera.cpp\

SRC_RAY = ray_grid_props.cpp\
	ray.cpp\

SRC_OBJECT = object.cpp\
	sphere.cpp\
	cone.cpp\
	cylinder.cpp\
	plane.cpp\

SRC_TRACE = trace_record.cpp\
	tracer.cpp\

SRC_SHADE = shade.cpp\
	ambient.cpp\

SRC_MLX = mlx_kit.cpp\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_MATH:.cpp=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_RAY:.cpp=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_OBJECT:.cpp=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_TRACE:.cpp=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_SHADE:.cpp=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_MLX:.cpp=.o))

# compile objs
HEADERS = $(INCDIR)/vec4.hpp\
	$(INCDIR)/camera.hpp\
	$(INCDIR)/ray.hpp\
	$(INCDIR)/object.hpp\
	$(INCDIR)/sphere.hpp\
	$(INCDIR)/cone.hpp\
	$(INCDIR)/cylinder.hpp\
	$(INCDIR)/plane.hpp\
	$(INCDIR)/trace_record.hpp\
	$(INCDIR)/tracer.hpp\
	$(INCDIR)/shade.hpp\
	$(INCDIR)/mlx_kit.hpp\

$(OBJDIR)/%.o : $(SRCDIR)/math/%.cpp $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/ray/%.cpp $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/object/%.cpp $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/trace/%.cpp $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/shade/%.cpp $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/mlx/%.cpp $(HEADERS)
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
build_test : all
	@$(CC) $(CFLAGS) $(INCLUDES) -I ./srcs/__tests__ $(LIBS) $(FRAMEWORKS) ./srcs/__tests__/*.cpp -o test

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re build_test
