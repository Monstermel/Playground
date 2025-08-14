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
	<div id="showcase-update">
		<section id="update" class="container">
			<h1>Actualizar datos</h1>
			<form id="form-update-titulo" class="flex">
				<input type="text" name="titulo" placeholder="Titulo" required/>
				<input id="btn-update-titulo" type="submit" class="btn btn-secondary" value="Actualizar"/>
			</form>
			<form id="form-update-genero" class="flex">
				<input type="text" name="genero" placeholder="Genero" required/>
				<input id="btn-update-genero" type="submit" class="btn btn-secondary" value="Actualizar"/>
			</form>
			<form id="form-update-portada" class="flex">
				<input type="file" name="portada" placeholder="Portada" required/>
				<input id="btn-update-portada" type="submit" class="btn btn-secondary" value="Actualizar"/>
			</form>
			<form id="form-update-precio" class="flex">
				<input type="number" name="precio" placeholder="Precio" required step="any" min="0"/>
				<input id="btn-update-precio" type="submit" class="btn btn-secondary" value="Actualizar"/>
			</form>
		</section>
	</div>

	<!-- Footer -->
	<?php include_once("assets/php/footer.php"); ?>

	<!-- Scripts -->
	<script src="assets/js/update.js" type="module"></script>
</body>

</html>