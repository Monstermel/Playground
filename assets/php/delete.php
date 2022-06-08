<?php
	require 'conexion.php';

	$id = $_POST["id"];

	var_dump($_POST);

	$query = $conn->prepare("DELETE FROM funciones WHERE id = ".$id);
    $query ->execute();

	$conn->close();
?>