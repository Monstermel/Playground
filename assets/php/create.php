<?php
	require 'conexion.php';

	$titulo = $_POST['titulo'];
    $genero = $_POST['genero'];
    $portada = $_FILES['portada'];
    $precio = $_POST['precio'];

	$query = $conn->prepare("INSERT INTO funciones (titulo, genero, portada, precio) VALUES (?, ?, ?, ?)");
    $query ->bind_param("sssd", $titulo, $genero, $portada["name"], $precio);
    $query ->execute();

    if(move_uploaded_file($portada["tmp_name"], $_SERVER["DOCUMENT_ROOT"]."/assets/img/".$portada["name"])){
		echo "Archivo subido con exito\n";
	} else {
		die("Error al subir el archivo: ".$portada["error"]."\n");
	}

	$conn->close();
?>