<?php
    $servidor = "127.0.0.1";
    $usuario = "root";
    $dbname  = "proyecto_web";

    $conn = new mysqli($servidor, $usuario, "", $dbname );

    if ($conn->connect_error) {
        die("Fallo en la conexion: " . $conn->connect_error . "\n");
    } else{
        echo "Conexion exitosa\n";
    }
?>