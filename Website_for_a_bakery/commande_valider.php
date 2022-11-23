<?php 
session_start();
?>

<?php
if (isset ($_POST['Terminer'])) {
	$reponse=$_POST['Terminer'];
	if ($reponse=="Oui") {
		?>
		<!DOCTYPE html>
		<html lang="fr">
		<head>
		<title>Valider la commande</title>
		<meta charset="UTF-8">
		<link href="Commande.css" rel="stylesheet">
		<link  href="menu.css" rel="stylesheet">
		</head>
		<body>

		<?php
		try {
			$bdd = new PDO('mysql:host=localhost;dbname=boulangerie;charset=utf8', 'root', '');
		}

		catch(Exception $e) {
        	die('Erreur : '.$e->getMessage());
		}

		if (isset($_SESSION['bis'])) {
			$bis='bis';
			unset($_SESSION['bis']);
		}
		else {
			$bis='';
		}


		if ($_SESSION['paiement']==2) {
			$paiement='non effectué';
		}
		else {
			$paiement='effectué';
		}

		$reponse = $bdd->query('INSERT INTO client (commande_id,nom,prenom,numero_tel,ville,code_postal,rue,num_rue) VALUES (NULL,"' . $_SESSION['nom'] . '","' . $_SESSION['Prénom'] . '","' . $_SESSION['num_tel'] . '","' . $_SESSION['Ville'] . '","' . $_SESSION['code_postal'] . '","' . $_SESSION['rue'] . '","' . $_SESSION['num_rue'] . ' ' . $bis . '")');

		$text=implode(", ",$_SESSION['produits_commandes']);

		$reponse = $bdd->query('INSERT INTO commande (commande_id,jour_heure,paiement,produits_commandes) VALUES (NULL,"' . $_SESSION['date'] . ' ' . $_SESSION['heure'] . '","' . $paiement . '","' . $text . '")');

		$informations=array('nom','Prénom','Ville','code_postal','num_tel','date','heure','num_rue','rue','paiement','produits_commandes');

		foreach ($informations as $key) {
			unset($_SESSION[$key]);
		}

		foreach ($_SESSION as $key => $value) {
  			$reponse = $bdd->query('UPDATE produits SET stock=stock-' . $value . ' WHERE nom="'.$key.'"');
		}

		$reponse->closeCursor(); 

		include("menu.php");
		?>

		<div class="sous-menu"></div>

   		<p>Votre commande a bien été effectuée.</p>
  		<form method="post" action="index.php">
   			<input type="submit" class="Valider" value="retour à l'accueil">
   		</form>
   		</body>
   		</html>
   		<?php
   		session_destroy();
  	}
 	else {
 		session_destroy();
  		include('commande.php');
  	}
}

elseif (isset($_SESSION['nom']) AND isset($_SESSION['Prénom']) AND isset($_SESSION['num_tel']) AND isset($_SESSION['num_rue']) AND isset($_SESSION['rue']) AND isset($_SESSION['code_postal']) AND isset($_SESSION['Ville']) AND isset($_SESSION['heure']) AND isset($_SESSION['date']) AND (isset($_SESSION['baguette_ordinaire']) OR isset($_SESSION['croissant']) OR isset($_SESSION['eclair_au_chocolat']) OR isset($_SESSION['eclair_au_cafe']) OR isset($_SESSION['baguette_complete']) OR isset($_SESSION['pain_au_chocolat']) OR isset($_SESSION['religieuse_au_chocolat']) OR isset($_SESSION['religieuse_au_cafe']) OR isset($_SESSION['pain_aux_graines']) OR isset($_SESSION['chausson_aux_pommes']) OR isset($_SESSION['mille-feuille']) OR isset($_SESSION['pain_blanc']) OR isset($_SESSION['pain_aux_raisins']) OR isset($_SESSION['tartelette']) OR isset($_SESSION['boule_ordinaire']) OR isset($_SESSION['cookie']) OR isset($_SESSION['tarte_aux_pommes']) OR isset($_SESSION['pain_muesli']) OR isset($_SESSION['muffin']) OR isset($_SESSION['flan_patissier']) OR isset($_SESSION['pain_de_mie']) OR isset($_SESSION['brioche']) OR isset($_SESSION['fondant_au_chocolat'])) AND isset($_POST['paiement'])) {
	$_SESSION['paiement']=$_POST['paiement'];
	?>
	<!DOCTYPE html>
	<html lang="fr">
	<head>
	<title>Valider la commande</title>
	<meta charset="UTF-8">
	<link href="Commande.css" rel="stylesheet">
	<link  href="menu.css" rel="stylesheet">
	</head>

	<?php
	include("menu.php");
	?>

	<div class="sous-menu"><a href="commande.php">Informations</a> | <a href="commande_2.php">Choix</a> | <a href="commande_3.php">Paiement</a> | <a href="#">Finaliser la commande</a></div>

	<p>&rArr;Nom : <strong><?php echo $_SESSION['nom'] . '</strong> ---- Prénom : <strong>' . $_SESSION['Prénom'] . '</strong> ---- Téléphone : <strong>' . $_SESSION['num_tel']; ?></strong></p>

	<p>&rArr;Livraison au <strong><?php echo $_SESSION['num_rue'];
	if (isset($_SESSION['bis'])) {echo ' bis';}
	echo  ' rue ' . $_SESSION['rue'] . ' ' . $_SESSION['code_postal'] . ' ' . $_SESSION['Ville'] . '</strong> à <strong>' . $_SESSION['heure'] . '</strong> le <strong>' . $_SESSION['date'];?></strong></p>

	<p>&rArr;Votre commande :<p>
	<ul>
		<?php 
		$total=0;
		$nb_article=0;
		if (isset($_SESSION['baguette_ordinaire'])) {
			echo '<li>' . $_SESSION['baguette_ordinaire'] . ' baguette(s) ordinaire(s) : ' . $_SESSION['baguette_ordinaire'] . ' × 0.90 €</li>';
			$total+=$_SESSION['baguette_ordinaire']*0.90;
			$nb_article+=$_SESSION['baguette_ordinaire'];
			$_SESSION['produits_commandes'][]=$_SESSION['baguette_ordinaire'] . ' baguette(s) ordinaire(s)';
		}
		if (isset($_SESSION['baguette_complete'])) {
			echo '<li>' . $_SESSION['baguette_complete'] . ' baguette(s) complète(s) : ' . $_SESSION['baguette_complete'] . ' × 1.00 €</li>';
			$total+=$_SESSION['baguette_complete']*1.00;
			$nb_article+=$_SESSION['baguette_complete'];
			$_SESSION['produits_commandes'][]=$_SESSION['baguette_complete'] . ' baguette(s) complète(s)';
		}
		if (isset($_SESSION['pain_aux_graines'])) {
			echo '<li>' . $_SESSION['pain_aux_graines'] . ' pain(s) aux graines : ' . $_SESSION['pain_aux_graines'] . ' × 0.90 €</li>';
			$total+=$_SESSION['pain_aux_graines']*0.90;
			$nb_article+=$_SESSION['pain_aux_graines'];
			$_SESSION['produits_commandes'][]=$_SESSION['pain_aux_graines'] . ' pain(s) aux graines';
		}
		if (isset($_SESSION['pain_blanc'])) {
			echo '<li>' . $_SESSION['pain_blanc'] . ' pain(s) blanc(s) : ' . $_SESSION['pain_blanc'] . ' × 0.80 €</li>';
			$total+=$_SESSION['pain_blanc']*0.80;
			$nb_article+=$_SESSION['pain_blanc'];
			$_SESSION['produits_commandes'][]=$_SESSION['pain_blanc'] . ' pain(s) blanc(s)';
		}
		if (isset($_SESSION['boule_ordinaire'])) {
			echo '<li>' . $_SESSION['boule_ordinaire'] . ' boule(s) ordinaire(s) : ' . $_SESSION['boule_ordinaire'] . ' × 1.00 €</li>';
			$total+=$_SESSION['boule_ordinaire']*1.00;
			$nb_article+=$_SESSION['boule_ordinaire'];
			$_SESSION['produits_commandes'][]=$_SESSION['boule_ordinaire'] . ' boule(s) ordinaire(s)';
		}
		if (isset($_SESSION['pain_muesli'])) {
			echo '<li>' . $_SESSION['pain_muesli'] . ' pain(s) muesli : ' . $_SESSION['pain_muesli'] . ' × 1.10 €</li>';
			$total+=$_SESSION['pain_muesli']*1.10;
			$nb_article+=$_SESSION['pain_muesli'];
			$_SESSION['produits_commandes'][]=$_SESSION['pain_muesli'] . ' pain(s) muesli';
		}
		if (isset($_SESSION['pain_de_mie'])) {
			echo '<li>' . $_SESSION['pain_de_mie'] . ' pain(s) de mie : ' . $_SESSION['pain_de_mie'] . ' × 1.20 €</li>';
			$total+=$_SESSION['pain_de_mie']*1.20;
			$nb_article+=$_SESSION['pain_de_mie'];
			$_SESSION['produits_commandes'][]=$_SESSION['pain_de_mie'] . ' pain(s) de mie';
		}
		if (isset($_SESSION['croissant'])) {
			echo '<li>' . $_SESSION['croissant'] . ' croissant(s) : ' . $_SESSION['croissant'] . ' × 0.90 €</li>';
			$total+=$_SESSION['croissant']*0.90;
			$nb_article+=$_SESSION['croissant'];
			$_SESSION['produits_commandes'][]=$_SESSION['croissant'] . ' croissant(s)';
		}
		if (isset($_SESSION['pain_au_chocolat'])) {
			echo '<li>' . $_SESSION['pain_au_chocolat'] . ' pain(s) au chocolat : ' . $_SESSION['pain_au_chocolat'] . ' × 1.00 €</li>';
			$total+=$_SESSION['pain_au_chocolat']*1.00;
			$nb_article+=$_SESSION['pain_au_chocolat'];
			$_SESSION['produits_commandes'][]=$_SESSION['pain_au_chocolat'] . ' pain(s) au chocolat';
		}
		if (isset($_SESSION['chausson_aux_pommes'])) {
			echo '<li>' . $_SESSION['chausson_aux_pommes'] . ' chausson(s) aux pommes : ' . $_SESSION['chausson_aux_pommes'] . ' × 1.20 €</li>';
			$total+=$_SESSION['chausson_aux_pommes']*1.20;
			$nb_article+=$_SESSION['chausson_aux_pommes'];
			$_SESSION['produits_commandes'][]=$_SESSION['chausson_aux_pommes'] . ' chausson(s) aux pommes';
		}
		if (isset($_SESSION['pain_aux_raisins'])) {
			echo '<li>' . $_SESSION['pain_aux_raisins'] . ' pain(s) aux raisins : ' . $_SESSION['pain_aux_raisins'] . ' × 1.20 €</li>';
			$total+=$_SESSION['pain_aux_raisins']*1.20;
			$nb_article+=$_SESSION['pain_aux_raisins'];
			$_SESSION['produits_commandes'][]=$_SESSION['pain_aux_raisins'] . ' pain(s) aux raisins';
		}
		if (isset($_SESSION['cookie'])) {
			echo '<li>' . $_SESSION['cookie'] . ' cookie(s) : ' . $_SESSION['cookie'] . ' × 1.00 €</li>';
			$total+=$_SESSION['cookie']*1.00;
			$nb_article+=$_SESSION['cookie'];
			$_SESSION['produits_commandes'][]=$_SESSION['cookie'] . ' cookie(s)';
		}
		if (isset($_SESSION['muffin'])) {
			echo '<li>' . $_SESSION['muffin'] . ' muffin(s) : ' . $_SESSION['muffin'] . ' × 1.50 €</li>';
			$total+=$_SESSION['muffin']*1.50;
			$nb_article+=$_SESSION['muffin'];
			$_SESSION['produits_commandes'][]=$_SESSION['muffin'] . ' muffin(s)';
		}
		if (isset($_SESSION['brioche'])) {
			echo '<li>' . $_SESSION['brioche'] . ' brioche(s) : ' . $_SESSION['brioche'] . ' × 2.50 €</li>';
			$total+=$_SESSION['brioche']*2.50;
			$nb_article+=$_SESSION['brioche'];
			$_SESSION['produits_commandes'][]=$_SESSION['brioche'] . ' brioche(s)';
		}
		if (isset($_SESSION['eclair_au_chocolat'])) {
			echo '<li>' . $_SESSION['eclair_au_chocolat'] . ' éclair(s) au chocolat : ' . $_SESSION['eclair_au_chocolat'] . ' × 1.80 €</li>';
			$total+=$_SESSION['eclair_au_chocolat']*1.80;
			$nb_article+=$_SESSION['eclair_au_chocolat'];
			$_SESSION['produits_commandes'][]=$_SESSION['eclair_au_chocolat'] . ' éclair(s) au chocolat';
		}
		if (isset($_SESSION['eclair_au_cafe'])) {
			echo '<li>' . $_SESSION['eclair_au_cafe'] . ' éclair(s) au café : ' . $_SESSION['eclair_au_cafe'] . ' × 1.80 €</li>';
			$total+=$_SESSION['eclair_au_cafe']*1.80;
			$nb_article+=$_SESSION['eclair_au_cafe'];
			$_SESSION['produits_commandes'][]=$_SESSION['eclair_au_cafe'] . ' éclair(s) au café';
		}
		if (isset($_SESSION['religieuse_au_chocolat'])) {
			echo '<li>' . $_SESSION['religieuse_au_chocolat'] . ' religieuse(s) au chocolat : ' . $_SESSION['religieuse_au_chocolat'] . ' × 2.00 €</li>';
			$total+=$_SESSION['religieuse_au_chocolat']*2.00;
			$nb_article+=$_SESSION['religieuse_au_chocolat'];
			$_SESSION['produits_commandes'][]=$_SESSION['religieuse_au_chocolat'] . ' religieuse(s) au chocolat';
		}
		if (isset($_SESSION['religieuse_au_cafe'])) {
			echo '<li>' . $_SESSION['religieuse_au_cafe'] . ' religieuse(s) au café : ' . $_SESSION['religieuse_au_cafe'] . ' × 2.00 €</li>';
			$total+=$_SESSION['religieuse_au_cafe']*2.00;
			$nb_article+=$_SESSION['religieuse_au_cafe'];
			$_SESSION['produits_commandes'][]=$_SESSION['religieuse_au_cafe'] . ' religieuse(s) au café';
		}
		if (isset($_SESSION['mille-feuille'])) {
			echo '<li>' . $_SESSION['mille-feuille'] . ' mille-feuille(s) : ' . $_SESSION['mille-feuille'] . ' × 1.90 €</li>';
			$total+=$_SESSION['mille-feuille']*1.90;
			$nb_article+=$_SESSION['mille-feuille'];
			$_SESSION['produits_commandes'][]=$_SESSION['mille-feuille'] . ' mille-feuille(s)';
		}
		if (isset($_SESSION['tartelette'])) {
			echo '<li>' . $_SESSION['tartelette'] . ' tartelette(s) : ' . $_SESSION['tartelette'] . ' × 1.70 €</li>';
			$total+=$_SESSION['tartelette']*1.70;
			$nb_article+=$_SESSION['tartelette'];
			$_SESSION['produits_commandes'][]=$_SESSION['tartelette'] . ' tartelette(s)';
		}
		if (isset($_SESSION['tarte_aux_pommes'])) {
			echo '<li>' . $_SESSION['tarte_aux_pommes'] . ' tarte(s) aux pommes : ' . $_SESSION['tarte_aux_pommes'] . ' × 3.50 €</li>';
			$total+=$_SESSION['tarte_aux_pommes']*3.50;
			$nb_article+=$_SESSION['tarte_aux_pommes'];
			$_SESSION['produits_commandes'][]=$_SESSION['tarte_aux_pommes'] . ' tarte(s) aux pommes';
		}
		if (isset($_SESSION['flan_patissier'])) {
			echo '<li>' . $_SESSION['flan_patissier'] . ' flan(s) pâtissier(s) : ' . $_SESSION['flan_patissier'] . ' × 1.50 €</li>';
			$total+=$_SESSION['flan_patissier']*1.50;
			$nb_article+=$_SESSION['flan_patissier'];
			$_SESSION['produits_commandes'][]=$_SESSION['flan_patissier'] . ' flan(s) pâtissier(s)';
		}
		if (isset($_SESSION['fondant_au_chocolat'])) {
			echo '<li>' . $_SESSION['fondant_au_chocolat'] . ' fondant(s) au chocolat : ' . $_SESSION['fondant_au_chocolat'] . ' × 2.00 €</li>';
			$total+=$_SESSION['fondant_au_chocolat']*2.00;
			$nb_article+=$_SESSION['fondant_au_chocolat'];
			$_SESSION['produits_commandes'][]=$_SESSION['fondant_au_chocolat'] . ' fondant(s) au chocolat';
		}
		$frais=2+floor($nb_article/5)*2;
		?>
	</ul>

	<p>&rArr;Frais de livraison : <?php echo $frais ?> €<br/>
	(augmente de 2 euros tous les 5 articles)

	<p>Total à payer : <?php echo number_format($total+$frais,2) ?> €<br/>

		&rArr;Vous avez choisi de <strong>payer
		<?php 
		if ($_SESSION['paiement']=='2') {
			echo 'lors de la livraison.</strong>';
		}
		else {
			echo 'maintenant</strong> par carte bancaire.';
		}
		?>
		</p>

	<form method="post">
  		<p>Envoyer ces informations ?</p>
  		<div id="oui_non">
  			<input type="submit" name="Terminer" class="Valider" value="Oui"/>
  			<input type="submit" name="Terminer" class="Valider" value="Non"/>
 		</div>
 	</form>
 	</body>
 	</html>

	<?php
}

else {
	?>
	<!DOCTYPE html>
	<html lang="fr">
	<head>
	<title>Erreur</title>
	<meta charset="UTF-8">
	<link href="Commande.css" rel="stylesheet">
	<link  href="menu.css" rel="stylesheet">
	</head>

	<?php
	include("menu.php");
	?>

	<div class="sous-menu"></div>

	<div id="erreur"><strong>Erreur :</strong> vous n'avez probablement pas rempli toutes les pages précédentes.</div>

	<form method="post" action="index.php">
  	 	<input type="submit" class="Valider" value="retour à l'accueil">
   	</form>
   	</body>
	</html>
   	<?php
}
?>


