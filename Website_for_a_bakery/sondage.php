<!DOCTYPE html >
<html lang="fr">
<head>
<meta charset="utf-8"/>
<title>SONDAGE POUR POLYBAKER ONLINE</title>
<link href="sondage.css" rel="stylesheet"/>
<link  href="menu.css" rel="stylesheet">
</head>

<body>

<?php include("menu.php"); ?>
<div class="sous-menu"></div>

<h1> POLYBAKER ONLINE VOUS ECOUTE</h1><br>
<p>Merci de prendre le temps de renseigner le formulaire ci dessous. Ce formulaire de sondage a pour but de collecter des avis, des opinions de la part des clients. Merci de rester courtois et poli !</p>
<img src="https://cdn.pixabay.com/photo/2017/06/23/23/57/bread-2436370_960_720.jpg" alt="pain">	
<form method="post" action="index.php">
	<p>Quelle note donneriez vous à la boulangerie ? <br/>
	<input type="range" min="0" max="10" id="note" name="note" onchange="nb.value=this.value;" value="10"/> <output name="nb">10</output></p>

	<p>Que préférez-vous dans notre Boulangerie ?
	<select name='préférence'>
		<optgroup label="Pains">
			<option value="Baguette ordinaire">Baguette ordinaire</option>
			<option value="Baguette complète">Baguette complète</option>
			<option value="Pain aux graines">Pain aux graines</option>
			<option value="Pain blanc">Pain blanc</option>
			<option value="Boule ordinaire">Boule ordinaire</option>
			<option value="Pain muesli">Pain muesli</option>
			<option value="Pain de mie">Pain de mie</option>
		</optgroup>
		<optgroup label="Viennoiseries">
			<option value="Croissant">Croissant</option>
			<option value="Pain au chocolat">Pain au chocolat</option>
			<option value="Chausson aux pommes">Chausson aux pommes</option>
			<option value="Pain au raisin">Pain au raisin</option>
			<option value="Cookie">Cookie</option>
			<option value="Muffin">Muffin</option>
			<option value="Brioche">Brioche</option>
		</optgroup>
		<optgroup label="Pâtisserie">
			<option value="Eclair au chocolat">Eclair au chocolat</option>
			<option value="Religieuse au chocolat">Religieuse au chocolat</option>
			<option value="Mille-feuille">Mille-feuille</option>
			<option value="Tartelette">Tartelette</option>
			<option value="Tarte aux pommes">Tarte aux pommes</option>
			<option value="Flan pâtissier">Flan pâtissier</option>
			<option value="Fondant au chocolat">Fondant au chocolat</option>
		</optgroup>
	</select></p>

	<p>Quelle est votre consommation de pain par semaine ?</p>
	<input type="radio" name="conso" value=1 id="1-3"><label for="1-3">1 à 3 baguettes </label>
	<input type="radio" name="conso" value=2 id="4-5"><label for="4-5">4 à 5 baguettes </label>
	<input type="radio" name="conso" value=3 id="+5" checked><label for="+5">plus de 5 baguettes </label><br/>
	<br/>
	<textarea  rows="20" cols="50" name="demande" class="demande">Une demande,une réclamation ?</textarea>
	<input type="submit" value="ENVOI" class="envoi">
<!--<script type="text/javascript">
	//var pain = document.getElementById("pain");
	//var vitesse = 7; // Valeur du déplacement en pixels

// Déplace le bloc sur sa gauche
//function deplacerPain() {
    // Conversion en nombre de la position gauche du bloc (valeur de la forme "XXpx")
    //var xpain = parseFloat(getComputedStyle(pain).left);
    // Déplacement du pain
   // pain.style.left = (xpain + vitesse) + "px";
    // Demande au navigateur d'appeler deplacerPain dès que possible
   // requestAnimationFrame(deplacerPain);
}//
//requestAnimationFrame(deplacerPain); // Début de l'animation//
</script>!-->
</form>
</body>

