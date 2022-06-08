(function () {
	const cards_display = document.querySelector(".cards-display");
	const btn_search_all = document.querySelector("#btn-search-all");

	btn_search_all.addEventListener("click", () => {
		fetch('assets/php/select_all.php', {
			method: 'post'
		})
			.then(response => response.json())
			.then(response => {
				cards_display.innerHTML = "";
				response.forEach(elemento => {
					let str = "<a class='card' href='#'>";
					str += "<span class='mask'></span>";
					str += "<div class='mask-hover'></div>";
					str += "<div class='overlay'>";
					str += "<p>" + elemento.titulo + "</p>"; // elemento.titulo
					str += "</div>";
					str += "<span class='image'>";
					str += "<img src= 'assets/img/" + elemento.portada + "' alt='" + elemento.titulo + "' />"; // elemento.portada
					str += "</span>";
					str += "</a>";
					cards_display.innerHTML += str;
				});
			})
			.catch(error => console.log(error));
	});
})();