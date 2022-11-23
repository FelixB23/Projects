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

<h1 id="titre"><strong>La boulangerie POLYBAKER ONLINE recrute!</strong></h1><br/>
<p>Nous recherchons un Patissier Boulanger, si vous êtes passionné, créatif et rigoureux, ce travail est fait pour vous:</p>

<p><em>Quelle sera votre travail ?</em></p>
<ul>
	<li>Vous devez avoir une expérience préalable en viennoiseries.</li>
	<li>Vous devrez effectuer des livraisons en vélo.</li>
	<li>Vous devrez préparer les différentes viennoiseries dès votre arrivée le matin, avant l'arrivée des clients.</li>
	<li>Vous devrez nettoyer la boulangerie à la fin de votre journée</li>
</ul>

<p>Pour postuler, veuillez remplir attentivement le formulaire de recrutement suivant.</p>

<form method="post" action="recrutement_valider.php" enctype="multipart/form-data">
	<label for="prénom"> Quel est votre prénom ?</label><br/>
	<input type="text" name="prénom" id="prénom" placeholder="CHAMP OBLIGATOIRE" required pattern="[a-zA-Z éèêëàâäiîïôöûü-]{1,}" /><br/>
	<span id="aidep"></span><br/>

	<label for="nom"> Quel est votre nom ?</label><br/>
	<input type="text" name="nom" id="nom" placeholder="CHAMP OBLIGATOIRE" required pattern="[A-Z]{1,}" title="Tout en majuscule"/><br/>

	<label for="numero"> Quel est votre numéro de téléphone ?</label><br/>
	<input type="tel" name="numero" id="numero" placeholder="CHAMP OBLIGATOIRE" required pattern="(0|\+33 )[1-9]( ?[0-9]{2}){4}"/><br/>

	<label for="email"> Quel est votre email ?</label><br/>
	<input type="email" name="email" placeholder="CHAMP OBLIGATOIRE" required id="email"/>
	<br/>
	
	<label for="formation"> Choisissez votre formation :</label><br/>
	<select name="formation" id="formation">
		<option>BEP</option>
		<option>Bac pro</option>
		<option>Bac+2</option>
		<option>Bac+3</option>
		<option>Autre</option>
	</select><br/>

	<label for="contrat"> Choisissez un type de contrat :</label><br/>
	<select name="contrat" id="contrat">
		<option>CDD</option>
		<option>CDI</option>
	</select>	
	<br/>
	<br/>
	<label for="CV"> Selectionnez votre CV : (format : pdf ; taille max : 5Mo)</label><br/>
	<input type="file" id="CV" required name="depot_CV"/>
		<br/>
		<br/>
	<textarea rows="25" cols="100" name="lettre" required class="lettremotiv">Saisissez votre lettre de motivation</textarea>

	<p> Pensez à bien vérifier les informations saisies avant de valider !	</p>
	<br/>
	<p>Si votre candidature est sélectionnée, vous serez contacter par e-mail.</p><br/>

	<input type="submit" value="ENVOYER"/>
</form>	

<script>
	
	// champ prenom saisi

	document.getElementById("prénom").addEventListener("input", function (e) {
	    var prénom = e.target.value; // Valeur saisie dans le champ prénom
	    var longueurp = "normal";
	    var couleurMsg = "blue"; // Longueur normal: couleur bleue
	    if (prénom.length >= 25) {
	        longueurp = "trop importante. Verifier votre saisie !";
	        couleurMsg = "red"; // Longueur excessive => couleur rouge !
	    } 
	    var aidepElt = document.getElementById("aidep");
	    aidepElt.textContent = "Longueur : " + longueurp; // Texte de l'aide
	    aidepElt.style.color = couleurMsg; // Couleur du texte de l'aide
	    prenom.style.color= couleurMsg;
	}); 

</script>	
</body>
</html>
