<!DOCTYPE html>
<html>

<head>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1.0" />
	<link href="assets/css/utilities.css" rel="stylesheet">
	<link href="assets/css/style.css" rel="stylesheet" />
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.1.1/css/all.min.css" integrity="sha512-KfkfwYDsLkIlwQp6LFnl8zNdLGxu9YAA1QvwINks4PhcElQSvqcyVLLD9aMhXd13uQjoXtEKNosOWaZqXgel0g==" crossorigin="anonymous" referrerpolicy="no-referrer" />
	<title>Ticket UNAM</title>
</head>

<body>
	<!-- Navbar -->
	<?php include_once("assets/php/navbar.php"); ?>

	<!-- Showcase -->
	<div id="showcase-create">
		<section id="create" class="container">
			<h1>Agregar pelicula</h1>
			<form id="form-create" class="flex">
				<input type="text" name="titulo" placeholder="Titulo" required/>
				<input type="text" name="genero" placeholder="Genero" required/>
				<input type="file" name="portada" placeholder="Portada" required/>
				<input type="number" name="precio" placeholder="Precio" required step="any" min="0"/>
				<input id="btn-nuevo" type="submit" class="btn btn-secondary" value="Enviar"/>
			</form>
		</section>
	</div>

	<!-- Footer -->
	<?php include_once("assets/php/footer.php"); ?>

	<!-- Scripts -->
	<script src="assets/js/parse_create.js" type="module"></script>
</body>

</html>