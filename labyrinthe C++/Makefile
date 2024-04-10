# Paramétrage du compilateur et des options de compilation des modules
COMP = g++
OPTIONS = -c

# Paramétrage de l'exécutable et de la liste des objets qui le composent
EXECUTABLE = exec
OBJETS = objet_graphique.o objet_graphique_mobile.o objet_graphique_fixe.o personnage.o mur.o couloir.o sortie.o plateau.o labyrinthe.o main.o

# Description des cibles
${EXECUTABLE}:${OBJETS}
	${COMP} -o ${EXECUTABLE} ${OBJETS}

objet_graphique.o: objet_graphique.cpp objet_graphique.hpp saisieIncorrecte.hpp
	${COMP} ${OPTIONS} objet_graphique.cpp

objet_graphique_mobile.o: objet_graphique_mobile.cpp objet_graphique_mobile.hpp objet_graphique.hpp
	${COMP} ${OPTIONS} objet_graphique_mobile.cpp

objet_graphique_fixe.o: objet_graphique_fixe.cpp objet_graphique_fixe.hpp objet_graphique.hpp
	${COMP} ${OPTIONS} objet_graphique_fixe.cpp

personnage.o: personnage.cpp personnage.hpp objet_graphique_mobile.hpp
	${COMP} ${OPTIONS} personnage.cpp

mur.o: mur.cpp mur.hpp objet_graphique_fixe.hpp
	${COMP} ${OPTIONS} mur.cpp

couloir.o: couloir.cpp couloir.hpp objet_graphique_fixe.hpp
	${COMP} ${OPTIONS} couloir.cpp

sortie.o: sortie.cpp sortie.hpp objet_graphique_fixe.hpp
	${COMP} ${OPTIONS} sortie.cpp

plateau.o: plateau.cpp plateau.hpp objet_graphique_fixe.hpp objet_graphique_mobile.hpp
	${COMP} ${OPTIONS} plateau.cpp

labyrinthe.o: labyrinthe.cpp labyrinthe.hpp personnage.hpp plateau.hpp deplacementImpossible.hpp
	${COMP} ${OPTIONS} labyrinthe.cpp

main.o: main.cpp mur.hpp couloir.hpp sortie.hpp labyrinthe.hpp
	${COMP} ${OPTIONS} main.cpp