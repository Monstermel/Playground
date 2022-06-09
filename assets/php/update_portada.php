<?php
	require 'conexion.php';

	$id = $_POST['id'];
	$portada = $_FILES['portada'];

	$query = $conn->prepare("UPDATE funciones SET portada = '".$portada["name"]."' WHERE id=".$id);
    $query ->execute();

	if(move_uploaded_file($portada["tmp_name"], $_SERVER["DOCUMENT_ROOT"]."/assets/img/".$portada["name"])){
		echo "Archivo subido con exito\n";
	} else {
		die("Error al subir el archivo: ".$portada["error"]."\n");
	}

	$conn->close();
?>