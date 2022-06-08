
const form = document.querySelector("#form-create");

form.addEventListener("submit", (event) => {
	event.preventDefault();

	const data = new FormData(form);
	fetch("assets/php/create.php", {
		method: "POST",
		body: data
	})
		.then(
			alert("Datos ingresados con exito")
		)
		.catch(error => {
			alert("Error al ingresar los datos");
			console.log(error);
		});

	form.reset();
})