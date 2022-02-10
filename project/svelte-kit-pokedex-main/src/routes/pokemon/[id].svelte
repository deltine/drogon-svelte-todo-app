<script context="module">
	console.log('id: 1');
	import { getPokemonById } from '../../pokestore';
	console.log('id: 2');
	export async function load(ctx) {
		let id = ctx.page.params.id;
		console.log('load id: ' + id);
		const pokeman = await getPokemonById(id);
		console.log('load pokeman: ' + pokeman);
		return { props: { pokeman } };
	}
	console.log('id: 3');
</script>

<script>
	export let pokeman;
	// const type = pokeman.types[0].type.name;
	// const type = "";
	// console.log('pokeman: ' + pokeman);
</script>

<svelte:head>
	<title>Pokedex - {pokeman.name}</title>
</svelte:head>

<div class="flex flex-col items-center">
	<h1 class="text-4xl text-center my-8 uppercase">{pokeman.name}</h1>
	<p>
		Type: <strong>{pokeman.types[0].type.name}</strong> | Height: <strong>{pokeman.height}</strong>
		| Weight: <strong>{pokeman.weight}</strong>
	</p>
	<img class="card-image" src={pokeman.sprites['front_default']} alt={pokeman.name} />
</div>
