<?php
	require 'conexion.php';

	$id = $_POST['id'];
	$genero = $_POST['genero'];

	$query = $conn->prepare("UPDATE funciones SET genero = '".$genero."' WHERE id=".$id);
    $query ->execute();

	$conn->close();
?>