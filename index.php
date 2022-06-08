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
	<div id="showcase">
		<div class="container p-left-1 p-bottom-5">
			<header>
				<div id="lipsum">
					<h1>Lorem</h1>
					<p>
						Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse mattis sapien elit, vitae
						auctor erat cursus sed. Pellentesque congue nec purus quis maximus. Sed non sagittis justo.
						Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Duis
						dignissim nisi et erat convallis commodo. Fusce ultricies, neque nec volutpat dictum, leo metus
						tincidunt eros, at congue orci eros sed risus. Donec non elementum elit. Mauris magna nibh,
						dignissim eget est at, venenatis iaculis ante. Curabitur tempor mauris eu lorem aliquam
						pulvinar. Suspendisse dictum cursus velit sed posuere. Quisque auctor quis libero et vehicula.
						Pellentesque vel massa ornare, imperdiet nunc sit amet, sagittis mauris. Vestibulum aliquet
						viverra libero vitae elementum.
					</p>
				</div>
			</header>

			<section class="showcase">
				<h1>Funciones</h1>
				<div class="cards-display">
					<a class="card" href="#">
						<span class="mask"></span>
						<div class="mask-hover"></div>
						<div class="overlay">
							<p>Jurassic World: Dominio</p>
						</div>
						<span class="image">
							<img src="assets/img/jurassic_world.jpg" alt="jurassic_world" />
						</span>
					</a>

					<a class="card" href="#">
						<span class="mask"></span>
						<div class="mask-hover"></div>
						<div class="overlay">
							<p>Lightyear</p>
						</div>
						<span class="image">
							<img src="assets/img/lightyear.jpg" alt="lightyear" />
						</span>
					</a>
				</div>
			</section>
		</div>
	</div>

	<!-- Footer -->
	<?php include_once("assets/php/footer.php"); ?>

	<!-- Scripts -->
	<script src=""></script>
</body>

</html>