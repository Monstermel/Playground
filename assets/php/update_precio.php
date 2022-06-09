<?php
	require 'conexion.php';

	$id = $_POST['id'];
	$precio = $_POST['precio'];

	$query = $conn->prepare("UPDATE funciones SET precio = ".$precio." WHERE id=".$id);
    $query ->execute();

	$conn->close();
?>