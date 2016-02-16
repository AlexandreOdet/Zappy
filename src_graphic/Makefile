CXX =		g++ -W -Wall -Wextra -Werror

CXXFLAGS +=	-I./lib/gdl/includes/ -I./lib/fmod/ -I./Game/ -I./object/ -I./ -I./Player/ -I./Network/ -I./HUD/ -std=c++11 -I./NetWork/

LDFLAGS +=	-L./lib/gdl/libs/ -lgdl_gl -lGL -lGLU -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -lSDL2_ttf -lSDL2_image ./lib/fmod/lib/libfmodexL64.so -Wl,-rpath=./src_graphic/lib/gdl/libs/

NAME =		../zappy_graphic

SRC =		main.cpp		\
		Sound.cpp		\
		Network/NetWork.cpp	\
		Network/RingBuff.cpp	\
		Network/Exec.cpp	\
		HUD/HUD.cpp		\
		Game/Camera.cpp		\
		Game/texture.cpp	\
		Game/MyGame.cpp		\
		Game/Ressource.cpp	\
		Game/Case.cpp		\
		Player/Team.cpp		\
		Player/Vivi.cpp		\
		Player/Egg.cpp		\
		object/Cube.cpp		\
		object/Plan.cpp

OBJ =		$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ) *~ *#

fclean: clean
	rm -f $(NAME)

re: fclean all
