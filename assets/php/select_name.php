<?php
    require 'conexion.php';

	$titulo = $_POST['titulo'];

    $query = $conn->prepare("SELECT * FROM funciones WHERE titulo LIKE '%".$titulo."%'");
    $query->execute();
    $query = $query->get_result();
    while($row = $query->fetch_assoc()){
        $data[] = $row;
    }

    echo json_encode($data);
?>