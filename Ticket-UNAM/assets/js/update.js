(function () {
	const form_update_titulo = document.querySelector('#form-update-titulo');
	const form_update_genero = document.querySelector('#form-update-genero');
	const form_update_portada = document.querySelector('#form-update-portada');
	const form_update_precio = document.querySelector('#form-update-precio');
	const urlParams = new URLSearchParams(window.location.search);

	form_update_titulo.addEventListener("submit", (event) => {
		event.preventDefault();
		console.log(urlParams.get("id"));

		const data = new FormData(form_update_titulo);
		data.append("id", urlParams.get("id"));

		fetch("assets/php/update_titulo.php", {
			method: "POST",
			body: data
		})
			.then(
				alert("Datos actualizados con exito")
			)
			.catch(error => {
				alert("Error al actualizados los datos");
				console.log(error);
			});

		form_update_titulo.reset();
	});

	form_update_genero.addEventListener("submit", (event) => {
		event.preventDefault();

		const data = new FormData(form_update_genero);
		data.append("id", urlParams.get("id"));

		fetch("assets/php/update_genero.php", {
			method: "POST",
			body: data
		})
			.then(
				alert("Datos actualizados con exito")
			)
			.catch(error => {
				alert("Error al actualizados los datos");
				console.log(error);
			});

		form_update_genero.reset();
	});

	form_update_portada.addEventListener("submit", (event) => {
		event.preventDefault();

		const data = new FormData(form_update_portada);
		data.append("id", urlParams.get("id"));

		fetch("assets/php/update_portada.php", {
			method: "POST",
			body: data
		})
			.then(
				alert("Datos actualizados con exito")
			)
			.catch(error => {
				alert("Error al actualizados los datos");
				console.log(error);
			});

		form_update_portada.reset();
	});

	form_update_precio.addEventListener("submit", (event) => {
		event.preventDefault();

		const data = new FormData(form_update_precio);
		data.append("id", urlParams.get("id"));

		fetch("assets/php/update_precio.php", {
			method: "POST",
			body: data
		})
			.then(
				alert("Datos actualizados con exito")
			)
			.catch(error => {
				alert("Error al actualizados los datos");
				console.log(error);
			});

		form_update_precio.reset();
	});

})();