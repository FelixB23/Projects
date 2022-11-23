<?php 
session_start(); 

foreach ($_POST as $key => $value) {
	if ($value>0) {
		$_SESSION[$key]=$value;
	}
}

if (!isset($_SESSION['baguette_ordinaire']) AND !isset($_SESSION['croissant']) AND !isset($_SESSION['eclair_au_chocolat']) AND !isset($_SESSION['eclair_au_cafe']) AND !isset($_SESSION['baguette_complete']) AND !isset($_SESSION['pain_au_chocolat']) AND !isset($_SESSION['religieuse_au_chocolat']) AND !isset($_SESSION['religieuse_au_cafe']) AND !isset($_SESSION['pain_aux_graines']) AND !isset($_SESSION['chausson_aux_pommes']) AND !isset($_SESSION['mille-feuille']) AND !isset($_SESSION['pain_blanc']) AND !isset($_SESSION['pain_aux_raisins']) AND !isset($_SESSION['tartelette']) AND !isset($_SESSION['boule_ordinaire']) AND !isset($_SESSION['cookie']) AND !isset($_SESSION['tarte_aux_pommes']) AND !isset($_SESSION['pain_muesli']) AND !isset($_SESSION['muffin']) AND !isset($_SESSION['flan_patissier']) AND !isset($_SESSION['pain_de_mie']) AND !isset($_SESSION['brioche']) AND !isset($_SESSION['fondant_au_chocolat'])) {
	$_SESSION['retour']='retour';
	include("commande_2.php");
}

else {
	?>
	<!DOCTYPE html>
	<html lang="fr">
	<head>
	<title>Commande</title>
	<meta charset="UTF-8">
	<link href="Commande.css" rel="stylesheet">
	<link  href="menu.css" rel="stylesheet">
	</head>
	<body>

	<?php
	include("menu.php");
	?>

	<div class="sous-menu"><a href="commande.php">Informations</a> | <a href="commande_2.php">Choix</a> | <a href="#Paiement">Paiement</a></div>

	<form method="post" action="commande_valider.php">
		<h4 id="Paiement">Paiement</h4>

		<p id="Payer"><label for="livraison">Payer lors de la livraison</label><input type="radio" name="paiement" id="livraison" value="2" onchange="form.payer.disabled=true"></p>
		<fieldset name="payer">
			<legend><label for="maintenant">Payer maintenant</label><input type="radio" checked name="paiement" id="maintenant" value="1" onchange="form.payer.disabled=false"></legend>
			<p><label for="numcarte">Numéro de carte : </label>
			<input type="text" name="numcarte" id="numcarte" title="16 chiffres - possibilité de mettre un espace tous les 4 chiffres" required pattern="([0-9]{16}|([0-9]{4} ){3}[0-9]{4})"></p>
			<p><label for="validité">Date de validité : </label>
			<input type="text"  name="validité" id="validité" required pattern="((0[1-9])|(1[0-2]))/202[0-9]" placeholder="mm/aaaa"></p>
			<p><label for="code">Code de sécurité : </label>
			<input type="text"  name="code" id="code" title="code de 3 chiffres situé au dos de la carte" maxlength="3" required pattern="[0-9]{3}"></p>
		</fieldset>
		<p><input type="submit" class="Valider" value="&rarr; Valider la commande"></p>
	</form>		
	</body>
	</html>
	<?php
}
?>