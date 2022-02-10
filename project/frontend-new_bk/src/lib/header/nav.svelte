<script>
	import logo from './svelte-logo.svg';

	async function handleSignOut() {
		await fetch('/api/sign-out', {
			method: 'POST'
		});

		window.location.href = '/';
	}
</script>

<nav class="flex items-center p-5 w-full bg-slate-700 h-10">
	<img class="h-9 w-6" src={logo} alt="SvelteKit" />

	<div class="flex justify-between w-full">
		<div>
			<a class="align-middle mx-4 text-lg text-blue-300" href="/">Home</a>
			<a class="align-middle mx-4 text-lg text-blue-300" href="/about">About</a>
		</div>
		<div>
			<!-- svelte-ignore a11y-invalid-attribute -->
			<a class="align-middle mx-4 text-lg text-blue-300" href="javascript:void(0)">SignUp</a>
			<!-- svelte-ignore a11y-invalid-attribute -->
			<a class="align-middle mx-4 text-lg text-blue-300" href="javascript:void(0)">SignIn</a>
			<!-- svelte-ignore a11y-invalid-attribute -->
			<a
				class="align-middle mx-4 text-lg text-blue-300"
				href="javascript:void(0)"
				on:click={handleSignOut}>SignOut</a
			>
		</div>
	</div>
</nav>
