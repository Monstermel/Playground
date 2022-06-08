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

	<div id="showcase-search">
		<div class="container p-left-1 p-bottom-5">
			<section id="search-all">
				<h1>Mostrar todos</h1>
				<button id ="btn-search-all" class="btn btn-secondary"><span>Mostrar</span></button>
			</section>

			<section id="search-name">
				<h1>Buscar por titulo</h1>
				<form id="form-search-name" class="flex">
					<input type="text" name="titulo" placeholder="Titulo" required/>
					<input id="btn-search-name" type="submit" class="btn btn-secondary" value="Buscar">
				</form>
			</section>
		</div>
		<div class="container p-left-1 p-bottom-5">
			<div class="cards-display">
			</div>
		</div>
	</div>

	<!-- Footer -->
	<?php include_once("assets/php/footer.php"); ?>

	<!-- Scripts -->
	<script src="assets/js/update_delete.js"></script>
	<script src="assets/js/search_all.js"></script>
	<script src="assets/js/search_name.js"></script>
</body>

</html>