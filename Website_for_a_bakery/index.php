<!DOCTYPE html>
<html lang="fr">  
<head>
<title>accueil</title>
<meta charset="UTF-8" />
<link  href="acceuil.css" rel="stylesheet">
<link  href="menu.css" rel="stylesheet">
</head>

<body>
<?php 
include("menu.php"); 
if (isset($_POST['note']) AND isset($_POST['préférence']) AND isset($_POST['conso']) AND isset($_POST['demande'])) {
	try {
			$bdd = new PDO('mysql:host=localhost;dbname=boulangerie;charset=utf8', 'root', '');
		}

	catch(Exception $e) {
        die('Erreur : '.$e->getMessage());
	}

	if ($_POST['conso']==1) {
		$conso='1 à 3 baguettes par semaine';
	}
	elseif ($_POST['demande']==2) {
		$conso='4 à 5 baguettes par semaine';
	}
	else {
		$conso='plus de 5 baguettes par semaine';
	}

	$reponse = $bdd->query('INSERT INTO sondage (sondage_id,note,préférence,conso,demande) VALUES (NULL,"' . $_POST['note'] . '","' . $_POST['préférence'] . '","' . $conso . '","' . $_POST['demande'] . '")');

	$reponse->closeCursor();
	?>
	<script type="text/javascript">alert('Merci d\'avoir participé à notre sondage !')</script>
	<?php
}
?>

<div class="sous-menu"><a href="#presentation">Présentation</a> | <a href="#localisation">Localisation</a> | <a href="#promos">Aperçu de nos produits</a></div>

<h1 id="presentation" >Présentation</h1>

<p>Faites-vous livrer vos produits préférés, préparés par votre artisan boulanger local. Récupérez-les directement avec notre service à domicile et dégustez-les pour bien commencer la journée. Nous utilisons des ingrédients de qualités, tous d’origine française avec une livraison rapide sans pollution. En effet, nos stagiaires vous apporteront vos pains, pâtisseries et viennoiseries (que vous pouvez commander depuis notre site, rubrique <a href="commande.php">commande</a>) en vélo. Cette boulangerie, créé récemment est en construction dans de nombreuses régions. </p>

<h1 id="localisation">Localisation</h1>

<div id="bloc">
	<iframe id="local" src="https://www.google.com/maps/d/embed?mid=1TQA5tkqKcCF6et-7V8qamthcTcriMQwa" width="500" height="400"></iframe>

	<p>Notre boulangerie se situe près du parc Grandmont, à Tours. Si vous habitez dans un rayon de 5km de la boulangerie vous pouvez commander toutes sortes de produits qui arriveront chez vous 1 heure (minimum) après commande.</p>
</div>
   
<h1 id="promos">Aperçu de nos produits</h1>

<table>
	<thead>
		<tr><th colspan="4" class="produit">Un aperçu de quelques-uns de nos produits</th></tr>
		<tr><th>Produit</th><th>Prix</th><th>Image</th><th>Composition</th></tr>
	</thead>
	<tbody>
		<tr><td>Baguette ordinaire</td><td class="prix">0.90€</td><td><a href="https://live.staticflickr.com/8420/9023500355_77ebd1e218_b.jpg"><img src="https://live.staticflickr.com/8420/9023500355_77ebd1e218_b.jpg" alt="Baguette ordinaire" width="400" height="350"></a></td><td>La baguette est fabriquée à partir de farine, d'eau, de levure et/ou de levain, et de sel. On n'utilise pas d' œuf, de produits laitiers ou d’ huile . </td></tr>
		<tr><td>Pain au chocolat</td><td class="prix">1.00€</td><td><a href="https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/2016-08_Pains_au_chocolat_02.jpg/800px-2016-08_Pains_au_chocolat_02.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/6b/2016-08_Pains_au_chocolat_02.jpg/800px-2016-08_Pains_au_chocolat_02.jpg" alt="Pain au chocolat" width="400" height="350"></a></td><td>Le pain au chocolat contient près de 50 % de glucides. Il s’agit pour les deux tiers de glucides complexes, qui proviennent de la farine, et pour un tiers de sucre. Le pain au chocolat comporte plus de 20 % de lipides, soit presque l’équivalent de 2 portions individuelles de beurre dans une viennoiserie.</td></tr>
		<tr><td>Brioche</td><td class="prix">2.50€</td><td><a href="https://cdn.pixabay.com/photo/2016/11/09/15/06/brioche-1811926_960_720.jpg"><img src="https://cdn.pixabay.com/photo/2016/11/09/15/06/brioche-1811926_960_720.jpg" alt="Brioche" width="400" height="350"></a></td><td>La brioche est une viennoiserie, à pâte levée et assez aérée, contenant du beurre (400 grammes minimum par kilogramme de farine) et des œufs. </td></tr>    
	</tbody>
</table>
<p>Retrouvez la totalité des produits que nous proposons dans la rubrique <a href="tarifs_horaires.php">Tarifs et horaires</a>.</p>
</body>
</html>