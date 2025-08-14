<?php
	require 'conexion.php';

	$id = $_POST['id'];
	$titulo = $_POST['titulo'];

	$query = $conn->prepare("UPDATE funciones SET titulo = '".$titulo."' WHERE id=".$id);
    $query ->execute();

	$conn->close();
?>