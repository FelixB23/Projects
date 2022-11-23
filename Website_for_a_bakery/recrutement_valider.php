<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="utf-8"/>
<title>Recrutement pour POLYBAKER ONLINE</title>
<link href="recrutement.css" rel="stylesheet"/>
<link  href="menu.css" rel="stylesheet">
</head>
<body>

<?php include("menu.php"); ?>
<div class="sous-menu"></div>

<?php
if (isset($_POST['prénom']) AND isset($_POST['nom']) AND isset($_POST['numero']) AND isset($_POST['email']) AND isset($_FILES['depot_CV']) AND isset($_POST['lettre'])) {
	$infosfichier = pathinfo($_FILES['depot_CV']['name']);
    $extension = $infosfichier['extension'];
	if ($_FILES['depot_CV']['error'] == 0 AND $_FILES['depot_CV']['size'] <= 5000000 AND $extension == 'pdf') {
        move_uploaded_file($_FILES['depot_CV']['tmp_name'], 'CV/' . basename($_POST['nom'] . '_' . $_POST['prénom'] . '.pdf'));
        
        try {
            $bdd = new PDO('mysql:host=localhost;dbname=boulangerie;charset=utf8', 'root', '');
        }

        catch(Exception $e) {
            die('Erreur : '.$e->getMessage());
        }

        $reponse = $bdd->query('INSERT INTO recrutement (recrutement_id,prenom,nom,numero,email,formation,contrat,lettre) VALUES (NULL,"' . $_POST['prénom'] . '","' . $_POST['nom'] . '","' . $_POST['numero'] . '","' . $_POST['email'] . '","' . $_POST['formation'] . '","' . $_POST['contrat'] . '","' . $_POST['lettre'] . '")');

        $reponse->closeCursor(); 

        ?>
        <h1>Demande envoyée</h1>
        <p>Merci de l'intérêt que vous portez à notre entreprise. Nous vous contacterons par mail ou par téléphone dès que nous aurons pris connaissance de votre CV et de votre lettre de motivation.</p>
        <?php
    }
    else {
    	?>
    	<h1>Echec de l'envoi</h1>
    	<p>Votre CV n'a pas pu être envoyé. Veillez à ce que le format du CV soit bien en pdf et que sa taille ne dépasse pas 1 Mo puis réessayez.</p>
    <?php
    }
}
else {
	?>
	<h1>Echec de l'envoi</h1>
	<p>Vous devez renseigner nom, prénom, e-mail, CV et lettre de motivation pour pouvoir postuler.</p>
	<?php 
}
?>
<form method="post" action="recrutement.php">
	<input type="submit" class="Valider" value="Retour">
</form>
</body>
</html>
