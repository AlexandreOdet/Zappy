all:
	make -C src_server/
	make -j -C src_graphic/
	make -C src_client/

zappy_server:
	make -C src_server/

zappy_graphic:
	make -j -C src_graphic/

zappy_ai:
	make -C src_client/

clean:
	make clean -C src_server/
	make clean -C src_graphic/
	make clean -C src_client/

fclean:
	make fclean -C src_server/
	make fclean -C src_graphic/
	make fclean -C src_client/

re: fclean all
