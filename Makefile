CC = gcc
FLAGS = -Wall -g
#--------------------------------------------------------------------------------------
batailleNavale:	positionnement.o affichage.o initialisation.o jeux.o tour.o menu.o main.o header.h
	$(CC) -o $@ positionnement.o affichage.o initialisation.o jeux.o tour.o menu.o main.o  $(FLAGS)

main.o:	main.c header.h
	$(CC) -o $@ -c main.c $(FLAGS)

positionnement.o: positionnement.c header.h
	$(CC) -o $@ -c positionnement.c $(FLAGS)

affichage.o: affichage.c header.h
	$(CC) -o $@ -c affichage.c $(FLAGS)

initialisation.o: initialisation.c header.h
	$(CC) -o $@ -c initialisation.c $(FLAGS)	

jeux.o:	jeux.c header.h
	$(CC) -o $@ -c jeux.c $(FLAGS)

tour.o:	tour.c header.h
	$(CC) -o $@ -c tour.c $(FLAGS)

menu.o: menu.c header.h
	$(CC) -o $@ -c menu.c $(FLAGS)
#--------------------------------------------------------------------------------------
testBatailleNavale: tester.o positionnement.o affichage.o initialisation.o jeux.o tour.o header.h
	$(CC) -o $@ tester.o positionnement.o affichage.o initialisation.o jeux.o tour.o $(FLAGS)

tester.o: tester.c header.h
	$(CC) -o $@ -c tester.c $(FLAGS)
#--------------------------------------------------------------------------------------
clean:
		rm -f *.o *~ core
