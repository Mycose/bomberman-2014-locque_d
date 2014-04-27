##
## Makefile for  in /home/laille_n//projet/tek2/cpp/bomberman
##
## Made by nicolas laille
## Login   <laille_n@epitech.net>
##
## Started on  Fri Apr 22 11:52:59 2011 nicolas laille
## Last update Fri Jun 17 17:46:59 2011 damien locque
##

NAME		= bomberman
SRCS		= main.cpp

SRCS_BOMBER	= bomber/ABombe.cpp		\
		  bomber/Bombe.cpp		\
		  bomber/Fire.cpp		\
		  bomber/ACharacter.cpp		\
		  bomber/ABomberman.cpp		\
		  bomber/Bomberman.cpp		\
		  bomber/RandColor.cpp		\
		  bomber/Plant.cpp		\
		  bomber/CheckBombe.cpp

SRCS_SAVE	= save/Serializer.cpp		\
		  save/XMLParser.cpp

SRCS_MAP	= mapgen/ABlock.cpp		\
		  mapgen/Box.cpp		\
		  mapgen/Void.cpp		\
		  mapgen/TMap.cpp		\
		  mapgen/Wall.cpp		\
		  mapgen/BombeContainer.cpp	\
		  mapgen/BonusBomb.cpp		\
		  mapgen/BonusPuiss.cpp		\
		  mapgen/BonusSpeed.cpp		\
		  mapgen/Map.cpp		\
		  mapgen/Mapgen.cpp		\
		  mapgen/Playerpos.cpp

SRCS_ENGINE	= engine/bomb_gl_object.cpp			\
		  engine/bomb_gl_objrotativeobj.cpp		\
		  engine/bomb_gl_texturedsq.cpp			\
		  engine/bomb_gl_inputman.cpp			\
		  engine/bomb_gl_displist.cpp			\
		  engine/bomb_gl_vector3f.cpp			\
		  engine/bomb_gl_graphic.cpp			\
		  engine/bomb_gl_camera.cpp			\
		  engine/bomb_gl_engine.cpp			\
		  engine/bomb_gl_objcontainer.cpp		\
		  engine/objects/bomb_gl_objground.cpp		\
		  engine/objects/bomb_gl_objstrongwall.cpp	\
		  engine/objects/bomb_gl_objdestructwall.cpp	\
		  engine/objects/bomb_gl_objcharacter.cpp	\
		  engine/objects/bomb_gl_objbomb.cpp		\
		  engine/objects/bomb_gl_objfireblock.cpp	\
		  engine/objects/bomb_gl_objbonusbomb.cpp	\
		  engine/objects/bomb_gl_objbonuspowerup.cpp	\
		  engine/objects/bomb_gl_objbonusspeed.cpp

SRCS_MODULE	= module/BomberGame.cpp		\
		  module/BomberMain.cpp		\
		  module/BomberPause.cpp	\
		  module/BomberLoad.cpp		\
		  module/HighScore.cpp		\
		  module/NewGame.cpp		\
		  module/EndGame.cpp		\
		  module/LoadGame.cpp

SRCS_MENU	= menu/GameMenu.cpp					\
		  menu/StrTexture.cpp					\
		  menu/MenuFrame.cpp					\
		  menu/sendData.cpp					\
		  engine/bomb_gl2d_menuitem.cpp				\
		  engine/bomb_gl2d_buttonmenuitem.cpp			\
		  engine/bomb_gl2d_textboxitem.cpp			\
		  engine/objects2D/menuframes/bomb_gl2d_mainframe.cpp	\
		  engine/objects2D/menuframes/bomb_gl2d_scoresframe.cpp	\
		  engine/objects2D/menuframes/bomb_gl2d_newgameframe.cpp\
		  engine/objects2D/menuframes/bomb_gl2d_loadgameframe.cpp\
		  engine/objects2D/menuframes/bomb_gl2d_introframe.cpp\
		  engine/objects2D/bomb_gl2d_btnnewgame.cpp		\
		  engine/objects2D/bomb_gl2d_btnloadgame.cpp		\
		  engine/objects2D/bomb_gl2d_btnhighscores.cpp		\
		  engine/objects2D/bomb_gl2d_btnquitgame.cpp		\
		  engine/objects2D/bomb_gl2d_btnback.cpp		\
		  engine/objects2D/bomb_gl2d_btnaction.cpp		\
		  engine/objects2D/bomb_gl2d_btnlaunchgame.cpp		\
		  engine/objects2D/bomb_gl2d_btnpushaction.cpp		\
		  engine/objects2D/bomb_gl2d_btnsoloversus.cpp		\
		  engine/objects2D/bomb_gl2d_picturebox.cpp

SRCS_LUA	= lua/IABomberman.cpp		\
		  lua/IALua.cpp

OBJS		= $(SRCS:.cpp=.o)
OBJS_SAVE	= $(SRCS_SAVE:.cpp=.o)
OBJS_BOMBER	= $(SRCS_BOMBER:.cpp=.o)
OBJS_MAP	= $(SRCS_MAP:.cpp=.o)
OBJS_ENGINE	= $(SRCS_ENGINE:.cpp=.o)
OBJS_LUA	= $(SRCS_LUA:.cpp=.o)
OBJS_MODULE	= $(SRCS_MODULE:.cpp=.o)
OBJS_MENU	= $(SRCS_MENU:.cpp=.o)

XML_LIB		= libxml.a
XML_SRCS	= save/Markup.cpp
OBJS_XML	= $(XML_SRCS:.cpp=.o)

CXX		= g++
CXXFLAGS	+=  -W -Wall -Wextra -Werror
LIBS		= -L. -L/u/all/gamelab/public/lib -Wl,--rpath=/u/all/gamelab/public/lib -lgdl_gl -lGL -lGLU -llua -lxml
INCPATH		= -Ibomber/ -Imapgen/ -Icommon/ -Imodule/ -I/u/all/gamelab/public/include -Iengine/includes/ -Ilua/ -Isave/ -Imenu/


all		: $(NAME)

$(NAME)		: $(XML_LIB) $(OBJS) $(OBJS_BOMBER) $(OBJS_MAP) $(OBJS_ENGINE) $(OBJS_LUA) $(OBJS_MODULE) $(OBJS_SAVE) $(OBJS_MENU)
		$(CXX) -o $(NAME) $(OBJS) $(OBJS_BOMBER) $(OBJS_MAP) $(OBJS_ENGINE) $(OBJS_LUA) $(OBJS_MODULE) $(OBJS_SAVE) $(OBJS_MENU) $(CXXFLAGS) $(LIBS)
		@echo "all"
		@echo "\`$(NAME)' built."

$(XML_LIB)	: $(OBJS_XML)
		ar r $(XML_LIB) $(OBJS_XML)
		ranlib $(XML_LIB)


$(OBJS_XML)	:
		$(CXX) -c save/Markup.cpp -o save/Markup.o

.cpp.o		:
		$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<


clean		:
		$(RM) $(OBJS)
		$(RM) $(OBJS_SAVE)
		$(RM) $(OBJS_BOMBER)
		$(RM) $(OBJS_MAP)
		$(RM) $(OBJS_ENGINE)
		$(RM) $(OBJS_LUA)
		$(RM) $(OBJS_MODULE)
		$(RM) $(OBJS_MENU)
		$(RM) $(OBJS_XML)
		@echo "clean"
		@echo "Done."


fclean		: clean
		$(RM) $(NAME)
		$(RM) $(XML_LIB)
		@echo "fclean"
		@echo "Done."


re		: fclean all
		@echo "re"
		@echo "Done."
