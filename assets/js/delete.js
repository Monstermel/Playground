function enable_delete_btn() {
	const card_data_container = document.querySelectorAll('.card-data-container');

	card_data_container.forEach(item => {
		const btn_delete = item.querySelector("#btn-delete");

		btn_delete.addEventListener('click', () => {
			if (confirm("Seguro que quieres eliminar este item?")) {
				let data = new FormData();
				data.append("id", item.id);
				fetch("assets/php/delete.php", {
					method: "POST",
					body: data
				})
					.then(
						alert("Datos borrados con exito")
					)
					.catch(error => {
						alert("Error al borrar los datos");
						console.log(error);
					});
				window.location.reload();
			}
		});
	});

}