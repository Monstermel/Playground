<?php
	require 'conexion.php';

	$id = $_POST["id"];

	// $query = $conn->prepare("SELECT portada FROM funciones WHERE id = ".$id);
	// $query ->execute();
	// $query = $query->get_result();
	// unlink($_SERVER["DOCUMENT_ROOT"]."/assets/img/".$query["portada"]);

	$query = $conn->prepare("DELETE FROM funciones WHERE id = ".$id);
    $query ->execute();

	$conn->close();
?>