	# Library Name #
NAME	= 	minishell

	# Compilator #
COMPILER	= 	clang

	# Variables #
SRCS		= 	coucou.c \
				checkers/is_what_alphanum.c \
				checkers/is_what_others.c \
				utils/utils_digits.c \
				utils/utils_gnl.c \
				utils/utils_linked.c \
				utils/utils_mem.c \
				utils/utils_str.c \
				utils/utils_write.c

INCLUDES 	= 	includes/minishell.h

	# Colors Foreground #
DEFAULT		=	\033[0;39m
BLACK		=	\033[0;30m
RED			=	\033[0;31m
RED_B		=	\033[1;31m
L_RED		=	\033[0;91m
GREEN		=	\033[0;32m
GREEN_B		=	\033[1;32m
L_GREEN		=	\033[0;92m
YELLOW		=	\033[0;33m
L_YELLOW	=	\033[0;93m
BLUE		=   \033[0;34m
BLUE_B		=	\033[1;34m
L_BLUE		=   \033[0;94m
PINK		=	\033[0;35m
L_PINK		=	\033[0;95m
SKY			=   \033[0;36m
SKY_B		=	\033[1;36m
L_CYAN		=   \033[0;96m
GREY		=	\033[0;37m
D_GREY		=	\033[0;90m
WHITE		=	\033[0;97m
RESET		=	\e[0m

	# Colors Background #
NOIR		=	\033[0;40m
ROUGE		=	\033[0;41m
L_ROUGE		=	\033[0;101m
VERT		=	\033[0;42m
L_VERT		=	\033[0;102m
JAUNE		=	\033[0;43m
L_JAUNE		=	\033[0;103m
BLEU		=	\033[0;44m
L_BLEU		=	\033[0;104m
ROSE		=	\033[0;45m
L_ROSE		=	\033[0;105m
CYAN		=	\033[0;46m
L_CYAN		=	\033[0;106m
GRIS		=	\033[0;100m
BLANC		=	\033[0;107m

	# Objects #
OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})
DEP		= $(OBJS:.o=.d)

	# Flags #

FLAGS	= 	-Wall -Werror -Wextra

	# Rules #
all:		${NAME}
			@printf "$(L_PINK)<3 <3 $(RESET)"
			@printf "$(RED_B)Manu et Dim le sang$(RESET)"
			@printf "$(L_PINK) <3 <3 \n$(RESET)"

$(NAME):	${OBJS} ${INCLUDES}
			${COMPILER} ${FLAGS} -I includes ${OBJS} -o $(NAME)
			@printf	"\n\n"
			@printf "$(GRIS)                                                                                                                                                                  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                  $(RESET)$(BLANC)  $(RESET)$(NOIR)                                                                                          $(RESET)$(ROUGE)              $(RESET)$(NOIR)                                  $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                $(RESET)$(BLANC)      $(RESET)$(NOIR)                                                                                  $(RESET)$(ROUGE)                          $(RESET)$(NOIR)                            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)              $(RESET)$(BLANC)          $(RESET)$(NOIR)                                                                            $(RESET)$(ROUGE)                                  $(RESET)$(NOIR)                        $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)            $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                                        $(RESET)$(ROUGE)          $(RESET)$(JAUNE)        $(RESET)$(ROUGE)  $(RESET)$(JAUNE)        $(RESET)$(ROUGE)          $(RESET)$(NOIR)                      $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)              $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                                    $(RESET)$(ROUGE)        $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)        $(RESET)$(ROUGE)  $(RESET)$(JAUNE)        $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)        $(RESET)$(NOIR)                    $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                                $(RESET)$(ROUGE)        $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)        $(RESET)$(NOIR)                  $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                  $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                            $(RESET)$(ROUGE)        $(RESET)$(JAUNE)      $(RESET)$(ROUGE)    $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)    $(RESET)$(JAUNE)      $(RESET)$(ROUGE)        $(RESET)$(NOIR)                $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                    $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                        $(RESET)$(ROUGE)          $(RESET)$(JAUNE)        $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)        $(RESET)$(ROUGE)          $(RESET)$(NOIR)              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                      $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                      $(RESET)$(ROUGE)            $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)            $(RESET)$(NOIR)              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                        $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                  $(RESET)$(ROUGE)        $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)        $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                          $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                $(RESET)$(ROUGE)      $(RESET)$(JAUNE)        $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)        $(RESET)$(ROUGE)      $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                            $(RESET)$(BLANC)              $(RESET)$(NOIR)                                              $(RESET)$(ROUGE)        $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)        $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                          $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                $(RESET)$(ROUGE)          $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)          $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                        $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                  $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)    $(RESET)$(ROUGE)    $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                      $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                    $(RESET)$(ROUGE)    $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)  $(RESET)$(JAUNE)      $(RESET)$(ROUGE)    $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                    $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                      $(RESET)$(ROUGE)    $(RESET)$(JAUNE)        $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)        $(RESET)$(ROUGE)    $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                  $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                        $(RESET)$(ROUGE)    $(RESET)$(JAUNE)          $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)    $(RESET)$(ROUGE)  $(RESET)$(JAUNE)          $(RESET)$(ROUGE)    $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                          $(RESET)$(ROUGE)      $(RESET)$(JAUNE)          $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)          $(RESET)$(ROUGE)      $(RESET)$(NOIR)            $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)              $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                              $(RESET)$(ROUGE)      $(RESET)$(JAUNE)          $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)          $(RESET)$(ROUGE)  $(RESET)$(JAUNE)  $(RESET)$(ROUGE)  $(RESET)$(JAUNE)          $(RESET)$(ROUGE)      $(RESET)$(NOIR)              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)            $(RESET)$(BLANC)              $(RESET)$(NOIR)                                                                  $(RESET)$(ROUGE)       $(RESET)$(JAUNE)                                   $(RESET)$(ROUGE)        $(RESET)$(NOIR)                $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)              $(RESET)$(BLANC)          $(RESET)$(NOIR)                                                                      $(RESET)$(ROUGE)        $(RESET)$(JAUNE)                              $(RESET)$(ROUGE)        $(RESET)$(NOIR)                  $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                $(RESET)$(BLANC)      $(RESET)$(NOIR)                                                                          $(RESET)$(ROUGE)      $(RESET)$(JAUNE)                              $(RESET)$(ROUGE)      $(RESET)$(NOIR)                    $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                  $(RESET)$(BLANC)  $(RESET)$(NOIR)                                                                            $(RESET)$(ROUGE)      $(RESET)$(JAUNE)                              $(RESET)$(ROUGE)      $(RESET)$(NOIR)                    $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                  $(RESET)$(ROUGE)    $(RESET)$(JAUNE)                              $(RESET)$(ROUGE)    $(RESET)$(NOIR)                      $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                          $(RESET)$(BLANC)                              $(RESET)$(NOIR)                          $(RESET)$(ROUGE)    $(RESET)$(JAUNE)                              $(RESET)$(ROUGE)    $(RESET)$(NOIR)                      $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                          $(RESET)$(BLANC)                              $(RESET)$(NOIR)                          $(RESET)$(ROUGE)                $(RESET)$(JAUNE)      $(RESET)$(ROUGE)                $(RESET)$(NOIR)                      $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                          $(RESET)$(BLANC)                              $(RESET)$(NOIR)                          $(RESET)$(ROUGE)                                      $(RESET)$(NOIR)                      $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                          $(RESET)$(BLANC)                              $(RESET)$(NOIR)                                          $(RESET)$(ROUGE)      $(RESET)$(NOIR)                                      $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)  $(RESET)$(NOIR)                                                                                                                                                              $(RESET)$(GRIS)  $(RESET)\n"
			@printf "$(GRIS)                                                                                                                                                                  $(RESET)\n"
			@printf	"\n\n"
			@printf "$(BLUE_B)Si tu ramasses un coquillage et que tu le portes à ton oreille, tu entendras la mer. Si tu le portes à ta poitrine, il entendra ton coeur <3 \n\n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)La vie passe, la moulinette trepasse !\n\n$(RESET)"

-include $(DEP)

objs/%.o:		srcs/%.c
					@mkdir -p $(dir $@)
					@${COMPILER} -MMD ${FLAGS} -I includes -o $@ -c $< 

norme:		
			@norminette srcs/*
			@norminette includes/*
			@printf "$(YELLOW)\nLa normalité est une expérience plus extrême que ce que les gens veulent communément admettre.\n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)La vie passe, la norminette trepasse !\n$(RESET)"

clean:
			rm -f ${OBJS}
			@printf "$(YELLOW)\nAu fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)===$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)Que la paix regne sur ton foyer\n\n$(RESET)"
fclean:
			rm -f ${OBJS}
			rm -f ${NAME}
			rm -rf objs
			@printf "$(YELLOW)\nAu fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)===$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)Que la paix regne sur ton foyer\n\n$(RESET)"

re:			fclean all
			@printf "$(YELLOW)\nAimer, désirer, c’est aussi souffrir, et être prêt à recommencer... \n$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			
.PHONY: 	all norme clean fclean re
