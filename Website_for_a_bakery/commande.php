<!DOCTYPE html>
<html lang="fr">
<head>
<title>Commande</title>
<meta charset="UTF-8">
<link href="Commande.css" rel="stylesheet">
<link  href="menu.css" rel="stylesheet">
</head>
<body>

<?php include("menu.php"); ?>

<div class="sous-menu"><a href="#Adresse">Adresse</a> | <a href="#Identité">Identité</a> | <a href="#Date">Date</a></div>

<h1>Commande</h1>
<p>Si vous habitez dans un rayon de 5km de notre boulangerie, vous pouvez commander du pain, des viennoiseries ou des pâtisseries à domicile !</p>

<img src="rayon.png" alt="rayon" width="900" height="800">

<h3>Commander maintenant:</h3>
<p>*Tous les champs doivent être remplis.</p>

<form method="post" action="commande_2.php">
	<h4 id="Adresse">Adresse</h4>
	<p><label for="Ville">Ville : </label><input type="text" name="Ville" maxlength="30" value="Tours" title="Entrer la ville de votre domicile" id="Ville" size="15" required pattern="[a-zA-Z éèêëàâäiîïôöûü-']{1,}"/></p>
	<p><label for="code_postal">Code postal : </label><input type="text" name="code_postal" maxlength="6" value="37 200" title="Entrer le code postale de la ville" id="code_postal" required size="8" pattern="[0-9]{2} ?[0-9]{3}"/></p>
	<p><label for="rue">Rue : </label><input type="text" name="rue" maxlength="40" title="Entrer la rue de votre habitat" id="rue" size="25" required pattern="[a-zA-Z éèêëàâäiîïôöûü-']{1,}"/></p>
	<p><label for="num_rue">Numéro de rue : </label><input type="number" name="num_rue" id="num_rue" title="Quel est le numéro de la rue ?" required min="1" max="1000"><input type="checkbox" name="bis" id="bis"><label for="bis">bis</label></p>

	<h4 id="Identité">Identité</h4>
	<p><label for="nom">Nom : </label><input type="text" name="nom" maxlength="20" title="Entrer votre nom de famille" id="nom" size="15" required pattern="[a-zA-Z éèêëàâäiîïôöûü-']{1,}"/></p>
	<p><label for="Prénom">Prénom : </label><input type="text" name="Prénom" maxlength="20" title="Entrer votre prénom" id="Prénom" size="15" required pattern="[a-zA-Z éèêëàâäiîïôöûü-']{1,}"/></p>
	<p><label for="num_tel">Numéro de téléphone </label><input type="tel" name="num_tel" placeholder="+33 # ## ## ## ##" maxlength="17" title="Entrer votre numéro de téléphone" id="num_tel" pattern="(0|\+33 )[1-9]( ?[0-9]{2}){4}" size="17" required/></p>
			
	<h4 id="Date">Date</h4>
	<p><label for=date>Veuillez sélectionner une date : </label><input type="date" required name="date" id="date" min="<?php 
	$joursem = array('dim', 'lun', 'mar', 'mer', 'jeu', 'ven', 'sam');
	list($jour, $mois, $annee) = explode('/', date("d/m/Y"));
	$timestamp = mktime (0, 0, 0, $mois, $jour, $annee); // $joursem[date("w",$timestamp)] est le jour de la semaine
	if ((in_array($joursem[date("w",$timestamp)],array('jeu','dim')) AND date('H')<12) OR (in_array($joursem[date("w",$timestamp)],array('lun', 'mar', 'mer', 'ven', 'sam')) AND date('H')<18)) {
		echo date('Y-m-d'); 
		$condition=True;
	}
	else {
		$condition=False;
		if (((date('m')==1 OR date('m')==3 OR date('m')==5 OR date('m')==7 OR date('m')==8) AND date('d')==31) OR ((date('m')==4 OR date('m')==6) AND date('d')==30) OR (date('m')==2 AND date('d')>=28)) {
			echo date('Y') . '-0' . (date('m')+1) . '-01';
		}
		if (((date('m')==9 OR date('m')==11) AND date('d')==30) OR (date('m')==10 AND date('d')==31)) {
			echo date('Y') . '-' . (date('m')+1) . '-01';
		}
		if (date('m')==12 AND date('d')==31) {
			echo (date('Y')+1) . '-01-01';
		}
		else {
			echo date('Y-m') . '-' . (date('d')+1);
		}
	}
	?>" max="<?php 
	if (date('m')<9) {
		echo date('Y') . '-0' . (date('m')+1) . '-12'; 
	}
	elseif (date('m')<12) {
		echo date('Y') . '-' . (date('m')+1) . '-12'; 
	}
	else {
		echo (date('Y')+1) . '-01-12'; 
	}
	?>"></p>
	<p>*Vous pouvez passer une commande entre 
	<?php 
	if ($condition==True) {
		echo "aujourd'hui";
	}
	else {
		echo "demain";
	}
	?>
	 et le 12 du mois prochain.</p>
	<input type="submit" class="Valider" value="suivant">
</form>
</body>
</html>	

