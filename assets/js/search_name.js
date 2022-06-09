(function () {
	const form = document.querySelector("#form-search-name");
	const cards_display = document.querySelector(".cards-display");

	form.addEventListener("submit", (event) => {
		event.preventDefault();

		const data = new FormData(form);
		fetch("assets/php/select_name.php", {
			method: "POST",
			body: data
		})
			.then(response => response.json())
			.then(response => {
				cards_display.innerHTML = "";
				response.forEach(elemento => {
					let str = "<div id='" + elemento.id + "' class='card-data-container'>";
					str += `
						<a class='card' href='#'>
						<span class='mask'></span>
						<div class='mask-hover'></div>
						<div class='overlay'>
					`;
					str += "<p>" + elemento.titulo + "</p>"; // elemento.titulo
					str += `
						</div>
						<span class='image'>
					`;
					str += "<img src= 'assets/img/" + elemento.portada + "' alt='" + elemento.titulo + "' />"; // elemento.portada
					str += `
						</span>
						</a>
						<div id="data" class="flex">
					`;

					str += "<p> Genero: " + elemento.genero + "</p>";
					str += "<p> Precio: " + elemento.precio + "</p>";

					str += "<button id=\"btn-update\" class=\"btn btn-secondary\" onclick=\"window.location.href='update.php?id=" + elemento.id + "'\"><span>Actualizar</span></button>"
					str += `
						<button id ="btn-delete" class="btn btn-secondary"><span>Borrar</span></button>
						</div>
						</div>
					`;
					cards_display.innerHTML += str;
				});
				enable_delete_btn();
			})
			.catch(error => console.log(error));

		form.reset();
	});
})();