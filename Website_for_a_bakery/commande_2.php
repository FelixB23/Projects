<?php 
if (!isset($_SESSION['retour'])) {
	session_start();
}
if (isset($_SESSION['bis'])) {
	$_SESSION['bis']=NULL;
}


if (array_key_exists('nom', $_POST) AND array_key_exists('Prénom', $_POST) AND array_key_exists('num_tel', $_POST) AND array_key_exists('num_rue', $_POST) AND array_key_exists('rue', $_POST) AND array_key_exists('code_postal', $_POST) AND array_key_exists('Ville', $_POST) AND array_key_exists('date', $_POST)) {
	foreach ($_POST as $key => $value) {
		$_SESSION[$key] = $_POST[$key];
	}
}

if (array_key_exists('nom', $_SESSION) AND array_key_exists('Prénom', $_SESSION) AND array_key_exists('num_tel', $_SESSION) AND array_key_exists('num_rue', $_SESSION) AND array_key_exists('rue', $_SESSION) AND array_key_exists('code_postal', $_SESSION) AND array_key_exists('Ville', $_SESSION) AND array_key_exists('date', $_SESSION)) {
	$produit=array('baguette_ordinaire','croissant','eclair_au_chocolat','eclair_au_cafe','baguette_complete','pain_au_chocolat','religieuse_au_chocolat','religieuse_au_cafe','pain_aux_graines','chausson_aux_pommes','mille-feuille','pain_blanc','pain_aux_raisins','tartelette','boule_ordinaire','cookie','tarte_aux_pommes','pain_muesli','muffin','flan_patissier','pain_de_mie','brioche','fondant_au_chocolat');
	foreach ($produit as $key) {
		unset($_SESSION[$key]);
	}
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

	<div class="sous-menu"><a href="commande.php">Informations</a> | <a href="#Choix">Choix</a></div>

	<h4>Heure</h4>

	<form method="post" action="commande_3.php">
		<p><label for="heure">A quelle heure souhaitez-vous être livré ? </label><input type="time" name="heure" id="heure" required min="<?php 
		if ($_SESSION['date']==date('Y-m-d') AND date('H')>6) {
			if (date('H')<9) {
				echo '0' . (date('H')+1) . ':' . date('i');
			}
			elseif (date('H')<=18) {
				echo (date('H')+1) . ':' . date('i');
			}
			else {
				echo '19:00';
			}
		}
		else {
			echo '07:00';
		}
		?>" max="<?php
		$joursem = array('dim', 'lun', 'mar', 'mer', 'jeu', 'ven', 'sam');
		list($annee,$mois,$jour) = explode('-', $_SESSION['date']);
		$timestamp = mktime (0, 0, 0, $mois, $jour, $annee);
		if (in_array($joursem[date("w",$timestamp)],array('jeu','dim'))) {
			echo '13:00';
		}
		else {
			echo '19:00';
		}
		?>"></p>
		<p>*Vous ne pouvez être livré que sur les heures d'ouverture de notre boulangerie : 7h-13h inclus le dimanche et le jeudi, et 7h-19h inclus le reste de la semaine. Si vous souhaitez commander pour aujourd'hui, sachez que vous recevrez votre commande dans une heure minimum.</p>

		<?php
		if (!isset($_SESSION['retour'])) {
			echo '<h4 id="Choix">Faites votre choix :</h4>';
		} 
		else {
			echo '<h4 id="Choix"> Veuillez choisir au moins un produit !</h4>';
		}
		?>

		<table>
			<thead>
				<tr><th>Pains<br/>&dArr;&dArr;&dArr;</th><th>Viennoiseries<br/>&dArr;&dArr;&dArr;</th><th>Pâtisserie<br/>&dArr;&dArr;&dArr;</th></tr>
			</thead>
			<tbody>
				<tr>
					<td id="bagord"><label for="baguette_ordinaire">Baguette ordinaire : </label><br/><input type="range" min="0" max="10" id="baguette_ordinaire" name="baguette_ordinaire" onchange="nb1.value=this.value;" value="0"><br/><output name="nb1">0</output></td>
					<td id="croi"><label for="croissant">Croissant : </label><br/><input type="range" min="0" max="10" id="croissant" name="croissant" onchange="nb8.value=this.value;" value="0"><br/><output name="nb8">0</output></td>
					<td id="eclair"><label for="eclair_au_chocolat">Eclair au chocolat : </label><br/><input type="range" min="0" max="10" id="eclair_au_chocolat" name="eclair_au_chocolat" onchange="nb15.value=this.value;" value="0"><output name="nb15">0</output><br/>
					<label for="eclair_au_cafe">Eclair au café : </label><br/><input type="range" min="0" max="10" id="eclair_au_cafe" name="eclair_au_cafe" onchange="nb16.value=this.value;" value="0"><output name="nb16">0</output></td>
				</tr>
				<tr>
					<td id="bagcom"><label for="baguette_complete">Baguette complète : </label><br/><input type="range" min="0" max="10" id="baguette_complete" name="baguette_complete" onchange="nb2.value=this.value;" value="0"><br/><output name="nb2">0</output></td>
					<td id="painchoc"><label for="pain_au_chocolat">Pain au chocolat : </label><br/><input type="range" min="0" max="10" id="pain_au_chocolat" name="pain_au_chocolat" onchange="nb9.value=this.value;" value="0"><br/><output name="nb9">0</output></td>
					<td id="rel"><label for="religieuse_au_chocolat">Religieuse au chocolat : </label><br/><input type="range" min="0" max="10" id="religieuse_au_chocolat" name="religieuse_au_chocolat" onchange="nb17.value=this.value;" value="0"><output name="nb17">0</output><br/>
					<label for="religieuse_au_cafe">Religieuse au café : </label><br/><input type="range" min="0" max="10" id="religieuse_au_cafe" name="religieuse_au_cafe" onchange="nb18.value=this.value;" value="0"><output name="nb18">0</output></td>
				</tr>
				<tr>
					<td id="paingr"><label for="pain_aux_graines">Pain aux graines : </label><br/><input type="range" min="0" max="10" id="pain_aux_graines" name="pain_aux_graines" onchange="nb3.value=this.value;" value="0"><br/><output name="nb3">0</output></td>
					<td id="chausson"><label for="chausson_aux_pommes">Chausson aux pommes : </label><br/><input type="range" min="0" max="10" id="chausson_aux_pommes" name="chausson_aux_pommes" onchange="nb10.value=this.value;" value="0"><br/><output name="nb10">0</output></td>
					<td id="m-f"><label for="mille-feuille">Mille-feuille : </label><br/><input type="range" min="0" max="10" id="mille-feuille" name="mille-feuille" onchange="nb19.value=this.value;" value="0"><br/><output name="nb19">0</output></td>
				</tr>
				<tr>
					<td id="painb"><label for="pain_blanc">Pain blanc : </label><br/><input type="range" min="0" max="10" id="pain_blanc" name="pain_blanc" onchange="nb4.value=this.value;" value="0"><br/><output name="nb4">0</output></td>
					<td id="painr"><label for="pain_aux_raisins">Pain aux raisins : </label><br/><input type="range" min="0" max="10" id="pain_aux_raisins" name="pain_aux_raisins" onchange="nb11.value=this.value;" value="0"><br/><output name="nb11">0</output></td>
					<td id="tart"><label for="tartelette">Tartelette : </label><br/><input type="range" min="0" max="10" id="tartelette" name="tartelette" onchange="nb20.value=this.value;" value="0"><br/><output name="nb20">0</output></td>
				</tr>
				<tr>
					<td id="boule"><label for="boule_ordinaire">Boule ordinaire : </label><br/><input type="range" min="0" max="10" id="boule_ordinaire" name="boule_ordinaire" onchange="nb5.value=this.value;" value="0"><br/><output name="nb5">0</output></td>
					<td id="cook"><label for="cookie">Cookie : </label><br/><input type="range" min="0" max="10" id="cookie" name="cookie" onchange="nb12.value=this.value;" value="0"><br/><output name="nb12">0</output></td>
					<td id="tartp"><label for="tarte_aux_pommes">Tarte aux pommes : </label><br/><input type="range" min="0" max="10" id="tarte_aux_pommes" name="tarte_aux_pommes" onchange="nb21.value=this.value;" value="0"><br/><output name="nb21">0</output></td>
				</tr>
				<tr>
					<td id="painm"><label for="pain_muesli">Pain muesli : </label><br/><input type="range" min="0" max="10" id="pain_muesli" name="pain_muesli" onchange="nb6.value=this.value;" value="0"><br/><output name="nb6">0</output></td>
					<td id="muf"><label for="muffin">Muffin : </label><br/><input type="range" min="0" max="10" id="muffin" name="muffin" onchange="nb13.value=this.value;" value="0"><br/><output name="nb13">0</output></td>
					<td id="flan"><label for="flan_patissier">Flan pâtissier : </label><br/><input type="range" min="0" max="10" id="flan_patissier" name="flan_patissier" onchange="nb22.value=this.value;" value="0"><br/><output name="nb22">0</output></td>
				</tr>
				<tr>
					<td id="mie"><label for="pain_de_mie">Pain de mie : </label><br/><input type="range" min="0" max="10" id="pain_de_mie" name="pain_de_mie" onchange="nb7.value=this.value;" value="0"><br/><output name="nb7">0</output></td>
					<td id="bri"><label for="brioche">Brioche : </label><br/><input type="range" min="0" max="10" id="brioche" name="brioche" onchange="nb14.value=this.value;" value="0"><br/><output name="nb14">0</output></td>
					<td id="fondant"><label for="fondant_au_chocolat">Fondant au chocolat : </label><br/><input type="range" min="0" max="10" id="fondant_au_chocolat" name="fondant_au_chocolat" onchange="nb23.value=this.value;" value="0"><br/><output name="nb23">0</output></td>
				</tr>
			</tbody>
		</table>
		<input type="submit" class="Valider" value="suivant">
	</form>
	</body>
	</html>
	<?php
}

else {
	include('commande.php'); 
}
?>