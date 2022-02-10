<script context="module">
	export async function load({ session }) {
		console.log('index session', session);

		return {
			props: {
				session
			}
		};
	}
</script>

<script>
	import Nav from '$lib/header/nav.svelte';
	import Footer from '$lib/footer.svelte';
	import LoginForm from '$lib/loginForm.svelte';

	let error;

	async function signUp(event) {
		console.log('signUp', event.detail.mailAddress);
		console.log('signUp', event.detail.password);

		const response = await fetch('/api/drogon', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json'
			},
			body: JSON.stringify({
				path: 'Account/signup',
				mailAddress: event.detail.mailAddress,
				password: event.detail.password
			})
		});

		if (!response.ok) {
			// error = (await response2.json()).message;
			return;
		}

		let resBody = await response.json();
		console.log('resBody', resBody);

		if (resBody.result == 1) {
			console.log('index signup success');
			window.location.href = '/todo';
		}
	}

	async function signIn(event) {
		console.log('signIn', event.detail.mailAddress);
		console.log('signIn', event.detail.password);

		const response = await fetch('/api/drogon', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json'
			},
			body: JSON.stringify({
				path: 'Account/signin',
				mailAddress: event.detail.mailAddress,
				password: event.detail.password
			})
		});

		if (!response.ok) {
			return;
		}

		let resBody = await response.json();
		console.log('resBody', resBody);

		if (resBody.result == 1) {
			console.log('index signin success');
			window.location.href = '/todo';
		}
	}

	async function testFunc() {
		console.log('test fanc: start');
		const response = await fetch('https://localhost/api/Account/test', {
			method: 'POST',
			headers: {
				mode: 'cors',
				// SameSite: 'None',
				'content-type': 'application/json',
				credentials: 'include'
			},
			body: JSON.stringify({
				mailAddress: 'test24@mail.jp',
				password: 'password'
			})
		});

		console.log('response', response);

		if (!response.ok) {
			error = (await response.json()).message;
			return;
		}

		console.log('test fanc: end');
	}
</script>

<svelte:head>
	<title>Home</title>
</svelte:head>

<button type="submit" on:click={testFunc}> test </button>

<div class="#index">
	<div class="min-h-[640px] min-w-[980px]">
		<Nav />
		<div class="pt-[100px]">
			<div class="flex justify-center">
				<div class="flex items-center min-h-min-[300px]">
					<div class="">
						<h1 class="text-4xl font-bold text-sky-800">SvelteKit Todo App</h1>
						<h2 class="text-2xl m-4">
							- frontend
							<p class="text-base">
								html / css / Javascript<br />
								Svelte / SvelteKit / Tailwind CSS
							</p>
							<br />

							- backend
							<p class="text-base">C++ / Drogon / MySql</p>
						</h2>
					</div>
				</div>
				<div class="w-[490px] min-h-min-[300px]">
					<div class=" justify-center overflow-hidden">
						<LoginForm on:signIn={signIn} on:signUp={signUp} />
					</div>
				</div>
			</div>
		</div>
		<Footer />
	</div>
</div>
