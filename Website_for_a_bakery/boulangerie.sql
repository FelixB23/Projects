-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : jeu. 28 mai 2020 à 11:16
-- Version du serveur :  10.4.11-MariaDB
-- Version de PHP : 7.2.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `boulangerie`
--

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE `client` (
  `commande_id` smallint(6) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `numero_tel` varchar(17) NOT NULL,
  `ville` varchar(255) NOT NULL,
  `code_postal` varchar(6) NOT NULL,
  `rue` varchar(255) NOT NULL,
  `num_rue` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `client`
--

INSERT INTO `client` (`commande_id`, `nom`, `prenom`, `numero_tel`, `ville`, `code_postal`, `rue`, `num_rue`) VALUES
(1, 'Baubriaud', 'Félix', '0781860506', 'Tours', '37 200', 'L\'Alouette', '6 bis'),
(2, 'Bracquier', 'Benjamin', '+33 6 80 80 35 36', 'Tours', '37 200', 'le haut lin', '16 '),
(3, 'Benbadra', 'Merwan', '0201245425', 'Tours', '37 200', 'La Boissière du Doré', '24 bis');

-- --------------------------------------------------------

--
-- Structure de la table `commande`
--

CREATE TABLE `commande` (
  `commande_id` smallint(5) UNSIGNED NOT NULL,
  `jour_heure` datetime NOT NULL,
  `paiement` varchar(12) NOT NULL,
  `produits_commandes` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `commande`
--

INSERT INTO `commande` (`commande_id`, `jour_heure`, `paiement`, `produits_commandes`) VALUES
(1, '2020-05-28 12:30:00', 'effectué', '3 baguette(s) complète(s), 2 pain(s) au chocolat, 1 brioche(s)'),
(2, '2020-05-31 08:00:00', 'non effectué', '3 pain(s) aux graines, 2 chausson(s) aux pommes'),
(3, '2020-06-10 16:00:00', 'effectué', '5 muffin(s), 1 tarte(s) aux pommes');

-- --------------------------------------------------------

--
-- Structure de la table `produits`
--

CREATE TABLE `produits` (
  `produit_id` smallint(5) UNSIGNED NOT NULL,
  `nom` varchar(30) NOT NULL,
  `prix` decimal(5,2) NOT NULL,
  `type` varchar(30) NOT NULL,
  `stock` decimal(5,0) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `produits`
--

INSERT INTO `produits` (`produit_id`, `nom`, `prix`, `type`, `stock`) VALUES
(1, 'baguette_ordinaire', '0.90', 'Pains', '150'),
(2, 'baguette_complete', '1.00', 'Pains', '147'),
(3, 'pain_aux_graines', '0.90', 'Pains', '147'),
(4, 'pains_blanc', '0.80', 'Pains', '150'),
(5, 'boule_ordinaire', '1.00', 'Pains', '150'),
(6, 'pain_muesli', '1.10', 'Pains', '150'),
(7, 'pain_de_mie', '1.20', 'Pains', '150'),
(8, 'croissant', '0.90', 'Viennoiseries', '150'),
(9, 'pain_au_chocolat', '1.00', 'Viennoiseries', '148'),
(10, 'chausson_aux_pommes', '1.20', 'Viennoiseries', '148'),
(11, 'pain_aux_raisins', '1.20', 'Viennoiseries', '150'),
(12, 'cookie', '1.00', 'Viennoiseries', '150'),
(13, 'muffin', '1.50', 'Viennoiseries', '145'),
(14, 'brioche', '2.50', 'Viennoiseries', '149'),
(15, 'eclair_au_chocolat', '1.80', 'patisserie', '150'),
(16, 'eclair_au_cafe', '1.80', 'patisserie', '150'),
(17, 'religieuse_au_chocolat', '2.00', 'patisserie', '150'),
(18, 'religieuse_au_cafe', '2.00', 'patisserie', '150'),
(19, 'mille_feuille', '1.90', 'patisserie', '150'),
(20, 'tartelette', '1.70', 'patisserie', '150'),
(21, 'tarte_aux_pommes', '3.50', 'patisserie', '149'),
(22, 'flan_patissier', '1.50', 'patisserie', '150'),
(23, 'fondant_au_chocolat', '2.00', 'patisserie', '150');

-- --------------------------------------------------------

--
-- Structure de la table `recrutement`
--

CREATE TABLE `recrutement` (
  `recrutement_id` smallint(6) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `numero` varchar(17) NOT NULL,
  `email` varchar(255) NOT NULL,
  `formation` varchar(255) NOT NULL,
  `contrat` varchar(255) NOT NULL,
  `lettre` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `recrutement`
--

INSERT INTO `recrutement` (`recrutement_id`, `prenom`, `nom`, `numero`, `email`, `formation`, `contrat`, `lettre`) VALUES
(1, 'FELIX', 'BAUBRIAUD', '0781860506', 'fsdfsf@fdsfgsd', 'Bac+2', 'CDI', 'Saisissez votre lettre de motivation'),
(2, 'Benjamin', 'BRACQUIER', '0545653212', 'adresse@gmail.com', 'Bac+2', 'CDD', 'Ceci est ma lettre de motivation.'),
(3, 'Merwan', 'BENBADRA', '0555000355', 'benbadra@etu.univ-tours.fr', 'Bac pro', 'CDD', 'Je veux faire ce métier');

-- --------------------------------------------------------

--
-- Structure de la table `sondage`
--

CREATE TABLE `sondage` (
  `sondage_id` smallint(6) NOT NULL,
  `note` varchar(11) NOT NULL,
  `préférence` varchar(30) NOT NULL,
  `conso` varchar(255) NOT NULL,
  `demande` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `sondage`
--

INSERT INTO `sondage` (`sondage_id`, `note`, `préférence`, `conso`, `demande`) VALUES
(1, '10', 'Baguette ordinaire', 'plus de 5 baguettes par semaine', 'Une demande,une réclamation ?'),
(3, '7', 'Mille-feuille', 'plus de 5 baguettes par semaine', 'C\'est parfait, rien à ajouter'),
(4, '8', 'Cookie', '1 à 3 baguettes par semaine', 'Faire plus de cookies'),
(5, '4', 'Pain muesli', 'plus de 5 baguettes par semaine', 'Peut mieux faire');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`commande_id`);

--
-- Index pour la table `commande`
--
ALTER TABLE `commande`
  ADD PRIMARY KEY (`commande_id`);

--
-- Index pour la table `produits`
--
ALTER TABLE `produits`
  ADD PRIMARY KEY (`produit_id`);

--
-- Index pour la table `recrutement`
--
ALTER TABLE `recrutement`
  ADD PRIMARY KEY (`recrutement_id`);

--
-- Index pour la table `sondage`
--
ALTER TABLE `sondage`
  ADD PRIMARY KEY (`sondage_id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `client`
--
ALTER TABLE `client`
  MODIFY `commande_id` smallint(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `commande`
--
ALTER TABLE `commande`
  MODIFY `commande_id` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `produits`
--
ALTER TABLE `produits`
  MODIFY `produit_id` smallint(5) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT pour la table `recrutement`
--
ALTER TABLE `recrutement`
  MODIFY `recrutement_id` smallint(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `sondage`
--
ALTER TABLE `sondage`
  MODIFY `sondage_id` smallint(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
