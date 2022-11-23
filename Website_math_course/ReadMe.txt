Ce projet a été réalisé par Félix Baubriaud et Merwan Benbadra. C'est un site sur le programme de mathématiques de terminale S.

Pour lancer le site web, il suffit de mettre tout dans le même fichier et d'ouvrir la page d'accueil ("accueil.html"), puis de naviguer sur les pages du site via le menu. 
Il y a 12 pages en tout. Nous avons mis les exercices sur les mêmes pages que les chapitres concernés.
Nous avons fait le choix de créer qu'un seul fichier css pour caractériser les 12 pages à la fois, le style étant à peu près le même pour chaque page.
Nous avons testé le site sur les navigateurs firefox et chrome.

Pour réaliser ce site, nous nous sommes aidés des cours de mathématiques que nous avions eu en terminale. 
Nous avons utilisé le langage LaTeX pour écrire les formules mathématiques. 
Il existe plusieurs méthodes pour écrire du LaTeX dans une page HTML, souvent compliquées (logiciel spécial nécessaire). 
Nous avons choisi la plus simple qui consiste à insérer une balise javascript dans l'entête de chaque page puis d'écrire le code LaTeX entre les balises \( et \).
Ce fut un travail suplémentaire pour nous qui n'avions jamais pratiqué le LaTeX avant.

Nous nous sommes réparti les tâches de la façon suivante : l'un s'occupait des chapitres impairs + page du bac (Félix), l'autre des chapitres pairs + page d'accueil (Merwan).

La première difficulté était de trouver comment utiliser le LaTeX. Après de nombreuses recherches sur internet, nous avons consulté régulièrement ce site et ses liens pour nous aider :
https://www.tutos.eu/2170
Au début nous n'arrivions pas à placer le texte à coté du menu (il apparaissait en dessous) puis nous avons réussi en utilisant en css le champ float en plus de display, appliqué à la div contenant le menu.
Nous voulions trouver une méthode pour afficher les réponses aux exercices à la fin des chapitres sans utiliser de php. Pour cela nous avons consulté ce site permettant de le faire entièrement en css et html:
https://forum.alsacreations.com/topic-1-86228-1-Resolu-Masquerafficher-un-bloc-de-texte-au-clic.html

Les images que nous avons utilisées (pour les courbes principalement) sont cliquables et emmènent vers les sites où nous les avons trouvées, 
sauf pour les images que nous avons créées manuellement (l'arbre de probabilité et le cercle trigonométrique) qui sont dans le fichier zippé.
Pour la page sur le bac, nous avons utilisé des liens d'annales que nous avons trouvé sur le site https://www.sujetdebac.fr/ .
