<?php
    require 'conexion.php';

    $query = $conn->prepare("SELECT * FROM funciones");
    $query->execute();
    $query = $query->get_result();
    while($row = $query->fetch_assoc()){
        $data[] = $row;
    }

    echo json_encode($data);
?>